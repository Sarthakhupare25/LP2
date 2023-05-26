#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

class Graph
{
public:
    void DFS(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        cout << node << " ";
        for (auto &i : adj[node])
        {
            if (!vis[i])
            {
                DFS(i, adj, vis);
            }
        }
    }

    void BFS(queue<int> &q, vector<int> adj[], vector<int> &vis)
    {
        if (q.empty())
        {
            return;
        }
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto &i : adj[node])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
        }
        BFS(q, adj, vis);
    }
};

int main()
{
    int n;
    cout << "Enter the Number of Vertex - ";
    cin >> n;
    int e;
    cout << "Enter the Number of Edges - ";
    cin >> e;
    vector<int> adj[n];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter the v1 and v2 - ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<endl;
    int ch;
    vector<int> vis(n, 0);
    Graph g;
    queue<int> q;
    while (1)
    {
        cout << "1.DFS - ";
        cout << "2.BFS - ";
        cout << "Enter choice - ";
        cin >> ch;
        if (ch == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    g.DFS(i, adj, vis);
                }
            }
            cout<<endl;
        }
        else if (ch == 2)
        {
            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                    g.BFS(q, adj, vis);
                }
            }
            cout<<endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}