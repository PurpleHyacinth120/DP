#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll dp[n][3];
    ll x, y, z;
    cin >> x >> y >> z;
    dp[0][0] = x;
    dp[0][1] = y;
    dp[0][2] = z;
    int i, j;
    for(i=1; i<n; i++)
    {
        cin >> x >> y >> z;
        for(j=0; j<3; j++)
        {
            if(j==0)
                dp[i][j] = max(dp[i-1][1], dp[i-1][2])+x;
            else if(j==1)
                dp[i][j] = max(dp[i-1][0], dp[i-1][2])+y;
            else
                dp[i][j] = max(dp[i-1][0], dp[i-1][1])+z;
        } 
    }
    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << "\n";
}