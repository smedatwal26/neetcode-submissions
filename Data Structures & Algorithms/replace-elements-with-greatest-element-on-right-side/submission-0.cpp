class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int s = arr.size();
        int m = arr[s-1];
        for(int i = s-2; i>=0; i--){
            int temp = arr[i];
            arr[i] = m;
            m = max(temp,m);
        }
        arr[s-1] = -1;
        return arr;
    }
};