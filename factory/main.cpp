#include <iostream>
#include <string>

class Plant {
private:
  std::string name;

public:
  Plant(const std::string &pname) : name(pname) {
    // Constructor to initialize the name
  }

  std::string getName() { return name; }
};

class Garden {
public:
  virtual Plant getCenter() = 0;
  virtual Plant getBorder() = 0;
  virtual Plant getShade() = 0;
};

class VegieGarden : public Garden {
public:
  Plant getShade() override { return Plant("Broccoli"); }

  Plant getCenter() override { return Plant("Corn"); }

  Plant getBorder() override { return Plant("Peas"); }
};

class PerennialGarden : public Garden {
public:
  Plant getShade() override { return Plant("Hosta"); }

  Plant getCenter() override { return Plant("Lily"); }

  Plant getBorder() override { return Plant("Lavender"); }
};

class AnnualGarden : public Garden {
public:
  Plant getShade() override { return Plant("Begonia"); }

  Plant getCenter() override { return Plant("Marigold"); }

  Plant getBorder() override { return Plant("Alyssum"); }
};

class GardenMaker {
private:
  Garden *gd;

public:
  Garden *getGarden(const std::string &gtype) {
    gd = new VegieGarden(); // Default is a Vegetable Garden
    if (gtype == "Perennial") {
      delete gd;
      gd = new PerennialGarden();
    } else if (gtype == "Annual") {
      delete gd;
      gd = new AnnualGarden();
    }
    return gd;
  }
};

int main() {
  GardenMaker gardenMaker;

  Garden *myGarden = gardenMaker.getGarden("Perennial");

  Plant centerPlant = myGarden->getCenter();
  Plant borderPlant = myGarden->getBorder();
  Plant shadePlant = myGarden->getShade();

  std::cout << "Center Plant: " << centerPlant.getName() << std::endl;
  std::cout << "Border Plant: " << borderPlant.getName() << std::endl;
  std::cout << "Shade Plant: " << shadePlant.getName() << std::endl;

  delete myGarden;

  return 0;
}
