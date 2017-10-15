#include <cstring>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int d, w, k, res;
int arr[13][20];

bool isCheck() {
    int cnt;
    bool isNext;
    for(int j=0; j<w; j++) {
        cnt = 1; isNext = false;
        for(int i=1; i<d; i++) {
            if (arr[i][j] != arr[i-1][j]) cnt = 1;
            else cnt++;
            if (cnt == k) {
                isNext = true;
                break;
            }
        }
        if (not isNext)
            return false;
    }
    return true;
}

void dfs(int col, int cnt) {
    if (cnt > k or cnt >= res)
        return;

    if (isCheck()) {
        res = min(res, cnt);
        return;
    }

    int temp[20];
    for (int i=col+1; i<d; i++) {

        memcpy(temp, arr[i], sizeof(temp));
        for(int j=0; j<w; j++)
            arr[i][j] = 0;
        dfs(i, cnt+1);
        for(int j=0; j<w; j++)
            arr[i][j] = 1;
        dfs(i, cnt+1);
        memcpy(arr[i], temp, sizeof(temp));
    }
}

int main() {
    sync();

    int T;
    cin >> T;

    for (int TC=1; TC<=T; TC++) {
        cin >> d >> w >> k;
        for(int i=0; i<d; i++)
            for(int j=0; j<w; j++)
                cin >> arr[i][j];

        res = 1e9;
        dfs(-1, 0);
        cout << "#" << TC << " " << res << endl;

    }

    return 0;
}