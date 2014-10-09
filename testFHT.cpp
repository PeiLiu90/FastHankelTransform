#include <iostream>
#include "math.h"
using namespace std;

//extern "C"
//{
//    void fhti_(int * n, double * mu, double * q, double * dlnr,
//               double * kr, int * kropt, double ** wsave, bool * ok);
//    void fht_(int * n, double * a[] , int * dir, double ** wsave);
//}

int main()
{
    int N=64;
    double mu=0.;
    double q=0.;
    double dlnr=0.;
    double kr=1.;
    int kropt=3;
    int dir=1;
    double logrmin=-4.;
    double logrmax=4.;
    double logrc=(logrmin+logrmax)/2.;
    double dlogr=(logrmax-logrmin)/double(N);
    dlnr=dlogr*log(10.);
    double nc=double(N+1)/2.;
//    double * r= new double [N];
//    double * a= new double [N];
//    double * wsave = NULL;
//    for(int i=0;i<N;i++)
//    {
//        r[i]=pow(10.,logrc+(i-nc)*dlogr);
//        a[i]=pow(r[i],mu+1.)*pow(M_E,-r[i]*r[i]/2.);
//    }
    bool ok;
    cout<<"HELLO WORLD"<<endl;
    //fhti_(& N, & mu, & q, & dlnr, & kr, & kropt, & wsave, & ok);
    //fht_(& N, & a, & dir, & wsave);
    return 0;
}






//double func(const double r)
//{
//    return pow(M_E,-r*r*0.5);
//}
//
//int main()
//{
//    int N=1024;
//    double xmax=10.;
//    double kmax;
//
//    double err;
//    time_t start,finish;
//    double duration;
//
//    return 0;
//}
