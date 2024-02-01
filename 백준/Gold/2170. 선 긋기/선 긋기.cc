#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> v[1000001];

void Solution() {
    int start, end, sum = 0;
    
    // 정렬
    sort(v, v + N);

    start = v[0].first, end = v[0].second;

    // 순회
    for (int i = 1; i < N; i++) {

        // 겹치는 경우
        if (v[i].first <= end) {
            // end update (업데이트 될 end 포인트가 더 클 경우)
            if (v[i].second > end)
                end = v[i].second;
        }

        // 겹치지 않을 경우
        else {
            // 합 계산
            sum += end - start;

            // start, end update
            start = v[i].first;
            end = v[i].second;
        }
    }

    sum += end - start;

    cout << sum << '\n';
}

void Input() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
}

int main() {
    Input();
    Solution();

    return 0;
}