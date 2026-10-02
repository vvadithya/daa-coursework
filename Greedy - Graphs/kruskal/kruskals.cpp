// common libraries
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class disjointset{
    private:
    vector<int>parent;
    vector<int>size;
    public:
    disjointset(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_ultimate_parent(int x){
        if(parent[x] != x){
            parent[x] = find_ultimate_parent(parent[x]); // path compression
        }

        return parent[x];
    }

    void union_by_size(int x , int y){
        int parent_x = find_ultimate_parent(x);
        int parent_y = find_ultimate_parent(y);
        if(parent_x == parent_y){
            return;
        }
        else if(size[parent_x] < size[parent_y]){
            // put x under y
            parent[parent_x] = parent_y;
            // y has now x more elements,so its size increases
            size[parent_y] += size[parent_x];
        }
        else{
            // put y under x
            parent[parent_y] = parent_x;
            // x has now y more elements,so its size increases
            size[parent_x] += size[parent_y];
        }
    }
};
int main(){

    // sort the adjacency list by weight in kruskals
    vector<pair<int, pair<int,int>>> edges = {
        {2, {0,1}},
        {1, {1,2}},
        {4, {0,2}},
        {3, {1,3}},
        {5, {2,3}},
        {7, {3,4}}
    };
    sort(edges.begin() , edges.end());
    int mst_sum = 0;
    int V = 100;
    disjointset ds(V);
    vector<pair<int,int>>mst_edges;

    for(auto &it : edges){
        int weight = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.find_ultimate_parent(u) != ds.find_ultimate_parent(v)){
            // if equalmeans alr connected component in graph
            // thats why take inequality
            mst_sum += weight;
            mst_edges.push_back({u , v});
            ds.union_by_size(u , v);
        }
    }

    cout << "Minimum Spanning tree sum is: " << mst_sum << endl;
    for(auto &it : mst_edges){
        cout << it.first << " " << it.second << endl;
    }

}
