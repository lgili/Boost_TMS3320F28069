################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./F2806x_CodeStartBranch.obj" \
"./Includes/F2806x_usDelay.obj" \
"./Source/0_Main.obj" \
"./Source/1_GPIO.obj" \
"./Source/2_ADC.obj" \
"./Source/3_PWM.obj" \
"./Source/5_ISR.obj" \
"./Source/DevInit.obj" \
"./Source/F2806x_DefaultIsr.obj" \
"./Source/F2806x_GlobalVariableDefs.obj" \
"./Source/F2806x_PieVect.obj" \
"../F2806x_FLASH_ContinuousADC.CMD" \
"C:/ti/controlSUITE/device_support/f2806x/v100/F2806x_headers/cmd/F2806x_Headers_nonBIOS.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Includes/subdir_vars.mk
-include Source/subdir_vars.mk
-include subdir_rules.mk
-include Includes/subdir_rules.mk
-include Source/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Boost.out \

EXE_OUTPUTS__QUOTED += \
"Boost.out" \

BIN_OUTPUTS += \
Boost.hex \

BIN_OUTPUTS__QUOTED += \
"Boost.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(CMD_UPPER_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "Boost.out"

# Tool invocations
Boost.out: $(OBJS) $(CMD_SRCS) $(CMD_UPPER_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -O2 --advice:performance=all --define=_INLINE --define=LARGE_MODEL --define=FLASH --define=_DEBUG --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi -z -m"Boost.map" --stack_size=0x300 --warn_sections -i"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/lib" -i"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="Boost_linkInfo.xml" --rom_model -o "Boost.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

Boost.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: C2000 Hex Utility'
	"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/hex2000"  -o "Boost.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "F2806x_CodeStartBranch.obj" "Includes\F2806x_usDelay.obj" "Source\0_Main.obj" "Source\1_GPIO.obj" "Source\2_ADC.obj" "Source\3_PWM.obj" "Source\5_ISR.obj" "Source\DevInit.obj" "Source\F2806x_DefaultIsr.obj" "Source\F2806x_GlobalVariableDefs.obj" "Source\F2806x_PieVect.obj" 
	-$(RM) "Source\0_Main.d" "Source\1_GPIO.d" "Source\2_ADC.d" "Source\3_PWM.d" "Source\5_ISR.d" "Source\DevInit.d" "Source\F2806x_DefaultIsr.d" "Source\F2806x_GlobalVariableDefs.d" "Source\F2806x_PieVect.d" 
	-$(RM) "F2806x_CodeStartBranch.d" "Includes\F2806x_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

