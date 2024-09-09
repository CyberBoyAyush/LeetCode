class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Create a result 2D matrix filled with zeros
        vector<vector<int>> res(n, vector<int>(n, 0));

        int id = 0;  // 0, 1, 2, 3 -> pointer that tells us the current direction
        int top = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;

        int num = 1; // This will hold the current number to be filled into the matrix

        while (left <= right && top <= down) {
            if (id == 0) {
                // Move left to right
                for (int i = left; i <= right; i++) {
                    res[top][i] = num++;
                }
                top++; // Shrink the top boundary
            }

            else if (id == 1) {
                // Move top to down
                for (int i = top; i <= down; i++) {
                    res[i][right] = num++;
                }
                right--; // Shrink the right boundary
            }

            else if (id == 2) {
                // Move right to left
                for (int i = right; i >= left; i--) {
                    res[down][i] = num++;
                }
                down--; // Shrink the down boundary
            }

            else if (id == 3) {
                // Move down to top
                for (int i = down; i >= top; i--) {
                    res[i][left] = num++;
                }
                left++; // Shrink the left boundary
            }

            // Change direction in the order: 0 -> 1 -> 2 -> 3 -> 0 (spiral order)
            id = (id + 1) % 4;
        }

        return res;
    }
};
