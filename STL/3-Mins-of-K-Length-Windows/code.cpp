#include<bits/stdc++.h>
using namespace std;

// technique 1: monotonic deque method:

class monotonic_deque{

    public:
    deque<int> dq;

    void push_back(int x){
         
        while(!dq.empty() && dq.back()>=x){
            dq.pop_back();
        }
        dq.push_back(x);
    }

};

void solve_using_monotonic_deque(vector<int>& v, int K){

    monotonic_deque dq;
    for(int i=0;i<v.size();i++){
        
    }

}


