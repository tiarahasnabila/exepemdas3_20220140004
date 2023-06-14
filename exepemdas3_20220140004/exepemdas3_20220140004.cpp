#include <iostream>
#include <vector>
using namespace std;

class Penerbit;
class Pengarang{
public:
	string nama;
	vector <Penerbit*> daftar_Penerbit;
	Pengarang(string pNama) :nama(pNama) {
		cout << "Pengarang \"" << nama << "\" ada\n";
	}
	~Pengarang() {
		cout << "Pengarang\"" << nama << "\" tidak ada\n";
	}
	void tambahPenerbit(Penerbit*);
	void cetakPenerbit();
};

class Penerbit{
public:
	string nama;
	vector<Pengarang*> daftar_Pengarang;
	Penerbit(string pNama) :nama(pNama) {
		cout << "Penerbit \"" << nama << "\" ada\n";
	}
	~Penerbit() {
		cout << "Penerbit\"" << nama << "\" tidak ada\n";
	}

	void tambahPengarang(Pengarang*);
	void cetakPengarang();
};

class Buku {
public: string nama;
	  vector<Pengarang*> daftar_Pengarang;
	  Buku (string pNama) :nama(pNama) {
		  cout << "Penerbit \"" << nama << "\" ada\n";
	  }
	  ~Buku() {
		  cout << "Penerbit\"" << nama << "\" tidak ada\n";
	  }

	  void tambahPengarang(Pengarang*);
	  void cetakPengarang();
};


void Pengarang::tambahPenerbit(Penerbit* pPenerbit) {
	daftar_Penerbit.push_back(pPenerbit);
}
void Pengarang::cetakPenerbit() {
	cout << "Daftar Pengarang yang dinaungi Penerbit \"" << this-> nama << "\":\n";
	for (auto& a : daftar_Penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void Penerbit::tambahPengarang(Pengarang* pPengarang) {
	daftar_Pengarang.push_back(pPengarang);
	pPengarang->tambahPenerbit(this);
}
void Penerbit::cetakPengarang() {
	cout << "Daftar Penerbit yang diikuti Pengarang\"" << this-> nama << "\":\n";
	for (auto& a : daftar_Pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void Buku::tambahPengarang(Pengarang* pPengarang) {
	daftar_Pengarang.push_back(pPengarang);
}
void Buku::cetakPengarang() {
	cout << "Daftar Buku yang dikarang Pengarang \"" <<  this-> nama << "\":\n";
		for (auto& a : daftar_Pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	Penerbit* varPenerbit1= new Penerbit("Gama Press");
	Penerbit* varPenerbit2 = new Penerbit("Intan Pariwara");
	Pengarang* varPengarang1 = new Pengarang("Joko");
	Pengarang* varPengarang2 = new Pengarang("Lia");
	Pengarang* varPengarang3 = new Pengarang("Giga");
	Pengarang* varPengarang4 = new Pengarang("Asroni");

	varPenerbit1->tambahPengarang(varPengarang1);
	varPenerbit1->tambahPengarang(varPengarang2);
	varPenerbit1->tambahPengarang(varPengarang3);
	varPenerbit2->tambahPengarang(varPengarang4);
	varPenerbit2->tambahPengarang(varPengarang3);

	varPenerbit1->cetakPengarang();
	varPenerbit2->cetakPengarang();
	varPengarang1->cetakPenerbit();
	varPengarang2->cetakPenerbit();
	varPengarang3->cetakPenerbit();
	varPengarang4->cetakPenerbit();

	delete varPengarang1;
	delete varPengarang2;
	delete varPengarang3;
	delete varPenerbit1;
	delete varPenerbit2;

	return 0;
}