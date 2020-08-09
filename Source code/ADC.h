/**
 * @file    ADC.h
 * @brief   ADC Module header file for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
//--------------------- Header Guard -------------------------------
#ifndef ADC_H_
#define ADC_H_

// ------------------ File Inclusions -------------------------------
#include "std_types.h"
#include <xc.h>

// ------  function prototypes -------------------------------

/**
 * \b Brief: This is The ADC Module Initialization Function 
 * @param void 
 * @return void 
 */
void ADC_Init(void);
/**
 * \b Brief: This is The ADC Module Read channel Function 
 * @param channel unsigned char to select certain channel of ADC module   
 * @return unsigned int to get the reading of ADC selected channel 
 */
uint16 ADC_ReadChannel(uint8 channel);

#endif /* ADC_H_ */

//--------------------- End of File --------------------------------