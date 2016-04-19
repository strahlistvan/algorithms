#include <iostream>
#include <vector>
using namespace std;

/** Halmaz osztaly: Minden elem csak egyszer fordulhat elo, a sorrend nem szamit, unio+metszet muvelet van ertelmezve. */
class Set
{
    vector<int> elements;
    public:
        Set(){ };

        /** Konstruktor (tomb+merete) */
        Set(int * elems, int N)
        {
            for (int i=0; i<N; ++i)
            {
                if (!isElement(elems[i]))
                    this->elements.push_back(elems[i]);
            }
        }

        /** Konstruktor (vektor) */
        Set(vector<int> elems)
        {
            for (int i=0; i<elems.size(); ++i)
            {
                if (!isElement(elems[i]))
                     this->elements.push_back(elems[i]);
            }
        }

        /** Ellenorzi, hogy az adott szam eleme-e a halmaznak */
        bool isElement(int elem)
        {
            for (int i=0; i<elements.size(); ++i)
                if (elements[i]==elem)
                    return true;
            return false;
        }

        /** Hozzaad egy uj elemet a halmazhoz (ha meg nincs bene) */
        void addElement(int elem)
        {
            if (!isElement(elem))
                elements.push_back(elem);
        }

        /** Kiirja a halmaz tartalmat */
        void print()
        {
            cout<<"{";
            for (int i=0; i<elements.size(); ++i)
                cout<<elements[i]<<",";
            cout<<"}"<<endl;
        }

        /** Visszaadja a halmaz meretet */
        int size()
        {
            return elements.size();
        }

        /** Visszaadja a halmaz elemeit egy vektorba */
        vector<int> getElements()
        {
            return this->elements;
        }
        /** Visszaadja a halmaz hatvanyhalmazat */
        vector<Set> getPowerSet()
        {
            int powerSetSize = 1<<size(); //2^n reszhalmaz
            vector<Set> powerSet;
            //Szamlalo 0-tol 2^n-1-ig
            for(int counter=0; counter<powerSetSize; ++counter)
            {
               Set s;
               for(int j=0; j<size(); j++)
               {
                  //Ha a szamlalo j. bitje 1-es, a j. elem bekerul a hatvanyhalmazba
                  if(counter & (1<<j))
                    s.addElement(j);
               }
             powerSet.push_back(s);
            }
         return powerSet;
        }

        /** Ertekado operator halmazokra */
        void operator = (Set setValue)
        {
            vector<int> val = setValue.getElements();
            this->elements = val;
        }
};

/** Ket halmaz unioja */
Set operator + (Set& A, Set& B)
{
    Set C = A;
    vector<int> Bvect = B.getElements();
    for (int i=0; i<Bvect.size(); ++i)
    {
        C.addElement(Bvect[i]);
    }
   return C;
}

/** Ket halmaz metszete */
Set operator * (Set& A, Set& B)
{
    Set C;
    vector<int> Bvect = B.getElements();
    for (int i=0; i<Bvect.size(); ++i)
    {
        if (A.isElement(Bvect[i]))
            C.addElement(Bvect[i]);
    }
    return C;
}

/** Ket halmaz egyenlo-e? (minden elemuk egyforma-e?) */
bool operator == (Set& A, Set& B)
{
    vector<int> Bvect = B.getElements();
    for (int i=0; i<Bvect.size(); ++i)
    {
        if (!A.isElement(Bvect[i]))
            return false;
    }
    vector<int> Avect = A.getElements();
    for (int i=0; i<Avect.size(); ++i)
    {
        if (!B.isElement(Avect[i]))
            return false;
    }
    return true;
}
