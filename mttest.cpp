#include "mttest.h"

#include <iostream>
#include <memory.h>
#include <algorithm>

#define MAX_LENGTH  1024
#define Min(a, b)   a < b ? a : b
#define Max(a, b)   a > b ? a : b

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

/*
 * find the longest palindrome of s[]
 * time complexity  : O(N)
 * space complexity : O(N)
 */
bool MTString::mtManacher(char *m, int m_length) {
    if (!flag) {
        cout << "The MTString is not correct ! \n";
        return false;
    }
    else {
        int mx = 0;
        int id;
        int longestMX = 0;
        int longestID = 0;
        int P[MAX_LENGTH << 1];
        char S[MAX_LENGTH << 1];
        memset(P, 0, sizeof(P));
        memset(S, 0, sizeof(S));
        S[0] = '$';
        for (int i = 1; i <= (length * 2) + 1; i++) {
            if (i % 2 == 1)
                S[i] = '#';
            else
                S[i] = s[(i / 2) - 1];
        } // set S[] and P[]

//        cout << "s[] is " << s << " and length is "<< length << endl;
//        cout << "S[] is " << S << endl;

        for (int i = 0; i < ((length + 1) * 2); i++) {
            if (mx > i)
                P[i] = Min(P[2 * id - 1], mx - i);
            else
                P[i] = 1;
            while (S[i + P[i]] == S[i - P[i]])
                P[i]++;
            if (P[i] + i > mx) {
                mx = P[i] + i;
                id = i;
            }
            if (mx - id > longestMX - longestID) {
                longestMX = mx;
                longestID = id;
            }
        } // Manacher algorithm

//        for (int i = 0; P[i] != 0; i++) {
//            cout << P[i];
//        }
//        cout << endl;
//        cout << "mx = " << mx << " and id = " << id << endl;
//        cout << "longestMX = " << longestMX << " and longsetID = " << longestID << endl;

        memset(m, 0, m_length);
        int p = 0;
        for (int i = 2 * longestID - longestMX + 1; i < longestMX; i++) {
            if (i % 2 == 0)
                m[p++] = S[i];
        }
        cout << "The longest palidrome is " << m << '.' <<endl;

        return true;
    }
}


/*
 * move all the char c in s[] to left
 * time complexity  : O(N)
 * space complexity : O(N)
 */
bool MTString::moveChar(char *b, char c) {
    if (!flag) {
        cout << "The MTString is not correct ! \n";
        return false;
    }
    else {
        int k = 0;
        for (int i = 0; i < length; i++) {
            if (s[i] == c)
                b[k++] = c;
        }
        for (int i = 0; i < length; i++) {
            if (s[i] != c)
                b[k++] = s[i];
        }
        return true;
    }
}

/*
 * condense the duplicate parts of s[]
 */
bool MTString::condenseDuplicate() {
    if (!flag) {
        cout << "The MTString is not correct ! \n";
        return false;
    }
    else {
        int stack[MAX_LENGTH];
        memset(stack, 0, sizeof(stack));
        stack[0] = 1;
        stack[1] = s[0];
        int next = 1, top = 1;
        for (; next < length; next++) {
            if (s[next] == stack[top]) {
                stack[top - 1]++;
            }
            else {
                stack[top + 1] = 1;
                stack[top + 2] = s[next];
                top += 2;
            }
        }

        for (int i = 0; i <= top; i++) {
            if (stack[i] != 1) {
                switch (i % 2) {
                case 1:
                    cout << (char)stack[i];
                    break;
                default:
                    cout << stack[i];
                    break;
                }
            }
        }
        cout << endl;

        return true;
    }
}
