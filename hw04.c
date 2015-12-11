#include <stdio.h>
#include <math.h>


struct point
{
    double x;
    double y;
};


struct triangle
{
    struct point a;
    struct point b;
    struct point c;
};

double area (struct triangle t);

double area (struct triangle t)
{
    double s;

    s = 0.5 * fabs ((t.b.x - t.a.x) * (t.c.y - t.a.y) - (t.c.x -
            t.a.x) * (t.b.y - t.a.y));
    return s;
}
double distance (struct point p, struct point l);

double distance (struct point p, struct point l)
{
    double d,r;
    d=(p.x-l.x)*(p.x-l.x)+(p.y-l.y)*(p.y-l.y);
    r=sqrt(d);
    return r;

}
double radius (struct triangle t);
double radius (struct triangle t)
{
    double r,a,p;
    a=area(t);
    p=distance(t.a,t.b)+distance(t.b,t.c)+distance(t.c,t.a);
    r=2*a/p;
    return r;
}
int main (void)
{
    struct triangle tri=(struct triangle) {{0.,0.},{0.,4.},{3.,0.}};
    double rad=radius (tri);
    printf("%f",rad);
    return 0;
}
