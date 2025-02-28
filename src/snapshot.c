/***********************************************************************************
  Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.

  (c) Copyright 1996 - 2002  Gary Henderson (gary.henderson@ntlworld.com),
                             Jerremy Koot (jkoot@snes9x.com)

  (c) Copyright 2002 - 2004  Matthew Kendora

  (c) Copyright 2002 - 2005  Peter Bortas (peter@bortas.org)

  (c) Copyright 2004 - 2005  Joel Yliluoma (http://iki.fi/bisqwit/)

  (c) Copyright 2001 - 2006  John Weidman (jweidman@slip.net)

  (c) Copyright 2002 - 2006  funkyass (funkyass@spam.shaw.ca),
                             Kris Bleakley (codeviolation@hotmail.com)

  (c) Copyright 2002 - 2010  Brad Jorsch (anomie@users.sourceforge.net),
                             Nach (n-a-c-h@users.sourceforge.net),
                             zones (kasumitokoduck@yahoo.com)

  (c) Copyright 2006 - 2007  nitsuja

  (c) Copyright 2009 - 2010  BearOso,
                             OV2


  BS-X C emulator code
  (c) Copyright 2005 - 2006  Dreamer Nom,
                             zones

  C4 x86 assembler and some C emulation code
  (c) Copyright 2000 - 2003  _Demo_ (_demo_@zsnes.com),
                             Nach,
                             zsKnight (zsknight@zsnes.com)

  C4 C++ code
  (c) Copyright 2003 - 2006  Brad Jorsch,
                             Nach

  DSP-1 emulator code
  (c) Copyright 1998 - 2006  _Demo_,
                             Andreas Naive (andreasnaive@gmail.com),
                             Gary Henderson,
                             Ivar (ivar@snes9x.com),
                             John Weidman,
                             Kris Bleakley,
                             Matthew Kendora,
                             Nach,
                             neviksti (neviksti@hotmail.com)

  DSP-2 emulator code
  (c) Copyright 2003         John Weidman,
                             Kris Bleakley,
                             Lord Nightmare (lord_nightmare@users.sourceforge.net),
                             Matthew Kendora,
                             neviksti

  DSP-3 emulator code
  (c) Copyright 2003 - 2006  John Weidman,
                             Kris Bleakley,
                             Lancer,
                             z80 gaiden

  DSP-4 emulator code
  (c) Copyright 2004 - 2006  Dreamer Nom,
                             John Weidman,
                             Kris Bleakley,
                             Nach,
                             z80 gaiden

  OBC1 emulator code
  (c) Copyright 2001 - 2004  zsKnight,
                             pagefault (pagefault@zsnes.com),
                             Kris Bleakley
                             Ported from x86 assembler to C by sanmaiwashi

  SPC7110 and RTC C++ emulator code used in 1.39-1.51
  (c) Copyright 2002         Matthew Kendora with research by
                             zsKnight,
                             John Weidman,
                             Dark Force

  SPC7110 and RTC C++ emulator code used in 1.52+
  (c) Copyright 2009         byuu,
                             neviksti

  S-DD1 C emulator code
  (c) Copyright 2003         Brad Jorsch with research by
                             Andreas Naive,
                             John Weidman

  S-RTC C emulator code
  (c) Copyright 2001 - 2006  byuu,
                             John Weidman

  ST010 C++ emulator code
  (c) Copyright 2003         Feather,
                             John Weidman,
                             Kris Bleakley,
                             Matthew Kendora

  Super FX x86 assembler emulator code
  (c) Copyright 1998 - 2003  _Demo_,
                             pagefault,
                             zsKnight

  Super FX C emulator code
  (c) Copyright 1997 - 1999  Ivar,
                             Gary Henderson,
                             John Weidman

  Sound emulator code used in 1.5-1.51
  (c) Copyright 1998 - 2003  Brad Martin
  (c) Copyright 1998 - 2006  Charles Bilyue'

  Sound emulator code used in 1.52+
  (c) Copyright 2004 - 2007  Shay Green (gblargg@gmail.com)

  SH assembler code partly based on x86 assembler code
  (c) Copyright 2002 - 2004  Marcus Comstedt (marcus@mc.pp.se)

  2xSaI filter
  (c) Copyright 1999 - 2001  Derek Liauw Kie Fa

  HQ2x, HQ3x, HQ4x filters
  (c) Copyright 2003         Maxim Stepin (maxim@hiend3d.com)

  NTSC filter
  (c) Copyright 2006 - 2007  Shay Green

  GTK+ GUI code
  (c) Copyright 2004 - 2010  BearOso

  Win32 GUI code
  (c) Copyright 2003 - 2006  blip,
                             funkyass,
                             Matthew Kendora,
                             Nach,
                             nitsuja
  (c) Copyright 2009 - 2010  OV2

  Mac OS GUI code
  (c) Copyright 1998 - 2001  John Stiles
  (c) Copyright 2001 - 2010  zones

  (c) Copyright 2010 - 2016 Daniel De Matteis. (UNDER NO CIRCUMSTANCE 
  WILL COMMERCIAL RIGHTS EVER BE APPROPRIATED TO ANY PARTY)

  Specific ports contains the works of other authors. See headers in
  individual files.


  Snes9x homepage: http://www.snes9x.com/

  Permission to use, copy, modify and/or distribute Snes9x in both binary
  and source form, for non-commercial purposes, is hereby granted without
  fee, providing that this license information and copyright notice appear
  with all copies and any derived work.

  This software is provided 'as-is', without any express or implied
  warranty. In no event shall the authors be held liable for any damages
  arising from the use of this software or it's derivatives.

  Snes9x is freeware for PERSONAL USE only. Commercial users should
  seek permission of the copyright holders first. Commercial use includes,
  but is not limited to, charging money for Snes9x or software derived from
  Snes9x, including Snes9x or derivatives in commercial game bundles, and/or
  using Snes9x as a promotion for your commercial product.

  The copyright holders request that bug fixes and improvements to the code
  should be forwarded to them so everyone can benefit from the modifications
  in future versions.

  Super NES and Super Nintendo Entertainment System are trademarks of
  Nintendo Co., Limited and its subsidiary companies.
 ***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snes9x.h"
#include "memmap.h"
#include "getset.h"
#include "dma.h"
#include "apu.h"
#include "fxinst.h"
#include "fxemu.h"
#include "sdd1.h"
#include "srtc.h"
#include "snapshot.h"
#include "controls.h"
#include "display.h"

#ifndef min
#define min(a,b)	(((a) < (b)) ? (a) : (b))
#endif

typedef struct
{
	int		offset;
	int		offset2;
	int		size;
	int		type;
	uint16		debuted_in;
	uint16		deleted_in;
	const char	*name;
}	FreezeData;

enum
{
	INT_V,
	uint8_ARRAY_V,
	uint16_ARRAY_V,
	uint32_ARRAY_V,
	uint8_INDIR_ARRAY_V,
	uint16_INDIR_ARRAY_V,
	uint32_INDIR_ARRAY_V,
	POINTER_V
};

#define COUNT(ARRAY)			(sizeof(ARRAY) / sizeof(ARRAY[0]))
#define Offset(field, structure)	((int) (((char *) (&(((structure) NULL)->field))) - ((char *) NULL)))
#define OFFSET(f)			Offset(f, STRUCT *)
#define DUMMY(f)			Offset(f, struct Obsolete *)
#define DELETED(f)			(-1)

#define INT_ENTRY(save_version_introduced, field) \
{ \
	OFFSET(field), \
	0, \
	sizeof(((STRUCT *) NULL)->field), \
	INT_V, \
	save_version_introduced, \
	9999, \
	#field \
}

#define ARRAY_ENTRY(save_version_introduced, field, count, elemType) \
{ \
	OFFSET(field), \
	0, \
	count, \
	elemType, \
	save_version_introduced, \
	9999, \
	#field \
}

#define POINTER_ENTRY(save_version_introduced, field, relativeToField) \
{ \
	OFFSET(field), \
	OFFSET(relativeToField), \
	4, \
	POINTER_V, \
	save_version_introduced, \
	9999, \
	#field \
}

#define OBSOLETE_INT_ENTRY(save_version_introduced, save_version_removed, field) \
{ \
	DUMMY(field), \
	0, \
	sizeof(((struct Obsolete *) NULL)->field), \
	INT_V, \
	save_version_introduced, \
	save_version_removed, \
	#field \
}

#define OBSOLETE_ARRAY_ENTRY(save_version_introduced, save_version_removed, field, count, elemType) \
{ \
	DUMMY(field), \
	0, \
	count, \
	elemType, \
	save_version_introduced, \
	save_version_removed, \
	#field \
}

#define OBSOLETE_POINTER_ENTRY(save_version_introduced, save_version_removed, field, relativeToField) \
{ \
	DUMMY(field), \
	DUMMY(relativeToField), \
	4, \
	POINTER_V, \
	save_version_introduced, \
	save_version_removed, \
	#field \
}

#define DELETED_INT_ENTRY(save_version_introduced, save_version_removed, field, size) \
{ \
	DELETED(field), \
	0, \
	size, \
	INT_V, \
	save_version_introduced, \
	save_version_removed, \
	#field \
}

#define DELETED_ARRAY_ENTRY(save_version_introduced, save_version_removed, field, count, elemType) \
{ \
	DELETED(field), \
	0, \
	count, \
	elemType, \
	save_version_introduced, \
	save_version_removed, \
	#field \
}

#define DELETED_POINTER_ENTRY(save_version_introduced, save_version_removed, field, relativeToField) \
{ \
	DELETED(field), \
	DELETED(relativeToField), \
	4, \
	POINTER_V, \
	save_version_introduced, \
	save_version_removed, \
	#field \
}

struct SDMASnapshot
{
	struct SDMA	dma[8];
};

static struct Obsolete
{
	uint8	reserved;
}	Obsolete;

#define STRUCT	struct SCPUState

static FreezeData	SnapCPU[] =
{
	INT_ENTRY(6, Cycles),
	INT_ENTRY(6, PrevCycles),
	INT_ENTRY(6, V_Counter),
	INT_ENTRY(6, Flags),
	INT_ENTRY(6, IRQActive),
	INT_ENTRY(6, IRQPending),
	INT_ENTRY(6, MemSpeed),
	INT_ENTRY(6, MemSpeedx2),
	INT_ENTRY(6, FastROMSpeed),
	INT_ENTRY(6, InDMA),
	INT_ENTRY(6, InHDMA),
	INT_ENTRY(6, InDMAorHDMA),
	INT_ENTRY(6, InWRAMDMAorHDMA),
	INT_ENTRY(6, HDMARanInDMA),
	INT_ENTRY(6, WhichEvent),
	INT_ENTRY(6, NextEvent),
	INT_ENTRY(6, WaitingForInterrupt),
};

#undef STRUCT
#define STRUCT	struct SRegisters

static FreezeData	SnapRegisters[] =
{
	INT_ENTRY(6, PB),
	INT_ENTRY(6, DB),
	INT_ENTRY(6, P.W),
	INT_ENTRY(6, A.W),
	INT_ENTRY(6, D.W),
	INT_ENTRY(6, S.W),
	INT_ENTRY(6, X.W),
	INT_ENTRY(6, Y.W),
	INT_ENTRY(6, PCw)
};

#undef STRUCT
#define STRUCT	struct SPPU

static FreezeData	SnapPPU[] =
{
	INT_ENTRY(6, VMA.High),
	INT_ENTRY(6, VMA.Increment),
	INT_ENTRY(6, VMA.Address),
	INT_ENTRY(6, VMA.Mask1),
	INT_ENTRY(6, VMA.FullGraphicCount),
	INT_ENTRY(6, VMA.Shift),
	INT_ENTRY(6, WRAM),
#define O(N) \
	INT_ENTRY(6, BG[N].SCBase), \
	INT_ENTRY(6, BG[N].HOffset), \
	INT_ENTRY(6, BG[N].VOffset), \
	INT_ENTRY(6, BG[N].BGSize), \
	INT_ENTRY(6, BG[N].NameBase), \
	INT_ENTRY(6, BG[N].SCSize)
	O(0), O(1), O(2), O(3),
#undef O
	INT_ENTRY(6, BGMode),
	INT_ENTRY(6, BG3Priority),
	INT_ENTRY(6, CGFLIP),
	INT_ENTRY(6, CGFLIPRead),
	INT_ENTRY(6, CGADD),
	ARRAY_ENTRY(6, CGDATA, 256, uint16_ARRAY_V),
#define O(N) \
	INT_ENTRY(6, OBJ[N].HPos), \
	INT_ENTRY(6, OBJ[N].VPos), \
	INT_ENTRY(6, OBJ[N].HFlip), \
	INT_ENTRY(6, OBJ[N].VFlip), \
	INT_ENTRY(6, OBJ[N].Name), \
	INT_ENTRY(6, OBJ[N].Priority), \
	INT_ENTRY(6, OBJ[N].Palette), \
	INT_ENTRY(6, OBJ[N].Size)
	O(  0), O(  1), O(  2), O(  3), O(  4), O(  5), O(  6), O(  7),
	O(  8), O(  9), O( 10), O( 11), O( 12), O( 13), O( 14), O( 15),
	O( 16), O( 17), O( 18), O( 19), O( 20), O( 21), O( 22), O( 23),
	O( 24), O( 25), O( 26), O( 27), O( 28), O( 29), O( 30), O( 31),
	O( 32), O( 33), O( 34), O( 35), O( 36), O( 37), O( 38), O( 39),
	O( 40), O( 41), O( 42), O( 43), O( 44), O( 45), O( 46), O( 47),
	O( 48), O( 49), O( 50), O( 51), O( 52), O( 53), O( 54), O( 55),
	O( 56), O( 57), O( 58), O( 59), O( 60), O( 61), O( 62), O( 63),
	O( 64), O( 65), O( 66), O( 67), O( 68), O( 69), O( 70), O( 71),
	O( 72), O( 73), O( 74), O( 75), O( 76), O( 77), O( 78), O( 79),
	O( 80), O( 81), O( 82), O( 83), O( 84), O( 85), O( 86), O( 87),
	O( 88), O( 89), O( 90), O( 91), O( 92), O( 93), O( 94), O( 95),
	O( 96), O( 97), O( 98), O( 99), O(100), O(101), O(102), O(103),
	O(104), O(105), O(106), O(107), O(108), O(109), O(110), O(111),
	O(112), O(113), O(114), O(115), O(116), O(117), O(118), O(119),
	O(120), O(121), O(122), O(123), O(124), O(125), O(126), O(127),
#undef O
	INT_ENTRY(6, OBJThroughMain),
	INT_ENTRY(6, OBJThroughSub),
	INT_ENTRY(6, OBJAddition),
	INT_ENTRY(6, OBJNameBase),
	INT_ENTRY(6, OBJNameSelect),
	INT_ENTRY(6, OBJSizeSelect),
	INT_ENTRY(6, OAMAddr),
	INT_ENTRY(6, SavedOAMAddr),
	INT_ENTRY(6, OAMPriorityRotation),
	INT_ENTRY(6, OAMFlip),
	INT_ENTRY(6, OAMReadFlip),
	INT_ENTRY(6, OAMTileAddress),
	INT_ENTRY(6, OAMWriteRegister),
	ARRAY_ENTRY(6, OAMData, 512 + 32, uint8_ARRAY_V),
	INT_ENTRY(6, FirstSprite),
	INT_ENTRY(6, LastSprite),
	INT_ENTRY(6, HTimerEnabled),
	INT_ENTRY(6, VTimerEnabled),
	INT_ENTRY(6, HTimerPosition),
	INT_ENTRY(6, VTimerPosition),
	INT_ENTRY(6, IRQHBeamPos),
	INT_ENTRY(6, IRQVBeamPos),
	INT_ENTRY(6, HBeamFlip),
	INT_ENTRY(6, VBeamFlip),
	INT_ENTRY(6, HBeamPosLatched),
	INT_ENTRY(6, VBeamPosLatched),
	INT_ENTRY(6, GunHLatch),
	INT_ENTRY(6, GunVLatch),
	INT_ENTRY(6, HVBeamCounterLatched),
	INT_ENTRY(6, Mode7HFlip),
	INT_ENTRY(6, Mode7VFlip),
	INT_ENTRY(6, Mode7Repeat),
	INT_ENTRY(6, MatrixA),
	INT_ENTRY(6, MatrixB),
	INT_ENTRY(6, MatrixC),
	INT_ENTRY(6, MatrixD),
	INT_ENTRY(6, CentreX),
	INT_ENTRY(6, CentreY),
	INT_ENTRY(6, M7HOFS),
	INT_ENTRY(6, M7VOFS),
	INT_ENTRY(6, Mosaic),
	INT_ENTRY(6, MosaicStart),
	ARRAY_ENTRY(6, BGMosaic, 4, uint8_ARRAY_V),
	INT_ENTRY(6, Window1Left),
	INT_ENTRY(6, Window1Right),
	INT_ENTRY(6, Window2Left),
	INT_ENTRY(6, Window2Right),
	INT_ENTRY(6, RecomputeClipWindows),
#define O(N) \
	INT_ENTRY(6, ClipCounts[N]), \
	INT_ENTRY(6, ClipWindowOverlapLogic[N]), \
	INT_ENTRY(6, ClipWindow1Enable[N]), \
	INT_ENTRY(6, ClipWindow2Enable[N]), \
	INT_ENTRY(6, ClipWindow1Inside[N]), \
	INT_ENTRY(6, ClipWindow2Inside[N])
	O(0), O(1), O(2), O(3), O(4), O(5),
#undef O
	INT_ENTRY(6, ForcedBlanking),
	INT_ENTRY(6, FixedColourRed),
	INT_ENTRY(6, FixedColourGreen),
	INT_ENTRY(6, FixedColourBlue),
	INT_ENTRY(6, Brightness),
	INT_ENTRY(6, ScreenHeight),
	INT_ENTRY(6, Need16x8Mulitply),
	INT_ENTRY(6, BGnxOFSbyte),
	INT_ENTRY(6, M7byte),
	INT_ENTRY(6, HDMA),
	INT_ENTRY(6, HDMAEnded),
	INT_ENTRY(6, OpenBus1),
	INT_ENTRY(6, OpenBus2)
};

#undef STRUCT
#define STRUCT	struct SDMASnapshot

static FreezeData	SnapDMA[] =
{
#define O(N) \
	INT_ENTRY(6, dma[N].ReverseTransfer), \
	INT_ENTRY(6, dma[N].HDMAIndirectAddressing), \
	INT_ENTRY(6, dma[N].UnusedBit43x0), \
	INT_ENTRY(6, dma[N].AAddressFixed), \
	INT_ENTRY(6, dma[N].AAddressDecrement), \
	INT_ENTRY(6, dma[N].TransferMode), \
	INT_ENTRY(6, dma[N].BAddress), \
	INT_ENTRY(6, dma[N].AAddress), \
	INT_ENTRY(6, dma[N].ABank), \
	INT_ENTRY(6, dma[N].DMACount_Or_HDMAIndirectAddress), \
	INT_ENTRY(6, dma[N].IndirectBank), \
	INT_ENTRY(6, dma[N].Address), \
	INT_ENTRY(6, dma[N].Repeat), \
	INT_ENTRY(6, dma[N].LineCount), \
	INT_ENTRY(6, dma[N].UnknownByte), \
	INT_ENTRY(6, dma[N].DoTransfer)
	O(0), O(1), O(2), O(3), O(4), O(5), O(6), O(7)
#undef O
};

#undef STRUCT
#define STRUCT	struct SControlSnapshot

static FreezeData	SnapControls[] =
{
	INT_ENTRY(6, ver),
	ARRAY_ENTRY(6, port1_read_idx, 2, uint8_ARRAY_V),
	ARRAY_ENTRY(6, dummy1, 4, uint8_ARRAY_V),
	ARRAY_ENTRY(6, port2_read_idx, 2, uint8_ARRAY_V),
	ARRAY_ENTRY(6, dummy2, 4, uint8_ARRAY_V),
	ARRAY_ENTRY(6, mouse_speed, 2, uint8_ARRAY_V),
	INT_ENTRY(6, justifier_select),
	ARRAY_ENTRY(6, dummy3, 8, uint8_ARRAY_V),
	INT_ENTRY(6, pad_read),
	ARRAY_ENTRY(6, internal, 60, uint8_ARRAY_V)
};

#undef STRUCT
#define STRUCT	struct STimings

static FreezeData	SnapTimings[] =
{
	INT_ENTRY(6, H_Max_Master),
	INT_ENTRY(6, H_Max),
	INT_ENTRY(6, V_Max_Master),
	INT_ENTRY(6, V_Max),
	INT_ENTRY(6, HBlankStart),
	INT_ENTRY(6, HBlankEnd),
	INT_ENTRY(6, HDMAInit),
	INT_ENTRY(6, HDMAStart),
	INT_ENTRY(6, NMITriggerPos),
	INT_ENTRY(6, WRAMRefreshPos),
	INT_ENTRY(6, RenderPos),
	INT_ENTRY(6, InterlaceField),
	INT_ENTRY(6, DMACPUSync),
	INT_ENTRY(6, NMIDMADelay),
	INT_ENTRY(6, IRQPendCount),
	INT_ENTRY(6, APUSpeedup)
};

#undef STRUCT
#define STRUCT	struct FxRegs_s

static FreezeData	SnapFX[] =
{
	ARRAY_ENTRY(6, avReg, 16, uint32_ARRAY_V),
	INT_ENTRY(6, vColorReg),
	INT_ENTRY(6, vPlotOptionReg),
	INT_ENTRY(6, vStatusReg),
	INT_ENTRY(6, vPrgBankReg),
	INT_ENTRY(6, vRomBankReg),
	INT_ENTRY(6, vRamBankReg),
	INT_ENTRY(6, vCacheBaseReg),
	INT_ENTRY(6, vCacheFlags),
	INT_ENTRY(6, vLastRamAdr),
	POINTER_ENTRY(6, pvDreg, avRegAddr),
	POINTER_ENTRY(6, pvSreg, avRegAddr),
	INT_ENTRY(6, vRomBuffer),
	INT_ENTRY(6, vPipe),
	INT_ENTRY(6, vPipeAdr),
	INT_ENTRY(6, vSign),
	INT_ENTRY(6, vZero),
	INT_ENTRY(6, vCarry),
	INT_ENTRY(6, vOverflow),
	INT_ENTRY(6, vErrorCode),
	INT_ENTRY(6, vIllegalAddress),
	INT_ENTRY(6, bBreakPoint),
	INT_ENTRY(6, vBreakPoint),
	INT_ENTRY(6, vStepPoint),
	INT_ENTRY(6, nRamBanks),
	INT_ENTRY(6, nRomBanks),
	INT_ENTRY(6, vMode),
	INT_ENTRY(6, vPrevMode),
	POINTER_ENTRY(6, pvScreenBase, pvRam),
#define O(N) \
	POINTER_ENTRY(6, apvScreen[N], pvRam)
	O(  0), O(  1), O(  2), O(  3), O(  4), O(  5), O(  6), O(  7),
	O(  8), O(  9), O( 10), O( 11), O( 12), O( 13), O( 14), O( 15),
	O( 16), O( 17), O( 18), O( 19), O( 20), O( 21), O( 22), O( 23),
	O( 24), O( 25), O( 26), O( 27), O( 28), O( 29), O( 30), O( 31),
#undef O
	ARRAY_ENTRY(6, x, 32, uint32_ARRAY_V),
	INT_ENTRY(6, vScreenHeight),
	INT_ENTRY(6, vScreenRealHeight),
	INT_ENTRY(6, vPrevScreenHeight),
	INT_ENTRY(6, vScreenSize),
	POINTER_ENTRY(6, pvRamBank, apvRamBank),
	POINTER_ENTRY(6, pvRomBank, apvRomBank),
	POINTER_ENTRY(6, pvPrgBank, apvRomBank),
#define O(N) \
	POINTER_ENTRY(6, apvRamBank[N], pvRam)
	O(0), O(1), O(2), O(3),
#undef O
	INT_ENTRY(6, bCacheActive),
	POINTER_ENTRY(6, pvCache, pvRegisters),
	ARRAY_ENTRY(6, avCacheBackup, 512, uint8_ARRAY_V),
	INT_ENTRY(6, vCounter),
	INT_ENTRY(6, vInstCount),
	INT_ENTRY(6, vSCBRDirty)
};

#undef STRUCT
#define STRUCT	struct SSA1

static FreezeData	SnapSA1[] =
{
	INT_ENTRY(6, ShiftedPB),
	INT_ENTRY(6, ShiftedDB),
	INT_ENTRY(6, Flags),
	INT_ENTRY(6, IRQActive),
	INT_ENTRY(6, WaitingForInterrupt),
	INT_ENTRY(6, overflow),
	INT_ENTRY(6, in_char_dma),
	INT_ENTRY(6, op1),
	INT_ENTRY(6, op2),
	INT_ENTRY(6, arithmetic_op),
	INT_ENTRY(6, sum),
	INT_ENTRY(6, VirtualBitmapFormat),
	INT_ENTRY(6, variable_bit_pos)
};

#undef STRUCT
#define STRUCT	struct SSA1Registers

static FreezeData	SnapSA1Registers[] =
{
	INT_ENTRY(6, PB),
	INT_ENTRY(6, DB),
	INT_ENTRY(6, P.W),
	INT_ENTRY(6, A.W),
	INT_ENTRY(6, D.W),
	INT_ENTRY(6, S.W),
	INT_ENTRY(6, X.W),
	INT_ENTRY(6, Y.W),
	INT_ENTRY(6, PCw)
};

#undef STRUCT
#define STRUCT	struct SDSP1

static FreezeData	SnapDSP1[] =
{
	INT_ENTRY(6, waiting4command),
	INT_ENTRY(6, first_parameter),
	INT_ENTRY(6, command),
	INT_ENTRY(6, in_count),
	INT_ENTRY(6, in_index),
	INT_ENTRY(6, out_count),
	INT_ENTRY(6, out_index),
	ARRAY_ENTRY(6, parameters, 512, uint8_ARRAY_V),
	ARRAY_ENTRY(6, output, 512, uint8_ARRAY_V),
	INT_ENTRY(6, CentreX),
	INT_ENTRY(6, CentreY),
	INT_ENTRY(6, VOffset),
	INT_ENTRY(6, VPlane_C),
	INT_ENTRY(6, VPlane_E),
	INT_ENTRY(6, SinAas),
	INT_ENTRY(6, CosAas),
	INT_ENTRY(6, SinAzs),
	INT_ENTRY(6, CosAzs),
	INT_ENTRY(6, SinAZS),
	INT_ENTRY(6, CosAZS),
	INT_ENTRY(6, SecAZS_C1),
	INT_ENTRY(6, SecAZS_E1),
	INT_ENTRY(6, SecAZS_C2),
	INT_ENTRY(6, SecAZS_E2),
	INT_ENTRY(6, Nx),
	INT_ENTRY(6, Ny),
	INT_ENTRY(6, Nz),
	INT_ENTRY(6, Gx),
	INT_ENTRY(6, Gy),
	INT_ENTRY(6, Gz),
	INT_ENTRY(6, C_Les),
	INT_ENTRY(6, E_Les),
	INT_ENTRY(6, G_Les),
#define O(N) \
	ARRAY_ENTRY(6, matrixA[N], 3, uint16_ARRAY_V), \
	ARRAY_ENTRY(6, matrixB[N], 3, uint16_ARRAY_V), \
	ARRAY_ENTRY(6, matrixC[N], 3, uint16_ARRAY_V)
	O(0), O(1), O(2),
#undef O
	INT_ENTRY(6, Op00Multiplicand),
	INT_ENTRY(6, Op00Multiplier),
	INT_ENTRY(6, Op00Result),
	INT_ENTRY(6, Op20Multiplicand),
	INT_ENTRY(6, Op20Multiplier),
	INT_ENTRY(6, Op20Result),
	INT_ENTRY(6, Op10Coefficient),
	INT_ENTRY(6, Op10Exponent),
	INT_ENTRY(6, Op10CoefficientR),
	INT_ENTRY(6, Op10ExponentR),
	INT_ENTRY(6, Op04Angle),
	INT_ENTRY(6, Op04Radius),
	INT_ENTRY(6, Op04Sin),
	INT_ENTRY(6, Op04Cos),
	INT_ENTRY(6, Op0CA),
	INT_ENTRY(6, Op0CX1),
	INT_ENTRY(6, Op0CY1),
	INT_ENTRY(6, Op0CX2),
	INT_ENTRY(6, Op0CY2),
	INT_ENTRY(6, Op02FX),
	INT_ENTRY(6, Op02FY),
	INT_ENTRY(6, Op02FZ),
	INT_ENTRY(6, Op02LFE),
	INT_ENTRY(6, Op02LES),
	INT_ENTRY(6, Op02AAS),
	INT_ENTRY(6, Op02AZS),
	INT_ENTRY(6, Op02VOF),
	INT_ENTRY(6, Op02VVA),
	INT_ENTRY(6, Op02CX),
	INT_ENTRY(6, Op02CY),
	INT_ENTRY(6, Op0AVS),
	INT_ENTRY(6, Op0AA),
	INT_ENTRY(6, Op0AB),
	INT_ENTRY(6, Op0AC),
	INT_ENTRY(6, Op0AD),
	INT_ENTRY(6, Op06X),
	INT_ENTRY(6, Op06Y),
	INT_ENTRY(6, Op06Z),
	INT_ENTRY(6, Op06H),
	INT_ENTRY(6, Op06V),
	INT_ENTRY(6, Op06M),
	INT_ENTRY(6, Op01m),
	INT_ENTRY(6, Op01Zr),
	INT_ENTRY(6, Op01Xr),
	INT_ENTRY(6, Op01Yr),
	INT_ENTRY(6, Op11m),
	INT_ENTRY(6, Op11Zr),
	INT_ENTRY(6, Op11Xr),
	INT_ENTRY(6, Op11Yr),
	INT_ENTRY(6, Op21m),
	INT_ENTRY(6, Op21Zr),
	INT_ENTRY(6, Op21Xr),
	INT_ENTRY(6, Op21Yr),
	INT_ENTRY(6, Op0DX),
	INT_ENTRY(6, Op0DY),
	INT_ENTRY(6, Op0DZ),
	INT_ENTRY(6, Op0DF),
	INT_ENTRY(6, Op0DL),
	INT_ENTRY(6, Op0DU),
	INT_ENTRY(6, Op1DX),
	INT_ENTRY(6, Op1DY),
	INT_ENTRY(6, Op1DZ),
	INT_ENTRY(6, Op1DF),
	INT_ENTRY(6, Op1DL),
	INT_ENTRY(6, Op1DU),
	INT_ENTRY(6, Op2DX),
	INT_ENTRY(6, Op2DY),
	INT_ENTRY(6, Op2DZ),
	INT_ENTRY(6, Op2DF),
	INT_ENTRY(6, Op2DL),
	INT_ENTRY(6, Op2DU),
	INT_ENTRY(6, Op03F),
	INT_ENTRY(6, Op03L),
	INT_ENTRY(6, Op03U),
	INT_ENTRY(6, Op03X),
	INT_ENTRY(6, Op03Y),
	INT_ENTRY(6, Op03Z),
	INT_ENTRY(6, Op13F),
	INT_ENTRY(6, Op13L),
	INT_ENTRY(6, Op13U),
	INT_ENTRY(6, Op13X),
	INT_ENTRY(6, Op13Y),
	INT_ENTRY(6, Op13Z),
	INT_ENTRY(6, Op23F),
	INT_ENTRY(6, Op23L),
	INT_ENTRY(6, Op23U),
	INT_ENTRY(6, Op23X),
	INT_ENTRY(6, Op23Y),
	INT_ENTRY(6, Op23Z),
	INT_ENTRY(6, Op14Zr),
	INT_ENTRY(6, Op14Xr),
	INT_ENTRY(6, Op14Yr),
	INT_ENTRY(6, Op14U),
	INT_ENTRY(6, Op14F),
	INT_ENTRY(6, Op14L),
	INT_ENTRY(6, Op14Zrr),
	INT_ENTRY(6, Op14Xrr),
	INT_ENTRY(6, Op14Yrr),
	INT_ENTRY(6, Op0EH),
	INT_ENTRY(6, Op0EV),
	INT_ENTRY(6, Op0EX),
	INT_ENTRY(6, Op0EY),
	INT_ENTRY(6, Op0BX),
	INT_ENTRY(6, Op0BY),
	INT_ENTRY(6, Op0BZ),
	INT_ENTRY(6, Op0BS),
	INT_ENTRY(6, Op1BX),
	INT_ENTRY(6, Op1BY),
	INT_ENTRY(6, Op1BZ),
	INT_ENTRY(6, Op1BS),
	INT_ENTRY(6, Op2BX),
	INT_ENTRY(6, Op2BY),
	INT_ENTRY(6, Op2BZ),
	INT_ENTRY(6, Op2BS),
	INT_ENTRY(6, Op28X),
	INT_ENTRY(6, Op28Y),
	INT_ENTRY(6, Op28Z),
	INT_ENTRY(6, Op28R),
	INT_ENTRY(6, Op1CX),
	INT_ENTRY(6, Op1CY),
	INT_ENTRY(6, Op1CZ),
	INT_ENTRY(6, Op1CXBR),
	INT_ENTRY(6, Op1CYBR),
	INT_ENTRY(6, Op1CZBR),
	INT_ENTRY(6, Op1CXAR),
	INT_ENTRY(6, Op1CYAR),
	INT_ENTRY(6, Op1CZAR),
	INT_ENTRY(6, Op1CX1),
	INT_ENTRY(6, Op1CY1),
	INT_ENTRY(6, Op1CZ1),
	INT_ENTRY(6, Op1CX2),
	INT_ENTRY(6, Op1CY2),
	INT_ENTRY(6, Op1CZ2),
	INT_ENTRY(6, Op0FRamsize),
	INT_ENTRY(6, Op0FPass),
	INT_ENTRY(6, Op2FUnknown),
	INT_ENTRY(6, Op2FSize),
	INT_ENTRY(6, Op08X),
	INT_ENTRY(6, Op08Y),
	INT_ENTRY(6, Op08Z),
	INT_ENTRY(6, Op08Ll),
	INT_ENTRY(6, Op08Lh),
	INT_ENTRY(6, Op18X),
	INT_ENTRY(6, Op18Y),
	INT_ENTRY(6, Op18Z),
	INT_ENTRY(6, Op18R),
	INT_ENTRY(6, Op18D),
	INT_ENTRY(6, Op38X),
	INT_ENTRY(6, Op38Y),
	INT_ENTRY(6, Op38Z),
	INT_ENTRY(6, Op38R),
	INT_ENTRY(6, Op38D)
};

#undef STRUCT
#define STRUCT	struct SDSP2

static FreezeData	SnapDSP2[] =
{
	INT_ENTRY(6, waiting4command),
	INT_ENTRY(6, command),
	INT_ENTRY(6, in_count),
	INT_ENTRY(6, in_index),
	INT_ENTRY(6, out_count),
	INT_ENTRY(6, out_index),
	ARRAY_ENTRY(6, parameters, 512, uint8_ARRAY_V),
	ARRAY_ENTRY(6, output, 512, uint8_ARRAY_V),
	INT_ENTRY(6, Op05HasLen),
	INT_ENTRY(6, Op05Len),
	INT_ENTRY(6, Op05Transparent),
	INT_ENTRY(6, Op06HasLen),
	INT_ENTRY(6, Op06Len),
	INT_ENTRY(6, Op09Word1),
	INT_ENTRY(6, Op09Word2),
	INT_ENTRY(6, Op0DHasLen),
	INT_ENTRY(6, Op0DOutLen),
	INT_ENTRY(6, Op0DInLen)
};

#undef STRUCT
#define STRUCT	struct SDSP4

static FreezeData	SnapDSP4[] =
{
	INT_ENTRY(6, waiting4command),
	INT_ENTRY(6, half_command),
	INT_ENTRY(6, command),
	INT_ENTRY(6, in_count),
	INT_ENTRY(6, in_index),
	INT_ENTRY(6, out_count),
	INT_ENTRY(6, out_index),
	ARRAY_ENTRY(6, parameters, 512, uint8_ARRAY_V),
	ARRAY_ENTRY(6, output, 512, uint8_ARRAY_V),
	INT_ENTRY(6, byte),
	INT_ENTRY(6, address),
	INT_ENTRY(6, Logic),
	INT_ENTRY(6, lcv),
	INT_ENTRY(6, distance),
	INT_ENTRY(6, raster),
	INT_ENTRY(6, segments),
	INT_ENTRY(6, world_x),
	INT_ENTRY(6, world_y),
	INT_ENTRY(6, world_dx),
	INT_ENTRY(6, world_dy),
	INT_ENTRY(6, world_ddx),
	INT_ENTRY(6, world_ddy),
	INT_ENTRY(6, world_xenv),
	INT_ENTRY(6, world_yofs),
	INT_ENTRY(6, view_x1),
	INT_ENTRY(6, view_y1),
	INT_ENTRY(6, view_x2),
	INT_ENTRY(6, view_y2),
	INT_ENTRY(6, view_dx),
	INT_ENTRY(6, view_dy),
	INT_ENTRY(6, view_xofs1),
	INT_ENTRY(6, view_yofs1),
	INT_ENTRY(6, view_xofs2),
	INT_ENTRY(6, view_yofs2),
	INT_ENTRY(6, view_yofsenv),
	INT_ENTRY(6, view_turnoff_x),
	INT_ENTRY(6, view_turnoff_dx),
	INT_ENTRY(6, viewport_cx),
	INT_ENTRY(6, viewport_cy),
	INT_ENTRY(6, viewport_left),
	INT_ENTRY(6, viewport_right),
	INT_ENTRY(6, viewport_top),
	INT_ENTRY(6, viewport_bottom),
	INT_ENTRY(6, sprite_x),
	INT_ENTRY(6, sprite_y),
	INT_ENTRY(6, sprite_attr),
	INT_ENTRY(6, sprite_size),
	INT_ENTRY(6, sprite_clipy),
	INT_ENTRY(6, sprite_count),
#define O(N) \
	ARRAY_ENTRY(6, poly_clipLf[N], 2, uint16_ARRAY_V), \
	ARRAY_ENTRY(6, poly_clipRt[N], 2, uint16_ARRAY_V), \
	ARRAY_ENTRY(6, poly_ptr[N], 2, uint16_ARRAY_V), \
	ARRAY_ENTRY(6, poly_raster[N], 2, uint16_ARRAY_V), \
	ARRAY_ENTRY(6, poly_top[N], 2, uint16_ARRAY_V), \
	ARRAY_ENTRY(6, poly_bottom[N], 2, uint16_ARRAY_V), \
	ARRAY_ENTRY(6, poly_cx[N], 2, uint16_ARRAY_V)
	O(0), O(1),
#undef O
	ARRAY_ENTRY(6, poly_start, 2, uint16_ARRAY_V),
	ARRAY_ENTRY(6, poly_plane, 2, uint16_ARRAY_V),
	ARRAY_ENTRY(6, OAM_attr, 16, uint16_ARRAY_V),
	INT_ENTRY(6, OAM_index),
	INT_ENTRY(6, OAM_bits),
	INT_ENTRY(6, OAM_RowMax),
	ARRAY_ENTRY(6, OAM_Row, 32, uint16_ARRAY_V)
};

#undef STRUCT
#define STRUCT	struct SST010

static FreezeData	SnapST010[] =
{
	ARRAY_ENTRY(6, input_params, 16, uint8_ARRAY_V),
	ARRAY_ENTRY(6, output_params, 16, uint8_ARRAY_V),
	INT_ENTRY(6, op_reg),
	INT_ENTRY(6, execute),
	INT_ENTRY(6, control_enable)
};

#undef STRUCT
#define STRUCT	struct SOBC1

static FreezeData	SnapOBC1[] =
{
	INT_ENTRY(6, address),
	INT_ENTRY(6, basePtr),
	INT_ENTRY(6, shift)
};

#undef STRUCT
#define STRUCT	struct SSPC7110Snapshot

static FreezeData	SnapSPC7110Snap[] =
{
	INT_ENTRY(6, r4801),
	INT_ENTRY(6, r4802),
	INT_ENTRY(6, r4803),
	INT_ENTRY(6, r4804),
	INT_ENTRY(6, r4805),
	INT_ENTRY(6, r4806),
	INT_ENTRY(6, r4807),
	INT_ENTRY(6, r4808),
	INT_ENTRY(6, r4809),
	INT_ENTRY(6, r480a),
	INT_ENTRY(6, r480b),
	INT_ENTRY(6, r480c),
	INT_ENTRY(6, r4811),
	INT_ENTRY(6, r4812),
	INT_ENTRY(6, r4813),
	INT_ENTRY(6, r4814),
	INT_ENTRY(6, r4815),
	INT_ENTRY(6, r4816),
	INT_ENTRY(6, r4817),
	INT_ENTRY(6, r4818),
	INT_ENTRY(6, r481x),
	INT_ENTRY(6, r4814_latch),
	INT_ENTRY(6, r4815_latch),
	INT_ENTRY(6, r4820),
	INT_ENTRY(6, r4821),
	INT_ENTRY(6, r4822),
	INT_ENTRY(6, r4823),
	INT_ENTRY(6, r4824),
	INT_ENTRY(6, r4825),
	INT_ENTRY(6, r4826),
	INT_ENTRY(6, r4827),
	INT_ENTRY(6, r4828),
	INT_ENTRY(6, r4829),
	INT_ENTRY(6, r482a),
	INT_ENTRY(6, r482b),
	INT_ENTRY(6, r482c),
	INT_ENTRY(6, r482d),
	INT_ENTRY(6, r482e),
	INT_ENTRY(6, r482f),
	INT_ENTRY(6, r4830),
	INT_ENTRY(6, r4831),
	INT_ENTRY(6, r4832),
	INT_ENTRY(6, r4833),
	INT_ENTRY(6, r4834),
	INT_ENTRY(6, dx_offset),
	INT_ENTRY(6, ex_offset),
	INT_ENTRY(6, fx_offset),
	INT_ENTRY(6, r4840),
	INT_ENTRY(6, r4841),
	INT_ENTRY(6, r4842),
	INT_ENTRY(6, rtc_state),
	INT_ENTRY(6, rtc_mode),
	INT_ENTRY(6, rtc_index),
	INT_ENTRY(6, decomp_mode),
	INT_ENTRY(6, decomp_offset),
	ARRAY_ENTRY(6, decomp_buffer, SPC7110_DECOMP_BUFFER_SIZE, uint8_ARRAY_V),
	INT_ENTRY(6, decomp_buffer_rdoffset),
	INT_ENTRY(6, decomp_buffer_wroffset),
	INT_ENTRY(6, decomp_buffer_length),
#define O(N) \
	INT_ENTRY(6, context[N].index), \
	INT_ENTRY(6, context[N].invert)
	O(  0), O(  1), O(  2), O(  3), O(  4), O(  5), O(  6), O(  7),
	O(  8), O(  9), O( 10), O( 11), O( 12), O( 13), O( 14), O( 15),
	O( 16), O( 17), O( 18), O( 19), O( 20), O( 21), O( 22), O( 23),
	O( 24), O( 25), O( 26), O( 27), O( 28), O( 29), O( 30), O( 31)
#undef O
};

#undef STRUCT
#define STRUCT	struct SSRTCSnapshot

static FreezeData	SnapSRTCSnap[] =
{
	INT_ENTRY(6, rtc_mode),
	INT_ENTRY(6, rtc_index)
};

#undef STRUCT
#define STRUCT	struct SBSX

static FreezeData	SnapBSX[] =
{
	INT_ENTRY(6, dirty),
	INT_ENTRY(6, dirty2),
	INT_ENTRY(6, bootup),
	INT_ENTRY(6, flash_enable),
	INT_ENTRY(6, write_enable),
	INT_ENTRY(6, read_enable),
	INT_ENTRY(6, flash_command),
	INT_ENTRY(6, old_write),
	INT_ENTRY(6, new_write),
	INT_ENTRY(6, out_index),
	ARRAY_ENTRY(6, output, 32, uint8_ARRAY_V),
	ARRAY_ENTRY(6, PPU, 32, uint8_ARRAY_V),
	ARRAY_ENTRY(6, MMC, 16, uint8_ARRAY_V),
	ARRAY_ENTRY(6, prevMMC, 16, uint8_ARRAY_V),
	ARRAY_ENTRY(6, test2192, 32, uint8_ARRAY_V)
};

static bool8 S9xOpenSnapshotFile(STREAM *file)
{
   if((*file = OPEN_STREAM()) != 0)
      return (TRUE);
   return (FALSE);
}

static void FreezeBlock (STREAM stream, const char *name, uint8 *block, int size)
{
	char	buffer[20];

	/* check if it fits in 6 digits. (letting it go over and using strlen isn't safe)*/
	if (size <= 999999)
		sprintf(buffer, "%s:%06d:", name, size);
	else
	{
		/* to make it fit, pack it in the bytes instead of as digits*/
		sprintf(buffer, "%s:------:", name);
		buffer[6] = (unsigned char) ((unsigned) size >> 24);
		buffer[7] = (unsigned char) ((unsigned) size >> 16);
		buffer[8] = (unsigned char) ((unsigned) size >> 8);
		buffer[9] = (unsigned char) ((unsigned) size);
	}

	buffer[11] = 0;

	WRITE_STREAM(buffer, 11, stream);
	WRITE_STREAM(block, (uint64_t)size, stream);
}

