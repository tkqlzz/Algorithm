#include <vector>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

struct Point {int y, x;};

int main() {
    sync();

    char map[101][101];
    int n;

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> map[i];

    Point res = {0, 0};

    for(int i=0; i<n; i++)
        for(int j=0; j<n-1; j++)
            if(map[i][j] == '.' and map[i][j+1] == '.') {
                res.x++;
                while(j < n-1 and map[i][j] == '.')
                    j++;
            }

    for(int i=0; i<n; i++)
        for(int j=0; j<n-1; j++)
            if(map[j][i] == '.' and map[j+1][i] == '.') {
                res.y++;
                while(j < n-1 and map[j][i] == '.')
                    j++;
            }

    cout << res.x << " " << res.y << endl;

    return 0;
}