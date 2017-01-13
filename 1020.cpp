/*月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、
以及市场的最大需求量，请你计算可以获得的最大收益是多少。
注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，
总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、
以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。
输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、
以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；
最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。
输出格式：
对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。
输入样例：
3 20
18 15 10
75 72 45
输出样例：
94.50
分析

声明double类型的二维数组，模仿一个表存放月饼的库存量、总售价和单价，然后利用qsort可以整行交换，来比大小，
最后按照单价的高的，优先作为收益。

注意：
double和int转换要注意精度问题。

遇到的坑：
1.题目中说第一行两个数是正整数，但是月饼的库存量是正数，总售价也是正数，而不是正整数；
2.qsort对double类型排序一定要注意！qsort对double类型排序一定要注意！
qsort对double类型排序一定要注意！
我考虑之后觉得最优方法不要返回两数相减的结果，而是返回两数比大小的结果，将bool值作为int型返回。

原理是：
在对浮点或者double型比大小的时候一定要用三目运算符，因为如果也使用整型那样的想减的话，
如果是两个很接近的数则可能返回一个小数（大于-1，小于1），而cmp的返回值是int型，因此会将这个小数返回0，
系统认为是相等，失去了本来存在的大小关系。

我觉得使用比大小得到的bool值作为返回还是比较简便的。*/ 

//C/C++实现
#include <iostream>
#include <stdlib.h>

using namespace std;

int compare(const void *a_t, const void *b_t){
    double *a = (double *)a_t, *b = (double *)b_t;
    return b[2] > a[2];
}

int main(){
    int type, max;
    scanf("%d %d", &type, &max);
    double moonCake[type][3]; //行数一会换成type，n行三列，分别是库存量、总售价、单价
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < type; ++j){
            scanf("%lf", &moonCake[j][i]);
        }
    }
    for(int l = 0; l < type; ++l){
        moonCake[l][2] = moonCake[l][1] / moonCake[l][0];
    }
    qsort(&moonCake[0], type, sizeof(moonCake[0]), compare);
    double profit = 0;
    double tmp = max;
    for(int k = 0; k < type && tmp != 0; ++k){
        if(moonCake[k][0] <= tmp){
            profit += moonCake[k][1];
            tmp -= moonCake[k][0];
        }
        else{
            profit += (moonCake[k][2] * tmp);
            tmp = 0;
        }
    }
    printf("%.2f\n", profit);
    return 0;
}
