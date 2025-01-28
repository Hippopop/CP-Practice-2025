# Global configuration!
output_dir = bin

# Configure for any Cpp file!
name = filename
compiler = g++
output_path = $(output_dir)/$(name).out


# Actual configuration!
all: run

run: build
	clear
	./$(output_path)

build: 
	mkdir -p $(output_dir)
	$(compiler) $(name).cpp -o $(output_path)

clean: 
	rm -rf $(output_dir)
