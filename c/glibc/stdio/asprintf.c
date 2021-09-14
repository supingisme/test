#include <stdio.h>
#include <sys/types.h>

size_t http_get_response(char *buffer, size_t size, size_t rxed, char **msg_in)
{
	char *c;
	asprintf(&c, "%s%.*s", *msg_in, size * rxed, buffer);
	*msg_in = c;
	return size * rxed;
}

int main()
{
	char *msg = "rongtao";
	char buffer[1024] = "Hello. ";

	http_get_response(buffer, 10, 10, &msg);

	printf("%s", msg);
}
