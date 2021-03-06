#include <iostream>
#include <fstream>
#include <cfortran.h>

#include "math.h"
using namespace std;

extern "C"
{
    void fhti_(int * n, double * mu, double * q, double * dlnr,
               double * kr, int * kropt, double * wsave, int * ok);
    void fht_(int * n, double * a , int * dir, double * wsave);
}

int main()
{
    double logrmin=-4.;
    double logrmax=4.;
    int N=1024;

    double mu=0.;
    double q=0.;
    double kr=1.;
    int kropt=3;
    int dir=1;
    double dlnr;
    double logrc=(logrmin+logrmax)/2.;
    double dlogr=(logrmax-logrmin)/double(N);
    dlnr=dlogr*log(10.);
    double nc=double(N+1)/2.;
    double * r= new double [N];
    double * a= new double [N];
    double * k= new double [N];
    double * ka=new double [N];
    double * wsave = new double [5*N];
    for(int i=0;i<N;i++)
    {
        r[i]=pow(10.,logrc+(i-nc+1)*dlogr);
        a[i]=pow(r[i],mu+1.)*pow(M_E,-r[i]*r[i]/2.);
    }
    ofstream input("input.txt");
    for(int i=0;i<N;i++)
    {
        input<<r[i]<<"  "<<a[i]<<endl;
    }
    input.close();
//CALL FORTRAN SUBROUTINE, compute Fast Hankel Transform
    int ok;
    int clogical=0;
    ok=C2FLOGICAL(clogical);

    fhti_(& N, & mu, & q, & dlnr, & kr, & kropt, wsave, & ok);

    clogical=F2CLOGICAL(ok);

    fht_(& N, a, & dir, wsave);
//END FORTRAN CALLING
    double logkc=log10(kr)-logrc;
    for(int i=0;i<N;i++)
    {
        k[i]=pow(10.,logkc+(i-nc+1)*dlogr);
        ka[i]=pow(k[i],mu+1.)*pow(M_E,-k[i]*k[i]/2.);
    }

    ofstream output("output.txt");
    for(int i=0;i<N;i++)
    {
        output<<k[i]<<"  "<<ka[i]<<"  "<<a[i]<<endl;
    }
    output.close();

    delete [] r;
    delete [] a;
    delete [] wsave;

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
