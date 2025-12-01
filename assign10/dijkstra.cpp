#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

//algo
 
vector<int>dij(int v,vector<vector<pair<int,int>>>&adj,int src){
    vector<int>dist(v,INT16_MAX);
    dist[src]=0;


    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src}); //dist,src

    //processing all nodes

    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(d>dist[node]) continue;
         for(auto &it:adj[node]){
            int adjnode=it.first;
            int wt=it.second;
             
            if(d+wt<dist[adjnode]){
                dist[adjnode]=d+wt;
                pq.push({dist[adjnode],adjnode});
            }
         }
    }
    return dist;
}
int main(){
    int v=5;
    vector<vector<pair<int,int>>>adj(v);
    adj[0].push_back({1,2}); //node and weight
     adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});
    int src=0;
    vector<int>dist=dij(v,adj,src);

    cout<<"shortest distance from "<<src<<" :\n";
    for(int i=0;i<v;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }

    return 0;

}