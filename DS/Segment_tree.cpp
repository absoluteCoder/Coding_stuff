#include <iostream>
#include "vector"
#include<algorithm>
using namespace std;
template<class Type> class ST{

public:
    ST(std::vector<Type> &arg, Type val): arr(arg){
        sg.resize(arr.size()*4);
        // Value of Type as third Parameter.
        fill(sg.begin(), sg.end(), val);
    }
    void Build(){
        build(0, arr.size()-1, 0);
    }
    Type query(int ql, int qr){
      return query(0, arr.size()-1, ql, qr, 0);
    }
    void update(int index, Type val){
      update(0, arr.size()-1, index, 0, val);
    }
private:
    Type query(int l, int r, int ql, int qr, int sgi){
        // do needful with return
        if(l > r || qr < l || r < ql) return INT_MAX;
        if(ql <= l && r <= qr){
            return sg[sgi];
        }
        else{
            int mid = (l+r)>>1;
            Type a = query(l, mid, ql, qr, sgi*2+1);
            Type b = query(mid+1, r, ql, qr, sgi*2+2);
            // do needful while return.
            return min(a, b);
        }
    }
    void update(int l, int r, int qi, int sgi, Type val){
        if(l > r || qi < l || r < qi) return;
        if(l == r){
            sg[sgi] = val;
            arr[l] = val;
        }
        else{
            int mid = (l+r)>>1;
            update(l, mid, qi, sgi*2+1, val);
            update(mid+1, r, qi, sgi*2+2, val);
            // do needful while return.
            sg[sgi] = min(sg[sgi*2+1], sg[sgi*2+2]);
        }
    }
    void build(int l, int r, int sgi){
        if(l > r) {
        }
        else if(l == r){
            // do needful
            sg[sgi] = arr[l];
        }
        else{
            int mid = (l+r)>>1;
            build(l, mid, sgi*2+1);
            build(mid+1, r, sgi*2+2);
            // do needful
            sg[sgi] = min(sg[sgi*2+1], sg[sgi*2+2]);
        }
    }
    std::vector<Type> arr;
    std::vector<Type> sg;
};
int main(int argc, const char * argv[]) {
    using namespace std;
    vector<int> arr(10);
    for(int i = 0; i < arr.size(); i++){
        arr[i] = rand()%1000;
    }
    // 807 249 73 658 930 272 544 878 923 70
    for(int d: arr) cout<<d<<" "; cout<<"\n";
    ST<int> ob(arr, INT_MAX);
    ob.Build();
    cout<<ob.query(3, 7)<<"\n"; // 272
    ob.update(5, 666);
    cout<<ob.query(3, 7)<<"\n"; // 544
    return 0;
}
