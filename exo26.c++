class Point
{
private:
    int d1;
    int d2;

public:
    int getD1()
    {
        return d1;
    }

    int getD2()
    {
        return d2;
    }
    Point(int x, int y) : d1(x), d2(y)
    {
    }
    ~Point()
    {
    }
};

class Segment
{
private:
    Point p1;
    Point p2;

public:
    Segment(Point x, Point y) : p1(x), p2(y)
    {
    }
    ~Segment()
    {
    }
};
