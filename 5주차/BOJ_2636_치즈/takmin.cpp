//문제: 치즈(골드5)
//알고리즘: BFS
//푼날짜: 2021-01-25


#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
int map[101][101];
int ret, time;
bool visited[101][101];
int dir[4][2] = {
	{-1,0},{0,1},{0,-1},{1,0}
};

bool isInside(int a, int b) {
	return (a >= 0 && a < n) && (b >= 0 && b < m);
}
void BFS() {
	while (true) {
		int cheese = 0;
		//치즈 개수세기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) cheese++;
			}
		}

		if (cheese == 0) break;
		ret = cheese;
		time++;



		//외곽 치즈없애기
		memset(visited, false, sizeof(visited));
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (!isInside(nx, ny)) continue;
				if (!visited[nx][ny]) {
						visited[nx][ny] = true;
						if (map[nx][ny] == 0) q.push(make_pair(nx, ny));
						else if (map[nx][ny] == 1) map[nx][ny] = 0;
				}
				
				
			}
		}



	}
}
int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	BFS();
	cout << time << endl << ret;
}