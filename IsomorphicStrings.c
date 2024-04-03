/*
    Given two strings s and t, determine if they are isomorphic.
    Two strings s and t are isomorphic if the characters in s can be replaced to get t.
    All occurrences of a character must be replaced with another character while preserving the order of characters. 
    No two characters may map to the same character, but a character may map to itself.

    Example 1:
    Input: s = "egg", t = "add"
    Output: true

    Example 2:
    Input: s = "foo", t = "bar"
    Output: false

    Example 3:
    Input: s = "paper", t = "title"
    Output: true
    
    Constraints:

    1 <= s.length <= 5 * 104
    t.length == s.length
    s and t consist of any valid ascii character.
*/
bool isIsomorphic(char* s, char* t) 
{
    /*
        make hash map for each string    
    */
    int *Fqs = (int*)calloc(127, sizeof(int));
    int *Fqt = (int*)calloc(127, sizeof(int));
    int len = strlen(s);
    bool result = 1;
    for(int i = 0; i < len; i++)
    {
        if(Fqs[s[i]] == 0)         // add new value
        {
            Fqs[s[i]] = (t[i]);
        }   
        else          // check if storing value is equal to new value or not 
        {
            if(Fqs[s[i]] != t[i])
            {
                result = 0;
                break;
            }
        }
        if(Fqt[t[i]] == 0)
        {
            Fqt[t[i]] = s[i];
        }   
        else
        {
            if(Fqt[t[i]] != s[i])
            {
                result = 0;
                break;
            }
        }
    }
    free(Fqs);
    free(Fqt);
    return result ;
}