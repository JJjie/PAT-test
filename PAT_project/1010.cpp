//
// Created by 胡文杰 on 2017/1/6.
//

#include "pat.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long map[256];//标记字符对应的10进制数值
const long long T = 0x7fffffffffffffff;//表示long long 的最大值

long long converttoten(string n1, long long radix, long long t);
long long binarySearch(string n2, long long low, long long high, long long n1);
int findLargestDigit(string n);

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
    unsigned long len = n1.length();
    for (int i = 0; i < len; i++) {
        ans = ans*radix + map[n1[i]];
        if (ans < 0 || ans > t) return -1;
    }
    return ans;
}

long long binarySearch(string n2, long long low, long long high, long long n1){
    long long mid;
    while (low <= high){
        mid = (low + high) / 2;
        long long num = converttoten(n2, mid, n1);
        if(num == n1) return mid;
        else if(num < n1 && num >= 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int findLargestDigit(string n){
    int ans = -1;
    unsigned long len = n.length();
    for (int i = 0; i < len ; i++) {
        if (map[n[i]] > ans){
            ans = map[n[i]];
        }
    }
    return ans+1;
}
