/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int util(string &a, string &b){
        int ans = 0 ;
        for(int i = 0 ; i < 6 ; i++){
            if(a[i] == b[i]){
                ans++ ;
            }
        }
        return ans ;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        for(int i = 0, matches = 0 ; i < 30 && matches != 6 ; i++){
            string trash = words[words.size()/2] ;
            matches = master.guess(trash) ;
            vector<string> newlist ;
            for(auto word: words){
                if(util(word, trash) == matches){
                    newlist.push_back(word) ;
                }
            }
            words = newlist ;
        }
    }
};