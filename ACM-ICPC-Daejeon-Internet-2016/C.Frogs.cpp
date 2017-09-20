#include <queue>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

struct Point {int y, x;};

int u, v, w, l;

int get_dist(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int dijkstra(vector<Point> start, vector<Point> goal, vector<vector<Point>> wood) {
    vector<int> dist(wood.size(), 2e9);
    vector<bool> visit(wood.size(), false);

    typedef pair<int, int> P;
    priority_queue<P, vector<P>, greater<P>> pq;

    // start - wood 사이 최소거리
    for(int i=0; i<start.size(); i++)
        for(int j=0; j<wood.size(); j++)
            for(int k=0; k<2; k++) {
                int d = get_dist(start[i], wood[j][k]);
                if (d <= l)
                    dist[j] = min(dist[j], d);
            }

    // wood - wood 사이 최소거리
    for(int i=0; i<wood.size(); i++)
        pq.push(P(dist[i], i));

    while (not pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        if (visit[cur])
            continue;
        visit[cur] = true;

        for(int i=0; i<wood.size(); i++)
            for(int j=0; j<2; j++)
                for(int k=0; k<2; k++) {
                    int d = get_dist(wood[cur][j], wood[i][k]);
                    if (d <= l)
                        dist[i] = min(dist[i], dist[cur] + d);
                }
    }

    int ret = 2e9;
    // start - goal 바로 갈수 있는 경우
    for(int i=0; i<start.size(); i++)
        for(int j=0; j<goal.size(); j++) {
            int d = get_dist(start[i], goal[j]);
            if (d <= l)
                ret = min(ret, d);
        }

    // wood - goal 사이 최소거리
    for(int i=0; i<wood.size(); i++)
        if(dist[i] < 2e9)
            for(int j=0; j<goal.size(); j++)
                for(int k=0; k<2; k++) {
                    int d = get_dist(wood[i][k], goal[j]);
                    if (d <= l)
                        ret = min(ret, dist[i] + d);
                }
    if (ret == 2e9)
        ret = -1;
    return ret;
};

int main() {
    sync();

    int n, m;
    cin >> n >> m;

    cin >> u >> v >> w >> l;

    vector<Point> start(u);
    vector<Point> goal(v);
    vector<vector<Point>> wood(w);

    for(int i=0; i<u; i++)
        cin >> start[i].x >> start[i].y;
    for(int i=0; i<v; i++)
        cin >> goal[i].x >> goal[i].y;

    Point p;
    int y, x;
    for(int i=0; i<w; i++) {
        for(int j=0; j<2; j++) {
            cin >> x >> y;
            p = {y, x};
            wood[i].push_back(p);
        }
    }

    cout << dijkstra(start, goal, wood) << endl;

    return 0;
}