#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "sets.cpp"
using namespace std;

vector<Set> generalas(int N, int M);

int N=15; //Ennyi elem van (also pontok)
int M=20; //Ennyi 3 elemu fedohalmazunk van (felso pontok)
Set bevett_pontok;//lefedett pontok halmaza (kedzetben ures)
vector<Set> min_fedes; //Fedohalmazok halmazrendszere
vector<Set> fedohalmazok; //Minden fedohalmaz

void lefed(int i)
{
    if (i==M) return; //Ha vegignezte az osszes halmazt
    lefed(i+1);
    bevett_pontok = bevett_pontok+fedohalmazok[i]; //Unio
    if (bevett_pontok.size()==N) return; //Ha minden pontot bevett
    //Ha meg nincs beveve az adott halmaz, beveheto
    bool ok = true;
    for (int j=0; j<min_fedes.size(); ++j)
    {
        if (min_fedes[j]==fedohalmazok[i])
            ok = false;
    }
    if (ok)
        min_fedes.push_back(fedohalmazok[i]);
    lefed(i+1);
}

int main(int argc, char ** argv)
{
    fedohalmazok = generalas(N, M);
    cout<<"Osszes halmaz: "<<endl;
    for (int i=0; i<M; ++i)
        fedohalmazok[i].print();

    lefed(0);
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