static int FreezeSize (int size, int type)
{
	switch (type)
	{
		case uint32_ARRAY_V:
		case uint32_INDIR_ARRAY_V:
			return (size * 4);

		case uint16_ARRAY_V:
		case uint16_INDIR_ARRAY_V:
			return (size * 2);

		default:
			return (size);
	}
}

static void FreezeStruct (STREAM stream, const char *name, void *base, FreezeData *fields, int num_fields)
{
	uint8	*addr, *block, *ptr;
	uint16	word;
	uint32	dword;
	int64	qaword;
	int	len, i, j, relativeAddr;

	len  = 0;

	for (i = 0; i < num_fields; i++)
	{
		if (SNAPSHOT_VERSION < fields[i].debuted_in)
			continue;

		if (SNAPSHOT_VERSION < fields[i].deleted_in)
			len += FreezeSize(fields[i].size, fields[i].type);
	}

	block = (uint8*)malloc(len);
	ptr = block;

	for (i = 0; i < num_fields; i++)
	{
		if (SNAPSHOT_VERSION >= fields[i].deleted_in || SNAPSHOT_VERSION < fields[i].debuted_in)
			continue;

		addr = (uint8 *) base + fields[i].offset;

		/* determine real address of indirect-type fields*/
		/* (where the structure contains a pointer to an array rather than the array itself)*/
		if (fields[i].type == uint8_INDIR_ARRAY_V || fields[i].type == uint16_INDIR_ARRAY_V || fields[i].type == uint32_INDIR_ARRAY_V)
			addr = (uint8 *) (*((intptr_t *) addr));

		/* convert pointer-type saves from absolute to relative pointers*/
		if (fields[i].type == POINTER_V)
		{
			uint8	*pointer    = (uint8 *) *((intptr_t *) ((uint8 *) base + fields[i].offset));
			uint8	*relativeTo = (uint8 *) *((intptr_t *) ((uint8 *) base + fields[i].offset2));
			relativeAddr = pointer - relativeTo;
			addr = (uint8 *) &relativeAddr;
		}

		switch (fields[i].type)
		{
			case INT_V:
			case POINTER_V:
				switch (fields[i].size)
				{
					case 1:
						*ptr++ = *(addr);
						break;

					case 2:
						word = *((uint16 *) (addr));
						*ptr++ = (uint8) (word >> 8);
						*ptr++ = (uint8) word;
						break;

					case 4:
						dword = *((uint32 *) (addr));
						*ptr++ = (uint8) (dword >> 24);
						*ptr++ = (uint8) (dword >> 16);
						*ptr++ = (uint8) (dword >> 8);
						*ptr++ = (uint8) dword;
						break;

					case 8:
						qaword = *((int64 *) (addr));
						*ptr++ = (uint8) (qaword >> 56);
						*ptr++ = (uint8) (qaword >> 48);
						*ptr++ = (uint8) (qaword >> 40);
						*ptr++ = (uint8) (qaword >> 32);
						*ptr++ = (uint8) (qaword >> 24);
						*ptr++ = (uint8) (qaword >> 16);
						*ptr++ = (uint8) (qaword >> 8);
						*ptr++ = (uint8) qaword;
						break;
				}

				break;

			case uint8_ARRAY_V:
			case uint8_INDIR_ARRAY_V:
				memcpy(ptr, addr, fields[i].size);
				ptr += fields[i].size;

				break;

			case uint16_ARRAY_V:
			case uint16_INDIR_ARRAY_V:
				for (j = 0; j < fields[i].size; j++)
				{
					word = *((uint16 *) (addr + j * 2));
					*ptr++ = (uint8) (word >> 8);
					*ptr++ = (uint8) word;
				}

				break;

			case uint32_ARRAY_V:
			case uint32_INDIR_ARRAY_V:
				for (j = 0; j < fields[i].size; j++)
				{
					dword = *((uint32 *) (addr + j * 4));
					*ptr++ = (uint8) (dword >> 24);
					*ptr++ = (uint8) (dword >> 16);
					*ptr++ = (uint8) (dword >> 8);
					*ptr++ = (uint8) dword;
				}

				break;
		}
	}

	FreezeBlock(stream, name, block, len);
	free(block);
}

