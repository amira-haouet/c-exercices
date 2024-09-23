#include <iostream>
using namespace std;

class Base {
    int att1;
public:
    Base(int i = 0) { att1 = i; }
    void afficher() {
        cout << "Objet de la classe de Base d’attribut 1 = " << att1 << endl;
    }
    int GetAtt1() { return att1; }
};

// Dérivation de la classe Derivee de manière publique
class Derivee : public Base {
    int att2; // Un nouvel attribut pour la classe dérivée
public:
    Derivee(int i = 0, int j = 0) : Base(i), att2(j) {} // Constructeur

    void afficher() { // Redéfinir la méthode afficher
        Base::afficher(); // Appeler la méthode de la classe de base
        cout << "Objet de la classe Derivee d’attribut 2 = " << att2 << endl;
    }

    int GetAtt2() { return att2; } // Méthode pour obtenir att2
};

int main() {
    Derivee obj(5, 10); // Création d'un objet de la classe Derivee
    obj.afficher(); // Affichage des attributs
    return 0;
}
