#include <vector>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'
#define MAXSIZE 101

struct Board {
    int v, d, max;
};

struct Point {
    int y, x, v, d; // v 값 d 방향
};

Board map[MAXSIZE][MAXSIZE];
int n, m, k;
int direct[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int solve() {
    int cnt = 1;

    while(cnt <= m) {
        vector<Point> s;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) {
                if (map[i][j].v) {
                    s.push_back(Point{i, j, map[i][j].v, map[i][j].d});
                    map[i][j] = {0, 0, 0};
                };
            }

        Point p;
        int cy, cx;
        for(int i=0; i<s.size(); i++) {
            p = s[i];
            cy = p.y + direct[p.d][0];
            cx = p.x + direct[p.d][1];
            if (cy == 0 or cx == 0 or cy == n-1 or cx == n-1) {
                map[cy][cx].v = p.v / 2;
                if (p.d & 1)
                    p.d += 1;
                else
                    p.d -= 1;
                map[cy][cx].d = p.d;
            } else {
                if (map[cy][cx].max < p.v) {
                    map[cy][cx].v += p.v;
                    map[cy][cx].d = p.d;
                    map[cy][cx].max = p.v;
                } else
                    map[cy][cx].v += p.v;
            }
        }

        cnt++;
    }

    int ret = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            ret += map[i][j].v;
            map[i][j] = {0, 0, 0};
        }

    return ret;
}

int main() {
    sync();
    int T;
    cin >> T;
    for(int TC=1; TC<=T; TC++) {

        cin >> n >> m >> k;

        int y, x, v, d;

        for (int i = 0; i < k; i++) {
            cin >> y >> x >> v >> d;
            map[y][x] = {v, d, 0};
        }

        int res = solve();

        cout << "#" << TC << " " <<  res << endl;
    }
}