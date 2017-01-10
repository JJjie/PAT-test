//
// Created by 胡文杰 on 2017/1/10.
//

#include "pat.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct customer{
    int arrivetime;
    int usetime;
};

bool less_time(customer &A, customer &B);
int findClosetWIN(int *W, int N);

int pat_1017(){
    int N,WIN;
    cin >> N >> WIN ;
    customer *ct = new customer[N];
    int h,m,s,cost;
    for (int i = 0; i < N; i++) {
        scanf("%d:%d:%d %d", &h, &m, &s, &cost);
        ct[i].arrivetime = h*3600 + m*60 + s;
        ct[i].usetime = cost*60;
    }

//    根据时间到达先后排序
    sort(ct, ct+N, less_time);
    int *W = new int[WIN];//每个窗口的服务时间
    int wait = 0;
    int count = 0;//记录多少记录有效可以参与求平均值
    for (int i = 0; i < WIN; i++) {
        W[i] = 8*3600;
    }
    for (int i = 0; i < N; i++) {
        if (ct[i].arrivetime < 17*3600+1){
            count ++ ;
            int index = findClosetWIN(W, WIN);
            if (ct[i].arrivetime < W[index]){
                wait += W[index] - ct[i].arrivetime;
                W[index] += ct[i].usetime;
            }else{
                W[index] = ct[i].arrivetime + ct[i].usetime;
            }

        }
    }
    cout << fixed << setprecision(1) << (float)wait/(count*60) << endl;

    delete[] W;
    delete[] ct;

    return 0;
}

bool less_time(customer &A, customer &B){
    if (A.arrivetime < B.arrivetime){
        return true;
    }else{
        return false;
    }
}

int findClosetWIN(int *W, int N){
    int index = 0;
    int temp = W[0];
    for (int i = 1; i < N; i++) {
        if (W[i] < temp){
            temp = W[i];
            index = i;
        }
    }
    return index;
}