#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
Concurrency - tasks operating at different rates need to communicate with an ADC
device over SPI. Some measurements are to be aquired at 100Hz and others at 10Hz.
Stubs have been provided for RTOS and SPI interfacing
*/

/*
SPI device interface:

|----------|              |----------|
|          |------SCK---->|          |
|          |------CS----->|          |
|    MCU   |-----MOSI---->|   ADC    |
|          |<----MISO-----|  device  |
|          |              |          |
|          |<--DATA RDY---|          |
|----------|              |----------|

Read: send command, wait for data ready GPIO interrupt (up to 1250 uSec), read N+1 bytes

        |                    Data
        | bit7  bit6  bit5  bit4  bit3  bit2  bit1  bit0
Command |
 byte0  | N[3]  N[2]  N[1]  N[0]  A[11] A[10] A[9]  A[8]
 byte1  | A[7]  A[6]  A[5]  A[4]  A[3]  A[2]  A[1]  A[0]

N - number of bytes to read. Actual bytes will be N+1
A - address at which to being read


Address |        Data
 0x520  |    current[23:16]
 0x521  |    current[15:8]
 0x522  |    current[7:0]
        |
 0x540  |    voltage0[15:8]
 0x541  |    voltage0[7:0]
 0x542  |    voltage1[15:8]
 0x543  |    voltage1[7:0]
 0x544  |    voltage2[15:8]
 0x545  |    voltage2[7:0]
 0x546  |    voltage3[15:8]
 0x547  |    voltage3[7:0]
 0x548  |    voltage4[15:8]
 0x549  |    voltage4[7:0]
 0x54A  |    voltage5[15:8]
 0x54B  |    voltage5[7:0]
 0x54C  |    voltage6[15:8]
 0x54D  |    voltage6[7:0]
 0x54E  |    voltage7[15:8]
 0x54F  |    voltage7[7:0]

current - signed 24-bit, in 1e-4 A
voltage - unsigned 16-bit, in 1e-4 V

*/

//-----------------------------------------------------------------------------
// RTOS stubs
//-----------------------------------------------------------------------------
typedef uint32_t * TaskHandle_t;
typedef uint32_t TickType_t;
typedef uint32_t * SemaphoreHandle_t;

static void EnterCriticalSection(void)
    {  }
static void ExitCriticalSection(void)
    {  }
static TaskHandle_t GetCurrentTaskHandle(void)
    { return NULL; };
static void TaskDelay(const TickType_t msToWait)
    { (void)msToWait; }
static bool TaskWaitForNotification(const TaskHandle_t handle, const TickType_t msToWait)
    { (void)handle; (void)msToWait; return true; }
static void TaskNotify(const TaskHandle_t handle)
    { (void)handle; }
static bool SemaphoreTake(const SemaphoreHandle_t handle, const TickType_t msToWait)
    { (void)handle; (void)msToWait; return true; }
static void SemaphoreGive(const SemaphoreHandle_t handle)
    { (void)handle; }

//-----------------------------------------------------------------------------
// SPI stubs
// Note: SPI is not polling - i.e. the CPU is free while SPI data is
// sent/received on the wire. SpiTransceiveCompleteISR() is called when data is done
//-----------------------------------------------------------------------------
static bool SpiTransceive(const uint8_t * const pTx, uint8_t * const pRx, const uint8_t numBytes)
    { (void)pTx; (void)pRx; (void)pTx; return numBytes; }

//-----------------------------------------------------------------------------
// Data ready GPIO stubs
//-----------------------------------------------------------------------------
static void EnableDataReadyInterrupt(void)
    {  }
static void DisableDataReadyInterrupt(void)
    {  }


//-----------------------------------------------------------------------------
// Application code
//-----------------------------------------------------------------------------
static void SpiTransceiveCompleteISR(void)
{
    // This function is called after the transceive from SpiTransceive completes
}
static void DataReadyISR(void)
{
    // This fuction is called after the ADC device generatees a data ready GPIO interrupt
}

static void Run100Hz(void)
{
    // Read current at 100Hz
    // Place periodic code here, assume scheduler will run this repeatedly at 100Hz
}

static void Run10Hz(void)
{
    // Read voltages at 10Hz
    // Place periodic code here, assume scheduler will run this repeatedly at 10Hz
}

int main(void)
{
    Run100Hz();
    Run10Hz();

    printf("Hello world\n");

    return 0;
}
