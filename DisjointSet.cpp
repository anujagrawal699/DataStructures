#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    private:
    vector<int> parent, rank, size;

    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        rank.resize(n+1, 0);
        for(int i =0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int uParent = findParent(u);
        int vParent = findParent(v);
        if(uParent==vParent) return;
        if(size[uParent] < size[vParent]){
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
    } else {
        parent[vParent] = uParent;
        size[uParent] += size[vParent];
    }
    }

    void unionByRank(int u, int v){
        int uParent = findParent(u);
        int vParent = findParent(v);
        if(uParent==vParent) return;
        if(rank[uParent]<rank[vParent]){
            parent[uParent] = vParent;
        } else if (rank[vParent] < rank[uParent]){
            parent[vParent] = uParent;
        } else {
            parent[uParent] = vParent;
            rank[vParent]++;
        }
    }


};

int main(){
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    cout << ds.findParent(1) << endl;
    cout << ds.findParent(2) << endl;
    cout << ds.findParent(3) << endl;
    cout << ds.findParent(4) << endl;
}