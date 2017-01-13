/*旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、
以及实际被输入的文字，请你列出肯定坏掉的那些键。
输入格式：
输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过80个字符的串，
由字母A-Z（包括大、小写）、数字0-9、以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。
输出格式：
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。
输入样例：
7_This_is_a_test
_hs_s_a_es
输出样例：
7TI
分析

1.首先声明一个数组来记录是否检测过对应的字符，注意，英文大写字母和小写字母用一个位置来检测，
小写字母-32即为大写字母。我这里用了三种状态：0为未判断，1为未损坏，-1为已损坏。
2.然后根据输入的第一个字符串遍历第二个字符串，如果发现有未检测的字符就进行检测，若检测后未找到就输出该字符。

需要注意的是大小写转换的时机。

遇到的坑：
这里我用的是string.find方法，按书上说是如果找到，返回下标；如果未找到，返回-1，我在使用时发现一个问题：

cout << "12345".find("6") <<endl;
输出的结果是4294967295，怀疑是find的返回类型默认是无符号整型，果然我在前面加上int转换就是-1了。

cout << (int)"12345".find("6") <<endl;
结果是-1

源代码*/ 

//C/C++实现
#include <iostream>
#include <string>

using namespace std;

//记录每个按键是否损坏
//0为未判断，1为未损坏，-1为已损坏
int isBroken[96]; 

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); ++i){
        if(s1[i] >= '0' && s1[i] <= '9'){
            if(isBroken[s1[i]] == 0){
                if((int)s2.find(s1[i]) >= 0){
                    isBroken[s1[i]] = 1;
                }
                else{
                    isBroken[s1[i]] = -1;
                    printf("%c", s1[i]);
                }
            }
        }
        else if(s1[i] >= 'A' && s1[i] <= 'Z'){
            if(isBroken[s1[i]] == 0){
                if((int)s2.find(s1[i]) >= 0){
                    isBroken[s1[i]] = 1;
                }
                else{
                    isBroken[s1[i]] = -1;
                    printf("%c", s1[i]);
                }
            }
        }
        else if(s1[i] >= 'a' && s1[i] <= 'z'){
            if(isBroken[s1[i] - 32] == 0){
                if((int)s2.find(s1[i]) >= 0){
                    isBroken[s1[i] - 32] = 1;
                }
                else{
                    isBroken[s1[i] - 32] = -1;
                    printf("%c", s1[i] - 32);
                }
            }
        }
        else if(s1[i] == '_'){
            if(isBroken['_'] == 0){
                if((int)s2.find('_') >= 0){
                    isBroken['_'] = 1;
                }
                else{
                    isBroken['_'] = -1;
                    printf("%c", '_');
                }
            }
        }
    }
    printf("%c", '\n');
    return 0;
}
