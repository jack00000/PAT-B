/*正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
现给定A、DA、B、DB，请编写程序计算PA + PB。
输入格式：
输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
输出格式：
在一行中输出PA + PB的值。
输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0*/
/*分析

思路就是分别记录A中DA出现的次数和B中DB出现的次数，然后根据其次数，得出实际的PA和PB，最终相加即可。*/

//C/C++实现
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main(){
    char a[11], b[11];
    char da, db;
    int count1 = 0, count2 = 0;
    int sum1 = 0, sum2 = 0;
    scanf("%s %c %s %c", a, &da, b, &db);
    for(int i = 0; i < strlen(a); i++){
        if(a[i] == da){
            count1++;
        }
    }
    for(int j = 0; j < count1; j++){
        sum1 += (int)(da - '0') * pow((double)10, j);
    }
    for(int i = 0; i < strlen(b); i++){
        if(b[i] == db){
            count2++;
        }
    }
    for(int j = 0; j < count2; j++){
        sum2 += (int)(db - '0') * pow((double)10, j);
    }
    printf("%d\n", sum1 + sum2);
    return 0;
} 
