//
// Created by 胡文杰 on 2017/2/3.
//

#include "pat.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define MAX87 0x7fffffff
using namespace std;
int road87[205][205],weight87[205],dis87[205];
bool visited87[205];
vector<int> pre87[205], temppath87, path87;
map<string, int> m87;
map<int ,string> m87_;
int maxvalue87 = 0, mindepth87, cntpath87 = 0;
double maxavg87;
void DFS_87(int index){
    temppath87.push_back(index);
    if (index == 1){
        int value = 0;
        for (int i = 0; i < temppath87.size(); ++i) {
            value += weight87[temppath87[i]];
        }
        double tempavg = 1.0 * value / (temppath87.size() - 1);
        if (value > maxvalue87){
            maxavg87 = tempavg;
            maxvalue87 = value;
            path87 = temppath87;
        } else if (value == maxvalue87 && tempavg > maxavg87){
            maxavg87 = tempavg;
            path87 = temppath87;
        }
        temppath87.pop_back();
        cntpath87++;
        return;
    }
    for (int i = 0; i < pre87[index].size(); ++i) {
        DFS_87(pre87[index][i]);
    }
    temppath87.pop_back();
}

int pat_1087(){
    fill(road87[0],road87[0]+205*205,MAX87);
    fill(dis87,dis87+205,MAX87);
    int n,k;
    scanf("%d %d",&n,&k);
    string s;
    cin >> s;
    m87[s] = 1;
    m87_[1] = s;
    for (int i = 1; i < n; ++i) {
        cin >> s >> weight87[i+1];
        m87[s] = i+1;
        m87_[i+1] = s;
    }
    string sa,sb;
    int temp;
    for (int i = 0; i < k; ++i) {
        cin >> sa >> sb >> temp;
        road87[m87[sa]][m87[sb]] = temp;
        road87[m87[sb]][m87[sa]] = temp;
    }
//    dijkstra
    dis87[1] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1,minn = MAX87;
        for (int j = 1; j <= n; ++j) {
            if (!visited87[j] && dis87[j] < minn){
                u = j;
                minn = dis87[j];
            }
        }
        if (u == -1) break;
        visited87[u] = true;
        for (int v = 1; v <= n ; ++v) {
            if (!visited87[v] && road87[u][v] < MAX87){
                if (dis87[u] + road87[u][v] < dis87[v]){
                    dis87[v] = dis87[u] + road87[u][v];
                    pre87[v].clear();
                    pre87[v].push_back(u);
                } else if (dis87[u] + road87[u][v] == dis87[v]){
                    pre87[v].push_back(u);
                }
            }
        }
    }
    int rom = m87["ROM"];
    DFS_87(rom);
    printf("%d %d %d %d\n",cntpath87,dis87[rom],maxvalue87,(int)maxavg87);
    for (int i = path87.size() - 1; i >= 1 ; i--) {
        cout << m87_[path87[i]] << "->";
    }
    cout << "ROM" << endl;
    return 0;
}