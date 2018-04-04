#ifndef Vector2D_H
#define Vector2D_H
#include <cmath>

class Vector2D
{
    public:
        Vector2D(double x, double y);
        Vector2D();
        virtual ~Vector2D();
        Vector2D(const Vector2D& v): x(v.x), y(v.y){}
        double length();
        Vector2D operator = (Vector2D v)
        {
            return Vector2D(x=v.x, y=v.y);
        }
        Vector2D operator + (Vector2D v)
        {
            return Vector2D(x+v.x, y+v.y);
        }
        Vector2D operator - (Vector2D v)
        {
            return Vector2D(x-v.x,y-v.y);
        }
        double operator * (Vector2D v)
        {
            return (x*v.x + y*v.y);
        }
        Vector2D operator * (double n)
        {
            return Vector2D(x*n,y*n);
        }
        Vector2D operator / (double n)
        {
            if(n == 0)
            {
                return Vector2D(x,y);
            }
            return Vector2D(x/n, y/n);

        }
        double getX(){return x;}
        double getY(){return y;}
        void setX(double x){ this->x = x;}
        void setY(double y){ this->y = y;}
        Vector2D normalized();
        Vector2D projectedOn(Vector2D v);
        double x;
        double y;
    protected:
    private:
};

#endif // Vector2D_H
