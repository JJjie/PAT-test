//
// Created by 胡文杰 on 2017/1/24.
//
#include "pat.h"
#include <iostream>
#include <stack>
//#define lowbit(i) ((i) & (-i))
using namespace std;
int c[100001];
stack<int> v; //作为全局变量，减少调参的延迟

int lowbit(int x){ //树状数组，返回'C[n]=A[x-2^k+1]+...+A[x]'中2^k的值
    return (x)&(-x);//按位与
}
void update(int x, int v){
    for (int i = x; i < 100001 ; i += lowbit(i)) {
        c[i] += v;
    }
}
int getsum(int x){
    int sum = 0;
    for (int i = x; i >= 1 ; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

void peekMedian(){
    int left = 1, right = 100001, mid, k = (v.size() + 1) / 2;
    while(left < right) {
        mid = (left + right) / 2;
        if(getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);

}

int pat_1057(){
    int n,temp;
    char str[11];
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%s",str);
        if (str[1] == 'u'){
            scanf("%d",&temp);
            v.push(temp);
            update(temp,1);
        } else if (str[1] == 'o'){
            if (!v.empty()){
                update(v.top(),-1);
                printf("%d\n",v.top());
                v.pop();
            } else{
                printf("Invalid\n");
            }
        } else {
            if (!v.empty()){
                peekMedian();
            } else{
                printf("Invalid\n");
            }
        }
    }
    return 0;
}
