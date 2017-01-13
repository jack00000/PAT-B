/*请编写程序，找出一段给定文字中出现最频繁的那个英文字母。
输入格式：
输入在一行中给出一个长度不超过1000的字符串。字符串由ASCII码表中任意可见字符及空格组成，
至少包含1个英文字母，以回车结束（回车不算在内）。
输出格式：
在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，
则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。
输入样例：
This is a simple TEST. There ARE numbers and other symbols 1&2&3...........
输出样例：
e 7
分析

首先建个英文字母的数组，记录每个英文字母出现的次数，然后先读入一行字符串，然后遍历字符串进行判断，
出现对应字母就将数组中的指定位置自增1，最后遍历整个数组输出最大频率及出现频率最高的字符。

源代码
*/
//C/C++实现
#include <iostream>
#include <string.h>

using namespace std;

int ascii[26]; //26个字母 

int main(){
    char c[1001];
    gets(c);
    int max = 0;
    char maxChar;
    for(int i = 0; i < strlen(c); ++i){
        if(c[i] >= 'A' && c[i] <= 'Z'){
            ++ascii[c[i] - 65];
        }
        else if(c[i] >= 'a' && c[i] <= 'z'){
            ++ascii[c[i] - 97];
        }
    }
    for(int i = 0; i < 26; ++i){
        if(ascii[i] > max){
            max = ascii[i];
            maxChar = i + 97;
        }
    }
    printf("%c %d\n", maxChar, max);
    return 0;
}
