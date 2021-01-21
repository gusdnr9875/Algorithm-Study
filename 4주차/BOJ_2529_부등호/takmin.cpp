//문제: 부등호 (실버2)
//알고리즘: 백트래킹
//푼 날짜: 2021-01-18

//풀이: 1. 백트래킹, 2. 완전탐색

//1. 백트래킹
//가지치기를 통하여 재귀를 진행한다.
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int k;
char sign[10]; //부등호
bool visited[10]; //0~9까지 방문여부
vector<string> ans;

bool check(int n1, int n2, char op) {
	if (op == '>' && n1 < n2) return false;
	else if (op == '<' && n1 > n2) return false;

	return true;
}
void DFS(int idx, string str) {
	//종료조건
	if (idx == k) {
		ans.push_back(str);
		return;
	}

	

	for (int i = 0; i <=9; i++) {
		if (visited[i])continue;
		if (idx == -1 || check(str[idx]-'0',i,sign[idx])) {
			visited[i] = true;
			DFS(idx + 1, str + to_string(i));
			visited[i] = false;
		}
		
	}

}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> sign[i];

	DFS(-1, "");
	string max = *max_element(ans.begin(), ans.end());
	string min = *min_element(ans.begin(), ans.end());	
	cout<<max<<endl<<min<<endl;

}


//// 2. 완전탐색
//// 재귀를 통해 모든경우의수를 구하고 n개의 길이가 됬을때 마지막에 검사한다.
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<string>
//#include<cstring>
//
//using namespace std;
//vector<string> ans; // 정답 후보들을 저장할 벡터
//bool check[10];
//int n;
//char a[20]; // 부등호를 입력받을 배열
//
//bool ok(string num) // 완성된 문자열이 부등호를 만족하는지 판별
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == '<'){
//			if (num[i] > num[i + 1]) return false;
//		}
//		else if (a[i] == '>'){
//			if (num[i] < num[i + 1]) return false;
//		}
//	}
//	return true;
//}
//
//void go(int index, string num)
//{
//	if (index == n + 1){
//		if (ok(num))
//			ans.push_back(num);
//		return;
//	}
//
//	for (int i = 0; i <= 9; i++)
//	{
//		if (check[i]) continue; // 중복 제거
//		check[i] = true;
//		go(index + 1, num + to_string(i)); // 문자열에 누적
//		check[i] = false;
//	}
//}
//
//int main(void)
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//
//	go(0, "");
//
//	auto minmax = minmax_element(ans.begin(), ans.end());
//
//	cout << *minmax.second << '\n'; // 최댓값
//	cout << *minmax.first << '\n'; // 최솟값
//
//}