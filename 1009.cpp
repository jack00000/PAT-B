/*C/C++ʵ����ƺ�����һԪ����ʽ�ĵ�������ע��xn��nΪ��������һ�׵���Ϊn*xn-1����
�����ʽ����ָ���ݽ���ʽ�������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���
�����ʽ������������ͬ�ĸ�ʽ�����������ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո�ע�⡰�����ʽ����ָ����ϵ������0�����Ǳ�ʾΪ��0 0����
����������
3 4 -5 2 6 1 -2 0
���������
12 3 -10 1 6 0*/ 
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int a, b;
    if(scanf("%d%d", &a, &b)==2){//a,b �ɹ����룬scanf����ֵΪ2 
        if(b == 0){
            printf("0 0");
            return 0;
        }
        else{
            printf("%d %d", a * b, b - 1);
        }
    }
    
    return 0;
}