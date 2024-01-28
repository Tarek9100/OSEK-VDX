#include "tp.h"
#include "tpl_os.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void) {
  initBoard();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/******************************************************************/
#define APP_Task_SWC1_Init_START_SEC_CODE
#include "tpl_memmap.h"

TASK(SWC1_Init) {
  ledToggle(BLUE);
  TerminateTask();
}

#define APP_Task_SWC1_Init_STOP_SEC_CODE
#include "tpl_memmap.h"

/******************************************************************/

#define APP_Task_SWC1_Task_250ms_START_SEC_CODE
#include "tpl_memmap.h"

TASK(SWC1_Task_250ms) {
  ledToggle(RED);
  TerminateTask();
}

#define APP_Task_SWC1_Task_250ms_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_SWC1_Task_500ms_START_SEC_CODE
#include "tpl_memmap.h"

TASK(SWC1_Task_500ms) {
  ledToggle(GREEN);
  TerminateTask();
}

#define APP_Task_SWC1_Task_500ms_STOP_SEC_CODE
#include "tpl_memmap.h"

/******************************************************************/

#define APP_Task_SWC2_MainTask_START_SEC_CODE
#include "tpl_memmap.h"

TASK(SWC2_MainTask) {
  /* Init Code */
  EventMaskType RecEvent;
  for (;;) {
    (void)WaitEvent(event1);
    (void)GetEvent(SWC2_MainTask, &RecEvent);
    (void)ClearEvent(RecEvent & (event1));

    if ((event1 & RecEvent) != (EventMaskType)0) {
      ledToggle(BLUE);
    }
  }
  TerminateTask();
}

#define APP_Task_SWC2_MainTask_STOP_SEC_CODE
#include "tpl_memmap.h"

/******************************************************************/

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

ALARMCALLBACK(Alarm_500msCallback) {
  /* Callback code. */
  ledToggle(ORANGE);
}

/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t *file, uint32_t line) {}

FUNC(void, OS_CODE) PreTaskHook() {}

FUNC(void, OS_CODE) PostTaskHook() {}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
