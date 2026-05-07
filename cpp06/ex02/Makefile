CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = ex02

SRCDIR = src
INCDIR = inc
OBJDIR = obj

SRC = main.cpp  Base.cpp Class.cpp
SRCS = $(addprefix $(SRCDIR)/,$(SRC))
OBJS = $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
