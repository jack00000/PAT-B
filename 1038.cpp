/*本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。
输入格式：
输入在第1行给出不超过10^5
的正整数N，即学生总人数。随后1行给出N名学生的百分制整数成绩，中间以空格分隔。
最后1行给出要查询的分数个数K（不超过N的正整数），随后是K个分数，中间以空格分隔。
输出格式：
在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。
输入样例：
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
输出样例：
3 2 0
分析

先新建成绩表，用于统计同成绩的人数，读入每个成绩，根据每个成绩，将对应索引的成绩表的数值自增1，
最后按照所求成绩，输出人数即可。

源代码

//C/C++实现
#include <iostream>

using namespace std;

int grade[101];

int main(){
    int n;
    scanf("%d", &n);
    int tmp;
    for(int i = 0; i < n; ++i){
        scanf("%d", &tmp);
        ++grade[tmp];
    }
    int k;
    scanf("%d", &k);
    scanf("%d", &tmp);
    printf("%d", grade[tmp]);
    for(int i = 1; i < k; ++i){
        scanf("%d", &tmp);
        printf(" %d", grade[tmp]);
    }
    printf("\n");
    return 0;
}
