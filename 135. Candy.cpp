class Solution {
public:
    int candy(vector<int>& ratings) {
       vector<int> left(ratings.size(),1) ;
       vector<int> right(ratings.size(),1) ;

       for(int i = 1, j = ratings.size() - 2 ; i < ratings.size() && j >= 0; i++, j--){
           if(ratings[i] > ratings[i - 1]) left[i] = left[i - 1] + 1 ;
           if(ratings[j] > ratings[j + 1]) right[j] = right[j + 1] + 1 ;
       }

       vector<int> ans ;
       for(int i = 0 ; i < ratings.size() ; i++){
           ans.push_back(max(left[i], right[i])) ;
        }
        int sum = accumulate(ans.begin(), ans.end(), 0) ;
        return sum ;
    }
};