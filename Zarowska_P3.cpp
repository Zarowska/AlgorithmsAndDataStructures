#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h> //dla srand(time(NULL));

using namespace std;

struct Twezel  {
   int Dane;
   Twezel *Lewy;
   Twezel *Prawy;
 };

struct Elem{
    int liczba;
    Elem* next;
};


bool DODAJ (Twezel *&wezel, int wartosc) {
    bool dodano;
    dodano = false;
   if (wezel == NULL) {
       wezel = new Twezel;
       wezel -> Dane = wartosc;
       wezel -> Lewy = NULL;
       wezel -> Prawy = NULL;
   }
   else
     if (wartosc < wezel -> Dane) DODAJ (wezel -> Lewy, wartosc );
   else
     if (wartosc > wezel -> Dane) DODAJ (wezel -> Prawy, wartosc );
   dodano = true ;
   return dodano;
}


void WYSWIETL (Twezel *wezel) {
  // porządek inorder
   if (wezel != NULL) {
         WYSWIETL (wezel->Lewy);
         cout << wezel->Dane << " ";
         WYSWIETL (wezel->Prawy);
  }
}

bool ZNAJDZ (Twezel* wezel, int wartosc) {
	bool wystepuje = false;
	if (wezel == NULL )
		return wezel;

	if ( wartosc == wezel->Dane) {
		wystepuje = true;
		return wystepuje;
	}

	if (wartosc < wezel->Dane)
		return ZNAJDZ (wezel->Lewy, wartosc);
	else
		return ZNAJDZ (wezel->Prawy, wartosc);
}


int WYSOKOSC (Twezel* wezel) {
	int wysokosc = 0;

	if (wezel == NULL ) {
        return wysokosc;
	}
	else {
        wysokosc = 1 + max (  WYSOKOSC(wezel->Lewy), WYSOKOSC(wezel->Prawy));
    }
}


int ROZMIAR (Twezel* wezel) {
	int rozmiar = 0;

	if (wezel != NULL) {
		rozmiar=1+ROZMIAR(wezel->Lewy)+ROZMIAR (wezel->Prawy);
	}
	return rozmiar;
}


Twezel* MAKSIMUM (Twezel* wezel) {
	int liczba =0;

	while (wezel->Prawy != NULL){
		wezel=wezel->Prawy;
	}
	return wezel;
}

void PRZEPISZ (Twezel *wezel,Elem *&glowa) {
	int licz;
	Elem* akt = NULL;
	Elem* ost = NULL;

	if (wezel != NULL) {
		PRZEPISZ (wezel->Lewy,glowa );
		licz= wezel->Dane ;
		akt = new Elem;
		akt ->liczba = licz;
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
			ost = akt;
		}
		PRZEPISZ (wezel->Prawy,glowa );
	}
}


void USUN (Twezel *&wezel) {
	Twezel *pom;
	if (wezel != NULL)  {
		USUN (wezel -> Lewy);
		USUN (wezel -> Prawy);
		pom=wezel;
		wezel=NULL;
		delete pom;
	}
}


void DODAJ2(Elem *&glowa, int licz ){
Elem* akt = NULL;
Elem* ost = NULL;
    akt = new Elem;
    akt->liczba =licz;
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
        ost = akt;
    }
}






void WYSWIETL2(Elem *glowa){
    Elem* akt =glowa;
    while(akt!=NULL){
        cout<<akt->liczba<<" ";
        akt = akt->next;
    }
}


void USUN2(Elem *&glowa) {
	Elem *pom;
	while (glowa != NULL) {
		pom = glowa;	//zapamiętujemy element elementu do usunięcia
		glowa = glowa->next;	//przesuwamy głowę dalej
		delete pom;		//usuwamy dotychczasową głowę
	}	//głowa po tej operacji usuwania jest równa NULL
};


////////////////////////////////////////////////////////////////////////////////////////////////////

