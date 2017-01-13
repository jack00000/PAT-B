/*如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。
例如123和51就是朋友数，因为1+2+3 = 5+1 = 6，而6就是它们的朋友证号。给定一些整数
要求你统计一下它们中有多少个不同的朋友证号。注意：我们默认一个整数自己是自己的朋友。
输入格式：
输入第一行给出正整数N。随后一行给出N个正整数，数字间以空格分隔。题目保证所有数字小于10^4。
输出格式：
首先第一行输出给定数字中不同的朋友证号的个数；随后一行按递增顺序输出这些朋友证号，数字间隔一个空格，且行末不得有多余空格。
输入样例：
8
123 899 51 998 27 33 36 12
输出样例：
4
3 6 9 26     朋友证号
分析

1.先把每个数各位之和加起来；
2.判断数组中有没有这个数，如果没有这个数的话，加到数组里；
3.给数组排序（升序）；
4.输出结果。

源代码
*/ 
//C/C++实现
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> v;
    string s;
    int sum;
    for(int i = 0; i < n; ++i){
        cin >> s;
        sum = 0;
        for(int j = 0; j < s.size(); ++j){
            sum += s[j] - '0';
        }
        vector<int>::iterator result = find(v.begin(), v.end(), sum);
        if(result == v.end()){ //如果没找到，再添加进去，防止重复 
            v.push_back(sum);
        }
    }
    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for(int i = 0; i < v.size(); ++i){
        if(i == 0){
            printf("%d", v[i]);
        }
        else{
            printf(" %d", v[i]);
        }
    }
    printf("\n");
}
