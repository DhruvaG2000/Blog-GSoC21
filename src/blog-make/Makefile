CC = gcc
DEFAULT_COMMON_FLAGS = -Werror -Wall -std=c++11 -g		# Flags: 1 for AM572x || 0 for AM33xx 
EXECUTABLE = bin/runfile
SRC = board_detect.cpp 
HEADER = board_detect.h

#Below is flag to detect if device is BBAI or Not
IS_AM572x :=$(shell grep -q AI model && echo 1 || echo 0)


all: $(SRC) $(HEADER)
	echo $(cur_dir)
ifeq ($(IS_AM572x),1)
	@echo AM572x chip detected
	$(CC) $(DEFAULT_COMMON_FLAGS) $(SRC) -DIS_AM572x -o $(EXECUTABLE)
else ifeq ($(IS_AM572x),0)
	@echo AM33xx chip detected
	$(CC) $(DEFAULT_COMMON_FLAGS) $(SRC) -o $(EXECUTABLE)
else
	@echo Not Recognized HW
endif

run: $(EXECUTABLE) all 
	./$<	# This will give error if you have not compiled

debug: all $(EXECUTABLE)
	gdb $^	# This will execute all: first then run the debugger

clean: $(EXECUTABLE)
	rm $(EXECUTABLE)
