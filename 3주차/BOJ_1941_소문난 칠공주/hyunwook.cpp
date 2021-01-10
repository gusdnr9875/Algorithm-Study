#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n = 0;
string arr;
string arr_re;
int dp[5001][5001] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	cin >> arr;
	arr_re = arr;
	reverse(arr_re.begin(), arr_re.end());
	for (int i = 0; i < n; i++) {
		if (arr_re[0] == arr[i]) dp[0][i] = 1;
		else if(dp[0][i - 1] == 1)dp[0][i] = 1;

		if (arr_re[i] == arr[0]) dp[i][0] = 1;
		else if (dp[i - 1][0] == 1)dp[i][0] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (arr_re[i] == arr[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}*/

	cout << n - dp[n - 1][n - 1] << endl;


	return 0;
}
