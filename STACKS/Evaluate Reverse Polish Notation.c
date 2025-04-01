int evalRPN(char** tokens, int tokensSize) 
{
    int* stack = calloc(tokensSize + 1, sizeof(int));
    int stackPtr = 0;
    for (int tokenPtr = 0; tokenPtr < tokensSize; tokenPtr++) {
        char* token = tokens[tokenPtr];
        // Single character and non-numeric
        if (token[1] == '\0' && (token[0] < '0' || token[0] > '9')) 
        {
            int arg2 = stack[--stackPtr]; // pop
            int arg1 = stack[--stackPtr]; // pop
            switch (token[0]) 
            {
            case '*':
                stack[stackPtr++] = arg1 * arg2;
                break;
            case '+':
                stack[stackPtr++] = arg1 + arg2;
                break;
            case '-':
                stack[stackPtr++] = arg1 - arg2;
                break;
            case '/':
                // Truncate towards zero
                stack[stackPtr++] = arg1 / arg2;
                break;
            // default: unknown operation!
            }
        } else {
            int isNeg = token[0] == '-';
            stack[stackPtr++] = atoi(token + isNeg) * (isNeg ? -1 : 1); 
        }
    }
    return stack[--stackPtr]; // pop
}
