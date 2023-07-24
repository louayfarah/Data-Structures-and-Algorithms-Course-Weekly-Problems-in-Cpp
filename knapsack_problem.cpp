//Louay Farah
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second
 
vector<vector<int>> dp(1001, vector<int>(10001, -1));
 
int solve(int i, int j, int n, int total_w, vector<int> &w, vector<int> &c)\
{
    if(i == -1)
    {
        return 0;
    }
 
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
 
    int res = 0;
 
    res = max(res, solve(i-1, j, n, total_w, w, c));
 
    if(j-w[i] >= 0)
    {
        res = max(res, solve(i-1, j-w[i], n, total_w, w, c) + c[i]);
    }
 
    return dp[i][j] = res;
}
 
 
int main()
{
    int n, total_w;
    cin >>n  >> total_w;
 
    vector<int> w(n);
    for(int i = 0; i<n; i++)
        cin >> w[i];
 
    vector<int> c(n);
    for(int i= 0; i<n; i++)
        cin >> c[i];
 
    int res = solve(n-1, total_w, n, total_w, w, c);
 
 
    vector<int> s;
 
    int curr_w = total_w;
    for(int i = n-1; i>0; i--)
    {
        if(dp[i][curr_w] == dp[i-1][curr_w])
        {
            continue;
        }
 
        s.pb(i+1);
 
        curr_w -= w[i];
    }
 
    if(curr_w >= w[0])
    {
        s.pb(1);
    }
 
    cout << int(s.size()) << endl;
    for(int i = int(s.size())-1; i>=0; i--)
    {
        cout << s[i] << ' ';
    }
    cout << endl;
 
    return 0;
}
