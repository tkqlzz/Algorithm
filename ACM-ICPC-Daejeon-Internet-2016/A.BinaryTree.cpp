#include <queue>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

vector<int> tree;
int n, k;

int max_travel(int i, int s) {
    if (i*2 < n)
        return max(max_travel(i*2, s + tree[i*2]), max_travel(i*2+1, s + tree[i*2+1]));
    return s;
}

int main() {
    sync();

    cin >> k;

    n = (1 << k+1);

    tree.resize(n, 0);

    for(int i=2; i<n; i++)
        cin >> tree[i];

    int maxN = max_travel(1, 0);
    int res = 0;

    for(int i=2; i<n; i++) {
        tree[i] = max(tree[i], maxN - (tree[i/2] + max_travel(i, 0)));
        res += tree[i];
        tree[i] += tree[i/2];
    }

    cout << res << endl;

    return 0;
}