//문제: 구슬탈출 (골드 3)
//알고리즘: bfs
//푼날짜: 2021-01-28

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct info {
	int rx, ry, bx, by, cnt;
};
int n, m;
char map[11][11];
int r_x, r_y;
int b_x, b_y;
bool visited[11][11][11][11];
int dir[4][2] = { {-1,0}, {0,1},{1,0},{0,-1} }; //북동남서
void move(int& x, int& y, int dx, int dy, int &c) {
	while (map[x+dx][y+dy] != '#' && map[x][y] != 'o') {
		x += dx; y += dy;
		c+=1;
		
	}
}
void bfs() {
	visited[r_x][r_y][b_x][b_y] = true;
	queue<info> q;
	q.push({ r_x,r_y,b_x,b_y,0 });

	while (!q.empty()) {
		
		int rx = q.front().rx; int ry = q.front().ry;
		int bx = q.front().bx; int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();
		
		if (cnt >= 10) break;
		for (int d = 0; d < 4; d++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0;
			move(nrx, nry, dir[d][0], dir[d][1], rc); //빨간공 이동
			move(nbx, nby, dir[d][0],dir[d][1], bc); //파란공 이동

			//파란공이빠지면안됨
			if (map[nbx][nby] == 'o') continue;
			//빨간공이빠지면 성공
			else if (map[nrx][nry]  == 'o') {
				cout << "1"<<endl; return;
			
			}

			

			//공이겹친다면
			if (nrx == nbx && nry == nby) {
				if (rc > bc) {
					nrx -= dir[d][0];
					nry -= dir[d][1];
				}
				else {
					nbx -= dir[d][0];
					nby -= dir[d][1];
				}
			}

			if (visited[nrx][nry][nbx][nby]) continue;
			visited[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby,cnt + 1 });
		}
	}
	cout << "0" << endl;
	

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'b') { b_x = i; b_y = j; }
			else if (map[i][j] == 'r') { r_x = i; r_y = j; }

		}

	bfs();



}