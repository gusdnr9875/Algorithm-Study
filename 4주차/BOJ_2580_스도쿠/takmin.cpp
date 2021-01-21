//문제: 스도쿠 (골드4)
//알고리즘: 백트래킹
//푼날짜: 2021-01-18

//각 열, 행 그리고 3*3칸 내에 숫자 존재여부를 파악하기위해
//bool형 배열 row, col ,square 선언
#include<iostream>
using namespace std;

const int MAX = 9;
int map[MAX][MAX];
bool row[MAX][MAX + 1];
bool col[MAX][MAX + 1];
bool square[MAX][MAX + 1]; //3*3 박스 IDX, 1~9

int setSquareID(int x, int y){
	return (x / 3)*3 + y / 3;
}

void DFS(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	int x = cnt / 9;
	int y = cnt % 9;
	if (map[x][y])//칸이 채워져있으면
		DFS(cnt + 1);
	else { //채워져있지않다면
		for (int k = 1; k <= MAX; k++) {
			//스도쿠 규칙에 적합하면 채우고본다
			if (!col[y][k] && !row[x][k] && !square[setSquareID(x,y)][k]) {
				map[x][y] = k;
				col[y][k] = true;
				row[x][k] = true;
				square[setSquareID(x,y)][k] = true;

				DFS(cnt + 1);
				map[x][y] = 0;
				col[y][k] = false;
				row[x][k] = false;
				square[setSquareID(x,y)][k] = false;

			}
		}
	}
	
}
int main() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> map[i][j];

			//행따로 열따로 ,square(3*3)따로 있는 숫자 체크
			if (map[i][j]) {
				row[i][map[i][j]] = true;
				col[j][map[i][j]] = true;
				square[setSquareID(i,j)][map[i][j]] = true;
			}
		}
	}
	DFS(0); //스도쿠는 81칸임
}
