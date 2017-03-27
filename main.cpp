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
//        char testT[100];
//        cin >> testT;
//        s->set(testT);
//        s->isPalindrome();

//        ** test for mtManacher **
//        char testT[100];
//        cin >> testT;
//        s->set(testT);
//        char testM[100];
//        s->mtManacher(testM, sizeof(testM) / sizeof(int));
//        cout << testM << endl;

//        ** test for moveChar **
//        char testT[100];
//        cin >> testT;
//        s->set(testT);
//        char testB[100];
//        char c = '*';
//        s->moveChar(testB, c);
//        cout << testB << endl;

//        ** test for condenseDuplicate **
//        char testT[1000];
//        cin >> testT;
//        s->set(testT);
//        s->condenseDuplicate();

//        ** test for deleteChar **
//        char testT[1000];
//        cin >> testT;
//        s->set(testT);
//        char testModel[1000];
//        cin >> testModel;
//        s->deleteChar(testT, testModel);
//        cout << testT << endl;



//        -------------^ end ^-------------

//        ********** test for MTArray **********
        int testA[100];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> testA[i];
        }
        MTArray *mta = new MTArray;
        mta->set(testA, n);
        // mta->show();

//        ** test for maxSum **
//        int testB_length = 100;
//        int & length = testB_length;
//        int *testB = new int[testB_length];
//        mta->maxSum(testB, length);
//        for (int i = 0; i < length; i++) {
//            cout << testB[i] << ' ';
//        }
//        cout << endl;



    }

    return a.exec();
}
