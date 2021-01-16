#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef struct
{
	int y,x;
}dir;

dir moveDir[4]= {{0,1},{1,0},{0,-1},{-1,0}};

char room[5][5];
vector<int> state(25);
bool temp[5][5];
bool visit[5][5];

bool check()
{
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(!(temp[i][j] == visit[i][j]))
				return false;
	return true;
}


int dfs(int y, int x)
{
	visit[y][x] = true;
	
	int ret =1;
	
	for(int i=0;i<4;i++)
	{
		int ny = y + moveDir[i].y;
		int nx = x + moveDir[i].x;
		
		if(0<=ny && ny <5 && 0<=nx && nx <5)
		{
			if(!visit[ny][nx] && temp[ny][nx])
				ret+=dfs(ny,nx);	
		}
		
	}	
	return ret;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<5;i++)
	{
		string s;
		cin >> s;
		for(int j=0;j<s.size();j++)
			room[i][j] = s[j]; 
	}
	
	
	for(int i=24;i>=18;i--)
		state[i] = 1;
	
	
	int result = 0;
	
	do
	{
		memset(temp, false, sizeof(temp));
	
		int Ycnt = 0;
		int ty,tx;
		for(int i=0;i<25;i++)
		{
			if(state[i])
			{
				ty = i/5;
				tx = i%5;
				
				temp[ty][tx] = true;
				
				if(room[ty][tx] == 'Y')
					Ycnt++;
			}
		}
		
		if(Ycnt >= 4)
			continue;
		
		memset(visit,false, sizeof(visit));
		result += dfs(ty,tx) == 7;
		
	
		
		
	}while(next_permutation(state.begin(),state.end()));
	
	cout << result <<"\n";
	
	return 0;
}
