#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n = 0;
int arr[501][501] = { 0, };
int dp[501][501];
int y_ar[4] = { 0,0,1,-1 };
int x_ar[4] = { 1,-1,0,0 };
int result = 0;

int solved(int y, int x) {
	int &ret = dp[y][x];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + y_ar[i];
		int nx = x + x_ar[i];
		if (ny >= 1 && ny <= n&&nx >= 1 && nx <= n)
			if (arr[y][x] < arr[ny][nx]) {
				ret = max(ret, solved(ny, nx) + 1);
		}

	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
				result = max(result, solved(i, j));
			
		}

	cout << result + 1 << endl;
	return 0;
}