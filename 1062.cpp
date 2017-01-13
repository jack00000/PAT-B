/*一个分数一般写成两个整数相除的形式：N/M，其中M不为0。最简分数是指分子和分母没有公约数的分数表示形式。
现给定两个不相等的正分数 N1/M1 和 N2/M2，要求你按从小到大的顺序列出它们之间分母为K的最简分数。
输入格式：
输入在一行中按N/M的格式给出两个正分数，随后是一个正整数分母K，其间以空格分隔。题目保证给出的所有整数都不超过1000。
输出格式：
在一行中按N/M的格式列出两个给定分数之间分母为K的所有最简分数，按从小到大的顺序，其间以1个空格分隔。
行首尾不得有多余空格。题目保证至少有1个输出。
输入样例：
7/18 13/20 12    列出它们之间分母为K的最简分数
输出样例：
5/12 7/12
分析

1.读入数据；
2.筛选出范围在[1,k]之间和k互质的数，放入数组；
3.判断输入的两个分数的大小，设置上下限；
4.若符合范围，则输出结果。

注意：输入的两个分数可能前>后，也可能后>前，所以要先判断大小，再设置上下限。

源代码
*/ 
//C/C++实现
#include <iostream>
#include <vector>

using namespace std;

bool prime(int m, int n){ //默认n为大数
    int remainder;
    while(m){
        remainder = n % m;
        n = m;
        m = remainder;
    }
    if(n == 1){ //最大公约数是1，则互质
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n1, m1, n2, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    vector<int> v;
    v.push_back(1);
    for(int i = 2; i < k; ++i){
        if(prime(i, k)){
            v.push_back(i);
        }
    }
    double r1 = (double)n1 / (double)m1;
    double r2 = (double)n2 / (double)m2;
    double lower, greater;
    if(r1 > r2){
        greater = r1;
        lower = r2;
    }
    else{
        greater = r2;
        lower = r1;
    }
    bool first = true;
    for(int i = 0; i < v.size(); ++i){
        double result = (double)v[i] / (double)k;
        if(first && result > lower && result < greater){
            first = false;
            printf("%d/%d", v[i], k);
        }
        else if(result > lower && result < greater){
            printf(" %d/%d", v[i], k);
        }
    }
    printf("\n");
    return 0;
}
