//
// Created by 胡文杰 on 2017/1/16.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;
#define INToMAX 0x7fffffff

vector<vector<int>> road_30;
vector<vector<int>> prices_30;
vector<bool> visited_30;
vector<int> previsited_30;
vector<int> shortest_30;
vector<int> cost_30;

void printpath(int s,int S){
    if (s == S){
        cout << s << " ";
    }else{
        printpath(previsited_30[s],S);
        cout << s << " ";
    }
}

int pat_1030(){
    int N,M,S,D;
    cin >> N >> M >> S >> D;
    road_30.resize(N);
    prices_30.resize(N);
    visited_30.resize(N, false);
    previsited_30.resize(N, S);
    shortest_30.resize(N, INToMAX);
    cost_30.resize(N,INToMAX);
    for (int i = 0; i < N; i++) {
        road_30[i].resize(N,INToMAX);
        prices_30[i].resize(N,INToMAX);
    }

    for (int i = 0; i < M; i++) {
        int a,b,len,cost;
        cin >> a >> b >> len >> cost;
        road_30[a][b] = len;
        prices_30[a][b] = cost;
        road_30[b][a] = len;
        prices_30[b][a] = cost;
    }
    for (int i = 0; i < N; i++) {//初始最小消费
        shortest_30[i] = road_30[S][i];
        cost_30[i] = prices_30[S][i];
    }
    visited_30[S] = true;
    shortest_30[S] = 0;
    cost_30[S] = 0;
    previsited_30[S] = S;

    int index=0, min;
    for (int i = 1; i < N; i++) {
        min = INToMAX;
        for (int j = 0; j < N; ++j) {
            if (!visited_30[j] && shortest_30[j] < min){
                min = shortest_30[j];
                index = j;
            }
        }
        if (index == D)
            break;
        visited_30[index] = true;
        for (int j = 0; j < N; j++) {
            if (!visited_30[j] && road_30[index][j] != INToMAX){
                if (min + road_30[index][j] < shortest_30[j]){
                    shortest_30[j] = min + road_30[index][j];
                    cost_30[j] = cost_30[index] + prices_30[index][j];
                    previsited_30[j] = index;
                }else{
                    if (min + road_30[index][j] == shortest_30[j]){
                        if (cost_30[j] > cost_30[index] + prices_30[index][j]){
                            cost_30[j] = cost_30[index] + prices_30[index][j];
                            previsited_30[j] = index;
                        }
                    }
                }
            }
        }
    }
    printpath(D,S);
    cout << shortest_30[D] << " " << cost_30[D] << endl;

    return 0;
}