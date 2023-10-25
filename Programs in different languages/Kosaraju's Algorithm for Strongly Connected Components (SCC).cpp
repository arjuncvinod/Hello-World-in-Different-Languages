class Solution
{
    private:
    void dfs(int node,stack<int>&st,vector<int>&vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,st,vis,adj);
            }
        }
        st.push(node);
    }
    
    void RevDfs(int node,vector<int>&vis,vector<int> transpose[]){
        vis[node]=1;
        for(auto it:transpose[node]){
            if(!vis[it]){
                RevDfs(it,vis,transpose);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // step 1 -> finding an order based on dcreasing finishing time 
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,st,vis,adj);
            }
        }
        // step 2 -> reversing the edges
        vector<int> transpose[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it: adj[i]){
                transpose[it].push_back(i);
            }
        }
        int cnt=0;
        while(!st.empty()){
          int node=st.top();
          st.pop();
          if(!vis[node]){
              cnt++;
              RevDfs(node,vis,transpose);
          }
        }
        return cnt;
    }
