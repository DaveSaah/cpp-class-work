#include "IntCell.h"

// construct Int_Cell with initial value
IntCell::IntCell(int initialValue) { this->storedValue = initialValue; }

// return the stored value
int IntCell::read() const { return this->storedValue; }

// store x
void IntCell::write(int x) { this->storedValue = x; }
