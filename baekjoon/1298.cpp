#include <vector>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

vector<vector<int>> graph;
vector<bool> visit;
vector<int> A, B;


bool dfs(int a) {
    visit[a] = true;
    for (const auto &b : graph[a])
        if (not B[b] or (not visit[B[b]] and dfs(B[b]))) {
            A[a] = b;
            B[b] = a;
            return true;
        }
    return false;
}


int main() {
    sync();

    int n, m;

    cin >> n >> m;

    graph.resize(n+1);
    visit.resize(n+1);
    A.resize(n+1, 0);
    B.resize(n+1, 0);

    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int cnt = 0;
    for(int i=1; i<=n; i++)
        if (not A[i]) {
            fill(visit.begin(), visit.end(), false);
            if(dfs(i))
                cnt++;
        }

    cout << cnt << endl;

    return 0;
}