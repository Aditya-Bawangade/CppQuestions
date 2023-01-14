#include<vector>
#include<iostream>
using namespace std;


// int maxSubArr(vector<int> diff){
//     if(diff.size()==1){
//         return diff[0];
//     }
//         int mid = diff.size()/2;
        
//         vector<int> v1;
//         for(int i = 0; i< mid;i++){
//             v1.push_back(diff[i]);
//         }
//         vector<int> v2;
//         for(int i= mid;i<diff.size();i++){
//             v2.push_back(diff[i]);
//         }
//         int s3 = 0;
//         int lsum = INT_MIN;
//         int rsum = INT_MIN;
//         for(int i = mid; i<diff.size();i++ ){
//             s3+=diff[i];
//             if(s3>=lsum){
//                 lsum = s3;
//             }
//         }
//         int s33 = 0;
//         for(int j= mid-1; j>=0;j--){
//             s33 += diff[j];
//             if(s33>=rsum){
//                 rsum = s33;
//             }
//         }
//         int scrossing = rsum + lsum;
//         int s1 = maxSubArr(v1);
//         int s2 = maxSubArr(v2);
//         int maxi  = max(s1,s2);
//         int maxii = max(maxi,scrossing);
//         return maxii;
        
//     }
//     int maxProfit(vector<int>& prices) {
//         vector<int> diff;
//         for(int i = 0; i<prices.size()-1;i++){
//             diff.push_back(prices[i+1]-prices[i]);
//         }
//         int s = diff.size();
//         return maxSubArr(diff);
//     }
//     int main(){
//         vector<int> prices = {7,98,1,2,6,3,8};
//         vector<int> diff;
//         for(int i = 0; i<prices.size()-1;i++){
//             diff.push_back(prices[i+1]-prices[i]);
//         }
//         int s = diff.size();
//         int a = maxSubArr(diff);
//         cout<<a;
//         return 0;
//     }
class Solution {
public:
    int maxSubArr(vector<int> diff){
        int maxendhere = 0;
        int maxsofar = INT_MIN;
        for(int i = 0 ; i < diff.size(); i++){
            maxendhere +=diff[i];
            if(maxsofar<=maxendhere){
                maxsofar = maxendhere;
            }
            if(maxendhere<0){
                maxendhere = 0;
            }
            
        }
        return maxsofar;
    }
   int maxProfit(vector<int>& prices) {
        vector<int> diff;
        if(prices.size()==1||prices.size()==0){
            return 0;
        }
        for(int i = 0; i<prices.size()-1;i++){
            diff.push_back(prices[i+1]-prices[i]);
        }
        int s = diff.size();
        int ans = maxSubArr(diff);
        if(ans<0){
            return 0;
        }
        return ans;
    }
};