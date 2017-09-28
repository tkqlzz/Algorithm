#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

vector<int> arr;
vector<vector<long long>> dp;
int n;

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(1, arr[0]));
    dp[0][arr[0]] = 1;

    pair<int, int> p;
    int i, s;
    while(not q.empty()) {
        p = q.front(); q.pop();
        i = p.first;
        s = p.second;

        if(i >= n-1)
            break;

        for(auto x : {s + arr[i], s - arr[i]}) {
            if ( x >= 0 and x <= 20) {
                if (not dp[i][x])
                    q.push(make_pair(i+1, x));
                dp[i][x] += dp[i-1][s];
            }
        }
    }
}

int main() {
    sync();

    cin >> n;

    arr.resize(n-1);
    dp.resize(n-1, vector<long long>(21, 0));

    for(int i=0; i<n-1; i++)
        cin >> arr[i];

    int res;
    cin >> res;

    bfs();

    cout << dp[n-2][res] << endl;

    return 0;
}