// 
// Autore: Daniela Brozzoni
// Data: 

#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;

class pc {
public:
   int f;
   int t;
};

int cmp(const void *a, const void *b) 
{ 
   pc primo = *(pc *)a;
   pc secondo = *(pc *)b;
    if (primo.f > secondo.f) return -1;
    if (secondo.f > primo.f) return 1;
    return 0;
}

int main()
{
   int N, M;
   cin >> N >> M;
   pc computer[21000];
   char temp[8];
   
   for (int i = 0; i < N; i++)
      cin >> computer[i].f;

   for (int i = 0; i < N; i++)
   {
      cin >> temp;
      if (strcmp(temp,"L10") == 0)
         computer[i].t=1;
      else if (strcmp(temp,"L16") == 0)
         computer[i].t=2;
      else
         computer[i].t=3;
   }
      
  
   int a = 0, b = 0, c = 0; //Numero di L10, L16, bipasso
   for (int i = 0; i < M; i++) {
      cin >> temp;
      //cout << temp << endl << endl;
      if (strcmp(temp,"L10") == 0)
         //cout << temp << " uguale a L10" << endl;
         a++;
      else if (strcmp(temp,"L16") == 0)
         //cout << temp << " uguale a L16" << endl;
         b++;
      else if (strcmp(temp,"bipasso") == 0)
         //cout << temp << " uguale a bipasso" << endl;
         c++;
   }
 
   //cout << a << b << c;

   int somma = 0;
   qsort(computer, N, sizeof(pc), cmp);


   for (int i = 0; i < N; i++)
   {
      if(computer[i].t==1 && a > 0)
      {
         a--;
         somma+= computer[i].f;
      }
         

      else if(computer[i].t==2 && b > 0)
      {
         b--;
         somma+= computer[i].f;
      }
      
      else if(c > 0)
      {
         c--;
         somma+= computer[i].f;
      }

   }

   cout << somma;

}