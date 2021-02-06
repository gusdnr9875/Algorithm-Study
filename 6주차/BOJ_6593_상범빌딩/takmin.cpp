//문제: 상범 빌딩 (골드 5)
//알고리즘: BFS
//푼 날짜: 2021-02-04

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct SangBum
{
	int h, x, y;
};

char map[31][31][31];
int check[31][31][31];

//상하북동남서
int dir[6][3] = { {-1,0,0}, {1,0,0}, {0,-1,0}, {0,0,1}, {0,1,0},{0,0,-1} };
int L, R, C;
SangBum S;

bool isInside(int a, int b, int c) {
	return (a >= 0 && a < L) && (b >= 0 && b < R) && (c >= 0 && c < C);
}
int BFS() {
	queue<SangBum> q;
	q.push(S);
	

	while (!q.empty()) {
		int h = q.front().h;
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

	

		if (map[h][x][y] == 'E') {
			return check[h][x][y];
		}

		for (int i = 0; i < 6; i++) {
			int nh = h + dir[i][0];
			int nx = x + dir[i][1];
			int ny = y + dir[i][2];

			if (!isInside(nh, nx, ny)) continue;
			
			if (map[nh][nx][ny] != '#' && !check[nh][nx][ny] ) {
				check[nh][nx][ny] = check[h][x][y]+1;
				q.push({ nh,nx,ny });


			}
		}
	}
	return -1;

}
int main() {

	while (1) {
		
		memset(map,' ', sizeof(map));
		memset(check, 0, sizeof(check));
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S')
						S.h = i, S.x = j, S.y = k;
				}
			}
		}

		int ret=BFS();
		if (ret != -1) {
			cout << "Escaped in "<<ret<<" minute(s)." << endl;;
		}
		else cout << "Trapped!" << endl;





	}
}