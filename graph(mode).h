#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

/* 图 */

//返回v和w之间的路径path
void pathGraph(int v, int w, vector<int> &from, vector<int> &path){
    stack<int> pathStack;
    int p = from[w];
    while(p != -1 && p != v){
        pathStack.push(p);
        p = from[p];
    }
    if(p != -1){
        path.push_back(v);
        while(!pathStack.empty()){
            path.push_back(pathStack.top());
            pathStack.pop();
        }
        path.push_back(w);
    }
}

//v和w是否连通
bool isConnected(int v, int w, vector<int> &id){
    return id[v] == id[w];
}

/*******************************/
//递归实现图邻接表深度优先遍历，visited记录节点是否遍历，from记录节点间路径，ccount连通分量，id每个节点连通分量查询是否连通

int n;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> from;
vector<int> id;

void __dfs(int ccount, int v){
    //遍历v
    //cout<<nodes[v].val;
    vis[v] = true;
    id[v] = ccount;
    for(int i = 0; i < adj[v].size(); ++i){
        int w = adj[v][i];
        if(!vis[w]){
            from[w] = v;
            __dfs(ccount, w);
        }
    }
}

void dfsGraph(){
    n = adj.size();
    vis.assign(n, false);
    from.assign(n, -1);
    int ccount = 0;
    id.assign(n, -1);
    //连通图只遍历一遍，不用记录ccount和id
    /*if(!vis[0])
        __dfs(ccount, 0);*/

    for(int i = 0; i < n; ++i)
        if(!vis[i]){
            __dfs(ccount, i);
            ++ccount;
        }
    
    //遍历后可查询是否连通和路径
    //if(isConnected(v, w))
    //vector<int> path;
    //pathGraph(v, w, from, path);
}
/*******************************/



/*******************************/
//递推实现图邻接表广度优先遍历，visited记录节点是否遍历，from记录节点间路径，ccount联通分量，id查询是否连通

int n;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> from;
vector<int> id;

void __bfs(int ccount, int v)
{
    queue<int> que;
    vis[v] = true;
    id[v] = ccount;
    que.push(v);
    while(!que.empty()){
        int p = que.front();
        que.pop();
        //遍历w
        //cout<<w;
        for(int i = 0; i < adj[p].size(); ++i){
            int w = adj[p][i];
            if(!vis[w]){
                vis[w] = true;
                from[w] = p;
                id[w] = ccount;
                que.push(w);
            }
        }
    }
}

void bfsGraph()
{
    n = adj.size();
    vis.assign(n, false);
    from.assign(n, -1);
    int ccount = 0;
    id.assign(n, -1);
    //连通图只遍历一遍，不用记录ccount和id
    /*if(!vis[0])
        __bfs(ccount, 0);*/
    for(int i = 0; i < n; ++i)
        if(!vis[i]){
            __bfs(ccount, i);
            ++ccount;
        }
    //遍历后可查询是否连通和路径，广度优先遍历的路径是最短路径
    //if(isConnected(v, w))
    //vector<int> path;
    //pathGraph(v, w, from, path);
}


/*******************************/


/*******************************/
/* 分层广度优先搜索 */
void bfs(){
    vector<vector<int>> adj;

    /* 层节点遍历，如果层节点需排序可用set，
        如果每次遍历只需拿出最（大/小）值节点，可使用priority_queue不分层 */
    vector<int> ls;
    //set<int> ls;
    //priority_queue<int> ns;

    /* 初始置放第一层节点，如果只第一个为第一层，放0 */
    ls.emplace_back(0);
    //for(;;) ln.emplace_back();
    
    /* 临时存放下一层节点，使用前置换到ls */
    vector<int> lt;
    int n, m;
    int p;
    while(!ls.empty()){
        n = ls.size();
        for(int i = 0; i < n; ++i){
            p = ls[i];
            m = adj[p].size();
            for(int j = 0; j < m; ++j){
                /* 下一层节点放置lt暂存 */
                lt.emplace_back(adj[p][j]);
            }
        }
        /* 一层结束，暂存的下一层节点置换回ls */
        ls.swap(lt);
        lt.clear();
    }
}

/*******************************/


/*******************************/
//递归实现有向图邻接表深度优先遍历，判断是否有环

int n;
vector<vector<int>> adj;  //adj[i] 代表有节点i指向adj[i]的有向边
vector<int> vis;

//vis记录节点是否遍历，三种状态：未遍历、在遍历中（邻接节点未遍历完）、结束遍历（邻接节点全部遍历）{-1，0，1}
//遍历中的节点被再次遍历到，则存在环
/* 结束的节点后面节点全部遍历完不可能是当前遍历中路径的前面节点，遍历中节点一定在当前遍历中路径前面的某位置 */
bool __dfs(int v){
    //遍历v
    //cout<<nodes[v].val;
    vis[v] = 0;
    for(int i = 0; i < adj[v].size(); i++){
        int w = adj[v][i];
        if(vis[w] == 0) return false;
        if(vis[w] == -1 && !__dfs(w)) return false;
    }
    vis[v] = 1;
    return true;
}

