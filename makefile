all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Bagli.cpp -o ./lib/Bagli.o
	g++ -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o
	g++ -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o 
	g++ -c -I "./include" ./src/AramaAgaci.cpp -o ./lib/AramaAgaci.o
	g++ -c -I "./include" ./src/Kontrol.cpp -o ./lib/Kontrol.o
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -c -I "./include" ./src/Queue.cpp -o ./lib/Queue.o
	g++ -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o 
	g++ -c -I "./include" ./src/Sistem.cpp -o ./lib/Sistem.o
	g++ -c -I "./include" ./src/TestProgrami.cpp -o ./lib/TestProgrami.o
bagla:
	g++  ./lib/TestProgrami.o ./lib/Bagli.o ./lib/Doku.o ./lib/Hucre.o  ./lib/AramaAgaci.o ./lib/Kontrol.o  ./lib/Organ.o ./lib/Organizma.o ./lib/Queue.o ./lib/Radix.o ./lib/Sistem.o  -o./bin/program
calistir:
	./bin/program
