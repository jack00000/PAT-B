/*科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，
即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。
现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。
输入格式：
每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。
输出格式：
对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。
输入样例1：
+1.23400E-03
输出样例1：
0.00123400
输入样例2：
-1.2E+10
输出样例2：
-12000000000
分析

该题主要考查对字符串的划分和处理。
1.首先要分别记录开始的正负号，中间的字符串，还有第二个正负号，以及最后的指数。
2.然后考虑两种处理方法，分别是第二个正负号为正或负的两种情况，处理方法见源代码。
类型转换时我用到了sstream中的stringstream，一般的用法如下：*/ 

//C/C++实现
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int status1 = (s[0] == '+' ? 0 : 1);
    int status2 = (s[s.find("E") + 1] == '+' ? 0 : 1);
    string index_s = s.substr(s.find("E") + 2, s.size() - s.find("E") - 2);
    stringstream sstream;
    sstream << index_s;
    int index = 0;
    sstream >> index;
    string num_s = s.substr(1, s.find("E") - 1);

    if(status1 != 0){
        printf("%c", '-');
    }
    if(status2 == 1){
        for(int i = 0; i < index; ++i){
            printf("%c", '0');
            if(i == 0){
                printf("%c", '.');
            }
        }
        printf("%c", num_s[0]);
        for(int j = 2; j < num_s.size(); ++j){
            printf("%c", num_s[j]);
        }
        printf("%c", '\n');
    }
    else if(status2 == 0){
        printf("%c", num_s[0]);
        int count = 0;
        for(int k = 2; k < num_s.size(); ++k){
            if(count == index){
                printf("%c", '.');
            }
            printf("%c", num_s[k]);
            ++count;
        }
        for(int l = 0; l < index - count; ++l){
            printf("%c", '0');
        }
        printf("%c", '\n');
    }
    return 0;
}
 
