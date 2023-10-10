/*
 * std_types.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Ahmed ElSayed
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char 		UINT8_t;
typedef unsigned short		UINT16_t;
typedef unsigned long		UINT32_t;
typedef unsigned long long	UINT64_t;
typedef float				FLOAT32_t;
typedef double				DOUBLE64_t;

typedef signed char 		INT8_t;
typedef signed short		INT16_t;
typedef signed long			INT32_t;
typedef signed long long	INT64_t;

typedef enum{
	FALSE,
	TRUE
}bool;

typedef enum{
	OFF,
	ON
}state;

#ifndef NULL
#define NULL	((void *) 0)
#endif


#endif /* STD_TYPES_H_ */
