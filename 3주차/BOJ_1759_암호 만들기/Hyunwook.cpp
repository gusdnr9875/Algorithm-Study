#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int l, c;
string arr;
bool checked[17] = { 0, };

void dfs(int cnt, int current) {

	if (cnt == l) {

		int m=0, j=0;
		for (int i = 0; i < arr.size(); i++) {
			if (checked[i]) {
				if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
					m++;
				else
					j++;
			}
		}
		if (m >= 1 && j >= 2) {
			for (int i = 0; i < arr.size(); i++)
				if (checked[i])
					cout << arr[i];
			cout << endl;
		}
		return;
	}


	for (int i = current; i < arr.size(); i++) {
		if (checked[i] == 0) {
			checked[i] = 1;
			dfs(cnt + 1, i);
			checked[i] = 0;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char temp;
		cin >> temp;
		arr += temp;
	}
	sort(arr.begin(), arr.end());
	//cout << arr << endl;
	dfs(0, 0);
	return 0;
}