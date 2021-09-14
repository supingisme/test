//29. 两数相除
//给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
//
//返回被除数 dividend 除以除数 divisor 得到的商。
//
//整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
//示例 1:
//
//输入: dividend = 10, divisor = 3
//输出: 3
//解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
//示例 2:
//
//输入: dividend = 7, divisor = -3
//输出: -2
//解释: 7/-3 = truncate(-2.33333..) = -2
// 
//
//提示：
//
//被除数和除数均为 32 位有符号整数。
//除数不为 0。
//假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

#include <stdio.h>
#include <limits.h>
//本质就是返回被除数能被除数分成多少份的个数。
//然而被除数太大且除数太小循环时间必然过长，所以采用了三层累加的算法大大降低了循环次数。
//除数和被除数采用负数减少溢出和判断的if-else语句
//sum+=dividend
//sums+=sum
//sumss+=sums
//


#if 1
//越界问题只要对除数是1和-1单独讨论就完事了啊
//关于如何提高效率快速逼近结果
//举个例子：11 除以 3 。
//首先11比3大，结果至少是1， 然后我让3翻倍，就是6，发现11比3翻倍后还要大，
//那么结果就至少是2了，那我让这个6再翻倍，得12，11不比12大，吓死我了，
//差点让就让刚才的最小解2也翻倍得到4了。但是我知道最终结果肯定在2和4之间。
//也就是说2再加上某个数，这个数是多少呢？我让11减去刚才最后一次的结果6，
//剩下5，我们计算5是3的几倍，也就是除法，看，递归出现了。说得很乱，不严谨，
//大家看个大概，然后自己在纸上画一画，或者直接看我代码就好啦！
//
//作者：liujin-4
//链接：https://leetcode-cn.com/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int divide(int dividend, int divisor) {
    if(dividend == 0) return 0;
    if(divisor == 1) return dividend;
    if(divisor == -1){
        if(dividend>INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
        return INT_MAX;// 是最小的那个，那就返回最大的整数啦
    }
    long a = dividend;
    long b = divisor;
    int sign = 1; 
    if((a>0&&b<0) || (a<0&&b>0)){
        sign = -1;
    }
    a = a>0?a:-a;
    b = b>0?b:-b;
    long res = div(a,b);
    if(sign>0)return res>INT_MAX?INT_MAX:res;
    return -res;
}
int div(long a, long b){  // 似乎精髓和难点就在于下面这几句
    if(a<b) return 0;
    long count = 1;
    long tb = b; // 在后面的代码中不更新b
    while((tb+tb)<=a){
        count = count + count; // 最小解翻倍
        tb = tb+tb; // 当前测试的值也翻倍
    }
    return count + div(a-tb,b);
}


#else


#define INT_MAX 0X7FFFFFFF
#define INT_MIN 0X80000000
int divide(int dividend, int divisor){
    if(dividend==INT_MIN&&divisor==-1)return INT_MAX;
    if(dividend==INT_MIN&&divisor==1)return INT_MIN;
    if(dividend==INT_MIN&&divisor==INT_MAX)return -1;
    if(dividend==divisor)return 1;
    int sum=0,t=0;//第一层累加数
    int sums=0,ts=0;//第二层累加数
    int sumss=0,tss=0;//第三层累加数
    int res=0;
    int flat=(dividend^divisor);//结果正负标志位
    if(dividend!=INT_MIN) dividend=(dividend<0)?dividend:-dividend;//被除数取负值
    if(divisor!=INT_MIN) divisor=(divisor<0)?divisor:-divisor;//除数取负值
    while(dividend<=divisor){//暴力累加法
            sum+=divisor;
            t--; 
        if(sums-1>(INT_MIN-sum)){//第一层累加是否超出
            sums+=sum;
            ts+=t;   
        }
        if(sumss-1>(INT_MIN-sums)){//第二层累加是否超出
            sumss+=sums;
            tss+=ts;  
        }
        if(dividend-sumss<0){//判断三层累加是否超出
            res+=tss;
            dividend-=sumss;
        }else{//超出则普通累加
            res--;
            dividend-=divisor;
            sum=0;
            t=0;
            sums=0;
            ts=0;
            sumss=0;
            tss=0;
        }
    }
       return(flat<0)?res:-res;
}
#endif


int main(int argc, char *argv[]) {
    int a,b,c;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = divide(a, b);
    printf("%d/%d=%d\n", a, b, c);
}

