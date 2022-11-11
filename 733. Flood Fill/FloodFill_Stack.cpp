class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return image;
        
        stack<pair<int, int>> pixelsStack;
        pixelsStack.push({sr, sc});
        do {
            int i = pixelsStack.top().first;
            int j = pixelsStack.top().second;
            pixelsStack.pop();
            if (i != -1 && i != image.size() && j != -1 && j != image[0].size())
            {
                if (image[i][j] == oldColor)
                {
                    image[i][j] = newColor;

                    pixelsStack.push({i-1, j});
                    pixelsStack.push({i+1, j});
                    pixelsStack.push({i, j-1});
                    pixelsStack.push({i, j+1});
                }
            }
            
        } while (!pixelsStack.empty());
        
        return image;
    }
};
