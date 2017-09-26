#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

typedef pair<int, char> P;

vector<pair<int, char>> same_cnt(char *arr, int size) {
    vector<pair<int, char>> ret;
    int cnt;
    for(int i=0; i<size; i++) {
        cnt = 0;
        for(int j=0; j<size; j++)
            if (arr[i] == arr[j])
                cnt++;
        ret.push_back(P(cnt, arr[i]));
    }
    sort(ret.begin(), ret.end(), greater<P>());
    return ret;
}

bool is_ascending (char *arr, int size) {
    vector<char> temp;
    for(int i=0; i<size; i++)
        temp.push_back(arr[i]);
    sort(temp.begin(), temp.end());
    for(int i=1; i<size; i++)
        if (temp[i-1] + 1 != temp[i])
            return false;
    return true;
}

int maxNum (char *arr, int size) {
    int ret = 0;
    for(int i=0; i<size; i++)
        ret = max(ret, arr[i]-'0');
    return ret;
}


int main() {
    sync();

    char color[6];
    char number[6];
    for(int i=0; i<5; i++) {
        cin >> color[i] >> number[i];
    }

    vector<pair<int, char>> col_same_cnt = same_cnt(color, 5);
    vector<pair<int, char>> num_same_cnt = same_cnt(number, 5);

    int res;
    if (col_same_cnt[0].first == 5 and is_ascending(number, 5))
        res = 900 + maxNum(number, 5);
    else if (num_same_cnt[0].first == 4)
        res = 800 + (num_same_cnt[0].second-'0');
    else if (num_same_cnt[0].first == 3 and num_same_cnt[3].first == 2)
        res = 700 + (num_same_cnt[0].second-'0') * 10 + (num_same_cnt[3].second-'0');
    else if (col_same_cnt[0].first == 5)
        res = 600 + maxNum(number, 5);
    else if (is_ascending(number, 5))
        res = 500 + maxNum(number, 5);
    else if (num_same_cnt[0].first == 3)
        res = 400 + (num_same_cnt[0].second-'0');
    else if (num_same_cnt[0].first == 2 and num_same_cnt[2].first == 2)
        res = 300 + max(num_same_cnt[0].second-'0', num_same_cnt[2].second-'0') * 10
              + min(num_same_cnt[0].second-'0', num_same_cnt[2].second-'0');
    else if (num_same_cnt[0].first == 2)
        res = 200 + (num_same_cnt[0].second-'0');
    else
        res = 100 + maxNum(number, 5);

    cout << res << endl;

    return 0;
}

