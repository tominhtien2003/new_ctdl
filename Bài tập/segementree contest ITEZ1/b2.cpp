#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
#define int long long
const int N=4e5+1;
int sgm[N]={};
void update(int root,int l,int r,int id,int value)
{
    if (id<l || id > r || l>r) return;
    if (l==r)
    {
        sgm[root]=value;
        return;
    }
    int m=(l+r)/2;
    update(root*2+1,l,m,id,value);
    update(root*2+2,m+1,r,id,value);
    sgm[root]=sgm[2*root+1]+sgm[2*root+2];
}
int get(int root,int l,int r,int low,int hight)
{
    if (l>hight || l>r || r<low) return 0;
    if (l>=low && r<=hight) return sgm[root];
    int m=(l+r)/2;
    return get(root*2+1,l,m,low,hight)+get(2*root+2,m+1,r,low,hight);
}
main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int n,q;cin >> n >> q;
    while (q--)
    {
        int a,b,c;cin >> a >> b >> c;
        if (a==1) update(0,0,n-1,b-1,c);
        else cout << get(0,0,n-1,b-1,c-1) << endl;
    }
    return 0;
}

