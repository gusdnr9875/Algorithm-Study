#include <iostream>

using namespace std;

const int MAX = 500;

int n,m; // 가로, 세로 
int arr[MAX][MAX];
int dp[MAX][MAX];
int count;

typedef struct
{
	int y,x;
}Dir; 

Dir moveDir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int dfs(int y, int x)
{
	if(y == m-1 && x == n-1)
		return 1;
		
	int &ret = dp[y][x];
	if(ret != -1)
		return ret;
	
	ret = 0;
	
	for(int i=0;i<4;i++)
	{
		int ny = y + moveDir[i].y;
		int nx = x + moveDir[i].x;
		
		if(0<= ny && ny <m && 0<= nx && nx < n)
		{
			if(arr[ny][nx] < arr[y][x])
			{
				ret += dfs(ny,nx);
			}	
		}
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>> arr[i][j]; 
			dp[i][j] = -1;
		}
	}
		
	cout << dfs(0,0) << "\n";
	
	return 0;
}
