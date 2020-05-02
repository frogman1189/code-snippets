#MakeFile
VPATH = src:bin/obj
CC = g++

CCFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual \
-Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self \
-Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept \
-Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow \
-Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 \
-Wswitch-default -Wundef -Werror -Wno-unused

LIBFLAGS = -lncurses

#Preprocessor Flags
PPFLAGS = -D NCURSES

FLAGS = $(CCFLAGS) $(LIBFLAGS) $(PPFLAGS)
SRCDIR = src
OBJDIR := bin/obj
EXEDIR := bin/exe
OBJS := $(addprefix $(OBJDIR)/,main.o input.o renderable.o test_class.o)

# Compile engine | Requires objects and exedir to exist
exe : $(OBJS) | $(EXEDIR)
	$(CC) $(OBJS) $(FLAGS) -o $(EXEDIR)/main
	$(EXEDIR)/main

# Compile all objects
all: $(OBJS)

# Compile objects | Requires cpp files and objdir to exist
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(FLAGS) -c $< -o $@

# Create exedir if doesn't exist
$(EXEDIR):
	mkdir $(EXEDIR)

# Some how required for the make objdir rule
$(OBJS): | $(OBJDIR)

#make objdir
$(OBJDIR):
	mkdir $(OBJDIR)

#clean
.PHONY : clean
clean : $(OBJS)
	-rm bin/obj/*.o
