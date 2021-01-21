문제: 비숍(골드 2)
알고리즘: 백트래킹
푼날짜: 2021-01-19


풀이코드1: 체스판을 흑색백색으로 분리함 시간복잡도: O(2^(n/2*n/2) )
풀이코드2(실패): 체스판을 흑색백색으로 분리하지않음: O(2^(n*n)) ==>시간초과

<<해결법>>
체스판은 흑색과 백색으로 나누어져있음
흑색과 백색으로 나누어서 문제를 접근한다.
흑색과 백색은 서로 영향을 주지않는다
(백색은 백색끼리, 흑색은 흑색끼리 영향을끼침)


//풀이코드 1: 체스판을 흑색백색으로 분리함 : O(2^(n/2*n/2))
//DFS를 2번하기때문에 2^이고, 1번할때마다 전체의 1/2를탐색하기때문에 (n/2)*(n/2)
#include<iostream>
#include<algorithm>
using namespace std;

int n;
bool l[21]; //왼쪽 대각선 '/'
bool r[21]; //오른쪽 대각선 '\'
int arr[11][11];
int ans[2];
void DFS(int row, int col,int cnt, int color) {
	if (col >= n) {
		row = row + 1;
		if (col % 2 == 0) col = 1; //백색일경우
		else col = 0; //흑색일경우
	}

	if (row >= n ) {
		ans[color] = max(ans[color], cnt);
		return;
	}

	//<해맸던부분>
	//row-col+n을 abs(row-col)으로 바꾸면되지않냐 라고 생각했는데
	//다음과 같은예외 때문에 row-col+n을 해줘야한다.
	//(1,2),(2,3) ...= -1 ,   (1,0), (2,1) ... =1
	//abs를 해버리면 두과정이 동일한 대각선에있다고 생각하는것이기 때문

	//비숍을 놓을수있는지 && 왼쪽 대각선에 놓을수있는지 && 오른쪽 대각선에 놓을수있는지
	if (arr[row][col] && !l[row - col+n] && !r[row + col]) {
		l[row - col+n] = r[row + col ] = true;
		DFS(row, col + 2, cnt + 1, color);
		l[row - col+n] = r[row + col ] = false;
	}
	//그 자리에 비숍을 놓을 수 있어도 놓지 않고 다음으로 넘어가는 경우
	DFS(row, col + 2, cnt, color);

}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	DFS(0, 0, 0, 0); //흑색
	DFS(0, 1, 0, 1); //백색
	cout << ans[0] + ans[1] << endl;

}


//틀린코드
//풀이코드 2: 체스판을 흑색백색으로 분리하지않음 : O(2^(n*n)) ==> 시간초과
//DFS를 2번하기때문에 2^이고, 1번할때마다 전체를 탐색하기때문에 (n/2)*(n/2)
#include <iostream>
#define MAX 10

using namespace std;

bool chess[MAX][MAX];
bool visited1[MAX * 2]; //오른쪽에서 왼쪽으로 가는 대각선
bool visited2[MAX * 2]; //왼쪽에서 오른쪽으로 가는 대각선
int bishop;
int chess_size;

//for문없이 재귀함수만으로 구현하기
void DFS(int cnt, int x, int y) {
	if (x >= chess_size) {
		x = 0;
		y++;
	}
	if (y >= chess_size) {
		if (cnt > bishop)
			bishop = cnt;
		return;
	}

	if (chess[y][x] && !visited1[x + y + 1] && !visited2[x - y + chess_size]) {
		visited1[x + y + 1] = true;
		visited2[x - y + chess_size] = true;
		DFS(cnt + 1, x + 1, y);
		visited1[x + y + 1] = false;
		visited2[x - y + chess_size] = false;
	}
	DFS(cnt, x + 1, y);
}

int main(void) {
	cin >> chess_size;

	for (int i = 0; i < chess_size; i++)
		for (int j = 0; j < chess_size; j++)
			cin >> chess[i][j];

	DFS(0, 0, 0);

	cout << bishop << '\n';
}
