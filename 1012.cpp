/*令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。
输入格式：
输入在一行中给出M和N，其间以空格分隔。
输出格式：
输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103*/
//C/C++实现
#include <stdio.h>
#include <iostream>

using namespace std;

int PNarray[10000] = {2}; //PNarray[0] = 2;

bool isPrimeNumber(int n, int PNarray[]){
    for(int i = 0; PNarray[i] * PNarray[i] <= n; i++){
        if(n % PNarray[i] == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int index = 1;
    for(int i = 3; index < b; i += 2){ //建立到第b个数的素数表
        if(isPrimeNumber(i, PNarray)){ //is prime number
            PNarray[index++] = i; //store in prime number table//素数存在表中 
        }
    }
    int count = 0;
    for(int j = a - 1; j < b; j++){
        if(count % 10 != 0){
            printf("%c", ' ');
        }
        printf("%d", PNarray[j]);
        count++;
        if(count % 10 == 0){
            printf("%c", '\n');//10个数一行 
        }
    }
   
    return 0;
}
