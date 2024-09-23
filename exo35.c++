#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// Classe abstraite Base
class Base {
public:
    virtual void Afficher() const = 0; // Fonction virtuelle pure
    virtual ~Base() {} // Destructeur virtuel
};

// Classe Point
class Point : public Base {
private:
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {}

    void Afficher() const override {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

// Classe Chaine
class Chaine : public Base {
private:
    string chaine;
public:
    Chaine(const string& str) : chaine(str) {}

    void Afficher() const override {
        cout << "Chaine: " << chaine << endl;
    }
};

// Classe Ens_Heter
class Ens_Heter {
private:
    vector<shared_ptr<Base>> elements; // Utilisation de shared_ptr pour gérer la mémoire
    size_t courant;

public:
    Ens_Heter() : courant(0) {}

    void Ajouter(Base& elem) {
        elements.push_back(shared_ptr<Base>(&elem)); // Ajout d'un élément à la fin
    }

    bool Appartient(Base& elem) {
        for (const auto& e : elements) {
            if (e.get() == &elem) return true; // Teste l'appartenance
        }
        return false;
    }

    int GetNbElem() const {
        return elements.size(); // Retourne le nombre d'éléments
    }

    const Base& Suivant() {
        if (courant < elements.size()) {
            return *elements[courant++];
        } else {
            // Retourne un objet bidon constant si on est à la fin
            static Point dummy(0, 0);
            return dummy;
        }
    }

    bool Fin() const {
        return courant == elements.size(); // Indique si on a atteint le dernier élément
    }

    void Afficher() const {
        for (const auto& e : elements) {
            e->Afficher(); // Affiche les valeurs des éléments de la liste
        }
    }
};

// Programme principal
int main() {
    Point p(1, 3);
    Chaine ch("Bonjour");
    Ens_Heter e;

    cout << "Nombre d'éléments dans la liste : " << e.GetNbElem() << endl;
    cout << "Contenu de l'ensemble : " << endl;
    e.Afficher();

    e.Ajouter(p);
    cout << "Nombre d'éléments dans la liste : " << e.GetNbElem() << endl;
    cout << "Contenu de l'ensemble : " << endl;
    e.Afficher();

    e.Ajouter(ch);
    cout << "Nombre d'éléments dans la liste : " << e.GetNbElem() << endl;
    cout << "Contenu de l'ensemble : " << endl;
    e.Afficher();

    return 0;
}
