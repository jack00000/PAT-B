/*本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，
将其每1位数字与A的对应位置上的数字进行以下运算：对奇数位，
对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，
用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。
输入格式：
输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。
输出格式：
在一行中输出加密后的结果。
输入样例：
1234567 368782971
输出样例：
3695Q8118
分析

1.首先读入两个字符串，然后根据长度差，为短的串在前面补0，为了方便之后的运算。
2.到了这一步，肯定两个字符串是一样长了，再按位数从后向前对比，将每位计算的结果存入新的字符串，然后输出结果。

源代码
*/
//C/C++实现
#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    string result = "";
    if(s1.size() > s2.size()){ //前面长 
        int val = s1.size() - s2.size();
        s2 = string(val, '0') + s2;
    }
    else if(s1.size() < s2.size()){ //后面长 
        int val = s2.size() - s1.size();
        s1 = string(val, '0') + s1;
    }
    int count = 1; //位数 
    for(int i = s1.size() - 1; i >= 0; --i){
        if(count % 2 == 1){ // 奇数
            int rest = (s1[i] + s2[i] - 2 * '0') % 13;
            if(rest >=0 && rest < 10){
                result = (char)(rest + '0') + result;
            }
            else if(rest == 10){
                result = "J" + result;
            }
            else if(rest == 11){
                result = "Q" + result;
            }
            else if(rest == 12){
                result = "K" + result;
            }
        }
        else{ //偶数 
            int tmp = s2[i] - s1[i];
            if(tmp < 0){
                tmp += 10;
            }
            result = (char)(tmp + '0') + result;
        }
        ++count;
    }
    cout << result << endl;
    return 0;
}
