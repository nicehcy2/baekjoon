#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N, B, C;
int A[1000001];

void Solution() {
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        sum += 1;
        A[i] -= B;
        if (A[i] > 0) {
            sum += ceil((double)A[i] / C);
        }
    }

    cout << sum << '\n';
}

void Input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin >> B >> C;
}

int main() {
    Input();
    Solution();

    return 0;
}