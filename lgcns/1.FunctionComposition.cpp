#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int n, maxB;
pair<int, int> res;
vector<pair<int, int>> arr;

pair<int, int> dfs(int x, int b, int visit, int cnt) {
    if (visit == (1 << n) - 1) {
        if (maxB <= b) {
            maxB = b;
            return {b, x * cnt};
        } else
            return {-1, 0};
    }

    int retB = -1, retRes = 0;

    pair<int, int> p;
    for(int i=0; i<n; i++) {
        if (not (visit & (1 << i))) {
            p = dfs(i+1, arr[i].first * b + arr[i].second, visit | (1 << i), cnt+1);
            if (p.first >= maxB) {
                retB = p.first;
                retRes = p.second;
                if (visit == 0) {
                    if (res.first < retB) {
                        res.first = retB;
                        res.second = retRes;
                    } else if (res.first == retB) {
                        res.second = min(res.second, retRes);
                    }
                } else {
                    retRes += x * cnt;
                }
            }
        }
    }
    return {retB, retRes};
}



int main() {
    sync();
    ofstream outFile("1.FunctionComposition.txt");
    ifstream inFile("input.txt");
    int T;
    inFile >> T;
//    cin >> T;
    while(T--) {
        inFile >> n;
//        cin >> n;

        arr.clear();
        arr.resize(n);
        for(int i=0; i<n; i++)
            inFile >> arr[i].first >> arr[i].second;

        res = {-2e9, 2e9};
        maxB = -2e9;
        // brute force
        dfs(0, 0, 0, 0);

//        cout << res.second << endl;
        outFile << res.second << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}