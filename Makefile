START_TIME := $(shell date +%s%3N)
BUILD_DIR := .build

NAME := firefly_sim
NAME_DEBUG := debug
NAME_ASAN := asan

# ↓ Sources

VPATH := src
SRC += main.c
SRC += board.c
SRC += firefly.c
SRC += gif.c
SRC += meadow.c
SRC += neighbours.c
SRC += neighbours_compute.c
SRC += population.c
SRC += simulation.c

VPATH += gifenc
SRC += gifenc.c

# ↓ Debug only sources

DSRC := $(SRC)

# ↓ Config
CC := gcc

CFLAGS := -W -Wall -Wextra
CFLAGS := -O2 -march=native
CFLAGS += -U_FORTIFY_SOURCE

CFLAGS += -iquote ./include
CFLAGS += -iquote ./gifenc

# ↓ Recipes
OBJ := $(SRC:%.c=$(BUILD_DIR)/release/%.o)
OBJ_DEBUG := $(DSRC:%.c=$(BUILD_DIR)/debug/%.o)
OBJ_ASAN := $(DSRC:%.c=$(BUILD_DIR)/asan/%.o)

DEPFLAGS := -MMD -MP

DEPS := $(OBJ:.o=.d)
DEPS_DEBUG := $(OBJ_DEBUG:.o=.d)
DEPS_ASAN := $(OBJ_ASAN:.o=.d)

NAMES += $(NAME)
NAMES += $(NAME_DEBUG)
NAMES += $(NAME_ASAN)

OBJS += $(OBJ)
OBJS += $(OBJ_DEBUG)
OBJS += $(OBJ_ASAN)

# ↓ clean & fclean helpers
CLEAN := $(OBJS)
FCLEAN := $(NAMES) $(BUILD_DIR)

ifeq ($(FORCE_DEBUG),1)
    CFLAGS += -D DEBUG_MODE
endif

# ↓ `touch .fast` to force multi-threading
ifneq ($(shell find . -name ".fast"),)
    MAKEFLAGS += -j
endif

# ↓ Quiet
V ?=
ifeq ($(V), 1)
    $(info Verbose mode enabled)
    Q :=
else
    Q := @
endif

CMD_NOT_FOUND = $(error $(strip $(1)) is required for this rule)
CHECK_CMD = $(if $(shell command -v $(1)),, $(call CMD_NOT_FOUND, $(1)))

# ↓ Utils
ifneq ($(shell tput colors),0)
    C_RESET := \033[00m
    C_BOLD := \e[1m
    C_RED := \e[31m
    C_GREEN := \e[32m
    C_YELLOW := \e[33m
    C_BLUE := \e[34m
    C_PURPLE := \e[35m
    C_CYAN := \e[36m
endif

_SOLVE_COLORS = $(subst :r,$(C_RED), \
    $(subst :c,$(C_CYAN),            \
    $(subst :p,$(C_PURPLE),          \
    $(subst :y,$(C_YELLOW),          \
    $(subst :b,$(C_BLUE),            \
    $(subst :g,$(C_GREEN),           \
    $(subst *,$(C_BOLD),             \
    $(subst ~,$(C_RESET),            \
    $(addprefix $(call _UNQUOTE,$(1)),~))))))))) # Do you like lisp?

## ↓ Hack to make highlighter happy
_UNQUOTE = $(subst ",,$(subst ',,$(1)))##")
_QUOTE = "$(strip $(1))"

COLORIZE = $(call _QUOTE, $(call _SOLVE_COLORS, $(1)))

CURRENT_TIME_MS = $(shell date +%s%3N)
TIME = $(shell expr $(call CURRENT_TIME_MS) - $(START_TIME))

HEADER := ":p"
LOG = @ echo -e $(call COLORIZE,$(2) ~$(TIME_BOX) $(HEADER)~ $(1)~)
TIME_BOX = "[ :b"$(call TIME)"~\t]"

ifneq ($(shell find . -name override.mk),)
    HOOK_BEFORE := 1
    -include override.mk
	undefine HOOK_BEFORE
endif

all: $(NAME)

.PHONY: all

$(NAME): HEADER += "release"
$(NAME): $(OBJ)
	$Q $(CC) $(CFLAGS) $(LIBFLAGS) $(LDLIBS) -o $@ $^
	$(call LOG,":g$@")

$(BUILD_DIR)/release/%.o: %.c
	@ mkdir -p $(dir $@)
	$Q $(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
	$(call LOG, ":c" $(notdir $@))

$(NAME_DEBUG): CFLAGS += -g3 -D DEBUG_MODE
$(NAME_DEBUG): HEADER += "debug"
$(NAME_DEBUG): $(OBJ_DEBUG)
	$Q $(CC) $(CFLAGS) $(LIBFLAGS) $(LDLIBS) -o $@ $^
	$(call LOG,":g$@")

$(BUILD_DIR)/asan/%.o: %.c
	@ mkdir -p $(dir $@)
	$Q $(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
	$(call LOG, ":c" $(notdir $@))

$(NAME_ASAN): CFLAGS += -g3 -D DEBUG_MODE
$(NAME_ASAN): CFLAGS += -fsanitize=address,leak,undefined
$(NAME_ASAN): HEADER += "asan"
$(NAME_ASAN): $(OBJ_ASAN)
	$Q $(CC) $(CFLAGS) $(LIBFLAGS) $(LDLIBS) -o $@ $^
	$(call LOG,":g$@")

$(BUILD_DIR)/debug/%.o: %.c
	@ mkdir -p $(dir $@)
	$Q $(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
	$(call LOG, ":c" $(notdir $@))

clean:
	$(call _FIND_LOG, $(CLEAN))

	$Q $(RM) $(CLEAN)
	$Q $(RM) -f vgcore.*

fclean:
	$(call _FIND_LOG, $(FCLEAN))

	$Q $(RM) -f vgcore.*
	$Q $(RM) -r $(FCLEAN)

_FIND_LOG = $(if                                             \
	$(shell find $(1) 2> /dev/null),                         \
	$(call LOG,"Removed:r" $(shell find $(1) 2> /dev/null)), \
)

re:	fclean
	@ make -sC . all

%:
	$(call SENTINEL, $@)

%.c:
	$(call SENTINEL, $@)

-include $(DEPS)
-include $(DEPS_DEBUG)
-include $(DEPS_ASAN)

ifneq ($(shell find . -name override.mk),)
    HOOK_AFTER := 1
    -include override.mk
	undefine HOOK_AFTER
endif
