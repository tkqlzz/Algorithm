#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'
#define MAX 1e9

// Min Segment Tree

vector<int> arr;
vector<int> tree;

void build(int i, int s, int e) {
    if (s == e)
        tree[i] = arr[s];
    else {
        build(i*2, s, (s+e)/2);
        build(i*2+1, (s+e)/2+1, e);
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }
}

int query(int i, int s, int e, int l, int r) {
    if (l > e or r < s)
        return MAX;
    if (l <= s and r >= e)
        return tree[i];
    else
        return min(query(i*2, s, (s+e)/2, l, r), query(i*2+1, (s+e)/2+1, e, l, r));
}

int main() {
    sync();
    int n, m;

    cin >> n >> m;
    arr.resize(n+1);
    tree.resize((1 << int(ceil(log2(n)+1))));

    for(int i=1; i<=n; i++)
        cin >> arr[i];

    build(1,1, n);

    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << endl;
    }

    return 0;
}