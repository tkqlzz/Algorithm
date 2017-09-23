#include <queue>
#include <vector>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int main() {
    sync();

    int n, m;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++)
        cin >> arr[i];
    cin >> m;

    vector<int> s(n-m+1, 0);

    for(int i=0; i<m; i++)
        s[0] += arr[i];
    for(int i=1; i<=n-m; i++)
        s[i] = s[i-1] - arr[i-1] + arr[i+m-1];

    vector<int> dp(n, 0);

    priority_queue<pair<int,int>> pq;
    for(int i=2*m; i<=n-m; i++)
        pq.push(make_pair(s[i], i));
    for(int i=2*m; i<=n-m; i++) {
        while(i > pq.top().second)
            pq.pop();
        dp[i] = pq.top().first;
    }

    while(not pq.empty()) pq.pop();
    for(int i=m; i<=n-2*m; i++)
        pq.push(make_pair(s[i]+dp[i+m], i));
    for(int i=m; i<=n-2*m; i++) {
        while(i > pq.top().second)
            pq.pop();
        dp[i] = pq.top().first;
    }

    int res = 0;
    for(int i=0; i<=n-3*m; i++)
        res = max(res, s[i] + dp[i+m]);

    cout << res << endl;

    return 0;
}