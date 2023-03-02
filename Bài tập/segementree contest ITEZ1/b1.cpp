#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
#define int long long
const int N=4e5+1;
int sgm[N];
void build(int root,int l,int r,int arr[])
{
    if (l==r)
    {
        sgm[root]=arr[l];
        return ;
    }
    int m=(l+r)/2;
    build(2*root+1,l,m,arr);
    build(2*root+2,m+1,r,arr);
    sgm[root]=max(sgm[2*root+1],sgm[2*root+2]);
}
void update(int root,int l,int r,int id,int value)
{
    if (id<l || id >r || l>r) return;
    if (l==r) 
    {
        sgm[root]=value;
        return;
    }
    int m=(l+r)/2;
    update(root*2+1,l,m,id,value);
    update(2*root+2,m+1,r,id,value);
    sgm[root]=max(sgm[2*root+1],sgm[2*root+2]);
}
int get(int root,int l,int r,int low,int hight)
{
    if (l>r || hight<l || low>r) return INT_MIN;
    if (low<=l && hight>=r) return sgm[root];
    int m=(l+r)/2;
    return max(get(2*root+1,l,m,low,hight),get(2*root+2,m+1,r,low,hight));
}
main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    memset(sgm,INT_MIN,sizeof(sgm));
    int n;std::cin >> n;
    int arr[n];
    for (int &x:arr) std::cin >> x;
    build(0,0,n-1,arr);
    int q;std::cin>>q;
    while (q--)
    {
        int step,a,b;cin >> step >> a >> b;
        if (step==1) update(0,0,n-1,a-1,b);
        else cout<< get(0,0,n-1,a-1,b-1) << endl;
    }
    return 0;
}
