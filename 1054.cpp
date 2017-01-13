/*本题的基本要求非常简单：给定N个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。
一个“合法”的输入是[-1000，1000]区间内的实数，并且最多精确到小数点后2位。当你计算平均值的时候，
不能把那些非法的数据算在内。
输入格式：
输入第一行给出正整数N（<=100）。随后一行给出N个正整数，数字间以一个空格分隔。
输出格式：
对每个非法输入，在一行中输出“ERROR: X is not a legal number”，其中X是输入。
最后在一行中输出结果：“The average of K numbers is Y”，其中K是合法输入的个数，Y是它们的平均值，
精确到小数点后2位。如果平均值无法计算，则用“Undefined”替换Y。如果K为1，则输出“The average of 1 number is Y”。
输入样例1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
输出样例1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
输入样例2：
2
aaa -9999
输出样例2：
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
分析

最初的分析是：
1.先判长度，太长直接out；
2.如果长度符合，开始遍历，计算小数点的数目，如果超过1，即非法；而一旦发现有非数字非小数点的情况，也认定为非法；
3.到这步后肯定是只有数字和小数点还有负号的组合了，再排除小数点后面超过两位的情况（用长度-小数点的索引看是否大于3），
还有去掉正数情况下小数点开头的情况，以及负数情况下小数点在第2个位置（索引为1）的情况。接着还有以小数点结尾的情况，
也要考虑进去。（这一条也是这道题不严谨的地方，如果认定了小数点结尾的情况为非法，则第四个测试点无法通过，去掉即可通过）

后来怕出现000000.1这种情况，于是把对长度的判断去掉了，但是这道题中的4个测试点并没有这种数据。

遇到的坑：
1.stringstream转换时，要进行清空和重置状态标志的操作（保险起见两个都做）；

stringstream.clear(); //重置stringstream的状态标志
stringstream.str(""); //清空数据
2.不知道是不是坑，还是改掉了，就是开始是拿double型变量>=1000比较的，但是怕double和int的相等比较出问题，
所以还是只比较double型变量<1000比较保险一些；
3.原题中有说明，当k=1时输出number而不是numbers。

源代码
*/
//C/C++实现
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    string tmp;
    double tmp_d;
    int tmp_i;
    stringstream ss;
    int correctCount = 0;
    double sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        bool correct = true;
        bool minus = false; 
        if(tmp[0] == '-'){
            minus = true;
        }
        int count = 0; //计算小数点的个数
        int j = (minus == false ? 0 : 1);
        for(; j < tmp.size(); ++j){
            if(tmp[j] == '.'){
                ++count;
                if(count > 1){ //小数点个数超过1 
                    correct = false;
                    break;
                }
            }
            else if(tmp[j] >= '0' && tmp[j] <= '9'){
                continue;
            }
            else{ //非小数点非数字
                correct = false;
                break;
            }
        }
        if(!correct){
            cout << "ERROR: " << tmp << " is not a legal number" << endl;
        }
        else{
            if(count == 0){ //整数 
                ss << tmp;
                ss >> tmp_i;
                ss.clear(); //重置stringstream的状态标志
                ss.str(""); //清空数据
                if(tmp_i < -1000 || tmp_i > 1000){
                    correct = false;
                }
                else{
                    sum += tmp_i;
                    ++correctCount;
                }
            }
            else{ //小数 
                int point = tmp.find('.');
                if(tmp.size() - point > 3){ //小数点后面超过2位 
                    correct = false;
                }
                //else if(point == tmp.size() - 1){ //小数点在最后一位，也不对 
                //    correct = false;
                //}
                else if(minus == true && point == 1){ //形如：-.x
                    correct = false;
                }
                else if(minus == false && point == 0){ //形如：.x
                    correct = false;
                }
                else{
                    ss << tmp;
                    ss >> tmp_d;
                    ss.clear(); //重置stringstream的状态标志
                    ss.str(""); //清空数据
                    if(tmp_d < -1000 || tmp_d > 1000){
                        correct = false;
                    }
                    else{
                        sum += tmp_d;
                        ++correctCount; 
                    }
                }
            }
            if(!correct){
                cout << "ERROR: " << tmp << " is not a legal number" << endl;
            }
        }
    }
    if(correctCount == 0){
        printf("The average of 0 numbers is Undefined\n");
    }
    else if(correctCount == 1){
        printf("The average of 1 number is %.2f\n", sum);
    }
    else{
        printf("The average of %d numbers is %.2f\n", correctCount, sum / correctCount);
    }
    return 0;
}
