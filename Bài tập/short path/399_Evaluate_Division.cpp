#include<bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<string,vector<pair<string,double>>>adj;
double dfs(unordered_set<string>&vis,string s,string e)
{
    if (!adj.count(s)) return -1;
    if (s==e) return 1;
    vis.insert(s);
    for (auto it:adj[s])
    {
        if (!vis.count(it.first))
        {
            double res=dfs(vis,it.first,e);
            if (res!=-1) return res*it.second;
        }
    }
    return -1;
}

main()
{
    vector<vector<string>>equations;
    vector<double>values;
    vector<vector<string>> queries;
    int m,n,q;cin >> m >> n >> q;
    for (int i=0;i<m;i++) 
    {
        string x,y;cin >>x >> y;
        equations.push_back({x,y});
    }
    for (int i=0;i<n;i++)
    {
        double x;cin >> x;
        values.push_back(x);
    }
    int cnt=0;
    for (auto it:equations)
    {
        adj[it[0]].push_back({it[1],values[cnt]});
        adj[it[1]].push_back({it[0],1.0/values[cnt]});
        ++cnt;
    }
    vector<double>res;
    for (int i=0;i<q;i++)
    {
        string x,y;cin >> x >> y;
        queries.push_back({x,y});
        unordered_set<string>vis;
        res.push_back(dfs(vis,queries[i][0],queries[i][1]));
    }
    for (auto it:res) cout << it << " ";
    return 0;
}