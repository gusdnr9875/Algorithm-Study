#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n;
int visit[100001];
vector<pair<int, int> > Btree[100001];
int FarNode; 
int result;


void dfs(int node, int cost)
{
	visit[node] =1;
	
	if(result < cost)
	{
		result = cost;
		FarNode = node;	
	}
	
	for(int i=0;i<Btree[node].size();i++)
	{
		int next = Btree[node][i].first;
		if(!visit[next])
		{
			dfs(next, cost + Btree[node][i].second);
			visit[next] = 0;
		}
	}
	
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		
		while(1)
		{
			int b,c;
			cin >> b;
			if(b == -1)
				break;
			cin >> c;
			Btree[a].push_back({b,c});
		}	
	}
	
	dfs(1,0);
	memset(visit, 0, sizeof(visit));
	result = 0;
	dfs(FarNode,0);
	cout << result <<"\n";
	
	return 0;
}
