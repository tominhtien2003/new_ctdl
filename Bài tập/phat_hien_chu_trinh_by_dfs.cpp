#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//decltype
#define ll long long int
const int mod=1e9+7;
bool dfs(std::vector<int>adj[],std::vector<int>&vis,std::vector<int>&path,int node)
{
    vis[node]=path[node]=1;
    for (auto &it:adj[node])
    {
        //la 1 chu trinh
        if (!vis[it])
        {
            if (dfs(adj,vis,path,node)) return true;
        }
        else if (path[it]) return true;
    }
    path[node]=0;
    return false;
}
int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int m,n;std::cin >> n >> m;
    std::vector<int>adj[n];
    for (int i=0;i<m;i++)
    {
        int x,y;std::cin >> x >> y;
        adj[x].push_back(y);
    }
    std::vector<int>path(n,0),vis(n,0);
    for (int i=0;i<n;i++)
    {
        if (!vis[i]) dfs(adj,vis,path,i);
    }
	return 0;
}

