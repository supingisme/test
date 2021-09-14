//wcstoimax, wcstoumax - convert wide-character string to integer

//SYNOPSIS
#include <stddef.h>
#include <inttypes.h>

 intmax_t wcstoimax(const wchar_t *nptr, wchar_t **endptr, int base);
uintmax_t wcstoumax(const wchar_t *nptr, wchar_t **endptr, int base);

