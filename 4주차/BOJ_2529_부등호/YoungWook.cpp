#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
// 부등호 저장 
char str[9];
vector<int> v1;
vector<int> v2;

// 부등호 성립조건 
bool possible(vector<int> v)
{
	for(int i=0;i<n;i++)
	{
		char temp = str[i];
		if(temp == '<')
		{
			if(v[i] > v[i+1])
				return false;
		}
		else
		{
			if(v[i] < v[i+1])
				return false;
		}
	}
	return true;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> str[i];
	
	// 부등호 n개는 숫자 n+1 개 필요	
	for(int i=0;i<n+1;i++)
	{
		v1.push_back(i);
		v2.push_back(9-i);
	}
	
	//부등호 성립하는 가장 큰 수 
	do{
		if(possible(v2))
		{
			for(int i=0;i<v2.size();i++)
				cout << v2[i];
			
			
			cout <<"\n";
			break;
		}
			
	}while(prev_permutation(v2.begin(), v2.end()));
	
	// 부등호 성립하는 가장 작은 수 
	do{
		if(possible(v1))
		{
			for(int i=0;i<v1.size();i++)
				cout << v1[i];
			
			break;
		}
		
	}while(next_permutation(v1.begin(), v1.end()));
	
	return 0;
}
