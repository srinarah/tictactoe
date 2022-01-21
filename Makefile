.PHONY: build

build:
	g++ -o tictactoe.out src/main.cpp

run:
	./tictactoe.out

clean:
	rm -f ./tictactoe.out
