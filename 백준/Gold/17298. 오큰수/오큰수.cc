#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<int> v, ans;

void Solution() {

    reverse(v.begin(), v.end());

    stack<int> st;

    for (int i = 0; i < v.size(); i++) {
        
        if (st.empty()) {
            st.push(v[i]);
            ans.push_back(-1);
        }

        else {

            if (st.top() <= v[i]) {

                while (!st.empty()) {
                    if (st.top() <= v[i]) st.pop();
                    else break;
                }

                if (st.empty()) ans.push_back(-1);
                else ans.push_back(st.top());

                st.push(v[i]);
            }
            else {
                ans.push_back(st.top());
                st.push(v[i]);
            }
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto a : ans) {
        cout << a << " ";
    }

    cout << '\n';
}

void Input() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        v.push_back(num);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();

    return 0;
}