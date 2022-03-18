################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-c2000_20.8.0.STS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./F2806x_CodeStartBranch.obj" \
"./F2806x_DefaultIsr.obj" \
"./F2806x_GlobalVariableDefs.obj" \
"./F2806x_PieCtrl.obj" \
"./F2806x_PieVect.obj" \
"./F2806x_Sci.obj" \
"./F2806x_SysCtrl.obj" \
"./F2806x_usDelay.obj" \
"./freemaster_mod/freemaster_Kxx.obj" \
"./freemaster_mod/freemaster_appcmd.obj" \
"./freemaster_mod/freemaster_bdm.obj" \
"./freemaster_mod/freemaster_can.obj" \
"./freemaster_mod/freemaster_lin.obj" \
"./freemaster_mod/freemaster_pipes.obj" \
"./freemaster_mod/freemaster_protocol.obj" \
"./freemaster_mod/freemaster_rec.obj" \
"./freemaster_mod/freemaster_scope.obj" \
"./freemaster_mod/freemaster_serial.obj" \
"./freemaster_mod/freemaster_sfio.obj" \
"./freemaster_mod/freemaster_tsa.obj" \
"./freemaster_mod/interrupt.obj" \
"./freemaster_mod/uart.obj" \
"./src/1_GPIO.obj" \
"./src/2_ADC.obj" \
"./src/3_PWM.obj" \
"./src/5_ISR.obj" \
"./src/DevInit.obj" \
"./src/main.obj" \
"C:/ti/C2000Ware_3_02_00_00_Software/device_support/f2806x/common/cmd/F28069.cmd" \
"C:/ti/C2000Ware_3_02_00_00_Software/device_support/f2806x/headers/cmd/F2806x_Headers_nonBIOS.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include cmd/subdir_vars.mk
-include freemaster_mod/subdir_vars.mk
-include src/subdir_vars.mk
-include subdir_rules.mk
-include cmd/subdir_rules.mk
-include freemaster_mod/subdir_rules.mk
-include src/subdir_rules.mk
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
SCI_BOOST_28069.out \

EXE_OUTPUTS__QUOTED += \
"SCI_BOOST_28069.out" \

BIN_OUTPUTS += \
SCI_BOOST_28069.hex \

BIN_OUTPUTS__QUOTED += \
"SCI_BOOST_28069.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(CMD_UPPER_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "SCI_BOOST_28069.out"

# Tool invocations
SCI_BOOST_28069.out: $(OBJS) $(CMD_SRCS) $(CMD_UPPER_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-c2000_20.8.0.STS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -O2 --advice:performance=all --define=_INLINE --define=LARGE_MODEL --define=_DEBUG --define=FLASH --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi -z -m"SCI_BOOST_28069.map" --stack_size=0x300 --warn_sections -i"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-c2000_20.8.0.STS/lib" -i"C:/Users/lgili/SCI_BOOST_28069/cmd" -i"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-c2000_20.8.0.STS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="SCI_BOOST_28069_linkInfo.xml" --rom_model -o "SCI_BOOST_28069.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

SCI_BOOST_28069.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: C2000 Hex Utility'
	"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-c2000_20.8.0.STS/bin/hex2000"  -o "SCI_BOOST_28069.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "F2806x_CodeStartBranch.obj" "F2806x_DefaultIsr.obj" "F2806x_GlobalVariableDefs.obj" "F2806x_PieCtrl.obj" "F2806x_PieVect.obj" "F2806x_Sci.obj" "F2806x_SysCtrl.obj" "F2806x_usDelay.obj" "freemaster_mod\freemaster_Kxx.obj" "freemaster_mod\freemaster_appcmd.obj" "freemaster_mod\freemaster_bdm.obj" "freemaster_mod\freemaster_can.obj" "freemaster_mod\freemaster_lin.obj" "freemaster_mod\freemaster_pipes.obj" "freemaster_mod\freemaster_protocol.obj" "freemaster_mod\freemaster_rec.obj" "freemaster_mod\freemaster_scope.obj" "freemaster_mod\freemaster_serial.obj" "freemaster_mod\freemaster_sfio.obj" "freemaster_mod\freemaster_tsa.obj" "freemaster_mod\interrupt.obj" "freemaster_mod\uart.obj" "src\1_GPIO.obj" "src\2_ADC.obj" "src\3_PWM.obj" "src\5_ISR.obj" "src\DevInit.obj" "src\main.obj" 
	-$(RM) "F2806x_DefaultIsr.d" "F2806x_GlobalVariableDefs.d" "F2806x_PieCtrl.d" "F2806x_PieVect.d" "F2806x_Sci.d" "F2806x_SysCtrl.d" "freemaster_mod\freemaster_Kxx.d" "freemaster_mod\freemaster_appcmd.d" "freemaster_mod\freemaster_bdm.d" "freemaster_mod\freemaster_can.d" "freemaster_mod\freemaster_lin.d" "freemaster_mod\freemaster_pipes.d" "freemaster_mod\freemaster_protocol.d" "freemaster_mod\freemaster_rec.d" "freemaster_mod\freemaster_scope.d" "freemaster_mod\freemaster_serial.d" "freemaster_mod\freemaster_sfio.d" "freemaster_mod\freemaster_tsa.d" "freemaster_mod\interrupt.d" "freemaster_mod\uart.d" "src\1_GPIO.d" "src\2_ADC.d" "src\3_PWM.d" "src\5_ISR.d" "src\DevInit.d" "src\main.d" 
	-$(RM) "F2806x_CodeStartBranch.d" "F2806x_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

