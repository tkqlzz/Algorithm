//
// Created by Jinwoo Bae on 2017-09-27.
//
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int reverse_num(int n) {
    int ret = 0;
    while (n) {
        ret *= 10;
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

bool is_prime(int n) {
    if(n <= 1)
        return false;
    int sqrtn = int(sqrt(n))+1;
    for(int i=2; i<sqrtn; i++)
        if(not (n % i))
            return false;
    return true;
}

int main() {
    sync();

    int n;
    cin >> n;

    while(n != reverse_num(n) or not is_prime(n))
        n++;
    cout << n << endl;

    return 0;
}

