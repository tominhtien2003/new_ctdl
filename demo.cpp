#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    vector<int>dist(1e6,1e9);
    dist[n]=0;
    auto comp=[](auto &a,auto &b){return a.first>b.first;};
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>PQ(comp);
    PQ.push({0,n});
    while (!PQ.empty())
    {
        auto [x,y]=PQ.top();PQ.pop();
        if (y==0) 
        {
            cout << x;
            return 0;
        }
        for (int i=0;i<=15;i++)
        {
            int left=y+pow(2,i);
            int right=y-pow(2,i);
            if (left<1e6 && dist[left]>x+1) 
            {
                PQ.push({x+1,left});
                dist[left]=x+1;
            }
            if (right>=0 && dist[right]>x+1) 
            {
                PQ.push({x+1,right});
                dist[right]=x+1;
            }
        } 
    }
    cout << -1;
}