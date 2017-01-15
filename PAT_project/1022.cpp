//
// Created by 胡文杰 on 2017/1/15.
//

#include "pat.h"
#include <iostream>
#include <map>
#include <set>
using namespace std;

map<string, set<int>> titles,authors,keys,pubs,years;
void search(map<string, set<int>> &tag, string &str);

int pat_1022(){
    int n, m, id, num;
    string title, author, key, publish, year;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id ;
        cin.ignore();
        getline(cin, title);//输入项有空格，将空格读入
        titles[title].insert(id);
        getline(cin, author);
        authors[author].insert(id);
        while (cin >> key){
            keys[key].insert(id);
            char c = getchar();
            if (c == '\n') break;
        }
        getline(cin, publish);
        pubs[publish].insert(id);
        getline(cin, year);
        years[year].insert(id);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d: ", &num);
        string temp;
        getline(cin, temp);
        cout << num << ": " << temp << endl;
        if (num == 1) search(titles, temp);
        else if (num == 2) search(authors, temp);
        else if (num == 3) search(keys, temp);
        else if (num == 4) search(pubs, temp);
        else if (num == 5) search(years, temp);
    }
    return 0;
}

void search(map<string, set<int>> &tag, string &str){
    if (tag.find(str) != tag.end()){
        for (set<int>::iterator it = tag[str].begin(); it != tag[str].end() ; it++) {
            printf("%07d\n", *it);//注意控制在7位范围，不然答案有错
        }
    }else{
        cout << "Not Found\n";
    }
}