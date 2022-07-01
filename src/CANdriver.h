#ifndef _CANDRIVER_H_
#define _CANDRIVER_H_

#include "mockSTM32.h"


void CANInit(CAN_HandleTypeDef * pcan, CAN_TxHeaderTypeDef *TxHeader, CAN_RxHeaderTypeDef *RxHeader);

void canTx(CAN_HandleTypeDef *pcan, CAN_TxHeaderTypeDef *pHeader, uint8_t *message);

void canRx(CAN_HandleTypeDef *pcan, CAN_RxHeaderTypeDef *pHeader, uint8_t *buffer);

#endif