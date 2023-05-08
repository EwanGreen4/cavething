// THIS IS DECOMPILED PROPRIETARY CODE - USE AT YOUR OWN RISK.
//
// The original code belongs to Daisuke "Pixel" Amaya.
//
// Modifications and custom code are under the MIT licence.
// See LICENCE.txt for details.

#pragma once

#include <cstdlib>

#include "CommonDefines.h"
#include "WindowsWrapper.h"

#define FADE_WIDTH (((gDisplayMode.width - 1) / 16) + 1)
#define FADE_HEIGHT (((gDisplayMode.height - 1) / 16) + 1)

#define COMPOUND_2D_ACCESS(x, y) (FADE_HEIGHT * y + x)
struct FADE {
  FADE() {
    mode = 0;
    bMask = false;
    count = 0;
    ani_no = static_cast<signed char *>(
        malloc((FADE_HEIGHT * FADE_WIDTH) * sizeof(signed char)));
    flag = static_cast<signed char *>(
        malloc((FADE_HEIGHT * FADE_WIDTH) * sizeof(signed char)));
    dir = 0;
  }

  int mode;
  BOOL bMask;
  int count;
  signed char *ani_no /*[FADE_HEIGHT][FADE_WIDTH]*/;
  signed char *flag /*[FADE_HEIGHT][FADE_WIDTH]*/;  // Not a BOOLEAN (those are
                                                    // unsigned)
  signed char dir;
};

extern FADE gFade;

void InitFade(void);
void SetFadeMask(void);
void ClearFade(void);
void StartFadeOut(signed char dir);
void StartFadeIn(signed char dir);
void ProcFade(void);
void PutFade(void);
BOOL GetFadeActive(void);
