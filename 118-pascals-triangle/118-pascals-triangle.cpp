class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> fin;
        
        for (int i = 0; i < numRows; ++i) {
            
            vector<int> row(i+1);
            
            // first and last are 1
            row[0] = 1;
            row[i] = 1;
            
            // get the middle things
            for (int j = 1; j <= i-1; ++j) {
                row[j] = fin[i-1][j-1] + fin[i-1][j];
            } 
            
            fin.push_back(row);
        }
        
        return fin;
    }
};