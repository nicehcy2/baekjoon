#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int N, K;
string num;

void Solution() {
    int cnt = 0;
    stack<int> s;

    s.push(num[0]);

    for (int i = 1; i < N; i++) {
        while (!s.empty()) {
            if (s.top() < num[i] && cnt != K) {
                s.pop();
                cnt++;
            }
            else {
                break;
            }
        }

        s.push(num[i]);
    }

    string ans = "";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < N - K; i++) {
        cout << ans[i];
    }
    cout << '\n';
}

void Input() {
    cin >> N >> K;
    cin >> num;
}

int main() {
    Input();
    Solution();

    return 0;
}