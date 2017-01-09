//
// Created by 胡文杰 on 2017/1/7.
//

#include "pat.h"
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

struct customer {
    int ID;
    int cost;
    int frontcost=0;
};
int WIN, M, K;
void serveCost(customer *c);
void turnToTime(customer &c);
int getHour(int d);
int getMinute(int d);

int pat_1014(){
    int Q;
    cin >> WIN >> M >> K >> Q;
    customer *customers = new customer[K];
    for (int i = 0; i < K; i++) {
        cin >> customers[i].cost;
        customers[i].ID = i+1;
    }

    serveCost(customers);
    for (int i = 0; i < Q; ++i) {
        int id;
        cin >> id;
        turnToTime(customers[id-1]);
    }
//    释放内存
    delete[] customers;

    return 0;
}

void serveCost(customer *c){
    int *p = new int[WIN];//正在处理
    int *cost = new int[WIN];//窗口预计消费
    queue<int> *q = new queue<int>[WIN];//N条队伍
    for (int i = 0; i < K; i++) {
        if (i < WIN){
            p[i] = c[i].cost;
            cost[i] = c[i].cost;
        } else{
            if (i < WIN*M){
                int index = i - WIN;
                while (index/WIN != 0){
                    index -= WIN;
                }
                q[index].push(c[i].cost);
                c[i].frontcost = cost[index];
                cost[index] += c[i].cost;
            } else{
                if (i < K){
                    int temp = p[0], t = 0;
                    for (int j = 1; j < WIN; j++) {
                        if (p[j] < temp) {
                            temp = p[j];
                            t = j;
                        }
                    }
                    p[t] += q[t].front();
                    c[i].frontcost = cost[t];
                    cost[t] += c[i].cost;
                    q[t].pop();
                    q[t].push(c[i].cost);
                }
            }
        }
    }
    delete[] p;
    delete[] cost;
    delete[] q;
}

void turnToTime(customer &c){
    int minute = c.frontcost;
    int startHour = getHour(minute);
    if (startHour > 16){
        cout << "Sorry" << endl;
    }else{
        minute += c.cost;
        int ehour = getHour(minute);
        int eminute = getMinute(minute);
        cout << setfill('0') << setw(2) << ehour << ':' << setfill('0') << setw(2) << eminute << endl;
    }
}

int getHour(int d){
    int hour = 8;
    while (d > 59){
        hour ++;
        d = d - 60;
    }
    return hour;
}
int getMinute(int d){
    int minute = d;
    while (minute > 59){
        minute = minute - 60;
    }
    return minute;
}