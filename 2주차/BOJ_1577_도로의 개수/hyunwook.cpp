#include <iostream>
#include <cstring>
using namespace std;
/*
	dp라고 모르고 풀었음 더 어려웠을 문제
	처음에 bfs 관점으로 접근하는데 자꾸 예외케이스가 생김
	모든 경우를 탐색해주어야 한다고 인식하게 됨 -> UP-DOWN 방식으로 구현
*/
int m, n;
int arr[501][501] = { 0, };
int dp[501][501] = { 0, };

int y_ar[4] = {0, 0, -1, 1};
int x_ar[4] = { 1,-1,0,0 };

int solved(int y, int x) {
	if (y == 1 && x == 1)
		return 1;
	int &ret = dp[y][x];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + y_ar[i];
		int nx = x + x_ar[i];
		if (ny >= 1 && ny <= m && nx >= 1 && nx <= n) {
			if (arr[y][x] < arr[ny][nx]) {
				ret += solved(ny, nx);
			}
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> m >> n;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	memset(dp, -1, sizeof(dp));
	cout << solved(m,n) << endl;

	/*
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}
	*/
	return 0;
}