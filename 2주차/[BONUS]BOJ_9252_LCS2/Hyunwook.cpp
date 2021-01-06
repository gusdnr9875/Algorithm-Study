#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
string a, b;
string result;
int dp[1001][1001] = { 0, };

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string temp1, temp2;
	cin >> temp1;
	cin >> temp2;
	
	a = ' ' + temp1;
	b = ' ' + temp2;
	
	
	for (int i = 1; i < b.size(); i++) {
		for (int j = 1; j < a.size(); j++) {
			if (a[j] == b[i]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	
	
	int col = a.size() - 1;
	int row = b.size() - 1;

	while (dp[row][col]) {

		if (dp[row][col] == dp[row - 1][col]) {
			row--;
		}
		else if (dp[row][col] == dp[row][col - 1]) {
			col--;
		}
		else {
			result += a[col];
			row--, col--;
		}

	}

	cout << dp[b.size() - 1][a.size() - 1] << endl;
	if (result.size() > 0) {
		reverse(result.begin(), result.end());
		cout << result << endl;
	}
	return 0;
}