Elem* SORTUJedList(Elem* lst1, Elem* lst2)
{
	Elem* result = NULL;

	if (lst1 == NULL)
		return (lst2);
	else if (lst2 == NULL)
		return (lst1);

	if (lst1->liczba <= lst2->liczba) {
		result = lst1;
		result->next = SORTUJedList(lst1->next, lst2);
	}
	else {
		result = lst2;
		result->next = SORTUJedList(lst1, lst2->next);
	}
	return result;
}

void SplitList(Elem* source, Elem** front, Elem** back)
{
	Elem* ptr1;
	Elem* ptr2;
	ptr2 = source;
	ptr1 = source->next;

	while (ptr1 != NULL) {
		ptr1 = ptr1->next;
		if (ptr1 != NULL) {
			ptr2 = ptr2->next;
			ptr1 = ptr1->next;
		}
	}

	*front = source;
	*back = ptr2->next;
	ptr2->next = NULL;
}


void SORTUJ(Elem** tglowa)
{
	Elem* glowa = *tglowa;
	Elem* ptr1;
	Elem* ptr2;

	if ((glowa == NULL) || (glowa->next == NULL)) {
		return;
	}

	SplitList(glowa, &ptr1, &ptr2);

	SORTUJ(&ptr1);
	SORTUJ(&ptr2);

	*tglowa = SORTUJedList(ptr1, ptr2);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

int main( ) {

Twezel* korzen;
korzen=NULL;

for (int i=0; i<30; i++) {
    cout << "_" ;
};
cout << endl  << "Pierwsza czesc zadania P3" << endl;
for (int i=0; i<30; i++) {
    cout << "_" ;
};

//a) wypełnić drzewo kolejno liczbami: 8,4,12,2,6,10,14,1,3,5,7,9,11,13,15 (bez interakcji z użytkownikiem)
cout  << endl << endl <<  "Krok 1.a)" << endl;

DODAJ (korzen, 8  );
if (DODAJ) cout <<  "Dodano liczbe " << 8 << endl;
DODAJ (korzen, 4  );
if (DODAJ) cout <<  "Dodano liczbe " << 4 << endl;
DODAJ (korzen, 12 );
if (DODAJ) cout <<  "Dodano liczbe " << 12 << endl;
DODAJ (korzen, 2  );
if (DODAJ) cout <<  "Dodano liczbe " << 2 << endl;
DODAJ (korzen, 6  );
if (DODAJ) cout <<  "Dodano liczbe " << 6 << endl;
DODAJ (korzen, 10 );
if (DODAJ) cout <<  "Dodano liczbe " << 10 << endl;
DODAJ (korzen, 14 );
if (DODAJ) cout <<  "Dodano liczbe " << 14 << endl;
DODAJ (korzen, 1  );
if (DODAJ) cout <<  "Dodano liczbe " << 1 << endl;
DODAJ (korzen, 3  );
if (DODAJ) cout <<  "Dodano liczbe " << 3 << endl;
DODAJ (korzen, 5  );
if (DODAJ) cout <<  "Dodano liczbe " << 5 << endl;
DODAJ (korzen, 7  );
if (DODAJ) cout <<  "Dodano liczbe " << 7 << endl;
DODAJ (korzen, 9  );
if (DODAJ) cout <<  "Dodano liczbe " << 9 << endl;
DODAJ (korzen, 11 );
if (DODAJ) cout <<  "Dodano liczbe " << 11 << endl;
DODAJ (korzen, 13 );
if (DODAJ) cout <<  "Dodano liczbe " << 13 << endl;
DODAJ (korzen, 15 );
if (DODAJ) cout <<  "Dodano liczbe " << 15 << endl;

//DODAJ (korzen, 17 ); //dla testów
//if (DODAJ) cout <<  "Dodano liczbe " << 17 << endl; //dla testów

//b) wypisać zawartość drzewa na ekranie w porządku inorder
cout  << endl <<  "Krok 1.b)" << endl;
cout  <<  "Wyswietlanie drzewa w porzadku inorder: " << endl;
WYSWIETL (korzen) ;

//c) wyznaczyć wysokość drzewa i wyświetlić ją na ekranie
cout  << endl << endl << "Krok 1.c)" << endl;
cout  << "Wysokosc dzewa jest rowna " << WYSOKOSC(korzen);

//d) dodać do drzewa 10 losowych liczb całkowitych z przedziału <16,30>
cout  << endl << endl <<   "Krok 1.d)" << endl;
for (int i=1; i<11; i++){
int liczba = 16+rand()%(30-16+1);
DODAJ (korzen, liczba );
if (DODAJ) cout  << "Dodano liczbe " << liczba << endl;
};

//e) ponownie wypisać zawartość drzewa na ekranie w porządku inorder
cout  << endl << "Krok 1.e)" << endl;
cout  <<  "Wyswietlanie drzewa w porzadku inorder: " << endl;
WYSWIETL (korzen) ;

//f) wyświetlić informację, jaka jest największa liczba w drzewie
cout  << endl << endl <<   "Krok 1.f)" << endl;
cout  <<  "Najwieksza liczba w drzewie jest rowna  " << MAKSIMUM(korzen)-> Dane ;

//g) wyświetlić informację, ile liczb zawiera drzewo
cout  << endl << endl <<   "Krok 1.g)" << endl;
cout  << "Ilosc liczb w drzewie - " << ROZMIAR(korzen);

//h) sprawdzić, czy w drzewie występuje liczba 22 i wyświetlić stosowny komunikat
cout  << endl << endl <<   "Krok 1.h)" << endl;
int liczba =22;
if (ZNAJDZ(korzen, 22))
    cout << "Liczba " << liczba << " wystepuje w drzewie ";
else
    cout << "Liczba " << liczba << " NIE wystepuje w drzewie ";

//i) przepisać zawartość drzewa w porządku inorder do nowej listy jednokierunkowej
cout  << endl << endl <<  "Krok 1.i)" << endl;
Elem* glowa;
glowa = NULL;
//cout << "glowa " << glowa  << endl; //dla testów
PRZEPISZ (korzen, glowa);
//cout << "glowa " << glowa << "glowa -> liczba " << glowa->liczba << endl; //dla testów
cout << "Lista: "  ;
Elem* akt =glowa;
while(akt!=NULL){
    cout<<akt->liczba<<" ";
    akt = akt->next;
}

//j) usunąć całe drzewo
cout  << endl << endl <<  "Krok j)" << endl;
USUN (korzen) ;
cout  <<  "Drzewo usunieto." << endl;


for (int i=0; i<30; i++) {
    cout << "_" ;
};
cout << endl  << "Druga czesc zadania P3" << endl;
for (int i=0; i<30; i++) {
    cout << "_" ;
};

//a) wyświetlić zawartość listy na ekranie
cout  << endl << endl << "Krok 2.a)" << endl;
cout  <<  "Zawartosc listy: " ;
WYSWIETL2(glowa);

//b) dodać na końcu listy 10 losowych liczb całkowitych z przedziału <31,50>
cout  << endl << endl <<  "Krok 2.b)" << endl;
for (int i=1; i<11; i++){
int liczba = 31+rand()%(50-31+1);
DODAJ2 (glowa, liczba );
cout  << "Do listy dodano " << liczba << endl;
};

//c) posortować listę rosnąco z zastosowaniem algorytmu Merge_Sort
cout  << endl << endl <<  "Krok 2.c)" << endl;
cout  <<  "Zawartosc listy przed sortowaniem: " << endl ;
WYSWIETL2(glowa);
SORTUJ(&glowa);

//d) ponownie wyświetlić zawartość listy na ekranie
cout  << endl << endl <<  "Krok 2.d)" << endl;
cout  <<  "Zawartosc listy po sortowaniu: " << endl ;
WYSWIETL2(glowa);

//e) usunąć listę
USUN2(glowa);
cout  << endl << endl <<  "Krok 2.e)" << endl;
cout  << "Lista zostala usunieta." << endl;
    return 0;
};
