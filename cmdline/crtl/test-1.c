#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <limits.h>
#include <termios.h>
#include <unistd.h>

#include "cli.h"


#define CLITEST_PORT        8000
#define MODE_CONFIG_INT     10
#define CLI_ENABLE_PASSWORD     "rong "


unsigned int regular_count = 0;
unsigned int debug_regular = 0;


const char *cli_user = "root";
const char *cli_passwd = "123456";


struct my_context {
    int value;
    char *message;
};


int cmd_test(struct cli_struct *cli, const char *command, char *argv[], int argc) 
{
    int i;
    cli_print(cli, "called %s with \"%s\"", __func__, command);
    cli_print(cli, "%d arguments:", argc);
    
    for (i = 0; i < argc; i++) 
        cli_error(cli, "        \033[31m%s\033[m", argv[i]);

    return CLI_OK;
}

int cmd_set(struct cli_struct *cli, const char   *command, char *argv[], int argc) 
{
    if (argc < 2 || strcmp(argv[0], "?") == 0) {
        cli_print(cli, "Specify a variable to set");
        return CLI_OK;
    }

    if (strcmp(argv[1], "?") == 0) {
        cli_print(cli, "Specify a value");
        return CLI_OK;
    }

    if (strcmp(argv[0], "regular_interval") == 0) {
        unsigned int sec = 0;
        if (!argv[1] && !*argv[1]) {
            cli_print(cli, "Specify a regular callback interval in seconds");
            return CLI_OK;
        }
        sscanf(argv[1], "%u", &sec);
        if (sec < 1) {
            cli_print(cli, "Specify a regular callback interval in seconds");
            return CLI_OK;
        }
        struct timeval tv = {sec, 0};
        cli_set_client_timeout(cli, &tv);

        cli_print(cli, "Regular callback interval is now %d seconds", sec);
        return CLI_OK;
    }

    cli_print(cli, "Setting \"%s\" to \"%s\"", argv[0], argv[1]);
    return CLI_OK;
}

int cmd_config_int(struct cli_struct *cli, const char   *command, char *argv[], int argc) 
{
    if (argc < 1) {
        cli_print(cli, "Specify an interface to configure");
        return CLI_OK;
    }

    if (strcmp(argv[0], "?") == 0)
        cli_print(cli, "  test0/0");
    else if (strcasecmp(argv[0], "test0/0") == 0)
        cli_set_configmode(cli, MODE_CONFIG_INT, "test");
    else
        cli_print(cli, "Unknown interface %s", argv[0]);

    return CLI_OK;
}

int cmd_config_int_exit(struct cli_struct *cli, const char   *command, char   *argv[], int   argc) 
{
    cli_set_configmode(cli, CLI_MODE_CONFIG, NULL);
    return CLI_OK;
}

int cmd_show_regular(struct cli_struct *cli, const char   *command, char   *argv[], int   argc) 
{
    cli_print(cli, "cli_regular() has run %u times", regular_count);
    return CLI_OK;
}

int cmd_debug_regular(struct cli_struct *cli, const char   *command, char   *argv[], int   argc) 
{
    debug_regular = !debug_regular;
    cli_print(cli, "cli_regular() debugging is %s", debug_regular ? "enabled" : "disabled");
    return CLI_OK;
}

int cmd_context(struct cli_struct *cli, const char   *command, char   *argv[], int   argc) 
{
    struct my_context *myctx = (struct my_context *)cli_get_context(cli);
    cli_print(cli, "User context has a value of %d and message saying %s", myctx->value, myctx->message);
    return CLI_OK;
}

int check_auth(const char *username, const char *password) 
{
    if (strcasecmp(username, cli_user) != 0) return CLI_ERROR;
    if (strcasecmp(password, cli_passwd) != 0) return CLI_ERROR;
    return CLI_OK;
}

