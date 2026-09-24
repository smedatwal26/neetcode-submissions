class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int> p;
        for(int i : s){
            p.push(i);
        }
        while(p.size()>1){
            int x = p.top();
            p.pop();
            int y = p.top();
            p.pop();
            if(x>y){
                p.push(x-y);
            }else if(x<y){
                p.push(y-x);
            }else{
                continue;
            }
        }
        if(p.size() == 0)
        return 0;
        return p.top();
    }
};
