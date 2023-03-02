#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[1001][1001];
pair<int,int> direcs[4]={{1,0},{-1,0},{0,1},{0,-1}};
main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    auto comp=[](auto &a,auto &b){return a[0]<b[0];};
    int test;cin >> test;
    while (test--)
    {
        int n,x,y;cin >> n >> x >> y;
        if (x==y)
        {
            cout << 0 << endl;
            continue;
        }
        int dist[n][n];
        memset(dist,1e9,sizeof(dist));
        int cnt=0;
        int left=0,right=n-1,top=0,bottom=n-1;
        priority_queue<vector<int>,vector<vector<int>>,decltype(comp)>PQ(comp);
        while (left<=right && top<=bottom)
        {
            for (int col=left;col<right;col++) 
            {
                arr[top][col]=++cnt;
                if (cnt==x) PQ.push({0,top,col});
            }
            for (int row=top;row<bottom;row++) 
            {
                arr[row][right]=++cnt;
                if (cnt==x) PQ.push({0,row,right});
            }
            for (int col=right;col>left;col--) 
            {
                arr[bottom][col]=++cnt;
                if (cnt==x) PQ.push({0,bottom,col});
            }
            for (int row=bottom;row>top;row--) 
            {
                arr[row][left]=++cnt;
                if (cnt==x) PQ.push({0,row,left});
            }
            if (left==right && left==bottom) 
            {
                arr[left][left]=++cnt;
                if (cnt==x) PQ.push({0,left,left});
            }
            left++;right--;bottom--;top++;
        }
        dist[PQ.top()[1]][PQ.top()[2]]=0;
        int res=-1,check=1;
        while (!PQ.empty())
        {
            vector<int>top=PQ.top();PQ.pop();
            if (dist[top[1]][top[2]]<top[0]) continue;
            for (auto [x,y]:direcs)
            {
                int u=x+top[1],v=y+top[2];
                if (u>=0 && v>=0 && u<n && v<n && __gcd(arr[u][v],arr[top[1]][top[2]])==1)
                {
                    if (arr[u][v]==y) 
                    {
                        res=top[0]+1;
                        check=0;
                        break;
                    }
                    if (dist[u][v]>top[0]+1)
                    {
                        dist[u][v]=top[0]+1;
                        PQ.push({dist[u][v],u,v});
                    }
                }
            }
            if (check==0) break;
        }
        cout << res << endl;
    }
    return 0;
}