int regular_callback(struct cli_struct *cli) 
{
    regular_count++;
    if (debug_regular) {
        cli_print(cli, "Regular callback - %u times so far", regular_count);
        cli_reprompt(cli);
    }
    return CLI_OK;
}

int check_enable(const char *password) 
{
    return !strcasecmp(password, "topsecret");
}

int idle_timeout(struct cli_struct *cli) 
{
    cli_print(cli, "Custom idle timeout");
    return CLI_QUIT;
}

void pc(struct cli_struct   *cli, const char *string) 
{
    printf("%s\n", string);
}

#define MODE_POLYGON_TRIANGLE 20
#define MODE_POLYGON_RECTANGLE 21

int cmd_perimeter(struct cli_struct *cli, const char *command, char *argv[], int argc) 
{
    struct cli_optarg_pair *optargs = cli_get_all_found_optargs(cli);
    int i = 1, numSides = 0;
    int perimeter = 0;
    int verbose_count = 0;
    char *verboseArg = NULL;
    char *shapeName = NULL;

    cli_print(cli, "perimeter callback, with %d args", argc);
    
    for (; optargs; optargs = cli_get_next_optargs(optargs)) 
        cli_print(cli, "%d, %s=%s", i++, cli_get_name_optargs(optargs), cli_get_value_optargs(optargs));

    if ((verboseArg = cli_get_optarg_value(cli, "verbose", verboseArg))) {
        do {
            verbose_count++;
        } while ((verboseArg = cli_get_optarg_value(cli, "verbose", verboseArg)));
    }
    cli_print(cli, "verbose argument was seen  %d times", verbose_count);

    shapeName = cli_get_optarg_value(cli, "shape", NULL);
    
    if (!shapeName) {
        cli_error(cli, "No shape name given");
        return CLI_ERROR;
    } else if (strcmp(shapeName, "triangle") == 0) {
        numSides = 3;
    } else if (strcmp(shapeName, "rectangle") == 0) {
        numSides = 4;
    } else {
        cli_error(cli, "Unrecognized shape given");
        return CLI_ERROR;
    }
    
    for (i = 1; i <= numSides; i++) {
        char sidename[50], *value;
        int length;
        snprintf(sidename, 50, "side_%d", i);
        value = cli_get_optarg_value(cli, sidename, NULL);
        length = strtol(value, NULL, 10);
        perimeter += length;
    }
    cli_print(cli, "Perimeter is %d", perimeter);
    return CLI_OK;
}


const char *KnownShapes[] = {"rectangle", "triangle", NULL};

int shape_completor(struct cli_struct *cli, const char *name, const char *value, struct cli_comphelp *comphelp) 
{
    const char **shape;
    int rc = CLI_OK;

    printf("shape_completor called with <%s>\n", value);
    
    for (shape = KnownShapes; *shape && (rc == CLI_OK); shape++) {
        if (!value || !strncmp(*shape, value, strlen(value))) {
            rc = cli_add_comphelp_entry(comphelp, *shape);
        }
    }
    return rc;
}

int shape_validator(struct cli_struct *cli, const char *name, const char *value) 
{
    const char **shape;

    printf("shape_validator called with <%s>\n", value);
    for (shape = KnownShapes; *shape; shape++) {
        if (!strcmp(value, *shape)) return CLI_OK;
    }
    
    return CLI_ERROR;
}

int verbose_validator(struct cli_struct *cli, const char *name, const char *value) 
{
    printf("verbose_validator called\n");
    return CLI_OK;
}

int shape_transient_eval(struct cli_struct *cli, const char *name, const char *value) 
{
    printf("shape_transient_eval called with <%s>\n", value);
    
    if (!strcmp(value, "rectangle")) {
        cli_set_transient_mode(cli, MODE_POLYGON_RECTANGLE);
        cli_set_optarg_value(cli, "duplicateShapeValue", value, 0);
        return CLI_OK;
    } else if (!strcmp(value, "triangle")) {
        cli_set_transient_mode(cli, MODE_POLYGON_TRIANGLE);
        cli_set_optarg_value(cli, "duplicateShapeValue", value, 0);
        return CLI_OK;
    }
    
    cli_error(cli, "unrecognized value for setting %s -> %s", name, value);
    
    return CLI_ERROR;
}

