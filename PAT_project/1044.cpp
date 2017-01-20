//
// Created by 胡文杰 on 2017/1/20.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;

int pat_1044(){
    int n,m;
    cin >> n >> m;
    vector<int> diamond;
    diamond.resize(n);
    vector<pair<int, int>> result;//将两个int数据组合为一个单元存储，不用map
    int pre = 0, pos = 0;
    int min = 0x7fffffff, temp = 0;
    for (int i = 0; i < n; i++) {
        cin >> diamond[i];
        temp += diamond[i];
        if (temp >= m){
            if (temp < min){
                min = temp;
                result.clear();
                result.push_back(pair<int,int>(pre,pos));
            } else {
                if (temp == min) result.push_back(pair<int,int>(pre,pos));
            }
            if (temp > m){
                while (temp >= m){
                    temp -= diamond[pre];
                    pre++;
                    if (temp < m) break;
                    if (temp < min){
                        min = temp;
                        result.clear();
                        result.push_back(pair<int,int>(pre,pos));
                    } else {
                        if (temp == min) result.push_back(pair<int,int>(pre,pos));
                    }
                }
            }
        }
        pos ++;
    }
    for (int i = 0; i < result.size() ; i++) {
        printf("%d-%d\n",result[i].first+1,result[i].second+1);
    }
    return 0;
}