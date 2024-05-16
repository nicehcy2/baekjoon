#include <iostream>
#include <deque>

using namespace std;

// <value, index>
deque<pair<int, int>> dq;
int N, L;

void Solution() {
    
}

void Input() {
    
    cin >> N >> L;
    int now;

    for (int i = 0; i < N; i++) {
        
        cin >> now;

        // 현재 수가 deque의 뒷 부분보다 작으면 뒷 부분을 pop -> 정렬 효과
        while (dq.size() && dq.back().first > now) {
            dq.pop_back();
        }
        
        dq.push_back({ now, i });

        // 슬라이딩 윈도우 범위가 아닌 인덱스 삭제
        // front 부분이 가장 오래 있었다. <- 나중에 들어온게 더 작을 경우 교체 되므로
        if (dq.front().second < i - L + 1) {
            dq.pop_front();
        }

        cout << dq.front().first << ' ';
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