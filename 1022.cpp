/*输入两个非负10进制整数A和B(<=2^30-1)，输出A+B的D (1 < D <= 10)进制数。
输入格式：
输入在一行中依次给出3个整数A、B和D。
输出格式：
输出A+B的D进制数。
输入样例：
123 456 8
输出样例：
1103
分析

就是根据短除法的代码实现，平时都是拿数组做的，这次我用栈来练习一下。

遇到的坑：
如果栈顶是0，即开头数字是0，则不输出，数组实现也同理。*/ 

//C/C++实现
#include <iostream>
#include <stack>

using namespace std;

int main(){
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    stack<int> s;
    int tmp = a + b;
    int rest;
    do{
        s.push(tmp %d);
        tmp /= d;
    }while(tmp != 0);
    while(!s.empty()){
        printf("%d", s.top());
        s.pop();
    }
    printf("%c", '\n');
    return 0;
}
