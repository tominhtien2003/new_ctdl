// #include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

// vector<int>sgm(4*100005,INT_MIN),a(100005),lazy(4*100005);
// void build(int root,int left,int right)
// {
//     //if (left>right) return;
//     if (left==right)
//     {
//         sgm[root]=a[left];
//         return;
//     }
//     int middle=(left+right)/2;
//     build(2*root+1,left,middle);
//     build(2*root+2,middle+1,right);
//     sgm[root]=max(sgm[2*root+1],sgm[2*root+2]);
// }
// int query(int root,int left,int right,int l,int r)
// {
//     if (right<l || left>r) return INT_MIN;
//     if (l<=left && r>=right) return sgm[root];
//     int middle=(left+right)/2;
//     return max(query(2*root+1,left,middle,l,r),query(2*root+2,middle+1,right,l,r));
// }
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i=0;i<n;i++) cin >> a[i];
//     build(0,0,n-1);
//     int q;cin >> q;
//     while (q--)
//     {
//         int l,r;
//         cin >> l >> r;
//         cout << query(0,0,n-1,l,r) << endl;
//     }
//     return 0;
// }
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

vector<int>sgm(4*100005,0),a(100005),lazy(4*100005,0);
void build(int root,int left,int right)
{
    if (left==right)
    {
        sgm[root]=a[left];
        return;
    }
    int middle=(left+right)/2;
    build(2*root+1,left,middle);
    build(2*root+2,middle+1,right);
    sgm[root]=sgm[2*root+1]+sgm[2*root+2];
}
void update(int root,int left,int right,int l,int r,int val)
{
    if (lazy[root]!=0)//kiem tra xem truoc do da cap nhat chua
    {
        sgm[root]+=(right-left+1)*lazy[root];
        if (left!=right) //kiem tra xem co phai la nut la ko
        {
            lazy[2*root+1]+=lazy[root];
            lazy[2*root+2]+=lazy[root];
        }
        lazy[root]=0;
    }
    if (r<left || l>right || left>right) return;
    if (left>=l && right<=r)
    {
        sgm[root]=(right-left+1)*val;
        if (left!=right)
        {
            lazy[2*root+1]+=val;
            lazy[2*root+2]+=val;
        }
        return;
    }
    int middle=(left+right)/2;
    update(2*root+1,left,middle,l,r,val);
    update(2*root+2,middle+1,right,l,r,val);
    sgm[root]=sgm[2*root+1]+sgm[2*root+2];
}
int query(int root,int left,int right,int l,int r)
{
    if (lazy[root]!=0)
    {
        sgm[root]+=(right-left+1)*lazy[root];
        if (left!=right)
        {
            lazy[2*root+1]+=lazy[root];
            lazy[2*root+2]+=lazy[root];
        }
        lazy[root]=0;
    }
    if (r<left || l>right || left>right) return 0;
    if (left>=l && right<=r) return sgm[root];
    int middle=(left+right)/2;
    return query(2*root+1,left,middle,l,r)+query(2*root+1,middle+1,right,l,r);
}
int main()
{
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    build(0,0,n-1);
    int q;cin >> q;
    while (q--)
    {
        int l,r;
        cin >> l >> r;
    }
    return 0;
}