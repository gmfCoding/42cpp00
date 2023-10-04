# tool macros
CXX := c++
CXXFLAGS := $(DFLAGS) -I./include -std=c++98
CCOBJFLAGS := $(CXXFLAGS) -c

# path macros
BIN_PATH := ./
OBJ_PATH := obj
SRC_PATH := src

# compile macros
TARGET_NAME := megaphone

TARGET := $(BIN_PATH)/$(TARGET_NAME)

# src files & obj files
SRC := $(foreach x, $(SRC_PATH), main.cpp megaphone.cpp)
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

# clean files list
DISTCLEAN_LIST := $(OBJ)

CLEAN_LIST := $(TARGET) \
			  $(DISTCLEAN_LIST)

.PHONY: all
all: makedir $(TARGET)

.PHONY: re
re:	fclean all

# non-phony targets
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	$(CXX) $(CCOBJFLAGS) -o $@ $<

# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(BIN_PATH) $(OBJ_PATH)

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)

.PHONY: fclean
fclean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(DISTCLEAN_LIST)
