#include <QCoreApplication>
#include <iostream>

using namespace::std;

#include "mttest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MTString *s = new MTString;
    char testS[5] = "abca";
    if (s->set(testS))
        cout << "success" << endl;
    else
        cout << "false" << endl;
    s->show();

    while (1) {
//        ** test for reverse **
//        int i, j;
//        cin >> i >> j;
//        if (s->reverse(i, j))
//            cout << "success" << endl;
//        else
//            cout << "false" << endl;
//        s->show();

//        cout << endl;


//        ** test for stringContain **
//        char testT[100];
//        cin >> testT;
//        s->stringContain(testT);

//        ** test for nextPermutation **
//        char testB[100];
//        cin >> testB;
//        s->nextPermutation(testB);
//        s->set(testB);
//        s->show();

//        ** test for allPermutation **
//        s->allPermutation();
//        system("pause");

//        ** test for isPalindrome **
        char testT[100];
        cin >> testT;
        s->set(testT);
        s->isPalindrome();
    }

    return a.exec();
}
