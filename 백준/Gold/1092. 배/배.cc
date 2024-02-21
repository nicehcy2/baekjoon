#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> crane, box;

void Solution() {
    sort(crane.begin(), crane.end(), greater<>());
    sort(box.begin(), box.end(), greater<>());

    int time = 0;

    if (crane[0] < box[0]) {
        cout << "-1\n";
        return;
    }

    while (!box.empty()) {

        for (int i = 0; i < crane.size(); i++) {

            for (int j = 0; j < box.size(); j++) {
                if (crane[i] >= box[j]) {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }

        time++;
    }

    cout << time << '\n';
}

void Input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        crane.push_back(num);
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        box.push_back(num);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Input();
    Solution();

    return 0;
}