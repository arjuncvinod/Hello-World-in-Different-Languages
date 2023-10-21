/*
problem:  https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1  
for explaination ...better to see video:  1.   https://www.youtube.com/watch?v=uzVUw90ZFIg(striver bhaiya)
                                          2.   https://youtu.be/TL9oORCqHe8 (prince bhaiya)
tc:O(V+E)
sc:O(N) for vis vector+O(n) for dfsVis vector
auxiliary space: O(V)
*/
class Solution

{
public:
    // Function to detect cycle in a directed graph.
    bool checkCycle(int s,vector<int> adj[],vector<bool>&vis,vector<bool>&dfsVis){
        vis[s]=true;
        dfsVis[s]=true;
        for(int u:adj[s]){
            if(!vis[u]){
                if(checkCycle(u,adj,vis,dfsVis))return true;
            }
            else if(dfsVis[u])return true;
        }
        dfsVis[s]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>vis(V,false),dfsVis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i,adj,vis,dfsVis))return true;
            }
        }
        return false;
    }
};
