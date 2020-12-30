#include <iostream>
#include <cstring>
using namespace std;

int dp[1002];
int dp_reverse[1002];
int n = 0;
int arr[1001] = { 0, };
int result = 1;

void solve_forward() {

	for (int i = 2; i <= n; i++) {

		for (int j = i - 1; j >= 1; j--) {
			if (arr[j] < arr[i])
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;

		}
	}
}
void solve_backward() {
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++) {
			if (arr[j] < arr[i])
				if (dp_reverse[i] < dp_reverse[j] + 1)
					dp_reverse[i] = dp_reverse[j] + 1;
		}

	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = 1;
		dp_reverse[i] = 1;
	}
	
	solve_forward();
	solve_backward();
	
	for (int i = 1; i <= n; i++) {

		if (dp[i] + dp_reverse[i] - 1 > result)
			result = dp[i] + dp_reverse[i] - 1;
		
		if (dp[i] > result)
			result = dp[i];
		else if (dp_reverse[i] > result)
			result = dp_reverse[i];
		
	}
	cout << result << endl;
	return 0;

}