#include <iostream>
#include <queue>
#include <functional>

using namespace std;
int n,k;
bool visit[100001];


int Search()
{
	priority_queue<pair<int, int > , vector<pair<int,int> > , greater<pair<int,int> > > q;
	q.push(make_pair(0,n));
	visit[n] = true;
	
	while(!q.empty())
	{
		int Loc = q.top().second;
		int Sec = q.top().first;
		q.pop();
		
		if(Loc == k)
			return Sec;
		
		int next = Loc *2;	
		if(next <= 100000 && !visit[next])
		{
			q.push(make_pair(Sec, next));
			visit[next] = true;	
		}			
		
		next = Loc+1;
		if(next<= 100000 && !visit[next])
		{
			q.push(make_pair(Sec+1, next));
			visit[next] = true;
		}
		
		next= Loc-1;
		if(next>=0 && !visit[next])
		{
			q.push(make_pair(Sec+1, next));
			visit[next] = true;
		}	
	}
	
	
}


int main(){
	cin >> n >> k;
	
	cout << Search() <<"\n";
	
	return 0;
}
