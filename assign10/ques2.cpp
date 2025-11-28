#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
  class graph{
      int v;
      list<int>*l; //dynamic list made kind of an array
      public:
      graph(int v){
        this->v=v;
        l=new list<int>[v] ;//dynamic array made 
      }
      void addedge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
      }

      void printadjlist(){
        for(int i=0;i<v;i++){
            cout<<i<<":";
            for(int neighbours:l[i]){
                cout<<neighbours<<" ";
            }
            cout<<endl;
        }
      }
    void bfs(){
queue<int>q;
vector<bool>vis(v,false);
q.push(0);
vis[0]=true;
while(q.size()>0){
    int u=q.front();
    q.pop();
    cout<<u<<" ";
    for(int v:l[u]){
        if(!vis[v]){
            vis[v]=true;
            q.push(v);
        }
    }
}
}

    
  };
int main(){
    graph g(5);
     g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.addedge(2,4);

    g.bfs();

    cout << "Adjacency List:\n";
    g.printadjlist();

   
}