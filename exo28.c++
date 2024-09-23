#include <iostream>
using namespace std;
class A
{
    int x;

public:
    A(int i = 0) { x = i; } // constructeur
    operator int()          // operateur de conversion d’un objet, instance de A, en int
    {
        cout << "**Appel de int() pour l’objet d’attribut " << x << endl;
        return x;
    }
};
