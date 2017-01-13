/*大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母
（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头
（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（
从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
输入格式：
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。
输出格式：
在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，
WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。
输入样例：
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
输出样例：
THU 14:04*/
//C/C++实现
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char a[60], b[60], c[60], d[60];
    char week, hour;
    int minute;
    int equals = 1;
    gets(a);
    gets(b);
    gets(c);
    gets(d);
    int len1 = strlen(a) > strlen(b) ? strlen(b) : strlen(a);
    for(int i = 0; i < len1; i++){
        if(equals == 1){
            if(a[i] >= 'A' && a[i] <= 'G'&& b[i] >= 'A' && b[i] <= 'G'){
                if(a[i] == b[i]){
                    week = a[i];
                    equals++;
                }
            }
        }
        else if(equals == 2){
            if((a[i] >= '0' && a[i] <= '9' || a[i] >= 'A' && a[i] <= 'N') && (b[i] >= '0' && b[i] <= '9' || b[i] >= 'A' && b[i] <= 'N')){
                if(a[i] == b[i]){
                    hour = a[i];
                    break;
                }
            }
        }
    }
    int len2 = strlen(c) > strlen(d) ? strlen(d) : strlen(c);
    for(int j = 0; j < len2; j++){
        if((c[j] >= 'a' && c[j] <= 'z' || c[j] >= 'A' && c[j] <= 'Z') && (d[j] >= 'a' && d[j] <= 'z' || d[j] >= 'A' && d[j] <= 'Z')){
            if(c[j] == d[j]){
                minute = j;
                break;
            }
        }
    }
    switch(week){
        case 'A': printf("MON ");break;
        case 'B': printf("TUE ");break;
        case 'C': printf("WED ");break;
        case 'D': printf("THU ");break;
        case 'E': printf("FRI ");break;
        case 'F': printf("SAT ");break;
        case 'G': printf("SUN ");break;
    }
    if(hour >= '0' && hour <= '9'){
        printf("0%c:", hour);
    }
    else if(hour >= 'A' && hour <= 'N'){
        switch(hour){
            case 'A': printf("10:");break;
            case 'B': printf("11:");break;
            case 'C': printf("12:");break;
            case 'D': printf("13:");break;
            case 'E': printf("14:");break;
            case 'F': printf("15:");break;
            case 'G': printf("16:");break;
            case 'H': printf("17:");break;
            case 'I': printf("18:");break;
            case 'J': printf("19:");break;
            case 'K': printf("20:");break;
            case 'L': printf("21:");break;
            case 'M': printf("22:");break;
            case 'N': printf("23:");break;
        }
    }
    printf("%02d\n", minute);
    return 0;
}
