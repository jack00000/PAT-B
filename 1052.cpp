/*萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：
[左手]([左眼][口][右眼])[右手]
现给出可选用的符号集合，请你按用户的要求输出表情。
输入格式：
输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号[]内。
题目保证每个集合都至少有一个符号，并不超过10个符号；每个符号包含1到4个非空字符。
之后一行给出一个正整数K，为用户请求的个数。随后K行，每行给出一个用户的符号选择，
顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从1开始），数字间以空格分隔。
输出格式：
对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出“Are you kidding me? @\/@”。
输入样例：
[╮][╭][o][~\][/~] [<][>]
[╯][╰][ ^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^] ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
输出样例：
╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@
分析

先根据三行的表情，存入对应的数组中，我用的是string数组，这里存数据是一个难点，
我是根据string.find方法找到中括号，然后用string.substr划分数组后，存入里面的。之后按要求输出即可。

遇到的坑：
1.getline(cin,string)之后需要清空cin，方法如下

cin.sync();
cin.clear();
2.题目说“这里只给出符号在相应集合中的序号（从1开始）”
3.别忘记给眼睛的左右两边加英文括号

所有的坑全踩了一遍，要不要这样？！

源代码
*/
//C/C++实现
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string hands, eyes, mouths;
    vector<string> hands_v(1), eyes_v(1), mouths_v(1); //先放一个占位置
    //input hands
    int i = 0;
    getline(cin, hands);
    int end = hands.find(']', i);
    while(end != -1){
        int start = hands.find('[', i);
        hands_v.push_back(hands.substr(start + 1, end - start - 1));
        i = end + 1;
        end = hands.find(']', i);
    }
    cin.sync();
    cin.clear();
    //input eyes
    i = 0;
    getline(cin, eyes);
    end = eyes.find(']', i);
    while(end != -1){
        int start = eyes.find('[', i);
        eyes_v.push_back(eyes.substr(start + 1, end - start - 1));
        i = end + 1;
        end = eyes.find(']', i);
    }
    cin.sync();
    cin.clear();
    //input mouths
    i = 0;
    getline(cin, mouths);
    end = mouths.find(']', i);
    while(end != -1){
        int start = mouths.find('[', i);
        mouths_v.push_back(mouths.substr(start + 1, end - start - 1));
        i = end + 1;
        end = mouths.find(']', i);
    }
    cin.sync();
    cin.clear();
    int n;
    scanf("%d", &n);
    int tmp;
    for(int j = 0; j < n; ++j){
        string result = "";
        //左手
        scanf("%d", &tmp);
        if(tmp > 0 && tmp < hands_v.size()){
            result += hands_v[tmp];
        }
        else{
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        //左眼
        scanf("%d", &tmp);
        if(tmp > 0 && tmp < eyes_v.size()){
            result += ("(" + eyes_v[tmp]);
        }
        else{
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        //口
        scanf("%d", &tmp);
        if(tmp > 0 && tmp < mouths_v.size()){
            result += mouths_v[tmp];
        }
        else{
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        //右眼
        scanf("%d", &tmp);
        if(tmp > 0 && tmp < eyes_v.size()){
            result += (eyes_v[tmp] + ")");
        }
        else{
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        //右手
        scanf("%d", &tmp);
        if(tmp > 0 && tmp < hands_v.size()){
            result += hands_v[tmp];
        }
        else{
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        cout << result << endl;
    }
    return 0;
}
