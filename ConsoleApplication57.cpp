//----------------------------------------------------------------------------//
// Name: Liam Fricker                                                         //
// Student ID: 1126303                                                        //
// Assignment: #3                                                             //
//----------------------------------------------------------------------------//

/*
  This program determines the best selling automotive parts by searching a file
  of data and outputing the parts that produce the best revenue. It uses a large
  hierarchy of classes and data members. Each class has accessor/getters, a 
  default and parameterized constructor, and an overloaded ofstream operator.
*/

#include "stdafx.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#define PARTINFO_CNT 15

class Car
{
public:
	Car();
	Car(const string &nbrand, const string &nmodel, const string &nyear);
	string getBrand() const;
	string getModel() const;
	string getYear() const;
	void setBrand(const string &nbrand);
	void setModel(const string &nmodel);
	void setYear(const string &nyear);
	friend ofstream& operator << (ofstream& ofs, const Car &c);
private:
	string brand;
	string model;
	string year;
};

Car::Car() : brand(""), model(""), year("") {}
Car::Car(const string &nbrand, const string &nmodel, const string &nyear) : brand(nbrand),
	model(nmodel), year(nyear) {}
string Car::getBrand() const { return brand; }
string Car::getModel() const { return model; }
string Car::getYear() const { return year; }
void Car::setBrand(const string &nbrand) { brand = nbrand; }
void Car::setModel(const string &nmodel) { model = nmodel; }
void Car::setYear(const string &nyear) { year = nyear; }


class Manufacturer
{
public:
	Manufacturer();
	Manufacturer(const string &nname);
	string getName() const;
	void setName(const string &nname);
	friend ofstream& operator << (ofstream& ofs, const Manufacturer &m);
private:
	string name;
};

Manufacturer::Manufacturer() : name("") {}
Manufacturer::Manufacturer(const string &nname) : name(nname) {}
string Manufacturer::getName() const { return name; }
void Manufacturer::setName(const string &nname) { name = nname; }

class Parts
{
public:
	Parts();
	Parts(const string &ndescription, const string &nprice, const string &nname, const string &nQtySold);
	Parts(const string &ndescription, const string &nprice, const Manufacturer &nM, const string &nQtySold);
	string getDescription() const;
	float getPrice() const;
	Manufacturer getManufacturer() const;
	int getQuantitySold() const;
	void setDescription(const string &ndescription);
	void setPrice(const string &nprice);
	void setManufacturer(const Manufacturer &nM);
	void setQuantitySold(const string &nQtySold);
	friend ofstream& operator << (ofstream& ofs, const Parts &p);
private:
	string description;
	string price; 
	Manufacturer m;
	string QtySold;
};

Parts::Parts() : description(""), price(""), m(), QtySold("") {}
Parts::Parts(const string &ndescription, const string &nprice, const string &nname, const string &nQtySold) :
	description(ndescription), price(nprice), m(nname), QtySold(nQtySold) {}
Parts::Parts(const string &ndescription, const string &nprice, const Manufacturer &nM, const string &nQtySold) :
	description(ndescription), price(nprice), m(nM), QtySold(nQtySold) {}
string Parts::getDescription() const { return description; }
float Parts::getPrice() const { return stof(price); }
Manufacturer Parts::getManufacturer() const { return m; }
int Parts::getQuantitySold() const { return stoi(QtySold); }
void Parts::setDescription(const string &ndescription) { description = ndescription; }
void Parts::setPrice(const string &nprice) { price = nprice; }
void Parts::setManufacturer(const Manufacturer &nM) { m = nM; }
void Parts::setQuantitySold(const string &nQtySold) { QtySold = nQtySold; }

class Brakes : public Parts
{
public:
	Brakes();
	Brakes(const string &ndescription, const string &nprice, const string &nname, const string &nQtySold,
		const string &nbrand, const string &nmodel, const string &nyear, const string &mnmaterial);
	Car getCar() const;
	string getMaterial() const;
	void setCar(const Car &nC);
	void setMaterial(const string &nMaterial);
	friend ofstream& operator << (ofstream& ofs, const Brakes &b);
private:
	Car c;
	string material;
};

Brakes::Brakes() : Parts(), c(), material("") {}
Brakes::Brakes(const string &ndescription, const string &nprice, const string &nname, const string &nQtySold,
	const string &nbrand, const string &nmodel, const string &nyear, const string &nmaterial) :
	Parts(ndescription, nprice, nname, nQtySold), c(nbrand, nmodel, nyear), material(nmaterial) {}
