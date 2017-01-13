/*一个数组A中存有 n>0 个整数，在不允许使用另外数组的前提下，将每个整数循环向右移 m≥0 个位置，
即将A中的数据由(A0A1……An?1)变换为(An?m……An?1A0A1……An?m?1)（最后 m 个数循环移至最前面的 m 个位置）。
如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
输入格式：每个输入包含一个测试用例，第1行输入n(1≤n≤100)、m(m≥0)；第2行输入n个整数，之间用空格分隔。

输出格式：在一行中输出循环右移 m 位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例：

6 2
1 2 3 4 5 6
输出样例：

5 6 1 2 3 4*/
#include <stdio.h>

int main()
{
    int n, m, ch[100] = {0};

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &ch[(i+m)%n]); // 读取时直接存储到移动后的位置上

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", ch[i]);
    }
    return 0;
}
