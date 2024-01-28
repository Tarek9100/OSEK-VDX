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
void SWC1_Init_Internal(void) {
  unsigned int l_Counter = 0;

  ledToggle(BLUE);
  for (l_Counter = 0; l_Counter < 6000000; l_Counter++) {
  }
}

TASK(SWC1_Init) {
  SWC1_Init_Internal();
  ActivateTask(SWC2_Init);
  TerminateTask();
}
#define APP_Task_SWC1_Init_STOP_SEC_CODE
#include "tpl_memmap.h"

/******************************************************************/

#define APP_Task_SWC2_Init_START_SEC_CODE
#include "tpl_memmap.h"
void SWC2_Init_Internal(void) {
  unsigned int l_Counter = 0;
  ledToggle(GREEN);
  for (l_Counter = 0; l_Counter < 6000000; l_Counter++) {
  }
}

TASK(SWC2_Init) {
  SWC2_Init_Internal();
  ActivateTask(SWC3_Init);
  TerminateTask();
}
#define APP_Task_SWC2_Init_STOP_SEC_CODE
#include "tpl_memmap.h"

/******************************************************************/

#define APP_Task_SWC3_Init_START_SEC_CODE
#include "tpl_memmap.h"
void SWC3_Init_Internal(void) {
  unsigned int l_Counter = 0;
  ledToggle(BLUE);
  for (l_Counter = 0; l_Counter < 6000000; l_Counter++) {
  }
}

TASK(SWC3_Init) {
  SWC3_Init_Internal();
  ActivateTask(SWC4_Init);
  TerminateTask();
}
#define APP_Task_SWC3_Init_STOP_SEC_CODE
#include "tpl_memmap.h"

/******************************************************************/

#define APP_Task_SWC4_Init_START_SEC_CODE
#include "tpl_memmap.h"
void SWC4_Init_Internal(void) {
  unsigned int l_Counter = 0;
  ledToggle(ORANGE);
  for (l_Counter = 0; l_Counter < 6000000; l_Counter++) {
  }
}

TASK(SWC4_Init) {
  SWC4_Init_Internal();
  ShutdownOS(E_OK);
  TerminateTask();
}
#define APP_Task_SWC4_Init_STOP_SEC_CODE
#include "tpl_memmap.h"

/******************************************************************/

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t *file, uint32_t line) {}

FUNC(void, OS_CODE) PreTaskHook() {}

FUNC(void, OS_CODE) PostTaskHook() {}

FUNC(void, OS_CODE) ShutdownHook(StatusType Error) {
  if (E_OK == Error) {
    /* Normal Shutdown */
    ledOff(RED);
    ledOff(GREEN);
    ledOff(ORANGE);
    ledOff(BLUE);
  } else {
    /* Abnormal Shutdown */
  }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
