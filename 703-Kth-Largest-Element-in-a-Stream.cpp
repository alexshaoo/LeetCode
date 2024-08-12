class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> h;
    int n;
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for (int num : nums) h.push(num);
        while (h.size() > n) h.pop();
    }
    int add(int val) {
        h.push(val);
        if (h.size() > n) h.pop();
        return h.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */