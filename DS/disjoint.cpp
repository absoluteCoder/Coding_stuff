#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DSU{
  vector<int> parent;
  vector<int> sizeOfGrp;
public:
  DSU(int n){
    parent.resize(n, -1);
    sizeOfGrp.resize(n, 1);
  }
  int getHead(int node){
    if(parent[node] == -1) return node;
    return parent[node] = getHead(parent[node]);
  }
  void merge(int a, int b){
    a = getHead(a);
    b = getHead(b);
    if(a != b){
      if(sizeOfGrp[a] < sizeOfGrp[b]) {
        swap(a,b);
      }
      parent[b] = a;
      sizeOfGrp[a] += sizeOfGrp[b];
    }
  }
  int getGroupSize(int a){
    return sizeOfGrp[getHead(a)];
  }
  int noOfGroup(){
    return count(parent.begin(), parent.end(), -1);
  }
};

int main(){
  DSU dsu(10);
  cout<<dsu.noOfGroup()<<"\n"; // 10
  dsu.merge(2,5);
  dsu.merge(4,5);
  dsu.merge(7,5);
  cout<<dsu.noOfGroup()<<"\n"; // 7
  cout<<dsu.getGroupSize(7)<<"\n"; // 4
  return 0;
}