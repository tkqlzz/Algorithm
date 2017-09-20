#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

struct edge {int v1, v2, w;};

bool cmp(const edge &a, const edge &b) {
    return a.w < b.w;
}

vector<int> parent;
vector<int> ranks;

vector<edge> edges;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (ranks[a] > ranks[b])
            parent[b] = a;
        else {
            parent[a] = b;
            if (ranks[a] == ranks[b])
                ranks[b]++;
        }
    }
}

int kruskal(int size) {
    sort(edges.begin(), edges.end(), cmp);
    int a, b, ret = 0;
    for(int i=0; i<size; i++) {
        a = find(edges[i].v1);
        b = find(edges[i].v2);
        if (a == b)
            continue;
        merge(a, b);
        ret += edges[i].w;
    }
    return ret;
}

int main() {
    sync();

    int V, E;
    cin >> V >> E;

    parent.resize(V+1);
    for(int i=1; i <= V; i++)
        parent[i] = i;
    ranks.resize(V+1, 0);

    int a, b, c;
    for(int i = 0; i<E; i++) {
        cin >> a >> b >> c;
        edge e = {a, b, c};
        edges.push_back(e);
    }

    cout << kruskal(E) << endl;

    return 0;
}