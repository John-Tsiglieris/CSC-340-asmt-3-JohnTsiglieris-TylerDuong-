# Compiler
CXX = g++

# Directories
BUILD_DIR = out

# Source files
SRCS = $(wildcard *.cpp) # wtf is wilfcard

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Output executable
EXEC = $(BUILD_DIR)/my_program

# Compilation flags
CXXFLAGS = -Wall -Werror -std=c++17

 # Compile .cpp files into .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link all .o files into an executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Run the program
run: 
	@echo running executable
	$(EXEC)
	./$(EXEC)

# Clean all generated files
clean:
	@echo cleaning generated files
	rm -rf $(BUILD_DIR)