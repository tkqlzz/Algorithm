#include <queue>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int main() {
    sync();

    int n, w, L;
    cin >> n >> w >> L;

    vector<int> arr(n);
    queue<int> q;
    for(int i=0; i<w; i++)
        q.push(0);

    for(int i=0; i<n; i++)
        cin >> arr[i];

    int res, i, s;
    res = i = s = 0;
    while(i != n or s) {
        res++;
        s -= q.front();
        q.pop();
        if(i < n and s + arr[i] <= L) {
            q.push(arr[i]);
            s += arr[i];
            i++;
        } else
            q.push(0);
    }
    cout << res << endl;
    return 0;
}