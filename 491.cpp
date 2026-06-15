#include "leet.h"

class Solution {
public:
    vector<vector<int>> result;
    set<vector<int>> sequences;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       vector<int> sequence;
       backtrack(nums, sequence, 0);
       return result; 
    }
    void backtrack(vector<int>& nums, vector<int>& sequence, int start) {
        if (start > nums.size() - 1) {
            if (sequence.size() > 1) {
                if (!sequences.count(sequence)) {
                    result.push_back(sequence);
                    sequences.insert(sequence);
                }
            }
            return;
        }
        if (sequence.size() == 0 || sequence.back() <= nums[start]) {
            sequence.push_back(nums[start]);
            backtrack(nums, sequence, start+1);
            sequence.pop_back();
        }
        backtrack(nums, sequence, start+1);
    }
};