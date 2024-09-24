class OrderedStream {
private:
    vector<string> packets;
    int ptr;
public:
    OrderedStream(int n) {
        packets.resize(n);
        ptr = 0;
    }
    vector<string> insert(int idKey, string value) {
        packets[idKey-1] = value;
        vector<string> res;
        while (ptr < packets.size() && packets[ptr] != "") {
            res.push_back(packets[ptr++]);
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */