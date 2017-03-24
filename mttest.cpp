#include "mttest.h"

#include <iostream>
#include <memory.h>
#include <algorithm>

#define MAX_LENGTH 1024

using namespace::std;

// ********** MTString **********

MTString::MTString()
{

}

/*
 * set s[]
 */
bool MTString::set(char * temp)
{
    char * p = temp;
    int i = 0;
    length = 0;
    memset(s, 0, sizeof(s));
    while (*p && i < MAX_LENGTH) {
        s[i++] = *(p++);
    }
    if (i >= MAX_LENGTH) {
        flag = false;
        return false;
    }
    else {
        flag = true;
        length = i;
        // cout << i << endl;
        return true;
    }
}

/*
 * show s[]
 */
void MTString::show()
{
    if (flag)
        cout << s << endl;
    else
        cout << "The MTString is not correct ! \n";
}

/*
 * reverse s[] from start to end
 * time complexity  : O(N)
 * space complexity : O(1)
 */
bool MTString::mtReverse(int start, int end)
{
    if (!flag) {
        cout << "The MTString is not correct ! \n";
        return false;
    }
    else {
        if (start < 0 || start >= length || end < 0 || end >= length) {
            cout << "Bad array bound ! \n";
            return false;
        }
        if (start > end) {
            cout << "Start should be smaller than end ! \n";
            return false;
        }
        else {
            while (start < end) {
                char temp;
                temp = s[start];
                s[start++] = s[end];
                s[end--] = temp;
            }
            return true;
        }
    }
}

/*
 * judge if s[] is contained by b
 * time complexity  : O(N + M)
 * space complexity : O(1)
 */
bool MTString::stringContain(char * b)
{
    if (!flag) {
        cout << "The MTString is not correct ! \n";
        return false;
    }
    else {
        int hashA = 0;
        int hashB = 0;
        for (int i = 0; i < length; i++) {
            hashA |= (0x1 << (int)s[i]);
        }
        for (int i = 0; b[i] != '\0'; i++) {
            hashB |= (0x1 << (int)b[i]);
        }
        hashB = ~hashB;
        if ((hashA & hashB) == 0) {
            cout << "Is contained. \n";
            return true;
        }
        else {
            cout << "Is not contained. \n";
            return false;
        }
    }
}


/*
 * to get the next permutation of s[] and put into b
 * time complexity  : O(N)
 * space complexity : O(1)
 */
bool MTString::nextPermutation(char *b) {
    if (!flag) {
        cout << "The MTString is not correct ! \n";
        return false;
    }
    else {
        memset(b, 0, 100);
        for (int i = 0; i < length; i++) {
            b[i] = s[i];
        }

        // step 1
        int i;
        for (i = length - 2; i >= 0 && (s[i] >= s[i + 1]); i--){
            ;
        }
        if (i < 0) {
            cout << "The string \"" << s << "\" is the last permutation !\n";
            return false;
        }

        // step 2
        int k;
        for (k = length - 1; k > i && (s[k] <= s[i]); k--){
            ;
        }

        // step 3
        swap(b[i], b[k]);

        // step 4
        reverse(b + i + 1, b + length);

        return true;
    }
}

/*
 * to print all the permutations of s[] in dictionary order
 * time complexity  : O(N!)
 * space complexity : O(1)
 */
bool MTString::allPermutation(){
    if (!flag) {
        cout << "The MTString is not correct ! \n";
        return false;
    }
    else {
        char temp[MAX_LENGTH];
        memset(temp, 0, MAX_LENGTH);
        this->show();
        this->nextPermutation(temp);

        MTString *next = new MTString;
        next->set(temp);
        next->show();

        while (next->nextPermutation(temp)) {
            next->set(temp);
            next->show();
        }
        return true;
    }
}

/*
 * judge if s[] is a palindrome
 * time complexity  : O(N)
 * space complexity : O(1)
 */
bool MTString::isPalindrome() {
    if (!flag) {
        cout << "The MTString is not correct ! \n";
        return false;
    }
    else {
        char * left, * right;
        left = s;
        right = s + length - 1;
        while (left < right) {
            if (*left != *right) {
                cout << "\"" << s << "\" is not a palindrome. \n";
                return false;
            }
            left++;
            right--;
        }
        cout << "\"" << s << "\" is a palindrome. \n";
        return true;
    }
}
