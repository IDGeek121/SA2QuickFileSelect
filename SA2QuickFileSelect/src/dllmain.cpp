#include "SA2ModLoader.h"
#include "menu_title_screen.h"
#define BUTTON_Y 0x200
#define BUTTON_START 0x8


FunctionPointer(int, sprintf, (char*, const char*, ...), 0x7a7c6d);
FunctionPointer(void, FUN_0043d5d0, (), 0x0043d5d0);


static const void* const write_replay_buffer_ptr = (void*)0x0043a730;
static inline void write_replay_buffer(char* filename)
{
	__asm
	{
		mov edi, [filename]
		call write_replay_buffer_ptr
	}
}


void __cdecl write_replay_buffer_thunk()
{
	if (DemoState == 2)
	{
		char filenameBuffer[256];
		sprintf(filenameBuffer, "gd_PC/demo%02d.bin", CurrentLevel);
		// char *filename = FUN_0077f420(filenameBuffer, local_8c);
		write_replay_buffer(filenameBuffer);
	}
}

void __declspec(naked) go_to_next_level_thunk()
{
	__asm
	{
		call write_replay_buffer_thunk
		jmp FUN_0043d5d0
	}
}

extern "C"
{
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };

	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		WriteCall((void*)0x0066628f, menu_title_screen);
		WriteCall((void*)0x0043bc77, go_to_next_level_thunk);

		WriteJump((void*)0x0043d09f, (void*)0x0043d0ae);
	}
}