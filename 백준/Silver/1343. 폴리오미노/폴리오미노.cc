#include <iostream>
#include <string>

using namespace std;

string str;

void Solution() {
    int cnt = 0;
    string res = "";

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.') {
            while (cnt != 0) {
                if (cnt - 4 >= 0) {
                    cnt -= 4;
                    res += "AAAA";
                }
                else if (cnt - 2 >= 0) {
                    res += "BB";
                    cnt -= 2;
                }
                else {
                    res = "-1";
                    cout << res << '\n';
                    return;
                }
            }
            res += ".";
        }
        else {
            cnt++;
        }
    }

    while (cnt != 0) {
        if (cnt - 4 >= 0) {
            cnt -= 4;
            res += "AAAA";
        }
        else if (cnt - 2 >= 0) {
            res += "BB";
            cnt -= 2;
        }
        else {
            res = "-1";
            cout << res << '\n';
            return;
        }
    }

    cout << res << '\n';
}

void Input() {
    cin >> str;
}

int main() {
    Input();
    Solution();

    return 0;
}