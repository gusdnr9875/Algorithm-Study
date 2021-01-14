//문제: 암호만들기
//알고리즘: 백트래킹
//푼날짜: 2021-01-12


#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int l, c;
char arr[16];


vector<char> a; //모음
vector<char> b; //자음
map<string,bool> visited;
string ans;
void DFS(int a_idx, int b_idx, int a_size, int b_size, string pass) {
	if (pass.size()==l ) {
		if (a_size >= 1 && b_size >= 2) {
			sort(pass.begin(), pass.end());
			if (!visited[pass]) {
				visited[pass] = true;
				cout << pass << "\n";
			}
		}
		else return;
	}

	for (int i = a_idx+1; i < a.size(); i++) {
		DFS(i, b_idx, a_size + 1, b_size, pass + a[i]);
	}

	for (int i = b_idx+1; i < b.size(); i++) {
		DFS(a_idx, i, a_size, b_size + 1, pass + b[i]);
	}


}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' ||
			arr[i] == 'o' || arr[i] == 'u') {
			a.push_back(arr[i]);
		}
		else b.push_back(arr[i]);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	DFS(-1, -1, 0, 0, "");

	


	

}