#include <iostream>
#include <queue>

using namespace std;

int N;

struct compare {
    bool operator() (int a, int b) {
        long fa = abs(a);
        long fb = abs(b);

        if (fa == fb) {
            return a > b; // 절댓값이 같을 때는 음수 우선 정렬
        }
        else return fa > fb;
    }
};

priority_queue<int, vector<int>, compare> pq;

void Solution() {

    while (N--) {
        int num; cin >> num;

        if (num == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(num);
        }
    }
}

void Input() {

    cin >> N;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();

    return 0;
}