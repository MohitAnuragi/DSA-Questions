class Solution {
public:
  // bfs
    bool bfs(int node,int color,vector<vector<int>> graph,vector<int>&col)
    {
       queue<int> q;
       q.push(node);
       col[node] = color;
       while(!q.empty())
       {
        int Node = q.front();
        q.pop();
        for(auto it : graph[Node])
        {
            if(col[it] == -1)
            {
                q.push(it);
                col[it] = !col[Node];
            }
            else if(col[it] == col[Node]) return false;
        }

       }
       return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        // making adj
        // vector<int> adj[n];
        // for(auto it : graph)
        // {
        //     int u = it[0];
        //     int v = it[1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

        vector<int> col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(col[i] == -1)
            {
                if(bfs(i,0,graph,col) == false)
                return false;
            }
        }
        return true;
    }
};