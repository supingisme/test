#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char s[1000];
	gets(s);
	int flag=0,i=0;
	int k=strlen(s);
	for(i;i<k;i++){
		if(s[i]!='+'){
			if(s[i]<'1' || s[i]>'9'){
				flag=1;
				break;
			}
		}
	}
	if(flag==1){
		for(i=0;i<k;i++){
	
			if(s[i]!='+'){
				printf("%c",s[i]);
			}
		}
	}else{
		char a[1000]={0};
		char c[100]={0};
		int f=0,count=0,num1=0,num2=0;
		
			for(i=0;i<k;i++){
	         
				if(s[i]!='+'){
					if(f==0){
						a[count]=(s[i]);
						count++;	
					}else{
						c[count]=(s[i]);
						count++;	
					}
				}else{
					f=1;
					count=0;
				}
			}
		
			for(i=0;i<strlen(a);i++){
				num1=num1+(a[i]-'0')*pow(10,strlen(a)-i-1);
			}
			for(i=0;i<strlen(c);i++){
				num2=num2+(c[i]-'0')*pow(10,strlen(c)-i-1);
			}
			printf("%d\n",num1+num2);
	}
	return 0;
}
	
