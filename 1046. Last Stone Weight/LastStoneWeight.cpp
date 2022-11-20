class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        while (stones.size() > 1)
        {
            int stoneX = stones.rbegin()[1];
            int stoneY = stones.rbegin()[0];
            if (stoneX == stoneY)
            {
                stones.pop_back();
                stones.pop_back();
            }
            else
            {
                stones.pop_back();
                stones.back() = stoneY - stoneX;
                sort(stones.begin(), stones.end());
            }
        }
        
        if (stones.size() == 0)
            return 0;
        return stones.back();
    }
};