const char *KnownColors[] = {"black",    "white",    "gray",      "red",        "blue",
                             "green",    "lightred", "lightblue", "lightgreen", "darkred",
                             "darkblue", "darkgree", "lavender",  "yellow",     NULL};

int color_completor(struct cli_struct *cli, const char *name, const char *word, struct cli_comphelp *comphelp) 
{
    // Attempt to show matches against the following color strings
    const char **color;
    int rc = CLI_OK;
    printf("color_completor called with <%s>\n", word);
    for (color = KnownColors; *color && (rc == CLI_OK); color++) {
        if (!word || !strncmp(*color, word, strlen(word))) {
            rc = cli_add_comphelp_entry(comphelp, *color);
        }
    }
    return rc;
}

int color_validator(struct cli_struct *cli, const char *name, const char *value) 
{
    const char **color;
    int rc = CLI_ERROR;
    printf("color_validator called for %s\n", name);
    for (color = KnownColors; *color; color++) {
        if (!strcmp(value, *color)) return CLI_OK;
    }
    return rc;
}

int side_length_validator(struct cli_struct *cli, const char *name, const char *value) 
{
    // Verify 'value' is a positive number
    long len;
    char *endptr;
    int rc = CLI_OK;

    printf("side_length_validator called\n");
    errno = 0;
    len = strtol(value, &endptr, 10);
    if ((endptr == value) || (*endptr != '\0') || ((errno == ERANGE) && ((len == LONG_MIN) || (len == LONG_MAX))))
        return CLI_ERROR;
    return rc;
}

int check1_validator(struct cli_struct *cli, const char   *name, const char   *value) 
{
    char *color;
    char *transparent;

    printf("check1_validator called \n");
    color = cli_get_optarg_value(cli, "color", NULL);
    transparent = cli_get_optarg_value(cli, "transparent", NULL);

    if (!color && !transparent) {
        cli_error(cli, "\nMust supply either a color or transparent!");
        return CLI_ERROR;
    } else if (color && !strcmp(color, "black") && transparent) {
        cli_error(cli, "\nCan not have a transparent black object!");
        return CLI_ERROR;
    }
    return CLI_OK;
}

