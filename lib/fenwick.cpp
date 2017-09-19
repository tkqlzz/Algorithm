#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'
#define MAXSIZE 10001

int tree[MAXSIZE] = {0, };
int n;

void update(int i, int x) {
    while(i <= n) {
        i += (i & -i);
        tree[i] += x;
    }
}

int sum(int i) {
    int ret = 0;
    while(i > 0) {
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}
