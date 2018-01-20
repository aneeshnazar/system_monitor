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
INC = includes/

$(ODIR)/%.o: $(SDIR)/%.cpp
	@$(CC) $(CFLAGS) -I $(INC) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC) -o $@ $(OBJ) -lncurses

$(OBJ): | $(ODIR)

$(ODIR):
	@mkdir $(ODIR)

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
