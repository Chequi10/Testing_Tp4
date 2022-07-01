#include "src/mockSTM32.h"
#include "src/CANdriver.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
CAN_HandleTypeDef hcan1 = 0xf;

CAN_TxHeaderTypeDef canTxHeader;

CAN_RxHeaderTypeDef canRxHeader;

uint8_t canBufferTx[128] = "";

uint8_t canBufferRx[128] = "";







void test_InitCan()

{

    CANInit(&hcan1, &canTxHeader, &canRxHeader);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT32)((0)), (UNITY_INT)(UNITY_UINT32)((canTxHeader.DLC)), (

   ((void *)0)

   ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_UINT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT32)((0)), (UNITY_INT)(UNITY_UINT32)((canRxHeader.DLC)), (

   ((void *)0)

   ), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_UINT32);

}





void test_CanTransmittByte()

{

    uint8_t byte[] = "A";

    canTx(&hcan1, &canTxHeader, byte);

    UnityAssertEqualString((const char*)((byte)), (const char*)((canBufferTx)), (

   ((void *)0)

   ), (UNITY_UINT)(34));

}





void test_CanReceiveByte()

{

    uint8_t BufferRx_temp[255];

    strcpy(canBufferRx, "b");

    canRx(&hcan1, &canRxHeader, BufferRx_temp);

    UnityAssertEqualString((const char*)((canBufferRx)), (const char*)((BufferRx_temp)), (

   ((void *)0)

   ), (UNITY_UINT)(43));

}





void test_transmision_un_string()

{

    uint8_t string[] = "Conectando";

    canTx(&hcan1, &canTxHeader, string);

    UnityAssertEqualString((const char*)((string)), (const char*)((canBufferTx)), (

   ((void *)0)

   ), (UNITY_UINT)(51));

}





void test_recepcion_un_string()

{

    uint8_t BufferRx_temp[255];

    strcpy(canBufferRx, "Conectado");

    canRx(&hcan1, &canRxHeader, BufferRx_temp);

    UnityAssertEqualString((const char*)((canBufferRx)), (const char*)((BufferRx_temp)), (

   ((void *)0)

   ), (UNITY_UINT)(60));

}
