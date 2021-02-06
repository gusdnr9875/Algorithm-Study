#include <iostream>
#include <queue>
using namespace std;

typedef struct MyStruct
{
	int l;
	int y;
	int x;
}position;

int l, r, c;
char arr[31][31][31]; // l r c 1base

int y_ar[6] = { 0,0,1,-1,0,0 };
int x_ar[6] = { 1,-1,0,0,0,0 };
int l_ar[6] = { 0,0,0,0,1,-1 };




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;

		int visited[31][31][31] = { 0, };
		queue <position> que;
		int el, ey, ex;

		for (int k = 1; k <= l; k++)
			for (int i = 1; i <= r; i++)
				for (int j = 1; j <= c; j++) {
					cin >> arr[k][i][j];
					if (arr[k][i][j] == 'S') {
						que.push({ k,i,j });
						visited[k][i][j] = 1;
					}
					if (arr[k][i][j] == 'E') {
						el = k, ey = i, ex = j;
					}
				}


		while (!que.empty()) {
			int cl = que.front().l;
			int cy = que.front().y;
			int cx = que.front().x;
			que.pop();

			for (int i = 0; i < 6; i++) {
				int nl = cl + l_ar[i];
				int ny = cy + y_ar[i];
				int nx = cx + x_ar[i];

				if (nl >= 1 && nl <= l && ny >= 1 && ny <= r && nx >= 1 && nx <= c) {
					if (visited[nl][ny][nx] == 0 && arr[nl][ny][nx] != '#') {
						visited[nl][ny][nx] = visited[cl][cy][cx] + 1;
						que.push({ nl,ny,nx });
					}
					

				}


			}


		}
		if (visited[el][ey][ex] == 0) {
			cout << "Trapped!" << endl;
		}
		else {
			cout << "Escaped in "<<visited[el][ey][ex] - 1 <<" minute(s)."<< endl;
		}
		

	}

}


/*
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int l = 0, r = 0, c = 0;
int result;
char arr[31][31][31];
int visited[31][31][31];
int y_ar[6] = { 0, 0, 1, -1, 0, 0 };
int x_ar[6] = { 0, 0, 0, 0, 1, -1 };
int z_ar[6] = { 1, -1, 0, 0, 0, 0 };



void bfs(int sz,int sy,int sx) {
	
	queue <int> que[3];
	que[0].push(sz);
	que[1].push(sy);
	que[2].push(sx);
	visited[sz][sy][sx] = 1;
	while (que[0].empty() != 1) {


		int zz = que[0].front();
		int yy = que[1].front();
		int xx = que[2].front();
		que[0].pop(), que[1].pop(), que[2].pop();
		
		for (int i = 0; i < 6; i++) {
			int z = zz + z_ar[i];
			int y = yy + y_ar[i];
			int x = xx + x_ar[i];

			if (z >= 0 && z < l && y >= 0 && y < r && x >= 0 && x < c)
				if (visited[z][y][x] == 0 && arr[z][y][x] != '#') {
					visited[z][y][x] = visited[zz][yy][xx] + 1;
					que[0].push(z);
					que[1].push(y);
					que[2].push(x);
				}
		}
	}

	for (int i = 0; i < l; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++)
				if (arr[i][j][k] == 'E')
					result = visited[i][j][k];



}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;

		memset(visited, 0, sizeof(visited));

		result = (int)2e9;
		int sz, sy, sx;

		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++) {
				cin >> arr[i][j];

				for (int k = 0; k < c; k++) {
					if (arr[i][j][k] == 'S')
						sz = i, sy = j, sx = k;
				}
			}
	
		bfs(sz, sy, sx);
		

		if (result == 0)
			cout << "Trapped!" <<"\n";
		else
			cout << "Escaped in " << result  - 1<< " minute(s)." <<"\n";
	}

	return 0;
}
*/