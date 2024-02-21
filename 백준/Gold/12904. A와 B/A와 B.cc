#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string S, T;

void Solution() {

    while (true) {
        if (S.length() == T.length()) {
            if (T == S) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
            break;
        }

        if (T.back() == 'A') {
            T.pop_back();
        }
        else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
}

void Input() {
    cin >> S >> T;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Input();
    Solution();

    return 0;
}