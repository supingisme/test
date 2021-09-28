#include <stdio.h>
#include<stdlib.h> 
FILE *stream;
void main( void )
{
	int i = 10;
	double fp = 1.5;
	char s[] = "this is a string";
	char c = '\n';
	stream = fopen( "libcare-cc.log", "w" );
	fprintf( stream, "%s%c", s, c );
	fprintf( stream, "%d\n", i );
	fprintf( stream, "%f\n", fp );
	fclose( stream );
	system( "type fprintf.out" );
}
