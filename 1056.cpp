/*给定N个非0的个位数字，用其中任意2个数字都可以组合成1个2位的数字。
要求所有可能组合出来的2位数字的和。例如给定2、5、8，则可以组合出：25、28、52、58、82、85，它们的和为330。
输入格式：
输入在一行中先给出N（1<N<10），随后是N个不同的非0个位数字。数字间以空格分隔。
输出格式：
输出所有可能组合出来的2位数字的和。
输入样例：
3 2 8 5
输出样例：
330
分析

先读入数据到数组，再遍历数组，计算方法以样例为例：2 8 5

int sum = 0;
// 2 and 8
sum = sum + 2 * 10 + 8; //28
sum = sum + 8 * 10 + 2; //82
// 2 and 5
sum = sum + 2 * 10 + 5; //25
sum = sum + 5 * 10 + 2; //52
// 8 and 5
sum = sum + 8 * 10 + 5; //85
sum = sum + 5 * 10 + 8; //58
源代码
*/ 
//C/C++实现
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    int sum = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            sum += v[i] * 10 + v[j];
            sum += v[j] * 10 + v[i];
        }
    }
    printf("%d\n", sum);
    return 0;
}
