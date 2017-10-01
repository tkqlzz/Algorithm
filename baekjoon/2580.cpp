#include <algorithm>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int board[9][9];
int y_mask[9] = {0,};
int x_mask[9] = {0,};
int s_mask[9] = {0,};
vector<pair<int, int>> arr;
int size;

bool dfs(int pos) {
    if (pos >= size)
        return true;

    int y = arr[pos].first, x = arr[pos].second;
    int ry = y/3*3, rx = x/3, t;
    int n = ((1 << 10) - 1) ^ (y_mask[x] | x_mask[y] | s_mask[ry+rx]);
    for(int i=1; i<=9; i++) {
        if ((1 << i) & n) {
            t = 1 << i;
            board[y][x] = i;
            y_mask[x] |= t;
            x_mask[y] |= t;
            s_mask[ry+rx] |= t;
            if (dfs(pos+1))
                return true;
            board[y][x] = 0;
            y_mask[x] -= t;
            x_mask[y] -= t;
            s_mask[ry+rx] -= t;
        }
    }
    return false;
}

int main() {
    sync();

    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++) {
            cin >> board[i][j];
            if (not board[i][j])
                arr.push_back({i, j});
        }

    size = arr.size();

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            y_mask[i] |= (1 << board[j][i]);
            x_mask[i] |= (1 << board[i][j]);
            s_mask[i/3*3+j/3] |= (1 << board[i][j]);
        }
    }

    dfs(0);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }

    return 0;
}