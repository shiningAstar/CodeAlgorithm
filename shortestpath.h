#ifndef PRESUM_H_INCLUDED
#define PRESUM_H_INCLUDED

/**********************************/
/* dijkstra单源最短路 */

vector<vector<pii>> adj;
int n, m, s;  //n个顶点，m条边，出发点s
vector<int> dis;
vector<int> vis;
PQ<pii, 0> pq

void dijkstra(){
    /* 需要先建图adj */
    int p, np, nw;    
    dis.assign(n, 0x3f3f3f3f);
    vis.assign(n, 0);

    pq.em(pii{0, s});
    while(!pq.empty()){
        p = pq.top().p2;
        pq.pop();
        if(!vis[p]){  //同一节点多个数据访问最小距离的一个，后面数据一定比最小距离长
            vis[p] = 1;
            rep(i,0,adj[p].size()){
                pii &npw = adj[p][i]; np = npw.p1; nw = npw.p2;
                if(dis[p] + nw < dis[np]){
                    dis[np] = dis[p] + nw;
                    pq.em(pii{dis[np], np});  //已知同最短点集联通节点范围扩展，可能更新已知点vis判断不处理长的
                }
            }
        }
    }
    //dis是单源最短路数组，每个顶点距离
}



/**********************************/


#endif //PRESUM_H_INCLUDED