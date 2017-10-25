
#ifndef __SPIConfig_H__
#define __SPIConfig_H__


#include <p18f47j13.h>
#include "declaration.h"
#include <spi.h>


extern void initialiserSPI(void);
extern void WriteENC(void);
extern void WriteEEPROM(void);
extern void WriteEEPROMAC(void);

#endif