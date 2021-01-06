#include <iostream>
using namespace std;

int n = 0, m = 0, k = 0;
int a, b, c, d;
bool construction[201][201] = { 0, };
unsigned long long dp[101][101] = { 0, };
int y_ar[2] = { 0,-1 };
int x_ar[2] = { -1,0 };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c >> d;
		construction[b + d][a + c] = 1;
	}
	dp[0][0] = 1;

	for (int i = 1; i <= m; i++) {
		if (construction[2 * i - 1][0] == 1)
			break;
		dp[i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (construction[0][2 * i - 1] == 1)
			break;
		dp[0][i] = 1;
	}


	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (construction[2 * i - 1][2 * j] == 0)
				dp[i][j] += dp[i - 1][j];
			if (construction[2 * i][2 * j - 1] == 0)
				dp[i][j] += dp[i][j - 1];


		}
	}

	cout << dp[m][n] << endl;
	return 0;
}