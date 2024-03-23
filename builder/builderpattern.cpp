#include <iostream>

/**
 * "Product"
 */
class Pizza {
public:
  void setDough(const std::string &dough) { this->dough = dough; }

  void setSauce(const std::string &sauce) { this->sauce = sauce; }

  void setTopping(const std::string &topping) { this->topping = topping; }

  void describePizza() {
    std::cout << "Pizza with dough: " << dough << ", sauce: " << sauce
              << ", topping: " << topping << std::endl;
  }

private:
  std::string dough = "";
  std::string sauce = "";
  std::string topping = "";
};

/**
 * "Abstract Builder"
 */
class PizzaBuilder {
protected:
  Pizza *pizza;

public:
  Pizza *getPizza() { return pizza; }

  void createNewPizzaProduct() { pizza = new Pizza(); }

  virtual void buildDough() = 0;
  virtual void buildSauce() = 0;
  virtual void buildTopping() = 0;
};

/**
 * "ConcreteBuilder"
 */
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
  void buildDough() { pizza->setDough("cross"); }

  void buildSauce() { pizza->setSauce("mild"); }

  void buildTopping() { pizza->setTopping("ham+pineapple"); }
};

/**
 * "ConcreteBuilder"
 */
class SpicyPizzaBuilder : public PizzaBuilder {
public:
  void buildDough() { pizza->setDough("pan baked"); }

  void buildSauce() { pizza->setSauce("hot"); }

  void buildTopping() { pizza->setTopping("pepperoni+salami"); }
};

/**
 * "Director"
 */
class Waiter {
private:
  PizzaBuilder *pizzaBuilder;

public:
  void setPizzaBuilder(PizzaBuilder *pb) { pizzaBuilder = pb; }

  Pizza *getPizza() { return pizzaBuilder->getPizza(); }

  void constructPizza() {
    pizzaBuilder->createNewPizzaProduct();
    pizzaBuilder->buildDough();
    pizzaBuilder->buildSauce();
    pizzaBuilder->buildTopping();
  }
};

int main() {
  Waiter waiter;
  PizzaBuilder *hawaiianPizzaBuilder = new HawaiianPizzaBuilder();
  PizzaBuilder *spicyPizzaBuilder = new SpicyPizzaBuilder();

  waiter.setPizzaBuilder(hawaiianPizzaBuilder);
  waiter.constructPizza();

  Pizza *pizza = waiter.getPizza();

  std::cout << "Hawaiian Pizza:" << std::endl;
  pizza->describePizza();

  // You can perform any necessary operations with the pizza object here

  // Don't forget to deallocate memory to prevent memory leaks
  delete pizza;
  delete hawaiianPizzaBuilder;
  delete spicyPizzaBuilder;

  return 0;
}
