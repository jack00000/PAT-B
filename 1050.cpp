/*本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，
是指从左上角第1个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为m行n列，
满足条件：m*n等于N；m>=n；且m-n取所有可能值中的最小值。
输入格式：
输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过10^4，相邻数字以空格分隔。
输出格式：
输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。
输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
98 95 93
42 37 81
53 20 76
58 60 76
分析

我们先进行题目分析，先分解成一个个小问题，然后逐个击破：
1.先按倒序排列数组：
用algorithm里面的sort或者stdlib.h中的qsort都可以，但是qsort不能排vector，因为地址不连续，
这个要注意一下。要自己写campare方法就行，默认是升序的。
2.根据输入的数组个数，求出矩阵的行数和列数：
这个方法有很多了，我用的就是对N开根的值开始，逐渐减到1，求m和n，别的方法也行。
3.螺旋放置：
这个是难点，我开始声明了变量status来确定是怎样放置的，一共有四种：左->右，上->下，右->左，下->上，然后针对不同的status对坐标有相应的自增或自减方法，并且如果这一行如果被放置过了，要给放置的次数做减1的操作。

注意：我想到的螺旋放置方法不适用于只有一列的情况，要单独判断这种情况，单独写输出方法。

源代码
*/ 
//C/C++实现
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(int a, int b){
    return a > b; //desc
}

int main(){
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &v[i]);
    }
    //sort
    sort(v.begin(), v.end(), compare);
    //calculate m and n
    int i = sqrt((double)N);
    int m, n;
    for(; i >= 1; --i){
        if(N % i == 0){ //整除
            n = i;
            m = N / n;
            break;
        }
    }
    int a[m][n]; //一会改成a[m][n]
    int x = 0, y = -1;
    int status = 0; //从左向右是0，上向下是1，右向左是2，下向上是3
    int c0 = 0, c1 = 0, c2 = 0, c3 = 0; //走过该路径就自增1
    if(n == 1){
        for(int i = 0; i < v.size(); ++i){
            printf("%d\n", v[i]);
        }
    }
    else{
        for(int i = 0; i < v.size(); ++i){
            if(status == 0){
                ++y;
                if(y == n - 1 - c1){
                    status = 1; //该从上往下填充了
                    ++c0;
                }
            }
            else if(status == 1){
                ++x;
                if(x == m - 1 - c2){
                    status = 2; //该从右往左填充了
                    ++c1;
                }
            }
            else if(status == 2){
                --y;
                if(y == 0 + c3){
                    status = 3; //该从下往上填充了
                    ++c2;
                }
            }
            else if(status == 3){
                --x;
                if(x == 0 + c0){ //该从左往右填充了
                    status = 0;
                    ++c3;
                }
            }
            a[x][y] = v[i];
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(j == 0){
                    printf("%d", a[i][j]);
                }
                else{
                    printf(" %d", a[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
