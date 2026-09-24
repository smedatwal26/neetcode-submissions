class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();
    int total = n1+n2;
    int half = (total+1)/2;
    if(n1>n2)
    return findMedianSortedArrays(b,a);
    int l = 0;
    int r = n1;
    while(l<=r){
        int mid1 = (l+r)/2;
        int mid2 = (half - mid1);
        int l1 = mid1>0 ? a[mid1 - 1] : INT_MIN; 
        int r1 = mid1<n1 ? a[mid1] : INT_MAX; 
        int l2 = mid2>0 ? b[mid2 - 1] : INT_MIN; 
        int r2 = mid2<n2 ? b[mid2] : INT_MAX; 

        if(l1<=r2 && l2<=r1){
            if(total%2!=0){
                return max(l1,l2);
            }
             return (max(l1,l2) + min(r1,r2))/2.0;
           
        } else if(l1 > r2){
            r = mid1 - 1;
        }else{
            l = mid1 + 1;
        }

    }
    return -1;
    }
};
