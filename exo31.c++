#include <iostream>

class Cellule {
    friend class ListeChainee;
    int valeur;
    Cellule* suivant;
    
public:
    Cellule(int v = 0) : valeur(v), suivant(nullptr) {} // constructeur
    ~Cellule() { delete suivant; } // destructeur
    
    Cellule(const Cellule &c) : valeur(c.valeur), suivant(c.suivant ? new Cellule(*c.suivant) : nullptr) {} // copy constructeur
    
    void afficher() {
        std::cout << valeur << " ";
    }
    
    int GetValeur() {
        return valeur;
    }
    
    Cellule* GetSuivant() {
        return suivant;
    }
    
    Cellule& operator=(const Cellule& c) {
        if (this != &c) {
            valeur = c.valeur;
            if (suivant) delete suivant;
            suivant = c.suivant ? new Cellule(*c.suivant) : nullptr;
        }
        return *this;
    }
    
    bool operator==(const Cellule &c) {
        return valeur == c.valeur;
    }
};
