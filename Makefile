NAME = ft_gkrellm
CC := clang++
CFLAGS	+= -Wall -Wextra -Werror
SFILES = 	CPUModule.Class.cpp \
			RAMModule.Class.cpp \
			DateTimeModule.Class.cpp \
			GraphicMonitor.Class.cpp \
			IMonitorDisplay.Class.cpp \
			IMonitorModule.Class.cpp \
			NameModule.Class.cpp \
			NetThruModule.Class.cpp \
			OSInfoModule.Class.cpp \
			TermMonitor.Class.cpp \
			main.cpp

ODIR = obj
SDIR = src
SRC = $(addprefix $(SDIR)/,$(SFILES))
OBJ = $(addprefix $(ODIR)/,$(SFILES:.cpp=.o))
#INC = includes/
LFLAG = -lncurses -framework sfml-graphics -framework sfml-window -framework sfml-system -F SFML/Frameworks
INC = -I ./SFML/include
SFML = DYLD_FRAMEWORK_PATH="$(PWD)/SFML/Frameworks"

$(ODIR)/%.o: $(SDIR)/%.cpp
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) -o $@ $(OBJ) $(LFLAG)

$(OBJ): | $(ODIR)

$(ODIR):
	@mkdir $(ODIR)

sfml:
	@echo export $(SFML)

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
