#include <iostream>
#include <string>
using namespace std;

class Personne
{
protected:
    string nom;
    string prenom;
    int age;
    char sexe;

public:
    Personne(string n, string p, int a, char s)
        : nom(n), prenom(p), age(a), sexe(s)
    {
    }

    string getNom() const
    {
        return nom;
    }
    string getPrenom() const
    {
        return prenom;
    }
    int getAge() const
    {
        return age;
    }
    char getSexe() const
    {
        return sexe;
    }

    // Méthode Affiche
    virtual void Affiche() const
    {
        cout << "Nom: " << nom << ", Prénom: " << prenom
             << ", Age: " << age << ", Sexe: " << sexe << endl;
    }
};

class Etudiant : public Personne
{

    int note;

public:
    Etudiant(string n, string p, int a, char s, int note) : Personne(n, p, a, s), note(note)
    {
    }
};

int main()
{
    Personne *p = new Personne("Gamotte", "Albert", 34, 'M');
    p->Affiche();
    Etudiant e("Gamotte", "Albert", 34, 'M', 13);
    e.Affiche();
}