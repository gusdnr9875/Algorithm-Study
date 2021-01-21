//문제: 랭퍼든 수열쟁이야!!
//알고리즘: 백트래킹
//푼날짜: 2021-01-21


#include<iostream>
using namespace std;

int n,x,y;
int ans;
int arr[26]; //i번째 인덱스에 들어있는 값
bool visited[13]; //1~12숫자가 쓰였는지 체크하는 배열

void DFS(int idx) {
	if (idx == 2 * n) {
		ans++;
		return;
	}
	//현재 배열 인덱스에 값이 없다면
	if (!arr[idx]) {
		for (int i = 1; i <= n; i++) {
			//현재 자연수가 사용됬다면 continue
			if (visited[i]) continue; 
			//쌍을 이루는 인덱스가 2*n을 넘어가거나, 이미 그 인덱스에 값이있다면
			//랭퍼드 수열을 만족못하므로 continue
			if (idx + i + 1 > 2 * n || arr[idx+i+1]) continue;

			//백트래킹으로 재귀 
			arr[idx] = arr[idx + i + 1] = i;
			visited[i] = true;
			DFS(idx + 1);
			arr[idx] = arr[idx + i + 1] = 0;
			visited[i] = false;
		}
	}
	//현재 배열 인덱스에 값이 있다면
	else DFS(idx + 1);
	
}
int main() {
	cin >> n >> x >> y;

	//x번째 수와 y번째수는 같음
	//x번째, y번째인덱스에있는 값= y-x-1
	arr[x]=arr[y] = y - x - 1;
	visited[y - x - 1] = true;

	DFS(1);
	cout << ans;

	
}