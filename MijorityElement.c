/*
    The intuition behind the Moore's Voting Algorithm is based on the fact 
    that if there is a majority element in an array, 
    it will always remain in the lead, even after encountering other elements.
*/


int majorityElement(int* nums, int numsSize) 
{
    int counter = 0;
    int MajorityElement;

    for(int i = 0; i < numsSize; i++)
    {
        // each element encounters the next different element, until the majority element remains (take the lead)
        if(counter == 0)
        {
            MajorityElement = nums[i];
        }
        if(nums[i] == MajorityElement)
        {
            counter++;
        }
        else 
        {
            counter--;
        }
    }
    return MajorityElement;
}