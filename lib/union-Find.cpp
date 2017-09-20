#include <iostream>
#include <vector>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

vector<int> parent;
vector<int> rank;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rank[a] > rank[b])
            parent[b] = a;
        else {
            parent[a] = b;
            if (rank[a] == rank[b])
                rank[b]++;
        }
    }
}

int main() {
    sync();

    int n, m;

    cin >> n >> m;

    parent.resize(n+1, 0);
    rank.resize(n+1, 0);

    for(int i=0; i<m; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if (o) {
            if (find(a) == find(b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else
            merge(a, b);
    }

    return 0;
}