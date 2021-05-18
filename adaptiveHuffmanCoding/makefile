CXX := g++

HEADER_DIR := ./include
BUILD_DIR := ./build
BIN_DIR := ./bin
SRC_DIR := ./src

INCLUDE := -I $(HEADER_DIR)

all : bin build encoder decoder 

bin :
	@mkdir -p $(BIN_DIR)

build :
	@mkdir -p $(BUILD_DIR)

encoder: $(BUILD_DIR)/encoder.o $(BUILD_DIR)/adaptiveHuffmanTree.o
	$(CXX) $(INCLUDE) $^ -o $(BIN_DIR)/$@

decoder: $(BUILD_DIR)/decoder.o $(BUILD_DIR)/adaptiveHuffmanTree.o
	$(CXX) $(INCLUDE) $^ -o  $(BIN_DIR)/$@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(INCLUDE) -c -o $@ $^

clean :
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BIN_DIR)
