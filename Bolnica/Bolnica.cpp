#include <iostream>
#include "Odjel.h"

int main()
{
	Odjel o;
	o.postaviOdjel();
	int izbor;
	do {
		system("cls");
		cout << "Odjel: " << o.getNaziv() << endl;
		cout << "\t1. Ispis odjela\n";
		cout << "\t2. Prijava pacijenta\n";
		cout << "\t3. Rezervacija\n";
		cout << "\t4. Oslobodi krevet\n";
		cout << "\t5. Kraj\n";
		cout << "\t\tOdabir: ";
		cin >> izbor;
		cin.ignore();
		switch (izbor) {
		case 1:
			o.ispisKreveta();
			break;
		case 2:
			o.smjestiPacijenta();
			break;
		case 3:
			o.rezervisiKrevet();
			break;
		case 4:
			o.ispisKreveta();
			int n;
			cout << "Unesite broj kreveta za osloboditi: ";
			cin >> n;
			cin.ignore();
			o.oslobodiKrevet(n);
			break;
		default:
			cout << "Pogresan odabir!\n";
		}
	} while (izbor != 5);

	return 0;
}

