#ifndef CIRCLE_H
#define CIRCLE_H

#include "../object/Object.h"

class Circle : public Object
{
public:

    Circle(const double radius);
    Circle(void);
    virtual void draw();
    virtual ~Circle(void);

    double radius;
};

#endif // CIRCLE_H
