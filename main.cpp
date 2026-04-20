#include <iostream>
#include <string>
using namespace std;

string naBinarny(int liczba) {
    if (liczba == 0) return "0";

    string wynik = "";
    while (liczba > 0) {
        wynik = char((liczba % 2) + '0') + wynik;
        liczba /= 2;
    }
    return wynik;
}

void wyrownaj(string &a, string &b) {
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
}

int main() {
    int x, y, wybor;
    string a, b, wynik = "";

    cout << "Podaj pierwsza liczbe dziesietna: ";
    cin >> x;

    cout << "Podaj druga liczbe dziesietna: ";
    cin >> y;

    a = naBinarny(x);
    b = naBinarny(y);

    cout << "Binarnie:\n";
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;

    cout << "\nWybierz operacje:\n";
    cout << "1 - AND\n";
    cout << "2 - OR\n";
    cout << "3 - XOR\n";
    cout << "4 - NOT (tylko pierwsza liczba)\n";
    cin >> wybor;

    switch (wybor) {
        case 1:
            wyrownaj(a, b);
            for (int i = 0; i < a.length(); i++) {
                if (a[i] == '1' && b[i] == '1')
                    wynik += '1';
                else
                    wynik += '0';
            }
            cout << "Wynik AND: " << wynik << endl;
            break;

        case 2:
            wyrownaj(a, b);
            for (int i = 0; i < a.length(); i++) {
                if (a[i] == '1' || b[i] == '1')
                    wynik += '1';
                else
                    wynik += '0';
            }
            cout << "Wynik OR: " << wynik << endl;
            break;

        case 3:
            wyrownaj(a, b);
            for (int i = 0; i < a.length(); i++) {
                if (a[i] != b[i])
                    wynik += '1';
                else
                    wynik += '0';
            }
            cout << "Wynik XOR: " << wynik << endl;
            break;

        case 4:
            for (int i = 0; i < a.length(); i++) {
                if (a[i] == '1')
                    wynik += '0';
                else
                    wynik += '1';
            }
            cout << "Wynik NOT: " << wynik << endl;
            break;

        default:
            cout << "Zly wybor!" << endl;
    }

    return 0;
}
