#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void Dfs_Helper(T src, map<T, bool> &visited)
    {
        cout << src << "    ";
        visited[src] = true;
        // Go to all node of src which are not  visted till
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                Dfs_Helper(nbr, visited);
            }
        }
    };

    void Dfs(T src)
    {
        map<T, bool> visited;
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        // Calling the helper function
        Dfs_Helper(src, visited);
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 0);

    g.Dfs(0);
    return 0;
}