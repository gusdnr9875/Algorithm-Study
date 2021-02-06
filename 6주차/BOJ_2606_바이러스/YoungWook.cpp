#include <iostream>
#include <vector>

using namespace std;
vector<int> computer[101];
int visit[101];

void dfs(int node)
{
	visit[node] = 1;
	
	for(int i=0;i<computer[node].size();i++)
	{
		int next = computer[node][i];
		if(!visit[next])
			dfs(next);
	}
	return;
}

int main(){
	int n,c;
	cin >> n;
	cin >> c;
	
	for(int i=0;i<c;i++)
	{
		int a,b;
		cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}
	
	dfs(1);
	
	int result = 0;
	
	for(int i=1;i<=n;i++)
		if(visit[i] == 1)
		{
			result++;	
		}
	cout << result -1 <<"\n";
	
	return 0;
} 
