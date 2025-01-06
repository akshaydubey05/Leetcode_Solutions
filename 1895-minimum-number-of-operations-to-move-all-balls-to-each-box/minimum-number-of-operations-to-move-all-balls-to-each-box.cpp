class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> answer(n, 0); // Stores the final result
        int totalBalls = 0; // Total number of balls in all boxes

        // Calculate operations to move all balls to the first box
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') { 
                totalBalls++; // Count the number of balls
                answer[0] += i; // Accumulate distance to the first box
            }
        }

        int rightBalls = totalBalls; // Balls to the right of the current box

        if (boxes[0] == '1') rightBalls--; // Adjust for the first box

        // Calculate operations for remaining boxes
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i - 1] - rightBalls + (totalBalls - rightBalls);
            if (boxes[i] == '1') rightBalls--; // Update rightBalls for current box
        }

        return answer;
    }
};