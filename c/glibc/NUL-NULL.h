

/**
 *	NUL vs. NULL
 *	NUL is the character with integer value 0. It's different from NULL, which is a pointer with value 0.
 *	In C, a character string is usually terminated with a NUL character. For instance, the character string
 *	"Hello, world!" occupies 14 bytes because there is an implicit NUL after the exclamation point
 *	indicating the end of the string.
 *	NULL, on the other hand, is a pointer value that you can be sure will never correspond to a real
 *	memory address in your program.
 *	In C and C++, NUL is expressed as the character constant '\0', or (char) 0. The definition of
 *	NULL differs among operating systems; on Linux, it is defined as ((void*)0) in C and simply 0 in
 *	C++.
 */
