#include <iostream>
using namespace std;

class Pile {
    const int max;
    int* tab;
    int sommet = 0;
    
public:
    Pile(int max) : max(max) {
        tab = new int[max];  
        for (int i = 0; i < max; i++) {
            tab[i] = 0;  
        }
    }

    ~Pile() {
        delete[] tab;
    }

    bool estVide() const {
        return sommet == 0;
    }

    int SommetDePile() const {
        return sommet;
    }

    void Empiler(int nb) {
        if (sommet == max) {
            cout << "Pile pleine" << endl;
        } else {
            tab[sommet] = nb;
            sommet++;
        }
    }

    void Depiler() {
        if (estVide()) {
            cout << "Pile vide" << endl;
        } else {
            sommet--;
            tab[sommet] = 0;
        }
    }

    void afficher() const {
        for (int i = 0; i < sommet; i++) {
            cout << tab[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Pile p(5);
    
    if (p.estVide()) {
        cout << "La pile est vide." << endl;
    }

    p.Empiler(10);
    p.Empiler(20);
    p.Empiler(30);
    
    cout << "Sommet de la pile: " << p.SommetDePile() << endl;
    p.afficher();

    p.Depiler();
    cout << "Sommet de la pile après dépilement: " << p.SommetDePile() << endl;
    p.afficher();

    if (p.estVide()) {
        cout << "La pile est maintenant vide." << endl;
    } else {
        cout << "La pile n'est pas vide." << endl;
    }

    return 0;
}
