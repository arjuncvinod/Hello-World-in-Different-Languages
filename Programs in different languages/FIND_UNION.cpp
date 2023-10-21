#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,0)
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
  
  //parent find
    int FindUParent(int node){
        if(node==parent[node])return node ;
      return  parent[node]=FindUParent(parent[node]);
    }
  
  //union
    
    void FindUnionByRank(int u,int v){
        int ulP_u=FindUParent(u);
        int ulP_v=FindUParent(v);
        if(ulP_v==ulP_u)return;
        if(rank[ulP_v]<rank[ulP_u]){
            parent[ulP_v]=ulP_u;
        }
       else if(rank[ulP_v]>rank[ulP_u]){
            parent[ulP_u]=ulP_v;
        }
        else{
             parent[ulP_u]=ulP_v;
             rank[ulP_v]++;
        }
    }
    void FindUnionBySize(int u,int v){
        int ulP_u=FindUParent(u);
        int ulP_v=FindUParent(v);
        if(ulP_v==ulP_u)return;
        if(rank[ulP_v]<rank[ulP_u]){
            parent[ulP_v]=ulP_u;
            size[ulP_u]+=size[ulP_v];
        }
       
        else{
            parent[ulP_u]=ulP_v;
            size[ulP_v]+=size[ulP_u];
        }
    }
};
    
