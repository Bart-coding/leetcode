class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return image;
        
        queue<pair<int, int>> pixelsQueue;
        pixelsQueue.push({sr, sc});
        do {
            int i = pixelsQueue.front().first;
            int j = pixelsQueue.front().second;
            pixelsQueue.pop();
            if (i != -1 && i != image.size() && j != -1 && j != image[0].size())
            {
                if (image[i][j] == oldColor)
                {
                    image[i][j] = newColor;

                    pixelsQueue.push({i-1, j});
                    pixelsQueue.push({i+1, j});
                    pixelsQueue.push({i, j-1});
                    pixelsQueue.push({i, j+1});
                }
            }
            
        } while (!pixelsQueue.empty());
        
        return image;
    }
};
