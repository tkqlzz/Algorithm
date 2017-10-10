#include <vector>
#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

int get_priority(char c) {
    switch (c) {
        case '*':
            return 3;
        case '+':
            return 2;
        case ')':
            return 1;
        case '(':
            return 0;
    }
    return -1;
}

void infix_to_postfix(string &str) {
    vector<char> op; // 연산자를 담을 스택
    string out; // 출력되는값
    int curPriority; // 현재우선순위값
    int size = str.size();
    for (int i = 0; i < size; i++) {
        curPriority = get_priority(str[i]);
        if (curPriority == -1) // 연산자가 아닐경우
            out.push_back(str[i]);
        else { // 연산자 일경우
            // 빈 스택이 아니고, '('가 아니며, 우선순위가 낮을경우 pop
            while (not op.empty() and curPriority and get_priority(op.back()) > curPriority) {
                out.push_back(op.back());
                op.pop_back();
            }
            if(not op.empty() and op.back() == '(' and str[i] == ')')
                op.pop_back();
            else
                op.push_back(str[i]);
        }
    }
    while (not op.empty()) {
        out.push_back(op.back());
        op.pop_back();
    }
    str = out;
}

int eval_postfix(string &str) {
    vector<int> stack;
    int a, b, c;
    int size = str.size();
    for (int i=0; i < size; i++) {
        if (get_priority(str[i]) == -1) // 피연산자일경우
            stack.push_back(str[i] - '0');
        else { // 연산자 일경우
            a = stack.back(); stack.pop_back();
            b = stack.back(); stack.pop_back();
            if (str[i] == '*')
                c = a * b;
            else if (str[i] == '+')
                c = a + b;
            stack.push_back(c);
        }
    }
    return stack.back();
}

int main() {
    sync();

    for(int TC=1; TC<=10; TC++) {
        int n;
        cin >> n;

        string str;
        cin >> str;

        infix_to_postfix(str);
        cout << "#" << TC << " " << eval_postfix(str) << endl;
    }

    return 0;
}