#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct var{
	int a;
	int b;
};
bool cmp(var t1, var t2) {
	if (t1.a > t2.a) return true;
	return false;
}
int l, w, h, n;
int result = 0;
var arr[20];
bool jud = true;
void solved(int ll, int ww, int hh) {
	if (jud == false) return;
	if (ll == 0 || ww == 0 || hh == 0) return;

	for (int i = 0; i < n; i++) {
		if (ll >= arr[i].a && ww >= arr[i].a && hh >= arr[i].a && arr[i].b > 0) {
			arr[i].b--;
			result++;
			solved(ll, ww, hh - arr[i].a);
			solved(arr[i].a, ww - arr[i].a, arr[i].a);
			solved(ll - arr[i].a, ww , arr[i].a);
			return;
		}
	}

	jud = false;
}


int main() {
	cin >> l >> w >> h;
	cin >> n;
	int temp1, temp2;
	for (int i = 0; i < n; i++) {
		cin >> temp1 >> arr[i].b;
		arr[i].a = pow(2,temp1);
	}
	sort(arr, arr + n, cmp); // 내림차순 정렬

	solved(l, w, h);

	if (jud == false)
		cout << -1 << endl;
	else
		cout << result << endl;
}
/*
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> cube;
int cube_count;// 채워넣은 큐브의 개수
bool possible;

void f(int x, int y, int z) {
	if (!possible) return;
	if (x == 0 || y == 0 || z == 0) return;
	for (auto &e : cube) {
		if (e.second > 0 && x >= e.first && y >= e.first && z >= e.first) {
			cube_count++;
			e.second--;
			f(x, y, z - e.first);
			f(e.first, y - e.first, e.first);
			f(x - e.first, y, e.first);
			return;
		}
	}
	possible = false;// 채울 수 없는 경우
}

int solution(int l, int w, int h) {
	possible = true;
	sort(cube.rbegin(), cube.rend());// 큐브가 큰 순서대로 사용하기 위해 역순으로 정렬
	f(l, w, h);
	return  possible ? cube_count : -1;
}

int main() {
	int l, w, h;
	cin >> l >> w >> h;
	int n;
	cin >> n;

	int x, y;
	for (int i = 0; i<n; i++) {
		cin >> x >> y;
		cube.push_back({ pow(2, x), y });
	}
	int result = solution(l, w, h);
	cout << result << endl;
	return 0;
}*/