class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int ROW = mat.size();
        int COL = mat[0].size();
        int l = 0, r = ROW * COL - 1;
        while(l <= r){
            int mid = l + (r-l)/2;
            int row = mid/COL, col = mid % COL;
            if(target > mat[row][col]){
                 l = mid + 1;
            } else if(target < mat[row][col]){
                r = mid - 1;
            } else{
                return true;
            }
        }
        return false;
    }
};
