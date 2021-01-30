// 1. 치즈부분을 제외하고 테두리에서 갈 수 있는 곳을 구분
// 2. 구분해준곳, 치즈가 4방향중 한 방향이라도 닿아있으면 1시간 뒤 녹게 되는 곳 

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100;

int cheese[MAX][MAX];
int y,x;
bool visit[MAX][MAX];
int copycheese[MAX][MAX];

typedef struct
{
	int y,x;
}Dir;

Dir moveDir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int cy, int cx)
{
	visit[cy][cx] = true;
	
	for(int i=0;i<4;i++)
	{
		int ny = cy + moveDir[i].y;
		int nx = cx + moveDir[i].x;
		
		if(0<= ny && ny <y && 0<=nx && nx < x)
		{
			if(!visit[ny][nx] && !cheese[ny][nx])
				dfs(ny, nx);
		}
	}
	
}

bool check(int cy, int cx)
{
	for(int i=0;i<4;i++)
	{
		int ny = cy + moveDir[i].y;
		int nx = cx + moveDir[i].x;
		
		if(!cheese[ny][nx] && visit[ny][nx])
			return true;
	}
	return false;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> y >> x;
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			cin >> cheese[i][j];
		
	int hour = 0;
	int Sizecheese = 0;
	
	while(1)
	{
		// 1. 수행
		 
		memset(visit, false, sizeof(visit));
		for(int i=0;i<x;i++)
		{
			if(!visit[0][i])
				dfs(0,i);
		}
		
		for(int i=0;i<x;i++)
		{
			if(!visit[y-1][i])
				dfs(y-1,i);
		}
		
		for(int i=0;i<y;i++)
		{
			if(!visit[i][0])
				dfs(i,0);
		}
		
		for(int i=0;i<y;i++)
		{
			if(!visit[i][x-1])
				dfs(i, x-1);
		}
		
		
		int temp = 0;
		for(int i=0;i<y;i++)
		{
			for(int j=0;j<x;j++)
			{
				if(cheese[i][j] == 1)
					temp++;				
				
			}
		}
		
		if(temp == 0)
			break;
		
		
		// 2. 수행 
		
		for(int i=0;i<y;i++)
			for(int j=0;j<x;j++)
				copycheese[i][j] = cheese[i][j];
		
				
		for(int i=0;i<y;i++)
		{
			for(int j=0;j<x;j++)
			{
				if(cheese[i][j] && check(i,j))
				{
					copycheese[i][j] = 0;	
				}	
			}	
		}
			
	
		for(int i=0;i<y;i++)
			for(int j=0;j<x;j++)
				cheese[i][j] = copycheese[i][j];
				
		
		hour++;

		Sizecheese = temp;
				
	}	
	
	cout << hour << "\n";
	cout << Sizecheese << "\n";
	
	return 0;
}
