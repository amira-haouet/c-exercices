#include <iostream>
#include <string>

class Personne {
protected:
    std::string nom;
    std::string prenom;
    int age;
    char sexe;

public:
    Personne(std::string n, std::string p, int a, char s)
        : nom(n), prenom(p), age(a), sexe(s) {}

  
};



class Etudiant : public Personne {
    int note;

public:
    // Constructeur
    Etudiant(std::string n, std::string p, int a, char s, int note)
        : Personne(n, p, a, s), note(note) {}

 
};
