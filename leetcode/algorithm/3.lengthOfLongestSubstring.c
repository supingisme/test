/*
3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

#include <stdio.h>
#include <string.h>

#ifdef DEBUG
void debug_map(char *map, int map_len)
{
	int i;
	printf(">>");
	for(i=0;i<map_len;i++) {
		printf("%c ", i+'a');
	}printf("\n");
	printf("  ");
	for(i=0;i<map_len;i++) {
		printf("%1d ", map[i]);
	}printf("\n");
}

void debug_s(char *s, int s_len, int start, int end)
{
	int i;
	printf(">>");
	for(i=0;i<s_len;i++) {
		printf("%c ", *(s+i));
	}printf("\n");
	printf("  ");
	for(i=0;i<s_len;i++) {
		printf("%c ", i==start?'^':(i==end?'^':' '));
	}printf("\n");
}

void debug(char *map, int map_len, char *s, int s_len, int start, int end)
{
	system("clear");
	debug_map(map, map_len);
	debug_s(s, s_len, start, end);
	sleep(3);
}
#endif

/* 
>>a b c d e f g h i j 
  1 1 0 0 0 0 0 0 0 0 
>>a b c a b c b b 
  ^ ^             
>>a b c d e f g h i j 
  1 1 1 0 0 0 0 0 0 0 
>>a b c a b c b b 
  ^   ^           
>>a b c d e f g h i j 
  1 1 1 0 0 0 0 0 0 0 
>>a b c a b c b b 
    ^   ^         
>>a b c d e f g h i j 
  1 1 1 0 0 0 0 0 0 0 
>>a b c a b c b b 
      ^   ^       
>>a b c d e f g h i j 
  1 1 1 0 0 0 0 0 0 0 
>>a b c a b c b b 
        ^   ^     
>>a b c d e f g h i j 
  0 1 1 0 0 0 0 0 0 0 
>>a b c a b c b b 
            ^ ^   
>>a b c d e f g h i j 
  0 1 0 0 0 0 0 0 0 0 
>>a b c a b c b b 
                ^ 
>>a b c d e f g h i j 
  0 1 0 0 0 0 0 0 0 0 
>>a b c a b c b b 
                ^ 
 */
int lengthOfLongestSubstring(char * s){
	int start = 0, end = 0, maxlen = 0;
    char map[256] = {0};

	//首字符的位置标记为1
	map[(int)*(s+start)] = 1;
    
	//字符串结尾
    while( *(s+end) != 0 )
    {
		//头尾指针间隔与maxlen比较，取较大值
        maxlen = maxlen>(end-start+1)?maxlen:(end-start+1);
		//end后移一位
        ++end;
		//若将要加入的新元素与map内元素冲突，则结束循环
        while( 0 != map[ (int)*(s+end) ] )
        {
			//start位置标记为0
            map[ (int)*(s+start) ] = 0;
			//start指针后移一位
            ++start;
        }
		//end处标记为1
        map[(int)*(s+end)] = 1;
		#ifdef DEBUG
		debug(map+'a', 10, s, strlen(s), start, end);
		#endif
    }
    
    return maxlen;
}

int main(int argc, char *argv[])
{
	printf("%s -> %d\n", argv[1], lengthOfLongestSubstring(argv[1]));
}
