/*
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	Copyright (C) 2012-2014 PIVA SOFTWARE (www.pivasoftware.com)
 *		Author: Mohamed Kallel <mohamed.kallel@pivasoftware.com>
 *		Author: Anis Ellouze <anis.ellouze@pivasoftware.com>
 *	Copyright (C) 2011 Luka Perkov <freecwmp@lukaperkov.net>
 */

#include <errno.h>
#include <malloc.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <libubox/uloop.h>
#ifdef JSONC
 #include <json-c/json.h>
#else
 #include <json/json.h>
#endif


#include "external.h"
#include "easycwmp.h"
#include "log.h"

LIST_HEAD(external_list_parameter);
char *external_method_status = NULL;
char *external_method_instance = NULL;
char *external_method_fault = NULL;
static int pfds_in[2], pfds_out[2], pid;

void external_add_list_paramameter(char *param_name, char *param_data, char *param_type, char *fault_code)
{
	struct external_parameter *external_parameter;
	struct list_head *ilist;

	if (!param_name) param_name = "";
	list_for_each(ilist, &external_list_parameter) {
		external_parameter = list_entry(ilist, struct external_parameter, list);
		int cmp = strcmp(external_parameter->name, param_name);
		if (cmp == 0) {
			if (!external_parameter->fault_code || external_parameter->fault_code[0] == '\0') {
				return;
			}
			else {
				break;
			}
		}
	}
	external_parameter = calloc(1, sizeof(struct external_parameter));
	list_add_tail(&external_parameter->list, &external_list_parameter);
	external_parameter->name = strdup(param_name);
	if (param_data) external_parameter->data = strdup(param_data);
	if (param_type) external_parameter->type = strdup(param_type);
	if (fault_code) external_parameter->fault_code = strdup(fault_code);
}

void external_parameter_delete(struct external_parameter *external_parameter)
{
	list_del(&external_parameter->list);
	free(external_parameter->name);
	free(external_parameter->data);
	free(external_parameter->type);
	free(external_parameter->fault_code);
	free(external_parameter);
}

void external_free_list_parameter()
{
	struct external_parameter *external_parameter;
	while (external_list_parameter.next != &external_list_parameter) {
		external_parameter = list_entry(external_list_parameter.next, struct external_parameter, list);
		external_parameter_delete(external_parameter);
	}
}

void external_set_param_resp_status(char *status)
{
	free(external_method_status);
	external_method_status = status ? strdup(status) : NULL;
}

void external_fetch_set_param_resp_status(char **status)
{
	*status = external_method_status;
	external_method_status = NULL;
}

void external_method_resp_status (char *status, char *fault)
{
	free(external_method_status);
	external_method_status = status ? strdup(status) : NULL;
	free(external_method_fault);
	external_method_fault = fault ? strdup(fault) : NULL;
}

void external_fetch_method_resp_status (char **status, char **fault)
{
	*status = external_method_status;
	external_method_status = NULL;
	*fault = external_method_fault;
	external_method_fault = NULL;
}

void external_add_obj_resp (char *status, char *instance, char *fault)
{
	free(external_method_status);
	external_method_status = status ? strdup(status) : NULL;
	free(external_method_instance);
	external_method_instance = instance ? strdup(instance) : NULL;
	free(external_method_fault);
	external_method_fault = fault ? strdup(fault) : NULL;
}

void external_fetch_add_obj_resp (char **status, char **instance, char **fault)
{
	*status = external_method_status;
	external_method_status = NULL;
	*instance = external_method_instance;
	external_method_instance = NULL;
	*fault = external_method_fault;
	external_method_fault = NULL;
}

