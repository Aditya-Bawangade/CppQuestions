class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        stk.push(s[0]);
        for(int i = 1 ; i < s.length(); i++){
            if(!stk.empty()){
                if(s[i] == stk.top()){
                stk.pop();
            }
                else{
                stk.push(s[i]);
            }
            }
            else{
                stk.push(s[i]);
            }
           
        }
        string ans = "";
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};