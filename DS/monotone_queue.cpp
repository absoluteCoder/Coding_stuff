#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<class T>
class CustomQueue{
    deque<T> q;
    T t;
    int k;
    vector<T> arr;
    function<bool(T,T)> func;
public:
    CustomQueue(int k, T t,function<bool(T,T)>  func, vector<int> arr):t(t), k(k), func(func){
        this->arr.swap(arr);
    }
    int push(int index){
        while(!q.empty() && index - q.front() > k){
            q.pop_front();
        }
        int maxDiff = -1;
        if(!q.empty()) maxDiff = abs(arr[index]-arr[q.front()]);
        while(!q.empty() && func(arr[q.back()], arr[index])){
            q.pop_back();
        }
        q.push_back(index);
        return maxDiff > t ? -1 : maxDiff;
    }
};
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    // max of nums[i]-nums[j], condition abs(j-i) <= k
    // and above result <= t
    
    function<bool(int,int)> f1 = [](int a, int b){ return a > b; };

    CustomQueue<int> q1(k, t, f1, nums);
    CustomQueue<int> q2(k, t, [](int a, int b)->bool { return a < b; }, nums);
    q1.push(0);
    q2.push(0);
    int n = nums.size();
    int res = -1;
    for(int i = 1; i < n; i++){
        res = max(res, q1.push(i));
        res = max(res, q2.push(i));
    }
    return res != -1;
}
int main(){
  vector<int> arr{1,5,8,2,15,9,13,17,4,7};
  cout<<boolalpha<<containsNearbyAlmostDuplicate(arr, 3, 10)<<"\n"; // true
  cout<<boolalpha<<containsNearbyAlmostDuplicate(arr, 2, 1)<<"\n"; // false
  return 0;
}