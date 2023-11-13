# tool macros
CXX := c++
CXXFLAGS := -I./include/ -Wall -Werror -Wextra -std=c++98 $(DFLAGS)
CCOBJFLAGS := $(CXXFLAGS) -c

# path macros
BIN_PATH := ./
OBJ_PATH := obj
SRC_PATH := ./

# compile macros
TARGET_NAME := phone

TARGET := $(BIN_PATH)/$(TARGET_NAME)

# src files & obj files
SRC := $(foreach x, $(SRC_PATH), util.cpp Contact.cpp PhoneBook.cpp main.cpp)
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
	@echo -n "${BLUE}"
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	@echo -n "${GREEN}"
	$(CXX) $(CCOBJFLAGS) -o $@ $<

# phony rules
.PHONY: makedir
makedir:
	@echo -n "${CYAN}"
	@mkdir -p $(BIN_PATH) $(OBJ_PATH)

.PHONY: fclean
fclean:
	@echo -n "${YELLOW}"
	rm -f $(CLEAN_LIST)

.PHONY: clean
clean:
	@echo -n "${YELLOW}"
	rm -f $(DISTCLEAN_LIST)

# COLORS
export GREEN = \033[1;32m
export RED = \033[0;31m
export BEIGE = \033[1;33m
export YELLOW = \033[0;33m
export BLUE = \033[1;34m
export CYAN = \033[1;36m
export NC = \033[0m
