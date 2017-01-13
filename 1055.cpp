/*拍集体照时队形很重要，这里对给定的N个人K排的队形设计排队规则如下：

每排人数为N/K（向下取整），多出来的人全部站在最后一排；
后排所有人的个子都不比前排任何人矮；
每排中最高者站中间（中间位置为m/2+1，其中m为该排人数，除法向下取整）；
每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧
（例如5人身高为190、188、186、175、170，则队形为175、188、190、186、170。这里假设你面对拍照者，
所以你的左边是中间人的右边）；
若多人身高相同，则按名字的字典序升序排列。这里保证无重名。
现给定一组拍照人，请编写程序输出他们的队形。
输入格式：
每个输入包含1个测试用例。每个测试用例第1行给出两个正整数N（<=10000，总人数）和K（<=10，总排数）
随后N行，每行给出一个人的名字（不包含空格、长度不超过8个英文字母）和身高（[30, 300]区间内的整数）。
输出格式：
输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，
前排输出在下方。
输入样例：
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
输出样例：
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John
分析

1.首先建个结构体数组存数据；
2.然后用sort排序（先按身高排序，若身高相等，按字母排序）；
3.按照先中间，再左边，再右边的顺序往将要输出的字符串里面存人名，要加上空格，每存满一列的人名后就输出结果。

遇到的坑：
1.按字母排序的时候，我只比较了第一位的字母， 只通过了前三个测试点，显然测试数据想的比较全，于是，换成直接利用字符串比大小就行了；
2.题目中说排队的逻辑也是倒着说的：“每排的身高非增序、字母序升序”，由于我也要从最后一排倒着输出，所以排序肯定与题目要求是一致的而不是相反的，这里不要搞错了，所以是身高降序，字母序升序。

源代码
*/
//C/C++实现
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct student{
    string name;
    int height;
};

bool compare(struct student a, struct student b){
    if(a.height != b.height){
        return a.height > b.height;
    }
    else{
        return a.name < b.name;
    }

}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<struct student> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].name >> v[i].height;
    }
    sort(v.begin(), v.end(), compare);
    int col = n / k; //其他排的人数 
    int final = n / k + (n % k); //最后一排人数
    string result = "";
    for(int i = 0; i < n; ){
        if(i == 0){ //先站最后一排 
            result = v[i].name;
            ++i;
            for(int j = 1; j < final; ++j, ++i){
                if(j % 2 == 1){
                    result = v[i].name + " " + result;
                }
                else{
                    result = result + " " + v[i].name;
                }
            }
            cout << result << endl;
        }
        else{
            result = v[i].name;
            ++i;
            for(int j = 1; j < col; ++j, ++i){
                if(j % 2 == 1){
                    result = v[i].name + " " + result;
                }
                else{
                    result = result + " " + v[i].name;
                }
            }
            cout << result << endl;
        }
    } 
}
