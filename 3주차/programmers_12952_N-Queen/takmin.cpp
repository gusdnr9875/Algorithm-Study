//문제: N-Queen
//알고리즘: 백트래킹

#include<iostream>
#include<vector>
using namespace std;
struct POINT {
	int x, y;
};
int arr[13];
int n;
vector<POINT> v;
int ans;

//대각선이나 같은열이라면 리턴
bool check(int x, int y) {
	for (int i = 0; i < x; i++) {
		if (y == v[i].y || (x - v[i].x == abs(y - v[i].y))) {
			return false;
		}
	}
	return true;
}
void DFS(int x, int y) {
	if (x == n) {
		ans++;
	}

	for (int j = 0; j < n; j++) {
		v.push_back({ x ,j });
		if (check(x, j)) {	
			DFS(x + 1, j);			
		}
		v.pop_back();
		
	}

}

int solution(int N) {
    n=N;
    DFS(0,0);
    return ans;
}