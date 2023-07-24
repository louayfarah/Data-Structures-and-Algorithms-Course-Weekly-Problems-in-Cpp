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
 
template <typename V, typename E> class Graph
{
private:
    int n; //Number of nodes
    unordered_map<V, vector<pair<V, E>>> adj; //adjacency map
public:
    Graph()
    {
        n = 0;
    }
 
    Graph(int n0)
    {
        n = n0;
    }
 
    //Construct the graph given an adjacency matrix
    Graph(int n0, vector<vector<E>>& grid)
    {
        n = n0;
 
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(grid[i][j])
                {
                    adj[i].pb(mp(j, grid[i][j]));
                }
            }
        }
    }
 
    void setNumberOfNodes(int n0)
    {
        n = n0;
    }
 
    void addDirectedEdge(V a, V b, E w)
    {
        adj[a].pb(mp(b, w));
    }
 
    void addUndirectedEdge(V a, V b, E w)
    {
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
 
    void dfs(V u, unordered_map<V, bool>& visited)
    {
        if(visited[u])
            return;
        visited[u] = true;
 
        for(auto v: adj[u])
        {
            dfs(v.fi, visited);
        }
    }
 
    //Returns true if the graph is connected, and false else
    //We check the connectivity of this graph by counting the number of its components.
    //The graph is connected if and only if the number of components is equal to 1
    bool isConnected()
    {
        unordered_map<V, bool> visited;
 
        int nb_comps = 0;
        for(int i = 1; i<=n; i++)
        {
            if(visited[i])
                continue;
 
            nb_comps++;
 
            dfs(i, visited);
        }
 
        return (nb_comps == 1);
    }
};
 
int main()
{
    int n;
    cin >> n;
 
    vector<vector<int>> grid(n+1, vector<int>(n+1, 0));
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cin >> grid[i][j];
        }
    }
 
    Graph<int, int> graph(n, grid);
 
    if(graph.isConnected())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
 
 
    return 0;
}
