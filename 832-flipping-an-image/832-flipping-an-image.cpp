class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        vector<vector<int>> fin;
        
        for (int i = 0; i < image.size(); ++i) {
            
            vector<int> line;
            
            for (int j = image.at(0).size()-1; j >= 0; --j) {
                int temp = (image.at(i).at(j) == 1) ? 0 : 1;
                line.push_back(temp);
            }
            
            fin.push_back(line);
        }
        
        return fin;
    }
};