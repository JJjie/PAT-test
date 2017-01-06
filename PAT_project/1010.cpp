//
// Created by 胡文杰 on 2017/1/6.
//

#include "pat.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int map[256];//标记字符对应的10进制数值
const long long T = (1LL << 63) -1;

long long converttoten(string n1, long long radix, long long t);
long long binarySearch(string n2, long long low, long long high, long long n1);
long long findLargestDigit(string n);
int cmp(string n2, long long radix, long long t);

int pat_1010(){
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    for (char c = '0'; c <= '9' ; c++) {
        map[c] = c - '0';
    }
    for (char c = 'a'; c < 'z' ; c++) {
        map[c] = c - 'a' + 10;
    }
    if (tag == 2){
        swap(N1, N2);
    }

    long long n1 = converttoten(N1, radix,T);//N1代表的十进制数
    long long low = findLargestDigit(N2);//N2最小的可能进制数
    long long high = max(low,n1) + 1;
    long long result = binarySearch(N2, low, high, n1);

    if (result == -1) cout << "Impossible" << endl;
    else cout << result << endl;

    return 0;
}

long long converttoten(string n1, long long radix, long long t){
    long long ans = 0;
    int len = n1.length();
    for (int i = 0; i < len; i++) {
        ans = ans*radix + map[n1[i]];
        if (ans < 0 || ans > t) return -1;
    }
    return ans;
}

int cmp(string n2, long long radix, long long t) {
    long long num = converttoten(n2, radix, t);
    if (num < 0) return 1;
    if(num < t) return -1;
    return (t == num) ? 0 : 1;
}

long long binarySearch(string n2, long long low, long long high, long long n1){
    long long mid;
    while (low <= high){
        mid = (low + high) / 2;
        int flag = cmp(n2, mid, n1);
        if(flag == 0) return mid;
        else if(flag == -1) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

long long findLargestDigit(string n){
    long long ans = -1;
    int len = n.length();
    for (int i = 0; i < len ; i++) {
        if (map[n[i]] > ans){
            ans = map[n[i]];
        }
    }
    return ans+1;
}
