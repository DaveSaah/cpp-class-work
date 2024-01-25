#ifndef _INTCELL_H_
#define _INTCELL_H_

class IntCell {
public:
  IntCell(int initialValue);
  int read() const;
  void write(int x);

private:
  int storedValue;
};

#endif // !_INTCELL_H
