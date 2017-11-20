#include <vector>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

struct Edge { int to, weight; };
vector<vector<Edge>> graph;
vector<int> visit;

int res, idx;

void dfs(int i, int x) {
    if (x > res) {
        res = x;
        idx = i;
    }
    visit[i] = 1;
    for (const auto &p : graph[i]) {
        if (not visit[p.to])
            dfs(p.to, x + p.weight);
    }
}

int main() {
    sync();

    int V;
    cin >> V;
    graph.resize(V+1);

    for(int i=0; i<V; i++) {
        int e, to, weight;
        cin >> e;
        while(true) {
            cin >> to;
            if (to == -1)
                break;
            cin >> weight;
            graph[e].push_back(Edge{to, weight});
        }
    }

    res = 0;
    visit.resize(V+1, 0);
    dfs(1, 0);
    fill(visit.begin(), visit.end(), 0);
    dfs(idx, 0);

    cout << res << endl;

    return 0;
}