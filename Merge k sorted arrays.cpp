#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> custom;
vector<int> Kmerge(vector<vector<int>> v,int k)
{
	vector<int> result;
	priority_queue<custom,vector<custom>,greater<custom>> pq;
	for(int i=0;i<k;i++)
	{
		pq.push(make_pair(v[i][0],make_pair(i,0)));
	}
	while(!pq.empty())
	{
		custom minimum = pq.top();
		pq.pop();
		result.push_back(minimum.first);
		int x = minimum.second.first;
		int y = minimum.second.second;
		if(y+1 < v[x].size() )
		 pq.push(make_pair(v[x][y+1],make_pair(x,y+1)));
	}
	return result;
}
int main()
{
	long long int n;
	int k;
	cin>>k>>n;
	vector<vector<int>> v;
	vector<int> temp;
	for(int i=0;i<k;i++)
	{
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			temp.push_back(x);
		}
		v.push_back(temp);
			for(int i = 0;i<n;i++)
		 temp.pop_back();
	}
	vector<int> ans = Kmerge(v,k);
	int p = ans.size();
	for(int i=0;i<p;i++)
	 cout<<ans[i]<<" ";
	return 0;
}
