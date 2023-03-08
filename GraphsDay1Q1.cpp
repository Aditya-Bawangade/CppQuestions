class Solution {
public:
    void utility(vector<vector<int>>& img, int sr, int sc, int color, int newcolor){
        if(img[sr][sc] == color){
            img[sr][sc] = newcolor;
            if(sr>=1){
                utility(img,sr-1,sc,color,newcolor);
            }
            if(sc>=1){
                utility(img,sr,sc-1,color,newcolor);
            }
            if(sc< img[0].size()-1){
                utility(img,sr,sc+1,color,newcolor);
            }
            if(sr< img.size()-1){
                utility(img,sr+1,sc,color,newcolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int clor = image[sr][sc];
       if(clor != color){
           utility(image,sr,sc,clor,color);
       } 
       return image;
    }
};