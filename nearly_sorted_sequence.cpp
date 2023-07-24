//Louay Farah
#include "bits/stdc++.h"
 
using namespace std;
 
void bubbleSort(int arr[], int n)
{
    bool swapped = true;
 
    while(swapped)
    {
        swapped = false;
 
        for(int i = 0; i<n-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
    }
}
 
int main()
{
    int n;
    cin >> n;
 
    int arr[n];
    for(int i = 0; i<n; i++)
        cin >> arr[i];
 
    bubbleSort(arr, n);
 
    for(auto elt: arr)
    {
        cout << elt << ' ';
    }
    cout << endl;
 
    return 0;
}