class Solution {
public:
    void floodFillHelper(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {
        if (i != -1 && i != image.size() && j != -1 && j != image[0].size())
        {
            if (image[i][j] == oldColor)
            {
                image[i][j] = newColor;
                floodFillHelper(image, i-1, j, oldColor, newColor);
                floodFillHelper(image, i+1, j, oldColor, newColor);
                floodFillHelper(image, i, j-1, oldColor, newColor);
                floodFillHelper(image, i, j+1, oldColor, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return image;
        floodFillHelper(image, sr, sc, oldColor, newColor);
        
        return image;
    }
};
