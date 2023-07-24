#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second
 
template <typename K, typename V> class MyHashMap
{
private:
    int size = 0;
    int capacity = 100;
public:
    vector<vector<pair<K, V>>> table;
    void init();
    int hashFunction(K key);
    void put(K key, V value);
    void remove(K key);
    V get(K key);
    int hashMapSize();
    bool isEmpty();
};
 
 
template <typename K, typename V> void MyHashMap<K, V>::init()
{
    table.assign(capacity, {});
}
 
template <typename K, typename V> int MyHashMap<K, V>::hashFunction(K key)
{
    int x = 0;
    for(auto elt: key)
    {
        x = ((x%capacity) + (elt%capacity))%capacity;
    }
 
    return x%capacity;
}
 
template <typename K, typename V> void MyHashMap<K, V>::put(K key, V value)
{
    int index = MyHashMap::hashFunction(key);
    MyHashMap::remove(key);
    MyHashMap::table[index].push_back(mp(key, value));
}
 
template <typename K, typename V> void MyHashMap<K, V>::remove(K key)
{
    int index = MyHashMap::hashFunction(key);
    if(!MyHashMap::table[index].empty())
    {
        for(int i = 0; i<int(MyHashMap::table[index].size()); i++)
        {
            if(MyHashMap::table[index][i].fi == key)
            {
                MyHashMap::table[index].erase(MyHashMap::table[index].begin()+i);
                break;
            }
        }
    }
}
 
template <typename K, typename V> V MyHashMap<K, V>::get(K key)
{
    int index = MyHashMap::hashFunction(key);
    if(!MyHashMap::table[index].empty())
    {
        for(int i = 0; i<int(MyHashMap::table[index].size()); i++)
        {
            if(MyHashMap::table[index][i].fi == key)
            {
                return MyHashMap::table[index][i].se;
            }
        }
    }
 
    return 0;
}
 
template <typename K, typename V> int MyHashMap<K, V>::hashMapSize()
{
    return MyHashMap::size;
}
 
template <typename K, typename V> bool MyHashMap<K, V>::isEmpty()
{
    return (MyHashMap::size == 0);
}
 
int main()
{
    ll n;
    cin >> n;
 
    MyHashMap<string, int> a;
    a.init();
 
    for(int i = 0; i<n; i++)
    {
        string s;
        cin >> s;
 
        //a[s] = true;
        a.put(s, 1);
    }
 
    ll m;
    cin >> m;
 
    vector<string> b;
    for(int i = 0; i<m; i++)
    {
        string s;
        cin >> s;
 
        b.pb(s);
    }
 
    MyHashMap<string, int> visited;
    visited.init();
 
    vector<string> res;
    for(auto s: b)
    {
        if(visited.get(s))
            continue;
 
        visited.put(s, 1);
 
        if(!a.get(s))
        {
            res.pb(s);
        }
    }
 
    cout << int(res.size()) << endl;
 
    for(auto elt: res)
        cout << elt << endl;
 
    return 0;
}