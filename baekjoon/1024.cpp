#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int main() {
    sync();

    int n, l;
    cin >> n >> l;

    int s, m, e;
    for (int i=l; i<101; i++) {
        m = n/i;
        s = m - (i-1) / 2;
        e = m + (i+2) / 2;
        if (s >= 0 and n == (s+e-1)*i/2) {
            for (int j=s; j<e; j++)
                cout << j << " ";
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}