#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
stack<int> s;

void Solution() {
    
    int target, cur = 1;
    string str;
    
    for (int i = 1; i <= n; i++) {

        cin >> target;

        while (true) {

            if (!s.empty() && s.top() != target && cur == n + 1) {
                cout << "NO\n";
                return;
            }

            if (!s.empty() && s.top() == target) {

                s.pop();
                str += "-";
                break;
            }

            s.push(cur++);
            str += "+";
        }
    }

    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << '\n';
    }
    
}

void Input() {

    cin >> n;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();

    return 0;
}