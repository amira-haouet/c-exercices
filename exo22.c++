#include <iostream>
using namespace std;

class Chaine
{
private:
    const char *ch;

public:
    Chaine(const char *ch)
    {
        this->ch = ch;
        cout << "constructeur" << endl;
    }

    Chaine(const Chaine &chaine)
    {
        this->ch = chaine.ch;
        cout << "copyConstructeur" << endl;
    }

    Chaine()
    {
        this->ch = "";
        cout << "constructeur par défaut" << endl;
    }
    ~Chaine()
    {
        cout << "distructeur" << endl;
    }

    const char *afficher()
    {
        return this->ch;
    }

    bool egal(Chaine &c)
    {
        return this->ch == c.ch;
    }

    Chaine &operator=(const Chaine &chaine)
    {
        if (this == &chaine)
        {
            return *this;
        }
        this->ch = chaine.ch;
        cout << "operateur d'affectation" << endl;
        return *this;
    }

    Chaine &operator+(const Chaine &chaine)
    {
        return;
    }

    Chaine &operator+(const Chaine &chaine)
    {
        return;
    }
};

int main()
{
    Chaine c1("Bonjour"), c2 = c1;
    cout << "La chaine c1 a pour valeur \"" << c1.afficher() << "\"\n";
    cout << "La chaine c2 a pour valeur \"" << c2.afficher() << "\"\n";
    if (c1.egal(c2))
        cout << "Egalite des chaines \n";
    else
        cout << "Inegalite des chaines \n";

    // Ajout d'un constructeur par défaut
    Chaine c3;
    c3 = c2;
    cout << "La chaine c3 a pour valeur \"" << c3.afficher() << "\"\n";
    c3 = "coucou";
    cout << "La chaine c2 a pour valeur \"" << c2.afficher() << "\"\n";

    cout << "La chaine c3 a pour valeur \"" << c3.afficher() << "\"\n";

    return 0;
}
