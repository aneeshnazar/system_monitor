NAME = ft_gkrellm
CC := clang++
CFLAGS	+= -Wall -Wextra -Werror
SFILES = DateTimeModule.Class.cpp \
GraphicMonitor.Class.cpp \
IMonitorDisplay.Class.cpp \
IMonitorModule.Class.cpp \
NameModule.Class.cpp \
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
	@$(CC) $(CFLAGS) -I $(INC) -o $@ $(OBJ)

$(OBJ): | $(ODIR)

$(ODIR):
	@mkdir $(ODIR)

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all