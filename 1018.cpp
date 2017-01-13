/*大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
输入格式：
输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。
C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
输出格式：
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，
中间有1个空格。如果解不唯一，则输出按字母序最小的解。
输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
分析

一共有9种情况，全部考虑到就可以，另外甲胜=乙负，甲负=乙胜，平局情况相同，可以节省几个变量。

遇到的坑：
使用scanf读取有效字符时一定要在前面加空格，因为：对于scanf()而言，%c是个较为特殊的说明符。 %c前没空格，scanf()将读取标准输入流中的第一个字符，%c前有空格，scanf()则读取标准输入流中第一个非空白字符。
*/ 

//C/C++实现
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int jiaWin = 0, jiaLose = 0, draw = 0;
    int jiaJWin = 0, jiaCWin = 0, jiaBWin = 0;
    int yiJWin = 0, yiCWin = 0, yiBWin = 0;
    char jia, yi;
    for(int i = 0; i < n; i++){
        scanf(" %c %c", &jia, &yi);
        if(jia == 'C'){
            if(yi == 'C'){
                draw++;
            }
            else if(yi == 'J'){
                jiaWin++;
                jiaCWin++;
            }
            else if(yi == 'B'){
                jiaLose++;
                yiBWin++;
            }
        }
        else if(jia == 'J'){
            if(yi == 'C'){
                jiaLose++;
                yiCWin++;
            }
            else if(yi == 'J'){
                draw++;
            }
            else if(yi == 'B'){
                jiaWin++;
                jiaJWin++;
            }
        }
        else if(jia == 'B'){
            if(yi == 'C'){
                jiaWin++;
                jiaBWin++;
            }
            else if(yi == 'J'){
                jiaLose++;
                yiJWin++;
            }
            else if(yi == 'B'){
                draw++;
            }
        }
    }
    printf("%d %d %d\n", jiaWin, draw, jiaLose);
    printf("%d %d %d\n", jiaLose, draw, jiaWin);
    printf("%c ", jiaBWin >= jiaCWin ? (jiaBWin >= jiaJWin ? 'B' : 'J') : (jiaCWin >= jiaJWin ? 'C' : 'J'));
    printf("%c\n", yiBWin >= yiCWin ? (yiBWin >= yiJWin ? 'B' : 'J') : (yiCWin >= yiJWin ? 'C' : 'J'));
    return 0;
}
  
