// 22. Generate Parentheses

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void helperFunction(int n, char** res, char* tmp, int index, int l, int r, int* elementNum){
    
    if (l==0 && r==0){
        char* record=(char*)malloc(sizeof(char)*(index)); 
        tmp[index] = '\0';
        strcpy(record,tmp);
        res[*elementNum] = record;
        (*elementNum)++;
    }    
   
    if(l != 0){
        tmp[index] = '(';
        helperFunction(n, res, tmp, index+1, l-1, r, elementNum);
    }
    if(r != 0 && r>l){
        tmp[index] = ')';
        helperFunction(n, res, tmp, index+1, l, r-1, elementNum);
    } 
    
}

char** generateParenthesis(int n, int* returnSize) {
    char** res = (char*)malloc(sizeof(char)*(100000));
    char* tmp = (char*)malloc(sizeof(char)*(2*n+1));
    int elementNum = 0;    
    helperFunction(n, res, tmp, 0, n, n, &elementNum);    
    *returnSize = elementNum;
    return res;
} 