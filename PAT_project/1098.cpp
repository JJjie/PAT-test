//
// Created by 胡文杰 on 2017/2/7.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
using namespace std;

int cmp_98(int a, int b) {
    return a < b;
}

int pat_1098() {
    int n;
    cin >> n;
    int *a = new int [n];
    int *b = new int [n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int i, j;
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
    for (j = i + 1; a[j] == b[j] && j < n; j++);
    if (j == n) {
        cout << "Insertion Sort" << endl;
        sort(a, a + i + 2, cmp_98);
        for (j = 0; j < n - 1; j++) {
            cout << a[j] << " ";
        }
        cout << a[n - 1];
    } else {
        cout << "Heap Sort" << endl;
        int p = n-1;
        while(p >= 1 && b[p] >= b[p - 1]) p--;
        swap(b[0], b[p]);
        int index = 0, jd = 1;
        while(jd <= p-1) {
            if(jd + 1 <= p-1 && b[jd] < b[jd + 1])
                jd = jd + 1;
            if(b[index] < b[jd]) {
                swap(b[index], b[jd]);
                index = jd; jd = index * 2;
            } else {
                break;
            }
        }
        for (j = 0; j < n - 1; j++) {
            cout << b[j] << " ";
        }
        cout << b[n - 1];
    }
    return 0;
}