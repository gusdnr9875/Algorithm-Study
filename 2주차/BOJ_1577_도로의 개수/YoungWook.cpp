#include <iostream>

using namespace std;

int n,m,k;
int a,b,c,d;
int dp[102][102];
bool noWay[203][203];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// 가로 = n, 세로 = m 
	cin >> n >> m;
	cin >> k;
	
	for(int i=0;i<k;i++)
	{
		cin >> a >> b >> c >> d;
		noWay[b+d+2][a+c+2] = true;
	}
	
	dp[1][1] = 1;
	
	for(int i=1;i<=m+1;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			if(noWay[2*i-1][2*j] == false)
				dp[i][j] += dp[i-1][j];
			
			if(noWay[2*i][2*j-1] == false)
				dp[i][j] += dp[i][j-1];	
		}
	}
	
	for(int i=0;i<=m+1;i++)
	{
		for(int j=0;j<=n+1;j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	
	
	cout << dp[m+1][n+1] << "\n";
	return 0;
}
