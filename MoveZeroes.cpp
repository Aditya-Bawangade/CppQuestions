  #include<iostream>
  #include<vector>
  using namespace std;
void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        vector<int>::iterator iter = nums.begin();
        vector<int>::iterator iter2 = nums.begin();
        while(iter != nums.end() && iter2 != nums.end()){
            if(*iter == 0 && *iter2 == 0){
                iter2++;
            }
            else if(*iter == 0 && *iter2 != 0){
                iter_swap(iter, iter2);
                iter++;
                iter2++;
            }
            else if(*iter != 0 && *iter2 != 0){
                iter++;
                iter2++;
            }
            else{
                return;
            }
           
        }
        return;
    }
int main()
{
    vector<int> a = {1,0,1,1,1};
    moveZeroes(a);
    for(int i = 0; i< a.size(); i++){
        cout<<a[i]<<" ";
    }
}
