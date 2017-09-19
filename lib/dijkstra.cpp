#include <queue>
#include <iostream>
using namespace std;
#define endl '\n'

int V, E, K;
struct edge {int to, length;};

void dijkstra(vector<vector<edge>> graph, int start) {
    vector<int> dist(graph.size(), 1e9);
    vector<bool> visit(graph.size(), false);
    dist[start] = 0;

    typedef pair<int, int> P;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, start));

    while (not pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        if (visit[cur])
            continue;
        visit[cur] = true;

        for(auto &p : graph[cur]) {
            if (dist[p.to] > dist[cur] + p.length) {
                dist[p.to] = dist[cur] + p.length;
                pq.push(P(dist[p.to], p.to));
            }
        }
    }

    for(int i=1; i<=V; i++) {
        if (dist[i] != 1e9)
            cout << dist[i] << endl;
        else
            cout << "INF" << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    cin >> V >> E >> K;
    vector<vector<edge>> graph(V+1);
    int u, v, w;
    edge temp;
    for(int i=0; i<E; i++) {
        cin >> u >> v >> w;
        temp = {v, w};
        graph[u].push_back(temp);
    }

    dijkstra(graph, K);

    return 0;
}