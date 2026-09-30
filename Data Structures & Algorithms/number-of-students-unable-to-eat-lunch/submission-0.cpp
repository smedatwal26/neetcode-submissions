class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> f1(2,0);
        for(int i=0; i<students.size(); i++){
            f1[students[i]]++;
        }
        int res = students.size();
        for(int i=0; i<students.size(); i++){
            if(f1[sandwiches[i]] > 0){
                res--;
                f1[sandwiches[i]]--;
            }else{
                break;
            }
        }
        return res;
    }
};