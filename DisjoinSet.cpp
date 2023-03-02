#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//find_by_order(pos)->giá trị vị trí thứ pos
//order_of_key(x) -> số số nhỏ hơn x?
//lower_bound(x) ->phần tử đầu tiên >=x
//upper_bound(x) ->phần tử đầu tiên > x
//decltype
//ki tu sang chuoi : string(1,c);c la ki tu
#define ll long long int
const int mod=1e9+7;
struct my_hash {
    uint32_t operator()(const vector<int> &V) const {
        uint32_t hash = V.size();
        for(auto &i : V) {
            hash ^= i +0x9e3779b97f4a7c15 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
class DisjoinSet
{
    vector<int>rank,parent,size;
    public:
        DisjoinSet(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for (int i=1;i<=n;i++)
                parent[i]=i;
        }
        int FindParent(int node)
        {
            if (node==parent[node]) return node;
            return parent[node]=FindParent(parent[node]);
        }
        void UnionByRank(int u,int v)
        {
            int par_u=FindParent(u);
            int par_v=FindParent(v);
            if (par_u==par_v) return;
            if (rank[par_u]<rank[par_v]) parent[par_u]=par_v;
            else if (rank[par_u]>rank[par_v]) parent[par_v]=par_u;
            else {
                parent[par_u]=par_v;
                rank[par_v]++;
            }
        }
        void UnionBySize(int u,int v)
        {
            int par_u=FindParent(u);
            int par_v=FindParent(v);
            if (par_u==par_v) return;
            if (size[par_u]<size[par_v]) 
            {
                parent[par_u]=par_v;
                size[par_v]+=size[par_u];
            }
            else
            {
                parent[par_v]=par_u;
                size[par_u]+=size[par_v];
            }
        }
};
bool prime(ll n)
{
	if (n <= 1)
		return false;
	if (n == 2 or n == 3)
		return true;
	if (n % 2 == 0 or n % 3 == 0)
		return false;
	for (ll i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}
size_t Power(size_t a,size_t b,size_t mod)
{
    a%=mod;
    size_t result = 1; 
	while (b) { 
		if (b&1) 
			result = result * a % mod; 
		b/=2;
		a = a * a % mod; 
	} 
	return result; 
}
vector<int>min_prime;
void sang_nt(int n)
{
	min_prime.resize(n+1,0);
	for (int i=2;i*i<=n;i++)
		if (min_prime[i]==0)
			for (int j=i*i;j<=n;j+=i) 
		        if (min_prime[j]==0) min_prime[j]=i;
	for (int i=2;i<=n;i++)
	    if (min_prime[i]==0) min_prime[i]=i;
}
int main()
{
    DisjoinSet ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(4,5);
    return 0;
}