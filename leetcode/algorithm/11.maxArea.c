/*
11. 盛最多水的容器
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
*/
#include <stdio.h>


int maxArea(int* height, int heightSize){
    int i=0;
    int j=heightSize-1;
    int Areamax=0;
    while(i!=j)
    {
        if(height[i]<height[j])
        {
            Areamax=Areamax>=(j-i)*height[i]?Areamax:(j-i)*height[i];
            i++;
        }
        else
        {
            Areamax=Areamax>=(j-i)*height[j]?Areamax:(j-i)*height[j];
            j--;
        }
        
    }
    return Areamax;
}

int main()
{
	int h[] = {1,8,6,2,5,4,8,3,7,9};

	printf("%d\n", maxArea(h, sizeof(h)/sizeof(h[0])));
}
