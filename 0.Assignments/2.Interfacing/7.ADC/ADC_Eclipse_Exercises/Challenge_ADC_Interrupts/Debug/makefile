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
Challenge_ADC_Interrupts.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Challenge_ADC_Interrupts.elf secondary-outputs

# Tool invocations
Challenge_ADC_Interrupts.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Challenge_ADC_Interrupts.map -mmcu=atmega16 -o "Challenge_ADC_Interrupts.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Challenge_ADC_Interrupts.lss: Challenge_ADC_Interrupts.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Challenge_ADC_Interrupts.elf  >"Challenge_ADC_Interrupts.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Challenge_ADC_Interrupts.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Challenge_ADC_Interrupts.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Challenge_ADC_Interrupts.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
