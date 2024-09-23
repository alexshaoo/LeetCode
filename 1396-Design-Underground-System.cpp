class UndergroundSystem {
private:
    unordered_map<string, pair<double, int>> times;
    unordered_map<int, pair<string, int>> in;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, ti] = in[id];
        auto& [total, n] = times[startStation+"-"+stationName];
        total += t-ti;
        n++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto [total, n] = times[startStation+"-"+endStation];
        return total/n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */