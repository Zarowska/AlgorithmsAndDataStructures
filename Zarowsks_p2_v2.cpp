#include <iostream>
#include <cstdlib>
#include<sstream> //dla stringstream
#include <time.h> //dla srand(time(NULL));

using namespace std;

struct Elem{
    int liczba;
    Elem* next;
};

void WYPISZ(Elem *glowa, string naglowek  ){
    Elem* akt = glowa;
    cout << naglowek << endl;
    while(akt!=NULL){
        cout<<akt->liczba<<"\n";
        akt = akt->next;
    }
}

int LICZBY(Elem *&glowa, int n){
    int ilosc=0; //liczba dodanych elementów
//1. Do listy jednokierunkowej zawieraj¹cej liczby ca³kowite i zaczynaj¹cej siê pod jakimœ adresem dodaje jak¹œ liczbê elementów zawieraj¹cych losowe liczby ca³kowite z przedzia³u <-100,100>,
    Elem* akt = NULL;
    Elem* ost = NULL;

    for (int i=0;i<n;i++) {
        akt = new Elem;
		akt->liczba = rand() % (100 - (-100) + 1) + (-100);
        akt->next = NULL;
        ilosc++;

        if (glowa == NULL){
            glowa = akt;
            ost = glowa;
        } else {
            ost = glowa;
            while(ost->next!=NULL) {
                ost = ost->next;
            }
            ost->next = akt;
        }
    }

    stringstream ss ;
    ss << n;
    cout<<endl;
    WYPISZ(glowa, "Wynik kroku 1. Do listy dodano "+ss.str()+" element.");

//2 Dodaje po ka¿dym elemencie zawieraj¹cym liczbê ujemn¹ element zawieraj¹cy tê liczbê pomniejszon¹ o 10.
    akt=glowa;
    while(akt!=NULL){
        if (akt ->liczba <0) {
            Elem* pom = NULL;
            pom = new Elem;
            ilosc++;
            pom ->liczba = akt ->liczba-10 ;
            pom->next = akt->next;

            akt->next = pom;
            akt = akt->next;
        }
    akt = akt->next;
    }
    cout<<endl;
    WYPISZ(glowa, "Wynik kroku 2. Dodano po kazdym elemencie zawierajacym liczbz ujemna element zawierajacy te liczbe pomniejszona o 10");

//3. Dodaje jako przedostatni element liczbê -25, o ile to mo¿liwe.
	if ( glowa == NULL ) {
        cout << endl << "Wynik kroku 3. Brak mozliwosci dodania przedostatniego elementu. Lista pusta." << endl;
   }
	else if ( glowa != NULL  && (glowa->next == NULL) ) {
       cout << endl << "Wynik kroku 3. Brak mozliwosci dodania przedostatniego elementu. Lista zawiera jeden element." << endl;
   }
	else {
    Elem* przedost = NULL;
    akt = glowa;
    while(akt->next!=NULL) {
        przedost = akt;
        akt = akt->next;
    }
    ost = akt;

    Elem* pom = NULL;
    pom = new Elem;
    ilosc++;
    pom->liczba=-25;
    pom->next = ost;
    przedost->next = pom;

    cout << endl;
    WYPISZ(glowa, "Wynik kroku 3. Dodano jako przedostatni element liczbe -25.");
    }

//4. Przesuwa na pocz¹tek listy element zawieraj¹cy najwiêksz¹ liczbê (pierwszy z napotkanych, je¿eli jest kilka), o ile to mo¿liwe.

   if ( glowa == NULL ) {
        cout << endl <<"Wynik kroku 4. Przysuwanie nie zrealizowano. Lista pusta." << endl;
   }
   else if ( glowa != NULL  && (glowa->next == NULL) ) {
       cout << endl << "Wynik kroku 4. Przysuwanie nie zrealizowano. Lista zawiera jeden element. " << endl;
   }
   else {

    Elem* max = NULL;
    Elem* pop = NULL;
    Elem* pop_max = NULL;

    pop = glowa;
    akt = glowa;
    max = glowa;

    while(akt!=NULL) {
        if(akt->liczba > max->liczba ) {
                max = akt;
                pop_max=pop;
        }
        pop = akt;
        akt = akt->next;
    }

    if (max!=glowa) {
		pop_max->next=max->next;
        max->next = glowa;
        glowa = max;
    }

    stringstream ss2 ;
    ss2 << max->liczba;
    cout << endl;
    WYPISZ(glowa, "Wynik kroku 4. Przesunieto na poczatek listy element zawierajacy najwieksza liczbe " + ss2.str() );
   }

    return ilosc;

}

int main() {
    srand(time(NULL));
 //a. Losuje liczbê ca³kowit¹ N z przedzia³u <0,5>
    int N = rand() % 6 ;
    cout << "Wylosowana liczba N="<< N << endl;

//b. Tworzy listê jednokierunkow¹ zawieraj¹c¹ liczby ca³kowite i dodaje do niej N elementów zawieraj¹cych losowe liczby ca³kowite z przedzia³u <0,100>
    Elem* glowa;
    glowa = NULL;

    Elem* akt = NULL;
    Elem* ost = NULL;
    for (int i=0;i<N;i++) {
        akt = new Elem;
		akt->liczba = rand() % 101 ;
        akt->next = NULL;
        if (glowa == NULL){
            glowa = akt;
            ost = glowa;
        } else {
            ost = glowa;
            while(ost->next!=NULL) {
                ost = ost->next;
            }
            ost->next = akt;
        }
    }

    cout<<endl;
    WYPISZ(glowa, "Utworzona lista: ");

//c. wywo³uje funkcjê LICZBY
	int liczba = LICZBY(glowa, 3);

//d. drukuje informacjê o liczbie dodanych przez funkcjê elementów
    cout << endl << "Liczba dodanych przez funkcje elementow powna " << liczba << endl;


//e. kasuje utworzon¹ listê.
    Elem  *pom;
    while (glowa != NULL) {
        pom=glowa;
        glowa=glowa->next;
        delete pom;
	}

return 0;
}
