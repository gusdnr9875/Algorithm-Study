#include <iostream>

using namespace std;

// dp[a][b] a~b까지 최소비용 
const int INF = 987654321;
int dp[501][501];
int t, k;
int cost[501];
int sum[501];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	
	for(int i=0;i<t;i++)
	{
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			cin >> cost[j];
			sum[j] = sum[j-1] + cost[j];
		}
		
		// 두 개의 구간으로 나눈다. 거리 = d 
		for(int d = 1;d<k;d++)
		{
			for(int a = 1;a + d <= k;a++)
			{
				int b = a + d;
				dp[a][b] = INF;
				
				for(int mid = a;mid<b;mid++)
				{
					dp[a][b] = min(dp[a][b], dp[a][mid] + dp[mid+1][b] + sum[b] - sum[a-1]);
				}
			}
		}
		cout << dp[1][k] <<"\n";	
	}
	
	
	return 0;
} 
