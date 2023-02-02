#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
Concurrency - We need to achieve current regulation by controlling a voltage source.
Voltage and current feedback are available at 100Hz, but voltage can only be
controlled at 10Hz

Stubs have been defined which provide an API to be consumed for application code
that will compile. As written, these stubs won't do anything

Make changes to application code to achieve functional goal
*/

//-----------------------------------------------------------------------------
// RTOS stubs
//-----------------------------------------------------------------------------
typedef uint32_t TickType_t;
typedef uint32_t SemaphoreHandle_t;

static void DisableInterrupts(void)
    {  }
static void EnableInterrupts(void)
    {  }
static bool SemaphoreTake(const SemaphoreHandle_t handle, const TickType_t msToWait)
    { (void)handle; (void)msToWait; return true; }
static void SemaphoreGive(const SemaphoreHandle_t handle)
    { (void)handle; }

//-----------------------------------------------------------------------------
// Feedback and control stubs
//-----------------------------------------------------------------------------
static float GetFeedbackCurrent100Hz(void)
    { return 0.0F; }
static float GetFeedbackVoltage100Hz(void)
    { return 0.0F; }
static void SetVoltageOutput10Hz(const float voltage)
    { (void)voltage; }

//-----------------------------------------------------------------------------
// Filter and regulator stubs
//-----------------------------------------------------------------------------
// 5Hz cutoff at 100Hz sampling for 10Hz consumption
static float CalculateFiltered5HzCutoffValue(const float input100HzValue)
    { (void)input100HzValue; return 0.0F; }
static float GetTargetCurrent(void)
    { return 0.0F; }
static float GetRegulatedVoltageOutput(const float feedbackCurrent, const float feedbackVoltage, const float targetCurrent)
    { (void)feedbackCurrent; (void)feedbackVoltage; (void)targetCurrent; return 0.0F; }

//-----------------------------------------------------------------------------
// Application code - make changes here
//-----------------------------------------------------------------------------
static void Run100Hz(void)
{
    // Place periodic code here, assume scheduler will run this repeatedly at 100Hz
}

static void Run10Hz(void)
{
    // Place periodic code here, assume scheduler will run this repeatedly at 10Hz
}

int main(void)
{
    Run100Hz();
    Run10Hz();

    printf("Hello world\n");

    return 0;
}
