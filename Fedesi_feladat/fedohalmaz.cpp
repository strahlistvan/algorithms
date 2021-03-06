#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "sets.cpp"
using namespace std;
vector<Set> generalas(int N, int M);

int main(int argc, char ** argv)
{
	 if (argc!=3)
	 {
	 	cout<<"Parameterezes: 1. Elemek szama 2. Fedohalmazok szama"<<endl;
	 	return -1;
	 }
    int N=atoi(argv[1]); //Ennyi elem van (also pontok)
    int M=atoi(argv[2]); //Ennyi 3 elemu fedohalmazunk van (felso pontok)

    vector<Set> fedohalmazok = generalas(N, M);
    cout<<"Osszes halmaz: "<<endl;
    for (int i=0; i<M; ++i)
        fedohalmazok[i].print();

    Set bevett_pontok; //lefedett pontok halmaza (kedzetben ures)
    vector<Set> min_fedes; //Fedohalmazok halmazrendszere

    //A leheto legtobb uj pontot hozza a konyhara (vagyis 'k' kozos pontja legyen az eddigi bevett_pontokkal
    for (int k=0; k<3; ++k)
    {
        //Amig nincs minden pont lefedve, es amig van el
        for (int i=0; bevett_pontok.size()<N && i<M; ++i)
        {
            //Ha 'k' kozos pontja van az adott halmaznak a bevett_pontokkal, akkor 3-k uj pontot hoz a konyhara...
            if ((bevett_pontok*fedohalmazok[i]).size()==k)
            {
                bevett_pontok = bevett_pontok+fedohalmazok[i]; //unio
                min_fedes.push_back(fedohalmazok[i]);
            }
        }
    }

    if (bevett_pontok.size()<N)
        cout<<"Nem talalhato teljes fedes"<<endl;
    else
    {
        //Fedes:
        cout<<"Kivalasztott fedes: "<<endl;
        for (int i=0; i<min_fedes.size(); ++i)
            min_fedes[i].print();
    }
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
