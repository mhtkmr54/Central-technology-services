#include <iostream>
#include <cstdlib>
#include <deque>
#include <map>
#include <set>
#include <iterator>

using namespace std;



class Vertex{
  public:
     int data;
     Vertex* next;
     Vertex(int d){
      data =d;
      next = NULL;
     }
};

set<int>::iterator it;
map <Vertex*, set<Vertex*> >::iterator i;

class graph{
 public:
    map <Vertex*, set<Vertex*> > graph_container;
    void add_vertex(int v) {
     Vertex* n = new Vertex(v);
     set<Vertex*> genset;
     graph_container[n] = genset;

    };


    void add_edge(int s, int d){

    };
    void printgraph(){
      for (i = graph_container.begin(); i !=graph_container.end(); ++i){
        cout << i->first->data << endl;
      }
    }
};


int main (){
  graph grph;
  grph.add_vertex(6);
  grph.printgraph();
  return 0;
}

