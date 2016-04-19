#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


const int MERET = 16; //A rendezendo szamok
int N=MERET; //A kupac merete (valtozhat)
//int kupac[]={-99999,6,2,9,11,10,3,4,7,5,1,8,12,6,13,8,19};
int * kupac = new int[N];
int * rendezett = new int[MERET];

/** Helyere teszi a megadott pozicioju elemet */
void helyretesz(int poz)
{
    //Ha az adott csucsnak ket gyereke van
    if (2*poz<N)
    {
     int maxindex=(kupac[2*poz+1]>kupac[2*poz])?(2*poz+1):(2*poz); //nagyobb gyerek indexe
     //  cout<<"maxindex: "<<maxindex<<endl;
      //Ha a nagyobb gyerek nagyobb a szulonel
      if(kupac[maxindex]>kupac[poz])
      {
          //szulo csereje a nagyobb gyerekkel
        //  cout<<"Csere: "<<kupac[poz]<<"<->"<<kupac[maxindex]<<endl;
          swap(kupac[poz], kupac[maxindex]);
          helyretesz(maxindex);
      }
    }
      //Ha csak egy gyereke van a csucsnak
      if(2*poz==N && kupac[2*poz]>kupac[poz])
      {
         swap(kupac[poz], kupac[2*poz]);
       // cout<<"Csere: "<<kupac[poz]<<"<->"<<kupac[2*poz]<<endl;
      }
}

/** Kupacrendezes: kupacepites, majd legnagyobb elemek kivetele a kupacbol */
void kupacrendezes()
{
  //kupac letrehozasa
  for(int poz=N/2; poz>=1; --poz)
        helyretesz(poz);

  //Kesz kupac kiirasa
  cout<<"A kupac: "<<endl;
  for (int i=1; i<=N; ++i)
    cout<<kupac[i]<<" ";
  cout<<endl;

  //Kupac rendezese a legnagyobb elem torlesevel
  int index=0;
  for(int i=N; i>=1; --i)
  {
    rendezett[index++] = kupac[1]; // A rendezett tombbe
    kupac[1]=kupac[N--];
    helyretesz(1); //kupactulajdonsag visszaallitasa
  }
}

int main(int argc, char ** argv)
{
    //Feltoltes veletlen szamokkal
    srand(time(0));
    for (int i=1; i<=N; ++i)
        kupac[i] = rand()%(2*N);

    cout<<"Az eredeti tomb: "<<endl;
    for(int i=1; i<=N; ++i)
        cout<<kupac[i]<<" ";
    cout<<endl;

    float t1 = clock();
    kupacrendezes();
    float t2 = clock();
    cout<<"Futasido: "<<(t2-t1)/CLOCKS_PER_SEC<<endl;

    cout<<"A rendezett tomb: "<<endl;
    for(int i=0; i<MERET; ++i)
        cout<<rendezett[i]<<" ";
    cout<<endl;
}
