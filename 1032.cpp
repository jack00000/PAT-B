/*旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，
打出的结果文字会是怎样？
输入格式：
输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过105个字符的串。可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。题目保证第2行输入的文字串非空。
注意：如果上档键坏掉了，那么大写的英文字母无法被打出。
输出格式：
在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。
输入样例：
7+IE.
7_This_is_a_test.
输出样例：
_hs_s_a_tst
分析

先声明一个数组，作为坏键的表，然后根据读入的第一个字符串，将坏键都标记为-1，需要注意的是：如果读入的是大写字母，需要将其对应的小写字母也置为-1，读入小写字母也要将其对应的大写字母置为-1；读入为'+'的话需要将全部大写字母置为-1。其他的，只需要将其对应的键置为-1即可。

注意：1.如果没有一个字符能被打出，则输出空行；

遇到的坑：
2.题目原话：“,”、“.”、“-”、“+”（代表上档键），结果我以为是这些符号都代表上档键了；
3.题目中要求说：题目保证第2行输入的文字串非空，也就是说第1行是可以为空的，所以还要为这种情况单独写一个处理方法，读入时用cin肯定是不行了，因为cin无法读入空格，所以针对第一个字符串，选用getline(cin, s1)方式，即可。

源代码
*/ 
//C/C++实现
#include <iostream>
#include <string>

using namespace std;

int isBroken[122];

int main(){
    string s1, s2;
    getline(cin, s1);
    cin >> s2;
    bool noBroken = true;
    for(int i = 0; i < s1.size(); ++i){
        if(s1[i] != ' '){
            noBroken = false;
            break;
        }
    }
    if(noBroken){
        cout << s2 <<endl;
        return 0;
    }
    bool shiftBroken = false;
    bool allBroken = true;
    for(int i = 0; i < s1.size(); ++i){
        if(s1[i] == '+'){
            if(!shiftBroken){
                for(int j = 'A'; j <= 'Z'; ++j){
                    isBroken[j] = -1;
                }
                shiftBroken = true;
            }
        }
        else if(s1[i] >= 'A' && s1[i] <= 'Z'){
            isBroken[s1[i]] = -1;
            isBroken[s1[i] + 32] = -1;
        }
        else if(s1[i] >= 'a' && s1[i] <= 'z'){
            isBroken[s1[i]] = -1;
            isBroken[s1[i] - 32] = -1;
        }
        else{
            isBroken[s1[i]] = -1;
        }
    }
    for(int i = 0; i < s2.size(); ++i){
        if(isBroken[s2[i]] != -1){
            printf("%c", s2[i]);
            allBroken = false;
        }
        else{
            continue;
        }
    }
    printf("%c", '\n');
    return 0;
}
