/*
Ques: 1657. Determine if Two Strings Are Close
Link: https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14
Medium
Companies: Meta, Google

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 ---------------------------------------------------------------------------------------------------------------------------------------------------

Example 1:
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"

Example 2:
Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

Example 3:
Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
-------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        if(m!=n){
            return false;
        }

        // 1st point find the freq of each char
        vector<int>freq1(26);
        vector<int>freq2(26);
        for(int i=0;i<m;i++){
            char ch1 = word1[i];
            char ch2 = word2[i];

            freq1[ch1-'a']++;
            freq2[ch2-'a']++;
        }


        // check the whether the char in word1 and word2 are same or different
        for(int i=0;i<26;i++){
            if(freq1[i]!=0 && freq2[i]!=0) continue;
            if(freq1[i]==0 && freq2[i]==0) continue;

            return false;
        }

        //check if freq are equal in number 
        // if freq1 has freq of char like 2,3,1 then freq2 should also have freq of char like 2,3,1;

        sort(begin(freq1),end(freq1));
        sort(begin(freq2),end(freq2));

        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }
};
