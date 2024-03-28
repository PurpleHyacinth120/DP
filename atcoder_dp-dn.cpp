#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, w;
    cin >> n >> w;
    pair<ll, ll> a[n];
    int i, tot = 0;
    for(i=0; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].ff = x;//w
        a[i].ss = y;//v
        tot+=x;
    }
    int cap = min(tot, w);
    ll dp[cap+10];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(i=0; i<n; i++)
    {
        for(int j = cap; j>=0; j--)
        {
            if(dp[j]!=-1 && j+a[i].ff<=cap)
                dp[j+a[i].ff] = max(dp[j+a[i].ff], dp[j]+a[i].ss);
        }
    }
    ll ans = 0;
    for(i=0; i<=cap; i++)
    {
        //cout << dp[i] << " " << i << "\n";
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--)
        solve();
}