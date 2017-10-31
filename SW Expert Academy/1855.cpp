#include <queue>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

#define MAX 18
int parent[100001][MAX];

int main() {
    sync();

    int T;
    cin >> T;

    for(int TC=1; TC<=T; TC++) {
        int n, m;
        cin >> n;
        m = log2(n) + 1;

        memset(parent, 0, sizeof(parent));
        vector<vector<int> > graph(n+1);
        vector<int> rank(n+1, 0);

        int a, b;
        for(b=2; b<=n; b++) {
            cin >> a;
            graph[a].push_back(b);
            parent[b][0] = a;
        }

        // parent[i][j] 는 i의 2^j번째 부모를 뜻함
        for(int j=0; j<m-1; j++)
            for(int i=2; i<=n; i++)
                if(parent[i][j])
                    parent[i][j+1] = parent[parent[i][j]][j];

        queue<int> q;
        // root 노드 자식들을 큐에 삽입
        for(int i=0; i<graph[1].size(); i++)
            q.push(graph[1][i]);

        int next, cur; // 가야할 노드, 현재위치해 있는 노드
        int p1, p2; // next, cur의 부모노드
        long long res = 0;
        cur = 1; // 시작점은 root(1)
        while(not q.empty()) {
            next = q.front(); q.pop();
            rank[next] = rank[parent[next][0]] + 1; // 트리 깊이 갱신

            p1 = next; p2 = cur;
            int diff = rank[p1] - rank[p2]; // 두 노드의 깊이 차이

            // 두 노드의 깊이가 다르면 맞춰줌
            /* 앞에서 만든 parent배열로
             * diff를 2진수 자리수만큼 반복문을 돌려
             * 1인 자리수만큼 점프해줌 */
            for(int i=0; diff; i++) {
                if (diff % 2)
                    p1 = parent[p1][i];
                diff /= 2;
            }

            // 동등한 깊이일때 두 노드가 같지 않다면
            /* 두 노드의 상위노드인 2^m-1 부터 비교해서 부모가 다르면
             * 두 노드의 상위노드인 2^i+1가 같은부모를 가지도록 2^i의 값으로
             * 점프하여 최소의 공통분모를 찾도록 i=0까지 반복 */
            if (p1 != p2) {
                for (int i=m-1; i>=0; i--) {
                    if (parent[p1][i] != parent[p2][i]) {
                        p1 = parent[p1][i];
                        p2 = parent[p2][i];
                    }
                }
                p1 = parent[p1][0];
            }

            // 목적지인 노드의 자식들을 큐에 삽입
            for(int i=0; i<graph[next].size(); i++)
                q.push(graph[next][i]);

            // 이동거리 = 두 노드의 root에서부터의 깊이합 - 최소공통조상의 깊이*2
            res += rank[cur] + rank[next] - (rank[p1] * 2);
            cur = next;
        }

        cout << "#" << TC << " "<< res << endl;
    }
}

