class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int result = 0;
        vector<int> hist(matrix[0].size());
        for (const vector<char>& row : matrix) {
            for (int i = 0; i < row.size(); ++i)
                hist[i] = row[i] == '0' ? 0 : hist[i] + 1;
            result = max(result, largestarea(hist));
        }
        return result;
    }
private:
    int largestarea(const vector<int>& heights) {
        int result = 0;
        stack<int> stack;
        for (int i = 0; i <= heights.size(); ++i) {
            while (!stack.empty() && (i == heights.size() || heights[stack.top()] > heights[i])) {
                const int m = heights[stack.top()];
                stack.pop();
                const int v = stack.empty() ? i : i - stack.top() - 1;
                result = max(result, m * v);
            }
            stack.push(i);
        }
        return result;
    }
};
