class Solution {
public:
    bool check(vector<int> p,int mid, int h){
        int time = 0;
        for(int i=0;i<p.size();i++){
             int t = p[i]/mid;
            if(p[i] < mid){
            t =1;
            } else if(p[i]%mid != 0){
                t++;
            }
            time+=t;
            if(time > h)
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1, high =0;
        for(int i=0;i<piles.size();i++){
            high = max(piles[i],high); 
        }
        
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(piles,mid,h)){
                high = mid - 1;
                ans = min(ans,mid); 
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
