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

#define APP_Task_SWC1_Task_START_SEC_CODE
#include "tpl_memmap.h"

TASK(SWC1_Task) {
  unsigned int l_Counter = 0;

  /* Enter Critical section */
  GetResource(Resource_One);
  /* Critical section */
  for (l_Counter = 0; l_Counter < 6000000; l_Counter++) {
  }
  ledOn(RED);
  /* Exit Critical section */
  ReleaseResource(Resource_One);

  TerminateTask();
}

#define APP_Task_SWC1_Task_STOP_SEC_CODE
#include "tpl_memmap.h"

/******************************************************************/

#define APP_Task_SWC2_Task_START_SEC_CODE
#include "tpl_memmap.h"

TASK(SWC2_Task) {
  unsigned int l_Counter = 0;

  /* Task functionality */
  ledOn(GREEN);
  for (l_Counter = 0; l_Counter < 6000000; l_Counter++) {
  }

  /* Enter Critical section */
  GetResource(Resource_One);
  /* Critical section */
  ActivateTask(SWC1_Task);
  for (l_Counter = 0; l_Counter < 6000000; l_Counter++) {
  }
  ledToggle(BLUE);
  /* Exit Critical section */
  ReleaseResource(Resource_One);

  /* Task functionality */
  for (l_Counter = 0; l_Counter < 6000000; l_Counter++) {
  }

  TerminateTask();
}

#define APP_Task_SWC2_Task_STOP_SEC_CODE
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
