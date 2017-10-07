#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'
#define MAXSIZE 1000

int arr[MAXSIZE];
int dp[MAXSIZE][MAXSIZE] = {0,};

int dfs(int i, int j, bool isTurn) {
    if(dp[i][j])
        return dp[i][j];
    if(i > j)
        return 0;

    if (isTurn)
        dp[i][j] = max(arr[i]+dfs(i+1,j,!isTurn), arr[j]+dfs(i,j-1,!isTurn));
    else
        dp[i][j] = min(dfs(i+1,j,!isTurn), dfs(i,j-1,!isTurn));

    return dp[i][j];
}

int main() {
    sync();

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;

        for(int i=0; i<n; i++)
            fill(dp[i], dp[i] + n, 0);

        for(int i=0; i<n; i++)
            cin >> arr[i];

        cout << dfs(0, n-1, true) << endl;
    }

    return 0;
}

