CXX :=	g++ -std=c++11 -g

buildthemakefile: Account.o Main.o
	$(CXX) Account.o main.o -o buildthemakefile


Account.o: Account.cc Account.hh
	$(CXX) -c Account.cc

Main.o: Account.hh
	$(CXX) -c Main.cc
