/*C语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：
0.冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
1.排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
2.其他人将得到巧克力。
给定比赛的最终排名以及一系列参赛者的ID，你要给出这些参赛者应该获得的奖品。
输入格式：
输入第一行给出一个正整数N（<=10000），是参赛者人数。随后N行给出最终排名，
每行按排名顺序给出一位参赛者的ID（4位数字组成）。接下来给出一个正整数K以及K个需要查询的ID。
输出格式：
对每个要查询的ID，在一行中输出“ID: 奖品”，其中奖品或者是“Mystery Award”
（神秘大奖）、或者是“Minion”（小黄人）、或者是“Chocolate”（巧克力）。如果所查ID根本不在排名里，
打印“Are you kidding?”（耍我呢？）。如果该ID已经查过了（即奖品已经领过了），打印“ID: Checked”（不能多吃多占）。
输入样例
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
输出样例：
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
分析

1.因为时间要求是200ms，素数求到10000，所以为防止超时，还是先建立10000以内的素数表吧；
2.接着每次输入，判断会得什么奖项，将对应的奖项编号存入得奖结果的数组中；
3.根据输入结果，查询奖项，若已查询，则将奖项编号置为-1，便于之后输出"Checked"。这里需要注意的是：若没有查询到结果，不要将其置为-1，参照输入样例，查询两次2222，结果均是" Are you kidding?"。

源代码
*/ 
//C/C++实现
#include <iostream>

using namespace std;

int award[10001];
int prime[10001];

int main(){
    //create prime table
    prime[1] = 1; //1不是素数 
    for(int i = 2; i <= 5000; ++i){
        for(int j = 2; i * j <= 10000; ++j){
            prime[i * j] = 1; //1为非素数 
        }
    }
    //input 
    int n;
    scanf("%d", &n);
    int tmp;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &tmp);
        if(i == 1){
            award[tmp] = 1; //神秘大奖 
        }
        else{
            if(prime[i] == 0){ // 是素数 
                award[tmp] = 2; //小黄人 
            }
            else{
                award[tmp] = 3; //巧克力 
            }
        }
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i){
        scanf("%d", &tmp);
        printf("%04d: ",tmp);
        if(award[tmp] == 0){
            printf("Are you kidding?\n");
        }
        else if(award[tmp] == 1){
            printf("Mystery Award\n");
            award[tmp] = -1; //已经查询过 
        }
        else if(award[tmp] == 2){
            printf("Minion\n");
            award[tmp] = -1; //已经查询过
        }
        else if(award[tmp] == 3){
            printf("Chocolate\n");
            award[tmp] = -1; //已经查询过
        }
        else if(award[tmp] == -1){
            printf("Checked\n");
        }
    }
    return 0;
}
