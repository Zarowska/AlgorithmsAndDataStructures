
#include <cstdlib>
#include <iostream>
#include <time.h>


using namespace std;

const int n=10, N1=1, N2=8;
const char P1='a', P2='h';

struct SPunkt
{
    int x;
    char y;
};




int main(int argc, char* argv[])
{
	int dolna;
    dolna=0;

    srand(time(NULL)); //instrukcja wpływa na to, żeby przy każdemu kolejnemu uruchomieniu programy losować się inne liczby

    SPunkt A[n];

//wypełnienie wylosowanymi rekordami tablice A
    for (int i=0; i<n; i++) {
    A[i].x = N1+rand()%(N2-N1+1); //rand()%(N2-N1) =  rand()%(8-1+1)= rand()%(8)={0 1 2 3 4 5 6 7};
    A[i].y = P1+rand()%(P2-P1+1);
    // A[i].x =rand()%8+1; //rand()%8 ={0 1 2 3 4 5 6 7}; rand()%8+1 = {1 2 3 4 5 6 7 8}
    //A[i].y =('a'+rand()%('h'-'a'+1));
    //A[i].x = int(N1+(N2+1-N1)*rand( )/double(RAND_MAX));
	//A[i].y = char(P1+(P2+1-P1)*rand( )/double(RAND_MAX));


        };

//dla testow
//for(int i=0; i<n; i++) {
//cout << A[i].x << "\t";
//}
//cout << 10%2 << endl;
//cout << endl;
//cout << endl;
//for(int i=0; i<n; i++) {
//cout << A[i].y << "\t";
//}
//cout << endl;
//cout << endl;

cout << "Tablica A:" << "\n" ;
//wydrukowanie tablicy B
for(int i=0; i<n; i++) {
cout <<  A[i].y << A[i].x << "\t";
};
cout << endl;
cout << endl;

//liczy rozmiar tabeli B
for(int i=0; i<n; i++) {
	if (A[i].x <=4) dolna++;
	};

//cout << "Rozmiar tablicy B: " << dolna << endl;
//cout << "Rozmiar tablicy C: " << n-dolna << endl;
//cout << endl;

//deklaacja wskaźnika, rezerwacja miejsce w pamięci o typie SPunkt
SPunkt * B = new SPunkt[dolna];
SPunkt * C = new SPunkt[n-dolna];


//przypisanie wartości tablicam B i C
int j=0, k=0;
for(int i=0; i<n; i++) {
	if (A[i].x <=4) {
        B[j].x=A[i].x;
        B[j].y=A[i].y;
        j++;
        }
    else {
        C[k].x=A[i].x;
        C[k].y=A[i].y;
        k++;
        };
};

cout << "Tablica B:" << "\n" ;
//wydrukowanie tablicy B
for(int i=0; i<dolna; i++) {
cout <<  B[i].y << B[i].x << "\t";
};
cout << endl;
cout << endl;

cout << "Tablica C:" << "\n" ;
//wydrukowanie tablicy C
for(int i=0; i<n-dolna; i++) {
cout <<  C[i].y << C[i].x << "\t";
};
cout << endl;
cout << endl;

//usuwanie tablic dynamicznych
delete [] B;
delete [] C;


    return 0;
}
