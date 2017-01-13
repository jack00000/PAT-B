/*给定一个k位整数N = dk-1*10^(k-1) + ... + d1*10^1 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)，
请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。
输入格式：
每个输入包含1个测试用例，即一个不超过1000位的正整数N。
输出格式：
对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。
输入样例：
100311
输出样例：
0:2
1:3
3:1
分析

读取一个字符串或者直接读入一行，然后根据字符串大小遍历，挨个比对，然后输出时判断下是否是0，如果0就不输出结果。*/ 

//C/C++实现
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char c[1000];
    gets(c);
    int count[10] = {0,0,0,0,0,0,0,0,0,0};
    for(int i = 0; i < strlen(c); ++i){
        if(c[i] - 48 == 0){
            count[0]++;
        }
        else if(c[i] - 48 == 1){
            count[1]++;
        }
        else if(c[i] - 48 == 2){
            count[2]++;
        }
        else if(c[i] - 48 == 3){
            count[3]++;
        }
        else if(c[i] - 48 == 4){
            count[4]++;
        }
        else if(c[i] - 48 == 5){
            count[5]++;
        }
        else if(c[i] - 48 == 6){
            count[6]++;
        }
        else if(c[i] - 48 == 7){
            count[7]++;
        }
        else if(c[i] - 48 == 8){
            count[8]++;
        }
        else if(c[i] - 48 == 9){
            count[9]++;
        }
    }
    for(int j = 0; j < 10; ++j){
        if(count[j] != 0){
            printf("%d:%d\n", j, count[j]);
        }
    }
    return 0;
}