void run_child(int acceptfd) 
{
    struct cli_command *c;
    struct cli_struct *cli;

    // Prepare a small user context
    char mymessage[] = "I contain user data!";
    struct my_context myctx;
    myctx.value = 5;
    myctx.message = mymessage;
    
#define CLI_BANNER  "# Welcome TO Crtl Telnet CLI \n"\
                    "#  ls - show the list of cmd\n"
#define CLI_HOSTNAME    "[telnet@crtl]"

    cli = cli_init(CLI_BANNER, CLI_HOSTNAME);
    
    cli_telnet_protocol(cli, 1);
    cli_regular(cli, regular_callback);

    // change regular update to 5 seconds rather than default of 1 second
    cli_regular_interval(cli, 5);
    
    // set 60 second idle timeout
    cli_set_idle_timeout_callback(cli, 60, idle_timeout);
    
    cli_register_command(cli, NULL, "set", cmd_set, CLI_PRIVILEGE_PRIVILEGED, CLI_MODE_EXEC, NULL);
    
    cli_register_command(cli, NULL, "interface", cmd_config_int, CLI_PRIVILEGE_PRIVILEGED, CLI_MODE_CONFIG,
                                                        "Configure an interface");
    cli_register_command(cli, NULL, "exit", cmd_config_int_exit, CLI_PRIVILEGE_PRIVILEGED, MODE_CONFIG_INT,
                                                                "Exit from interface configuration");
    cli_register_command(cli, NULL, "address", cmd_test, CLI_PRIVILEGE_PRIVILEGED, MODE_CONFIG_INT, 
                                                            "Set IP address");
    
    cli_register_command(cli, NULL, "test", cmd_test, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC, NULL);
    cli_register_command(cli, NULL, "simple", NULL, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC, NULL);
    cli_register_command(cli, NULL, "simon", NULL, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC, NULL);
    
    
    c = cli_register_command(cli, NULL, "show", NULL, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC, NULL);
    cli_register_command(cli, c, "regular", cmd_show_regular, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC,
                                                    "Show the how many times cli_regular has run");
    cli_register_command(cli, c, "counters", cmd_test, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC,
                                                        "Show the counters that the system uses");
    cli_register_command(cli, c, "junk", cmd_test, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC, NULL);
    
    c = cli_register_command(cli, NULL, "debug", NULL, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC, NULL);
    cli_register_command(cli, c, "regular", cmd_debug_regular, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC,
                                                                    "Enable cli_regular() callback debugging");

    // Register some commands/subcommands to demonstrate opt/arg and buildmode operations

    c = cli_register_command(cli, NULL, "perimeter", cmd_perimeter, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC,
                                                            "Calculate perimeter of polygon");
    cli_register_optarg(c, "transparent", CLI_CMD_OPTIONAL_FLAG, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC,
                                                            "Set transparent flag", NULL, NULL, NULL);
    cli_register_optarg(c, "verbose", CLI_CMD_OPTIONAL_FLAG | CLI_CMD_OPTION_MULTIPLE, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC,
                                                        "Set transparent flag", NULL, NULL, NULL);
    cli_register_optarg(c, "color", CLI_CMD_OPTIONAL_ARGUMENT, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC, "Set color",
                                                        color_completor, color_validator, NULL);
    cli_register_optarg(c, "__check1__", CLI_CMD_SPOT_CHECK, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC, NULL, NULL,
                                                        check1_validator, NULL);
    cli_register_optarg(c, "shape", CLI_CMD_ARGUMENT | CLI_CMD_ALLOW_BUILDMODE, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC,
                                                        "Specify shape to calclate perimeter for", shape_completor, shape_validator,
                                                        shape_transient_eval);
    cli_register_optarg(c, "side_1", CLI_CMD_ARGUMENT, CLI_PRIVILEGE_UNPRIVILEGED, MODE_POLYGON_TRIANGLE,
                                                        "Specify side 1 length", NULL, side_length_validator, NULL);
    cli_register_optarg(c, "side_1", CLI_CMD_ARGUMENT, CLI_PRIVILEGE_UNPRIVILEGED, MODE_POLYGON_RECTANGLE,
                                                        "Specify side 1 length", NULL, side_length_validator, NULL);

    cli_register_optarg(c, "side_2", CLI_CMD_ARGUMENT, CLI_PRIVILEGE_UNPRIVILEGED, MODE_POLYGON_TRIANGLE,
                                                        "Specify side 2 length", NULL, side_length_validator, NULL);
    cli_register_optarg(c, "side_2", CLI_CMD_ARGUMENT, CLI_PRIVILEGE_UNPRIVILEGED, MODE_POLYGON_RECTANGLE,
                                                        "Specify side 2 length", NULL, side_length_validator, NULL);
    cli_register_optarg(c, "side_3", CLI_CMD_ARGUMENT, CLI_PRIVILEGE_UNPRIVILEGED, MODE_POLYGON_TRIANGLE,
                                                        "Specify side 3 length", NULL, side_length_validator, NULL);
    cli_register_optarg(c, "side_3", CLI_CMD_ARGUMENT, CLI_PRIVILEGE_UNPRIVILEGED, MODE_POLYGON_RECTANGLE,
                                                        "Specify side 3 length", NULL, side_length_validator, NULL);
    cli_register_optarg(c, "side_4", CLI_CMD_ARGUMENT, CLI_PRIVILEGE_UNPRIVILEGED, MODE_POLYGON_RECTANGLE,
                                                        "Specify side 4 length", NULL, side_length_validator, NULL);

    // Set user context and its command
    cli_set_context(cli, (void *)&myctx);
    cli_register_command(cli, NULL, "context", cmd_context, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC,
                                                        "Test a user-specified context");

    cli_set_auth_callback(cli, check_auth);
    cli_set_enable_callback(cli, check_enable);
    
    {// Test reading from a file
        FILE *fh;

        if ((fh = fopen("demo_clitest.txt", "r"))) {
            // This sets a callback which just displays the cli_print() text to stdout
            cli_print_callback(cli, pc);
            cli_file(cli, fh, CLI_PRIVILEGE_UNPRIVILEGED, CLI_MODE_EXEC);
            cli_print_callback(cli, NULL);
            fclose(fh);
        }
    }
    cli_loop(cli, acceptfd);
    cli_done(cli);
}

