

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> newArr;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix.size(); j++) {
                newArr.push_back(matrix[i][j]);
            }
        }
        sort(newArr.begin(), newArr.end());
        return newArr[k-1];
    }
};