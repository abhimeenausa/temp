#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
int depth[N],height[N];
void dfs(int vertex,int par)
{
	//take action on vertex after entering the vertex
	cout<<vertex<<endl;

	for(int child:g[vertex])
	{
		if(child==par)
			continue;
		depth[child]=depth[vertex]+1;
		//take action on child before entering the child node
		dfs(child,vertex);
		height[vertex]=max(height[vertex],height[child]+1);
		//take action on child after exiting the child node
	}
	//take action on vertex before exiting the vertex
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" "<<depth[i]<<" "<<height[i]<<endl;
	}
	return 0;
}

/*
13
1 2
1 3 
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
*/


