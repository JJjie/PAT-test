//
// Created by 胡文杰 on 2017/2/9.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct people_109{
    string name;
    int height;
};
bool cmp_109(people_109 a,people_109 b){
    if (a.height == b.height){
        return a.name < b.name;
    } else {
        return a.height > b.height;
    }
}
int pat_1109(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<people_109> people(n);
    for (int i = 0; i < n; ++i) {
        cin >> people[i].name >> people[i].height;
    }
    sort(people.begin(),people.end(),cmp_109);
    int row = n/k;
    int row1 = n - row*(k-1);
    vector<vector<people_109>> group(k);
    for (int i = 0; i < k; ++i) {
        if (i == 0)
            group[i].resize(row1);
        else
            group[i].resize(row);
    }
    int index,start=0;
    for (int i = 0; i < k; i++) {
        int m;
        if (i == 0){
            m = row1;
        } else {
            m = row;
        }
        index = m/2;
        for (int j = 0; 2*j <= m; j++) {
            if (j == 0){
                group[i][index] = people[start+j];
            } else {
                if (index - j < 0) break;
                group[i][index-j] = people[start+2*j-1];
                if (index + j >= m) break;
                group[i][index+j] = people[start+2*j];
            }
        }
        start += m;
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < group[i].size(); ++j) {
            if (j == 0) cout << group[i][j].name;
            else cout << " " << group[i][j].name;
        }
        cout << endl;
    }
    return 0;
}