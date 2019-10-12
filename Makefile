TARGET := filter
SRC_DIR := ./

CC = g++
CFLAGS = -O3 -Wall -I$(SRC_DIR)
LDFLAGS =

DIRS = $(shell find $(SRC_DIR) -type d)
SRCS = $(foreach dir,$(DIRS),$(wildcard $(dir)/*.cpp))
DEPS = $(SRCS:%.cpp=%.d)
OBJS = $(SRCS:%.cpp=%.o)

all: $(TARGET)
$(TARGET): $(OBJS)
	@echo "Linking" $(TARGET)
	@$(CC) $(LDFLAGS) -o $(TARGET) $(CFLAGS) $(OBJS)

.PHONY: doc
doc:
	doxygen

.PHONY: clean
clean:
	@rm $(OBJS) $(DEPS)
	@rm $(TARGET)
	@rm -rf doc/

-include $(DEPS)

%.o: %.cpp
	@echo "Compiling" $(subst $(SRC_DIR)/,,$<)
	@$(CC) -c -MMD $(CFLAGS) $< -o $@
