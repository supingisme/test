#include <stdio.h>
#include <string.h>
#include <stdarg.h>


const char *vstrcat(unsigned long nstr, ...) 
{
	static char S[1024] = {0};
	memset(S, 0x00, sizeof(S));

	va_list va;
	va_start(va, nstr);
	int i;
	for(i=0;i<nstr;i++){
		char *s = va_arg(va, char*);
		strcat(S, s);
		//printf("%s\n", s);
	}
	va_end(va);
	return (char*)S;
}

const char *xml_xpath_1(const char *root, const char *s1)
{
	return vstrcat(4, "/", root, "/", s1);
}
const char *xml_xpath_2(const char *root, const char *s1, const char *s2)
{
	return vstrcat(6, "/", root, "/", s1, "/", s2);
}
const char *xml_xpath_3(const char *root, const char *s1, const char *s2, const char *s3)
{
	return vstrcat(8, "/", root, "/", s1, "/", s2, "/", s3);
}
const char *xml_xpath_4(const char *root, const char *s1, const char *s2, const char *s3, const char *s4)
{
	return vstrcat(10, "/", root, "/", s1, "/", s2, "/", s3, "/", s4);
}




int main()
{
	printf("%s\n", vstrcat(3, "rongtao", "is", "me"));
	printf("%s\n", xml_xpath_1("root", "cell"));
	printf("%s\n", xml_xpath_2("root", "cell", "plmn"));
	printf("%s\n", xml_xpath_3("root", "cell", "plmn", "info"));
	printf("%s\n", xml_xpath_4("root", "cell", "plmn", "info", "csdn"));

	return 0;
}
