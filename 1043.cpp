/*给定一个长度不超过10000的、仅由英文字母构成的字符串。
请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。
当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，
则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。
输入格式：
输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。
输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。
输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee
分析

用6个变量记录PATest的出现次数，然后按照从P到t的顺序输出，每输出一次把计数器自减1，最终全为0时，停止输出即可。

源代码
*/
//C/C++实现
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char c[10001];
    gets(c);
    int countP = 0, countA = 0, countT = 0, counte = 0, counts = 0, countt = 0;
    for(int i = 0; i < strlen(c); ++i){
        if(c[i] == 'P'){
            ++countP;
        }
        else if(c[i] == 'A'){
            ++countA;
        }
        else if(c[i] == 'T'){
            ++countT;
        }
        else if(c[i] == 'e'){
            ++counte;
        }
        else if(c[i] == 's'){
            ++counts;
        }
        else if(c[i] == 't'){
            ++countt;
        }
    }
    while(countP != 0 || countA !=0 || countT !=0 || counte != 0 || counts !=0 || countt !=0){
        if(countP != 0){
            printf("P");
            --countP;
        }
        if(countA != 0){
            printf("A");
            --countA;
        }
        if(countT != 0){
            printf("T");
            --countT;
        }
        if(counte != 0){
            printf("e");
            --counte;
        }
        if(counts != 0){
            printf("s");
            --counts;
        }
        if(countt != 0){
            printf("t");
            --countt;
        }
    }
    printf("\n");
    return 0;
}
