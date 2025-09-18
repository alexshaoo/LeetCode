class TaskManager {
public:
    unordered_map<int, pair<int, int>> mp; // taskId -> {userId, priority}
    priority_queue<pair<int, int>> pq; // {priority, taskId}
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            int u = task[0], t = task[1], p = task[2];
            mp[t] = {u, p};
            pq.push({p, t});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto& [userId, priority] = mp[taskId];
        priority = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [p, t] = pq.top(); pq.pop();
            auto it = mp.find(t);
            if (it == mp.end()) continue;
            if (it->second.second != p) continue;
            int u = it->second.first;
            mp.erase(it);
            return u;
        }
        return -1;
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