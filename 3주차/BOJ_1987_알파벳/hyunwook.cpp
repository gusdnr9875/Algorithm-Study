#include <iostream>
#include <string>
using namespace std;
int result = 0;
bool al[26] = { 0 };
int x_ar[4] = { 0,0,1,-1 };
int y_ar[4] = { 1,-1,0,0 };
int r = 0, c = 0;
string arr[20];
void dfs(int yy, int xx, int cnt) {
	if (cnt > result) {
		result = cnt;
	}

	for (int i = 0; i < 4; i++) {
		int y = y_ar[i] + yy;
		int x = x_ar[i] + xx;
		if (y >= 0 && y < r && x >= 0 && x < c) {
			if (al[arr[y][x] - 65] == 0) {
				al[arr[y][x] - 65] = 1;
				dfs(y, x, cnt + 1);
				al[arr[y][x] - 65] = 0;
			}
		}
	}
	return;

}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> arr[i];


	al[arr[0][0] - 65] = 1;
	dfs(0, 0, 1);
	al[arr[0][0] - 65] = 0;


	cout << result << endl;
}