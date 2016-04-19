#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "sets.cpp"
using namespace std;

vector<Set> generalas(int N, int M);

int N=15; //Ennyi elem van (also pontok)
int M=5; //Ennyi 3 elemu fedohalmazunk van (felso pontok)
Set bevett_pontok;//lefedett pontok halmaza (kedzetben ures)
vector<Set> min_fedes; //Fedohalmazok halmazrendszere
vector<Set> fedohalmazok; //Minden fedohalmaz

int main(int argc, char ** argv)
{
    fedohalmazok = generalas(N, M);
    cout<<"Osszes halmaz: "<<endl;
    for (int i=0; i<M; ++i)
        fedohalmazok[i].print();


    int powerSetSize = 1<<M; //2^M reszhalmaz

    //Szamlalo 0-tol 2^n-1-ig minden lehetoseg
    for(int counter=0; counter<powerSetSize; ++counter)
    {

        for(int j=0; j<M; j++)
        {
            //Ha a szamlalo j. bitje 1-es, a j. elem bekerul a hatvanyhalmazba (ha ad hozza uj pontot)
            if((counter & (1<<j)) )
            {
                min_fedes.push_back(fedohalmazok[j]);
            }
        }

    }


    cout<<"Minimalis fedes: "<<endl;
    for (int i=0; i<min_fedes.size(); ++i)
        min_fedes[i].print();

}

/** N elem M darab 3 elemu halmazzal valo veletlenszeru fedeset generalja */
vector<Set> generalas(int N, int M)
{
    srand(time(0));
    vector<Set> fedohalmazok;
    while (fedohalmazok.size()<M)
    {
        Set s;
        while(s.size()<3)
        {
            s.addElement(rand()%N+1);
        }
        bool ok = true;
        for (int i=0; i<fedohalmazok.size(); ++i)
            if (fedohalmazok[i]==s)
                ok = false;
        if (ok)
            fedohalmazok.push_back(s);
    }
    return fedohalmazok;
}
