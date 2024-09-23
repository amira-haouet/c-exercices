#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Personne {
private:
    char *nom;
    char *prenom;
    int age;
    char sexe;

public:
    Personne(const char *n, const char *p, int a, char s)
        : age(a), sexe(s) // Initialisation des membres non pointeurs
    {
        nom = new char[strlen(n) + 1];
        strcpy(nom, n);
        
        prenom = new char[strlen(p) + 1];
        strcpy(prenom, p);
    }

    ~Personne() { // Ajout du destructeur pour libérer la mémoire
        delete[] nom;
        delete[] prenom;
    }

    string getNom() const {
        return nom;
    }

    string getPrenom() const {
        return prenom;
    }

    int getAge() const {
        return age;
    }

    char getSexe() const {
        return sexe;
    }

    void Affiche() const {
        cout << "Nom: " << nom << ", Prénom: " << prenom
             << ", Age: " << age << ", Sexe: " << sexe << endl;
    }
};

class Etudiant : public Personne {
private:
    int note;

public:
    Etudiant(const char* n, const char* p, int a, char s, int note)
        : Personne(n, p, a, s), note(note) {
    }

    void Affiche() const {
        cout << "Nom: " << getNom() << ", Prénom: " << getPrenom()
             << ", Age: " << getAge() << ", Sexe: " << getSexe()
             << ", Note: " << getNote() << endl;
    }

    int getNote() const {
        return note;
    }
};

int main() {
    Personne p("Gamotte", "Albert", 34, 'M');
    p.Affiche();
    
    Etudiant e("Gamotte", "Albert", 34, 'M', 13);
    e.Affiche();

    return 0;
}
