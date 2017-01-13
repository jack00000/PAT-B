/*字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P),第4位(A),第6位(T)；第二个PAT是第3位(P),第4位(A),第6位(T)。
现给定字符串，问一共可以形成多少个PAT？
输入格式：
输入只有一行，包含一个字符串，长度不超过10^5，只包含P、A、T三种字母。
输出格式：
在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。
输入样例：
APPAPT
输出样例：
2
分析

开始先是想了一个暴力算法结果超时了，最坏要计算10^3次，后来再参考了别人的代码才学会了这个方法。
简单来说就是：
从末尾开始遍历
1.先找到T的个数；
2.再找到A的个数，每次找到后都把A后面的T的个数加上，作为AT的个数；
3.再找到P的个数，每次找到后都把P后面的AT的个数加上。
最后对1000000007取余输出结果，屌屌的。

源代码
*/
//C/C++实现（暴力法超时）
#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    long long count = 0;
    int indexP = s.find('P');
    while(indexP != -1){
        int indexA = s.find('A', indexP + 1);
        while(indexA != -1){
            int indexT = s.find('T', indexA + 1);
            while(indexT != -1){
                ++count;
                indexT = s.find('T', indexT + 1);
            }
            indexA = s.find('A', indexA + 1);
        }
        indexP = s.find('P', indexP + 1);
    }
    printf("%lld\n", count % (long long)1000000007);
    return 0;
}
