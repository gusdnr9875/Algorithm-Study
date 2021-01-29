#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int arr[102][102] = { 0, };
int n = 0, m = 0;
int result_time = 0, result = 0;
bool visited[102][102] = { 0, };

int y_ar[4] = { 0,0,1,-1 };
int x_ar[4] = { 1,-1,0,0 };


void bfs() {
	visited[1][1] = 1;
	queue <pair<int, int>> que;
	que.push(make_pair(1, 1));

	while (!que.empty()) {
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + y_ar[i];
			int nx = cx + x_ar[i];
			if (visited[ny][nx] == 0 && arr[ny][nx] == 0) {
				if (ny >= 1 && ny <= n&&nx >= 1 && nx <= m) {
					visited[ny][nx] = 1;
					que.push(make_pair(ny, nx));
				}
			}

		}

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	while (1) {
		//1. 검사
		int temp = 0;
		//4. 치즈개수 세기
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (arr[i][j] == 1)
					temp++;
		if (temp != 0)
			result = temp;
		bool chk = false;
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (arr[i][j] == 1)
					chk = true;
		if (chk == false)
			break;

		result_time++;


		//2. 외부공기 표시하기
		memset(visited, 0, sizeof(visited));
		bfs();
		//3. 외부공기에 닿아있으면 제거
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] == 1) {
					if (visited[i - 1][j] == 1 || visited[i][j - 1] == 1 || visited[i + 1][j] == 1 || visited[i][j + 1] == 1)
						arr[i][j] = 0;
				}

			}
		
	}


	cout << result_time << endl;
	cout << result << endl;
	return 0;
}