void S9xFreezeToStream (STREAM stream)
{
	struct SDMASnapshot	dma_snap;
	struct SControlSnapshot	ctl_snap;
	char	buffer[1024];
	static uint8	soundsnapshot[SPC_SAVE_STATE_BLOCK_SIZE];

        S9xPackStatus();

	snprintf(buffer, sizeof(buffer), "%s:%04d\n", SNAPSHOT_MAGIC, SNAPSHOT_VERSION);
	WRITE_STREAM(buffer, (uint64_t)strlen(buffer), stream);

	strcpy(buffer, "NAM:000001:");
	WRITE_STREAM(buffer, (uint64_t)strlen(buffer) + 1, stream);

	FreezeStruct(stream, "CPU", &CPU, SnapCPU, COUNT(SnapCPU));

	FreezeStruct(stream, "REG", &Registers, SnapRegisters, COUNT(SnapRegisters));

	FreezeStruct(stream, "PPU", &PPU, SnapPPU, COUNT(SnapPPU));

	dma_snap.dma[0] = DMA[0];
	dma_snap.dma[1] = DMA[1];
	dma_snap.dma[2] = DMA[2];
	dma_snap.dma[3] = DMA[3];
	dma_snap.dma[4] = DMA[4];
	dma_snap.dma[5] = DMA[5];
	dma_snap.dma[6] = DMA[6];
	dma_snap.dma[7] = DMA[7];

	FreezeStruct(stream, "DMA", &dma_snap, SnapDMA, COUNT(SnapDMA));

	FreezeBlock (stream, "VRA", Memory.VRAM, 0x10000);

	FreezeBlock (stream, "RAM", Memory.RAM, 0x20000);

	FreezeBlock (stream, "SRA", Memory.SRAM, 0x80000);

	FreezeBlock (stream, "FIL", Memory.FillRAM, 0x8000);

	S9xAPUSaveState(soundsnapshot);
	FreezeBlock (stream, "SND", soundsnapshot, SPC_SAVE_STATE_BLOCK_SIZE);

	S9xControlPreSaveState(&ctl_snap);
	FreezeStruct(stream, "CTL", &ctl_snap, SnapControls, COUNT(SnapControls));

	FreezeStruct(stream, "TIM", &Timings, SnapTimings, COUNT(SnapTimings));

	if (Settings.SuperFX)
	{
		GSU.avRegAddr = (uint8 *) &GSU.avReg;
		FreezeStruct(stream, "SFX", &GSU, SnapFX, COUNT(SnapFX));
	}

	if (Settings.SA1)
	{
		S9xSA1PackStatus();
		FreezeStruct(stream, "SA1", &SA1, SnapSA1, COUNT(SnapSA1));
		FreezeStruct(stream, "SAR", &SA1Registers, SnapSA1Registers, COUNT(SnapSA1Registers));
	}

	if (Settings.DSP == 1)
		FreezeStruct(stream, "DP1", &DSP1, SnapDSP1, COUNT(SnapDSP1));

	if (Settings.DSP == 2)
		FreezeStruct(stream, "DP2", &DSP2, SnapDSP2, COUNT(SnapDSP2));

	if (Settings.DSP == 4)
		FreezeStruct(stream, "DP4", &DSP4, SnapDSP4, COUNT(SnapDSP4));

	if (Settings.C4)
		FreezeBlock (stream, "CX4", Memory.C4RAM, 8192);

	if (Settings.SETA == ST_010)
		FreezeStruct(stream, "ST0", &ST010, SnapST010, COUNT(SnapST010));

	if (Settings.OBC1)
	{
		FreezeStruct(stream, "OBC", &OBC1, SnapOBC1, COUNT(SnapOBC1));
		FreezeBlock (stream, "OBM", Memory.OBC1RAM, 8192);
	}

	if (Settings.SPC7110)
	{
		S9xSPC7110PreSaveState();
		FreezeStruct(stream, "S71", &s7snap, SnapSPC7110Snap, COUNT(SnapSPC7110Snap));
	}

	if (Settings.SRTC)
	{
		S9xSRTCPreSaveState();
		FreezeStruct(stream, "SRT", &srtcsnap, SnapSRTCSnap, COUNT(SnapSRTCSnap));
	}

	if (Settings.SRTC || Settings.SPC7110RTC)
		FreezeBlock (stream, "CLK", RTCData.reg, 20);

	if (Settings.BS)
		FreezeStruct(stream, "BSX", &BSX, SnapBSX, COUNT(SnapBSX));
}

