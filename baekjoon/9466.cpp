#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'
#define MAXSIZE 100001

int arr[MAXSIZE], visit[MAXSIZE];

int x;
bool dfs(int cur) {
    if (visit[x] and cur == x)
        return true;

    if (visit[cur])
        return false;
    visit[cur] = 1;
    if (dfs(arr[cur]))
        return true;
    else
        visit[cur] = 0;
    return false;
}

int main() {
    sync();

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        fill(visit, visit+n+1, 0);

        for(int i=1; i<=n; i++)
            cin >> arr[i];

        int cnt = 0;
        for(x=1; x<=n; x++)
            if(not visit[x])
                if (not dfs(x)) {
                    cnt++;
                    visit[x] = 1;
                }
        cout << cnt << endl;
    }


    return 0;
}