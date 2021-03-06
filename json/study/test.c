#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

#include "json-c/json.h"

void print_hex(const char* s)
{
	const char *iter = s;
	unsigned char ch;
	while ((ch = *iter++) != 0)
	{
		if( ',' != ch)
			printf("%x ", ch);
		else
			printf( ",");
	}
	putchar('\n');
}

int main(void)
{
	const char *input = "\"\\ud840\\udd26,\\ud840\\udd27,\\ud800\\udd26,\\ud800\\udd27\"";
	const char *expected = "\xF0\xA0\x84\xA6,\xF0\xA0\x84\xA7,\xF0\x90\x84\xA6,\xF0\x90\x84\xA7";
	struct json_object *parse_result = json_tokener_parse(input);
	const char *unjson = json_object_get_string(parse_result);

	printf("input: %s\n", input);

	int strings_match = !strcmp( expected, unjson);
	int retval = 0;
	if (strings_match)
	{
		printf("JSON parse result is correct: %s\n", unjson);
		puts("PASS");
	} else {
		printf("JSON parse result doesn't match expected string\n");
		printf("expected string bytes: ");
		print_hex(expected);
		printf("parsed string bytes:   ");
		print_hex(unjson);
		puts("FAIL");
		retval = 1;
	}
	json_object_put(parse_result);
	return retval;
}

