#include <iostream>
#include <algorithm>

using namespace std;

int N, ans = 0;
long arr[2001];

void Solution() {

    sort(arr, arr + N);

    int i = 0, j = N - 1, target = 0;

    while (target != N) {

        if (i == target) i++;
        if (j == target) j--;

        if (i >= j) {
            target++;
            i = 0, j = N - 1;
            continue;
        }
        
        if (arr[i] + arr[j] == arr[target]) {
            
            target++;  ans++; 
            i = 0, j = N - 1;

            continue;
        }

        else if (arr[i] + arr[j] < arr[target]) i++;
        else if (arr[i] + arr[j] > arr[target]) j--;
    }

    cout << ans << '\n';
}

void Input() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
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