/*C/C++实现让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。
输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。
输出格式：每个测试用例的输出占一行，用规定的格式输出n。
输入样例1：
234
输出样例1：
BBSSS1234
输入样例2：
23
输出样例2：
SS123*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main(){
    int n, count = 0, ge = 0, shi = 0, bai = 0;
    scanf("%d", &n);
    while(n != 0){
        if(count == 0){
            ge = n % 10;
            n /= 10;
            count ++;
        }
        else if(count == 1){
            shi = n % 10;
            n /= 10;
            count ++;
        }
        else{
            bai = n % 10;
            n /= 10;
        }
    }
    if(bai != 0){
        for(int i=0;i<bai;i++){
            printf("%c", 'B');
        }
    }
    if(shi != 0){
        for(int j=0;j<shi;j++){
            printf("%c", 'S');
        }
    }
    if(ge != 0){
        for(int k=0;k<ge;k++){
            printf("%d", k+1);
        }
    }
    printf("%c", '\n');
    return 0;
}
