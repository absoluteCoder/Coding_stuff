#include<iostream>
#include<vector>
using namespace std;


template<class T>class BIT{
  vector<T> bit;
public:
  BIT(int n){
    bit.resize(n+1, 0);
  }
  void update(int index, int val = 1){
    index++;
    while(index < bit.size()){
      bit[index] += val;
      index += (index&-index);
    }
  }
  T query(int index){
    index++;
    T res = 0;
    while(index > 0){
      res += bit[index];
      index -= (index&-index);
    }
    return res;
  }
};

int main(){
  BIT<long long> obj(100);
  obj.update(20);
  obj.update(10);
  obj.update(30);
  obj.update(40);
  cout<<obj.query(29)<<" \n"; // 2
  cout<<obj.query(30)<<" \n"; // 3
  cout<<obj.query(31)<<" \n"; // 3
  return 0;
}