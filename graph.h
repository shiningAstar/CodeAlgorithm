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

vvi adj;
int n;
vi vis;
//vector<int> from;
//vector<int> id;

void __dfs(/*int ccount,*/ int p){
    //cout<<nodes[p].val; //遍历p
    //id[p] = ccount;
    rep(i, 0, adj[p].size()){
        auto &np = adj[p][i];
        if(!vis[np]){
            vis[np] = 1;
            //from[np] = p;
            __dfs(/*ccount,*/ np);
        }
    }
}

void dfsGraph(){
    vis.assign(n, 0);
    //from.assign(n, -1);
    //int ccount = 0;
    //id.assign(n, -1);
    //连通图只遍历一遍，不用记录ccount和id
    /*if(!vis[0])
        __dfs(ccount, 0);*/

    for(int i = 0; i < n; ++i)
        if(!vis[i]){
            vis[i] = 1;
            __dfs(/*ccount,*/ i);
            //++ccount;
        }
    
    //遍历后可查询是否连通和路径
    //if(isConnected(v, w))
    //vector<int> path;
    //pathGraph(v, w, from, path);
}
/*******************************/



/*******************************/
//递推实现图邻接表广度优先遍历，visited记录节点是否遍历，from记录节点间路径，ccount联通分量，id查询是否连通

vvi adj;
int n;
vi vis;
//vector<int> from;
//vector<int> id;

void __bfs(/*int ccount, int v*/)
{
    vis.assign(n, 0);
    queue<int> q;
    //id[v] = ccount;
    q.em(0);
    vis[0] = 1;
    while(!q.empty()){
        auto &p = q.front();
        //cout<<p; //遍历p
        rep(i, 0, adj[p].size()){
            auto &np = adj[p][i];
            if(!vis[np]){
                vis[np] = 1;
                //from[np] = p;
                //id[np] = ccount;
                q.em(np);
            }
        }
        q.pop();
    }
}

void bfsGraph()
{
    
    //from.assign(n, -1);
    //int ccount = 0;
    //id.assign(n, -1);
    //连通图只遍历一遍，不用记录ccount和id
    /*if(!vis[0])
        __bfs(ccount, 0);*/
    /*for(int i = 0; i < n; ++i)
        if(!vis[i]){
            __bfs(ccount, i);
            //++ccount;
        }*/
    //遍历后可查询是否连通和路径，广度优先遍历的路径是最短路径
    //if(isConnected(v, w))
    //vector<int> path;
    //pathGraph(v, w, from, path);
}


/*******************************/


/*******************************/
/* 分层广度优先搜索 */
void bfs(){
    vvi adj;

    /* 层节点遍历，如果层节点需排序可用set，
        如果每次遍历只需拿出最（大/小）值节点，可使用priority_queue不分层 */
    vector<int> ls;
    /* 临时存放下一层节点，使用前置换到ls */
    vector<int> lst;
    int ln, p, pn, np;
    //set<int> ls;
    //priority_queue<int> ns;

    /* 初始置放第一层节点，如果只第一个为第一层，放0 */
    ls.eb(0);
    //for(;;) ls.eb();
    
    while(!ls.empty()){
        ln = ls.size();
        rep(i, 0, ln){
            p = ls[i], pn = adj[p].size();
            rep(j, 0, pn){
                /* 下一层节点放置lt暂存 */
                np = adj[p][j];
                lst.eb(np);
            }
        }
        /* 一层结束，暂存的下一层节点置换回ls */
        ls.swap(lst); lst.clear();
    }
}

/*******************************/


/*******************************/
//递归实现有向图邻接表深度优先遍历，判断是否有环

int n;
vvi adj;  //adj[i] 代表有节点i指向adj[i]的有向边
vi vis;

//vis记录节点是否遍历，三种状态：未遍历、在遍历中（邻接节点未遍历完）、结束遍历（邻接节点全部遍历）{-1，0，1}
//遍历中的节点被再次遍历到，则存在环
/* 结束的节点后面节点全部遍历完不可能是当前遍历中路径的前面节点，遍历中节点一定在当前遍历中路径前面的某位置 */
bool __dfs(int p){  //有环返回false，无环true
    //cout<<nodes[p].val;   //遍历p
    vis[p] = 0;
    rep(i,0,adj[p].size()){
        auto &np = adj[p][i];
        if(vis[np] == 0) return false;
        if(vis[np] == -1 && !__dfs(np)) return false;
    }
    vis[np] = 1;
    return true;
}

bool dfs(){  //有环返回false，无环true
    vis.assign(n, -1);
    //连通图只遍历一遍，不用记录ccount和id
    //return __dfs(0);
    rep(i,0,n)
        if(vis[i] != 1 && !__dfs(i)) return false;

    return true;
}

