/*
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]
*/
#include <stdlib.h>

void dfs(int** image, int m, int n, int r, int c, int originalColor, int newColor) {
    if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != originalColor) {
        return;
    }

    image[r][c] = newColor;

    dfs(image, m, n, r + 1, c, originalColor, newColor);
    dfs(image, m, n, r - 1, c, originalColor, newColor);
    dfs(image, m, n, r, c + 1, originalColor, newColor);
    dfs(image, m, n, r, c - 1, originalColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int m = imageSize;
    int n = imageColSize[0];
    int originalColor = image[sr][sc];

    if (originalColor != color) {
        dfs(image, m, n, sr, sc, originalColor, color);
    }

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}