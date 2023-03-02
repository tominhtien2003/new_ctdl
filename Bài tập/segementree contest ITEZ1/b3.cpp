#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
#define int long long
const int N=4e5+1;
int sgm[N],lazy[N];
void build(int root,int l,int r,int arr[])
{
    if (l==r)
    {
        sgm[root]=arr[l];
        return;
    }
    int m=(l+r)/2;
    build(root*2+1,l,m,arr);
    build(root*2+2,m+1,r,arr);
    sgm[root]=max(sgm[2*root+1],sgm[2*root+2]);
}
void update(int root,int l,int r,int x,int y,int val)
{
    if (y<l || x>r || l>r) return;
    if (x<=l && y>=r)
    {
        sgm[root]+=val;
        lazy[root]+=val;
        return;
    }
    int m=(l+r)/2;
    sgm[2*root+1]+=lazy[root];
    sgm[2*root+2]+=lazy[root];
    lazy[2*root+1]+=lazy[root];
    lazy[2*root+2]+=lazy[root];
    lazy[root]=0;
    update(root*2+1,l,m,x,y,val);
    update(root*2+2,m+1,r,x,y,val);
    sgm[root]=max(sgm[2*root+1],sgm[2*root+2]);
}
int get(int root,int l,int r,int low,int hight)
{
    if (l>r || low>r || hight<l) return LONG_MIN;
    if (l>=low && hight>=r) return sgm[root];
    int m=(l+r)/2;
    sgm[2*root+1]+=lazy[root];
    sgm[2*root+2]+=lazy[root];
    lazy[2*root+1]+=lazy[root];
    lazy[2*root+2]+=lazy[root];
    lazy[root]=0;
    return max(get(root*2+1,l,m,low,hight),get(root*2+2,m+1,r,low,hight));
}
main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int n;cin >> n;
    memset(sgm,LONG_MIN,sizeof(sgm));
    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];
    build(0,0,n-1,arr);
    int q;cin >> q;
    while(q--)
    {
        int s;cin >> s;
        if (s==1)
        {
            int x,y,z;cin >> x >> y >> z;
            update(0,0,n-1,x-1,y-1,z);
        }
        else{
            int x,y;cin >> x >> y;
            cout << get(0,0,n-1,x-1,y-1) << endl;
        }
    }
    return 0;
}
