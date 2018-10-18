// 17. Letter Combinations of a Phone Number

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example:

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void test(char** strs, int length, char** res, char* temp, int index, int* elementNum){
    char* letters;
    if (index == length){
        
        letters=(char*)malloc(sizeof(char)*(length+1));       
        temp[index] = 0;      
        strcpy(letters,temp);
        
        res[*elementNum] = letters;       
        (*elementNum)++;
        
        return;
    }
    
    for (int i=0; i<strlen(strs[index]); i++){
        temp[index] = strs[index][i];
        test(strs,length,res,temp,index+1,elementNum);
    }
}


char** letterCombinations(char* digits, int* returnSize) {
    int length = 0, num = 1, elementNum = 0;
    char letters[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    // if empty string is passed
    if (!digits[length]){
        return;
    }    
    // length of input string
    while(digits[length]){
        if (digits[length] == '7' || digits[length] == '9') {num *= 4;}
        else if (digits[length] != '0' || digits[length] != '1') {num *= 3;}
        length++;
    }
    // for each character in input string, assign a alphabetical string
    // allocate memory dynamically
    char** strs = (char**)malloc(sizeof(char*)*length);   
    for (int i=0; i<length; i++){
        strs[i] = letters[digits[i]-'0'];
    }    
    // for storing results
    char** res = (char**)malloc(sizeof(char*)*(num));
    char* temp = (char*)malloc(sizeof(char)*length+1);
    
    test(strs,length,res,temp,0,&elementNum);
    *returnSize = elementNum;
    
    return res;
}