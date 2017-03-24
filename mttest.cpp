#include "mttest.h"

#include <iostream>
#include <memory.h>

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
 */
bool MTString::reverse(int start, int end)
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
 */
bool MTString::stringContain(char * b)
{
    return true;
}
