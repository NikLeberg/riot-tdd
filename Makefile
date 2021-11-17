# Name of your application
APPLICATION = tdd

# If no BOARD is found in the environment, use this default:
BOARD ?= native

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= /data/riotbuild/RIOT

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
DEVELHELP ?= 1

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

# Modules to include:
USEMODULE += shell
USEMODULE += shell_commands
USEMODULE += ps
# include and auto-initialize all available sensors
USEMODULE += saul_default

# Our own packages:
EXTERNAL_PKG_DIRS += pkg
USEPKG += uKal

# Our own modules:
EXTERNAL_MODULE_DIRS += src
USEMODULE += eekf
USEMODULE += hello_module

# Start the RIOT buildprocess
include $(RIOTBASE)/Makefile.include

# Create disassembly of elf file
LISTFILE = $(ELFFILE:.elf=.list)

$(LISTFILE): $(ELFFILE)
	$(call check_cmd,$(OBJDUMP),Objdump program)
	$(info Generating disassembly listing...)
	$(Q)$(OBJDUMP) $(OBJDUMPFLAGS) $(ELFFILE) > $(LISTFILE)

disassemble: $(LISTFILE)
	$(info Disassembly listing created: $(LISTFILE))

# Provide easy target for module / package generation
gen-%:
	riotgen $(@:gen-%=%) -r $(PWD) -i
	