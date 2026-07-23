class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int layer =0; layer < n/2; layer++){
            int first = layer;
            int last = n -1 - layer;
            for ( int col = first; col < last; col++){
                int offset = col - first;
                int top = matrix[first][col];
                // left to top 
                matrix[first][col] = matrix[last - offset][first];
                // bottom to left 
                matrix[last - offset][first] = matrix[last][last - offset];
                // right to bottom
                matrix[last][last - offset] = matrix[col][last];
                // top to right
                matrix[col][last] = top;
            }
        }
    }
};