bool8 S9xFreezeGame (void)
{
	STREAM	stream = NULL;

	if (S9xOpenSnapshotFile(&stream))
	{
		S9xFreezeToStream(stream);
		CLOSE_STREAM(stream);

		return (TRUE);
	}

	return (FALSE);
}

bool8 S9xUnfreezeGame (void)
{
	STREAM stream = NULL;

	if (S9xOpenSnapshotFile(&stream))
	{
		int result = S9xUnfreezeFromStream(stream);
		CLOSE_STREAM(stream);

		if (result == SUCCESS)
			return (TRUE);
	}

	return (FALSE);
}

static bool CheckBlockName(STREAM stream, const char *name, int *len)
{
	char	buffer[16];
	uint64_t rewind = FIND_STREAM(stream);
	uint64_t l      = READ_STREAM(buffer, (uint64_t)11, stream);

	buffer[l]       = 0;

	*len            = 0;

   (void)rewind;

	REVERT_STREAM(stream, FIND_STREAM(stream) - l, 0);

	if (buffer[4] == '-')
	{
		*len = (((unsigned char)buffer[6]) << 24)
			| (((unsigned char)buffer[7]) << 16)
			| (((unsigned char)buffer[8]) << 8)
			| (((unsigned char)buffer[9]) << 0);
	}
	else
		*len = atoi(buffer + 4);

	if (l != 11 || strncmp(buffer, name, 3) != 0 || buffer[3] != ':')
		return false;

	if (*len <= 0)
		return false;

	return true;
}

