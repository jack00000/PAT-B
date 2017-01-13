//C/C++й╣ож
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int count = 0;
    while(n != 1){
        if(n % 2 != 0){
            n = (3 * n + 1) / 2;
            count ++;
        }
        else{
            n /= 2;
            count ++;
        }
    }
    printf("%d\n", count);
    return 0;
	cin>>n;

}
