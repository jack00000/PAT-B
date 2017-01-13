/*C/C++实现卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。
当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。
现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。
输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。
输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。
输入样例：
6
3 5 6 7 8 11
输出样例：
7 6*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

bool flag[10000]; //测试n=97时已经跑到4616了，故预留10000个空间

int main(){
    int k, n;
    scanf("%d", &k);
    vector<int> v(k);//向量   vector 是一个容器 看不太懂 
    vector<int> result;//让函数返回一个向量
    for(int i=0;i<k;i++){
        scanf("%d", &v[i]);
        n = v[i];
        while(n != 1){
            if(n % 2 == 0){
                n /= 2;
                if(flag[n] == true){
                    break;
                }
                flag[n] = true;
            }
            else{
                n = (3 * n + 1) / 2;
                if(flag[n] == true){
                    break;
                }
                flag[n] = true;
            }
        }
    }
    for(int j=0,l=0;j<k;j++){
        if(flag[v[j]] == false){
            result.push_back(v[j]);
        }
    }
    for(int m=0;m<result.size()-1;m++){
        for(int n=0;n<result.size()-1-m;n++){
            if(result[n] < result[n + 1]){
                int tmp = result[n];
                result[n] = result[n + 1];
                result[n + 1] = tmp;
            }
        }
    }
    for(int o=0;o<result.size();o++){
        printf("%d", result[o]);
        if(o != result.size() - 1){
            printf("%c", ' ');
        }
    }
    printf("%c", '\n');
    return 0;
}
