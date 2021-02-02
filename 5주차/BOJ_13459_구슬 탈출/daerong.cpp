//Solution
//- 어릴 때 하던 구멍으로 구슬빼는 게임에 빨강, 파랑 구슬의 룰이 추가되었다. Blue 구슬에 대한 예외처리가 관건
//- DFS를 사용해서 풀이했다.
//- 이론적 접근은 다음과 같다.
//- 1. 구슬은 턴당 한쪽 방향으로만 이동할 수 있다. 또한 두개의 구슬이 모두 벽을 만나기 전까지 이동한다.
//- 2. 구슬이 겹치는 경우, 이동거리가 큰 구슬을 한칸 전으로 되돌린다.
//- 3. 어떤 경우에서도 파란 구슬이 빠지는 경우는 제외한다.
//- 4. 시행 횟수가 10을 넘기는 경우 제외한다.
//- 5. 빨간구슬만 탈출 했을 경우, 1을 출력한다.
//- 6. 그 외의 경우 0을 출력한다.
//- Failed 1 : 같은 방식으로 풀이했으나 중간에 변수를 잘못 사용한듯하다.
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 선언한다.
//- 1.1. map[][] : 맵의 상태를 저장할 배열, 'R'과 'B'는 '.'으로 치환했다.
//- 1.2. RX, RY : 초기 Red 구슬의 위치를 저장할 변수
//- 1.3. BX, BY : 초기 Blue 구슬의 위치를 저장할 변수
//- 1.4. answer : 결과를 저장할 변수 default는 0
//- 2. move() 함수를 사용해 빠져나갈 수 있는 경우의 수를 DFS로 찾는다.
//- 2.1. 첫 시행은 RX, RY, BX, BY, 1을 사용한다.
//- 2.2. 4방향에 대해 각각 다음을 수행한다.
//- 2.2.1. Blue 돌을 이동시킨다.
//- 2.2.2. Blue 돌이 'O'를 만난 경우, 다음 반복을 수행한다.
//- 2.2.3. Blue 돌이 '#'을 만난 경우, 바로 직전 위치를 nBx, nBy라 한다.
//- 2.2.4. Red 돌을 이동시킨다.
//- 2.2.5. Red 돌이 'O'를 만난 경우, answer에 1을 저장하고 3.으로 이동한다.
//- 2.2.6. Red 돌이 '#'을 만난 경우, 바로 직전 위치를 nRx, nRy라 한다.
//- 2.3. Red 돌과 Blue 돌의 위치가 같은 경우, 다음을 수행한다.
//- 2.3.1. Red 돌의 이동거리와 Blue 돌의 이동거리를 비교한다.
//- 2.3.2. Red Dist가 큰 경우, Red 돌의 바로 직전 위치를 nRx, nRy라 한다.
//- 2.3.3. Blue Dist가 큰 경우, Blue 돌의 바로 직전 위치를 nBx, nBy라 한다.
//- 2.4. move() 함수에 nRx, nRy, nBx, nBy, turn + 1을 넣어 2.2.로 돌아간다.
//- 3. answer을 출력한다.

#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 10

int X, Y;
char map[N_MAX][N_MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int RX, RY;
int BX, BY;
int answer;

void init() {
	cin >> Y >> X;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'R') {
				RX = x;
				RY = y;
				map[y][x] = '.';
			}
			else if (map[y][x] == 'B') {
				BX = x;
				BY = y;
				map[y][x] = '.';
			}
		}
	}
}

void move(int Rx, int Ry, int Bx, int By, int turn) {
	if (answer == 1) return;
	if (turn > 10) return;

	for (int dir = 0; dir < 4; dir++) {
		int nBx = Bx;
		int nBy = By;
		bool is_fall = false;
		while (map[nBy][nBx] != '#') {
			nBx += dx[dir];
			nBy += dy[dir];
			if (map[nBy][nBx] == 'O') {
				is_fall = true;
				break;
			}
		}
		if (is_fall) continue;
		nBx -= dx[dir];
		nBy -= dy[dir];

		int nRx = Rx;
		int nRy = Ry;
		is_fall = false;
		while (map[nRy][nRx] != '#') {
			nRx += dx[dir];
			nRy += dy[dir];
			if (map[nRy][nRx] == 'O') {
				is_fall = true;
				break;
			}
		}
		if (is_fall) {
			answer = 1;
			return;
		}
		nRx -= dx[dir];
		nRy -= dy[dir];

		if (nRx == nBx && nRy == nBy) {
			int Rdiff = abs(nRx + nRy - Rx - Ry);
			int Bdiff = abs(nBx + nBy - Bx - By);
			if (Rdiff > Bdiff) {
				nRx -= dx[dir];
				nRy -= dy[dir];
			}
			else {
				nBx -= dx[dir];
				nBy -= dy[dir];
			}
		}

		move(nRx, nRy, nBx, nBy, turn + 1);
	}
}

void solution() {
	init();
	move(RX, RY, BX, BY, 1);
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}