Car Brakes::getCar() const { return c; }
string Brakes::getMaterial() const { return material; }
void Brakes::setCar(const Car &nC) { c = nC; }
void Brakes::setMaterial(const string &nmaterial) { material = nmaterial; }

class Lights : public Parts
{
public:
	Lights();
	Lights(const string &ndescription, const string &nprice, const string &nname, const string &nQtySold,
		const string &nbrand, const string &nmodel, const string &nyear, const string &nwatts);
	Car getCar() const;
	string getWatts() const;
	void setCar(const Car &nC);
	void setWatts(const string &nwatts);
	friend ofstream& operator << (ofstream& ofs, const Lights &l);
private:
	Car c;
	string watts;
};

Lights::Lights() : Parts(), c(), watts("") {}
Lights::Lights(const string &ndescription, const string &nprice, const string &nname, const string &nQtySold,
	const string &nbrand, const string &nmodel, const string &nyear, const string &nwatts) :
	Parts(ndescription, nprice, nname, nQtySold), c(nbrand, nmodel, nyear), watts(nwatts) {}
Car Lights::getCar() const { return c; }
string Lights::getWatts() const { return watts; }
void Lights::setCar(const Car &nC) { c = nC; }
void Lights::setWatts(const string &nwatts) { watts = nwatts; }

class Oil : public Parts
{
public:
	Oil();
	Oil(const string &ndescription, const string &nprice, const string &nname, const string &nQtySold,
		const string &nweight, const string &ntype, const string &nquarts);
	string getWeight() const;
	string getType() const;
	string getQuarts() const;
	void setWeight(const string &nweight);
	void setType(const string &ntype);
	void setQuarts(const string &nquarts);
	friend ofstream& operator << (ofstream& ofs, const Oil &o);
private:
	string weight, type;
	string quarts;
};

Oil::Oil() : Parts(), weight(""), type(""), quarts("") {}
Oil::Oil(const string &ndescription, const string &nprice, const string &nname, const string &nQtySold,
	const string &nweight, const string &ntype, const string &nquarts):
	Parts(ndescription, nprice, nname, nQtySold), weight(nweight), type(ntype), quarts(nquarts) {}
string Oil::getWeight() const { return weight; }
string Oil::getType() const { return type; }
string Oil::getQuarts() const { return quarts; }
void Oil::setWeight(const string &nweight) { weight = nweight; }
void Oil::setType(const string &ntype) { type = ntype; }
void Oil::setQuarts(const string &nquarts) { quarts = nquarts; }

class Tires : public Parts
{
public:
	Tires();
	Tires(const string &ndescription, const string &nprice, const string &nname, const string &nQtySold,
		const string &nsize, const string &nwarranty);
	string getSize() const;
	string getWarranty() const;
	void setSize(const string &nsize);
	void setWarranty(const string &nwarranty);
	friend ofstream& operator << (ofstream& ofs, const Tires &t);
private:
	string size;
	string warranty;
};

Tires::Tires() : Parts(), size(""), warranty("") {}
Tires::Tires(const string &ndescription, const string &nprice, const string &nname, const string &nQtySold,
	const string &nsize, const string &nwarranty) :
	Parts(ndescription, nprice, nname, nQtySold), size(nsize), warranty(nwarranty) {}
string Tires::getSize() const { return size; }
string Tires::getWarranty() const { return warranty; }
void Tires::setSize(const string &nsize) { size = nsize; }
void Tires::setWarranty(const string &nwarranty) { warranty = nwarranty; }

ofstream& operator << (ofstream& ofs, const Car &c);
ofstream& operator << (ofstream& ofs, const Manufacturer &m);
ofstream& operator << (ofstream& ofs, const Parts &p);
ofstream& operator << (ofstream& ofs, const Brakes &b);
ofstream& operator << (ofstream& ofs, const Lights &l);
ofstream& operator << (ofstream& ofs, const Oil &o);
ofstream& operator << (ofstream& ofs, const Tires &t);

//Parses a line of text into an array of strings.
void parseLineToTokens(string lineText, string tokens[]);
//Finds the occurence of a given part.
int findPart(ifstream &ifs, string part);
//Each of these read from the File to populate their respective arrays.
void readFileToBrakes(ifstream &IF, Brakes Barr[]);
void readFileToLights(ifstream &IF, Lights Larr[]);
void readFileToOil(ifstream &IF, Oil Oarr[]);
void readFileToTires(ifstream &IF, Tires Tarr[]);
//Each of these find the part in their respective catogories that produce the most revenue.
Brakes bestBrake(Brakes Barr[], int barrsize);
Lights bestLight(Lights Larr[], int larrsize);
Oil bestOil(Oil Oarr[], int oarrsize);
Tires bestTire(Tires Tarr[], int Tarrsize);

