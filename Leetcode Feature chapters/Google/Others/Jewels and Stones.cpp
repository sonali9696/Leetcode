class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int l = jewels.size();
        map<char,int> jewelCache;
        for(int i=0; i<l; i++) jewelCache[jewels[i]] = 1;

        l = stones.size();
        int numberOfJewels = 0;
        for(int i=0; i<l; i++)
        {
            if(jewelCache.find(stones[i]) != jewelCache.end()) numberOfJewels++;
        }      

        return numberOfJewels;
    }
};

