#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int diofant(int a0, int b0, int c0);

int main ()
{
    const int N = 5;
    int modulus[N] = {2,3,5,7,11}; //Megadott maradekrendszer
    int maradek[N]; //Felhasznalotol kerjuk be

    int szorzat = 1;
    for (int i=0; i<N; ++i)
    {
        szorzat*=modulus[i];
    }
    cout<<"\tGondoljon egy szamra 1 es "<<szorzat<<" kozott!\n\n";

    for (int i=0; i<N; ++i)
    {
        int n = -1; //segedvaltozo bekereshez
        cout<<"\nKerem a(z) "<<modulus[i]<<"-val/vel valo osztasi maradekot: ";
        cin>>n;
        //Hibakezeles.
        while (n<0 || n>=modulus[i])
        {
            cerr<<"A maradeknak 0 es "<<modulus[i]-1<<" kozott kell lennie..."<<endl;
            cout<<"Kerem a(z) "<<modulus[i]<<"-val/vel valo IGAZI osztasi maradekot: ";
            cin>>n;
        }
        maradek[i] = n;
    }

    int c[N];
    c[0] = maradek[0];
    cout<<"\nx==="<<c[0]<<" (mod "<<modulus[0]<<")\n";
    for (int i=1; i<N; ++i)
    {
        c[i] = c[i-1]+modulus[i-1]*maradek[i];
        cout<<"x==="<<c[i]<<" (mod "<<modulus[i]<<")\n";
    }

   vector<bool> bits; //kiutott szamok: 0, ha nincs kihuzva
   bits.resize(szorzat);
   for (int i=0; i<N; ++i)
   {
       for (int j=0; j<szorzat; j++)
       {
         if (j%modulus[i]!=maradek[i])
            bits[j] = 1;
       }
   }
    int index = 0;
    for (index=0; index<szorzat && bits[index]; ++index);
    cout<<"\tA gondolt szam: "<<index<<endl;

    return 0;
}

/**   Linearis diofantoszi egyenlet megoldo
 *  Bemeno parameterek a*x+b*y=c egyenlet egyutthatoi
 *   Visszateresi ertek: x0 partikularis megoldas */
int diofant(int a0, int b0, int c0)
{
    bool volt_csere = false;
    if (b0 > a0)
    {
        swap(a0, b0);
        volt_csere = true;
    }

    int a = a0, b=b0;
    // x,y valtozok a bovitett algoritmushoz
    int x=0, y=1, x_prev=1, y_prev=0;
    int hanyados = a/b, maradek = a%b;

    //Euklideszi algoritmus
    while (b!=0)
    {
        hanyados = a/b;
        maradek = a%b;
        a = b;
        b = maradek;

        //Bovitett euklideszi alg.: x-y - ok kiszamitasa
        int temp = x;
        x = x_prev-hanyados*x;
        x_prev = temp;

        temp = y;
        y = y_prev-hanyados*y;
        y_prev = temp;
    }

    //Ellenorzes
    int lnko = a;
    int lnko2 = a0*x_prev + b0*y_prev;
    if (lnko2!=lnko)
    {
         cout<<"Valami hiba van a szamitas soran"<<endl;
         return -1;
    }

  /*  cout << "lnko: " << lnko << endl;
    cout << "x: " << x_prev << endl;
    cout << "y: " << y_prev << endl; */

    if (c0%lnko!=0)
    {
       cout<<"Nem oldhato meg az egyenlet"<<endl;
       return -1;
    }
    //Ha van megoldas:
    int x0 = x_prev*c0/lnko;
    int y0 = y_prev*c0/lnko;
    if (volt_csere)
    {
        swap(x0, y0);
    }
    //Megkeresi a megfelelo x0 partikularis megoldast
  /*  while ( x0<0 || x0>b0)
    {
        if (x0<0)
        {
            x0+=(b0/lnko);
        }
        else if (x0>b0)
        {
                x0-=(b0/lnko);
        }
    } */
    return x0;
}
