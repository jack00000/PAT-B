/*����Ҫ����д������Ѹ����ķ��Ŵ�ӡ��ɳ©����״���������17����*����Ҫ�����и�ʽ��ӡ
*****
***
*
***
*****
�������ľ��д�ӡ�������޷���ʾ����Ч����
��ν��ɳ©��״������ָÿ��������������ţ����з������Ķ��룻�������з�������2���������ȴӴ�С˳��ݼ���1��
�ٴ�С����˳���������β��������ȡ�
��������N�����ţ���һ�����������һ��ɳ©��Ҫ���ӡ����ɳ©���õ������ܶ�ķ��š�
�����ʽ��
������һ�и���1��������N��<=1000����һ�����ţ��м��Կո�ָ���
�����ʽ��
���ȴ�ӡ���ɸ���������ɵ�����ɳ©��״�������һ�������ʣ��û�õ��ķ�������
����������
19 *
���������
*****
***
*
***
*****
�������ľ��д�ӡ�������޷���ʾ����Ч����
2
����

1.�������������Ϊɳ©��������һ�㣬Ȼ��ÿ���������㣬������(n - 1) / 2��
Ȼ���ٴ�i = 3��ʼ����һֱ����С��2 * iΪֹ����Ϊ������
2.��Ҫ��¼������ַ������õ��˸ղż��������ķ�����������ַ����������һ�ε�i��ֵ��
3.Ȼ�������������ͬ�����ģ���Ҫ���ǲ��ܴճ�ɳ©�����������С��ɳ©������7���ַ���ɵģ�ҪΪС��6���ַ��ĵ���д�����ķ�����

Դ����
*/ 
//C/C++ʵ��
#include <iostream>

using namespace std;

int main(){
    int n;
    char c;
    scanf("%d %c", &n, &c);
    if(n == 1){
        printf("%c\n0\n", c);
        return 0;
    }
    int rest = n, max = 0;
    for(int i = 1; rest >= 2 * i; i += 2){
        if(i == 1){
            rest -= i;
        }
        else{
            rest -= (2 * i);
            max = i;
        }
    }
    if(n < 7){
        printf("%c\n", c);
    }
    int blank = 0;
    for(int j = max; j > 0; j -= 2, ++blank){
        for(int k = 0; k < blank; ++k){
            printf("%c", ' ');
        }
        for(int l = 0; l < j; ++l){
            printf("%c", c);
        }
        printf("%c", '\n');
    }
    blank -= 2;
    for(int m = 3; blank >= 0; --blank, m += 2){
        for(int n = 0; n < blank; ++n){
            printf("%c", ' ');
        }
        for(int o = 0; o < m; ++o){
            printf("%c", c);
        }
        printf("%c", '\n');
    }
    printf("%d\n", rest);
    return 0;
}
