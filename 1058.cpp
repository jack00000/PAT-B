/*批改多选题是比较麻烦的事情，本题就请你写个程序帮助老师批改多选题，并且指出哪道题错的人最多。
输入格式：
输入在第一行给出两个正整数N（<=1000）和M（<=100），分别是学生人数和多选题的个数。随后M行，
每行顺次给出一道题的满分值（不超过5的正整数）、选项个数（不少于2且不超过5的正整数）、
正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母a开始顺次排列。
各项间以1个空格分隔。最后N行，每行给出一个学生的答题情况，其每题答案格式为“(选中的选项个数 选项1 ……)”，
按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。
输出格式：
按照输入的顺序给出每个学生的得分，每个分数占一行。注意判题时只有选择全部正确才能得到该题的分数。
最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从1开始编号）。如果有并列，则按编号递增顺序输出。
数字间用空格分隔，行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出“Too simple”。
输入样例：
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
输出样例：
3
6
5
2 2 3 4
分析

代码里面写的很清楚了，这里就不写分析了，其实是自己懒的写了（逃…

源代码
*/ 
//C/C++实现
#include <iostream>
#include <vector>

using namespace std;

struct question{
    int score; //分值 
    int number; //选项个数 
    int number_correct; //正确项个数
    int count; //出错次数
    int weight; //引入权重，a-e分别是1、2、4、8、16
};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> grade(n); //n个人的成绩 
    vector<struct question> v(m); //m道题 
    int max = 0; //错误最多的题数
    bool allCorrect = true; 
    char tmp;
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", &v[i].score, &v[i].number, &v[i].number_correct);
        v[i].count = 0; //init
        v[i].weight = 0;
        for(int j = 0; j < v[i].number_correct; ++j){
            scanf(" %c", &tmp); //%c前面有空格匹配一个或多个空格
            if(tmp == 'a'){
                v[i].weight += 1;    
            }
            else if(tmp == 'b'){
                v[i].weight += 2;
            }
            else if(tmp == 'c'){
                v[i].weight += 4;
            }
            else if(tmp == 'd'){
                v[i].weight += 8;
            }
            else if(tmp == 'e'){
                v[i].weight += 16;
            }
        }
    }
    for(int i = 0; i < n; ++i){ //n个人
        for(int j = 0; j < m; ++j){ //m道题
            int tmp_weight = 0; //学生答每题答案的权重
            scanf(" %c", &tmp); //吸收左括号
            int num; //学生每题的答案数
            scanf("%d", &num);
            for(int k = 0; k < num; ++k){
                scanf(" %c", &tmp);
                if(tmp == 'a'){
                    tmp_weight += 1;    
                }
                else if(tmp == 'b'){
                    tmp_weight += 2;
                }
                else if(tmp == 'c'){
                    tmp_weight += 4;
                }
                else if(tmp == 'd'){
                    tmp_weight += 8;
                }
                else if(tmp == 'e'){
                    tmp_weight += 16;
                }
            }
            if(num == v[j].number_correct){
                if(tmp_weight == v[j].weight){ //与每题答案的权重比较 
                    grade[i] += v[j].score; //若相等，加分 
                }
                else{
                    allCorrect = false;
                    ++v[j].count; //该题错误次数+1 
                    if(v[j].count > max){
                        max = v[j].count;
                    }
                }
            }
            else{
                allCorrect = false;
                ++v[j].count; //该题错误次数+1 
                if(v[j].count > max){
                    max = v[j].count;
                }
            }
            scanf(" %c", &tmp); //吸收右括号
        }
        printf("%d\n", grade[i]);
    }
    if(allCorrect){
        printf("Too simple\n");
    }
    else{
        vector<int> result;
        for(int i = 0; i < m; ++i){
            if(v[i].count == max){
                result.push_back(i + 1); //把题号加入数组中 
            }
        }
        printf("%d ", max);
        for(int i = 0; i < result.size(); ++i){
            if(i == 0){
                printf("%d", result[i]);
            }
            else{
                printf(" %d", result[i]);
            }
        }
    }
    return 0;
}
