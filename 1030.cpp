/* 
输入格式：
输入第一行给出正整数N（<= 100）是输入的身份证号码的个数。随后N行，每行给出1个18位身份证号码。
输出格式：
按照输入的顺序每行输出1个有问题的身份证号码。这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。如果所有号码都正常，则输出“All passed”。
输入样例1：
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
输出样例1：
12010X198901011234
110108196711301866
37070419881216001X
输入样例2：
2
320124198808240056
110108196711301862
输出样例2：
All passed
分析

读入字符串，然后将其按权重相加，根据对11取余的结果，得出最后一位的数值，再跟读入字符串的最后一位比较，若相等，则不输出，若不相等，则输出此字符串。
另外，还要定义一个bool类型的变量或者int型变量，记录是否全部正确，这里方法有很多种，选一种实现即可，若全部正确再输出All passed即可。

源代码*/ 

//C/C++实现
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    string s;
    int sum = 0;
    char tmp;
    bool flag = true;
    for(int i = 0; i < n; ++i){
        cin >> s;
        sum = (s[0] - 48) * 7 + (s[1] - 48) * 9 + (s[2] - 48) * 10 + (s[3] - 48) * 5 +
            (s[4] - 48) * 8 + (s[5] - 48) * 4 + (s[6] - 48) * 2 + (s[7] - 48) +
            (s[8] - 48) * 6 + (s[9] - 48) * 3 + (s[10] - 48) * 7 + (s[11] - 48) * 9 +
            (s[12] - 48) * 10 + (s[13] - 48) * 5 + (s[14] - 48) * 8 + (s[15] - 48) * 4 +
            (s[16] - 48) * 2;
        switch(sum % 11){
            case 0: tmp = '1';break;
            case 1: tmp = '0';break;
            case 2: tmp = 'X';break;
            case 3: tmp = '9';break;
            case 4: tmp = '8';break;
            case 5: tmp = '7';break;
            case 6: tmp = '6';break;
            case 7: tmp = '5';break;
            case 8: tmp = '4';break;
            case 9: tmp = '3';break;
            case 10: tmp = '2';break;
        }
        if(s[17] != tmp){
            cout << s << endl;
            flag = false;
        }
    }
    if(flag){
        printf("All passed\n");
    }
    return 0;
}
