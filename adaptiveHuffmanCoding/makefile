CXX := g++

HEADER_DIR := ./include
BUILD_DIR := ./build
BIN_DIR := ./bin
SRC_DIR := ./src

ENCODER := encoder.o
DECODER := decoder.o
ADAPTIVE_HUFFMAN_TREE := adaptiveHuffmanTree.o

all : $(BIN_DIR)/encoder $(BIN_DIR)/decoder

encoder : $(BIN_DIR)/encoder

decoder : $(BIN_DIR)/decoder

$(BIN_DIR)/encoder: $(BUILD_DIR)/$(ENCODER) $(BUILD_DIR)/$(ADAPTIVE_HUFFMAN_TREE)
	@mkdir -p $(BIN_DIR)
	$(CXX) -I $(HEADER_DIR) $^ -o $@

$(BIN_DIR)/decoder: $(BUILD_DIR)/$(DECODER) $(BUILD_DIR)/$(ADAPTIVE_HUFFMAN_TREE)
	$(CXX) -I $(HEADER_DIR) $^ -o $@

$(BUILD_DIR)/$(ENCODER): $(SRC_DIR)/encoder.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) -I $(HEADER_DIR) -c -o $@ $^

$(BUILD_DIR)/$(DECODER): $(SRC_DIR)/decoder.cpp
	$(CXX) -I $(HEADER_DIR) -c -o $@ $^

$(BUILD_DIR)/$(ADAPTIVE_HUFFMAN_TREE): $(SRC_DIR)/adaptiveHuffmanTree.cpp
	$(CXX) -I $(HEADER_DIR) -c -o $@ $^

clean :
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BIN_DIR)