static int external_read_pipe(int (*json_handle)(char *))
{
//    cwmp_log(NAME, L_DEBUG, ">> call external_read_pipe\n");
    
	char buffer[1];
	ssize_t rxed;
	char *c = NULL, *line = NULL;
	int t;
	while ((rxed = read(pfds_out[0], buffer, sizeof(buffer))) > 0) {
		if (buffer[0] == '\n') {
//            cwmp_log(NAME, L_DEBUG, ">> line: %s\n", line);
			if (line == NULL) continue;
			if (strcmp(line, EXTERNAL_PROMPT) == 0) goto done;
			if (json_handle) json_handle(line);
			FREE(line);
            
		} else {
		
//		    cwmp_log(NAME, L_DEBUG, ">> char: %c\n", buffer[0]);
			if (line)
				t = asprintf(&c, "%s%c", line, buffer[0]);
			else
				t = asprintf(&c, "%c", buffer[0]);

			if (t == -1) goto error;

			free(line);
			line = c;
		}
	}
//    cwmp_log(NAME, L_DEBUG, ">> rxed: %d\n", rxed);
done:
//    cwmp_log(NAME, L_DEBUG, ">> call external_read_pipe done\n");
	free(line);
	return 0;

error:
    cwmp_log(NAME, L_NOTICE, ">> call external_read_pipe error\n");
	free(c);
	free(line);
	return -1;
}

static void external_write_pipe(const char *msg)
{
	char *value = NULL;
	if(asprintf(&value, "%s\n", msg) == -1) return;
	if (write(pfds_in[1], value, strlen(value)) == -1) {
		cwmp_log(NAME, L_CRIT, "error occured when trying to write to the pipe\n");
	}
	free(value);
}

static void external_add_json_obj(json_object *json_obj_out, char *object, char *string)
{
	json_object *json_obj_tmp = json_object_new_string(string);
	json_object_object_add(json_obj_out, object, json_obj_tmp);
}

int external_init()
{
	cwmp_log(NAME, L_NOTICE, "external script init\n");
	if (pipe(pfds_out) < 0)
			return -1;
	if (pipe(pfds_in) < 0)
			return -1;
	if ((pid = fork()) == -1) {
		cwmp_log(NAME, L_CRIT, "external init fork failed\n");
		return -1;
	}
    
	if (pid == 0) {
		/* child */
		close(pfds_out[0]);
		dup2(pfds_out[1], STDOUT_FILENO);
		close(pfds_out[1]);

		close(pfds_in[1]);
		dup2(pfds_in[0], STDIN_FILENO);
		close(pfds_in[0]);

		int i=0;
		const char *argv[4];
		argv[i++] = fc_script;
		argv[i++] = "--json-input";
		argv[i++] = NULL;

		execvp(argv[0], (char **) argv);
        
        cwmp_log(NAME, L_NOTICE, ">> execvp %s %s\n", fc_script, argv[1]);
        
		exit(ESRCH);
	} 
    else if (pid < 0)
		return -1;

    cwmp_log(NAME, L_NOTICE, ">> execvp %s\n", fc_script);

	close(pfds_out[1]);
	close(pfds_in[0]);

	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		cwmp_log(NAME, L_CRIT, "ignoring pipe signal failed\n");

	int r = external_read_pipe(NULL);
    cwmp_log(NAME, L_NOTICE, ">> external_read_pipe ret %d\n", r);
    
	return r;
}

void external_exit()
{
	cwmp_log(NAME, L_NOTICE, "external script exit\n");////////////////////
    
	json_object *json_obj_out = json_object_new_object();
	external_add_json_obj(json_obj_out, "command", "exit");

	cwmp_log(NAME, L_NOTICE, ">> external_add_json_obj done\n");////////////////////

    external_write_pipe(json_object_to_json_string(json_obj_out));
    
	cwmp_log(NAME, L_NOTICE, ">> external_write_pipe done\n");////////////////////

    json_object_put(json_obj_out);
    
	external_read_pipe(NULL);

    cwmp_log(NAME, L_NOTICE, ">> external_read_pipe done\n");////////////////////
	
	int status;
	while (wait(&status) != pid) {
		cwmp_log(NAME, L_DEBUG, "waiting for child to exit\n");
		cwmp_log(NAME, L_NOTICE, "waiting for child to exit\n");
	}
    cwmp_log(NAME, L_NOTICE, ">> wait done\n");////////////////////
    
	close(pfds_out[0]);
	close(pfds_in[1]);
}

