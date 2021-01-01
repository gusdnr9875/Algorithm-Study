////문제: 행렬곱셈순서
////알고리즘: dp
////푼날짜: 2021-01-01
//
////<<접근법>>
////일반 재귀를 통한 완전탐색으로할시 시간복잡도=O(N!)임
////행렬의개수 
////3->2가지
////4->3x2가지
////5->4x3x2가지
////...
////n->(n-1)!
//
////->따라서 dp사용해야함
//
//
//
//#include<iostream>
//#include<algorithm>
//#include<limits.h>
//using namespace std;
//int R[500], C[500]; //행, 열
//int dp[500][500]; //dp[i][j]배열: i번째, j번째 행렬 까지 곱의 최소 연산 횟수
//
//int func(int x, int y) {
//	if (dp[x][y]) return dp[x][y];
//	if (y - x <= 0) return 0;
//	int mn = INT_MAX;
//	for (int k = x; k < y; k++) {
//		//이등분 된것을 각각
//		//재귀를 통해(x번째 ~ k번째)까지의 곱 최소연산 횟수 탐색 + 
//		//재귀를 통해 (k+1번째 ~ y번째)까지의 곱 최소연산 횟수 탐색
//		//+현재 이등분되었을때 연산횟수
//		mn = min(mn, func(x, k) + func(k + 1, y) + R[x] * C[k] * C[y]);
//	}
//	return dp[x][y]=mn;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> R[i] >> C[i];
//	cout << func(0, n - 1);
//}
//
