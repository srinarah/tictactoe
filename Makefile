.PHONY: build

build:
	g++ -o tictactoe src/main.cpp

run:
	./tictactoe

clean:
	rm -f ./tictactoe
