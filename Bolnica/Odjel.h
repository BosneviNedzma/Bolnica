#pragma once
#include "Krevet.h"
#include <vector>

class Odjel {
private:
	char naziv[50];
	static int maxKreveta;
	vector<Krevet>kreveti;

public:
	Odjel();
	void setNaziv();
	static void setMaxKrevet();
	void setKreveti();
	char* getNaziv();
	static int getMaxKreveti();
	vector<Krevet>& getKreveti();
	void postaviOdjel();
	void smjestiPacijenta();
	void rezervisiKrevet();
	void oslobodiKrevet();
	void ispisKreveta();
	~Odjel() = default;
};