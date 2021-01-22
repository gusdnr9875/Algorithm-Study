#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int arr[9][9] = { 0, };
bool fin = false;
vector <pair<int, int>> vec;

void dfs(int cnt) {
	if (cnt == vec.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << endl;
		}
		fin = true;
		return;
	}
	if (fin)
		return;

	int y = vec[cnt].first;
	int x = vec[cnt].second;
	bool temp[10] = { 0, };
	for (int i = 0; i < 9; i++) {
		temp[arr[i][x]] = 1;
		temp[arr[y][i]] = 1;
	}
	for (int i = y / 3 * 3; i < y / 3 * 3 + 3; i++) {
		for (int j = x / 3 * 3; j < x / 3 * 3 + 3; j++) {
			temp[arr[i][j]] = 1;
		}
	}

	for(int i=1;i<=9;i++)
		if (temp[i] == 0) {
			arr[y][x] = i;
			dfs(cnt + 1);
			arr[y][x] = 0;
		}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				vec.push_back(make_pair(i, j));
		}

	dfs(0);

	return 0;
}