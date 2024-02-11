#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T;
string str;

int is_Palindrom(int i, int j, int cnt) {

    while (i < j) {
        if (str[i] == str[j]) {
            i++;
            j--;
        }
        else {
            if (cnt == 0) {
                if (is_Palindrom(i + 1, j, cnt + 1) == 0 || is_Palindrom(i, j - 1, cnt + 1) == 0) {
                    return 1;
                }
                else return 2;
            }
            else {
                return 2;
            }
        }
    }

    return 0;
}

void Solution() {
    int i = 0, j = str.size() - 1, cnt = 0;
    cout << is_Palindrom(i, j, cnt) << '\n';
}

void Input() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> str;
        Solution();
    }
}

int main() {
    Input();

    return 0;
}