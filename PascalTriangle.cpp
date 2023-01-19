class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> answer;
       vector<int> a;
       a.push_back(1);
       answer.push_back(a);
        if(numRows==1){
           return answer;
       }
       vector<int> b;
       b.push_back(1);
       b.push_back(1);
       answer.push_back(b);
       if(numRows==2){
           return answer;
       }
       for(int i = 2; i< numRows;i++){
           vector<int> arr;
           for(int j = 0 ; j < i+1 ; j++){
               if(j == 0 || j==i){
                   arr.push_back(1);
                   continue;
               }
               arr.push_back(answer[i-1][j-1]+answer[i-1][j]);
           }
           answer.push_back(arr);
       }
       return answer;
    }
};