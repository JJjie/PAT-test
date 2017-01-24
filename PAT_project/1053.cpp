//
// Created by 胡文杰 on 2017/1/24.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node_53{
    int weight;
    vector<int> children;
};
vector<node_53> tree_53;
vector<int> road_53; // 标记路径结点

bool cmp_53(int a, int b){
    return tree_53[a].weight > tree_53[b].weight;
}
void getroads(int id, int nodenum, int w){
    w = w - tree_53[id].weight;
    if (w < 0) return;
    else if (w == 0){
        if (!tree_53[id].children.empty()) return;
        else {
            for (int i = 0; i < nodenum; i++) {
                printf("%d%c",tree_53[road_53[i]].weight, (i == nodenum-1) ? '\n' : ' ');
            }
        }
    } else {
        int len = tree_53[id].children.size();
        for (int i = 0; i < len; i++) {
            road_53[nodenum] = tree_53[id].children[i];
            getroads(tree_53[id].children[i], nodenum+1, w);
        }
    }
}
int pat_1053(){
    int n, m, s;
//    cin >> n >> m >> s;
    scanf("%d%d%d",&n,&m,&s);
    tree_53.resize(n);
    road_53.resize(n);
    for (int i = 0; i < n; i++) {
//        cin >> tree_53[i].weight;
        scanf("%d",&tree_53[i].weight);
    }
    for (int i = 0; i < m; i++) {
        int id, k;
//        cin >> id >> k;
        scanf("%d%d",&id,&k);
        tree_53[id].children.resize(k);
        for (int j = 0; j < k; j++) {
//            cin >> tree_53[id].children[j];
            scanf("%d",&tree_53[id].children[j]);
        }
        sort(tree_53[id].children.begin(), tree_53[id].children.end(), cmp_53);
    }
    road_53[0] = 0;
    getroads(0,1,s);
    return 0;
}