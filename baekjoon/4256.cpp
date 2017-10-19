#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

struct Node {
    int data;
    Node *left;
    Node *right;
};

void postorder(Node *v) {
    if (v->left != NULL)
        postorder(v->left);
    if (v->right != NULL)
        postorder(v->right);
    cout << v->data << " ";

}

int main() {
    sync();

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n+1);
        vector<int> arr2(n+1);
        vector<int> dp(n+1);
        vector<int> dp2(n+1);
        for(int i=1; i<=n; i++) {
            cin >> arr[i];
            dp[arr[i]] = i;

        }
        for(int i=1; i<=n; i++) {
            cin >> arr2[i];
            dp2[arr2[i]] = i;
        }

        vector<Node> tree(n+1);
        for(int i=1; i<=n; i++)
            tree[i].data = arr[i];

        for(int i=1; i<n; i++) {
            if(dp2[arr[i]] > dp2[arr[i+1]])
                tree[i].left = &tree[i+1];

            int x = dp2[arr[i]] + 1, t = 2e9, index;
            if(x <= n and dp[arr[i]] < dp[arr2[x]]) {
                while (x <= n and dp[arr[i]] < dp[arr2[x]]) {
                    if (t > dp[arr2[x]] - dp[arr[i]]) {
                        t = dp[arr2[x]] - dp[arr[i]];
                        index = dp[arr2[x]];
                    }
                    x++;
                }
                tree[i].right = &tree[index];
            }
        }

        postorder(&tree[1]);
        cout << endl;

    }

    return 0;
}