static void SkipBlockWithName(STREAM stream, const char *name)
{
	int len;
	bool matchesName = CheckBlockName(stream, name, &len);
	if (matchesName)
	{
		uint64_t rewind  = FIND_STREAM(stream);
		rewind          += len + 11;
		REVERT_STREAM(stream, rewind, 0);
	}
}

static int UnfreezeBlock (STREAM stream, const char *name, uint8 *block, int size)
{
	char	buffer[20];
   uint64_t len    = 0;
   uint64_t rem    = 0;
	uint64_t	rewind = FIND_STREAM(stream);
	uint64_t   l    = READ_STREAM(buffer, 11, stream);

	buffer[l]       = 0;

	if (l != 11 || strncmp(buffer, name, 3) != 0 || buffer[3] != ':')
   {
err:
      /*fprintf(stdout, "absent: %s(%d); next: '%.11s'\n", name, size, buffer);*/
      REVERT_STREAM(stream, FIND_STREAM(stream) - l, 0);
      return (WRONG_FORMAT);
   }

	if (buffer[4] == '-')
	{
		len = (((unsigned char) buffer[6]) << 24)
			| (((unsigned char) buffer[7]) << 16)
			| (((unsigned char) buffer[8]) << 8)
			| (((unsigned char) buffer[9]) << 0);
	}
	else
		len = (uint64_t)atoi(buffer + 4);

	if (len <= 0)
		goto err;

	if (len > size)
	{
		rem = len - size;
		len = size;
	}

	if (!Settings.FastSavestates)
		memset(block, 0, size);

	if (READ_STREAM(block, len, stream) != len)
	{
		REVERT_STREAM(stream, rewind, 0);
		return (WRONG_FORMAT);
	}

	if (rem)
	{
		char *junk = (char*)malloc((size_t)rem);
		len = READ_STREAM(junk, rem, stream);
		free(junk);
		if (len != rem)
		{
			REVERT_STREAM(stream, rewind, 0);
			return (WRONG_FORMAT);
		}
	}

	return (SUCCESS);
}

