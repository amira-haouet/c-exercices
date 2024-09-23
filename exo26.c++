#include <cmath>
#include <iostream>
using namespace std;

class Point {
private:
    int d1;
    int d2;

public:
    // Constructeur
    Point(int x, int y) : d1(x), d2(y) {}

    int getD1()  { return d1; }
    int getD2()  { return d2; }

    bool operator==(const Point& other)  {
        return d1 == other.d1 && d2 == other.d2;
    }
};

class Segment {
private:
    Point p1;
    Point p2;

public:
    // Constructeur
    Segment(Point x, Point y) : p1(x), p2(y) {}

    // calcul la norme
    double Norme()  {
        return sqrt(pow(p2.getD1() - p1.getD1(), 2) + pow(p2.getD2() - p1.getD2(), 2));
    }

    bool operator==(const Segment& other)  {
        return (p1 == other.p1 && p2 == other.p2) || (p1 == other.p2 && p2 == other.p1);
    }
};

class Vecteur : public Segment {
public:
    // Constructeur
    Vecteur(Point x, Point y) : Segment(x, y) {}

    // bool operator==(const Vecteur& other)  {
    //     return Segment::operator==(other);
    // }
};

int main() {
    Point p1(1, 2);
    Point p2(4, 6);
    Segment s(p1, p2);
    Vecteur v(p1, p2);

    cout << "Norme du segment: " << s.Norme() << endl;
    cout << "Segment et Vecteur sont equal: " << (s == v) << endl;

    return 0;
}
