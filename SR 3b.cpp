#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cout << "Enter the Number of Vertex - ";
    cin >> N;
    int m;
    cout << "Enter the Number of Edges - ";
    cin >> m;

    vector<pair<int, int>> adj[N];

    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cout << "Enter the v1,v2 and weight - ";
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    cout << endl;

    int key[N];     // Distances
    bool mstSet[N]; // Visited or not
    int parent[N];

    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        auto u = pq.top();
        pq.pop();

        int nd = u.second;
        int wt = u.first;

        mstSet[nd] = true;
        sum += wt;

        for (auto it : adj[nd])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = nd;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << " - " << i << " \n";
    }
    cout << sum << endl;
    return 0;
}