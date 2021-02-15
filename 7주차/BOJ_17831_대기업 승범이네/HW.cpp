#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef struct a {
	int sy;
	int sx;
	int dy;
	int dx;
	bool alive;
}m_arr;
int arr[21][21] = { 0, };
int visited[21][21] = { 0, };
int n = 0, m = 0, k = 0;
int driver_y, driver_x;
vector <m_arr> vec;

int y_ar[4] = { 1,-1,0,0 };
int x_ar[4] = { 0,0,1,-1 };
void bfs(int y, int x) {

	queue <pair<int, int>> que;
	que.push(make_pair(y, x));
	visited[y][x] = 1;

	while (!que.empty()) {

		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + y_ar[i];
			int nx = cx + x_ar[i];
			if (visited[ny][nx] == 0 && arr[ny][nx] != 1 && 1 <= ny && ny <= n && 1 <= nx && nx <= n) {
				que.push(make_pair(ny, nx));
				visited[ny][nx] = visited[cy][cx] + 1;
			}

		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	cin >> driver_y >> driver_x;

	int temp1, temp2, temp3, temp4;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2 >> temp3 >> temp4;
		vec.push_back({ temp1,temp2,temp3,temp4,true });
	}

	for (int countt = 0; countt < m; countt++) {

		//1.가장 가까운 yx
		memset(visited, 0, sizeof(visited));
		bfs(driver_y, driver_x);

		int mini_num = -1, mini_distance = 1000000000;
		int mini_y = -1, mini_x = -1;
		bool flag = false;
		for (int i = 0; i < m; i++) {
			if (vec[i].alive == true) {
				int y = vec[i].sy;
				int x = vec[i].sx;
				if (visited[y][x] == 0) continue;

				if (mini_distance > visited[y][x]) {
					mini_distance = visited[y][x];
					mini_num = i;
					mini_y = y;
					mini_x = x;
					flag = true;
				}
				else if (mini_distance == visited[y][x]) {
					//cout << 12312312312 << endl;
					if (mini_y > y) {
						mini_distance = visited[y][x];
						mini_num = i;
						mini_y = y;
						mini_x = x;
					}
					else if (mini_y == y && mini_x > x) {
						mini_distance = visited[y][x];
						mini_num = i;
						mini_y = y;
						mini_x = x;
					}


				}
			}
		}
		if (flag == false) {
			cout << -1 << endl;
			return 0;
		}
		/*
		cout << endl;
		for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
		cout << visited[i][j] << ' ';
		cout << endl;
		}*/
		vec[mini_num].alive = false;
		driver_y = vec[mini_num].sy;
		driver_x = vec[mini_num].sx;
		k -= (mini_distance - 1);
		//cout << "k "<<k<<"mini_distance - 1"<< mini_distance - 1 <<endl;
		if (k <= 0) {
			cout << -1 << endl;
			return 0;
		}

		memset(visited, 0, sizeof(visited));
		bfs(driver_y, driver_x);
		if (visited[vec[mini_num].dy][vec[mini_num].dx] == 0) {
			cout << -1 << endl;
			return 0;
		}
		k -= (visited[vec[mini_num].dy][vec[mini_num].dx] - 1);
		if (k < 0) {
			cout << -1 << endl;
			return 0;
		}
		k += ((visited[vec[mini_num].dy][vec[mini_num].dx] - 1) * 2);
		driver_y = vec[mini_num].dy;
		driver_x = vec[mini_num].dx;
		//cout << driver_y << ' ' << driver_x << endl;
	}

	cout << k << endl;
	return 0;
}