NAME := PmergeMe

BUILD_DIR := obj
SRC_DIRS := ./

SRCS := main.cpp

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

CXXLDFLAGS = #-fsanitize=address -fno-sanitize=leak
LDFLAGS = $(CXXLDFLAGS)
CPPFLAGS := -I./ -MMD -MP
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g -pedantic $(CXXLDFLAGS)

all: $(NAME)

# The final build step.
$(NAME): $(OBJS)
	-@printf "${BLUE}"
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	-@printf "${GREEN}"
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

re: fclean all

clean:
	-@printf "${YELLOW}"
	-rm -rf $(BUILD_DIR)

fclean: clean
	-@printf "${RED}"
	-rm -f $(NAME)

-include $(DEPS)

.PHONY: all re fclean clean

# COLORS
export BGREEN = \033[1;32m
export GREEN = \033[0;32m
export BRED = \033[1;31m
export RED = \033[0;31m
export BYELLOW = \033[1;33m
export YELLOW = \033[0;33m
export BBLUE = \033[1;34m
export BLUE = \033[0;34m
export BCYAN = \033[1;36m
export CYAN = \033[0;36m
export NC = \033[0m
