//문제: 욕심쟁이판다
//알고리즘: dp
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int map[501][501];
//bool visited[501][501];
//int dp[501][501];
//int n;
//int ans,maxValue;
//int dir[4][2] = {
//	{-1,0},{0,1},{1,0},{0,-1} //북동남서
//};
//
//bool isInside(int a, int b) {
//	return (a >= 0 && a < n) && (b >= 0 && b < n);
//}
//
//int DFS(int x, int y) {
//
//	//dp에값이 있다면
//	if (dp[x][y]) return dp[x][y];
//	//없다면
//	dp[x][y] = 1;
//
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dir[i][0]; int ny = y + dir[i][1];
//		if(!isInside(nx, ny)) continue;
//		if (map[x][y] < map[nx][ny]) {
//			dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
//		}
//	}
//	return dp[x][y];
//}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			
//			ans = max(ans, DFS(i, j));
//			
//		}
//	}
//	cout << ans;
//}



//알고리즘: dfs
//완전탐색+ 백트래킹
//시간복잡도: O(V!) 
//시간초과

//#include<iostream>
//#include<algorithm>
//using namespace std;
//int map[501][501];
//bool visited[501][501];
//int n;
//int ans, maxValue;
//int dir[4][2] = {
//	{-1,0},{0,1},{1,0},{0,-1} //북동남서
//};
//
//bool isInside(int a, int b) {
//	return (a >= 0 && a < n) && (b >= 0 && b < n);
//}
//
//int DFS(int x, int y, int day) {
//  visited[x][y] = true;
//	if (maxValue < day) {
//		maxValue = day;
//	}
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dir[i][0];
//		int ny = y + dir[i][1];
//		if (!isInside(nx, ny)) continue;
//
//		//전에먹었던곳보다 더많다면
//		if (map[x][y] < map[nx][ny] && !visited[nx][ny]) {
//			DFS(nx, ny, day + 1);
//		}
//     visited[x][y] = false;
//	}
//	return maxValue;
//}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			ans = DFS(i, j, 1);
//		}
//	}
//	cout << ans;
//}