/*如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 ——
 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”
 现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。
输入格式：
输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。
里Galleon是[0, 10^7]区间内的整数，Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。
输出格式：
在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。
输入样例1：
10.16.27 14.1.28
输出样例1：
3.2.1
输入样例2：
14.1.28 10.16.27
输出样例2：
-3.2.1
分析

首先先都换算成单位为Knut的，然后再计算即可，注意下为负的情况要用P减去A，然后如果P与A相等，则输出0.0.0。
0 
源代码
*/ 
//C/C++实现
#include <iostream>

using namespace std;

int main(){
    long long priceG, priceS, priceK, payG, payS, payK;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &priceG, &priceS, &priceK, &payG, &payS, &payK);
    long long priceSum = priceG * 17 * 29 + priceS * 29 + priceK;
    long long paySum = payG * 17 * 29 + payS * 29 + payK;
    if(priceSum > paySum){
        printf("-");
        long long changeSum = priceSum - paySum;
        long long changeG = changeSum / (17 * 29);
        changeSum -= changeG * 17 * 29;
        long long changeS = changeSum / 29;
        changeSum -= changeS * 29;
        long long changeK = changeSum;
        printf("%lld.%lld.%lld\n", changeG, changeS, changeK);
    }
    else if(priceSum == paySum){
        printf("0.0.0\n");
    }
    else{
        long long changeSum = paySum - priceSum;
        long long changeG = changeSum / (17 * 29);
        changeSum -= changeG * 17 * 29;
        long long changeS = changeSum / 29;
        changeSum -= changeS * 29;
        long long changeK = changeSum;
        printf("%lld.%lld.%lld\n", changeG, changeS, changeK);
    }
    return 0;
}
