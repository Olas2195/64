#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Obrazki{
	ifstream plik;
	vector <string> obraz;
	int poprawnych = 0;
	int naprawialnych = 0;
	int niepoprawnych = 0;
	
	public:
		Obrazki();
		~Obrazki();
		void wczytaj();
		void czy_poprawny();
};

Obrazki::Obrazki() {
	plik.open("dane_obrazki.txt");
}

void Obrazki::wczytaj() {
	string wiersz, pusta;
	int lini=0;
	if(plik.good()) {
		while(!plik.eof()) {
			lini++;
			plik>>wiersz;
			obraz.push_back(wiersz);
			if(lini==21){
				this->czy_poprawny();
				lini=0;
				obraz.clear();
				plik>>pusta;
			}
		}
	}
	cout<<"poprawnych "<<poprawnych<<"\n";
	cout<<"niepoprawnych "<<niepoprawnych<<"\n";
	cout<<"naprawialnych "<<naprawialnych<<"\n";
}

void Obrazki::czy_poprawny() {
	int ile1=0;
	int blednych=0;
	bool poprawne_k = false;
	bool poprawne_w = false;
	for (int w=0; w<obraz.size()-1; w++) {
		for (int k=0; k<obraz.size()-1; k++) {
			if (obraz[w][k]=='1') {
			    ile1++;
			}
		}
		if ((ile1%2==0 && obraz[w][obraz.size()-1]=='0') || (ile1%2==1 && obraz[w][obraz.size()-1]=='1')) {
			poprawne_w = true;			
		}
		else {
			blednych++;
		}
	}
	if (blednych>2) {
		niepoprawnych++;
		return;
	}
	blednych=0;
	for (int k=0; k<obraz.size()-1; k++) {
		for (int w=0; w<obraz.size()-1; w++) {
			if (obraz[w][k]=='1') {
			    ile1++;
			}
		}
		if ((ile1%2==0 && obraz[obraz.size()-1][k]=='0') || (ile1%2==1 && obraz[obraz.size()-1][k]=='1')) {
			poprawne_k = true;			
		}
		else {
			blednych++;
		}
	}
	if (blednych>2) {
		niepoprawnych++;
		return;
	}
	if (poprawne_k && poprawne_w) {
		poprawnych++;
		return;
	}
	naprawialnych++;
	return;
}

Obrazki::~Obrazki() {
	plik.close();
}

int main(int argc, char** argv) {
	Obrazki o;
	o.wczytaj();
	
	return 0;
}
