#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Obrazki{
	ifstream plik;
	ofstream plik2;
	vector <string> obraz;
	
	public:
		Obrazki();
		~Obrazki();
		void wczytaj();
		bool zbadaj();

};

Obrazki::Obrazki() {
	plik.open("dane_obrazki.txt");
	plik2.open("wyniki_obrazki.txt");
}

void Obrazki::wczytaj() {
	int lini=0;
	int rekurencyjnych=0;
	string wiersz;
	string pusta;
	if(plik.good()) {
		while(!plik.eof()) {
			lini++;
			plik>>wiersz;
			obraz.push_back(wiersz);
			if(lini==20){
				if(this->zbadaj()) {
					rekurencyjnych++;
				}
				lini=0;
				obraz.clear();
				plik>>pusta;
			}
		}
	}
	cout<<rekurencyjnych;
}

bool Obrazki::zbadaj() {
	vector <string> szablon;
	for(int i=0; i<obraz.size()/2; i++) {
		string pierwszy = obraz[i].substr(0, obraz[i].length()/2);
		string drugi = obraz[i].substr(obraz[i].length()/2, obraz[i].length()/2);
		if(pierwszy!=drugi) {
			return false;
		}
		szablon.push_back(pierwszy);
	}
	int j=0;
	for(int i=obraz.size()/2; i<obraz.size(); i++) {
		string trzeci = obraz[i].substr(0, obraz[i].length()/2);
		string czwarty = obraz[i].substr(obraz[i].length()/2, obraz[i].length()/2);
		if(trzeci!=szablon[j] || czwarty!=szablon[j]) {
			return false;
		}
		j++;
	}
	return true;
}

Obrazki::~Obrazki() {
	plik.close();
	plik2.close();
}

int main(int argc, char** argv) {
	Obrazki o;
	o.wczytaj();
	
	return 0;
}
