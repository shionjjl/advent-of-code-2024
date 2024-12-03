# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Input and Output files
INPUT_FILE = test.in
OUTPUT_FILE = test.out

# Automatically find all directories starting with two digits
DIRS = $(wildcard ??*/)

# Collect all source files and executables from directories that start with two digits
SOURCES = $(wildcard $(addsuffix *.cpp, $(DIRS)))
EXECUTABLES = $(SOURCES:.cpp=)

# Default target: build everything
all: $(EXECUTABLES)

# Compile each .cpp file into its executable
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Run all executables with input from test.in and output to test.out
run: all
	@echo "Running programs and redirecting output to $(OUTPUT_FILE)"
	for exe in $(EXECUTABLES); do \
		dir=$$(dirname $$exe); \
		# Empty the output file before running \
		> $$dir/$(OUTPUT_FILE); \
	done
	# Loop through each executable and run with input from test.in
	for exe in $(EXECUTABLES); do \
		dir=$$(dirname $$exe); \
		if [ -f $$dir/$(INPUT_FILE) ]; then \
			cat $$dir/$(INPUT_FILE) | ./$$exe >> $$dir/$(OUTPUT_FILE); \
		fi; \
	done
	@echo "Results written to $(OUTPUT_FILE)"

# Clean up all executables
clean:
	for exe in $(EXECUTABLES); do \
		dir=$$(dirname $$exe); \
		if [ -f $$dir/$(OUTPUT_FILE) ]; then \
			rm $$dir/$(OUTPUT_FILE); \
		fi; \
	done
	rm -f $(EXECUTABLES)
