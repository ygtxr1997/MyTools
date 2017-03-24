#ifndef MTTEST_H
#define MTTEST_H

#define MAX_LENGTH 1024

class MTString
{
private:
    bool flag = false;
public:
    MTString();
    char s[MAX_LENGTH];
    int length = 0;

    bool set(char *);
    /*
     * to set the private s[] as a new char*
     * if set successfully , return true
     */

    void show();
    /*
     * to show the private s[]
     */

    bool mtReverse(int start, int end);
    /*
     * to reverse the private s[] from start to end
     */

    bool stringContain(char * b);
    /*
     * to judge if private s[] is contained by char* b
     */

    bool nextPermutation(char * b);
    /*
     * to get the next permutation of s[] in dictionary and put into b[]
     */

    bool allPermutation();
    /*
     * to print all the permutations of s[] in dictionary order
     */

    bool isPalindrome();
    /*
     * to judge if s[] is a palindrome
     */
};

#endif // MTTEST_H
