//
// Created by 胡文杰 on 2017/1/7.
//

#include "pat.h"
#include <iostream>
using namespace std;

struct customer {
    int ID;
    int cost;
    int window;
    int frontcost;
};
int M, K;
void serveCost(int *w, customer *c);
string turnToTime(customer &c);
char* format(int num);

int pat_1014(){
    int N, Q;
    int *windows = new int[N];
    for (int i = 0; i < N; i++) {
        windows[i] = 0;
    }
    customer *customers = new customer[K];
    for (int i = 0; i < K; i++) {
        cin >> customers[i].cost;
        customers[i].ID = i+1;
    }

    serveCost(windows, customers);
    for (int i = 0; i < Q; ++i) {
        int id;
        cin >> id;
        string result = turnToTime(customers[id-1]);
        cout << result << endl;
    }

//    释放内存
    delete[] windows;
    delete[] customers;

    return 0;
}

void serveCost(int *w, customer *c){
    for (int i = 0; i < K; i++) {
        int cost = c[i].cost;
        int temp = 0;
        int index = 0;
        for (int j = 0; j < M; j++) {
            int tag = w[j] + cost;
            if (tag < temp || temp == 0){
                temp = tag;
                index = j;
            }
        }
        c[i].window = index;
        c[i].frontcost = temp;
        w[index] += temp;
    }
}

string turnToTime(customer &c){
    int cost = c.cost + c.frontcost;
    int hour = 8, minute = 0;
    string time;
    minute += cost;
    while (minute > 59){
        minute = minute - 60;
        hour ++;
    }
    if (hour >= 17 && minute > 0){
        return "Sorry";
    }else{
        char *h = format(hour);
        char *m = format(minute);
        time[0] = h[0];
        time[1] = h[1];
        time[2] = ':';
        time[3] = m[0];
        time[4] = m[1];

        delete[] h,m;
        return time;
    }
}

char* format(int num){
    char *str = new char[2];
    int ten = num/10;
    str[0] = (char)(ten);
    str[1] = (char)(num-10*ten);
    return str;
}