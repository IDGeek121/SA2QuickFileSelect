#include "menu_title_screen.h"


void __cdecl should_load_file_menu()
{
	if ((MenuButtons_Held[0] & BUTTON_Y) != 0)
	{
		FileLoadStatus = -1;
	}
}

int __cdecl menu_title_screen()
{
	if (LoadDemo_q != 0)
	{
		CurrentSubMenu = 3;
		DAT_0174b017 = 0;
		titleStruct->enable = 0;
	}

	switch (CurrentSubMenu)
	{
	case 0:
		titleStruct->enable = 1;
		titleStruct->field_4 = 1;
		if (titleFirstBoot != 0)
		{
			titleDoZoomOut = 1;
			titleSize = 1.f;
			titleZoomTimer = 0;
			titleFirstBoot = 0;
			titleOpacity = 0.f;
		}
		showBlankScreenHint_q = 0;
		CurrentSubMenu = 1;
		titleTimeToDemo = 0;
		return 0;
	case 1:
		if (titleStruct->transition_q == 0)
		{
			CurrentSubMenu = 2;
			return 0;
		}
		if ((MenuButtons_Pressed[0] & BUTTON_START) != 0)
		{
			titleZoomTimer = DAT_00c769d4 - 1;
			return 0;
		}
		break;
	case 2:
		titleStruct->field_10 = (FrameCountIngame >> 6) & 1;
		showBlankScreen_q = 0;
		if (((MenuButtons_Pressed[0] & BUTTON_START) == 0) || (FUN_00441a50() != 0))
		{
			titleTimeToDemo++;
			if (titleTimeToDemo <= 1200)
			{
				return 0;
			}
			CurrentSubMenu = 3;
			titleStruct->enable = 0;
			return 0;
		}
		DAT_01d1b7b0 = 0;
		DAT_0174b48c = 0;
		DAT_0093beb2 = 1;
		titleStruct->field_4 = 0;
#ifdef QUICK_FILE_LOAD
		should_load_file_menu();
#endif
		if (FileLoadStatus == FILE_NOTLOADED)
		{
			DAT_01a557e0 = 0;
			fileSelectFreezeAfter = 0;
			FUN_00688c20();
			CurrentMenu = 0x9;
			PlaySoundProbably(0x8008, 0, 0, 0);
			return 0;
		}
		FUN_00664b60();
		CurrentMenu = 0x1;
		PlaySoundProbably(0x8008, 0, 0, 0);
		return 0;
	case 3:
		if (titleStruct->transition_q == 0)
		{
			FUN_00446460();
			short stageNumber = (short)demoInfoTable[demoIndex].stage;
			if (stageNumber == -1)
			{
				DemoState = 0;
				FUN_0067e690();
			}
			else
			{
				SetCurrentLevel(stageNumber);
				Current2PLevelGroup = (byte)demoInfoTable[demoIndex].levelGroup2p;
				TwoPlayerMode = 1;
				int p1Char = demoInfoTable[demoIndex].p1Character;
				CurrentCharacter = p1Char;
				if ((isFirstStageLoad == 1) && (overrideCharacter != -2))
				{
					CurrentCharacter = overrideCharacter;
					overrideCharacter = -2;
				}
				CurrentCharacter2P = demoInfoTable[demoIndex].p2Character;
#ifdef SINGLE_PLAYER_DEMO
				Current2PLevelGroup = 0;
				TwoPlayerMode = 0;
#endif
				DAT_0174afe0 = 1 < (p1Char - 6);
				AltCharacter[0] = 0;
				AltCharacter[1] = 0;
				DAT_01deb31e = 0;
				DAT_01deb31f = 0;
				DAT_01deb320 = 0;
				DAT_01deb321 = 1;
				NextGameMode = 9;
				DemoState = 1;
			}
			demoIndex++;
			DAT_01deb323 = 1;
			if (demoIndex > 7)
			{
				demoIndex = 0;
			}
			FUN_0044ca90();
			MissionNum = 0;
			return 1;
		}
		break;
	case 4:
		titleStruct->field_4 = 0;
		FUN_00664b60();
		CurrentMenu = 0x1;
		PlaySoundProbably(0x8008, 0, 0, 0);
		return 0;
	}

	return 0;
}