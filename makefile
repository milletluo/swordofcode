CC = gcc
XX = g++
CFLAGS = -W -O0 -fPIC
TARGET = ./run_test
#放置头文件路径
HEADERS =  -I ./ \
			-I ../ \
			-I ./include \

#放置源文件路径
USER_DIR =  ./ \
			./testsrc

#放置库文件路径
LIB_PATH =  -L ./   \
			-L ../ \
			-L ./lib

#link lib.a file
LIBS = -lpthread \
	-lgtest\

INCLUDE := $(HEADERS)

FILES = $(foreach d, $(USER_DIR), $(wildcard $(d)/*.cpp))
OBJS = $(patsubst %.cpp, %.o, $(FILES))

$(TARGET) : $(OBJS)
	$(XX)  $^ -o $@  $(LIB_PATH) $(LIBS)

%.o : %.cpp
	$(XX) $(CFLAGS) $(HEADERS) -c  $^  -g -o  $@  -DLinux

.PHONY:clean
clean :
	rm -rf $(TARGET)
	rm -rf $(OBJS)
