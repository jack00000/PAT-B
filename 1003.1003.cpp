#include <stdio.h>/*读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
输入格式：每个测试输入包含1个测试用例，格式为
第1行：正整数n
第2行：第1个学生的姓名 学号 成绩
第3行：第2个学生的姓名 学号 成绩*/

#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int n;
    char name[11],sid[11];//学号 
    char max_name[11],max_sid[11];
    int max_grade = 0,min_grade =100,grade;
    char min_name[11],min_sid[11];
    scanf("%d", &n);//学生个数 
    for(int i=0;i<n;i++){
        scanf("%s%s%d", name, sid, &grade);//输入数据 
       // 比较 grade 
        if(grade > max_grade){
            max_grade = grade;
            strcpy(max_name,name);//string copy 
            strcpy(max_sid,sid);
        }
        if(grade < min_grade){
            min_grade = grade;
            strcpy(min_name,name);
            strcpy(min_sid,sid);
        }
    }
    printf("%s %s\n", max_name, max_sid);
    printf("%s %s\n", min_name, min_sid);
    return 0;
}
