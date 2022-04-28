#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

/* 图 */

//返回v和w之间的路径path
void pathGraph(int v, int w, vector<int> &from, vector<int> &path)
{
    stack<int> pathStack;

    int p = from[w];

    while(p != -1 && p != v)
    {
        pathStack.push(p);
        p = from[p];
    }

    if(p != -1)
    {
        path.push_back(v);
        while(!pathStack.empty())
        {
            path.push_back(pathStack.top());
            pathStack.pop();
        }
    }

}

//v和w是否连通
bool isConnected(int v, int w, vector<int> &id)
{
    return id[v] == id[w];
}

/*******************************/
//递归实现图邻接表深度优先遍历，visited记录节点是否遍历，from记录节点间路径，ccount联通分量，id查询是否连通

void __dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &from, vector<int> &id, int ccount, int v)
{
    //遍历v
    //cout<<nodes[v].val;
    visited[v] = true;
    id[v] = ccount;


    for(int i = 0; i < adj[v].size(); i++)
    {
        int w = adj[v][i];
        if(!visited[w])
        {
            from[w] = v;
            __dfs(adj, visited, from, id, ccount, w);
        }
    }

}

void dfsGraph(vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    vector<int> from(adj.size(), -1);
    int ccount = 0;
    vector<int> id(adj.size() - 1, -1);

    //连通图只遍历一遍，不用记录ccount和id
    //if(!visited[i])
        //__dfs(adj, visited, from, i);


    for(int i = 0; i < adj.size(); i++)
    {
        if(!visited[i])
        {
            __dfs(adj, visited, from, id, ccount, i);
            ccount++;
        }
    }

    //遍历后可查询是否连通和路径
    //if(isConnected(v, w))
    //vector<int> path;
    //pathGraph(v, w, from, path);


}

/*******************************/



/*******************************/
//递推实现图邻接表广度优先遍历，visited记录节点是否遍历，from记录节点间路径，ccount联通分量，id查询是否连通


void __bfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &from, vector<int> &id, int ccount, int v)
{
    queue<int> que;

    visited[v] = true;
    id[v] = ccount;
    que.push(v);

    while(!que.empty())
    {
        int p = que.front();
        que.pop();
        //遍历w
        //cout<<w;
        for(int i = 0; i < adj[p].size(); i++)
        {
            int w = adj[p][i];
            if(!visited[w])
            {
                visited[w] = true;
                from[w] = p;
                id[w] = ccount;
                que.push(w);
            }
        }
    }
}


void bfsGraph(vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    vector<int> from(adj.szie(), -1);
    int ccount = 0;
    vector<int> id(adj.size() - 1, -1);




    //连通图只遍历一遍，不用记录ccount和id
    //if(!visited[i])
        //__bfs(adj, visited, from, id, ccount, i);


    for(int i = 0; i < adj.size(); i++)
    {
        if(!visited[i])
        {
            __bfs(adj, visited, from, id, ccount, i);
            ccount++;
        }
    }

    //遍历后可查询是否连通和路径，广度优先遍历的路径是最短路径
    //if(isConnected(v, w))
    //vector<int> path;
    //pathGraph(v, w, from, path);

}


/*******************************/

#endif // GRAPH_H_INCLUDED
