
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Returns a nonzero value if and only if the WORD appears in
 * /usr/dict/words. */
int grep_for_word (const char* word, const char *file)
{
	size_t length;
	char* buffer;
	int exit_code;
	/* Build up the string 'grep -x WORD /usr/dict/words'. Allocate the
	 * string dynamically to avoid buffer overruns. */
	length =
		strlen ("grep ") + strlen (word) + strlen (file) + 1;
	buffer = (char*) malloc (length);
	sprintf (buffer, "grep %s %s", word, file);
	/* Run the command. */
	exit_code = system (buffer);
	/* Free the buffer. */
	free (buffer);
	/* If grep returned 0, then the word was present in the
	 * dictionary. */
	return exit_code == 0;
}

int main(int argc, char *argv[])
{
	grep_for_word(argv[1], argv[2]);
}
