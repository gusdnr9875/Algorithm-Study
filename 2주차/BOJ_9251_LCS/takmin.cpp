//문제: LCS(골드 5)
//알고리즘: LCS
//푼날짜: 2021-01-04
//참고: https://sihyungyou.github.io/baekjoon-9251/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int dp[1001][1001];
int main() {
	char s1[1001];
	char s2[1001];

	cin >> s1>>s2;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int ans = 0;

	for(int i=1; i<=len1; i++)
		for (int j = 1; j <= len2; j++) {
			if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	cout << dp[len1][len2];


}