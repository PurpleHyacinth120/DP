#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>

ll sol(int x, vector<int>&dp, int h[])
{
    if(x<=1)
        return 0;
    if(x==2)
        return abs(h[1]-h[0]);
    if(dp[x]!=-1)
        return dp[x];
    dp[x] = min(sol(x-1, dp, h)+abs(h[x-1]-h[x-2]),sol(x-2, dp, h)+abs(h[x-1]-h[x-3]));    
    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int h[n];
    int i;
    for(i=0; i<n; i++)
        cin >> h[i];
    vector<int>dp(n+1,-1);
    cout << sol(n, dp, h) << "\n";
}