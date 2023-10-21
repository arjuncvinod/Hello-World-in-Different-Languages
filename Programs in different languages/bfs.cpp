void helperBFS(vector<int>adj[],int s,vector<boo>&visited){
queue<int>q;
visited[s]=true;
  q.push(s);
  while(!q.empty()){
  int v=q.front();
    q.pop();
    cout<<v<<" ";
    for(int v:adj[u]){
    if(visited[v]==false){
    visited[v]=true;
      q.push(v);
    }
    }
  }

}


void BFS(vector<int>adj[],intv){
  vector<bool>visited(v,false);
  for(int i=0;i<v;i++){
    if(visited[i]==false){
      helperBFS(adj,i,visited);
    }
  }
}
