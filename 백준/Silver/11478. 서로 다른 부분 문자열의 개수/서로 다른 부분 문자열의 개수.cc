#include <iostream>
#include <string>
#include <set>

using namespace std;

string str;
set<string> s;

void Solution() {
    string curStr = "";
    int ans = 0;

    for (int i = 0; i < str.length(); i++) {
        curStr = "";

        for (int j = i; j < str.length(); j++) {
            curStr += str[j];

            if (s.find(curStr) == s.end()) {
                s.insert(curStr);

                ans++;
            }
        }
    }

    cout << ans << '\n';
}

void Input() {
    cin >> str;
}

int main() {
    Input();
    Solution();

    return 0;
}