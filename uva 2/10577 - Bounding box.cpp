#include <cstdio>
#include <cstdlib>
#include <cmath>
#include<iostream>
#include <algorithm>
#define EPS 1e-9

using namespace std;

const double HALF_PI  = acos(0.0);
const double PI  = 2*HALF_PI;

struct Vector2d
{
    double x,y;
    Vector2d()
    {
        x=y=0;
    };
    Vector2d(double _x,double _y):x(_x),y(_y) {}
    Vector2d rotate(double radians)
    {
        double COS = cos(radians);
        double SIN = sin(radians);
        return Vector2d((COS*x-SIN*y),
                        (SIN*x+COS*y));
    }
};
struct Point
{
    double x,y;
    Point()
    {
        x=y=0;
    }
    Point(double _x,double _y):x(_x),y(_y) {};
    double det(Point P0,Point P1)
    {
        return (P1.x-P0.x)*(x-P0.x)-(P1.y-P0.y)*(y-P0.y);
    }
    bool isLeft(Point P0,Point P1)
    {
        return det(P0,P1) >= 0;
    }
};
struct Line
{
    double A,B,C;
    Line(double x1,double y1,double x2,double y2)
    {
        A = y1-y2;
        B = x2-x1;
        C = ((-A)*x1)-(B*y1);
    }
    Line(Point P1,Point P2)
    {
        A = P1.y-P2.y;
        B = P2.x-P1.x;
        C = ((-A)*P1.x)-(B*P1.y);
    }
    bool intersectingPoint(const Line& l,double& X,double& Y)
    {
        double det = A*l.B-l.A*B;
        if(fabs(det)<EPS)
        {
            return false;
        }
        X = double(B*l.C-C*l.B)/double(det);
        Y = double(C*l.A-A*l.C)/double(det);
        return true;
    }
};
int main()
{
    double auxx,auxy,radius,ang;
    Point p1,p2,p3,c;
    int sides;
    int cases = 0;
    while(scanf("%d",&sides) && sides && scanf("%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y)==6)
    {
        Line l1(p1,p2);
        Line l2(p2,p3);


        auxx = (p1.x-p2.x)/2+p2.x;
        auxy = (p1.y-p2.y)/2+p2.y;
        Line pp1(auxx,auxy,auxx+l1.A,auxy+l1.B);

        auxx = (p3.x-p2.x)/2+p2.x;
        auxy = (p3.y-p2.y)/2+p2.y;
        Line pp2(auxx,auxy,auxx+l2.A,auxy+l2.B);

        pp1.intersectingPoint(pp2,c.x,c.y);
        radius = sqrt((c.x-p1.x)*(c.x-p1.x)+(c.y-p1.y)*(c.y-p1.y));

        double sumAng = 2*PI/sides;
        Vector2d vec(p1.x-c.x,p1.y-c.y);
        double xmax, xmin, ymax, ymin;
        xmax = xmin = p1.x;
        ymax = ymin = p1.y;
        for(int i = 0; i<=sides; ++i)
        {
            vec = vec.rotate(sumAng);
            double xact = vec.x+c.x;
            double yact = vec.y+c.y;
            xmin = min(xmin, xact);
            ymin = min(ymin, yact);
            xmax = max(xmax, xact);
            ymax = max(ymax, yact);
        }
        double area = (ymax-ymin) * (xmax-xmin);
        printf("Polygon %d: %.3lf\n",++cases,area);
    }
    return 0;
}
