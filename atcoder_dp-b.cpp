#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>

ll sol(int x, vector<int>&dp, int h[], int k)
{
    if(x<=1)
        return 0;
    if(x==2)
        return abs(h[1]-h[0]);
    if(dp[x]!=-1)
        return dp[x];
    ll minim = LLONG_MAX;
    for(int i = 1; i<=k; i++)
    {
        if(x-i-1>=0)
            minim = min(minim, sol(x-i, dp, h, k)+abs(h[x-1]-h[x-i-1]));
    }
    dp[x] = minim;    
    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int h[n];
    int i;
    for(i=0; i<n; i++)
        cin >> h[i];
    vector<int>dp(n+1,-1);
    cout << sol(n, dp, h, k) << "\n";
}