/*******************************/

/*******************************/
//递归实现无向图邻接表深度优先遍历，判断是否有环

vvi adj;  //adj[i] 代表节点i和adj[i]有边连接
int n;
vi vis;

//vis记录节点是否遍历，二种状态：未遍历、已遍历遍历（邻接节点全部遍历）{0，1}
//遍历中的节点被再次遍历到，则存在环
/* 全部已节点都可以通当前节点，因为无向边可双向通路遍历，遍历到已遍历节点一定存在环 */
bool __dfs(int p){   //有环返回false，无环true
    //cout<<nodes[p].val;   //遍历p
    vis[p] = 1;
    rep(i,0,adj[p].size()){
        auto &np = adj[p][i];
        if(vis[np]) return false;
        if(!vis[np] && !__dfs(np)) return false;
    }
    return true;
}

bool dfs(){   //有环返回false，无环true
    vis.assign(n, 0);
    //连通图只遍历一遍
    //return __dfs(0);
    rep(i,0,n)
        if(!vis[i] && !__dfs(i)) return false;

    return true;
}

/*******************************/

/*******************************/
/* 二维表格中移动问题移动数组方式 */

vvi g;
int n, m;
vvi vis;

const int d[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};   //移动数组

void dfs(int r, int c){
    //执行点遍历
    if(g[r][c]?) return;   //移动终止条件
    int nr, nc;
    rep(i, 0, 4){
        nr = d[i][0] + r; nc = d[i][1] + c;
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){   //判断下一步移动点条件
            vis[nr][nc] = 1;
            dfs(nr, nc);
        }
    }
}

void bfs(int r, int c){
    queue<pii> q;
    pii np;
    q.em(pii{r,c});
    vis[r][c] = 1;
    while(!q.empty()){
        pii &p = q.front();
        rep(i, 0, 4){
            np.p1 = d[i][0] + p.p1; np.p2 = d[i][1] + p.p2;
            if(np.p1 >= 0 && np.p1 < n && np.p2 >= 0 && np.p2 < m && !vis[np.p1][np.p2]){   //判断下一步移动点条件
                vis[np.p1][np.p2] = 1;
                q.em(np);
            }
        }
        q.pop();
    }
}

void moveinGrid(vector<vector<int>> grid){
    g.swap(grid);
    n = g.size();
    m = g[0].size();
    vis.assign(n, vi(m, 0));
    dfs(0, 0); bfs(0, 0);
}


/*******************************/

/*******************************/
/* 有向无环图DAG拓扑排序 */

    vvi adj;
    int n;
    vi order;
    //vi rk;     //记录节点到排序位置

    /* 在入度为0的顶点开始排，去掉入度为0的顶点和出度边，剩余节点入度为0的继续排，直到排完全部顶点，
       还有顶点未排没有入度为0的顶点，图中有环不能排序 */
    bool topo_sort(vector<vector<int>> route){
        adj.assign(n,vi());        //节点号0~n-1
        //adj.assign(n + 1,vi());  //节点号1~n
        //zk.assign(n);       //节点号0~n-1
        //zk.assign(n + 1);   //节点号1~n

        rep(i,0,p.size()) adj[route[i][0]].eb(route[i][1]);

        queue<int> zq;   /* 入度为0的顶点队列 */
        vi ni(n, 0);         /* 每个顶点入度数 */   //节点号0~n-1
        //vector<int> ni(n + 1, 0);   //节点号1~n

        int p, pn, np;
        //int c = 0;    //记录节点到顺序位置时，使用当前位置
        /* 计算每个节点入度值 */
        rep(i,0,n){     //节点号0~n-1
        //repe(i,1,n){   //节点号1~n
            pn = adj[i].size();
            rep(j,0,pn) ++ni[adj[i][j]];
        }
        /* 入度为0节点入队 */
        rep(i,0,n) if(ni[i] == 0) zq.emplace(i);     //节点号0~n-1
        //repe(i,1,n) if(ni[i] == 0) zq.emplace(i);  //节点号1~n

        while(!zq.empty()){
            p = zq.front();
            /* 入度为0为当前位置计入排序 */
            order.emplace_back(p);
            //rk[p] = c; ++c;    //记录节点到当前位置
            /* 删除已排序顶点的出度对应顶点的入度，再把删除后入度为0顶点加入队列 */
            pn = adj[p].size();
            rep(i,0,pn) {
                np = adj[p][i];
                --ni[np];
                if(ni[np] == 0) zq.emplace(np);
            }
            zq.pop();
        }

        if(order.size() < n/* c < n *//* 记录节点到当前位置时 */) return false;
        return true;
    }

/*******************************/

#endif // GRAPH_H_INCLUDED
