/*
5. 最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/
#include <stdio.h>
#include <string.h>


/*
 *	a * b * c * b * a
 *	0 1 2 3 4 5 6 7 8
 */

char * longestPalindrome(char * s){
	if(!s) return NULL;
	
	char *ss = NULL;
	int start = 0, end = 0, maxlen = 0, len;
	int iex = 0;
	int s_len = strlen(s);
	
	/* 轮询添加过星符号变量的字符串遍历 */
	for(iex=0; iex<s_len*2-1; iex++) 
	{
		/* 如果是中间添加的星符号变量 */
		int is_star = (iex%2!=0);
		
		for(start=iex-(is_star?1:0), end = iex + (is_star?1:0); 
			start <= end && start >= 0 && end < s_len*2-1;
			start-=2, end+=2) 
		{
			//printf("%d (%d, %d)\n", iex, start, end);

			if(s[start/2] == s[end/2]) 
			{
				len = (end)/2 - (start)/2 + 1;
				if(len > maxlen) 
				{
					maxlen = len;
					ss = &s[(start)/2];
				}
				//printf("  maxlen = %d\n", maxlen);
			} else break;
		}
	}

	ss = strndup(ss, maxlen);
	return ss;
}

int main(int argc, char *argv[]) {

	printf("%s -> %s\n", argv[1], longestPalindrome(argv[1]));
	return 0;
}

