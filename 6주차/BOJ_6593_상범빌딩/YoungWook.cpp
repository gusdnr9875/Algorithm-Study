#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;
int l,r,c;
char building[30][30][30];
int visit[30][30][30];
queue<pair<pair<int,int>, int> > q;

typedef struct
{
	int z,y,x;
	
} dir;

dir moveDir[6] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

int bfs()
{
	int second = 0;
	while(!q.empty())
	{
		int cursize = q.size();
		for(int i=0;i<cursize;i++)
		{
			int curZ = q.front().first.first;
			int curY = q.front().first.second;
			int curX = q.front().second;	
			q.pop();
			
			if(building[curZ][curY][curX] == 'E')
				return second;
			
			
			for(int j=0;j<6;j++)
			{
				int nz = curZ + moveDir[j].z;
				int ny = curY + moveDir[j].y;
				int nx = curX + moveDir[j].x;
				
				if(0<=nz && nz<l && 0<=ny && ny< r&& 0<=nx && nx< c)
				{
					if((building[nz][ny][nx] == '.' || building[nz][ny][nx] =='E') && !visit[nz][ny][nx])
					{
						visit[nz][ny][nx] = 1;
						q.push(make_pair(make_pair(nz,ny),nx));	
					}	
				}	
				
			}			
		
		}
		second++;
	}
	return -1;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1)
	{		
		cin >> l >> r >> c;
		
		if(l == 0 && r==0 && c==0)
			break;
		
		memset(visit, 0,sizeof(visit));
		
		while(!q.empty())
			q.pop();
		
		
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<r;j++)
			{
				string s;
				cin >> s;
				for(int l=0;l<s.size();l++)
				{
					building[i][j][l] = s[l];
					if(building[i][j][l] == 'S')
					{
						q.push(make_pair(make_pair(i,j),l));
						visit[i][j][l] = 1;
					}
				}		
			}	
		}
		
		int result = bfs();
		
		
		if(result == -1)
			cout<< "Trapped!" <<"\n";
		else
			cout << "Escaped in " << result << " minute(s).\n";
			
	}
	
	
	return 0;
}
