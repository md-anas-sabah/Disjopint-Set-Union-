#include<bits/stdc++.h>
using namespace std;

class DSU{
    int *parent , *rank;
public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for(int i=0;i<n;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if(parent[x]!=x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y){
        int xSet = find(x);
        int ySet = find(y);

        if(xSet == ySet)
            return;

        if(parent[xSet] < parent[ySet]){
            parent[xSet] = ySet;
        }else if(parent[ySet] < parent[xSet]){
            parent[ySet] = xSet;
        }else{
            parent[ySet] = xSet;
            rank[xSet] = rank[xSet] + 1;
        }
    }
};

class Graph{
    vector<vector<int>> edgeList;
    int V;
public:
    Graph(int V){
        this->V;
    }
    void addEdge(int x , int y, int w ){
        edgeList.push_back({w , x ,y});
    }
    void krushkal_MST(){

        sort(edgeList.begin(),edgeList.end());

        DSU s(V);
        int ans = 0;
        cout<< "Following are the edges in the constructed MST" << endl;

        for (auto edge : edgeList){
            int w =edge[0];
            int x =edge[1];
            int y =edge[2];

            if(s.find(x)!=s.find(y)){
                s.Union(x,y);
                ans +=w;
                cout<< x << "--" << y << "==" << w << endl;
            }
        } 
        cout <<"MST : "<< ans;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
    
    g.krushkal_MST();
    return 0;
}