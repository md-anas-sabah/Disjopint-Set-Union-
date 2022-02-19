#include<bits/stdc++.h>
using namespace std;

class DisjointSet{

    int *rank , *parent , n;

public:

    // Constructor to create or initialize sets of n items.
    DisjointSet(int n){
        rank = new int[n];
        parent = new int [n];
        this->n=n;
        makeSet();
    }

    //create n Single item set.
    void makeSet()
    {
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
     // Finds set of given item x
    int find(int x){
        if(parent[x]!=x){
            parent[x]= find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x , int y){
        int xSet= find(x);
        int ySet= find(y);

        if(xSet == ySet)
            return;

        if(parent[xSet] < parent[ySet] ){
            parent[xSet] = ySet;
        }else if(parent[ySet] < parent[xSet]){
            parent[ySet] = xSet;
        }else{
            parent[ySet]= xSet;
            rank[xSet] = rank[xSet] + 1;
        }
    }
};


int main()
{   
  DisjointSet obj(5);
    obj.Union(0, 2);
    obj.Union(4, 2);
    obj.Union(3, 1);
    if (obj.find(4) == obj.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (obj.find(1) == obj.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
  
    return 0;

}