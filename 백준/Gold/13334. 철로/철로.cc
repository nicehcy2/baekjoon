#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, D;
pair<int, int> arr[100001];

struct Compare {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

void Solution() {
    int ans = 0, start, end;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    // 정렬 
    sort(arr, arr + N);

    //초기화
    start = arr[0].second, end = arr[0].first;
    
    if (end - start <= D) pq.push({ start, end });

    for (int i = 1; i < N; i++) {
        pq.push({ arr[i].second, arr[i].first });

        // D 범위에서 속하면
        if (arr[i].first - pq.top().first <= D) {
            
            if (pq.size() > ans) {
                ans = pq.size();
            }

        } // 속하지 않으면
        else {
            // 가장 왼쪽에 있는 선 제거

            while (pq.size() != 1) {
                pq.pop();

                if (arr[i].first - pq.top().first <= D) {
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}

void Input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;

        if (start >= end) {
            arr[i].first = start;
            arr[i].second = end;
        }
        else {
            arr[i].first = end;
            arr[i].second = start;
        }
    }

    cin >> D;
}

int main() {
    Input();
    Solution();

    return 0;
}