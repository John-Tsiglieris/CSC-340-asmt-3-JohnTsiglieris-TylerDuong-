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
