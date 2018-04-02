#include <iostream>
#include <cstdlib>
using namespace std;

int * diofantoszi(int a0, int b0, int c0);

int main(int argc, char ** argv)
{
    int a=0, a_inv=0, mod = 1;
    cout<<"Kerek egy szamot: ";
    cin>>a;
    cout<<"Kerek egy m modulust: ";
    cin>>mod;

    int * eredm = diofantoszi(a, mod, 1);
    //Ha van megoldas
    if (eredm)
    {
        a_inv = *eredm;
        a_inv %= mod; //A legkisebb inverz keresese
        if (a_inv<0)  //A legkisebb pozitiv inverz
            a_inv += mod;
        cout<<a<<" multiplikativ inverze (mod"<<mod<<"): "<<a_inv<<endl;
    }
    else {
        return -1;
    }

    return 0;

}

/**   Linearis diofantoszi egyenlet megoldo
 *  Bemeno parameterek a*x+b*y=c egyenlet egyutthatoi
 *   Visszateresi ertek: x0 partikularis megoldas (cime), hiba eseten NULL pointer */
int * diofantoszi(int a0, int b0, int c0)
{
    cout<<a0<<"x + "<<b0<<"y = "<<c0<<endl;
    bool volt_csere = false;
    if (b0 > a0)
    {
        swap(a0, b0);
        volt_csere = true;
    }

    int a = a0, b = b0;
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

        cout << "[01] x_prev: " << x_prev << " x: " << x << " y_prev: " << y_prev << " y : " << y << endl;


        //Bovitett euklideszi alg.: x-y - ok kiszamitasa
        int temp = x;
        x = x_prev-hanyados*x;
        x_prev = temp;


        temp = y;
        y = y_prev-hanyados*y;
        y_prev = temp;

        cout << "[02] x_prev: " << x_prev << " x: " << x << " y_prev: " << y_prev << " y : " << y << endl;
    }

    //Ellenorzes
    int lnko = a;
    int lnko2 = a0*x_prev + b0*y_prev;
    if (lnko2!=lnko) //Egyezniuk kell
    {
         cout<<"Valami hiba van a szamitas soran"<<endl;
         return NULL;
    }

    cout << "lnko: " << lnko << endl;
    cout << "x: " << x_prev << endl;
    cout << "y: " << y_prev << endl;

    if (c0%lnko!=0)
    {
       cout<<"Nem oldhato meg az egyenlet"<<endl;
       return NULL;
    }
    //Ha van megoldas:
    static int x0 = x_prev*c0/lnko;
    int y0 = y_prev*c0/lnko;
    if (volt_csere)
    {
        swap(x0, y0);
    }

    return &x0;
}
