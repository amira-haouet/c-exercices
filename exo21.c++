#include <iostream>
using namespace std;

class Fraction
{
    private: 
     int den;
     int num;
     
     
    public:
    Fraction()
    {
       this->den=1;
       this->num=0;
    }
    
    Fraction(int num, int den)
    {
         this->den=den;
         this->num=num;
         
    }
    int Signe() {
        if ((num/den) >= 0)
        {
         return 1;   
        }
        else{
         return -1;
        }
    }
    
     void Afficher(){
         cout << num << "/" << den<< endl;
     }
     
     float Valeur()
     {
         return (int) num/den;
     }
     

     void Simplifier() 
     {
      cout << num/pgcd(num,den) << "/" << den/pgcd(num,den)<< endl;

     }
     
     int pgcd (int a, int b){
         
         if(b==0)
         {
             return a;
         }
         else {
          return  pgcd(b,b%a);
         }
          
     }
     
     Fraction Inverse(){
          Fraction f(den,num);
          return f;
     }
     
     
     int compare(const Fraction& f, const Fraction& g) {
    int produit1 = f.getNum() * g.getDen(); // num_f * den_g
    int produit2 = g.getNum() * f.getDen(); // num_g * den_f
    
    if (produit1 > produit2) {
        return 1; // f > g
    } else if (produit1 == produit2) {
        return 0; // f == g
    } else {
        return -1; // f < g
    }
}
     
};

  int main()
  {
     Fraction f1(24,18);
     cout << "la signe: "<< f1.Signe()<< endl;
     f1.Afficher();
     f1.Simplifier();
     cout << "val: " << f1.Valeur()<< endl;
      Fraction f2=f1.Inverse();
     cout << "val: " << f2.Valeur() << endl;

  }