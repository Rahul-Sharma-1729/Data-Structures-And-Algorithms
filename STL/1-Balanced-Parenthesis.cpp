#include<bits/stdc++.h>
#define LOCAL
using namespace std;

//idea 1: directly using stack for multiple symbols 

bool solve_using_stack(string str){

    // extensible map which can be extended depending on the symbols
    map<char,int> symbol_value_map;
    symbol_value_map['{'] = +1;
    symbol_value_map['}'] = -1;
    symbol_value_map['<'] = +2;
    symbol_value_map['>'] = -2;
    symbol_value_map['('] = +3;
    symbol_value_map[')'] = -3;

    bool is_balanced = true;
    stack<int> parenthesis_stack;
    for(auto symbol: str){ // Time Complexity: O(n)
     
        int symbol_value = symbol_value_map[symbol];
        if(symbol_value > 0){    // we can keep pushing +ve values (opening symbols) directly
            parenthesis_stack.push(symbol_value); // O(1)
        }else if(!parenthesis_stack.empty() && (symbol_value + parenthesis_stack.top() == 0)){    // if negative value and stack is not empty then sum should be 0
            parenthesis_stack.pop(); // O(1)
        }else{ // all other cases it would be not balanced (total sum of values in stack would be <0, lower than the graph)
            is_balanced = false;
            break;
        }
    }

    // if only positive ones remain then also it is not balanced
    if(parenthesis_stack.size() != 0){
        is_balanced = false;
    }

    // Total Time Complexity: O(n)
    return is_balanced;
}

//idea 2: for a single symbol problem we can solve directly using just one variable depth
bool solve_using_depth(string str){

    // Only single symbol can be used, cannot be extended
    map<char,int> symbol_value_map;
    symbol_value_map['{'] = +1;
    symbol_value_map['}'] = -1;

    bool is_balanced = true;
    int depth = 0;

    for(auto symbol: str){
        int symbol_value = symbol_value_map[symbol];
        depth += symbol_value;
        if(depth < 0){ // more closing brackets have come than the number of opening brackets. Graph going below 0 (start value)
            is_balanced = false;
            break;
        }
    }

    // if the depth at the end is not equal to the start value of the range then we cannot have balanced range. 
    // Imagine the graph, if final depth > 0 then some extra opening brackets are still left which are not closed
    // if the depth is <0 then more closing brackets were added
    if(depth != 0){ 
        is_balanced = false;
    }

    return is_balanced;
}


int main(){
    
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int num_test_cases;
    cin>>num_test_cases;

    while(num_test_cases--){
        string test_case;
        cin>>test_case;
        cout<<"The test case: "<<test_case<<" is "<<(solve_using_stack(test_case)?"balanced":"not balanced")<<"\n";
    }

    cin.ignore();
    cin.get();

}