static int UnfreezeBlockCopy (STREAM stream, const char *name, uint8 **block, int size)
{
	int	result;

	/* check block name first to avoid memory allocation */
	int blockLength;
	if (!CheckBlockName(stream, name, &blockLength))
	{
		return 0;
	}

	*block = (uint8*)malloc(size);

	result = UnfreezeBlock(stream, name, *block, size);
	if (result != SUCCESS)
	{
		free(*block);
		*block = NULL;
		return (result);
	}

	return SUCCESS;
}

static int UnfreezeStructCopy (STREAM stream, const char *name, uint8 **block, FreezeData *fields, int num_fields, int version)
{
	int i;
	int len = 0;

	for ( i = 0; i < num_fields; i++)
	{
		if (version >= fields[i].debuted_in && version < fields[i].deleted_in)
			len += FreezeSize(fields[i].size, fields[i].type);
	}

	return (UnfreezeBlockCopy(stream, name, block, len));
}

static void UnfreezeStructFromCopy (void *sbase, FreezeData *fields, int num_fields, uint8 *block, int version)
{
	uint8	*ptr = block;
	uint16	word;
	uint32	dword;
	int64	qaword;
	uint8	*addr, *relativeTo;
	void	*base;
	int	relativeAddr;
	int	i, j;

	for (i = 0; i < num_fields; i++)
	{
		if (version < fields[i].debuted_in || version >= fields[i].deleted_in)
			continue;

		base = (SNAPSHOT_VERSION >= fields[i].deleted_in) ? ((void *) &Obsolete) : sbase;
		addr = (uint8 *) base + fields[i].offset;

		if (fields[i].type == uint8_INDIR_ARRAY_V || fields[i].type == uint16_INDIR_ARRAY_V || fields[i].type == uint32_INDIR_ARRAY_V)
			addr = (uint8 *) (*((intptr_t *) addr));

		switch (fields[i].type)
		{
			case INT_V:
			case POINTER_V:
				switch (fields[i].size)
				{
					case 1:
						if (fields[i].offset < 0)
						{
							ptr++; 
							break;
						}

						*(addr) = *ptr++;
						break;

					case 2:
						if (fields[i].offset < 0)
						{
							ptr += 2;
							break;
						}

						word  = *ptr++ << 8;
						word |= *ptr++;
						*((uint16 *) (addr)) = word;
						break;

					case 4:
						if (fields[i].offset < 0)
						{
							ptr += 4;
							break;
						}

						dword  = *ptr++ << 24;
						dword |= *ptr++ << 16;
						dword |= *ptr++ << 8;
						dword |= *ptr++;
						*((uint32 *) (addr)) = dword;
						break;

					case 8:
						if (fields[i].offset < 0)
						{
							ptr += 8;
							break;
						}

						qaword  = (int64) *ptr++ << 56;
						qaword |= (int64) *ptr++ << 48;
						qaword |= (int64) *ptr++ << 40;
						qaword |= (int64) *ptr++ << 32;
						qaword |= (int64) *ptr++ << 24;
						qaword |= (int64) *ptr++ << 16;
						qaword |= (int64) *ptr++ << 8;
						qaword |= (int64) *ptr++;
						*((int64 *) (addr)) = qaword;
						break;

					default:
						break;
				}

				break;

			case uint8_ARRAY_V:
			case uint8_INDIR_ARRAY_V:
				if (fields[i].offset >= 0)
					memcpy(addr, ptr, fields[i].size);
				ptr += fields[i].size;

				break;

			case uint16_ARRAY_V:
			case uint16_INDIR_ARRAY_V:
				if (fields[i].offset < 0)
				{
					ptr += fields[i].size * 2;
					break;
				}

				for (j = 0; j < fields[i].size; j++)
				{
					word  = *ptr++ << 8;
					word |= *ptr++;
					*((uint16 *) (addr + j * 2)) = word;
				}

				break;

			case uint32_ARRAY_V:
			case uint32_INDIR_ARRAY_V:
				if (fields[i].offset < 0)
				{
					ptr += fields[i].size * 4;
					break;
				}

				for (j = 0; j < fields[i].size; j++)
				{
					dword  = *ptr++ << 24;
					dword |= *ptr++ << 16;
					dword |= *ptr++ << 8;
					dword |= *ptr++;
					*((uint32 *) (addr + j * 4)) = dword;
				}

				break;
		}

		if (fields[i].type == POINTER_V)
		{
			relativeAddr = (int) *((intptr_t *) ((uint8 *) base + fields[i].offset));
			relativeTo = (uint8 *) *((intptr_t *) ((uint8 *) base + fields[i].offset2));
			*((intptr_t *) (addr)) = (intptr_t) (relativeTo + relativeAddr);
		}
	}
}

