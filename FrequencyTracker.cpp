class FrequencyTracker {
    unordered_map<int,int> mp;
    unordered_map<int,int> freq ;
public:
    FrequencyTracker() {
        mp = {};
        freq = {} ;
    }
    
    void add(int number) {
        if(mp[number]>0){
            freq[mp[number]]--;
            mp[number]++;
            freq[mp[number]]++;
        }
        else{
            mp[number]++ ;
            freq[mp[number]]++;
        }
        return ;
    }
    
    void deleteOne(int number) {
        if(mp[number]>0){
            freq[mp[number]]--;
            mp[number]--;
            freq[mp[number]]++;
        }
        
        return ;
    }
    
    bool hasFrequency(int frequency) {
        return freq[frequency] > 0 ;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */