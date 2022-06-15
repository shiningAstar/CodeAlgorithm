#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

/* ͼ */

//����v��w֮���·��path
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
        path.push_back(w);
    }

}

//v��w�Ƿ���ͨ
bool isConnected(int v, int w, vector<int> &id)
{
    return id[v] == id[w];
}

/*******************************/
//�ݹ�ʵ��ͼ�ڽӱ�������ȱ�����visited��¼�ڵ��Ƿ������from��¼�ڵ��·����ccount��ͨ������id��ѯ�Ƿ���ͨ

void __dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &from, vector<int> &id, int ccount, int v)
{
    //����v
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

    //��ͨͼֻ����һ�飬���ü�¼ccount��id
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

    //������ɲ�ѯ�Ƿ���ͨ��·��
    //if(isConnected(v, w))
    //vector<int> path;
    //pathGraph(v, w, from, path);


}

/*******************************/



/*******************************/
//����ʵ��ͼ�ڽӱ������ȱ�����visited��¼�ڵ��Ƿ������from��¼�ڵ��·����ccount��ͨ������id��ѯ�Ƿ���ͨ


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
        //����w
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
    vector<int> from(adj.size(), -1);
    int ccount = 0;
    vector<int> id(adj.size() - 1, -1);




    //��ͨͼֻ����һ�飬���ü�¼ccount��id
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

    //������ɲ�ѯ�Ƿ���ͨ��·����������ȱ�����·�������·��
    //if(isConnected(v, w))
    //vector<int> path;
    //pathGraph(v, w, from, path);

}


/*******************************/

/*******************************/
//�ݹ�ʵ������ͼ�ڽӱ�������ȱ������ж��Ƿ��л�

//visited��¼�ڵ��Ƿ����������״̬��δ�������ڱ����У��ڽӽڵ�δ�����꣩�������������ڽӽڵ�ȫ��������{-1��0��1}
//�����еĽڵ㱻�ٴα�����������ڻ�
/* �����Ľڵ����ڵ�ȫ�������겻�����ǵ�ǰ������·����ǰ��ڵ㣬�����нڵ�һ���ڵ�ǰ������·��ǰ���ĳλ�� */
bool __dfs(vector<vector<int>> &adj, vector<int> &visited, int v)
{
    //����v
    //cout<<nodes[v].val;
    visited[v] = 0;

    for(int i = 0; i < adj[v].size(); i++)
    {
        int w = adj[v][i];

        if(visited[w] == 0)
            return false;

        if(visited[w] != 1 && !__dfs(adj, visited, w))
            return false;
    }
    visited[v] = 1;
    return true;
}

bool dfsGraph(vector<vector<int>> &adj)
{
    vector<int> visited(adj.size(), -1);

    //��ͨͼֻ����һ�飬���ü�¼ccount��id
    //return __dfs(adj, visited, 0);


    for(int i = 0; i < adj.size(); i++)
    {
        if(visited[i] < 1 && !__dfs(adj, visited, i))
            return false;
    }
    return true;

}

/*******************************/

#endif // GRAPH_H_INCLUDED