int main()
{
	//open the file from which to read the data
	ifstream PartsData("Parts_List.txt");
	//call a global function to find out how many objects of each type to create
	int BrakesSize = findPart(PartsData, "Brakes"), LightsSize = findPart(PartsData, "Lights"),
		OilSize = findPart(PartsData, "Oil"), TiresSize = findPart(PartsData, "Tires");
	//create arrays to contain the necessary objects
	Brakes *BrakesList = new Brakes[BrakesSize];
	Lights *LightsList = new Lights[LightsSize];
	Oil *OilList = new Oil[OilSize];
	Tires *TiresList = new Tires[TiresSize];
	//global function to read information from the file into the arrays of objects
	readFileToBrakes(PartsData, BrakesList);
	readFileToLights(PartsData, LightsList);
	readFileToOil(PartsData, OilList);
	readFileToTires(PartsData, TiresList);
	PartsData.close();
	//call functions to find the best selling item for each category, output best to a file
	Brakes b = bestBrake(BrakesList, BrakesSize);
	Lights l = bestLight(LightsList, LightsSize);
	Oil o = bestOil(OilList, OilSize);
	Tires t = bestTire(TiresList, TiresSize);
	ofstream BestParts("Best_Parts.txt");
	BestParts << b << l << o << t;
	//close the file explicitly
	delete[] BrakesList, LightsList, OilList, TiresList;
	BestParts.close();
	return 0;
}

// Parse a line of text into tokens and store them in an array of strings
void parseLineToTokens(string lineText, string tokens[])
{
	int end, start;

	start = -2;
	int k = 1;
	for (int j = 0; j + k < PARTINFO_CNT; j++)
	{
		start = start + 3;
		end = lineText.find('"', start);
		if (lineText.substr(start, end - start) == "") {
			tokens[PARTINFO_CNT - k++] = "";
			j--;
		}
		else {
			tokens[j] = lineText.substr(start, end - start);
		}
		start = end;
	
	}
}
int findPart(ifstream &IF, string part) {
	int end;
	IF.clear();
	IF.seekg(0, ios::beg);
	int i = 0;
	string filter;
	while (!IF.eof()) {
		IF >> filter;
		end = filter.find('"', 1);
		if (filter.substr(1, end - 1) == part) {
			i++;
		}
		getline(IF, filter);
	}
	return i;
}
void readFileToBrakes(ifstream &IF, Brakes Barr[]) {
	string filter, filterarr[15];
	int i = 0;
	IF.clear();
	IF.seekg(0, ios::beg);
	while (!IF.eof()) {
		getline(IF, filter);
		parseLineToTokens(filter, filterarr);
		if (filterarr[0].compare("Brakes") == 0) {
			Barr[i++] = Brakes(filterarr[1], filterarr[2], filterarr[3], filterarr[4], filterarr[5], filterarr[6], filterarr[7], filterarr[8]);
		}
	}
}
void readFileToLights(ifstream &IF, Lights Larr[]) {
	string filter, filterarr[15];
	int i = 0;
	IF.clear();
	IF.seekg(0, ios::beg);
	while (!IF.eof()) {
		getline(IF, filter);
		parseLineToTokens(filter, filterarr);
		if (filterarr[0].compare("Lights") == 0) {
			Larr[i++] = Lights(filterarr[1], filterarr[2], filterarr[3], filterarr[4], filterarr[5], filterarr[6], filterarr[7], filterarr[8]);
		}
	}
}
void readFileToOil(ifstream &IF, Oil Oarr[]) {
	string filter, filterarr[15];
	int i = 0;
	IF.clear();
	IF.seekg(0, ios::beg);
	while (!IF.eof()) {
		getline(IF, filter);
		parseLineToTokens(filter, filterarr);
		if (filterarr[0].compare("Oil") == 0) {
			Oarr[i++] = Oil(filterarr[1], filterarr[2], filterarr[3], filterarr[4], filterarr[5], filterarr[6], filterarr[7]);
		}
	}
}
void readFileToTires(ifstream &IF, Tires Tarr[]) {
	string filter, filterarr[15];
	int i = 0;
	IF.clear();
	IF.seekg(0, ios::beg);
	while (!IF.eof()) {
		getline(IF, filter);
		parseLineToTokens(filter, filterarr);
		if (filterarr[0].compare("Tires") == 0) {
			Tarr[i++] = Tires(filterarr[1], filterarr[2], filterarr[3], filterarr[4], filterarr[5], filterarr[6]);
		}
	}
}
Brakes bestBrake(Brakes Barr[], int barrsize){
	float mrevenue = Barr[0].getPrice() * Barr[0].getQuantitySold();
	int Pnum = 0;
	for (int i = 1; i < barrsize; i++) {
		if (mrevenue > Barr[i].getPrice() * Barr[i].getQuantitySold()) {
			mrevenue = Barr[i].getPrice() * Barr[i].getQuantitySold();
			Pnum = i;
		}
	}
	return Barr[Pnum];
}
Lights bestLight(Lights Larr[], int larrsize) {
	float mrevenue = Larr[0].getPrice() * Larr[0].getQuantitySold();
	int Pnum = 0;
	for (int i = 1; i < larrsize; i++) {
		if (mrevenue > Larr[i].getPrice() * Larr[i].getQuantitySold()) {
			mrevenue = Larr[i].getPrice() * Larr[i].getQuantitySold();
			Pnum = i;
		}
	}
	return Larr[Pnum];
}
Oil bestOil(Oil Oarr[], int oarrsize) {
	float mrevenue = Oarr[0].getPrice() * Oarr[0].getQuantitySold();
	int Pnum = 0;
	for (int i = 1; i < oarrsize; i++) {
		if (mrevenue > Oarr[i].getPrice() * Oarr[i].getQuantitySold()) {
			mrevenue = Oarr[i].getPrice() * Oarr[i].getQuantitySold();
			Pnum = i;
		}
	}
	return Oarr[Pnum];
}
Tires bestTire(Tires Tarr[], int tarrsize) {
	float mrevenue = Tarr[0].getPrice() * Tarr[0].getQuantitySold();
	int Pnum = 0;
	for (int i = 1; i < tarrsize; i++) {
		if (mrevenue > Tarr[i].getPrice() * Tarr[i].getQuantitySold()) {
			mrevenue = Tarr[i].getPrice() * Tarr[i].getQuantitySold();
			Pnum = i;
		}
	}
	return Tarr[Pnum];
}

