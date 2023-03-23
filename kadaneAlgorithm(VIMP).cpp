class Solution {
public:
    int maxSubArray(vector<int> diff){
        int msf = INT_MIN;
        int meh = 0;
       for(int i = 0; i < diff.size(); i++){
           meh+=diff[i];
           if(msf < meh){
               msf = meh;
           }
           if(meh < 0){
               meh = 0;
           }
       } 
       return msf;
    }
};