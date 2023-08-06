/*
 * HCLCD_interface.h
 *
 *  Created on: Sep 16, 2022
 *      Author: Eng. Karim
 */

#ifndef HAL_HCLCD_HCLCD_INTERFACE_H_
#define HAL_HCLCD_HCLCD_INTERFACE_H_

void HCLCD_voidInit (void);

void HCLCD_voidSend_Command (u8 Copy_u8CMD);
void HCLCD_voidSend_Data (u8 Copy_u8DATA);

void HCLCD_voidClear (void);

void HCLCD_voidDisplay_Char (u8 Copy_u8Char);
void HCLCD_voidDisplay_String (u8 *Copy_pu8String);
void HCLCD_voidDisplay_Number (u8 Copy_u8Num);
void HCLCD_voidDisplay_MultiNumber (u32 Copy_u32Num, u8 Copy_u8RowPos, u8 Copy_u8ColPos);
void HCLCD_voidDisplay_SpecialChar (u8 Copy_u8SpChar);

void HCLCD_voidGoTo (u8 Copy_u8RowPos, u8 Copy_u8ColPos);
void HCLCD_voidBlinkCursor (void);

void HCLCD_voidShift_Right (void);
void HCLCD_voidShift_Left (void);

enum Rows
{
	HCLCD_ROW1,
	HCLCD_ROW2,
};

enum Columns
{
	HCLCD_Column1, HCLCD_Column2, HCLCD_Column3, HCLCD_Column4, HCLCD_Column5,
	HCLCD_Column6, HCLCD_Column7, HCLCD_Column8, HCLCD_Column9, HCLCD_Column10,
	HCLCD_Column11, HCLCD_Column12, HCLCD_Column13, HCLCD_Column14, HCLCD_Column15,
	HCLCD_Column16, HCLCD_Column17, HCLCD_Column18, HCLCD_Column19, HCLCD_Column20,
	HCLCD_Column21, HCLCD_Column22, HCLCD_Column23, HCLCD_Column24, HCLCD_Column25,
	HCLCD_Column26,	HCLCD_Column27, HCLCD_Column28, HCLCD_Column29, HCLCD_Column30,
	HCLCD_Column31, HCLCD_Column32, HCLCD_Column33, HCLCD_Column34, HCLCD_Column35,
	HCLCD_Column36, HCLCD_Column37, HCLCD_Column38, HCLCD_Column39, HCLCD_Column40,
	HCLCD_Column41, HCLCD_Column42, HCLCD_Column43, HCLCD_Column44, HCLCD_Column45,
	HCLCD_Column46, HCLCD_Column47, HCLCD_Column48, HCLCD_Column49, HCLCD_Column50,
	HCLCD_Column51, HCLCD_Column52, HCLCD_Column53, HCLCD_Column54, HCLCD_Column55,
	HCLCD_Column56, HCLCD_Column57, HCLCD_Column58, HCLCD_Column59, HCLCD_Column60,
	HCLCD_Column61, HCLCD_Column62, HCLCD_Column63, HCLCD_Column64, HCLCD_Column65,
	HCLCD_Column66, HCLCD_Column67, HCLCD_Column68, HCLCD_Column69, HCLCD_Column70,
	HCLCD_Column71, HCLCD_Column72, HCLCD_Column73, HCLCD_Column74, HCLCD_Column75,
	HCLCD_Column76, HCLCD_Column77, HCLCD_Column78, HCLCD_Column79, HCLCD_Column80
};
#endif /* HAL_HCLCD_HCLCD_INTERFACE_H_ */
