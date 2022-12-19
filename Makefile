NAME = firefly_sim

CC = gcc
CFLAGS = -I includes

SRC_DIR = src

SRC := $(SRC_DIR)/main.c

SRC += $(SRC_DIR)/board.c
SRC += $(SRC_DIR)/firefly.c
SRC += $(SRC_DIR)/firefly_utils.c
SRC += $(SRC_DIR)/simulation.c
SRC += $(SRC_DIR)/population.c
SRC += $(SRC_DIR)/meadow.c
SRC += $(SRC_DIR)/meadow_display.c
SRC += $(SRC_DIR)/neighbours.c
SRC += $(SRC_DIR)/neighbours_compute.c

# Build
BUILD_DIR = build
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

# Deps
DEPS := $(SRC:%.c=$(BUILD_DIR)/%.d)

# Colors
ifneq ($(shell tput colors),0)
    C_BOLD=\e[1m
    C_RESET=\033[00m
    C_BLUE=\e[34m
    C_RED=\e[31m
    C_CYAN=\e[36m
endif

ECHO  = /bin/echo -e

# Output
ASK = @ $(ECHO) "$(C_BOLD)$(C_BLUE)?$(C_RESET)"
OK = @ $(ECHO) "$(C_BOLD)[$(C_BLUE)OK$(C_RESET)$(C_BOLD)]$(C_RESET)"
KO = @ $(ECHO) "$(C_BOLD)[$(C_RED)KO$(C_RESET)$(C_BOLD)]$(C_RESET)"
NTD = @ $(ECHO) "$(C_BOLD)Nothing to do.$(C_RESET)"

# Errors
DIE = exit 1

all: $(NAME)
	$(NTD)

# Check
%.c:
	$(KO) "Missing file: $@" && $(DIE)

%:
	$(KO) "Unknown directive $@" && $(DIE)

$(BUILD_DIR)/%.d: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $(DFLAGS) -MM -MT $(@:.d=.o) $< -MF $@

-include $(DEPS)

# Link
$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ || $(DIE)
	$(OK) "$(CC) $(C_CYAN)    $<$(C_RESET)"

# Exec
$(NAME): $(DEPS) $(OBJ)
	$(CC) $(DFLAGS) -o $(NAME) $(OBJ) $(CFLAGS) || $(DIE)
	$(OK) "Compiled $(C_BLUE)$(shell echo "$?" | wc -w)$(C_RESET) file(s)"

v: CFLAGS += -g

v: re
	$(ASK) "program arguments"
	@ read ARG; valgrind --track-origins=yes --leak-check=full -s \
 		./$(NAME) $${ARG} 2> "logs/trace_$(shell date +%s)_.log"
	$(NTD)

.PHONY: v

# Clean
clean:
	@ rm -rf $(BUILD_DIR)
	$(OK) "Deleted $(C_BLUE)$(BUILD_DIR)$(C_RESET)"
	@ rm -f *.log
	$(OK) "Deleted $(C_BLUE)*.log$(C_RESET)"
	@ rm -rf $(COV_DIR)
	$(OK) "Deleted $(C_BLUE)$(COV_DIR)$(C_RESET)"

fclean: clean
	@ rm -f "$(NAME)"
	@ rm -f "$(TESTS_EXEC)"
	$(OK) "Deleted executable(s)"


re: fclean all

.PHONY: fclean re
