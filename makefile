# USE THIS COMMAND FOR MANUAL COMPILATION
# g++ -c Amazon340.cpp -o out/Amazon340.o
# g++ -c AmazonMain.cpp -o out/AmazonMain.o
# g++ -c Good.cpp -o out/Good.o
# g++ -c Media.cpp -o out/Media.o
# g++ -c Product.cpp -o out/Product.o
# g++ -c Vendor.cpp -o out/Vendor.o
# g++ out/Amazon340.o out/AmazonMain.o out/Good.o out/Media.o out/Product.o out/Vendor.o -o prog
# ./out/prog

CXX = g++
CXXFLAGS = -Wall -std=c++17
SRC = Amazon340.cpp AmazonMain.cpp Good.cpp Media.cpp Product.cpp Vendor.cpp
OBJ = $(SRC:.cpp=.o)
OUT = out/my_program

all: $(OUT)

$(OUT): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(OUT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)
