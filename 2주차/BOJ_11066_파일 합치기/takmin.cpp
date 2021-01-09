//문제: 파일 합치기(골드 3)
//알고리즘: DP
//푼날짜: 2021-01-07
//백준 11049(행렬곱셈순서)랑 비슷한문제

//파일을합칠때, 인접한 파일끼리만 합칠수있음


#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int dp[501][501]; //i에서 j까지 파일을 합칠때, 최소 비용
int f[501];
int t, k;


int solve(int i, int j) {
	//종료조건
	if (i == j) return 0;

	if (dp[i][j]) return dp[i][j];

	int sum=0;

	for (int k = i; k <= j; k++)
		sum += f[k];

	int mn = INT_MAX;
	//이등분 하고 각각 재귀함수에서
	//인덱스~인덱스 사이에서 최소 비용을 구하여 반환한다.
	for (int k = i; k <= j - 1; k++) {
		 mn = min(mn, solve(i, k) + solve(k + 1, j) + sum);
	}
	//가장 작은값 dp값 갱신
	return dp[i][j]=mn;

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(dp, 0, sizeof(dp));
		cin >> k;
		for (int j = 1; j <= k; j++) cin >> f[j];
		int ret=solve(1, k);
		cout << ret << "\n";
	}
}