bool dfs(){
    n = adj.size();
    vis.assign(n, -1);
    //连通图只遍历一遍，不用记录ccount和id
    //return __dfs(0);
    for(int i = 0; i < n; i++){
        if(vis[i] != 1 && !__dfs(i)) return false;
    }
    return true;
}

/*******************************/

/*******************************/
//递归实现无向图邻接表深度优先遍历，判断是否有环

int n;
vector<vector<int>> adj;  //adj[i] 代表节点i和adj[i]有边连接
vector<int> vis;

//vis记录节点是否遍历，二种状态：未遍历、已遍历遍历（邻接节点全部遍历）{0，1}
//遍历中的节点被再次遍历到，则存在环
/* 全部已节点都可以通当前节点，因为无向边可双向通路遍历，遍历到已遍历节点一定存在环 */
bool __dfs(int v){
    //遍历v
    //cout<<nodes[v].val;
    vis[v] = 1;
    for(int i = 0; i < adj[v].size(); i++){
        int w = adj[v][i];
        if(vis[w]) return false;
        if(!vis[w] && !__dfs(w)) return false;
    }
    return true;
}

bool dfs(){
    n = adj.size();
    vis.assign(n, 0);
    //连通图只遍历一遍
    //return __dfs(0);
    for(int i = 0; i < n; i++){
        if(!vis[i] && !__dfs(i)) return false;
    }
    return true;
}

/*******************************/

/*******************************/
/* 二维表格中移动问题移动数组方式 */

int n;
int m;
vector<vector<int>> g;
vector<vector<bool>> vis;

const int d[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};   //移动数组

void dfs(int i, j){
    //执行点遍历
    //if(g[i][j]?) return;   //移动终止条件
    int ni, nj;
    for(int k = 0; k < 4; ++k){
        ni = d[k][0] + i; nj = d[k][1] + j;
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]){   //判断下一步移动点条件
            vis = true;
            dfs(i, j);
        }
    }
}

void moveinGrid(vector<vector<int>> grid){
    g.swap(grid);
    n = g.size();
    m = g[0].size();
    vis.assign(n, vector<bool>(m, false));
    dfs(0, 0);
}


/*******************************/



/*******************************/
/* 有向无环图DAG拓扑排序 */

    vector<vector<int>> a;
    int n;
    vector<int> o;
    //vector<int> np;     //记录节点到顺序位置

    bool topo(){
        /* 入度为0的顶点队列 */
        queue<int> ns;
        /* 每个顶点入度数 */
        vector<int> ni(n, 0);         //节点号0~n-1
        //vector<int> ni(n + 1, 0);   //节点号1~n

        int vn;
        int node;
        //int c = 0;    //记录节点到顺序位置时，使用当前位置

        for(int i = 0; i < n; ++i){     //节点号0~n-1
        //for(int i = 1; i <= n; ++i){   //节点号1~n
            auto &v = a[i]; vn = v.size();
            for(int j = 0; j < vn; ++j) ++ni[v[j]];
        }

        for(int i = 0; i < n; ++i) if(ni[i] == 0) ns.emplace(i);     //节点号0~n-1
        //for(int i = 1; i <= n; ++i) if(ni[i] == 0) ns.emplace(i);  //节点号1~n

        while(!ns.empty()){
            node = ns.front(); ns.pop();
            /* 入度为0排在剩下顶点的最前面 */
            o.emplace_back(node);
            //np[node] = c; ++c;    //记录节点到当前位置
            /* 删除已排序顶点的出度对应顶点的入度，再把删除后入度为0顶点加入队列 */
            auto &v = a[node]; vn = v.size();
            for(int j = 0; j < vn; ++j) {
                int &vj = v[j];
                int &vjni = ni[vj];
                --vjni;
                if(vjni == 0) ns.emplace(vj);
            }
        }

        if(o.size() < n/* c < n *//* 记录节点到当前位置时 */) return false;
        return true;
    }

    void topo_init(int noden, vector<vector<int>> p){
        n = noden;
        a.assign(n);        //节点号0~n-1
        //a.assign(n + 1);  //节点号1~n
        np.assign(n);       //节点号0~n-1
        //np.assign(n + 1);   //节点号1~n
        int pn = p.size();
        for(int i = 0; i < pn; ++i) a[p[i][0]].emplace_back(p[i][1]);
        if(topo()){
            /* 排序正常，对结果o操作 */
            
        } else {
            /* 排序不正常，图中有环 */
        }
    }

/*******************************/

#endif // GRAPH_H_INCLUDED
