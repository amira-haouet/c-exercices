#include <iostream>
using namespace std;
 
 class Chaine{
     public:
     const char * ch;
     
     Chaine(const char * ch){
         this->ch = ch;
         cout<<"constructeur"<<endl;
     }
     
     Chaine(const Chaine &chaine){
        this->ch=chaine.ch;
        cout <<"copyConstructeur"<<endl;

     }
     ~Chaine(){
         cout <<"distructeur" <<endl;
     }
     
    const char * afficher(){
         return this->ch;
     }
     
      bool egal(Chaine &c)
        {
            
           return  this->ch==c.ch; 
        }
            bool egal(Chaine &c)
        {
            
           return  this->ch==c.ch; 
        }
    

    Chaine& operator=(const Chaine& chaine) {
        if (this == &chaine) { // Éviter l'auto-affectation
           return *this;
        }
        this->ch= chaine.ch;
        cout << "operateur d'affectation" << endl;
        return *this;
    }
    
 };
 


 int main()
{ 
    Chaine c1("Bonjour"), c2=c1;
    cout << "La chaine c1 a pour valeur \"" << c1.afficher() << "\"\n";
    cout << "La chaine c2 a pour valeur \"" << c2.afficher() << "\"\n";
     if(c1.egal(c2)) cout << "Egalite des chaines \n";
    else cout << "Inegalite des chaines \n";


    return 0;
}

///

