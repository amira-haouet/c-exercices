#include <iostream>
using namespace std;

template <typename T>
T somme(T* tab, int taille) {
    T total = 0; 
    for (int i = 0; i < taille; ++i) {
        total += tab[i]; 
    }
    return total; 
}

// Programme principal
int main() {
    int ti[] = {3, 5, 2, 1};
    float tf[] = {2.5, 3.2, 1.8};
    char tc[] = {'a', 'e', 'i', 'o', 'u'};

    cout << "Somme des entiers : " << somme(ti, 4) << endl;
    cout << "Somme des flottants : " << somme(tf, 3) << endl;
    cout << "Somme des caractères (valeurs ASCII) : " << somme(tc, 5) << endl;

    return 0;
}
