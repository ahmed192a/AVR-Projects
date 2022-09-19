/**
 * @file CommonMacros.h
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Common macros header file
 * @version 0.1
 * @date 2022-09-19 @ 15:09:83
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef COMMONMACROS_H
#define COMMONMACROS_H

#define SET_BIT(REG,BIT) (REG |= (1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGGLE_BIT(REG,BIT) (REG ^= (1<<BIT))
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)

#define SHIFT_LEFT(REG, BITNUM) (REG = (REG<<BITNUM)|(REG>>(8-BITNUM)))
#define SHIFT_RIGHT(REG, BITNUM) (REG = (REG>>BITNUM)|(REG<<(8-BITNUM)))



#endif  /* COMMONMACROS_H */