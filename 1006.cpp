/*C/C++实现让我们定义 dn为：dn = pn + 1- pn，其中 pi是第i个素数。显然有 d1=1 且对于n>1有 dn是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。
输入格式：每个测试输入包含1个测试用例，给出正整数N。
输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。
输入样例：
20
输出样例：
4*/ 
#include <stdio.h>
#include <iostream>

using namespace std;

bool array[100000];

int main(){
    int n;//数的范围 
    scanf("%d", &n);
    for(int i=2;i<n/2+1;i++){
        for(int j=2;j*i<=n;j++){
            array[i*j] = true;
        }
    }
    int count = 0, tmp = 2;
    for(int k=2;k<=n;k++){
        if(array[k] == false){
            if(k - tmp == 2){
                count ++;
                tmp = k;
            }
            else{
                tmp = k;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
