/**
 * @file    common_macros.h
 * @brief   Common Macros header file for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
//--------------------- Header Guard -------------------------------

#ifndef COMMON_MACROS
#define COMMON_MACROS


#define SET_BIT(REG,BIT) (REG|=(1<<BIT)) /**< Set a certain bit in any register */

#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT))) /**< Clear a certain bit in any register */

#define GET_BIT(REG,BIT) ((REG>>BIT)&1) /**< Clear a certain bit in any register */

#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT)) /**< Toggle a certain bit in any register */

#endif
//--------------------- End of File --------------------------------