/*复数可以写成(A + Bi)的常规形式，其中A是实部，B是虚部，i是虚数单位，满足i^2= -1；
也可以写成极坐标下的指数形式(R*e^(Pi))，其中R是复数模，P是辐角，i是虚数单位，其等价于三角形式(R(cos(P) + isin(P))。
现给定两个复数的R和P，要求输出两数乘积的常规形式。
输入格式：
输入在一行中依次给出两个复数的R1, P1, R2, P2，数字间以空格分隔。
输出格式：
在一行中按照“A+Bi”的格式输出两数乘积的常规形式，实部和虚部均保留2位小数。注意：如果B是负数，则应该写成“A-|B|i”的形式。
输入样例：
2.3 3.5 5.2 0.4
输出样例：
-8.68-8.23i
分析

做过最恶心的一道15分题，先笔算对公式化简，化简的式子见下面的源代码，需要注意的是省略2位小数，
要与正负0.005比较大小判断是否为0，不能直接判断等于0，因为是浮点数；若比较的数太精确可能也是不行的。

遇到的坑：
开始以为如果a或者b部分如果是0就不输出了，结果发现还是需要输出0.00，
这里面需要注意的是当b=0的时候要输出"+0.00i"，开始这里忘记加正号了。

源代码

//C/C++实现
#define PI 3.14159

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double r1, p1, r2, p2;
    scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
    double a = r1 * r2 * cos(p1 + p2);
    double b = r1 * r2 * sin(p1 + p2);
    if(a > -0.005 && a < 0.005){ //a = 0
        printf("0.00");
    }
    else{
        printf("%.2f", a);
    }
    if(b > -0.005 && b < 0.005){ //b = 0
        printf("+0.00i\n"); //这里别忘记+0.00i好坑
    }
    else if(b > 0){
        printf("+%.2fi\n", b);
    }
    else if(b < 0){
        printf("%.2fi\n", b);
    }
    return 0;
}
