class Solution {
public:
    int findrow(vector<int>& matrix, int target,int low,int high){
        int mid = low + (high - low)/2;
         if(high == 0)
         return 0;
        if( matrix[low] > target ){
             cout<<"here"<<endl;
        return -1;
        }
        if(matrix[high] < target)
        return high;
        while(high >= low){
            mid = low + (high - low)/2;
            if(mid > 0 &&matrix[mid] > target && matrix[mid - 1] <= target){
                return mid - 1;
            }
             if(mid > 0 &&matrix[mid] >= target && matrix[mid + 1] < target){
                return mid;
            }
            if(matrix[mid] == target)
            return mid;
            if(matrix[mid] < target && matrix[high] >= target)
            {
                low = mid + 1;
            } else{
                high = mid - 1;
            }
            }
            return -1;
        }
    bool binary(vector<int>& matrix, int target,int low,int high){
         int mid = low + (high - low)/2;
           while(high >= low){
            mid = low + (high - low)/2;
            if(matrix[mid] == target)
            {
                return true;
            } 
            if(matrix[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            }
            return false;
        }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> col;
        for(int i=0;i<r;i++){
            col.push_back(matrix[i][0]);
        }
        r = findrow(col,target,0,r-1);
        cout<<r<<endl;
        if(r==-1)
        return false;
        return binary(matrix[r],target,0,c);
    }
};
