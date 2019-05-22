#include <stdint.h>
#ifndef MMU_H
#define MMU_H

class MMU {
	public: // Good for direct access - it's faster
		MMU();

		// Memory Layout
		/*
			ROM:			0x0000 - 0x1FFF
			RAM:			0x2000 - 0x23FF
			VRAM:			0x2400 - 0x3FFF
			RAMMirror:	0x4000 - 0x43FF
		*/

		uint16_t ROMAddress = 0x0000;
		uint16_t RAMAddress = 0x2000;
		uint16_t VRAMAddress = 0x2400;
		uint16_t RAMMirrorAddress = 0x4000;
		
		// Convenience Pointers
		uint8_t* VRAM = Memory + 0x2400;

		uint8_t* MemoryMap[0x4400];
		uint8_t GetByteAt (uint16_t Address);
		void SetByteAt (uint16_t Address, uint8_t Value);
		void LoadInMemory (uint8_t* Buffer, uint16_t Address, int BufferSize);
	private:
		uint8_t Memory[0x4000];
};

#endif