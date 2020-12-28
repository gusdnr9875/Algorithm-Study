//알고리즘: dp
//최대 경로의수는 10억이하이므로 dp로 풀어야한다.
//완전탐색으로 할시,  연산횟수의 1억당 1초가 걸리니 10초가걸림
#include<iostream>
using namespace std;

int m, n;
int map[501][501];
int ans;
int dp[501][501]; //(x,y) 지점일 때, 존재하는 경로의 개수

int dir[4][2] = {
	{-1,0}, {0,1}, {1,0},{0,-1} //북동남서
};
bool isInside(int a, int b) {
	return (a >= 0 && a < m) && (b >= 0 && b < n);
}
int DFS(int x, int y) {
	if (x == m - 1 && y == n - 1) {
		return 1;
	}
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int d = 0; d < 4; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (!isInside(nx, ny)) continue;
		if (map[x][y] > map[nx][ny]) {
			dp[x][y] += DFS(nx, ny);

		}
	}
	return dp[x][y];
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}

	ans = DFS(0, 0);
	cout << ans;
}



//
////알고리즘: dfs완전탐색==>시간초과
//#include<iostream>
//using namespace std;
//
//int m, n;
//int map[501][501];
//int ans;
//int dp[501][501]; //(x,y) 지점일 때, 존재하는 경로의 개수
//bool visited[501][501];
//
//int dir[4][2] = {
//	{-1,0}, {0,1}, {1,0},{0,-1} //북동남서
//};
//bool isInside(int a, int b) {
//	return (a >= 0 && a < m) && (b >= 0 && b < n);
//}
//void DFS(int x, int y) {
//	if (x == m - 1 && y == n - 1) {
//		ans++;
//		return;
//	}
//	
//	for (int d = 0; d < 4; d++) {
//		int nx = x + dir[d][0];
//		int ny = y + dir[d][1];
//		if (!isInside(nx, ny) || visited[nx][ny])
//			continue;
//		if (map[x][y] > map[nx][ny]) {
//			visited[nx][ny] = true;
//			DFS(nx, ny);
//			visited[nx][ny] = false;
//		}
//	}
//}
//int main() {
//	cin >> m >> n;
//	for (int i = 0; i < m; i++) 
//		for (int j = 0; j < n; j++) 
//			cin >> map[i][j];
//	visited[0][0] = true;
//	DFS(0,0);
//	cout << ans;
//}