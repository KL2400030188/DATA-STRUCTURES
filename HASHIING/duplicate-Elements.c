//Find All Duplicates in an Array 
//Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the 
//integers that appears twice.You must write an algorithm that runs in O(n) time and use only constant auxiliary space, excluding the space needed to store the output 

int* findDuplicates(int* nums, int numsSize, int* returnSize) 
{
    int* A = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    for (int i = 0; i < numsSize; i++) 
    {
        if (nums[abs(nums[i]) - 1] < 0) 
        {
            A[count++] = abs(nums[i]);
        } else {
            nums[abs(nums[i]) - 1] *= -1;
        }
    }
    *returnSize = count;
    return A;
}
