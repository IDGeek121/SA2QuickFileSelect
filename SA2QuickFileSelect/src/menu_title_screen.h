#pragma once
#include "SA2ModLoader.h"

#ifndef _MENU_TITLE_SCREEN_H
#define _MENU_TITLE_SCREEN_H
#define BUTTON_Y 0x200
#define BUTTON_START 0x8

struct DemoInfo {
	int stage;
	int levelGroup2p;
	int p1Character;
	int p2Character;
};

struct TitleStruct {
	int enable;
	int field_4;
	int transition_q;
	int field_c;
	int field_10;
};

int __cdecl menu_title_screen();

DataPointer(byte, DAT_0093beb2, 0x0093beb2);
DataPointer(int, titleFirstBoot, 0x00c75434);
DataArray(struct DemoInfo, demoInfoTable, 0x00c76648, 8);
DataPointer(int*, DAT_00c7664c, 0x00c7664c);
DataPointer(int, DAT_00c76650, 0x00c76650);
DataPointer(int, DAT_00c769d4, 0x00c769d4);
DataPointer(TitleStruct*, titleStruct, 0x00c77f00);
DataPointer(int, FileLoadStatus, 0x0173d06c);
DataPointer(int, overrideCharacter, 0x01749564);
DataPointer(byte, demoIndex, 0x0174afc1);
DataPointer(byte, DAT_0174afe0, 0x0174afe0);
DataPointer(byte, DAT_0174b017, 0x0174b017);
DataPointer(int, DAT_0174b48c, 0x0174b48c);
DataPointer(float, titleOpacity, 0x01a49fe8);
DataPointer(int, titleZoomTimer, 0x01a49ff0);
DataPointer(int, titleDoZoomOut, 0x01a49ff4);
DataPointer(float, titleSize, 0x01a49ffc);
DataPointer(int, DAT_01a557e0, 0x01a557e0);
DataPointer(int, showBlankScreen_q, 0x01a557e4);
DataPointer(int, showBlankScreenHint_q, 0x01a557e8);
DataPointer(int, DAT_01d1b7b0, 0x01d1b7b0);
DataPointer(int, fileSelectFreezeAfter, 0x01d1c23c);
DataPointer(int, LoadDemo_q, 0x01d7b9d0);
DataPointer(int, titleTimeToDemo, 0x01d7bb18);
DataPointer(byte, DAT_01deb31e, 0x01deb31e);
DataPointer(byte, DAT_01deb31f, 0x01deb31f);
DataPointer(byte, DAT_01deb320, 0x01deb320);
DataPointer(byte, DAT_01deb321, 0x01deb321);
DataPointer(byte, DAT_01deb323, 0x01deb323);

FunctionPointer(int, FUN_00441a50, (), 0x00441a50);
VoidFunc(FUN_00446460, 0x00446460);
VoidFunc(FUN_0044ca90, 0x0044ca90);
VoidFunc(FUN_00664b60, 0x00664b60);
VoidFunc(FUN_0067e690, 0x0067e690);
VoidFunc(FUN_00688c20, 0x00688c20);

enum FileLoadStatus {
	FILE_NOSAVE = -2,
	FILE_NOTLOADED = -1,
	FILE_LOADED = 0
};
#endif