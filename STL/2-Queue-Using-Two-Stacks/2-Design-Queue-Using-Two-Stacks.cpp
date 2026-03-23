 #include<bits/stdc++.h>
 using namespace std;


 // The idea is basically to have two stack and think of them like single queue where one stack would be for getting the front/popping and one would be for pushing
 template <typename any>
 class Queue{

    private:
    stack<any> front_stack,back_stack;

    public:

    void push(any x){
        back_stack.push(x);
    }

    any pop(){
        
        any front_element = this->front();

        front_stack.pop();

        return front_element;
    }

    any front(){

        if(front_stack.size()+back_stack.size()==0){
            throw "Queue is empty";
        }

        any front_element;
        if(!front_stack.empty()){
            front_element = front_stack.top();
        }else{
            while(!back_stack.empty()){
                any back_element = back_stack.top();
                back_stack.pop();
                front_stack.push(back_element);
            }
            front_element = front_stack.top();
        }

        return front_element;
    }

    size_t size(){
        size_t total_size = back_stack.size()+front_stack.size();
        return total_size;
    }
    
 };

 int main(){
    Queue<int> test_q;
    test_q.push(21);

 }