/*
Ques: 2125. Number of Laser Beams in a Bank
Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2024-01-03
Topics: Array, Math, String, Matrix
Medium
----------------------------------------------------------------------------------------------------------------------------------------------------------
Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, 
which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a 
security device.

There is one laser beam between any two security devices if both conditions are met:
The two devices are located on two different rows: r1 and r2, where r1 < r2.
For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with another.

Return the total number of laser beams in the bank.
----------------------------------------------------------------------------------------------------------------------------------------------------------
Input: bank = ["011001","000000","010100","001000"]
Output: 8
Explanation: Between each of the following device pairs, there is one beam. In total, there are 8 beams:
 * bank[0][1] -- bank[2][1]
 * bank[0][1] -- bank[2][3]
 * bank[0][2] -- bank[2][1]
 * bank[0][2] -- bank[2][3]
 * bank[0][5] -- bank[2][1]
 * bank[0][5] -- bank[2][3]
 * bank[2][1] -- bank[3][2]
 * bank[2][3] -- bank[3][2]
Note that there is no beam between any device on the 0th row with any on the 3rd row.
This is because the 2nd row contains security devices, which breaks the second condition.
--------------------------------------------------------------------------------------------------------------------------------------------------------
Constraints:
m == bank.length
n == bank[i].length
1 <= m, n <= 500
bank[i][j] is either '0' or '1'.
*/

class Solution {
public:

    //TC: O(nm) SC: O(1);
    int numberOfBeams(vector<string>& bank) {
        int prevCount = 0;
        int ans = 0;
        for(int i=0;i<bank.size();i++){
            int currDeviceCount = 0;
            for(char &ch:bank[i]){
                if(ch=='1'){
                    currDeviceCount++;
                }
            }

            ans = ans + (currDeviceCount*prevCount);
            if(currDeviceCount!=0){
                prevCount = currDeviceCount;
            }
        }
        return ans;
    }
};