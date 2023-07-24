//Louay Farah
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second
 
vector<int> res;
vector<int> curr;
string last = "";
 
vector<vector<bool>> dp(100001, vector<bool>(1001, false));
 
void solve(int i, int last_word, int n, int k, vector<string> &words, string &token)
{
    if(i == k)
    {
        if(last.empty())
            res = curr;
        return;
    }
 
    if(dp[i][last_word+1])
    {
        return;
    }
 
    last.pb(token[i]);
    dp[i][last_word+1] = true;
 
    solve(i+1, last_word, n, k, words, token);
 
 
    for(int j = 0; j<n; j++)
    {
        string elt = words[j];
        int len = int(elt.length());
 
        if(len != int(last.length()))
            continue;
 
        if(elt == last)
        {
            dp[i][j+1] = true;
            string temp = last;
            last = "";
            curr.pb(j);
            solve(i+1, j, n, k, words, token);
            curr.pop_back();
            last = temp;
        }
    }
 
    last.pop_back();
}
 
int main()
{
    int n, k;
    cin >> n >> k;
 
    vector<string> words;
 
    for(int i = 0; i<n; i++)
    {
        string s;
        cin >> s;
 
        words.pb(s);
    }
 
    string token;
    cin >> token;
 
    solve(0, 0, n, k, words, token);
 
    for(auto elt: res)
        cout << words[elt] << ' ';
    cout << endl;
 
    return 0;
}
