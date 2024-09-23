#include <iostream>

class Vect {
    int nbElements;  
    int* Adresse;    // Adresse de la zone dynamique contenant les éléments

public:
    Vect(int taille) {
        nbElements = taille;
        Adresse = new int[nbElements];  // Allouer dynamiquement un tableau d'entiers
        for (int i = 0; i < nbElements; ++i) {
            Adresse[i] = 0;  
        }
    }

    // Destructeur pour libérer la mémoire
    ~Vect() {
        delete[] Adresse;  // Libérer la mémoire allouée dynamiquement
    }

    // Surcharge de l'opérateur [] pour accéder à un élément par son indice
    int& operator[](int index) {
        if (index >= 0 && index < nbElements) {
            return Adresse[index];
        } else {
            std::cerr << "Index out of bounds!" << std::endl;
            exit(EXIT_FAILURE);  
        }
    }
};

int main() {
    Vect vect(5);

    vect[0] = 10;
    vect[1] = 20;
    vect[2] = 30;
    std::cout << "Élément à l'indice 0: " << vect[0] << std::endl;
    std::cout << "Élément à l'indice 1: " << vect[1] << std::endl;
    std::cout << "Élément à l'indice 2: " << vect[2] << std::endl;
    return 0;
}

