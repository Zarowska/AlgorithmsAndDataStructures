#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>

using namespace std;

struct STowar {
	string nazwa;
	double  cena;
	STowar *nast;
};
	//funkcja, która dopisuje towar o jakichś danych na początku listy zaczynającej się pod jakimś adresem
void dopiszNaPoczatek(STowar *&glowa, string ntow, double ctow) {
	STowar * p = new STowar;	//tworzymy nowy element
	if (glowa != NULL) {
		p->nazwa = ntow;	//umieszczamy dane w elemencie
		p->cena = ctow;		//umieszczamy dane w elemencie
		p->nast = glowa;	//następnikiem będzie bieżący pierwszy element listy
		glowa = p;	//ustawiamy początek listy na nowy element
	}
	else {
		glowa = new STowar;
		glowa->nazwa = ntow;
		glowa->cena = ctow;
		glowa->nast = NULL;
    };
};
	//funkcja drukująca listę zaczynając się pod jakimś adresem
void pisz(STowar *element) {
	while (element != NULL) {
		cout << element->nazwa << ": " << round(element->cena*100)/100  << " zl" << endl;
		element = element->nast;
	}
};
	//funkcja kasująca listę zaczynającą się pod jakimś adresem
void usun_liste (STowar  *&glowa) {
	STowar  *pom;
	while (glowa != NULL) {
		pom = glowa;	//zapamiętujemy element elementu do usunięcia
		glowa = glowa->nast;	//przesuwamy głowę dalej
		delete pom;		//usuwamy dotychczasową głowę
	}	//głowa po tej operacji usuwania jest równa NULL
};

int main() {

	STowar *glowa;
	glowa = NULL;
	string name = "towary";
	ifstream plik(name.c_str());

	if (!plik.good()) {
		cout << "Problem z otwarciem pliku" << endl;
		return 1;
	};

	string linia, s1;
	double suma, sr_a ;
	int j = 0;
	suma = sr_a = 0;

	while(!plik.eof()) {
	j++;	//liczba wczytanych towarów
	getline(plik, linia);	//pobierz linijkę
	int pos = linia.find("-");	 //pozycja znaku spacji w linii
	string s1 = linia.substr(0,pos-1);	//część pobranej linii przed spacją
	double result = atof((linia.substr(pos+1)).c_str());
	dopiszNaPoczatek(glowa, s1, result); 	//dla kolejnych linijek towary będą dodawane na początek listy
	suma += result;
	};
	plik.close();	//zamykamy plik

//2. Wydrukować utworzoną listę, korzystając z funkcji drukującej listę zaczynającą się pod jakimś adresem.
	cout << "Utworzona lista:" << endl;
	pisz(glowa);
	cout << endl;

//3. Dodać na pierwszym miejscu dodatkowo wczytany z klawiatury element tej listy.
	double cena_wczytana;
	string nazwa_wczytana;
	cout << "Podaj nazwe towaru" << endl;
	getline (cin,nazwa_wczytana);
	cout << "Podaj cene towaru" << endl;
	cin >> cena_wczytana;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(100,'\n');
		cout << "Blad we wprowadzeniu ceny. Podaj cene towaru" << endl;
		cin >> cena_wczytana;
	};
	dopiszNaPoczatek(glowa, nazwa_wczytana, cena_wczytana) ;
	suma += cena_wczytana;
	j++;
	sr_a = double(suma/j); 	//średnia cena wszystkich towarów

//4. Ponownie wydrukować listę.
	cout << endl << "Lista po dodaniu nowego elementu:" << endl;
	pisz(glowa);
	cin.ignore();
	cin.get();

//5. Wydrukować elementy listy zawierajace towary o cenie mniejszej niż średnia cena wszystkich towarów.
	cout << endl << "Elementy listy zawierajace towary o cenie mniejszej niz srednia cena (" << round(sr_a*100)/100 << " zl) wszystkich towarow:" << endl;
	STowar  *element;
	element = glowa;
	while (element != NULL) {
		if (element->cena < sr_a) {
			cout << "andres: " << element << " nazwa:" << element->nazwa << " cena: " << round(element->cena*100)/100 << " zl" << endl;
		};
		element = element->nast;
	};

//6. Skasować utworzoną listę korzystając z funkcji kasującej listę zaczynającą się pod jakimś adresem.
	usun_liste(glowa);

//7. Ponownie wydrukować listę.
	pisz(glowa);

	return 0;
}
