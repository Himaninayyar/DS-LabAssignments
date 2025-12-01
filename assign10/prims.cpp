#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class edge{
    public:
    int v; //destination 
    int w; //weight
    edge(int vertex,int weight){
        v=vertex;
        w=weight;

    }
};

class graph{
  int v;
  vector<vector<edge>>adj;
  public:
  graph(int vertices){
    v=vertices;
    adj.resize(v);
  }
  void addedge(int u,int v,int w){
    adj[u].push_back(edge(v,w));
     adj[v].push_back(edge(u,w));

  }

  void prims(int start=0){
    vector<int>key(v,INT16_MAX);
    vector<bool>visisted(v,false);
    vector<int>parent(v,-1);

    //min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    key[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        if(visisted[u]) continue;
        visisted[u]=true;
        for(auto e:adj[u]){
            int v=e.v;
            int w=e.w;
            if(!visisted[v] && w<key[v]){
                key[v]=w;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }
    }
            cout << "Edges in the Minimum Spanning Tree:\n";
        int totalWeight = 0;
        for (int i = 1; i < v; i++) {
            cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
            totalWeight += key[i];
        }
        cout << "Total weight of MST = " << totalWeight << endl;
  }
};
int main(){
  graph g(5);

    g.addedge(0, 1, 2);
    g.addedge(0, 3, 6);
    g.addedge(1, 2, 3);
    g.addedge(1, 3, 8);
    g.addedge(1, 4, 5);
    g.addedge(2, 4, 7);
    g.addedge(3, 4, 9);

    g.prims(0);
    return 0;
}