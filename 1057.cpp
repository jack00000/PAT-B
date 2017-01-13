/*给定一串长度不超过10^5的字符串，本题要求你将其中所有英文字母的序号
（字母a-z对应序号1-26，不分大小写）相加，得到整数N，
然后再分析一下N的二进制表示中有多少0、多少1。例如给定字符串“PAT (Basic)”，
其字母序号之和为：16+1+20+2+1+19+9+3=71，而71的二进制是1000111，即有3个0、4个1。
输入格式：
输入在一行中给出长度不超过10^5、以回车结束的字符串。
输出格式：
在一行中先后输出0的个数和1的个数，其间以空格分隔。
输入样例：
PAT (Basic)
输出样例：
3 4
分析

题目难度不大，就是先用C语言的gets函数或者C++的getline函数读入一行，然后计算换算成a-z的数字，
求个和，最后转换成二进制，然后遍历一下判断0和1的个数，最后输出即可。

源代码
*/ 
//C/C++实现
#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    int sum = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            sum += ((int)s[i] - 64);
        }
        else if(s[i] >= 'a' && s[i] <= 'z'){
            sum += ((int)s[i] - 96);
        }
    }
    int tmp = sum;
    int count0 = 0, count1 = 0;
    while(tmp != 0){
        if(tmp % 2 == 0){
            ++count0;
        }
        else{
            ++count1;
        }
        tmp /= 2;
    }
    printf("%d %d\n", count0, count1);
    return 0;
}
