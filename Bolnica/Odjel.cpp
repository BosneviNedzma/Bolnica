#include <iostream>
#include "Odjel.h"

using namespace std;

int Odjel::maxKreveta = 0;

Odjel::Odjel() {
	Odjel::maxKreveta = 0;
	strcpy(this->naziv, "Novi odjel");
}

void Odjel::setNaziv() {
	cout << "Unesite naziv odjela: ";
	cin.getline(this->naziv, 50);
}

void Odjel::setMaxKrevet() {
	cout << "Unesite broj kreveta na odjelu: ";
	cin >> Odjel::maxKreveta;
	cin.ignore();
}

void Odjel::setKreveti() {
	shared_ptr<Krevet>temp = make_shared<Krevet>();
	for (int i = 0; i < Odjel::maxKreveta; i++) {
		temp->postaviKrevet(i, slobodan);
		this->kreveti.push_back(*temp);
	}
}

char* Odjel::getNaziv() {
	return this->naziv;
}

int Odjel::getMaxKreveti() {
	return Odjel::maxKreveta;
}

vector<Krevet>& Odjel::getKreveti() {
	return this->kreveti;
}

void Odjel::postaviOdjel() {
	this->setNaziv();
	this->setMaxKrevet();
	this->setKreveti();
}

void Odjel::smjestiPacijenta() {
	bool smjesten = false;
	try {
		for (int i = 0; i < this->kreveti.size(); i++) {
			if (this->kreveti[i].getStatus() == slobodan && !smjesten) {
				this->kreveti[i].setStatus(zauzet);
				cout << "Pacijent smjesten na krevet broj " << i + 1 << ". \n";
				smjesten = true;
			}
		}
		if (!smjesten) {
			throw "Svi kreveti zauzeti!\n";
		}
	}
	catch (const char* Greska) {
		cout << "Greska " << Greska;
	}

	catch (...) {
		cout << "Greska, Nepoznata greska!\n";
	}
}

void Odjel::rezervisiKrevet() {
	bool puno = true;
	for (int i = 0; i < this->kreveti.size(); i++) {
		if (this->kreveti[i].getStatus() == slobodan) {
			cout << i + 1 << ". krevet\n";
			puno = false;
		}
	}
	if (puno) {
		cout << "Zao mi je. Svi kreveti zauzeti/rezervisani!\n";
	}
	else {
		int rBr;
		cout << "Unesite redni broj kreveta koji zelite rezervisati: ";
		cin >> rBr;
		cin.ignore();
		if (this->kreveti[rBr - 1].getStatus() == slobodan) {
			this->kreveti[rBr - 1].setStatus(rezervisan);
			cout << "Rezervisan krevet broj " << rBr << endl;
		}
		else {
			cout << "Nisi to trebao uraditi.\n";
		}
	}
}

void Odjel::oslobodiKrevet(int n) {
	try {
		if (n > Odjel::getMaxKreveti() || n < 0) {
			throw 5n;
		}
		else if (this->kreveti[n - 1].getStatus() == slobodan) {
			throw "Taj krevet je vec slobodan!\n";
		}
		else if (this->kreveti[n - 1].getStatus() == rezervisan) {
			throw "Taj krevet je rezervisan!\n";
		}
		else {
			this->kreveti[n - 1].setStatus(slobodan);
			cout << "Krevet broj " << n << " je sada slobodan!\n";
		}
	}
	catch (int n) {
		cout << "Greska, ne postoji krevet sa brojem " << n << endl;
	}
	catch (const char* Greska) {
		cout << "Greska " << Greska;
	}

	catch (...) {
		cout << "Greska, nepoznata greska!\n";
	}
}

void Odjel::ispisKreveta() {
	cout << "Odjel: " << this->getNaziv() << endl;
	cout << "Broj\t\tStatus\n";
	cout << "krevet\t\tkreveta\n";
	for (int i = 0; i < this->kreveti.size(); i++) {
		cout << i + 1 << "\t\t";
		if (this->kreveti[i].getStatus() == slobodan) {
			cout << "Slobodan\n";
		}
		else if(this->kreveti[i].getStatus() == zauzet) {
			cout << "Zauzet\n";
		}
		else {
			cout << "Rezervisan\n";
		}
	}
}