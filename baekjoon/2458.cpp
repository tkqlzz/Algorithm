#include <vector>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

vector<int> visit;

int dfs(vector<vector<int>> &graph, int cur) {
    int cnt = 1;
    for(const auto &next : graph[cur]) {
        if(visit[next])
            continue;
        visit[next] = 1;
        cnt += dfs(graph, next);
    }
    return cnt;
}

int main() {
    sync();

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<vector<int>> rev_graph(n+1);
    visit.resize(n+1, 0);

    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }

    int res = 0, cnt;
    for(int i=1; i<=n; i++) {
        cnt = 0;
        fill(visit.begin(), visit.end(), 0);
        visit[i] = 1;
        cnt += dfs(graph, i);
        cnt += dfs(rev_graph, i);
        cnt--;
        if (n == cnt)
            res++;
    }

    cout << res << endl;

    return 0;
}