################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
freemaster_mod/%.obj: ../freemaster_mod/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-c2000_20.8.0.STS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -O2 --include_path="C:/Users/lgili/SCI_BOOST_28069" --include_path="C:/Users/lgili/SCI_BOOST_28069/cmd" --include_path="C:/ti/C2000Ware_3_02_00_00_Software/device_support/f2806x/MWare/inc" --include_path="C:/ti/C2000Ware_3_02_00_00_Software/device_support/f2806x/MWare/driverlib" --include_path="C:/ti/C2000Ware_3_02_00_00_Software/device_support/f2806x/common/include" --include_path="C:/ti/C2000Ware_3_02_00_00_Software/device_support/f2806x/headers/include" --include_path="C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-c2000_20.8.0.STS/include" --advice:performance=all --define=_INLINE --define=LARGE_MODEL --define=_DEBUG --define=FLASH --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="freemaster_mod/$(basename $(<F)).d_raw" --obj_directory="freemaster_mod" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


