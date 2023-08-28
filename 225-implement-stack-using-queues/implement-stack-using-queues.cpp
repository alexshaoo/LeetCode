class MyStack {
public:
  queue<int> q;
  MyStack() {
      
  }
  
  void push(int x) {
    queue<int> tmp;
    tmp.push(x);
    while (!q.empty()) {
      tmp.push(q.front());
      q.pop();
    }
    swap(tmp, q);
  }
  
  int pop() {
    int tmp = this->top();
    q.pop();
    return tmp;
  }
  
  int top() {
    return q.front();
  }
  
  bool empty() {
    return q.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */