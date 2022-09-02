CC=g++ -g

bin/vend: src/*.cpp
	$(CC) $^ -o bin/vend

run: bin/vend
	$^