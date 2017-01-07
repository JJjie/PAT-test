//
// Created by 胡文杰 on 2017/1/7.
//

#include "pat.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct customer {
    int ID;
    int cost;
    int frontcost=0;
};
int N, M, K;
void serveCost(vector<int> *w, customer *c);
void turnToTime(customer &c);

int pat_1014(){
    int Q;
    cin >> N >> M >> K >> Q;
    vector<int> *windows = new  vector<int>[N];

    customer *customers = new customer[K];
    for (int i = 0; i < K; i++) {
        cin >> customers[i].cost;
        customers[i].ID = i+1;
    }

    serveCost(windows, customers);
    for (int i = 0; i < Q; ++i) {
        int id;
        cin >> id;
        turnToTime(customers[id-1]);
    }

//    释放内存
    delete[] windows;
    delete[] customers;

    return 0;
}

void serveCost(vector<int> *w, customer *c){
    for (int i = 0; i < N; i++) { //初始化
        for (int j = i; (j/2) < M; j=j+2) {
            w[j].push_back(c[j].cost);
        }
    }
    for (int i = N*M; i < K ; i++) {
        int index = 0, temp = 0;
        for (int j = 0; j < N ; j++) {
            for (int k = 0; k < M; k++) {
                if (w[j][k] < temp && temp!=0){
                    temp = w[j][k];
                }
            }
        }
    }

}

void turnToTime(customer &c){
    int cost = c.frontcost;
    int hour = 8, minute = 0;
    minute += cost;
    while (minute > 59){
        minute = minute - 60;
        hour ++;
    }
    if (hour >= 17 && minute > 0){
        cout << "Sorry" << endl;
    }else{
        cout << setfill('0') << setw(2) << hour << ':' << setfill('0') << setw(2) << minute << endl;
    }
}