
all: singleNum allNums

singleNum: main.cpp pi.h
	$(CXX) -Ofast -march=native main.cpp -o singleNum

allNums: main.cpp pi.h
	$(CXX) -DMODE -Ofast -march=native main.cpp -o allNums
