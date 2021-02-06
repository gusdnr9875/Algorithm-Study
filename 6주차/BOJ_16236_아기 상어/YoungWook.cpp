#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 20;

typedef struct
{
	int y,x;
}dir;

dir moveDir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int Sy,Sx,Ssize; //Shark의 위치 
int n; 
int space[MAX][MAX];
bool visit[MAX][MAX];
int ate; // 상어가 먹은 물고기 마리 수 

int Searching()
{
	memset(visit, false, sizeof(visit));
	queue<pair<int,int>> q;
	q.push(make_pair(Sy,Sx));	
	visit[Sy][Sx] = true;
	vector<pair<int,int>> v;
	int count = 0;
	
	while(!q.empty())
	{
		int cursize = q.size();
		bool flag = false;
			
		for(int i=0;i<cursize;i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			
			if(0 < space[y][x] && space[y][x] <Ssize)
			{
				flag = true;
				v.push_back(make_pair(y,x));
			}
			
			for(int j=0;j<4;j++)
			{
				int ny = y + moveDir[j].y;
				int nx = x + moveDir[j].x;
				
				if(0<=ny &&ny < n && 0<=nx && nx <n)
				{
					if(!visit[ny][nx] && space[ny][nx] <=Ssize )
					{
						visit[ny][nx] = true;
						q.push(make_pair(ny,nx));						 
					}
				}			
			}	
		}
		if(flag)
		{
			sort(v.begin(),v.end());
			Sy = v[0].first;
			Sx = v[0].second;
			space[Sy][Sx] = 0;
			return count;
		}
		
		count++;
	}
	
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin >> space[i][j];
			if(space[i][j] == 9)
			{
				Sy = i;
				Sx = j;
				Ssize = 2;
				space[i][j] = 0;
			}
		}
	
	int result = 0;
	
	while(1)
	{
		int temp = Searching();
		
		if(temp == -1)
			break;
		
		ate++;
		if(ate == Ssize)
		{
			ate = 0;
			Ssize++;
		}
	
		result += temp;
	}
	
	
	cout << result << "\n";
	
	return 0;
}
