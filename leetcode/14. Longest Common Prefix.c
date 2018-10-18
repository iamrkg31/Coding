// 14. Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"

// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Note:

// All given inputs are in lowercase letters a-z.

char* longestCommonPrefix(char** strs, int strsSize) {
    char* res = strs[0];
    int j = 0;
    if (strsSize==0) return "";
    for(int i=0; i<strlen(res); i++){
        int flag = 0;
        for (int j=0; j<strsSize; j++){
            if (strs[j][i] != res[i]){
                flag = 1;
                break;
            }
        }
        if (flag==1) res[i] = '\0';
    }
    return res;
}