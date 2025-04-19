//Check if Number Has Equal Digit Count and Digit Value 
//You are given a 0-indexed string num of length n consisting of digits. 
//Return true if for every index i in the range 0 <= i < n, the digit i occurs num[i] times in num, otherwise return false

#include <stdio.h>
#include <string.h>
int digitCount(char* num) 
{
    int len = strlen(num);
    
    for(int i = 0; i < len; ++i) 
    {
        int freq = 0;
        for(int j = 0; j < len; ++j) 
        {
            if(num[j] == '0' + i) 
            {
                freq++;
            }
        }
        if(num[i] - '0' != freq) 
        { // check if frequencies of digit i is equal to num[i]
            return 0; // false
        }
    }
    return 1; // true
}

