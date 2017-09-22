#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int main() {
    sync();

    string s;
    getline(cin, s);
    while (s != "EOI") {
        for(int i=0; i<s.size(); i++)
            if (s[i] >= 'a' and s[i] <= 'z')
                s[i] -= ('a' - 'A');

        if (s.find("NEMO") == -1)
            cout << "Missing" << endl;
        else
            cout << "Found" << endl;
        getline(cin, s);
    }

}