class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, mt = 0;
        while (numBottles >= numExchange) {
            ans += numBottles - mt;
            mt = numBottles % numExchange;
            numBottles = numBottles / numExchange + mt;
        }
        return ans + numBottles - mt;
    }
};