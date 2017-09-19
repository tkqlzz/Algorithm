#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'
#define MAXSIZE 101

int adj[MAXSIZE][MAXSIZE], n;

int floyd() {
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);

    return adj[1][n];
}

int main() {
    sync();
    int m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            adj[i][j] = 1e9;
        adj[i][i] = 0;
    }


    int u, v, w;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
    }

    floyd();

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }

    return 0;
}