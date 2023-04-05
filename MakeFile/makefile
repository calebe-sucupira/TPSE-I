all: app

app: main.o ordenacao.o
	g++ -o bin/out main.o ordenacao.o 

main.o: src/main.cpp 
	g++ -c src/main.cpp

ordenacao.o: src/ordenacao.cpp
	g++ -c src/ordenacao.cpp

clean:
	rm app obj/*.o