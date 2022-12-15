#include "Krevet.h"

Krevet::Krevet() {
	this->status = slobodan;
}

void Krevet::setBroj(int a) {
	this->broj = a;
}

void Krevet::setStatus(Status x) {
	this->status = x;
}

int Krevet::getBroj() {
	return this->broj;
}

Status Krevet::getStatus() {
	return this->status;
}

void Krevet::postaviKrevet(int a, Status x) {
	this->broj = a;
	this->status = x;
}