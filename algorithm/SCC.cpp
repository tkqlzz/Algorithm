#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

vector<vector<int>> graph;
vector<vector<int>> rev_graph;
vector<int> visit;
vector<int> st;
vector<int> tmp;
vector<vector<int>> res;

void dfs(int i) {
    visit[i] = 1;
    for(const auto &p : graph[i])
        if (not visit[p])
            dfs(p);
    st.push_back(i);
}

void dfs2(int i) {
    visit[i] = 1;
    tmp.push_back(i);
    for(const auto &p : rev_graph[i])
        if (not visit[p])
            dfs2(p);
}

int main() {
    sync();
    int v, e;
    cin >> v >> e;

    graph.resize(v+1);
    rev_graph.resize(v+1);
    visit.resize(v+1, 0);

    int a, b;
    for(int i=0; i<e; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }

    for(int i=1; i<=v; i++)
        if (not visit[i])
            dfs(i);

    fill(visit.begin(), visit.end(), 0);

    while(not st.empty()) {
        int i = st.back(); st.pop_back();
        if (not visit[i]) {
            dfs2(i);
            sort(tmp.begin(), tmp.end());
            res.push_back(tmp);
            tmp.clear();
        }
    }

    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(const auto &arr : res) {
        for(const auto &i : arr) {
            cout << i << " ";
        }
        cout << -1 << endl;
    }

}