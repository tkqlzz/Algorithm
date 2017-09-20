#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXSIZE 100001

int main(){
    int n;
    scanf("%d", &n);

    pair<int, int> arr[MAXSIZE];
    for(int i=0; i<n; i++) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
        if (arr[i].first < arr[i].second) swap(arr[i].first, arr[i].second);
    }
    sort(arr, arr+n);

    int d;
    scanf("%d", &d);

    int res = 0;
    priority_queue<int> q;
    for(int i=0; i<n; i++) {
        q.push(-arr[i].second);
        while ( !q.empty() and -q.top() < arr[i].first-d)
            q.pop();
        res = max(res, int(q.size()));
    }

    printf("%d", res);

    return 0;
}
