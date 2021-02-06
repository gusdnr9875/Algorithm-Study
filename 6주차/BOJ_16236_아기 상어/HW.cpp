#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n = 0, result = 0;
int arr[20][20] = { 0, };
int visited[20][20] = { 0, };
int y_ar[4] = { 0,0,1,-1 };
int x_ar[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	int sy, sx;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9)
				arr[i][j] = 0, sy = i, sx = j;
		}

	int shark = 2;
	int exp = 0;
	while (1) {
		memset(visited, 0, sizeof(visited));
		
		//1. 이동거리 측정

		queue <pair<int, int >> que;
		que.push(make_pair(sy, sx));
		visited[sy][sx] = 1;
		while (!que.empty()) {
			int cy = que.front().first;
			int cx = que.front().second;
			que.pop();

			for (int i = 0; i < 4; i++) {
				int ny = cy + y_ar[i];
				int nx = cx + x_ar[i];

				if (ny >= 0 && ny < n && nx >= 0 && nx < n && visited[ny][nx] == 0) {
					if (arr[ny][nx] <= shark ) {
						visited[ny][nx] = visited[cy][cx] + 1;
						que.push(make_pair(ny, nx));
					}
				}
			}
		}

		//2. 물고기 취식
		
		bool chk = false;
		int mmy=-1, mmx=-1;
		int mined = (int)2e9;
		for(int i=0;i<n; i++)
			for (int j = 0; j < n; j++)
				if (visited[i][j] != 0 && visited[i][j] < mined && arr[i][j] != 0 && shark > arr[i][j]) {
					chk = true;
					mined = visited[i][j];
					mmy = i, mmx = j;
				}

		
		exp++;
		if (exp == shark)
			shark++, exp = 0;
		arr[mmy][mmx] = 0;
		if (chk == false)
			break;
		result += visited[mmy][mmx] - 1;
		sy = mmy, sx = mmx;
		
	}
	cout << result << endl;
	return 0;
}