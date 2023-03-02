#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
#define int long long
const int N=4e5+1;

main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int n,k;cin >> n >> k;
    deque<int>dq;
    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];
    int dp[n],res=LONG_LONG_MIN;
    memset(dp,LONG_LONG_MIN,sizeof(dp));
    for (int i=0;i<n;i++)
    {
        if (!dq.empty() && (i-dq.front()>k)) dq.pop_front();
        if (!dq.empty()) dp[i]=max(dp[dq.front()]+arr[i],arr[i]);
        else dp[i]=arr[i];
        res=max(res,dp[i]);
        while (!dq.empty() && dp[i]>=dp[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    cout << max(1LL*0,res);
    return 0;
}

