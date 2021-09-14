#include <stdio.h>
#include <sys/types.h>
#include <regex.h>

int main(void)
{
	int status = 0, i = 0;
	int flag = REG_EXTENDED;
	regmatch_t pmatch[1];
	const size_t nmatch = 1;
	regex_t reg;
	const char *pattern = "^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$";
	char *buf = "123456789@qq.com";//success
	// char *buf = "###270401@163.com";//error

	regcomp(&reg, pattern, flag);
	status = regexec(&reg, buf, nmatch, pmatch, 0);
	if(status == REG_NOMATCH){
		printf("no match\n");
	}else if(status == 0){
		printf("match success\n");
		for(i = pmatch[0].rm_so; i < pmatch[0].rm_eo; i++){
			putchar(buf[i]);
		}
		putchar('\n');
	}
	regfree(&reg);

	return 0;
}
