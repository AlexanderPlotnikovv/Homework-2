#include <iostream>
#include <fstream>

class Address
{
protected:
	std::string City = "";
	std::string Street = "";
	int House = 1;
	int Flat = 1;
public:
	Address() {}
	Address(std::string City, std::string Street, int House, int Flat) {
		this->City = City;
		this->Street = Street;
		this->House = House;
		this->Flat = Flat;
	}
	void read(std::ifstream& File) {
		File >> City >> Street >> House >> Flat;
	}
	void write(std::ofstream& File1) {
		File1 << City << ", " << Street << ", " << House << ", " << Flat << std::endl;
	}
	std::string value() const {
		return City;
	}
};

int main()
{
	std::ifstream File("in.txt");
	int N;
	File >> N;
	Address* p = new Address[N];
	int i = 0;
	while (File.good() && i < N) {
		p[i].read(File);
		i++;
	}
	File.close();
	Address temp;
	std::ofstream File1("out.txt");
	File1 << N << std::endl;
	for (i = 0; i < N-1; i++) {
		for (int j = 0; j < N - i-1; j++) {
			if (p[j].value() > p[j+1].value()) {
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	for (int i = 0; i < N;i++) {
		p[i].write(File1);
	}
	File1.close();

	delete[] p;
	return 0;
}