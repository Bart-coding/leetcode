class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1)
        {
            auto maxEl_Iterator = std::max_element(stones.begin(), stones.end());
            int stoneY = *maxEl_Iterator;
            stones.erase(maxEl_Iterator);
            
            maxEl_Iterator = std::max_element(stones.begin(), stones.end());
            int stoneX = *maxEl_Iterator;
            
            if (stoneX == stoneY)
                stones.erase(maxEl_Iterator);
            else
                *maxEl_Iterator = stoneY - stoneX;
        }
        
        if (stones.size() == 0)
            return 0;
        return stones.back();
    }
};
