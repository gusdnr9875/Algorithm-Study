//문제: 가장 긴 바이토닉 부분수열(골드3)
//알고리즘: LIS DP
#include<iostream> 
#include<algorithm>
using namespace std;

int n;
int left_dp[1001];
int right_dp[1001];
int ans;
int arr[1001];
void LIS() {
	for (int i = 0; i < n; i++) {
		left_dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				left_dp[i] = max(left_dp[i], left_dp[j] + 1);
		}
	}
}

void reverseLIS() {
	for (int i = n - 1; i >= 0; i--) {
		right_dp[i] = 1;
		for (int j = n -1; j > i; j--) {
			if (arr[i] > arr[j])
				right_dp[i] = max(right_dp[i], right_dp[j] + 1);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	LIS();
	reverseLIS();
	for (int i = 0; i < n; i++) {
		if (ans < left_dp[i] + right_dp[i])
			ans = left_dp[i] + right_dp[i];
	}
	cout << ans - 1;

}