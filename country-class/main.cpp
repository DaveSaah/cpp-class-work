#include <iostream>
using namespace std;

class Country {
  public:
    Country(string name, int population, string continent, string capital);
    int getPopulation();
    void printInfo();
    void setName(string name);

  private:
    int population;
    string name;
    string continent;
    string capital;
};

Country::Country(string name, int population, string continent, string capital) {
  this->name = name;
  this->population = population;
  this->continent = continent;
  this->capital = capital;
}

int Country::getPopulation() {
  return population;
}

void Country::setName(string name) {
  this->name = name;
}

void Country::printInfo() {
  cout << "name: " << name << ", " << "population: " << population
    << ", " << "continent: " << continent << ", " << "capital: "
    << capital << endl;
}

int main() {
  Country ghana("Ghana", 30000000, "Africa", "Accra");
  ghana.printInfo();
}
