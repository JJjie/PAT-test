//
// Created by 胡文杰 on 2017/2/9.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
using namespace std;
struct DATA {
    int id, fid, mid, num, area;
    int cid[10];
}data[1005];
struct node {
    int id, people;
    double num, area;
    bool flag = false;
}ans114[10000];
int father114[10000];
bool visit114[10000];
int find(int x) {
    while(x != father114[x])
        x = father114[x];
    return x;
}
void Union114(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA > faB)
        father114[faA] = faB;
    else if(faA < faB)
        father114[faB] = faA;
}
int cmp1(node a, node b) {
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int pat_1114() {
    int n, k, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < 10000; i++)
        father114[i] = i;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
        visit114[data[i].id] = true;
        if(data[i].fid != -1) {
            visit114[data[i].fid] = true;
            Union114(data[i].fid, data[i].id);
        }
        if(data[i].mid != -1) {
            visit114[data[i].mid] = true;
            Union114(data[i].mid, data[i].id);
        }
        for(int j = 0; j < k; j++) {
            scanf("%d", &data[i].cid[j]);
            visit114[data[i].cid[j]] = true;
            Union114(data[i].cid[j], data[i].id);
        }
        scanf("%d %d", &data[i].num, &data[i].area);
    }
    for(int i = 0; i < n; i++) {
        int id = find(data[i].id);
        ans114[id].id = id;
        ans114[id].num += data[i].num;
        ans114[id].area += data[i].area;
        ans114[id].flag = true;
    }
    for(int i = 0; i < 10000; i++) {
        if(visit114[i])
            ans114[find(i)].people++;
        if(ans114[i].flag)
            cnt++;
    }
    for(int i = 0; i < 10000; i++) {
        if(ans114[i].flag) {
            ans114[i].num = (double)(ans114[i].num * 1.0 / ans114[i].people);
            ans114[i].area = (double)(ans114[i].area * 1.0 / ans114[i].people);
        }
    }
    sort(ans114, ans114 + 10000, cmp1);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans114[i].id, ans114[i].people, ans114[i].num, ans114[i].area);
    return 0;
}