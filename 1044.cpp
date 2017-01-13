/*火星人是以13进制计数的：

地球人的0被火星人称为tret。
地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。为了方便交流，请你编写程序实现地球和火星数字之间的互译。
输入格式：
输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。
输出格式：
对应输入的每一行，在一行中输出翻译后的另一种语言的数字。
输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13
分析

看到这个题，我第一次就很自然的写了个进制转换的方法，但是发现并不用那么麻烦。还要仔细读题后再作答，题目中明明写了[0,169)的数字，换算一下在13进制下只可能是两位数，所以不用那么麻烦，只要把所有情况都考虑到就好了。
1.首先根据首位字符判断是地球数字还是火星数字，然后分别写处理方法；
2.这里稍微有难度的就是对火星数字的处理，首先先分类，我分成了小于等于4位的输入和4位以上的输入。前者有可能是0-12，也有可能是13的整数倍的数，这里需要注意的是：火星数字除了单独是0的时候写0，只要高位数字有数，个位数字如果是0就省略不写。后者肯定是>13的火星数字，先让0-2位与高位数的火星数字比较，如果相同，则输出；再让4-6位与低位数的火星数字比较，如果相同，则输出即可。
这里我的方法会遇到一个坑就是：
equal的范围是左闭右开区间，所以想比较0-2位的话必须要比较到s.begin()+3的位置上，才是0-2位。

另外，这道题还需要注意的点有：
1.因为是要读入带空格的字符串，所以要这样getline(cin, s);
2.用getline之前要清空cin流

cin.clear();
cin.ignore();
源代码
*/
//C/C++实现
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    string mars1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string mars2[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    cin >> n;
    cin.clear(); 
    cin.ignore();//后面用getline，所以要清空cin流 
    string s;
    for(int i = 0; i < n; ++i){
        getline(cin, s);
        if(s[0] >= '0' && s[0] <= '9'){ //地球数字 
            stringstream ss;
            ss << s;
            int num;
            ss >> num;
            if(num < 13){
                cout << mars1[num] << endl;
            }
            else{
                if(num % 13 == 0){
                    cout << mars2[num / 13] << endl;
                }
                else{
                    cout << mars2[num / 13] << " " << mars1[num % 13] << endl;
                }
            }
        }
        else{ //火星数字 
            if(s.size() <= 4){
                for(int j = 0; j < 13; ++j){
                    if(s == mars1[j]){
                        printf("%d\n", j);
                        break;
                    }
                    else if(s == mars2[j]){
                        printf("%d\n", j * 13);
                        break;
                    }
                }
            }
            else{
                int num = 0;
                for(int j = 0; j < 13; ++j){
                    if(equal(s.begin(), s.begin() + 3, mars2[j].begin())){ //equal范围是左闭右开区间，所以要+3 
                        num += j * 13;
                        break;
                    }
                }
                for(int j = 0; j < 13; ++j){
                    if(equal(s.begin() + 4, s.end(), mars1[j].begin())){
                        num += j;
                        printf("%d\n", num);
                        break;
                    }
                }
            }
        }
    }
    return 0;
