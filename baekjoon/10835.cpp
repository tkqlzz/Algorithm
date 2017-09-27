#include <algorithm>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

vector<int> arr1;
vector<int> arr2;
vector<vector<int>> dp;
int n;

int solve(int i, int j) {
    if (i >= n or j >= n) {
        return 0;
    }

    int ret = 0;
    if(dp[i+1][j] == -1)
        solve(i+1, j);
    if(dp[i+1][j+1] == -1)
        solve(i+1, j+1);
    if(dp[i][j+1] == -1)
        if(arr1[i] > arr2[j])
            ret = max(ret, solve(i, j+1) + arr2[j]);

    ret = max(ret, dp[i+1][j]);
    ret = max(ret, dp[i+1][j+1]);
    dp[i][j] = max(dp[i][j], ret);
    return dp[i][j];
}

int main() {
    sync();

    cin >> n;

    arr1.resize(n);
    arr2.resize(n);
    dp.resize(n+1, vector<int>(n+1, -1));

    for(int i=0; i<n; i++)
        cin >> arr1[i];
    for(int i=0; i<n; i++)
        cin >> arr2[i];

    cout << solve(0, 0) << endl;

    return 0;
}
