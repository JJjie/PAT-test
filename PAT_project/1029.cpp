//
// Created by 胡文杰 on 2017/1/16.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pat_1029(){
    int N1,N2,i,j;
    cin >> N1;
    long int *first = new long int[N1];
    for ( i = 0; i < N1; i++) {
        cin >> first[i];
    }
    cin >> N2;
    long int *second = new long int[N2];
    for ( i = 0; i < N2; i++) {
        cin >> second[i];
    }
    int cnt = (N1+N2-1)/2;
    i=0;j=0;
    while (cnt ){//舍弃cnt个数即可
        while (i<N1 && j<N2 && first[i]<second[j] && cnt){
            i++;
            cnt--;
        }
        while (i<N1 && j<N2 && first[i]>=second[j] && cnt){
            j++;
            cnt--;
        }
        while (i<N1 && j>=N2 && cnt){
            i++;
            cnt--;
        }
        while (i>=N1 && j<N2 && cnt){
            j++;
            cnt--;
        }
    }
    long int res ;
    if (i<N1 && j<N2){
        res = (first[i] < second[j]) ? first[i] : second[j];
    }else{
        res = (i < N1) ? first[i] : second[j];
    }
    cout << res << endl;

    delete[] first;
    delete[] second;
    return 0;
}