all: run clean

build:
	@g++ *.cpp *.h -o main.out

run: build
	@./main.out

clean:
	@rm *.out

debug:
	@g++ -g *.cpp *.h -o main.out
	@gdb main.out
