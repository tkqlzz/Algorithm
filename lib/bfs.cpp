#include <iostream>
#include <queue>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs() {
    queue q;

    while (not q.empty()) {
        int cur = q.pop();
        int next;
        q.push(next);
    }
}