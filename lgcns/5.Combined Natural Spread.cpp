#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int V, E;
struct edge {long long to, length;};
struct data {
    long long from,to,length;
    bool operator<(const data& a) const{
        return length < a.length;
    }
};

vector<vector<edge>> graph;
vector<vector<long long>> dist;
vector<vector<priority_queue<data>>> trace;

void dijkstra(int start) {
    vector<bool> visit(graph.size(), false);
    dist[start][start] = 0;

    typedef pair<long long, long long> P;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, start});

    while (not pq.empty()) {

        int cur = pq.top().second;
        pq.pop();

        if (visit[cur])
            continue;
        visit[cur] = true;

        for(const auto &p : graph[cur]) {
            if (dist[start][p.to] >= dist[start][cur] + p.length) {
                dist[start][p.to] = dist[start][cur] + p.length;
                while (not trace[start][p.to].empty() and trace[start][p.to].top().length > dist[start][p.to])
                    trace[start][p.to].pop();
                trace[start][p.to].push({cur, p.to, dist[start][p.to]});
                pq.push({dist[start][p.to], p.to});
            }
        }
    }
};

int main() {
    sync();
    ofstream outFile("5.txt");
    int T;
    cin >> T;
    while(T--) {
        cin >> V >> E;
        graph.clear(); dist.clear(); trace.clear();

        graph.resize(V+1);
        dist.resize(V+1, vector<long long>(V+1, 2e9));
        trace.resize(V+1, vector<priority_queue<data>>(V+1));

        int u, v, w;
        for(int i=0; i<E; i++) {
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
        }

        for(int i=1; i<=V; i++)
            dijkstra(i);

        vector<vector<int>> dp(V+1, vector<int>(V+1, 0));
        data d;
        for (int i=1; i<=V; i++) {
            for (int j=1; j<=V; j++) {
                if(trace[i][j].size() == 1) {
                    d = trace[i][j].top(); trace[i][j].pop();
                    dp[d.from][d.to] = 1;
                }
            }
        }

        int cnt, size;

        for (int i=1; i<=V; i++) {
            for (int j=1; j<=V; j++) {
                cnt = 0;
                size = trace[i][j].size();
                while(not trace[i][j].empty()) {
                    d = trace[i][j].top(); trace[i][j].pop();
                    if (not dp[d.from][d.to])
                        cnt++;
                }
            }
        }

        long long res = 0;

        for (int i=1; i<=V; i++) {
            for (int j = 1; j <= V; j++) {
                if(dp[i][j])
                    res += dist[i][j];
            }
        }
        outFile << res << endl;
    }

    return 0;
}