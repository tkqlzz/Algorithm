#include <vector>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

vector<vector<int>> arr;
int cnt[2] = {0, };

bool same_check(int y, int x, int n) {
    int c = arr[y][x];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if (arr[y+i][x+j] != c)
                return false;

    return true;
}

void divide(int y, int x, int n) {
    if (same_check(y, x, n)) {
        cnt[arr[y][x]]++;
        return;
    }

    int m = n/2;
    divide(y, x, m);
    divide(y+m, x, m);
    divide(y, x+m, m);
    divide(y+m, x+m, m);
}

int main() {
    sync();

    int n;
    cin >> n;

    arr.resize(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];

    divide(0, 0, n);

    cout << cnt[0] << endl << cnt[1] << endl;
}