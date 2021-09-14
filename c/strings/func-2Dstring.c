#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>

const char *oids[] = {
	"Device.DeviceInfo.SerialNumber",
	"Device.DeviceInfo.Rongtao",
	NULL,
};
#define OIDS_NUM ({int num = 0, __i; \
	for(__i=0; ; __i++) { \
		if(oids[__i]) num++; \
		else break;\
	}\
	num;\
})

char **get_oids(char ** get, int *size)
{
	get = (char**)malloc(sizeof(char*)*OIDS_NUM);
	*size = OIDS_NUM;
	int i;
	for(i=0;i<*size;i++) {
		get[i] = malloc(strlen(oids[i])+1);
		strcpy(get[i], oids[i]);
	}
	return get;
}

int main()
{
	printf("OID num: %d\n", OIDS_NUM);

	int size;
	char **getoids = get_oids(NULL, &size);
	int i;
	for(i=0;i<size;i++) {
		printf("%s\n", getoids[i]);
	}
	return 0;
}	
