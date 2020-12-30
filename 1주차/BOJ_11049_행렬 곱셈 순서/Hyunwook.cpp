#include <iostream>
#include <cstring>
using namespace std;

int n = 0;
int arr[501][2];
int dp[501][501];

int  sol(int st, int ed) {
	if (st == ed) return dp[st][ed] = 0;

	int &ret = dp[st][ed];

	if (ret != -1)
		return ret;

	for (int i = st; i < ed; i++) {
		int temp = sol(st, i) + sol(i + 1, ed) + arr[st][0] * arr[i][1] * arr[ed][1];
		if (ret > temp || ret == -1) ret = temp;
	}

	return ret;
}


int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1];

	memset(dp, -1, sizeof(dp));
	sol(1, n);

	cout << dp[1][n] << endl;
	return 0;
}