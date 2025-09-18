class TaskManager {
public:
    unordered_map<int, pair<int, int>> mp; // taskId -> {userId, priority}}
    struct Cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            if (a[2] != b[2]) return a[2] > b[2];
            return a[1] > b[1];
        }
    };
    set<vector<int>, Cmp> s;
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            int u = task[0], t = task[1], p = task[2];
            mp[t] = {u, p};
            s.insert(task);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        vector<int> v = {userId, taskId, priority};
        s.insert(v);
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, _] = mp[taskId];
        rmv(taskId);
        add(userId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        auto [userId, priority] = mp[taskId];
        mp.erase(taskId);
        vector<int> v = {userId, taskId, priority};
        s.erase(s.find(v));
    }
    
    int execTop() {
        if (s.empty()) return -1;
        auto task = *s.begin();
        rmv(task[1]);
        return task[0];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */