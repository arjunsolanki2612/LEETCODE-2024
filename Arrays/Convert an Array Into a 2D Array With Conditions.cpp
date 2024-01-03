/*
Ques: 2610. Convert an Array Into a 2D Array With Conditions
Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02
Topics: Array, Hash Table
------------------------------------------------------------------------------------------------------------------------------------------------------
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.
-------------------------------------------------------------------------------------------------------------------------------------------------------
Example 1:
Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.
------------------------------------------------------------------------------------------------------------------------------------------------------
Example 2:
Input: nums = [1,2,3,4]
Output: [[4,3,2,1]]
Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
----------------------------------------------------------------------------------------------------------------------------------------------------- 
Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= nums.length
*/

// Brute Force: TC: O(n*m), SC:O(n)
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        vector<vector<int>>ans;
        int maxFreq = INT_MIN;
        for(auto &x:mp){
            if(x.second>maxFreq){
                maxFreq = x.second;
            }
        }
        for(int i=0;i<maxFreq;i++){
            vector<int>res;
            for(auto &it:mp){
                if(it.second>0){
                    res.push_back(it.first);
                    it.second--;
                }
                
            }
            if(res.size()>=1){

            ans.push_back(res);
            }
        }
        return ans;
    }
};

// Optimised: TC: O(N), SC: O(N)
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<vector<int>>ans;

      // if the freq is zero then add to the zeroth row otherwise add to the next row and increase the freq of the element
        for(int i=0;i<nums.size();i++){
           int freq = mp[nums[i]];
           if(freq == ans.size())
           {
               ans.push_back({}); // add one more row
           }

           ans[freq].push_back(nums[i]);
           mp[nums[i]]++;
        }
        return ans;
    }
};
