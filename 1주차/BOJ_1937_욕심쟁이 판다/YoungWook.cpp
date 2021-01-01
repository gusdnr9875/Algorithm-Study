#include <iostream>

using namespace std;

const int MAX = 500;

typedef struct
{
	int y,x;
}Dir;

Dir moveDir[4] = {{0,1},{1,0},{0,-1},{-1,0}};
 
int n;
int arr[MAX][MAX];
int dp[MAX][MAX];

/* 기저사례 : 움직일 곳이 없을 떄 */

int dfs(int y, int x) 
{
	int &ret = dp[y][x];
	
	if(ret != -1) return ret;
	
	ret = 1;
	
	for(int i=0;i<4;i++)
	{
		int ny = y + moveDir[i].y;
		int nx = x + moveDir[i].x;
		
		if(0<=ny && ny <n && 0<=nx && nx < n)
		{			
			if(arr[y][x] < arr[ny][nx])
			{
				int temp = dfs(ny,nx) + 1;
				ret = max(ret, temp);
			}
		}
	}
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	/* 대나무숲 정보 및 초기화 */
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	
	int result = 0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	
			int temp = dfs(i,j);
			result = max(result, temp);	
		}
	}
	
	cout << result <<"\n";
	
	return 0;
}
