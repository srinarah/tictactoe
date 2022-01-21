.PHONY: build

build:
	g++ -o tictactoe.out src/main.cpp

run:
	./tictactoe.out

clean:
	rm -f ./tictactoe.out

test-draw:
	echo
	echo "Testing draw scenario"
	./tictactoe.out < test/draw.txt | grep --color "It is a draw"

test-win:
	echo
	echo "Testing win scenario"
	./tictactoe.out < test/win.txt | grep --color "Sudhama wins"

test-eof-mid-game:
	echo
	echo "Testing EOF mid-game scenario"
	./tictactoe.out < test/eof_mid_game.txt | grep --color "incomplete"

test-eof-after-one-name:
	echo
	echo "Testing scenario with EOF after player x's name"
	./tictactoe.out < test/eof_after_one_name.txt | grep --color "Player Y"

test-immediate-eof:
	echo
	echo "Testing scenario with immediate EOF"
	./tictactoe.out < /dev/null | grep --color "Player X"

test: test-draw test-win test-eof-after-one-name test-immediate-eof
	echo
	echo "All tests successful!"

test-all: build test
