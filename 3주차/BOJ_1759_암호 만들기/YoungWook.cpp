#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
int l,c;
vector<char> vowel;
vector<char> consonant;
vector<string> result; 
map<string, int> visit;
char alphabet[15];

void password(int idx1, int idx2, int vcnt, int ccnt, string s)
{
	if(vcnt >=1 && ccnt >=2 && s.size() == l ) // 모음 수가 1개이상이고 자음수가 2개이상이고 사이즈가 l이면 !! 
	{
		sort(s.begin(),s.end());
		if(!visit.count(s))
		{
			visit[s] = 1;
			result.push_back(s);
		}
		return;
	}
	
	if(s.size() == l)
		return;
	
	for(int i=idx1+1;i<vowel.size();i++)
		password(i, idx2,vcnt+1,ccnt, s+ vowel[i]);
	for(int i=idx2+1;i<consonant.size();i++)
		password(idx1, i, vcnt, ccnt+1, s+ consonant[i]);
}


int main(){
	cin >> l >> c;
	
	for(int i=0;i<c;i++)
	{
		cin >> alphabet[i];
		if(alphabet[i]== 'a'|| alphabet[i] == 'e'||alphabet[i] == 'i'||alphabet[i] =='o'||alphabet[i] =='u')
			vowel.push_back(alphabet[i]);
		else
			consonant.push_back(alphabet[i]); 
	}	
	
	password(-1,-1,0,0,"");
	
	sort(result.begin(), result.end());
	
	for(int i=0;i<result.size();i++)
		cout << result[i] << "\n";
	
	
	return 0;
}
