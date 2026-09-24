class Solution {
public:
    int calPoints(vector<string>& ope) {
        stack<int> st;
        int res = 0;
        for (const string& op : ope) {
            if(op == "+"){
                int t1 = st.top();
                st.pop();
                int t2 = st.top() + t1;
                st.push(t1);
                st.push(t2);
                res+=t2;
            } else if(op == "C"){
                int t = st.top();
                st.pop();
                res-= t;
            } else if( op == "D" ){
                st.push(2 * st.top());
                res+=st.top();
            } else{
                st.push(stoi(op));
                res+= st.top();
            }
        }
        return res;
    }
};