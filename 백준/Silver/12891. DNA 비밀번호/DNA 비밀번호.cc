#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, M, ans;
int arr[200];
string str;

void Solution() {

    int cnt = M, A = 0, C = 0, G = 0, T = 0;

    for (int i = 0; i < M; i++) {

        if (str[i] == 'A') A++;
        else if (str[i] == 'C') C++;
        else if (str[i] == 'G') G++;
        else if (str[i] == 'T') T++;
    }

    if (A >= arr['A'] && C >= arr['C'] && G >= arr['G'] && T >= arr['T']) ans++;

    while (cnt < N) {

        char start = str[cnt - M];
        char end = str[cnt];

        if (start == 'A') A--;
        else if (start == 'C') C--;
        else if (start == 'G') G--;
        else if (start == 'T') T--;

        if (end == 'A') A++;
        else if (end == 'C') C++;
        else if (end == 'G') G++;
        else if (end == 'T') T++;

        if (A >= arr['A'] && C >= arr['C'] && G >= arr['G'] && T >= arr['T']) ans++;

        cnt++;
    }

    cout << ans << '\n';
}

void Input() {

    cin >> N >> M;
    cin >> str;
    
    cin >> arr['A'];
    cin >> arr['C'];
    cin >> arr['G'];
    cin >> arr['T'];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();

    return 0;
}