#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int result = 0;
string arr[5];
bool chk[5][5] = { 0, };
bool temp[5][5] = { 0, };
int y_ar[4] = { 0,0,1,-1 };
int x_ar[4] = { 1,-1,0,0 };

void search(int y, int x) {
	temp[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + y_ar[i];
		int nx = x + x_ar[i];
		if (chk[ny][nx] == 1 && temp[ny][nx] == 0)
			if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5)
				search(ny, nx);
	}
}

void dfs(int cnt, int y, int x, int som, int yim) {
	if (yim >= 4)
		return;
	if (cnt == 7 && som >= 4) {
		int val_temp = 0;
		memset(temp, 0, sizeof(temp));
		for(int i=0;i<5;i++)
			for(int j=0; j<5;j++)
				if (chk[i][j] == 1&& temp[i][j]==0) {
					search(i, j);
					val_temp++;
				}

		if (val_temp == 1)
			result++;
		return;
	}


	for (int i = y; i < 5; i++) {
		for (int j = (i == y ? x : 0); j < 5; j++) {
			if (chk[i][j] == 0) {
				chk[i][j] = 1;
				dfs(cnt + 1, i, j, arr[i][j] == 'S' ? som + 1 : som, arr[i][j] == 'Y' ? yim + 1 : yim);
				chk[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	dfs(0, 0, 0, 0, 0);

	cout << result << endl;

	return 0;
}