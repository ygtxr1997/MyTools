#include <QCoreApplication>
#include <iostream>

using namespace::std;

#include "mttest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MTString *s = new MTString;
    char testS[5] = "abcd";
    if (s->set(testS))
        cout << "success" << endl;
    else
        cout << "false" << endl;
    s->show();

    while (1) {
        int i, j;
        cin >> i >> j;
        if (s->reverse(i, j))
            cout << "success" << endl;
        else
            cout << "false" << endl;
        s->show();

        cout << endl;
    }

    return a.exec();
}