int socket_keepalive(int sockfd, int sec, int usec)
{
    struct  timeval timeout={sec,usec};//timeout
    return setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &timeout, sizeof(timeout));
}
int socket_reuseaddr(int sockfd, int sec, int usec)
{
    struct  timeval timeout={sec,usec};//timeout
    return setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &timeout, sizeof(timeout));
}

int socket_server_tcp(struct sockaddr_in *srvaddr, int port, int listen_backlog)
{
    if((!srvaddr) || (!port) || !listen_backlog)
    {
        printf("Invalid value.\n");
        return -1;
    }
    
    int listenfd = -1;
    
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        printf("socket: %s\n", strerror(errno));
		return -1;
    } 
    
    /**
	 *  Set send/receive message timeout
	 */
	socket_keepalive(listenfd, 2, 0);
	socket_reuseaddr(listenfd, 2, 0);

    
    bzero(srvaddr, sizeof(struct sockaddr_in));
    
    srvaddr->sin_family = AF_INET;
    srvaddr->sin_addr.s_addr = INADDR_ANY;
    srvaddr->sin_port = htons(port);
    
    if(bind(listenfd, (struct sockaddr*)srvaddr, sizeof(struct sockaddr)) < 0)
    {
        printf("bind: %s\n", strerror(errno));
        close(listenfd);
		return -1;
    }
    
    if(listen(listenfd, listen_backlog) < 0)
    {
        printf("listen: %s\n", strerror(errno));
        close(listenfd);
		return -1;
    }  
    
    return listenfd;
}


void *__libcli_callback(void*arg)
{
    signal(SIGCHLD/*Child status has changed (POSIX).*/, SIG_IGN/*sigignore*/);
    
    struct sockaddr_in srvaddr, cliaddr;
    int listenfd = socket_server_tcp(&srvaddr, CLITEST_PORT, 50);
    while(1)
    {
        printf("Listening on port %d\n", CLITEST_PORT);
        socklen_t len;
        int acceptfd = accept(listenfd, (struct sockaddr*)&cliaddr, &len);
        int pid = fork();
        if (pid < 0) {
            perror("fork");
            return NULL;
        }

        /* parent */
        if (pid > 0) {
            socklen_t len = sizeof(cliaddr);
            if (getpeername(acceptfd, (struct sockaddr *)&cliaddr, &len) >= 0)
            printf(" * accepted connection from %s, port %d\n", inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port);

            close(acceptfd);
            continue;
        }

        /* child */
        close(listenfd);
        run_child(acceptfd);
        exit(0);

    }

    close(listenfd);
    
}




void demo_libcli_test1() 
{

    __libcli_callback(NULL);
    
    while(1)
    {
        sleep(5);
//        printf("CRTL main rutinue.\n");
    }
}



int main()
{
    demo_libcli_test1();
//    demo_libcli_test2();
    
    return 0;
}




