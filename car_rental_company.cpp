//Louay Farah
//l.farah@innopolis.university
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second
 
struct City
{
    string name;
    ll penalty;
 
    City()
    {
        name = "";
        penalty = -1;
    }
 
    bool operator==(const City &c) const
    {
        return name == c.name;
    }
 
    bool operator<(const City &c) const
    {
        return name < c.name;
    }
 
    bool operator<=(const City &c) const
    {
        return name <= c.name;
    }
 
    bool operator>(const City &c) const
    {
        return name > c.name;
    }
 
    bool operator>=(const City &c) const
    {
        return name >= c.name;
    }
};
 
struct CityHash
{
    template <typename V> size_t operator() (const V &city) const
    {
        size_t h = hash<string>()(city.name);
        return h;
    }
};
 
 
template <typename T> class MinHeap
{
private:
    vector<T> heap;
    int capacity;
    int size;
    T INIT;
public:
    MinHeap()
    {
        capacity = 0;
        size = 0;
    }
 
    MinHeap(int capacity, T miniInit)
    {
        this->capacity = capacity;
        size = 0;
        INIT = miniInit;
        heap.assign(capacity, INIT);
    }
 
    int parent(int x)
    {
        return (x-1)/2;
    }
 
    int left(int x)
    {
        return 2*x+1;
    }
 
    int right(ll x)
    {
        return 2*x+2;
    }
 
    T mini()
    {
        return heap[0];
    }
 
    void heapify(int beg)
    {
        int target = beg;
 
        if(left(beg) < size && heap[left(beg)] < heap[beg])
        {
            target = left(beg);
        }
 
        if(right(beg) < size && heap[right(beg)] < heap[target])
            target = right(beg);
 
        if(target != beg)
        {
            swap(heap[target], heap[beg]);
            heapify(target);
        }
    }
 
    void deleteMin()
    {
        if(size == 0)
            return;
 
        if(size == 1)
        {
            heap[0] = INIT;
            size--;
            return;
        }
 
        heap[0] = heap[size-1];
        size--;
        heapify(0);
    }
 
    void insert(T x)
    {
        if(size >= capacity)
        {
            return;
        }
 
        size++;
        int curr = size-1;
        heap[curr] = x;
 
        while(curr != 0 && heap[parent(curr)] > heap[curr])
        {
            swap(heap[parent(curr)], heap[curr]);
            curr = parent(curr);
        }
    }
 
    bool empty()
    {
        return size == 0;
    }
};
 
template<typename V, typename E, typename H> class Graph
{
private:
    int graphSize;
    int nbEdges;
    vector<pair<E, pair<V, V>>> el;
    unordered_map<V, vector<pair<V, E>>, H> adj;
    vector<V> nodes;
    E INIT;
public:
    unordered_map<string, V> cityOf;
    unordered_map<ll, V> cityWithRank;
    unordered_map<V, ll, H> indexOf;
 
    Graph(E INIT)
    {
        graphSize = 0;
        nbEdges = 0;
        this->INIT = INIT;
    }
 
    void insertNode(V node)
    {
        nodes.pb(node);
        cityOf[node.name] = node;
        graphSize++;
        indexOf[node] = graphSize;
        cityWithRank[graphSize] = node;
    }
 
    void insertEdge(V a, V b, E w)
    {
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
        el.pb(mp(w, mp(a, b)));
 
        nbEdges++;
    }
 
    vector<pair<V, V>> primForest()
    {
        vector<bool> visited(graphSize+1, false);
        MinHeap<pair<E, pair<ll, ll>>> pq(1e5+5, mp(INIT, mp(0, 0)));
        vector<pair<V, V>> res;
        for(auto beg: nodes)
        {
            if(visited[indexOf[beg]])
                continue;
 
            pq.insert(mp(0.0, mp(indexOf[beg], -1)));
 
            while(!pq.empty())
            {
                ll u = pq.mini().se.fi;
                ll p = pq.mini().se.se;
 
 
                pq.deleteMin();
 
                if(visited[u])
                    continue;
                visited[u] = true;
 
                //add edge
                if(p != -1)
                    res.pb(mp(cityWithRank[p], cityWithRank[u]));
 
                for(auto v: adj[cityWithRank[u]])
                {
                    pq.insert(mp(v.se, mp(indexOf[v.fi], u)));
                }
            }
        }
 
        return res;
    }
};
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Graph<City, double, CityHash> graph(1e9);
 
    ll n;
    cin >> n;
 
 
    while(n--)
    {
        string command;
        cin >> command;
 
        if(command == "ADD")
        {
            string name;
            ll penalty;
            cin >> name >> penalty;
 
 
            City temp;
            temp.name = name;
            temp.penalty = penalty;
 
            graph.insertNode(temp);
        }
        if(command == "CONNECT")
        {
            string a, b;
            ll d;
            cin >> a >> b >> d;
 
            double w = double(d)/(graph.cityOf[a].penalty+graph.cityOf[b].penalty);
 
            graph.insertEdge(graph.cityOf[a], graph.cityOf[b], w);
        }
        if(command == "PRINT_MIN")
        {
            vector<pair<City, City>> res = graph.primForest();
 
            for(auto p: res)
            {
                cout << p.fi.name << ':' << p.se.name << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
