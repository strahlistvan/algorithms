#include <iostream>
#include<vector>
#include<deque>
#include<thread>
#include<mutex>
#include<algorithm>
using namespace std;

const int N=5;
int G[N][N]={{0,1,1,0,0},
             {1,0,0,1,1},
             {1,0,0,1,1},
             {0,1,1,0,1},
             {0,1,1,1,0}};

//const int N = 10000;
//int G[N][N];

void gen_random_graph(int G[N][N], double density){
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            if (rand()%100 < density*100) {
                G[i][j] = G[j][i] = 1;
            }
            else {
                G[i][j] = G[j][i] = 0;
            }
        }
    }
}

vector<int> path;
vector<int> OK(N, 0);

void dfsearch(int v){
  OK[v]=1;
  path.push_back(v);
  for(int i=0; i<N; i++){
    if(G[v][i]!=0 && OK[i]==0) {
        dfsearch(i);
    }
  }
}

void dfsearch_it(int v){
  vector<int> stack_v;
  path.clear();

  stack_v.push_back(v);
  while(!stack_v.empty()) {
      v = stack_v.back();
      stack_v.pop_back();
      if (OK[v] == 0) {
          OK[v] = 1;
          path.push_back(v);
          for(int i=N-1; i>=0; i--){ //0..N or N..0
        //   for (int i=0; i<N; ++i) {
            if(G[v][i]!=0 && OK[i]==0) {
                stack_v.push_back(i);
            }
          }
      }
  }
}

void bfsearch(int v){
  deque<int> qu;
  path.clear();

  OK[v]=1;
  qu.push_back(v);
  path.push_back(v);
  while(!qu.empty()){
    int next = qu[0];
    qu.pop_front();
    //find 'next' vertex neighbors
    for(int i=0; i<N; i++){
      if(G[next][i]!=0 && OK[i]==0){
        path.push_back(i);
        OK[i]=1;
        qu.push_back(i);
      }
    }
  }
}

mutex mtx;

void bfsearch_para(int v, int level){
  vector<thread> thread_list;
  unique_lock<mutex> lck(mtx, defer_lock);

  lck.lock();
  OK[v]=1;
  path.push_back(v);
  lck.unlock();

  for(int i=0; i<N; i++){
    if(G[v][i]!=0 && OK[i]==0) {
   //     lck.lock();
   //     cout << " vertex " << v << " neighbor " << i << " thread number "
  //        << thread_list.size()+1 << " LEVEL: " << level << endl;
  //      lck.unlock();
        thread_list.push_back(thread(bfsearch_para, i, level+1));
    }
  }
  for (int i=0; i<thread_list.size(); i++) {
    thread_list[i].join();
  }
}

void print_path(vector<int> path){
  for(int i=0; i<path.size(); i++)
    cout<<path[i]<<", ";
  cout<<endl<<endl;
}

void reinit_globals(){
  for(int i=0;i<N;i++){
    OK[i]=0;
  }

  path.clear();
}

int main(){

  gen_random_graph(G, 0.9);

  dfsearch(2);
  cout<<"melysegi kereses: "<<endl;
 // print_path(path);

  reinit_globals();
  bfsearch(2);
  cout<<"szelessegi kereses: "<<endl;
//  print_path(path);
/*
  for (int k=0; k<10; ++k) {
      reinit_globals();
      bfsearch_para(2, 0);
      cout<<"szelessegi parhuzamos kereses: "<<endl;
      print_path(path);
  }
*/

  reinit_globals();
  dfsearch_it(2);
  cout<<"iterativ melysegi kereses: "<<endl;
//  print_path(path);
}
