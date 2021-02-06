#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 20;
int n,m,fuel;
int Map[MAX][MAX];
int sy,sx; // 출발 위치  
vector<pair<pair<int,int>,pair<int,int>>> st; // 출발지역 
bool visit[MAX][MAX];
bool client[MAX][MAX]; 


typedef struct
{
	int y,x;
}Dir;

Dir moveDir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

// 승객을 찾는다. 
int bfsc()
{
	memset(visit,false, sizeof(visit));
	visit[sy][sx] = true;
	queue<pair<int,int>> q;
	q.push(make_pair(sy,sx));
	vector<pair<int,int>> tp;
	
	int dis = 0; // 거리 
	bool flag = false;
	while(!q.empty())
	{
		int cursize = q.size();
		for(int i=0;i<cursize;i++)
		{
 
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			
			if(client[y][x])
			{
				flag = true;
				tp.push_back(make_pair(y,x));
			}
			
			
			for(int j=0;j<4;j++)
			{
				int ny = y + moveDir[j].y;
				int nx = x + moveDir[j].x;
				
				if(0<=ny && ny < n&& 0<=nx && nx <n)
				{
					if(Map[ny][nx] == 0 && !visit[ny][nx])
					{
						visit[ny][nx] = true;
						q.push(make_pair(ny,nx));						
					}
					
				}
				
			}
		
		}
		if(flag)
		{
			sort(tp.begin(),tp.end());
			sy = tp[0].first;
			sx = tp[0].second;
			client[sy][sx] = false;
			return dis;
		}
		
		dis++;
	}
	
	return -1;
} 

// 목적지를 찾는다.

int bfsd()
{
	queue<pair<int,int>> q;
	memset(visit, false, sizeof(visit));
	int dy,dx; // 목적지  
	for(int i=0;i<st.size();i++)
	{
		int ty = st[i].first.first;
		int tx = st[i].first.second;
		
		if(sy == ty && sx == tx)
		{
			dy = st[i].second.first;
			dx = st[i].second.second;
			break;
		}
	}
	
	visit[sy][sx] =true;
	q.push(make_pair(sy,sx));
	
	int dis = 0; // 거리 
	
	while(!q.empty())
	{
		int cursize = q.size();
		for(int i =0;i<cursize;i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			
			
			if( y == dy && x == dx)
			{
				sy = dy;
				sx = dx;
				return dis;
			}
			for(int j=0;j<4;j++)
			{
				int ny = y + moveDir[j].y;
				int nx = x + moveDir[j].x;
				
				
				if(0<=ny && ny<n && 0<=nx && nx <n)
				{
					if(!visit[ny][nx] && Map[ny][nx]== 0)
					{
						visit[ny][nx] = true;
						q.push(make_pair(ny,nx));
					}
					
					
				}
				
			}
			
			
		}
		dis++;
	}
	
	
	return -1;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> fuel;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> Map[i][j];
	
	int t1,t2;
	cin >> t1 >> t2;
	sy = t1 - 1;
	sx = t2 - 1;
	
	for(int i=0;i<m;i++)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		st.push_back(make_pair(make_pair(a-1,b-1),make_pair(c-1,d-1)));
		client[a-1][b-1] = true;
	
	}
	
	int num = st.size();
	
	
	for(int i=0;i<num;i++)
	{
		// 승객찾기 
		int clidis = bfsc();
		
		fuel -= clidis;
		
		if(fuel<=0 || clidis == -1)
		{
			cout << -1 << "\n";
			return 0;
		}
		
		
		// 목적지찾기  
		int desdis = bfsd();
		
		fuel -= desdis;
		
		
		if(fuel <0 || desdis == -1)
		{
			cout << -1 << "\n";
			return 0;
		}
		
		// 기름 부족 or 못가는 곳  
		fuel += 2 * desdis;
			
	}
	
	
	cout << fuel <<"\n";
	
	
	return 0;
}
