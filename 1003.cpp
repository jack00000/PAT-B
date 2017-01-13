//C/C++实现
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>

using namespace std;

int main(){
	 
    int n;//字符个数 
    char c[101];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        bool result = true; 
        int count1 = 0, count2 = 0, count3 = 0;
        int countP = 0, countT = 0;//计数 
        scanf("%s", c);//输入字符 
        
        for(int j=0;j<strlen(c);j++){
            if(c[j] != 'P' && c[j] != 'A' && c[j] != 'T'){//除PAT  以外字符  error 
                result = false;
                break;
            }
            if(c[j] == 'P'){//两个P及以上字符 error 
                countP ++;
                if(countP == 2){
                    result = false;
                    break;
                }
            }
            if(c[j] == 'T'){//两个P及以上字符 error 
                countT ++;
                if(countT == 2){
                    result = false;
                    break;
                }
            }
        }
        if(result){//error则不执行 
            string s = c;//先要将数组转换为字符串 
            count1 = s.find("P");//找到‘P’的位置 
            count2 = s.find("A");
            count3 = s.find("T");
            if(count1 == -1 || count2 == -1 || count3 == -1){
                result = false;
            }
            else{
                result = ((count1 * (count3 - count1 - 1)) == (strlen(c) - count3 - 1)) ? true : false;
            }
        }
        if(result){ 
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
