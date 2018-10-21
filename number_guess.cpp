#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int inverse(int num, int mod)
{
    for (int i=1; i<=num; ++i) {
        if ((num*i)%mod == 1) {
            return i;
        }
    }
    cerr << " Can not find multiplicative inverse " << endl;
}

int main(int argc, char ** argv)
{
    const int N = 5;
    int modulus[N] = {2,3,5,7,11}; //Megadott maradekrendszer
    int remainder[N]; //Felhasznalotol kerjuk be

    int product = 1;
    for (int i=0; i<N; ++i)
    {
        product*=modulus[i];
    }
    cout<<"\tGondoljon egy szamra 1 es "<<product<<" kozott!\n\n";

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
        remainder[i] = n;
    }

    int c[N];
    c[0] = inv(remainder[0], modulus[0]);
    c[1] = inv(modulus[0], remainder[2]) * (remainder[1] - c[1]);

   vector<bool> bits; //kiutott szamok: 0, ha nincs kihuzva
   bits.resize(product);
   for (int i=0; i<N; ++i)
   {
       for (int j=0; j<product; j++)
       {
         if (j%modulus[i]!=remainder[i])
            bits[j] = 1;
       }
   }
    int index = 0;
    for (index=0; index<product && bits[index]; ++index);
    cout<<"\tA gondolt szam: "<<index<<endl;

    return 0;
}
