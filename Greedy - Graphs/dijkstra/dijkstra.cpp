#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    
    // {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    vector<int> dist(V, 1e9);
    
    dist[S] = 0;
    pq.push({0, S});
    
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        
        int d = it.first;
        int node = it.second;
        
        for(auto it : adj[node]) {
            int adjNode = it[0];
            int wt = it[1];
            
            // relaxation
            if(d + wt < dist[adjNode]) {
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    
    return dist;
}

int main() {
    int V = 5;
    vector<vector<int>> adj[V];
    
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});
    
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    
    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});
    
    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});
    
    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});
    
    int S = 0;
    vector<int> dist = dijkstra(V, adj, S);
    
    cout << "Shortest distances from source:\n";
    for(int i = 0; i < V; i++) {
        cout << i << " -> " << dist[i] << endl;
    }
    
    return 0;
}