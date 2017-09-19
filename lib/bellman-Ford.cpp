#include <iostream>
#include <vector>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'
#define MAX 1e9

struct edge {int from, to, length;};
int V, E;

void bellmanFord(vector<edge> edges, int start) {
    vector<int> dist(V+1, MAX);
    dist[start] = 0;

    for(int i=1; i<=V; i++)
        for(int j=0; j<E; j++)
            if(dist[edges[j].from] != MAX)
                dist[edges[j].to] = min(dist[edges[j].to], dist[edges[j].from] + edges[j].length);

    // 음의 사이클 판별
    for(int i=0; i<E; i++)
        if(dist[edges[i].from] != MAX and dist[edges[i].from] + edges[i].length < dist[edges[i].to]) {
            cout << -1 << endl;
            return;
        }

    for(int i=2; i<=V; i++) {
        if(dist[i] == MAX)
            cout << -1 << endl;
        else
            cout << dist[i] << endl;
    }
}

int main() {
    sync();
    cin >> V >> E;

    vector<edge> edges;

    int a, b, c;
    for(int i=0; i<E; i++) {
        cin >> a >> b >> c;
        edge e = {a, b, c};
        edges.push_back(e);
    }

    bellmanFord(edges, 1);

    return 0;
}