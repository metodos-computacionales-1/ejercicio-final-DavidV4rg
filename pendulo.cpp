#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include<fstream>

const double G = 9.8;
const double dt = 0.01; 
const double epsilon = 0.001;
const double PI = 3.14159265359;

class pendulo
{
public:
    double L; 
    double k; 
    double Fo; 
    double O; 
    double vv; 
    double theta; 
    pendulo();
    ~pendulo();
};
pendulo::pendulo()
{
    L=0.0;
    k=0.0;
    Fo=0.0;
    O=0.0;
    vv=0.0;
    theta=0.0;
}
pendulo::~pendulo()

void condiciones(pendulo & p, float F);
void euler(pendulo & p,double dt,double t);

void euler(pendulo & p,float dt,float t)
{

    p.vv=p.vv+(-(G/p.L)*sin(p.theta) - p.k*p.vv + p.Fo*sin(p.O*t))*dt;
    p.theta=p.theta + p.vv*dt;
    if(p.theta < - PI)
    {
        p.theta += 2*PI;
    }
    if(p.theta > PI)
    {
    p.theta += -2*PI;
    }
} 
 
void condiciones(pendulo & p, float F)
{
    p.k=0.82;
    p.Fo=F;
    p.O=0.2;
    p.L = G;
    p.vv=0.1;
    p.theta = 0.8;  
}
std::ofstream outfile;


int main(int argc, char** argv)
{
    pendulo p;
    float t=0.0; 
    int N = atoi(argv[1]);
        float F = atof(argv[2]);
    //Initialization
    
    condiciones(p, F); 
        std::string filename = "data.dat";
        if(atoi(argv[3])==2){
            filename = "data";
            filename.append(argv[2]);
            filename.append(".dat");
    }
    outfile.open(filename);
    outfile << p.Fo << "\t" << p.O << "\t" << dt  << std::endl;
    for (int i=1; i<=N; i++)
    {
        euler(p,dt,t);
        outfile << t << "\t" << p.theta << "\t" << p.vv  << std::endl;
        t+=dt;
    }
    outfile.close();
    return 0;
}


