//Louay Farah
#include <bits/stdc++.h>
 
using namespace std;
 
 
void selectionSort(pair<int, string> players[], int n, int k)
{
    int limit = min(n, k);
 
    for(int i = 0; i<limit; i++)
    {
        int mini = i;
        for(int j = i+1; j<n; j++)
        {
            if(players[mini].first < players[j].first)
            {
                mini = j;
            }
        }
 
        if(mini != i)
        {
            swap(players[i], players[mini]);
        }
    }
}
 
int main()
{
    int n, k;
    cin >> n >> k;
 
    pair<int, string> players[n];
    for(int i = 0; i<n; i++)
    {
        int score;
        string player;
 
        cin >> player >> score;
 
        players[i] = make_pair(score, player);
    }
 
    selectionSort(players, n, k);
 
    for(int i = 0; i<min(n, k); i++)
    {
        cout << players[i].second << ' ' << players[i].first << endl;
    }
 
    return 0;
}