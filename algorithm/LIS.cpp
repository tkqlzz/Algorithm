#include <vector>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int main() {
    sync();
    int n;
    cin >> n;

    int t;
    cin >> t;
    vector<int> dp;
    dp.push_back(t);

    for (int i=1; i<n; i++) {
        cin >> t;
        if (dp.back() < t) {
            dp.push_back(t);
        } else {
            *lower_bound(dp.begin(), dp.end(), t) = t;
        }
    }

    cout << n-dp.size() << endl;
}