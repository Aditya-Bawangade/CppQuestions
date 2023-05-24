class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans ;
        int i = 0 ; 
        while(i < words.size()){
            string trash = "" ;
            while(i < words.size() && trash.length() <= maxWidth){
                if(trash.length() + words[i].length() > maxWidth){
                    trash.erase(std::find_if(trash.rbegin(), trash.rend(),
                    [](int ch) {return !std::isspace(ch);}).base(),
                    trash.end());
                    break ;
                }
                trash += words[i] ;
                trash += " " ;
                i++ ;
            }
            trash.erase(std::find_if(trash.rbegin(), trash.rend(),
            [](int ch) {return !std::isspace(ch);}).base(),
            trash.end());
            ans.push_back(trash) ;
        }
        for(int a = 0 ; a < ans.size() - 1 ; a++){
            if(ans[a].length() == maxWidth){
                continue ;
            }
            int spaces = 0 ;
            for(int j = 0 ; j < ans[a].length() ; j++){
                if(ans[a][j] == ' '){
                    spaces++ ;
                }
            }
            int diff = maxWidth - ans[a].length() ;
            if(spaces == 0){
                while(diff > 0){
                    ans[a] += " " ;
                    diff-- ;
                }
            }
            else if(spaces != 0){
                int lim = diff/spaces ;
                int idxe = 0 ;
                while(idxe < ans[a].length()){
                    if(ans[a][idxe] == ' '){
                        ans[a].insert(idxe, lim, ' ') ;
                        idxe += lim + 1 ;
                    }
                    else{
                        idxe++ ;
                    }
                }
                int rem = diff%spaces ;
                int idx = 0 ;
                while(rem > 0){
                    if(ans[a][idx] == ' '){
                        ans[a].insert(idx, 1, ' ') ; 
                        rem-- ;
                        idx += 2 ; 
                    }else{
                        idx++ ; 
                    }
                }
            }
        }
        int oop = ans[ans.size() - 1].length() ;
        int diff2 = maxWidth - oop ;
        while(diff2 > 0){
            ans[ans.size() - 1] += ' ' ;
            diff2-- ;
        }
        return ans ;
    }
};