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

    void Dfs()
    {
        map<T, bool> visited;

        // Mark all node as a begning.
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        // Calling the helper function

        // Iterate over all the vertices and init a dfs call
        int cnt = 0;
        for (auto p : l)
        {
            T node = p.first;

            if (!visited[node])
            {
                cout << "Component " << cnt << "--> ";
                Dfs_Helper(node, visited);
                cnt++;
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(8, 8);

    g.Dfs();
    return 0;
}