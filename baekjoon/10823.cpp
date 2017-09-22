#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int main() {
    sync();

    string s;
    while(not cin.eof()) {
        string t;
        cin >> t;
        s += t;
    }
    stringstream ss(s);

    int i, sum = 0;
    while (ss >> i) {
        sum += i;
        if (ss.peek() == ',')
            ss.ignore();
    }

    cout << sum << endl;

}