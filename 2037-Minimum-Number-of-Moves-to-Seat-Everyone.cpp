class Solution {
public:
    void cs(vector<int>& arr) {
        int c[101];
        int ind = 0;
        for (int i = 0; i < arr.size(); ++i) {
            ++c[arr[i]];
        }
        for (int i = 0; i < 101; ++i) {
            while (c[i]--> 0) {
                arr[ind++] = i;
            }
        }
    }
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        int ans = 0;
        cs(seats);
        cs(students);
        for (int i = 0; i < n; ++i) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};