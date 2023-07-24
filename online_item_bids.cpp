//Louay Farah
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second
 
struct Bid
{
    int minimum_bid;
    int maximum_bid;
    int position;
};
 
void ascending_counting_sort(vector<Bid> &arr, int n)
{
    vector<int> counting(100001, 0);
    vector<int> pref(100001, 0);
 
    for(int i = 0; i<n; i++)
    {
        counting[arr[i].maximum_bid]++;
    }
 
    pref[0] = counting[0];
    for(int i = 1; i<=100000; i++)
    {
        pref[i] = pref[i-1] + counting[i];
    }
 
    vector<Bid> output(n);
    for(int i = n-1; i>=0; i--)
    {
        output[pref[arr[i].maximum_bid]-1] = arr[i];
        pref[arr[i].maximum_bid]--;
    }
 
    arr = output;
}
 
void descending_counting_sort(vector<Bid> &arr, int n)
{
    vector<int> counting(101, 0);
    vector<int> pref(101, 0);
 
    for(int i = 0; i<n; i++)
    {
        counting[arr[i].minimum_bid]++;
    }
 
    pref[0] = counting[0];
    for(int i = 1; i<=100; i++)
    {
        pref[i] = pref[i-1] + counting[i];
    }
 
    vector<Bid> output(n);
    for(int i = 0; i<n; i++)
    {
        output[n-pref[arr[i].minimum_bid]] = arr[i];
        pref[arr[i].minimum_bid]--;
    }
 
    arr = output;
}
 
int main()
{
    int n;
    cin >> n;
 
    vector<Bid> arr(n);
    for(int i = 0; i<n; i++)
    {
        arr[i].position = i+1;
        cin >> arr[i].minimum_bid >> arr[i].maximum_bid;
    }
 
    ascending_counting_sort(arr, n); // according to the maximum bid
    descending_counting_sort(arr, n);// according to the minimum bid
 
    for(int i = 0; i<n; i++)
    {
        cout << arr[i].position << ' ';
    }
 
    cout << endl;
 
    return 0;
}
