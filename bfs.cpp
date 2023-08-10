    int n;
    cin >> n;
    vector < vector < int > > adj(n + 1);
    for(int i = 0 ; i < n - 1 ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector < int > ans , vis(n + 5);

    auto bfs = [&](){
        queue < int > q;
        q.push(1);
        vis[1] = 1;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto & child : adj[node]){
                if(!vis[child]){
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }

    };
