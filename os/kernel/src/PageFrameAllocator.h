#pragma once

#include <stdint.h>

#include "Bitmap.h"
#include "EFIMemory.h"
#include "memory.h"

class PageFrameAllocator {
   public:
    void ReadEFIMemoryMap(EFI_MEMORY_DESCRIPTOR* mMap, size_t mMapSize, size_t mMapDescSize);
    Bitmap PageBitmap;
    void FreePage(void* address);
    void LockPage(void* address);
    void FreePages(void* address, uint64_t pageCount);
    void LockPages(void* address, uint64_t pageCount);

    void* RequestPage();

    uint64_t GetFreeRAM();
    uint64_t GetUsedRAM();
    uint64_t GetReservedRAM();

   private:
    void InitBitmap(size_t bitmapSize, void* bufferAddress);
    void ReservePage(void* address);
    void ReleasePage(void* address);
    void ReservePages(void* address, uint64_t pageCount);
    void ReleasePages(void* address, uint64_t pageCount);
};