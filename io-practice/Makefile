all: run clean

build:
	@g++ main.cpp -o main.out

run: build
	@./main.out

clean:
	@rm *.out

debug:
	g++ -g main.cpp -o main.out
	gdb main.out
