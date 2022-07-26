#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int start, int mid, int end, int n) //출발지, 경유지, 목적지, 원판 개수
{
	if (n == 1) //재귀 함수의 탈출 조건(마지막에 남은 원판 개수가 1일 때 목적지로 마지막 기둥을 옮긴다)
	{
		cout << start << " " << end << '\n';
	}
	else {
		hanoi(start, end, mid, n - 1); //기둥1의 n-1개의 원판을 기둥2로 옮기는 과정
		cout << start << " " << end << '\n'; //기둥1의 1개의 원판을 기둥3으로 옮기는 출력
		hanoi(mid, start, end, n - 1); //기둥2의 n-1 원판을 기둥3으로 옮기는 과정
	}
}

int main() {
	int n;

	cin >> n;

	cout << (int)pow(2, 3) - 1 << '\n';

	hanoi(1, 2, 3, n);

	return 0;
}
