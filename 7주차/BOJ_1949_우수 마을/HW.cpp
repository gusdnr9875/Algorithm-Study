#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0;
bool visited[10001] = { 0, };
int cost[10001] = { 0, };
vector <int> arr[10001];
int dp[10001][2];
void dfs(int current) {
	if (visited[current])
		return;
	
	visited[current] = 1;
	int& normal = dp[current][0];
	int& greated = dp[current][1];
	normal = 0;
	greated = cost[current];
	for (int i = 0; i < arr[current].size(); i++) {
		int num = arr[current][i];
		if (visited[num] == 1) continue;

		dfs(num);
		normal += max(dp[num][1], dp[num][0]);
		greated += dp[num][0];
		
	}
}



int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		arr[t1].push_back(t2);
		arr[t2].push_back(t1);
	}

	dfs(1);

	cout << max(dp[1][0],dp[1][1]) << endl;

	return 0;
}