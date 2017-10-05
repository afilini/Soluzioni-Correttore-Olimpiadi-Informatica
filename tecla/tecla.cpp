#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <queue>
#include <list>
#include <stack>
#define infinito 1001000;
using namespace std;

struct Nodo
{
    int min = infinito;     //Questo viene usato da dijkstra
    int distanza;           //Questo contiene la distanza dal nodo zero
    list<int> connessi;
    int precedente = -1;    //Questo è per stampare
};

Nodo nodi[100];
int N, M;

int dijkstra(int inizio, int fine)
{
    nodi[inizio].min = 0;
    queue<int> coda;
    coda.push(inizio);
    while(!coda.empty())
    {
        int attuale = coda.front();
        coda.pop();
        for(auto i: nodi[attuale].connessi)
        {
            if(nodi[attuale].min + 1 < nodi[i].min)
            {
                nodi[i].min = nodi[attuale].min + 1;
                nodi[i].precedente = attuale;
                coda.push(i);
            }
        }
    }

    return nodi[fine].distanza = nodi[fine].min;
}

void clearNodi()
{
    for(int i = 0; i < N; i++)
        nodi[i].min = infinito;
}

void stampaPercorso(int inizio, int fine)
{
    stack<int> pila;
    pila.push(fine);
    int attuale = fine;
    while(attuale != inizio)
    {
        pila.push(nodi[attuale].precedente);
        attuale = nodi[attuale].precedente;
    }


    while(!pila.empty())
    {
        attuale = pila.top();
        pila.pop();
        cout << attuale << " ";
    }
}

int main()
{
    FILE *in, *out;
    in = freopen("input.txt", "r", stdin);
    out = freopen("output.txt", "w", stdout);

    //input

    scanf("%d %d", &N, &M);    
    for(int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        nodi[u].connessi.push_back(v);
        nodi[v].connessi.push_back(u);
    }  

    for(int i = 0; i < N; i++)
    {
        //Faccio dijkstra tante volte e ogni volta mi segno la distanza dal nodo zero
        //nel nodo i, potrebbe essere inutile fare dijkstra N volte ma non importa
        dijkstra(0,i);
        //Ogni volta ripulisco i nodi che ho usato
        clearNodi();
    }

    int primo, secondo;

    for(int i = 0; i < N; i++)
    {
        for(auto j: nodi[i].connessi)
        {
            //Ogni nodo i viene confrontato con i nodi connessi a lui (quindi a distanza uno):
            //posso dire di aver trovato un percorso di lunghezza dispari se sono entrambi pari o
            //entrambi dispari (dato che distano 1 l'uno dall'altro), il mio percorso sarà: 0 -> primo ->
            //secondo -> 0 
            
            if(nodi[i].distanza % 2 == nodi[j].distanza % 2)
            //Può esser riscritto come:
            //if(nodi[i].distanza % 2 == 0 && nodi[j].distanza % 2 == 0 ||
                //nodi[i].distanza % 2 == 1 && nodi[j].distanza % 2 == 1 ) 
            {
                primo = i;
                secondo = j;
                i = N+1;      //Trovati, esco anche dal ciclo esterno
                break;
            }
        }
    }

    cout << nodi[primo].distanza + nodi[secondo].distanza + 1 << endl;

    //Stampo il percorso

    dijkstra(0, primo);
    stampaPercorso(0, primo);
    clearNodi();
    dijkstra(secondo, 0);
    stampaPercorso(secondo, 0);

}