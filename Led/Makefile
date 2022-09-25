
build_path			:= Build

device     			:= atmega2560
f_cpu				:= 16000000UL

port				:= /dev/ttyUSB0
baudrata			:= 19200
program_type		:= stk500v2

cflags 				= -g -w -Wall -Os -mmcu=$(device) -DF_CPU=$(f_cpu)
cflags 				+= -Wl,-u,vfprintf -lprintf_flt

gcc_compile    		:= $(compile_path)avr-gcc
size_compile    	:= $(compile_path)avr-size
obj_copy_compile   	:= $(compile_path)avr-objcopy
avrdude_compile		:= $(compile_path)avrdude

target 	= led

c_sources = \
Use/use.c \
Drivers/Src/serial.c \
Drivers/Src/main.c

h_sources = \
-IDrivers/Inc \
-IUse

all: clean $(build_path)/$(target).elf $(build_path)/$(target).hex size

objects	= $(addprefix $(build_path)/,$(notdir $(c_sources:.c=.o)))
vpath %.c $(sort $(dir $(c_sources)))

$(build_path)/%.o: %.c
	$(gcc_compile) $(cflags) $(h_sources) -c $< -o $@

$(build_path)/$(target).hex: $(build_path)/$(target).elf
	$(obj_copy_compile) -O ihex -R .eeprom $< $@

$(build_path)/$(target).elf: $(objects)
	$(gcc_compile) $(cflags) $(objects) -o $@

size:
	$(size_compile) -A $(build_path)/$(target).elf
	$(size_compile) -A $(build_path)/$(target).hex

push:
	$(avrdude_compile) -F -v -p $(device) -b $(baudrata) -c $(program_type) -P $(port) -D -U flash:w:$(build_path)/$(target).hex:i

clean:
	rm -f $(build_path)/*


