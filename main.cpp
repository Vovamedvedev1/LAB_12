#include <iostream>
#include "vect.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Enter n"; cin >> n;
    Vector<int>v1(n);
    Vector<double>v2(n);
    Vector<char>v3(n);
    cout << "��������� ������ v1 int" << endl;
    cin >> v1;
    cout << "��������� ������ v2 double" << endl;
    cin >> v2;
    cout << "��������� ������ v3 char" << endl;
    cin >> v3;
    cout << "------------------------------------" << endl;
    cout << " v1 = " << v1 << endl;
    cout << " v2 = " << v2 << endl;
    cout << " v3 = " << v3 << endl;
    cout << " v1 + v2 = " << v1 + v2 << endl;
    cout << " v1 - v2 = " << v1 - v2 << endl;
    cout << " v1 * v2 = " << v1 * v2 << endl;
    cout << " v1 + v3 = " << v1 + v3 << endl;
    cout << " v3 - v1 = " << v3 - v1 << endl;
    cout << " v1 * v3 = " << v1 * v3 << endl;
    cout << "-------------------------------------" << endl;
    Vector<string>s1(n);
    Vector<string>s2(n);
    cout << "��������� ������ s1 string" << endl;
    cin >> s1;
    cout << "��������� ������ s2 string" << endl;
    cin >> s2;
    cout << " s1 = " << s1 << endl;
    cout << " s2 = " << s2 << endl;
    cout << " s1 + s2 = " << s1 + s2 << endl;
    cout << " s1 - s2 = " << s1 - s2 << endl;
    cout << " s1 * s2 = " << s1 * s2 << endl;
    return 0;
}
