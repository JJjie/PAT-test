//
// Created by 胡文杰 on 2017/2/1.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
#include <string>
#define MAX_72 9999999
using namespace std;
int road_72[1020][1020],dis_72[1020];
bool visited_72[1020];

int pat_1072(){
    int n,m,k,ds;
    scanf("%d%d%d%d",&n,&m,&k,&ds);
    fill(road_72[0], road_72[0]+1020*1020, MAX_72);
    for (int i = 0; i < k; ++i) {
        string p1,p2;
        int dist;
        int a,b;
        cin >> p1 >> p2 >> dist;
        if (p1[0] != 'G'){
            a = (int)(p1[0] - '0');
        } else {
            a = n + (int)(p1[1] - '0');
        }
        if (p2[0] != 'G'){
            b = (int)(p2[0] - '0');
        } else {
            b = n + (int)(p2[1] - '0');
        }
        road_72[a][b] = dist;
        road_72[b][a] = dist;
    }
    int ansid = -1;
    float ansdis = -1, ansaver = MAX_72;
    for (int index = n+1; index <= n+m ; ++index) {
        float mindis = MAX_72, aver = 0;
        fill(dis_72, dis_72+1020, MAX_72);
        fill(visited_72, visited_72+1020, false);
        dis_72[index] = 0;
        for (int i = 0; i < n+m; ++i) {
            int u = -1,minn = MAX_72;
            for (int j = 1; j <= n+m ; ++j) {
                if (!visited_72[j] && dis_72[j] < minn){
                    u = j;
                    minn = dis_72[j];
                }
            }
            if (u == -1) break;
            visited_72[u] = true;
            for (int v = 1; v <= m+n ; ++v) {
                if (!visited_72[v] && dis_72[v] > dis_72[u]+road_72[u][v]){
                    dis_72[v] = dis_72[u]+road_72[u][v];
                }
            }
        }
        for (int i = 1; i <= n ; ++i) {
            if (dis_72[i] > ds){
                mindis = -1;
                break;
            }
            if (dis_72[i] < mindis) mindis = dis_72[i];
            aver += 1.0 * dis_72[i];
        }
        if (mindis == -1) continue;
        aver = aver / n;
        if (mindis > ansdis){
            ansid = index;
            ansdis = mindis;
            ansaver = aver;
        } else if (mindis == ansdis && aver < ansaver){
            ansid = index;
            ansaver = aver;
        }
    }
    if (ansid == -1){
        cout << "No Solution" << endl;
    } else {
        printf("G%d\n",ansid - n);
        printf("%.1f %.1f\n",ansdis,ansaver);
    }
    return 0;
}