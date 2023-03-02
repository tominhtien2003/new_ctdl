#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
//decltype
#define ll long long
const int mod=1e9+7;

void dfs(vector<int>adj[],vector<int>&topo,vector<bool>&vis,int node)
{
    vis[node]=true;
    for (auto &it:adj[node])
    {
        if (!vis[it]) dfs(adj,topo,vis,it);
    }
    topo.push_back(node);
}
std::vector<int> topoSort(int V,std::vector<int>adj[])
{
    std::vector<int>topo,degree(V);
    for (int i=0;i<V;i++)
        for (auto it:adj[i]) degree[it]++;
    std::queue<int>Q;
    for (int i=0;i<V;i++)
        if (degree[i]==0) Q.push(i);
    while (!Q.empty())
    {
        int node=Q.front();Q.pop();
        topo.push_back(node);
        for (auto it:adj[node])
        {
            degree[it]--;
            if (degree[it]==0) Q.push(it);
        }
    }
    return topo;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin >> n >>m;
    vector<int>adj[n],degree(n,0);
    for (int i=0;i<m;i++) 
    {
        int x,y;cin >> x >> y;
        adj[x].push_back(y);
        degree[y]++;
    }
    vector<int>topo;
    //dfs
    // vector<bool>vis(n,false);
    // for (int i=0;i<n;i++)
    // {
    //     if (!vis[i]) dfs(adj,topo,vis,i);
    // }
    // reverse(topo.begin(),topo.end());
    // for (auto it:topo) cout << it << " ";
    // cout << endl;
    //bfs
    topo=topoSort(n,adj);
    for (auto it:topo) cout << it << " ";
	return 0;
}