#include <vector>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'
#define MAXSIZE 20

int map[MAXSIZE][MAXSIZE];
vector<int> visit(101);
int direct[4][2] = { { 1, 1 }, { -1, 1 }, { -1, -1 }, { 1, -1 } };
int n;
int res;
int sy, sx;

void move(int y, int x, int directVisit, int arrow, int cnt) {
    if (sy == y and sx == x and directVisit == (1 << 4) - 1)
        res = max(res, cnt);
    int cy, cx;
    for (int i = 0; i < 4; i++) {
        cy = y + direct[i][0];
        cx = x + direct[i][1];
        if (cy < 0 || cx < 0 || cy >= n || cx >= n)
            continue;
        if (directVisit & (1 << i) && arrow != i)
            continue;
        if (visit[map[cy][cx]])
            continue;
        visit[map[cy][cx]] = 1;
        move(cy, cx, directVisit | (1 << i), i, cnt+1);
        visit[map[cy][cx]] = 0;
    }
}

int main() {
    sync();
    int T;
    cin >> T;
    for(int TC=1; TC<=T; TC++) {
        cin >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> map[i][j];

        res = -1;
        fill(visit.begin(), visit.end(), 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (visit[map[i][j]] == 0) {
                    sy = i; sx = j;
                    move(i, j, 0, -1,0);
                }
            }

        cout << "#" << TC << " " <<  res << endl;

    }
}