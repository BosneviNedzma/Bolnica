#pragma once
enum Status{slobodan, zauzet, rezervisan};

class Krevet {
private:
	int broj;
	Status status;

public:
	Krevet();
	void setBroj(int a);
	void setStatus(Status x);
	int getBroj();
	Status getStatus();
	void postaviKrevet(int a, Status x);
	~Krevet() = default;
};
