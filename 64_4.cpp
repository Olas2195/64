#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Obrazki{
	ifstream plik;
	vector <string> obraz;
	
	public:
		Obrazki();
		~Obrazki();
		void wczytaj();
		bool czy_naprawialny();
};

Obrazki::Obrazki() {
	plik.open("dane_obrazki.txt");
}

void Obrazki::wczytaj() {
	string wiersz;
	int nr_obrazka=0;
	int x=0;
	if(plik.good()) {
		while(!plik.eof()) {
			nr_obrazka++;
			for(int i=0; i<21; i++) {
				plik>>wiersz;
				obraz.push_back(wiersz);
			}
			if(this->czy_naprawialny()) {
				cout<<"Nr obrazka: "<<nr_obrazka<<"\n\n";
			}
			obraz.clear();
		}
	}
}

bool Obrazki::czy_naprawialny() {
	int ile1=0;
	int b_k=0, b_w=0;
	int y=0, x=0;
	for (int w=0; w<20; w++) {
		for (int k=0; k<20; k++) {
			if (obraz[w][k]=='1') {
			    ile1++;
			}
		}
		if ((ile1%2==0 && obraz[w][20]=='1') || (ile1%2==1 && obraz[w][20]=='0')) {
			b_w++;
			x=w;
		}
	}
	if (b_w>1) {
		return false;
	}
	
	ile1=0;
	for (int k=0; k<20; k++) {
		for (int w=0; w<20; w++) {
			if (obraz[w][k]=='1') {
			    ile1++;
			}
		}
		if ((ile1%2==0 && obraz[20][k]=='1') || (ile1%2==1 && obraz[20][k]=='0')) {
			b_k++;
			y=k;
		}
	}
	if (b_w==1 || b_k==1) {
		cout<<"Wspolrzedne: "<<x+1<<" "<<y+1<<"\n";
		return true;	
	}
	return false;
}

Obrazki::~Obrazki() {
	plik.close();
}

int main(int argc, char** argv) {
	Obrazki o;
	o.wczytaj();
	
	return 0;
}


