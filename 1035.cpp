/*根据维基百科的定义：
插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，
将之插入有序序列中正确的位置。如此迭代直到全部元素有序。
归并排序进行如下迭代操作：首先将原始序列看成N个只包含1个元素的有序子序列，
然后每次迭代归并两个相邻的有序子序列，直到最后只剩下1个有序的序列。
现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？
输入格式：
输入在第一行给出正整数N (<=100)；随后一行给出原始序列的N个整数；最后一行给出由某排序算法产生的中间序列。
这里假设排序的目标序列是升序。数字间以空格分隔。
输出格式：
首先在第1行中输出“Insertion Sort”表示插入排序、或“Merge Sort”表示归并排序；
然后在第2行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行末不得有多余空格。
输入样例1：
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
输出样例1：
Insertion Sort
1 2 3 5 7 8 9 4 6 0
输入样例2：
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
输出样例2：
Merge Sort
1 2 3 8 4 5 7 9 0 6
分析

这道题的题目先入为主的让我们来写插入排序和归并排序算法，但是仔细想想并没有那么复杂。
1.首先是判断排序方法，根据插入排序的特征，前面部分为已排序的，后面的与原始序列是一样的。通过这个特征来判断是否是插入排序，然后不是插入排序的即为归并排序；
2.将插入排序的序列多向后排序一位即可，用sort函数非常简单；
3.难点在于输出归并排序的下一步，首先要模拟归并排序，当然不用完全按照归并排序来做，也可以调用sort方法会简单很多，首先按照两位两位一排序，排序后，与给定数列对比，若不同，则再次排序一轮，接着再和给定的数列对比，若不同，则再排序……直到相同后，再排序一轮，然后输出即可。

这道题学到了一个技巧是：
可以用equal()方法比较容器中的两个区间内的元素。有3个参数first1，last1和first2。如果对于区间[first1, last1)内所有的first1+i，first1+i和first2所在位置处的元素都相等，则equal算法返回真，否则返回假。

源代码
*/ 
//C/C++实现
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> origin(n), target(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &origin[i]);
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &target[i]);
    }
    //插入排序的特征是，前面为有序的，后面与原始序列一样。
    //如果不是插入排序，则是归并排序
    int index = -1;
    for(int i = 1; i < n; ++i){
        if(target[i] < target[i - 1]){
            index = i;
            break;
        }
    }
    int flag = 0; //0为插入排序，1为归并排序
    for(int i = index; i < n; ++i){
        if(target[i] != origin[i]){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Insertion Sort\n");
        //输出下一步
        sort(target.begin(), target.begin() + index + 1);
        printf("%d", target[0]);
        for(int i = 1; i < n; ++i){
            printf(" %d", target[i]);
        }
    }
    else if(flag == 1){
        printf("Merge Sort\n");
        //输出下一步
        int k = 1;
        bool isNotEqual = true;
        while(isNotEqual){
            isNotEqual = false;
            if(!equal(origin.begin(), origin.end(), target.begin())){ //如果不同的话，就进行一次归并排序
                isNotEqual = true;
            }
            k *= 2;
            for(int i = 0; i < n / k; ++i){
                sort(origin.begin() + i * k, origin.begin() + (i + 1) * k);
            }
            //将剩下的排序
            sort(origin.begin() + k * (n / k), origin.end());
        }
        printf("%d", origin[0]);
        for(int i = 1; i < n; ++i){
            printf(" %d", origin[i]);
        }
    }
    printf("\n");
    return 0;
}
