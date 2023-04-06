#include <iostream>
#include <vector>

class Solution {
public:

    void dfs(std::vector<std::vector<int>>& image, int i, int j, int colour, int newColour){

        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size()) return; // If the pixel is out of bounds, return

        if (image[i][j] != newColour) return; // If the pixel is not the same colour as the starting pixel, return

        image[i][j] = colour; // Fill in the pixel

        // Fill in the 4 connected pixels using dfs
        dfs(image, i-1, j, colour, newColour);
        dfs(image, i+1, j, colour, newColour);
        dfs(image, i, j-1, colour, newColour);
        dfs(image, i, j+1, colour, newColour);
    }

    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {

        if(image[sr][sc] == color) return image; // If the starting pixel is already the same colour as the new colour, return

        dfs(image, sr, sc, color, image[sr][sc]); // Call dfs on the starting pixel

        return image;
    }
};

int main() {

    Solution s;
    std::vector<std::vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};

    std::vector<std::vector<int>> result = s.floodFill(image, 1, 1, 2);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
