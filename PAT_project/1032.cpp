//
// Created by 胡文杰 on 2017/1/17.
//

#include "pat.h"
#include <iostream>
using namespace std;

struct word_32{
    char c;
    int next;
    int count = 0;
};
word_32 words_32[100000];
int pat_1032(){
    int w1, w2, n;
    cin >> w1 >> w2 >> n;
    for (int i = 0; i < n; i++) {
        int tag, next;
        char c;
        cin >> tag >> c >> next;
        words_32[tag].c = c;
        words_32[tag].next = next;
    }
    if (w1 == -1 || w2 == -1){
        cout << "-1" << endl;
        return 0;
    }
    int index = -1;
    int current = w1;
    while (current != -1){
        words_32[current].count = 1;
        current = words_32[current].next;
    }
    current = w2;
    while (current != -1){
        if (words_32[current].count == 1) {
            index = current;
            break;
        }
        current = words_32[current].next;
    }
    if (index < 0){
        cout << "-1" << endl;
    }else{
        printf("%05d\n",index);
    }

    return 0;
}