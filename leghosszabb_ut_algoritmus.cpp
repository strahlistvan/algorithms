#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector < vector<int> > mtx;
//Allapotok:
// 0. Kezdoallapot, 1. uj csucs bevetel,    2. megtalalt egy megoldast,    3. nem tud tovabbmenni
enum stateTypes {STARTER, ADD_NODE, REACH_END, NO_WAY};

mtx read_graph(string filename);
bool inPath(vector<int> PATH, int elem);
void PrintMatrix(mtx & Matrix);
void print_path(vector <int> & PATH);

int main(int argc, char ** argv)
{
    mtx Matrix =  read_graph("graf66.txt");
    const int SIZE = Matrix.size();
    PrintMatrix(Matrix);

    vector <int> PATH, MaxPATH;
    int start =0, dest = 4;
    //Hibakezeles
    if (start<0 || dest<0 || start>=SIZE || dest>=SIZE)
    {
        cerr<<"HIBA!"<<SIZE<<" meretu grafban nincs "<<start<<"-->"<<dest<<" ut\n";
        return -1;
    }

    int pos = start; // Az ut utolso csucsa, a jelenlegi pozicio
    PATH.push_back(pos); //Kezdetben egy csucsbol allo ut
    stateTypes state = STARTER; //kezdoallapot
    int minIndex=0;

    //Fo ciklus: minden lehetseges ut vizsgalata
    bool done = false;
    while (!done)
    {
        cout<<"\nUj ciklus!\n"<<endl;
        state=STARTER; //Minden ciklusban kezdoallapot
        print_path(PATH); //jelenlegi ut

        cout<<"Pozicio: "<<pos<<endl;
        //Ha talalt utat a celpontba
        if (pos == dest)
        {
            cout<<"Talaltam utat"<<dest<<"be, ut hossza:"<<PATH.size()<<"Eddigi leghosszabb: "<<MaxPATH.size()<<endl;
            minIndex=pos+1;

            //Ha a jelenlegi ut nagyobb, mint az eddigi legnagyobb....
            if (PATH.size() > MaxPATH.size())
            {
                MaxPATH = PATH;
                cout<<"Az Uj leghosszabb ut: "<<MaxPATH.size()<<endl;
            }

            //Ha talalt egy megfelelo megoldast, letorli az utolso csucsot
            cout<<"utolso csucs torlese, mivel talalt megfelelo utat\n";
            PATH.pop_back();
            pos = PATH.back();
            state = REACH_END;
        } //Ha talalt utat

        //Ha nem talalt megfelelo megoldast
        if (pos != dest)
        {
            bool found = false; //talalt-e nem bevett elt?
            for (int i=minIndex; !found && i<SIZE; i++)
            {
                //Ha van olyan el, amit meg nem vettunk be
                if (Matrix[pos][i]==1 && !inPath(PATH, i))
                {
                  pos = i;
                  cout<<"Uj csucs bevetele:" <<pos<<endl;;
                  PATH.push_back(pos);
                  minIndex = 0;
                  found = true; //Ha mar talalt, kilephet a ciklusbol
                  state = ADD_NODE; //Uj csucs bevetele
                }
          }
        }  //Ha nem talalt utat

        //Csucs torlese, mivel nem lehet tovabb lepni
        if (state==STARTER && pos!=start)
        {
          minIndex=pos+1;
          cout<<"Csucs torles (nem lehet tovabb menni): "<<PATH.back()<<endl;
          PATH.pop_back(); //Visszalepes
          pos = PATH.back();
          state = NO_WAY; //Nem lehet tovabb menni
        }
        //Ha nem lehet tovabb lepni, es a start pozicion vagyunk -> vege
        if (state==STARTER && pos == start)
        {
            cout<<"Vege az algortimusnak...\n";
            done = true;
        }
    }
    // Ha minden csucsot tartalmaz, akkor Hamilton-ut
    if (MaxPATH.size()==SIZE)
        cout<<"Van Hamilton ut "<<start<<" es "<<dest<<"kozott!\n";
    else
        cout<<"Nincs Hamilton ut "<<start<<" es "<<dest<<"kozott!\n";
    cout<<"Leghosszabb ut:\n";
    print_path(MaxPATH);
}

/** Beolvassa egy graf szomszedsagi matrixat */
mtx read_graph(string filename)
{
    ifstream fin(filename.c_str());
    if (!fin)
    {
        cerr<<"Hiba a file megnyitasakor"<<endl;
        return mtx();
    }
    mtx graph;
    int N;
    fin>>N;
    graph.resize(N);
    for (int i=0; i<N; ++i)
        graph[i].resize(N);

    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            int e;
            fin>>e;
            graph[i][j] = e;
        }
    }
    fin.close();
    return graph;
}

/** Benne van-e a megadott PATHban a megadott elem? */
bool inPath(vector<int> PATH, int elem)
{
    for (int i=0; i<PATH.size(); ++i)
    {
        if (PATH[i]==elem)
            return true;
    }
    return false;
}

/** Kiirja a graf szomszedsagi matrixat a kepernyore */
void PrintMatrix(mtx & Matrix)
{
    cout<<endl;
    for (int i=0; i<Matrix.size(); ++i)
    {
        for (int j=0; j<Matrix[i].size(); ++j)
            cout<<Matrix[i][j]<<" ";
        cout<<endl;
    }
}

/** Kiirja az aktualis utvonalat a kepernyore */
void print_path(vector <int> & PATH)
{
  if (PATH.empty())
  {
    cout<<"Nincs ilyen ut."<<endl;
    return;
  }
  cout<<"Ut ("<<PATH[0]<<") es ("<<PATH.back()<<") kozott: ";
  for (int i=0 ; i<PATH.size()-1; ++i)
    cout<<PATH[i]<<"->";
  cout<<PATH.back()<<endl;
}
