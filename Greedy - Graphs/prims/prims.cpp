#include <bits/stdc++.h>
using namespace std;

pair<int, vector<pair<int,int>>> spanningTree(int V, vector<vector<int>> adj[]) {
    
    // {weight, node, parent}
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    
    vector<int> vis(V, 0);
    vector<pair<int,int>> mst_edges;
    
    pq.push({0, 0, -1}); // start from node 0
    
    int sum = 0;
    
    while(!pq.empty()) {
        auto [wt, node, parent] = pq.top();
        pq.pop();
        
        if(vis[node]){
            continue;
        }
        vis[node] = 1;
        sum += wt;
        
        // store the edge (ignore first dummy edge)
        if(parent != -1) {
            mst_edges.push_back({parent, node});
        }
        
        for(auto it : adj[node]) {
            int adjNode = it[0];
            int edW = it[1];
            
            if(!vis[adjNode]) {
                pq.push({edW, adjNode, node});
            }
        }
    }
    
    return {sum, mst_edges};
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
    
    auto result = spanningTree(V, adj);
    
    cout << "MST Weight: " << result.first << endl;
    
    cout << "MST Edges:\n";
    for(auto it : result.second) {
        cout << it.first << " - " << it.second << endl;
    }
    
    return 0;
}