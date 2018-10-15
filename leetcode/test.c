/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void test(char** strs, int length, char** res, char* temp, int index, int* elementNum){
    // printf("%d\n",*elementNum);
    char* letters;
    if (index == length){
        letters=(char*)malloc(sizeof(char)*(length+1));
        // printf("%c\n",temp[index-2]);
        temp[index] = '\0';
        // printf("%s\n",temp);
        strcpy(letters,temp);
        res[*elementNum] = letters;
        // printf("%s:%s\n",temp,letters);
        (*elementNum)++;
        return;
    }
    
    for (int i=0; i<strlen(strs[index]); i++){
        temp[index] = strs[index][i];
        printf("%c:%d:%d\n",temp[index],index,*elementNum);
        test(strs,length,res,temp,index+1,elementNum);
    }
}


char** letterCombinations(char* digits, int* returnSize) {
    int length = 0, numChars = 0;
    char letters[10][5] = {"", "" , "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    while(digits[length]){
        length++;
    }
    
    char** strs = (char**)malloc(sizeof(char*)*length);
   
    for (int i=0; i<length; i++){
        strs[i] = letters[digits[i]-'0'];
    }
    
    char** res = (char**)malloc(sizeof(char*)*(*returnSize));
    char* temp = (char*)malloc(sizeof(char)*length+1);
    int elementNum = 0;
    test(strs,length,res,temp,0,&elementNum);
    printf("%s\n",res[(*returnSize)-1]);
    return res;
}