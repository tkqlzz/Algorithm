#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int main() {
    sync();

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end(), greater<int>());

    int res = 0;
    for(int i=0; i<n; i++)
        res = max(res, arr[i] * (i+1));

    cout << res << endl;

    return 0;
}