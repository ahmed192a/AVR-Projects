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
Exercise2_Measure_Signal_Period.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Exercise2_Measure_Signal_Period.elf secondary-outputs

# Tool invocations
Exercise2_Measure_Signal_Period.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Exercise2_Measure_Signal_Period.map -mmcu=atmega16 -o "Exercise2_Measure_Signal_Period.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Exercise2_Measure_Signal_Period.lss: Exercise2_Measure_Signal_Period.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Exercise2_Measure_Signal_Period.elf  >"Exercise2_Measure_Signal_Period.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Exercise2_Measure_Signal_Period.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Exercise2_Measure_Signal_Period.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Exercise2_Measure_Signal_Period.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
