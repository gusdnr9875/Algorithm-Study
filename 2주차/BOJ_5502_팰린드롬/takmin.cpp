//문제: 팰린드롬(골드 3)
//알고리즘 dp(LCS)
//푼날짜: 2021-01-07

//0. 문자열, 뒤짚은문자열 준비
//1. LCS로 최장공통수열길이를 구한다음
//2. 문자열의 전체길이에서 빼준다
//삽입해야할 최소숫자개수= 전체길이-최장공통수열길이

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[5001][5001];

int main() {
	int n;
	cin >> n;

	string str;
	cin >> str;
	string str_rv = str;
	reverse(str_rv.begin(), str_rv.end());
	
	
	//LCS
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (str[i-1] == str_rv[j-1]) dp[i][j] =dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	cout << n-dp[n][n];


	

}
