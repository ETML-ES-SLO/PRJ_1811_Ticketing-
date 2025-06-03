#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/1811_Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/1811_Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/system_config/default/framework/driver/spi/static/src/drv_spi_static.c ../src/system_config/default/framework/driver/spi/static/src/drv_spi_mapping.c ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_tasks.c ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_sys_queue.c ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_ebm_tasks.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c ../src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c ../src/system_config/default/framework/driver/usart/src/drv_usart_static.c ../src/system_config/default/framework/driver/usart/src/drv_usart_static_byte_model.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/app.c ../src/main.c ../src/DriverLCD.c ../src/glcdfont.c ../src/Mc32Delays.c ../src/Gest_Menu.c ../src/GesFifoTh32.c ../src/Gest_TFT.c ../src/Mc32gest_RS232.c ../src/app_SDCard.c ../src/RF.c ../src/Gest_USB.c ../../../../../../framework/driver/sdcard/src/dynamic/drv_sdcard.c ../../../../../../framework/system/fs/src/dynamic/sys_fs.c ../../../../../../framework/system/fs/src/dynamic/sys_fs_media_manager.c ../../../../../../framework/system/fs/fat_fs/src/file_system/ff.c ../../../../../../framework/system/fs/fat_fs/src/hardware_access/diskio.c ../../../../../../framework/system/int/src/sys_int_pic32.c ../../../../../../framework/system/tmr/src/sys_tmr.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/715571337/drv_spi_static.o ${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o ${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o ${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o ${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o ${OBJECTDIR}/_ext/327000265/drv_usart_static.o ${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/DriverLCD.o ${OBJECTDIR}/_ext/1360937237/glcdfont.o ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o ${OBJECTDIR}/_ext/1360937237/Gest_Menu.o ${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o ${OBJECTDIR}/_ext/1360937237/Gest_TFT.o ${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o ${OBJECTDIR}/_ext/1360937237/app_SDCard.o ${OBJECTDIR}/_ext/1360937237/RF.o ${OBJECTDIR}/_ext/1360937237/Gest_USB.o ${OBJECTDIR}/_ext/1856604796/drv_sdcard.o ${OBJECTDIR}/_ext/1189039745/sys_fs.o ${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o ${OBJECTDIR}/_ext/2143635134/ff.o ${OBJECTDIR}/_ext/598511097/diskio.o ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o ${OBJECTDIR}/_ext/430974239/sys_tmr.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/715571337/drv_spi_static.o.d ${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o.d ${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o.d ${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o.d ${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o.d ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o.d ${OBJECTDIR}/_ext/327000265/drv_usart_static.o.d ${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o.d ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d ${OBJECTDIR}/_ext/1688732426/system_init.o.d ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/DriverLCD.o.d ${OBJECTDIR}/_ext/1360937237/glcdfont.o.d ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o.d ${OBJECTDIR}/_ext/1360937237/Gest_Menu.o.d ${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o.d ${OBJECTDIR}/_ext/1360937237/Gest_TFT.o.d ${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o.d ${OBJECTDIR}/_ext/1360937237/app_SDCard.o.d ${OBJECTDIR}/_ext/1360937237/RF.o.d ${OBJECTDIR}/_ext/1360937237/Gest_USB.o.d ${OBJECTDIR}/_ext/1856604796/drv_sdcard.o.d ${OBJECTDIR}/_ext/1189039745/sys_fs.o.d ${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o.d ${OBJECTDIR}/_ext/2143635134/ff.o.d ${OBJECTDIR}/_ext/598511097/diskio.o.d ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d ${OBJECTDIR}/_ext/430974239/sys_tmr.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/715571337/drv_spi_static.o ${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o ${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o ${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o ${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o ${OBJECTDIR}/_ext/327000265/drv_usart_static.o ${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/DriverLCD.o ${OBJECTDIR}/_ext/1360937237/glcdfont.o ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o ${OBJECTDIR}/_ext/1360937237/Gest_Menu.o ${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o ${OBJECTDIR}/_ext/1360937237/Gest_TFT.o ${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o ${OBJECTDIR}/_ext/1360937237/app_SDCard.o ${OBJECTDIR}/_ext/1360937237/RF.o ${OBJECTDIR}/_ext/1360937237/Gest_USB.o ${OBJECTDIR}/_ext/1856604796/drv_sdcard.o ${OBJECTDIR}/_ext/1189039745/sys_fs.o ${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o ${OBJECTDIR}/_ext/2143635134/ff.o ${OBJECTDIR}/_ext/598511097/diskio.o ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o ${OBJECTDIR}/_ext/430974239/sys_tmr.o

