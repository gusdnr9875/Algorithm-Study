#include <iostream>
#include <string>
using namespace std;
int n, m;
int result = 2e9;
string arr[21]; //0base
int y_ar[4] = { 0,0,1,-1 };
int x_ar[4] = { 1,-1,0,0 };

void dfs(int cnt, int c1y, int c1x, int c2y, int c2x) {
	
	if (cnt == 10)
		return;

	for (int i = 0; i < 4; i++) {
		int n1y = c1y + y_ar[i];
		int n1x = c1x + x_ar[i];
		int n2y = c2y + y_ar[i];
		int n2x = c2x + x_ar[i];
		if (n1y >= 0 && n1y < n && n2y >= 0 && n2y < n && n1x >= 0 && n1x < m &&  n2x >= 0 && n2x < m) {
			if (arr[n1y][n1x] == '#' && arr[n2y][n2x] == '#')
				continue;
			if (arr[n1y][n1x] == '#')
				n1y = c1y, n1x = c1x;
			if (arr[n2y][n2x] == '#')
				n2y = c1y, n2x = c1x;
			dfs(cnt + 1, n1y, n1x, n2y, n2x);
		}
		else if ((n1y < 0 || n1y >= n || n1x < 0 || n1x >= m) && (n2y < 0 || n2y >= n || n2x < 0 || n2x >= m)) {
			continue;
		}
		else {
			if (result > cnt + 1)
				result = cnt + 1;
			return;
		}
	}

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int c1y, c1x, c2y, c2x;
	bool chk = false;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 'o'&& chk == false) {
				c1y = i, c1x = j;
				chk = true;
			}
			else if (arr[i][j] == 'o'&& chk == true) {
				c2y = i, c2x = j;
			}
	}
	dfs(0, c1y, c1x, c2y, c2x);
	if (result == 2e9)
		cout << -1 << endl;
	else
		cout << result << endl;
	return 0;
}