################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
EEPROM_I2C.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: EEPROM_I2C.elf secondary-outputs

# Tool invocations
EEPROM_I2C.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,EEPROM_I2C.map -mmcu=atmega16 -o "EEPROM_I2C.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

EEPROM_I2C.lss: EEPROM_I2C.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S EEPROM_I2C.elf  >"EEPROM_I2C.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: EEPROM_I2C.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 EEPROM_I2C.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) EEPROM_I2C.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