int S9xUnfreezeFromStream (STREAM stream)
{
	const bool8 fast = Settings.FastSavestates;

	struct SDMASnapshot	dma_snap;
	struct SControlSnapshot	ctl_snap;
	int		version;
	char		buffer[PATH_MAX + 1];
	uint8		hdma_byte;
	int		result            = SUCCESS;
	uint8 *local_cpu           = NULL;
	uint8 *local_registers     = NULL;
	uint8 *local_ppu           = NULL;
	uint8 *local_dma           = NULL;
	uint8 *local_vram          = NULL;
	uint8 *local_ram           = NULL;
	uint8 *local_sram          = NULL;
	uint8 *local_fillram       = NULL;
	uint8 *local_apu_sound     = NULL;
	uint8 *local_control_data  = NULL;
	uint8 *local_timing_data   = NULL;
	uint8 *local_superfx       = NULL;
	uint8 *local_sa1           = NULL;
	uint8 *local_sa1_registers = NULL;
	uint8 *local_dsp1          = NULL;
	uint8 *local_dsp2          = NULL;
	uint8 *local_dsp4          = NULL;
	uint8 *local_cx4_data      = NULL;
	uint8 *local_st010         = NULL;
	uint8 *local_obc1          = NULL;
	uint8 *local_obc1_data     = NULL;
	uint8 *local_spc7110       = NULL;
	uint8 *local_srtc          = NULL;
	uint8 *local_rtc_data      = NULL;
	uint8 *local_bsx_data      = NULL;
	uint64_t len               = (uint64_t)strlen(SNAPSHOT_MAGIC) + 1 + 4 + 1;

	if (READ_STREAM(buffer, len, stream) != len)
		return (WRONG_FORMAT);

	if (strncmp(buffer, SNAPSHOT_MAGIC, strlen(SNAPSHOT_MAGIC)) != 0)
		return (WRONG_FORMAT);

	version = atoi(&buffer[strlen(SNAPSHOT_MAGIC) + 1]);
	if (version > SNAPSHOT_VERSION)
		return (WRONG_VERSION);

	result = UnfreezeBlock(stream, "NAM", (uint8 *) buffer, PATH_MAX);
	if (result != SUCCESS)
		return (result);


	do
	{
		result = UnfreezeStructCopy(stream, "CPU", &local_cpu, SnapCPU, COUNT(SnapCPU), version);
		if (result != SUCCESS)
			break;

		result = UnfreezeStructCopy(stream, "REG", &local_registers, SnapRegisters, COUNT(SnapRegisters), version);
		if (result != SUCCESS)
			break;

		result = UnfreezeStructCopy(stream, "PPU", &local_ppu, SnapPPU, COUNT(SnapPPU), version);
		if (result != SUCCESS)
			break;

		result = UnfreezeStructCopy(stream, "DMA", &local_dma, SnapDMA, COUNT(SnapDMA), version);
		if (result != SUCCESS)
			break;

		if (fast)
			result = UnfreezeBlock(stream, "VRA", Memory.VRAM, 0x10000);
		else
			result = UnfreezeBlockCopy(stream, "VRA", &local_vram, 0x10000);
		if (result != SUCCESS)
			break;

		if (fast)
			result = UnfreezeBlock(stream, "RAM", Memory.RAM, 0x20000);
		else
			result = UnfreezeBlockCopy(stream, "RAM", &local_ram, 0x20000);
		if (result != SUCCESS)
			break;

		if (fast)
			result = UnfreezeBlock(stream, "SRA", Memory.SRAM, 0x80000);
		else
		result = UnfreezeBlockCopy (stream, "SRA", &local_sram, 0x80000);
		if (result != SUCCESS)
			break;

		if (fast)
			result = UnfreezeBlock(stream, "FIL", Memory.FillRAM, 0x8000);
		else
			result = UnfreezeBlockCopy(stream, "FIL", &local_fillram, 0x8000);
		if (result != SUCCESS)
			break;

		result = UnfreezeBlockCopy (stream, "SND", &local_apu_sound, SPC_SAVE_STATE_BLOCK_SIZE);
		if (result != SUCCESS)
			break;

		result = UnfreezeStructCopy(stream, "CTL", &local_control_data, SnapControls, COUNT(SnapControls), version);
		if (result != SUCCESS)
			break;

		result = UnfreezeStructCopy(stream, "TIM", &local_timing_data, SnapTimings, COUNT(SnapTimings), version);
		if (result != SUCCESS)
			break;

		result = UnfreezeStructCopy(stream, "SFX", &local_superfx, SnapFX, COUNT(SnapFX), version);
		if (result != SUCCESS && Settings.SuperFX)
			break;

		result = UnfreezeStructCopy(stream, "SA1", &local_sa1, SnapSA1, COUNT(SnapSA1), version);
		if (result != SUCCESS && Settings.SA1)
			break;

		result = UnfreezeStructCopy(stream, "SAR", &local_sa1_registers, SnapSA1Registers, COUNT(SnapSA1Registers), version);
		if (result != SUCCESS && Settings.SA1)
			break;

		result = UnfreezeStructCopy(stream, "DP1", &local_dsp1, SnapDSP1, COUNT(SnapDSP1), version);
		if (result != SUCCESS && Settings.DSP == 1)
			break;

		result = UnfreezeStructCopy(stream, "DP2", &local_dsp2, SnapDSP2, COUNT(SnapDSP2), version);
		if (result != SUCCESS && Settings.DSP == 2)
			break;

		result = UnfreezeStructCopy(stream, "DP4", &local_dsp4, SnapDSP4, COUNT(SnapDSP4), version);
		if (result != SUCCESS && Settings.DSP == 4)
			break;

		if (Settings.C4)
		{
			if (fast)
				result = UnfreezeBlock(stream, "CX4", Memory.C4RAM, 8192);
			else
				result = UnfreezeBlockCopy(stream, "CX4", &local_cx4_data, 8192);
			if (result != SUCCESS)
			break;
		}
		else
		{
			SkipBlockWithName(stream, "CX4");
		}

		result = UnfreezeStructCopy(stream, "ST0", &local_st010, SnapST010, COUNT(SnapST010), version);
		if (result != SUCCESS && Settings.SETA == ST_010)
			break;

		result = UnfreezeStructCopy(stream, "OBC", &local_obc1, SnapOBC1, COUNT(SnapOBC1), version);
		if (result != SUCCESS && Settings.OBC1)
			break;

		if (Settings.OBC1)
		{
			if (fast)
				result = UnfreezeBlock(stream, "OBM", Memory.OBC1RAM, 8192);
			else
				result = UnfreezeBlockCopy(stream, "OBM", &local_obc1_data, 8192);
			if (result != SUCCESS)
			break;
		}
		else
		{
			SkipBlockWithName(stream, "OBM");
		}

		result = UnfreezeStructCopy(stream, "S71", &local_spc7110, SnapSPC7110Snap, COUNT(SnapSPC7110Snap), version);
		if (result != SUCCESS && Settings.SPC7110)
			break;

		result = UnfreezeStructCopy(stream, "SRT", &local_srtc, SnapSRTCSnap, COUNT(SnapSRTCSnap), version);
		if (result != SUCCESS && Settings.SRTC)
			break;

		result = UnfreezeBlockCopy (stream, "CLK", &local_rtc_data, 20);
		if (result != SUCCESS && (Settings.SRTC || Settings.SPC7110RTC))
			break;

		result = UnfreezeStructCopy(stream, "BSX", &local_bsx_data, SnapBSX, COUNT(SnapBSX), version);
		if (result != SUCCESS && Settings.BS)
			break;

		result = SUCCESS;
	} while (0);

	if (result == SUCCESS)
	{
		uint32 old_flags     = CPU.Flags;
		uint32 sa1_old_flags = SA1.Flags;

		if (fast)
		{
			S9xResetPPUFast();
		}
		else
		{
			/* Don't call this if you bypassed the "local_" buffers and modified the "Memory." buffers directly. */
			S9xReset();
		}

		UnfreezeStructFromCopy(&CPU, SnapCPU, COUNT(SnapCPU), local_cpu, version);

		UnfreezeStructFromCopy(&Registers, SnapRegisters, COUNT(SnapRegisters), local_registers, version);

		UnfreezeStructFromCopy(&PPU, SnapPPU, COUNT(SnapPPU), local_ppu, version);

		UnfreezeStructFromCopy(&dma_snap, SnapDMA, COUNT(SnapDMA), local_dma, version);

		if (local_vram)
			memcpy(Memory.VRAM, local_vram, 0x10000);

		if (local_ram)
			memcpy(Memory.RAM, local_ram, 0x20000);

		if (local_sram)
			memcpy(Memory.SRAM, local_sram, 0x80000);

		if (local_fillram)
			memcpy(Memory.FillRAM, local_fillram, 0x8000);

		S9xAPULoadState(local_apu_sound);

		UnfreezeStructFromCopy(&ctl_snap, SnapControls, COUNT(SnapControls), local_control_data, version);

		UnfreezeStructFromCopy(&Timings, SnapTimings, COUNT(SnapTimings), local_timing_data, version);

		if (local_superfx)
		{
			GSU.avRegAddr = (uint8 *) &GSU.avReg;
			UnfreezeStructFromCopy(&GSU, SnapFX, COUNT(SnapFX), local_superfx, version);
		}

		if (local_sa1)
			UnfreezeStructFromCopy(&SA1, SnapSA1, COUNT(SnapSA1), local_sa1, version);

		if (local_sa1_registers)
			UnfreezeStructFromCopy(&SA1Registers, SnapSA1Registers, COUNT(SnapSA1Registers), local_sa1_registers, version);

		if (local_dsp1)
			UnfreezeStructFromCopy(&DSP1, SnapDSP1, COUNT(SnapDSP1), local_dsp1, version);

		if (local_dsp2)
			UnfreezeStructFromCopy(&DSP2, SnapDSP2, COUNT(SnapDSP2), local_dsp2, version);

		if (local_dsp4)
			UnfreezeStructFromCopy(&DSP4, SnapDSP4, COUNT(SnapDSP4), local_dsp4, version);

		if (local_cx4_data)
			memcpy(Memory.C4RAM, local_cx4_data, 8192);

		if (local_st010)
			UnfreezeStructFromCopy(&ST010, SnapST010, COUNT(SnapST010), local_st010, version);

		if (local_obc1)
			UnfreezeStructFromCopy(&OBC1, SnapOBC1, COUNT(SnapOBC1), local_obc1, version);

		if (local_obc1_data)
			memcpy(Memory.OBC1RAM, local_obc1_data, 8192);

		if (local_spc7110)
			UnfreezeStructFromCopy(&s7snap, SnapSPC7110Snap, COUNT(SnapSPC7110Snap), local_spc7110, version);

		if (local_srtc)
			UnfreezeStructFromCopy(&srtcsnap, SnapSRTCSnap, COUNT(SnapSRTCSnap), local_srtc, version);

		if (local_rtc_data)
			memcpy(RTCData.reg, local_rtc_data, 20);

		if (local_bsx_data)
			UnfreezeStructFromCopy(&BSX, SnapBSX, COUNT(SnapBSX), local_bsx_data, version);

		CPU.Flags |= old_flags & (DEBUG_MODE_FLAG | TRACE_FLAG | SINGLE_STEP_FLAG);
		ICPU.ShiftedPB = Registers.PB << 16;
		ICPU.ShiftedDB = Registers.DB << 16;
		S9xSetPCBase(Registers.PBPC);
		S9xUnpackStatus();
		S9xFixCycles();

		DMA[0] = dma_snap.dma[0];
		DMA[1] = dma_snap.dma[1];
		DMA[2] = dma_snap.dma[2];
		DMA[3] = dma_snap.dma[3];
		DMA[4] = dma_snap.dma[4];
		DMA[5] = dma_snap.dma[5];
		DMA[6] = dma_snap.dma[6];
		DMA[7] = dma_snap.dma[7];

		CPU.InDMA = CPU.InHDMA = FALSE;
		CPU.InDMAorHDMA = CPU.InWRAMDMAorHDMA = FALSE;
		CPU.HDMARanInDMA = 0;

		S9xFixColourBrightness();
		IPPU.RenderThisFrame = TRUE;
		IPPU.OBJChanged = TRUE;

		hdma_byte = Memory.FillRAM[0x420c];
		S9xSetCPU(hdma_byte, 0x420c);

		S9xControlPostLoadState(&ctl_snap);

		if (local_sa1 && local_sa1_registers)
		{
			SA1.Flags |= sa1_old_flags & TRACE_FLAG;
			S9xSA1PostLoadState();
		}

		if (Settings.SDD1)
			S9xSDD1PostLoadState();

		if (local_spc7110)
			S9xSPC7110PostLoadState();

		if (local_srtc)
			S9xSRTCPostLoadState();

		if (local_bsx_data)
			S9xBSXPostLoadState();
	}

	if (local_cpu)			free(local_cpu);
	if (local_registers)		free(local_registers);
	if (local_ppu)			free(local_ppu);
	if (local_dma)			free(local_dma);
	if (local_vram)			free(local_vram);
	if (local_ram)			free(local_ram);
	if (local_sram)			free(local_sram);
	if (local_fillram)		free(local_fillram);
	if (local_apu_sound)		free(local_apu_sound);
	if (local_control_data)		free(local_control_data);
	if (local_timing_data)		free(local_timing_data);
	if (local_superfx)		free(local_superfx);
	if (local_sa1)			free(local_sa1);
	if (local_sa1_registers)	free(local_sa1_registers);
	if (local_dsp1)			free(local_dsp1);
	if (local_dsp2)			free(local_dsp2);
	if (local_dsp4)			free(local_dsp4);
	if (local_cx4_data)		free(local_cx4_data);
	if (local_st010)		free(local_st010);
	if (local_obc1)			free(local_obc1);
	if (local_obc1_data)		free(local_obc1_data);
	if (local_spc7110)		free(local_spc7110);
	if (local_srtc)			free(local_srtc);
	if (local_rtc_data)		free(local_rtc_data);
	if (local_bsx_data)		free(local_bsx_data);

	return (result);
}
