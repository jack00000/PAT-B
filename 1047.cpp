/*编程团体赛的规则为：每个参赛队由若干队员组成；所有队员独立比赛；参赛队的成绩为所有队员的成绩和；成绩最高的队获胜。
现给定所有队员的比赛成绩，请你编写程序找出冠军队。
输入格式：
输入第一行给出一个正整数N（<=10000），即所有参赛队员总数。随后N行，
每行给出一位队员的成绩，格式为：“队伍编号-队员编号 成绩”，

其中“队伍编号”为1到1000的正整数，“队员编号”为1到10的正整数，“成绩”为0到100的整数。
输出格式：
在一行中输出冠军队的编号和总成绩，其间以一个空格分隔。注意：题目保证冠军队是唯一的。
输入样例：
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
输出样例：
11 176
分析

先建个表存放各队伍的成绩，下标为队伍编号，题目输入的队员编号其实是没有用的，把每个成绩都加到对应的队伍上，然后输出最大值和最大值的队伍就行。

源代码
*/
//C/C++实现
#include <iostream>

using namespace std;

int queue[1001];

int main(){
    int n;
    scanf("%d", &n);
    int max = 0, max_index = -1;
    for(int i = 0; i < n; ++i){
        int queueNo, memberNo, grade;
        scanf("%d-%d %d", &queueNo, &memberNo, &grade);
        // memberNo没卵用的，就来客串一下
         queue[queueNo] += grade;
         if(queue[queueNo] > max){
             max = queue[queueNo];
             max_index = queueNo;
         }
    }
    printf("%d %d\n", max_index, max);
    return 0;
}
