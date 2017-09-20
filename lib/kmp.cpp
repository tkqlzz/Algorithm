#include <iostream>
#include <vector>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

string str, pattern;
int n, m;

vector<int> getPi() {
    vector<int> pi(m, 0);
    int j = 0;
    for(int i=1; i<m; i++) {
        while(j > 0 and pattern[i] != pattern[j])
            j = pi[j-1];
        if (pattern[i] == pattern[j])
            pi[i] = ++j;
    }
    return pi;
}

int main() {
    sync();

    getline(cin, str);
    getline(cin, pattern);

    n = str.size();
    m = pattern.size();

    vector<int> pi = getPi();
    vector<int> res;

    // KMP
    int j = 0;
    for(int i=0; i<n; i++) {
        while (j > 0 && str[i] != pattern[j])
            j = pi[j-1];
        if (str[i] == pattern[j]) {
            if (j == m -1) {
                res.push_back(i+2 - m);
                j = pi[j];
            } else
                j++;
        }
    }

    cout << res.size() << endl;
    for(int i=0; i<res.size(); i++)
        cout << res[i] << " ";

    return 0;
}