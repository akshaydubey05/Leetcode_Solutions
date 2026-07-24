class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // Step 1: Extract unique elements
        unordered_set<int> unique_elements(nums.begin(), nums.end());
        
        int max_val = 0;
        for (int num : unique_elements) {
            max_val = max(max_val, num);
        }
        
        // Find the upper bound for XOR values (next power of 2)
        int max_xor_limit = 1;
        while (max_xor_limit <= max_val) {
            max_xor_limit <<= 1;
        }
        max_xor_limit <<= 1; 

        // visited[c][val] keeps track of whether XOR sum 'val' is reachable with 'c' elements
        vector<vector<bool>> visited(4, vector<bool>(max_xor_limit, false));
        // reachable[c] stores only the active, reachable XOR values with 'c' elements
        vector<vector<int>> reachable(4);
        
        visited[0][0] = true;
        reachable[0].push_back(0);

        // Step 2: Process each unique element up to 3 times
        for (int val : unique_elements) {
            for (int occurrence = 0; occurrence < 3; ++occurrence) {
                // Update backwards to prevent using the same occurrence multiple times in one step
                for (int chosen = 3; chosen >= 1; --chosen) {
                    int current_size = reachable[chosen - 1].size();
                    for (int i = 0; i < current_size; ++i) {
                        int prev_xor = reachable[chosen - 1][i];
                        int next_xor = prev_xor ^ val;
                        
                        if (!visited[chosen][next_xor]) {
                            visited[chosen][next_xor] = true;
                            reachable[chosen].push_back(next_xor);
                        }
                    }
                }
            }
        }

        // Step 3: The size of reachable[3] is the number of unique XOR values with exactly 3 elements
        return reachable[3].size();
    }
};