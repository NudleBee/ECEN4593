//
// Created by Dylan Van de Kerkhove on 5/5/17.
//

#define I_CACHE_SIZE 64
#define D_CACHE_SIZE 64
#define BLOCK_SIZE 4
#define WRITE_POLICY "WT"

using namespace std;

#ifndef ECEN4593_CACHE_H
#define ECEN4593_CACHE_H

struct _block {
    unsigned int dirty; //dirty bit for WB policy
    unsigned int valid; //valid bit
    int tag; //initialized 0x0
    int data[BLOCK_SIZE]; //initialized to array of BLOCK_SIZE words
    // each initialized to 0x0
};
typedef struct _block * block;

struct _cache {
    int accesses;
    int hitCount;
    int cacheSize; //bytes per cache
    int blockSize; //words per block
    int numBlocks; //number of blocks per cache
    int blockOffset; //number of bits in address
    int indexOffset; //number of bits in address
    char writePolicy[3]; //WT or WB with null-char termination
    int writeBufferLoadedCycle;
    block * cacheBlock; //pointer to array of blocks
    int instBlockLoadedCycle;
};
typedef struct _cache * cache;

block newBlock(void);
cache newCache(int cacheSize, int blockSize);
void deleteCache(cache c);

void validateDBlock(cache c, int address, int index, int tag);
void checkBlockRead(cache c, int address, int index, int tag);
void checkBlockWrite(cache c, int address, int index, int tag);
void updateMem(cache c, int address, int newData);

int readCacheByte(cache c, int address);
int readCacheByteUnsigned(cache c, int address);
int readCacheHalfwordUnsigned(cache c, int address);
int readDCacheWord(cache c, int address);
int readICache(cache c, int pc);

void writeCacheByte(cache c, int address, int data);
void writeCacheHalfword(cache c, int address, int data);
void writeCacheWord(cache c, int address, int data);

#endif //ECEN4593_CACHE_H