ofstream& operator << (ofstream& ofs, const Car &c) {
	ofs << "\tCar: ";
	ofs << "\n\t\tBrand: " << c.brand;
	ofs << "\n\t\tModel: " << c.model;
	ofs << "\n\t\tYear: " << c.year << endl;
	return ofs;
}
ofstream& operator << (ofstream& ofs, const Manufacturer &m) {
	ofs << "\tManufacturer: " << m.name << endl;
	return ofs;
}
ofstream& operator << (ofstream& ofs, const Parts &p) {
	ofs << "\tDescription: " << p.description << endl;
	ofs << "\tPrice: " << fixed << setprecision(2) << p.price << endl;
	ofs << p.m;
	ofs << "\tQtySold: " << p.QtySold << endl;
	return ofs;
}
ofstream& operator << (ofstream& ofs, const Brakes &b) {
	ofs << "** Brakes **\n";
	ofs << Parts(b.getDescription(), to_string(b.getPrice()), b.getManufacturer(), to_string(b.getQuantitySold()));
	ofs << b.c;
	ofs << "\tMaterial: " << b.material << endl;
	return ofs;
}
ofstream& operator << (ofstream& ofs, const Lights &l) {
	ofs << "** Lights **\n";
	ofs << Parts(l.getDescription(), to_string(l.getPrice()), l.getManufacturer(), to_string(l.getQuantitySold()));
	ofs << l.c;
	ofs << "\tWatts: " << l.watts << endl;
	return ofs;
}
ofstream& operator << (ofstream& ofs, const Oil &o) {
	ofs << "** Oil **\n";
	ofs << Parts(o.getDescription(), to_string(o.getPrice()), o.getManufacturer(), to_string(o.getQuantitySold()));
	ofs << "\tWeight: " << o.weight << endl;
	ofs << "\tType: " << o.type << endl;
	ofs << "\tQuarts: " << o.quarts << endl;
	return ofs;
}
ofstream& operator << (ofstream& ofs, const Tires &t) {
	ofs << "** Tires **\n";
	ofs << Parts(t.getDescription(), to_string(t.getPrice()), t.getManufacturer(), to_string(t.getQuantitySold()));
	ofs << "\tSize: " << t.size << endl;
	ofs << "\tWarranty: " << t.warranty << endl;
	return ofs;
}

// Notes:
//
// I used stof and stoi because I found myself stuck and out of time near the end.
// Maybe I should've made a better outline of what I was planning to do.