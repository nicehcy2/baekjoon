#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

void Solution() {

    int ans = 0;

    while (true) {
        
        int n1, n2, sum;
        if (!pq.empty()) {
            n1 = pq.top(); pq.pop();
        }
        else {
            cout << ans << '\n';
            break;
        }
        if (!pq.empty()) {
            n2 = pq.top(); pq.pop();
        }
        else {
            cout << ans << '\n';
            break;
        }

         sum = n1 + n2;
         ans += sum;
         pq.push(sum);
    }
}

void Input() {

    cin >> N;
    for (int i = 0; i < N; i++) {

        int num; cin >> num;
        pq.push(num);
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