int external_action_parameter_execute(char *command, char *class, char *name, char *arg)
{
	cwmp_log(NAME, L_NOTICE, "external: execute %s %s %s %s\n",
			command, class, name, arg?arg:"");

	json_object *json_obj_out = json_object_new_object();
	external_add_json_obj(json_obj_out, "command", command);
	external_add_json_obj(json_obj_out, "class", class);
	external_add_json_obj(json_obj_out, "parameter", name);
	if (arg) external_add_json_obj(json_obj_out, "argument", arg);
	external_write_pipe(json_object_to_json_string(json_obj_out));
    
    cwmp_log(NAME, L_NOTICE, "external: execute parameter %s\n", json_object_to_json_string(json_obj_out));
    
	json_object_put(json_obj_out);

	return 0;
}

int external_action_simple_execute(char *command, char *class, char *arg)
{
	cwmp_log(NAME, L_NOTICE, "external: execute %s %s %s\n",
			command, class?class:"", arg?arg:"");

	json_object *json_obj_out = json_object_new_object();
	external_add_json_obj(json_obj_out, "command", command);
	if (class) external_add_json_obj(json_obj_out, "class", class);
	if (arg) external_add_json_obj(json_obj_out, "argument", arg);
	external_write_pipe(json_object_to_json_string(json_obj_out));
	json_object_put(json_obj_out);

	return 0;
}

int external_action_download_execute(char *url, char *file_type, char *file_size, char *user_name, char *password)
{
	cwmp_log(NAME, L_NOTICE, "external: execute download %s\n", url);

	json_object *json_obj_out = json_object_new_object();
	external_add_json_obj(json_obj_out, "command", "download");
	external_add_json_obj(json_obj_out, "url", url);
	external_add_json_obj(json_obj_out, "file_type", file_type);
	if (file_size) external_add_json_obj(json_obj_out, "file_size", file_size);
	if (user_name) external_add_json_obj(json_obj_out, "user_name", user_name);
	if (password) external_add_json_obj(json_obj_out, "password", password);

    cwmp_log(NAME, L_NOTICE, "external: execute download %s\n", json_object_to_json_string(json_obj_out));
    
	external_write_pipe(json_object_to_json_string(json_obj_out));
	json_object_put(json_obj_out);

	return 0;
}


/* ????????????????????????????????????????????????
    Author: rongtao@sylincom.com 
    Time: 2020.03.25
   */
int external_action_download_execute_easy(char *url, char *file_size)
{
	cwmp_log(NAME, L_NOTICE, "external: execute download %s\n", url);

	json_object *json_obj_out = json_object_new_object();
	external_add_json_obj(json_obj_out, "command", "download");
	external_add_json_obj(json_obj_out, "url", url);
	if (file_size) external_add_json_obj(json_obj_out, "file_size", file_size);

    cwmp_log(NAME, L_NOTICE, "external: execute download %s\n", json_object_to_json_string(json_obj_out));
    
	external_write_pipe(json_object_to_json_string(json_obj_out));
	json_object_put(json_obj_out);

	return 0;
}


int external_action_upload_execute(char *url, char *file_type, char *user_name, char *password)
{
	cwmp_log(NAME, L_NOTICE, "external: execute upload %s\n", url);

	json_object *json_obj_out = json_object_new_object();
	external_add_json_obj(json_obj_out, "command", "upload");
	external_add_json_obj(json_obj_out, "url", url);
	external_add_json_obj(json_obj_out, "file_type", file_type);
	if (user_name) external_add_json_obj(json_obj_out, "user_name", user_name);
	if (password) external_add_json_obj(json_obj_out, "password", password);
    
    cwmp_log(NAME, L_NOTICE, "external: execute upload %s\n", json_object_to_json_string(json_obj_out));
    
	external_write_pipe(json_object_to_json_string(json_obj_out));
	json_object_put(json_obj_out);

	return 0;
}

int external_action_handle (int (*json_handle)(char *))
{
	json_object *json_obj_out = json_object_new_object();
	external_add_json_obj(json_obj_out, "command", "end");
	external_write_pipe(json_object_to_json_string(json_obj_out));
	json_object_put(json_obj_out);

	int r = external_read_pipe(json_handle);
	return r;
}
