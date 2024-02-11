#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
int originLength;

string recursion(string s) {
    int idx = 1;
    stack<char> st;

    st.push(s[0]);

    while (idx < s.length()) {

        while (!st.empty()) {
            if (st.top() > s[idx]) {
                st.pop();
                s.erase(s.begin() + idx - 1);
                return s;
            }
            else {
                break;
            }
        }

        st.push(s[idx]);
        idx++;
    }

    s.erase(s.begin() + s.length() - 1);
    return s;
}

void Solution() {
    originLength = str.length();
    string res = str;
    stack<string> ans;

    ans.push(str);
    for (int i = 0; i < originLength - 1; i++) {
        res = recursion(res);
        ans.push(res);
    }

    while (!ans.empty()) {
        cout << ans.top() << '\n';
        ans.pop();
    }
}

void Input() {
    cin >> str;
}

int main() {
    Input();
    Solution();

    return 0;
}