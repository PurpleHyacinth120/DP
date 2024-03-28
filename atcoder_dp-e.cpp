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
const ll lim = 1e5 + 10;
const ll inf = 1e12;

void solve()
{
    ll n, w;
    cin >> n >> w;
    ll i, j;
    pair<ll, ll> a[n];
    ll sum = 0;
    for(i=0; i<n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[i].ff = x;
        a[i].ss = y;
        sum+=y;
    }
    ll sz = min(sum, lim);
    //cout << sz << "\n";
    ll dp[sz+5];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(i=0; i<n; i++)
    {
        for(j=sz; j>=0; j--)
        {
            if(dp[j]!=-1 && dp[j]+a[i].ff<=w)
            {
                if(dp[j+a[i].ss]==-1)
                {
                    dp[j+a[i].ss] = dp[j]+a[i].ff;
                    //cout << dp[j+a[i].ss] << " " << j+a[i].ss << "\n";
                    continue;
                }
                dp[j+a[i].ss] = min(dp[j]+a[i].ff, dp[j+a[i].ss]);
                //cout << dp[j+a[i].ss] << " " << j+a[i].ss << "\n";
            }
            //cout << dp[j+a[i].ss] << " ";
        }
        //cout << "*********\n";
    }
    ll ans = 0;
    ll wei = -1;
    for(i=0; i<=sz; i++)
    {
        if(dp[i]!=-1)
        {
            ans = i;
            wei = dp[i];
        }
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