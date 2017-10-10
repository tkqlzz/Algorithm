#include <queue>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int map[8][8];
int dp[8][8];
int n, k;

int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int bfs(int i, int j) {
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));

    int y, x, cy, cx, ret = 0;
    while (not q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {

            cy = y + direct[i][0];
            cx = x + direct[i][1];

            if (cy < 0 or cx < 0 or cy >=n or cx >= n)
                continue;
            if (map[cy][cx] >= map[y][x])
                continue;
            if (dp[cy][cx] >= dp[y][x]+1)
                continue;
            dp[cy][cx] = dp[y][x]+1;
            ret = max(ret, dp[cy][cx]);
            q.push(make_pair(cy, cx));
        }
    }

    return ret;
}


int main() {
    sync();

    int T;
    cin >> T;


    for(int TC=1; TC<=T; TC++) {
        cin >> n >> k;

        fill(dp[0], dp[7] + 8, 0);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> map[i][j];

        int top = 0, res = 0;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                top = max(top, map[i][j]);

        vector<pair<int, int> > arr;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(top == map[i][j]) {
                    arr.push_back(make_pair(i, j));
                    res = max(res, bfs(i, j));
                }

        int size = arr.size();

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int m=1; m<=k; m++) {
                    fill(dp[0], dp[7] + 8, 0);
                    map[i][j] -= m;
                    for(int a=0; a<size; a++)
                        res = max(res, bfs(arr[a].first, arr[a].second));
                    map[i][j] += m;
                }

        cout << "#" << TC << " " << res+1 << endl;
    }

    return 0;
}