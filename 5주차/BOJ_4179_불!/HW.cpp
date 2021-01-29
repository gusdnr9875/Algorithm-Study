#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int r, c, result = 0;
char arr[1002][1002] = { 0, };
int visited[1002][1002] = { 0, };
int y_ar[4] = { 1,-1,0,0 };
int x_ar[4] = { 0,0,1,-1 };
queue <pair<int, int>> vec; //fire

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> r >> c;
	int sy, sx; // (시작점)
	for (int i = 1; i <= r; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= c; j++) {
			arr[i][j] = temp[j - 1];
			if (arr[i][j] == 'J')
				arr[i][j] = '.',sy = i, sx = j;
			if (arr[i][j] == 'F')
				vec.push(make_pair(i, j));
		}
	}


	if (sy == 1 || sy == r || sx == 1 || sx == c) { //초기에 끝나는 경우
		result = 1;
		cout << result << endl;
		return 0;
	}

	queue <pair<int, int>> que;
	que.push(make_pair(sy, sx));
	visited[sy][sx] = 1;
	while (!que.empty()) {
		if (result != 0)
			break;

		//1. 불의 이동 
		int len = vec.size();
		while (len--) {
			int cy = vec.front().first;
			int cx = vec.front().second;
			vec.pop();
			for (int j = 0; j < 4; j++) {
				int ny = cy + y_ar[j];
				int nx = cx + x_ar[j];
				if (ny >= 1 && ny <= r && nx >= 1 && nx <= c)
					if (arr[ny][nx] == '.') {
						arr[ny][nx] = 'F';
						vec.push(make_pair(ny, nx));
					}
			}
		}

		len = que.size();

		//2. 지훈이의 이동
		while(len--) {
			int cy = que.front().first;
			int cx = que.front().second;
			que.pop();

			for (int j = 0; j < 4; j++) {
				int ny = cy + y_ar[j];
				int nx = cx + x_ar[j];
				if (arr[ny][nx] == '#' || arr[ny][nx] == 'F')
					continue;
				if (ny == 1 || ny == r || nx == 1 || nx == c) {
					result = visited[cy][cx] + 1;
					break;
				}
				else if(visited[ny][nx] == 0){
					que.push(make_pair(ny, nx));
					visited[ny][nx] = visited[cy][cx] + 1;
				}
			}
			if (result != 0)
				break;
		}	
	}
	if (result != 0)
		cout << result << endl;
	else
		cout << "IMPOSSIBLE" << endl;
	return 0;
}

/*
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int h = 0, w = 0;
int visited[1000][1000] = { 0 };
char arr[1000][1000];

queue <int> fire[2];
queue <int> people[2];

int x_ar[4] = { -1,1,0,0 };
int y_ar[4] = { 0,0,1,-1 };

void bfs() {
	//초기값 입력
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (arr[i][j] == 'F')
				fire[0].push(i), fire[1].push(j);
			else if (arr[i][j] == 'J')
				people[0].push(i), people[1].push(j), visited[i][j] = 1;



	while (!people[0].empty()) { //상근이가 이동할 경로가 없을 때 까지 반복
								 //1. 불먼저 전파
		int fire_cnt = fire[0].size();
		while (fire_cnt--) {
			int yy = fire[0].front();
			int xx = fire[1].front();
			fire[0].pop(), fire[1].pop();
			for (int i = 0; i < 4; i++) {
				int y = yy + y_ar[i];
				int x = xx + x_ar[i];
				if (y >= 0 && y < h && x >= 0 && x < w)
					if (arr[y][x] == '.' || arr[y][x] == 'J') {
						arr[y][x] = 'F';
						fire[0].push(y), fire[1].push(x);
					}
			}
		}
		//2. 상근좌 이동
		int people_cnt = people[0].size();
		while (people_cnt--) {
			int yy = people[0].front();
			int xx = people[1].front();
			people[0].pop(), people[1].pop();
			for (int i = 0; i < 4; i++) {
				int y = yy + y_ar[i];
				int x = xx + x_ar[i];
				if (y >= 0 && y < h && x >= 0 && x < w)
					if (arr[y][x] == '.' && visited[y][x] == 0) {
						visited[y][x] = visited[yy][xx] + 1;
						people[0].push(y), people[1].push(x);
					}
			}
		}
	}
	//3. 모서리의 visited값들을 확인하고 결과값을 도출
	int result = 1000000;
	bool alive = false;
	for (int i = 0; i < h; i++) {
		if (visited[i][0] != 0) {
			alive = true;
			if (visited[i][0] < result)
				result = visited[i][0];
		}
		if (visited[i][w - 1] != 0) {
			alive = true;
			if (visited[i][w - 1] < result)
				result = visited[i][w - 1];
		}
	}
	for (int j = 0; j < w; j++) {
		if (visited[0][j] != 0) {
			alive = true;
			if (visited[0][j] < result)
				result = visited[0][j];
		}
		if (visited[h - 1][j] != 0) {
			alive = true;
			if (visited[h - 1][j] < result)
				result = visited[h - 1][j];
		}
	}

	if (alive)
		cout << result << '\n';
	else
		cout << "IMPOSSIBLE" << '\n';
}

int main() {

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		string val;
		cin >> val;
		for (int j = 0; j < val.size(); j++)
			arr[i][j] = val[j];
	}
	bfs();

}
*/