# Source Files
SOURCEFILES=../src/system_config/default/framework/driver/spi/static/src/drv_spi_static.c ../src/system_config/default/framework/driver/spi/static/src/drv_spi_mapping.c ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_tasks.c ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_sys_queue.c ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_ebm_tasks.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c ../src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c ../src/system_config/default/framework/driver/usart/src/drv_usart_static.c ../src/system_config/default/framework/driver/usart/src/drv_usart_static_byte_model.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/app.c ../src/main.c ../src/DriverLCD.c ../src/glcdfont.c ../src/Mc32Delays.c ../src/Gest_Menu.c ../src/GesFifoTh32.c ../src/Gest_TFT.c ../src/Mc32gest_RS232.c ../src/app_SDCard.c ../src/RF.c ../src/Gest_USB.c ../../../../../../framework/driver/sdcard/src/dynamic/drv_sdcard.c ../../../../../../framework/system/fs/src/dynamic/sys_fs.c ../../../../../../framework/system/fs/src/dynamic/sys_fs_media_manager.c ../../../../../../framework/system/fs/fat_fs/src/file_system/ff.c ../../../../../../framework/system/fs/fat_fs/src/hardware_access/diskio.c ../../../../../../framework/system/int/src/sys_int_pic32.c ../../../../../../framework/system/tmr/src/sys_tmr.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/1811_Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX170F256D
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/715571337/drv_spi_static.o: ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static.c  .generated_files/flags/default/f0d5b72d29f697407b0ed20c5c528441892c784a .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/715571337" 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/715571337/drv_spi_static.o.d" -o ${OBJECTDIR}/_ext/715571337/drv_spi_static.o ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o: ../src/system_config/default/framework/driver/spi/static/src/drv_spi_mapping.c  .generated_files/flags/default/747055195d551619f78859cb000b38cfabcd96f7 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/715571337" 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o.d" -o ${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o ../src/system_config/default/framework/driver/spi/static/src/drv_spi_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o: ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_tasks.c  .generated_files/flags/default/1f7ab62bb7b8d0eaa65c8e5ea91588d77946efc5 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/715571337" 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o.d" -o ${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o: ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_sys_queue.c  .generated_files/flags/default/39d701424f929c16ce0177f3cf04407b5fb59776 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/715571337" 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o.d" -o ${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_sys_queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o: ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_ebm_tasks.c  .generated_files/flags/default/be69b5ba613087bf82834224e40fadf780ca76a8 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/715571337" 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o.d" -o ${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_ebm_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c  .generated_files/flags/default/49bbd90de0d4b65adc8771e49a3df07c670c5c56 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c  .generated_files/flags/default/23e703aebe5ca457314aa53b5f9d4aae6e71682c .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o: ../src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c  .generated_files/flags/default/e873dc2e2ee72ad096d207bbe05b2e21b4bccba0 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/327000265" 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o.d" -o ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o ../src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/327000265/drv_usart_static.o: ../src/system_config/default/framework/driver/usart/src/drv_usart_static.c  .generated_files/flags/default/742e515ac5ca0956ab9d7939840115e1aa038fda .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/327000265" 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/327000265/drv_usart_static.o.d" -o ${OBJECTDIR}/_ext/327000265/drv_usart_static.o ../src/system_config/default/framework/driver/usart/src/drv_usart_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o: ../src/system_config/default/framework/driver/usart/src/drv_usart_static_byte_model.c  .generated_files/flags/default/5da53b2b32c558630197f9ca0891d85b25a7bbd2 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/327000265" 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o.d 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o.d" -o ${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o ../src/system_config/default/framework/driver/usart/src/drv_usart_static_byte_model.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c  .generated_files/flags/default/1675c589ef638a418cf9399d30f0d85a1e6308c7 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  .generated_files/flags/default/c88f2830542bd8ace52668caaa2bc1cf74258b38 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c  .generated_files/flags/default/d3a0a2f32d9b63b3f6b8ab60cd2d390af99aa81d .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  .generated_files/flags/default/1abf8b5a5016f3ec3d4d40d864e625ede57c28ce .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  .generated_files/flags/default/d80e21f9743b1ffccc8f19094238bebc1ea87679 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  .generated_files/flags/default/3a4a165df207889b0d767aea6cfd4e41bfd4bd58 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  .generated_files/flags/default/79a2f828c3f289ef47c5eaa4027c262f883c1480 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  .generated_files/flags/default/c2ffbf9c55ed1cae1522926ce03562c6185904ea .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/760f0ee4519792d8465d9f8846db8692cb737a0e .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/935f3435631bbec7ea1ab4ca1f940507e30e856 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/DriverLCD.o: ../src/DriverLCD.c  .generated_files/flags/default/c91bb764f5f6d6cf0bd6555d5a96d4c187803ec .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DriverLCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DriverLCD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/DriverLCD.o.d" -o ${OBJECTDIR}/_ext/1360937237/DriverLCD.o ../src/DriverLCD.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/glcdfont.o: ../src/glcdfont.c  .generated_files/flags/default/9c92815a0c19ddb761adce3c02f57c8dbd022e0f .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/glcdfont.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/glcdfont.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/glcdfont.o.d" -o ${OBJECTDIR}/_ext/1360937237/glcdfont.o ../src/glcdfont.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32Delays.o: ../src/Mc32Delays.c  .generated_files/flags/default/a7ed861aa666451006e3cb21ea101cebdf2141aa .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32Delays.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o ../src/Mc32Delays.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Gest_Menu.o: ../src/Gest_Menu.c  .generated_files/flags/default/4a2eb81d32623c33e17b7c6c67a11727cf5cd00f .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Gest_Menu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Gest_Menu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Gest_Menu.o.d" -o ${OBJECTDIR}/_ext/1360937237/Gest_Menu.o ../src/Gest_Menu.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o: ../src/GesFifoTh32.c  .generated_files/flags/default/d3827fcda7a740585ee20b04d88156003f865a44 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o.d" -o ${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o ../src/GesFifoTh32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Gest_TFT.o: ../src/Gest_TFT.c  .generated_files/flags/default/59eba4722f811c174c897bcd02192b958b4ce450 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Gest_TFT.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Gest_TFT.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Gest_TFT.o.d" -o ${OBJECTDIR}/_ext/1360937237/Gest_TFT.o ../src/Gest_TFT.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o: ../src/Mc32gest_RS232.c  .generated_files/flags/default/24d3c9926b5db697e59ff14f42fe635c83787182 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o ../src/Mc32gest_RS232.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app_SDCard.o: ../src/app_SDCard.c  .generated_files/flags/default/d12b8b321a8a90877540b917b85b93d604ee2de0 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_SDCard.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_SDCard.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app_SDCard.o.d" -o ${OBJECTDIR}/_ext/1360937237/app_SDCard.o ../src/app_SDCard.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/RF.o: ../src/RF.c  .generated_files/flags/default/1b27bfd41a877d4e0cb137d950e9b8c3f623999a .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RF.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RF.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/RF.o.d" -o ${OBJECTDIR}/_ext/1360937237/RF.o ../src/RF.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Gest_USB.o: ../src/Gest_USB.c  .generated_files/flags/default/b6943cb57a1afd913663f08d294209c5eef411fe .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Gest_USB.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Gest_USB.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Gest_USB.o.d" -o ${OBJECTDIR}/_ext/1360937237/Gest_USB.o ../src/Gest_USB.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1856604796/drv_sdcard.o: ../../../../../../framework/driver/sdcard/src/dynamic/drv_sdcard.c  .generated_files/flags/default/aab0f7beed63bb288b8229867c6b7b76add5940b .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1856604796" 
	@${RM} ${OBJECTDIR}/_ext/1856604796/drv_sdcard.o.d 
	@${RM} ${OBJECTDIR}/_ext/1856604796/drv_sdcard.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1856604796/drv_sdcard.o.d" -o ${OBJECTDIR}/_ext/1856604796/drv_sdcard.o ../../../../../../framework/driver/sdcard/src/dynamic/drv_sdcard.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1189039745/sys_fs.o: ../../../../../../framework/system/fs/src/dynamic/sys_fs.c  .generated_files/flags/default/d2f2f1d416470551830b50c345ca691ddad144cb .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1189039745" 
	@${RM} ${OBJECTDIR}/_ext/1189039745/sys_fs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1189039745/sys_fs.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1189039745/sys_fs.o.d" -o ${OBJECTDIR}/_ext/1189039745/sys_fs.o ../../../../../../framework/system/fs/src/dynamic/sys_fs.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o: ../../../../../../framework/system/fs/src/dynamic/sys_fs_media_manager.c  .generated_files/flags/default/a6894c9452dfbbfba609b233fb2fdf03d4d4b54c .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1189039745" 
	@${RM} ${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o.d" -o ${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o ../../../../../../framework/system/fs/src/dynamic/sys_fs_media_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2143635134/ff.o: ../../../../../../framework/system/fs/fat_fs/src/file_system/ff.c  .generated_files/flags/default/54237aad3bf6f22f37f571a4ce901876fc823806 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/2143635134" 
	@${RM} ${OBJECTDIR}/_ext/2143635134/ff.o.d 
	@${RM} ${OBJECTDIR}/_ext/2143635134/ff.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/2143635134/ff.o.d" -o ${OBJECTDIR}/_ext/2143635134/ff.o ../../../../../../framework/system/fs/fat_fs/src/file_system/ff.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/598511097/diskio.o: ../../../../../../framework/system/fs/fat_fs/src/hardware_access/diskio.c  .generated_files/flags/default/6c6f91ac855372fae4c491e43774e8b2862b5931 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/598511097" 
	@${RM} ${OBJECTDIR}/_ext/598511097/diskio.o.d 
	@${RM} ${OBJECTDIR}/_ext/598511097/diskio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/598511097/diskio.o.d" -o ${OBJECTDIR}/_ext/598511097/diskio.o ../../../../../../framework/system/fs/fat_fs/src/hardware_access/diskio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/711155467/sys_int_pic32.o: ../../../../../../framework/system/int/src/sys_int_pic32.c  .generated_files/flags/default/90c8d15936687439a59f860fa32a9baeefd673a7 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/711155467" 
	@${RM} ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o ../../../../../../framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/430974239/sys_tmr.o: ../../../../../../framework/system/tmr/src/sys_tmr.c  .generated_files/flags/default/a3cf8dc213dbf226f1e0dcf14be4b45643ae3146 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/430974239" 
	@${RM} ${OBJECTDIR}/_ext/430974239/sys_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/430974239/sys_tmr.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/430974239/sys_tmr.o.d" -o ${OBJECTDIR}/_ext/430974239/sys_tmr.o ../../../../../../framework/system/tmr/src/sys_tmr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/715571337/drv_spi_static.o: ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static.c  .generated_files/flags/default/79e478857970e2f35985819dfd7b8120b90c51c3 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/715571337" 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/715571337/drv_spi_static.o.d" -o ${OBJECTDIR}/_ext/715571337/drv_spi_static.o ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o: ../src/system_config/default/framework/driver/spi/static/src/drv_spi_mapping.c  .generated_files/flags/default/3a38a32870abeaad7d4708f0abb1bd9dbf8415e3 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/715571337" 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o.d" -o ${OBJECTDIR}/_ext/715571337/drv_spi_mapping.o ../src/system_config/default/framework/driver/spi/static/src/drv_spi_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o: ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_tasks.c  .generated_files/flags/default/d3b757f1db50bf9249b54fe7e3ba9019845a5277 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/715571337" 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o.d" -o ${OBJECTDIR}/_ext/715571337/drv_spi_static_tasks.o ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o: ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_sys_queue.c  .generated_files/flags/default/39782bc6087ec0afce476b399a13aae8fbbc33f0 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/715571337" 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o.d" -o ${OBJECTDIR}/_ext/715571337/drv_spi_static_sys_queue.o ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_sys_queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o: ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_ebm_tasks.c  .generated_files/flags/default/d1b3baac9ee1c82ae83eaa05fdd92e255180b84 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/715571337" 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o.d" -o ${OBJECTDIR}/_ext/715571337/drv_spi_static_ebm_tasks.o ../src/system_config/default/framework/driver/spi/static/src/drv_spi_static_ebm_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c  .generated_files/flags/default/600d0ae08765d0db4c13f69b4a4eaa172f2c9115 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c  .generated_files/flags/default/193b16cb4e1c2956bb083449f6c0371a926d163e .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o: ../src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c  .generated_files/flags/default/4bd1c4931e1b001006717c0c12b3533bc7b1de .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/327000265" 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o.d" -o ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o ../src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/327000265/drv_usart_static.o: ../src/system_config/default/framework/driver/usart/src/drv_usart_static.c  .generated_files/flags/default/d138facecd5d4277f94088ad7fc176ad0bb8cebe .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/327000265" 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/327000265/drv_usart_static.o.d" -o ${OBJECTDIR}/_ext/327000265/drv_usart_static.o ../src/system_config/default/framework/driver/usart/src/drv_usart_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o: ../src/system_config/default/framework/driver/usart/src/drv_usart_static_byte_model.c  .generated_files/flags/default/1a2b48ffa892c4043f145d3fd3ec59ff06b9b1e4 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/327000265" 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o.d 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o.d" -o ${OBJECTDIR}/_ext/327000265/drv_usart_static_byte_model.o ../src/system_config/default/framework/driver/usart/src/drv_usart_static_byte_model.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c  .generated_files/flags/default/b63f4ea3163bbd4b598ca4d04825509e80df5f55 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  .generated_files/flags/default/e58bc3f5a680dd20f6b01f822f4e40c28315421d .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c  .generated_files/flags/default/bcedc1d7d4b1323724f928fec73370bff50730e5 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  .generated_files/flags/default/a85077d28519202112fa273008ad21bf851a8ce5 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  .generated_files/flags/default/b1c81e2cbd7514b6d03aacdd0a3eb9ac570b406b .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  .generated_files/flags/default/64921e0c26ebd363455232b88b96b140e482b4c1 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  .generated_files/flags/default/7a624ec28fbeb3d6e95fe54c521ca81c08c33bdb .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  .generated_files/flags/default/d9f8ed37765b1bc115f8ca7b894130dcb21ed72b .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/b5d4e59d9ff3426f4be4d886b2626a27cfb6b407 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/85d5ce8bf87478c66df538aed5ac6458488550fb .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/DriverLCD.o: ../src/DriverLCD.c  .generated_files/flags/default/7703d42e1c8134898fa237593acdb74d235382ba .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DriverLCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DriverLCD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/DriverLCD.o.d" -o ${OBJECTDIR}/_ext/1360937237/DriverLCD.o ../src/DriverLCD.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/glcdfont.o: ../src/glcdfont.c  .generated_files/flags/default/44a994cf11ed8886d376c6cfe69322cdc17d466a .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/glcdfont.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/glcdfont.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/glcdfont.o.d" -o ${OBJECTDIR}/_ext/1360937237/glcdfont.o ../src/glcdfont.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32Delays.o: ../src/Mc32Delays.c  .generated_files/flags/default/b6f60715a9ee97d4d51d2a2c722da1943c43d8d4 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32Delays.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o ../src/Mc32Delays.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Gest_Menu.o: ../src/Gest_Menu.c  .generated_files/flags/default/c57b4fbc784b2a6483d62a4e435248d72a2cd2ab .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Gest_Menu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Gest_Menu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Gest_Menu.o.d" -o ${OBJECTDIR}/_ext/1360937237/Gest_Menu.o ../src/Gest_Menu.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o: ../src/GesFifoTh32.c  .generated_files/flags/default/44520674eda5c75bad70c7f11f2681bc1c9e135d .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o.d" -o ${OBJECTDIR}/_ext/1360937237/GesFifoTh32.o ../src/GesFifoTh32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Gest_TFT.o: ../src/Gest_TFT.c  .generated_files/flags/default/f266acb8d5225347f2e7bf901279eeff027b86ab .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Gest_TFT.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Gest_TFT.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Gest_TFT.o.d" -o ${OBJECTDIR}/_ext/1360937237/Gest_TFT.o ../src/Gest_TFT.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o: ../src/Mc32gest_RS232.c  .generated_files/flags/default/ec4f7e6548aac170815a927b7cbe3c9f8b79f9e2 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32gest_RS232.o ../src/Mc32gest_RS232.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app_SDCard.o: ../src/app_SDCard.c  .generated_files/flags/default/efd86db7674ed8e8e8866283f3d908fd468ca6bc .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_SDCard.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_SDCard.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app_SDCard.o.d" -o ${OBJECTDIR}/_ext/1360937237/app_SDCard.o ../src/app_SDCard.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/RF.o: ../src/RF.c  .generated_files/flags/default/3a67eb5d2e4bde12a1c63de767fadad8fdecf02f .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RF.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RF.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/RF.o.d" -o ${OBJECTDIR}/_ext/1360937237/RF.o ../src/RF.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Gest_USB.o: ../src/Gest_USB.c  .generated_files/flags/default/d8b881f6d19a43822b31cf9f8ab868880c5387d1 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Gest_USB.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Gest_USB.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Gest_USB.o.d" -o ${OBJECTDIR}/_ext/1360937237/Gest_USB.o ../src/Gest_USB.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1856604796/drv_sdcard.o: ../../../../../../framework/driver/sdcard/src/dynamic/drv_sdcard.c  .generated_files/flags/default/10b0b90a2e76e262ac8f677d515d8c0a083f547e .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1856604796" 
	@${RM} ${OBJECTDIR}/_ext/1856604796/drv_sdcard.o.d 
	@${RM} ${OBJECTDIR}/_ext/1856604796/drv_sdcard.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1856604796/drv_sdcard.o.d" -o ${OBJECTDIR}/_ext/1856604796/drv_sdcard.o ../../../../../../framework/driver/sdcard/src/dynamic/drv_sdcard.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1189039745/sys_fs.o: ../../../../../../framework/system/fs/src/dynamic/sys_fs.c  .generated_files/flags/default/e46ac0babe43b9035ab8ce2b9b89c2e8de4058e0 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1189039745" 
	@${RM} ${OBJECTDIR}/_ext/1189039745/sys_fs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1189039745/sys_fs.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1189039745/sys_fs.o.d" -o ${OBJECTDIR}/_ext/1189039745/sys_fs.o ../../../../../../framework/system/fs/src/dynamic/sys_fs.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o: ../../../../../../framework/system/fs/src/dynamic/sys_fs_media_manager.c  .generated_files/flags/default/b730d24f7a8138bb5a2da179202ff2cc3833d755 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/1189039745" 
	@${RM} ${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o.d" -o ${OBJECTDIR}/_ext/1189039745/sys_fs_media_manager.o ../../../../../../framework/system/fs/src/dynamic/sys_fs_media_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2143635134/ff.o: ../../../../../../framework/system/fs/fat_fs/src/file_system/ff.c  .generated_files/flags/default/a6191aeeba91a30523a91d77efc7577757de5080 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/2143635134" 
	@${RM} ${OBJECTDIR}/_ext/2143635134/ff.o.d 
	@${RM} ${OBJECTDIR}/_ext/2143635134/ff.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/2143635134/ff.o.d" -o ${OBJECTDIR}/_ext/2143635134/ff.o ../../../../../../framework/system/fs/fat_fs/src/file_system/ff.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/598511097/diskio.o: ../../../../../../framework/system/fs/fat_fs/src/hardware_access/diskio.c  .generated_files/flags/default/96c8ebf61133a760226b0e7ab7a4eeda2aa73207 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/598511097" 
	@${RM} ${OBJECTDIR}/_ext/598511097/diskio.o.d 
	@${RM} ${OBJECTDIR}/_ext/598511097/diskio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/598511097/diskio.o.d" -o ${OBJECTDIR}/_ext/598511097/diskio.o ../../../../../../framework/system/fs/fat_fs/src/hardware_access/diskio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/711155467/sys_int_pic32.o: ../../../../../../framework/system/int/src/sys_int_pic32.c  .generated_files/flags/default/73341999adc11dfb0b3dbcd37e095e313b41753b .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/711155467" 
	@${RM} ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o ../../../../../../framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/430974239/sys_tmr.o: ../../../../../../framework/system/tmr/src/sys_tmr.c  .generated_files/flags/default/931a890b0f17175a9c27c714cf06c27bfcf38a81 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}/_ext/430974239" 
	@${RM} ${OBJECTDIR}/_ext/430974239/sys_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/430974239/sys_tmr.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../../../../framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/430974239/sys_tmr.o.d" -o ${OBJECTDIR}/_ext/430974239/sys_tmr.o ../../../../../../framework/system/tmr/src/sys_tmr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/1811_Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../bin/framework/peripheral/PIC32MX170F256D_peripherals.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/1811_Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\bin\framework\peripheral\PIC32MX170F256D_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/1811_Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../bin/framework/peripheral/PIC32MX170F256D_peripherals.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/1811_Master.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\bin\framework\peripheral\PIC32MX170F256D_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/1811_Master.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
