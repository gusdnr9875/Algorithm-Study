#include <iostream>
#include <cstring>


using namespace std;

const int INF = 987654321;
const int MAX = 500;

int n;
/* 왼쪽에서 오른쪽까지 곱셈 중 최소값 */
int dp[MAX][MAX];
pair<int,int> arr[MAX];

int Solution(int start, int end)
{
	if(start == end)
		return 0;
	
	int &ret = dp[start][end];
	
	if(ret != -1)
		return ret;
	
	ret = INF;
	
	for(int i=start; i<end;i++)
	{
		ret = min(ret, Solution(start, i) + Solution(i+1, end) + arr[start].first *arr[i].second *arr[end].second);
	} 
	return ret; 
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i].first >> arr[i].second;
	
	memset(dp, -1, sizeof(dp));
	cout << Solution(0,n-1) << "\n";
	
	return 0;
}
