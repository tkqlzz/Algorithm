#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int main() {
    sync();

    string s;
    deque<char> dq;

    cin >> s;
    s = '#' + s;
    int size = s.size();
    for(int i=0;i<size; i++)
        dq.push_back(s[i]);

    int n;
    char op, data;
    cin >> n;
    while(n--) {
        cin >> op;
        if (op == 'P') {
            cin >> data;
            dq.push_back(data);
        } else if (op == 'L')  {
            if (dq.back() != '#') {
                data = dq.back(); dq.pop_back();
                dq.push_front(data);
            }
        } else if (op == 'D') {
            if (dq.front() != '#') {
                data = dq.front(); dq.pop_front();
                dq.push_back(data);
            }
        } else if (op == 'B') {
            if (dq.back() != '#')
                dq.pop_back();
        }
    }

    while (dq.front() != '#') {
        data = dq.front(); dq.pop_front();
        dq.push_back(data);
    }
    dq.pop_front();

    while (not dq.empty()) {
        cout << dq.front(); dq.pop_front();
    }

    return 0;
}

