int minInsertions(char* s) 
{
    int n=strlen(s);
    int left=0,insert_left=0,insert_right=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') left++; 
        else{
            if(i+1<n && s[i+1]==')'){
                if(left<=0) insert_left++;
                else left--;
                i++;
            }
            else{
                insert_right++;
                if(left>0) left--;
                else insert_left++;
            }
        }
    }
    return left*2+insert_right+insert_left;
}
