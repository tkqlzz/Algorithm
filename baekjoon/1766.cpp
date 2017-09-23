#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int main() {
    sync();

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> rev_graph_cnt(n+1, 0);

    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        rev_graph_cnt[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1; i<=n; i++)
        if (not rev_graph_cnt[i])
            pq.push(i);

    int i;
    while (not pq.empty()) {
        i = pq.top(); pq.pop();
        cout << i << " ";
        for (const auto &j: graph[i]) {
            rev_graph_cnt[j]--;
            if (not rev_graph_cnt[j])
                pq.push(j);
        }
    }

    return 0;
}