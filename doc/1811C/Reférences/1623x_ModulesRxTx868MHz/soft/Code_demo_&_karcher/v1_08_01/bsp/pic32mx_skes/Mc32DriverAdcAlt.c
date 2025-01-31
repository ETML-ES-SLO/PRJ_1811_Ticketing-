/*--------------------------------------------------------*/
//  Mc32DriverAdcAlt.c
/*--------------------------------------------------------*/
//	Description :	Fonctions pour gestion ADC 10 bits
//                      en mode Alterné
//	Auteur 		: 	C. HUBER
//					
//	Version		:	V1.0
//	Compilateur	:	XC32 V1.33 & Harmony 1.00
//
//      BSP             :  pic32mx_skes
//
// Revu / modifié:
//      création 18.09.2014 CHR
/*--------------------------------------------------------*/

#include "system_config.h"
#include "Mc32DriverAdcAlt.h"
#include "peripheral/adc/plib_adc.h"



/*--------------------------------------------------------*/
// Fonction BSP_InitADC10Alt
/*--------------------------------------------------------*/

void BSP_InitADC10Alt(void)
{
    // Configure l'ADC
    
    PLIB_ADC_ResultFormatSelect(ADC_ID_1, ADC_RESULT_FORMAT_INTEGER_16BIT);
    PLIB_ADC_ResultBufferModeSelect(ADC_ID_1, ADC_BUFFER_MODE_TWO_8WORD_BUFFERS);
    PLIB_ADC_SamplingModeSelect(ADC_ID_1, ADC_SAMPLING_MODE_ALTERNATE_INPUT);

    PLIB_ADC_ConversionTriggerSourceSelect(ADC_ID_1, ADC_CONVERSION_TRIGGER_INTERNAL_COUNT);
    PLIB_ADC_VoltageReferenceSelect(ADC_ID_1, ADC_REFERENCE_VDD_TO_AVSS );
    PLIB_ADC_SampleAcquisitionTimeSet(ADC_ID_1, 0x1F);
    PLIB_ADC_ConversionClockSet(ADC_ID_1, SYS_CLK_FREQ, 32);

    // configure MUXA - traitement AN0
    PLIB_ADC_MuxChannel0InputPositiveSelect(ADC_ID_1, ADC_MUX_A, ADC_INPUT_POSITIVE_AN0);
    PLIB_ADC_MuxChannel0InputNegativeSelect(ADC_ID_1, ADC_MUX_A, ADC_INPUT_NEGATIVE_VREF_MINUS);

     // configure MUXB - traitement AN1
    PLIB_ADC_MuxChannel0InputPositiveSelect(ADC_ID_1, ADC_MUX_B, ADC_INPUT_POSITIVE_AN1);
    PLIB_ADC_MuxChannel0InputNegativeSelect(ADC_ID_1, ADC_MUX_B, ADC_INPUT_NEGATIVE_VREF_MINUS);
    
    // Rem CHR le nb d'échantillon par interruption doit correspondre a 2
    PLIB_ADC_SamplesPerInterruptSelect(ADC_ID_1, ADC_2SAMPLES_PER_INTERRUPT);
    // Disable scan
    PLIB_ADC_InputScanMaskRemove(ADC_ID_1, 0xFFFF) ;    // les 16

    // Start auto sampling
    PLIB_ADC_SampleAutoStartEnable(ADC_ID_1);

    // Enable the ADC module
    PLIB_ADC_Enable(ADC_ID_1);
 }



/*--------------------------------------------------------*/
// Fonction BSP_ReadADCAlt()
/*--------------------------------------------------------*/

S_ADCResultsAlt  BSP_ReadADCAlt()
{
    S_ADCResultsAlt result;
    ADC_RESULT_BUF_STATUS BufStatus;

    PLIB_ADC_SampleAutoStartDisable(ADC_ID_1);
    // on exploite un résulat déja converti mais on bloque durant la lecture du buffer

    // traitement avec buffer alterné
    BufStatus = PLIB_ADC_ResultBufferStatusGet(ADC_ID_1);
    if (BufStatus == ADC_FILLING_BUF_0TO7) {
        result.Chan0 = PLIB_ADC_ResultGetByIndex(ADC_ID_1, 0);
        result.Chan1 = PLIB_ADC_ResultGetByIndex(ADC_ID_1, 1);
    } else {
        result.Chan0 = PLIB_ADC_ResultGetByIndex(ADC_ID_1, 8);
        result.Chan1 = PLIB_ADC_ResultGetByIndex(ADC_ID_1, 9);
    }

    // relance Auto start sampling
    PLIB_ADC_SampleAutoStartEnable(ADC_ID_1);
    
    return result;
}
