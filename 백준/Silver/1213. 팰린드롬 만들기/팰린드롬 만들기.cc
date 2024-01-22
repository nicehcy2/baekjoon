#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int alp[100];
bool visited[100];

void Solution() {
    for (int i = 0; i < str.size(); i++) {
        alp[str[i]] += 1;
    }

    sort(str.begin(), str.end());

    // 홀수의 개수
    int cnt = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
        if (alp[i] % 2 != 0) {
            cnt++;
        }
    }

    // 홀수의 개수가 2개 이상이면 회문이 안된다
    if (cnt > 1) {
        cout << "I'm Sorry Hansoo\n";
        return;
    }

    // 예외: 개수가 홀수만 하나는 뒤로 빠져야함
    // 절반만 연산하고 나머지는 reverse해서 붙여 넣음.

    string ans = "";
    string copy = "";
    for (int i = 0; i < str.size(); i++) {
        // 방문했으면 넘어감
        if (visited[str[i]] == true) {
            continue;
        }

        visited[str[i]] = true;
        if (alp[str[i]] % 2 == 1) {
            copy += str[i];
        }

        for (int j = 0; j < alp[str[i]] / 2; j++) {
            ans += str[i];
        }
    }

    string rev = "";
    for (int i = ans.size() - 1; i >= 0; i--) {
        rev += ans[i];
    }
    ans += copy;
    ans += rev;

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