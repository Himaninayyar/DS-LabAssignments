#include<iostream>
#include<vector>
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
      int degree(int vertex){
        return l[vertex].size();
      }
      void printadjacent(int vertex){
        cout<<"adjacent vertices of "<<vertex<<": ";
        for(int neigh:l[vertex]){
            cout<<neigh<<" ";
        }
        cout<<endl;
      }

      int countedges(){
            int sum=0;
            for(int i=0;i<v;i++){
                sum+=l[i].size();
            }
            return sum/2;
      }
  };
int main(){
    graph g(5);
     g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.addedge(2,4);

    cout << "Adjacency List:\n";
    g.printadjlist();

    cout << "\nDegree of vertex 1: " << g.degree(1) << endl;

    g.printadjacent(2);

    cout << "Total number of edges: " << g.countedges() << endl;
    return 0;
}