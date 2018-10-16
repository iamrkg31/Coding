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
    
    if()
    
}
char** generateParenthesis(int n, int* returnSize) {
    // for storing results
    char** res = (char*)malloc(sizeof(char)*(1000));
    char* temp = (char*)malloc(sizeof(char)*(2*n+1));
    int elementNum = 0;
    helperFunction(n, res, tmp, index, l, r, &elementNum);
    return;
} 