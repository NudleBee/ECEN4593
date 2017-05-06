//
// Created by Dylan Van de Kerkhove on 5/5/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "initalization.h"
#include "cache.h"

block newBlock(void) {
    block b = (block) malloc(sizeof(struct _block));
    int i = 0;
    b->dirty = 0;
    b->valid = 0;
    b->tag = 0x0;
    for (i = 0; i < BLOCK_SIZE; i++) {
        b->data[i] = 0x0;
    }
    return b;
}

cache newCache(int cacheSize, int blockSize) {
    cache c = (cache) malloc(sizeof(struct _cache));
    int i = 0;
    c->accesses = 0;
    c->hitCount = 0;
    c->cacheSize = cacheSize;
    c->blockSize = blockSize;
    c->numBlocks = cacheSize / (4 * blockSize);
    c->blockOffset = log2(blockSize);
    c->indexOffset = log2(c->numBlocks);
    strcpy(c->writePolicy, WRITE_POLICY);
    c->writeBufferLoadedCycle = 0;
    //make block array from [0] to [numBlocks-1]
    //allocate a block array of length numBlocks
    c->cacheBlock = (block *) malloc((c->numBlocks)*sizeof(block));
    //initialize all blocks
    for (i = 0; i < (c->numBlocks); i++) {
        c->cacheBlock[i] = newBlock();
    }
    c->instBlockLoadedCycle = 0;
    return c;
}

void deleteCache(cache c) {
    //free block memory
    for (int i = 0; i < (c->numBlocks); i++) {
        free(c->cacheBlock[i]);
    }
    //free block array
    free(c->cacheBlock);
    //free cache
    free(c);
}

void validateDBlock(cache c, int address, int index, int tag) {

    //miss penalty
    cycleCount += (6 + 2*(c->blockSize));

    //update cache contents:
    int memAddress = (address / (4*(c->blockSize))) * (c->blockSize);
    c->cacheBlock[index]->tag = tag;
    for (int i = 0; i < (c->blockSize); i++) {
        c->cacheBlock[index]->data[i] = mainMemory[memAddress];
        memAddress++;
    }
    c->cacheBlock[index]->valid = 1;
    return;
}

void checkBlockRead(cache c, int address, int index, int tag) {
    if (tag != c->cacheBlock[index]->tag) { //miss

        //miss penalty
        cycleCount += (6 + 2*(c->blockSize));

        //update cache contents:
        int memAddress = (address / (4*(c->blockSize))) * (c->blockSize);
        c->cacheBlock[index]->tag = tag;
        for (int i = 0; i < (c->blockSize); i++) {
            c->cacheBlock[index]->data[i] = mainMemory[memAddress];
            memAddress++;
        }
    }
    else { //hit!
        (c->hitCount)++;
    }
    return;
}

void checkBlockWrite(cache c, int address, int index, int tag) {
    if (tag != c->cacheBlock[index]->tag) { //miss

        //miss penalty
        cycleCount += (6 + 2*(c->blockSize));

        //update block contents:
        int i = 0;
        int memAddress = (address / (4*(c->blockSize))) * (c->blockSize);
        c->cacheBlock[index]->tag = tag;
        for (i = 0; i < (c->blockSize); i++) {
            c->cacheBlock[index]->data[i] = mainMemory[memAddress];
            memAddress++;
        }

        if (!strcmp(WRITE_POLICY, "WB")) {
            //after cache block updates, load previous block (if dirty) back to mainMemory
            if (c->cacheBlock[index]->dirty) { //check dirty bit
                if (c->writeBufferLoadedCycle) { //if not first buffer fill
                    if (cycleCount <= ((c->writeBufferLoadedCycle)+(2*(c->blockSize))+4)) { //memory store cycles have not passed, stall
                        cycleCount = (c->writeBufferLoadedCycle)+(2*(c->blockSize))+5;
                    }
                }
                c->writeBufferLoadedCycle = cycleCount;
            }
        }
        c->cacheBlock[index]->dirty = 0;
    }

    else { //hit!
        (c->hitCount)++;
        c->cacheBlock[index]->dirty = 1;
    }
    return;
}

void updateMem(cache c, int address, int newData) {
    if (!strcmp(WRITE_POLICY, "WT")) {
        //fill buffer, update mainMemory in 6 cycles
        if (c->writeBufferLoadedCycle) { //if not first buffer fill
            if (cycleCount <= ((c->writeBufferLoadedCycle)+6)) { //6 cycles have not passed, stall
                cycleCount = (c->writeBufferLoadedCycle)+7;
            }
        }
        c->writeBufferLoadedCycle = cycleCount;
    }
    //update mainMemory for either policy; stalls added to cycleCount separately
    mainMemory[address >> 2] = newData;
    return;
}

int readCacheByte(cache c, int address) {
    (c->accesses)++;
    //decode address into bit fields
    int decodeAddress = address; //copy address
    int whichByte = decodeAddress % 4;
    decodeAddress >>= 2; //shift right to get rid of byte offset
    int whichWord = decodeAddress % (c->blockSize);
    decodeAddress >>= (c->blockOffset);  //shift right to get rid of block offset
    int index = decodeAddress % (c->numBlocks);
    decodeAddress >>= (c->indexOffset);  //shift right to get rid of index offset
    int addressTag = decodeAddress; //tag is all remaining bits

    //check corresponding block's valid bit
    if (!(c->cacheBlock[index]->valid)) {
        validateDBlock(c, address, index, addressTag);
    }
        //check tag for hit or miss
    else {
        checkBlockRead(c, address, index, addressTag);
    }
    //return requested data
    int byteShift = 4 * whichByte;
    int extractedByte = ((c->cacheBlock[index]->data[whichWord]) & ((0xFF) << byteShift)) >> byteShift;
    if (extractedByte >> 7) {
        extractedByte |= 0xFFFFFF00;
    }
    return extractedByte;
}

int readCacheByteUnsigned(cache c, int address) {
    (c->accesses)++;
    //decode address into bit fields
    int decodeAddress = address; //copy address
    int whichByte = decodeAddress % 4;
    decodeAddress >>= 2; //shift right to get rid of byte offset
    int whichWord = decodeAddress % (c->blockSize);
    decodeAddress >>= (c->blockOffset); //shift right to get rid of block offset
    int index = decodeAddress % (c->numBlocks);
    decodeAddress >>= (c->indexOffset); //shift right to get rid of index offset
    int addressTag = decodeAddress; //tag is all remaining bits

    //check corresponding block's valid bit
    if (!(c->cacheBlock[index]->valid)) {
        validateDBlock(c, address, index, addressTag);
    }
        //check tag for hit or miss
    else {
        checkBlockRead(c, address, index, addressTag);
    }
    //return requested data
    int byteShift = 4 * whichByte;
    return ((c->cacheBlock[index]->data[whichWord]) & ((0xFF) << byteShift)) >> byteShift;
}

int readCacheHalfwordUnsigned(cache c, int address) {
    (c->accesses)++;
    //decode address into bit fields
    int decodeAddress = (address >> 1); //copy address (shifted to get rid of byte)
    int whichHalfword = decodeAddress % 2;
    decodeAddress >>= 1; //shift right to get rid of byte offset
    int whichWord = decodeAddress % (c->blockSize);
    decodeAddress >>= (c->blockOffset); //shift right to get rid of block offset
    int index = decodeAddress % (c->numBlocks);
    decodeAddress >>= (c->indexOffset); //shift right to get rid of index offset
    int addressTag = decodeAddress; //tag is all remaining bits

    //check corresponding block's valid bit
    if (!(c->cacheBlock[index]->valid)) {
        validateDBlock(c, address, index, addressTag);
    }
        //check tag for hit or miss
    else {
        checkBlockRead(c, address, index, addressTag);
    }
    //return requested data
    int halfwordShift = 16 * whichHalfword;
    return ((c->cacheBlock[index]->data[whichWord]) & ((0xFFFF) << halfwordShift)) >> halfwordShift;
}

int readDCacheWord(cache c, int address) {
    (c->accesses)++;
    //decode address into bit fields
    int decodeAddress = (address >> 2); //shift right to get rid of byte offset
    int whichWord = decodeAddress % (c->blockSize);
    decodeAddress >>= (c->blockOffset); //shift right to get rid of block offset
    int index = decodeAddress % (c->numBlocks);
    decodeAddress >>= (c->indexOffset); //shift right to get rid of index offset
    int addressTag = decodeAddress; //tag is all remaining bits

    //check corresponding block's valid bit
    if (!(c->cacheBlock[index]->valid)) {
        validateDBlock(c, address, index, addressTag);
    }
        //check tag for hit or miss
    else {
        checkBlockRead(c, address, index, addressTag);
    }
    //return requested data
    return c->cacheBlock[index]->data[whichWord];
}

int readICache(cache c, int pc) { //word aligned pc (mem[pc])
    (c->accesses)++;
    //decode pc address into bit fields
    int decodePCAddress = pc;
    int whichWord = decodePCAddress % (c->blockSize);
    decodePCAddress >>= (c->blockOffset); //shift right to get rid of block offset
    int index = decodePCAddress % (c->numBlocks);
    decodePCAddress >>= (c->indexOffset); //shift right to get rid of index offset
    int pcTag = decodePCAddress; //tag is all remaining bits

    int i = 0;
    int memAddress = (pc / (c->blockSize)) * (c->blockSize); //start address of block

    //check corresponding block's total valid bit
    if (!(c->cacheBlock[index]->valid)) { //block first visited
        //miss penalty/update cache contents:
        c->cacheBlock[index]->tag = pcTag;
        c->instBlockLoadedCycle = cycleCount;
        for (i = 0; i < (c->blockSize); i++) {
            if (!i) { //first word of block
                cycleCount += 8;
            }
            else { //other words
                if (i <= whichWord) {
                    cycleCount += 2;
                }
            }
            c->cacheBlock[index]->data[i] = mainMemory[memAddress];
            memAddress++;
        }
        c->cacheBlock[index]->valid = 1;
    }

        //check tag for hit or miss
    else {
        if (pcTag != c->cacheBlock[index]->tag) { //miss: wrong tag in block
            if (cycleCount <= ((c->instBlockLoadedCycle)+(2*(c->blockSize))+6)) {
                cycleCount = (c->instBlockLoadedCycle)+(2*(c->blockSize))+7;
            } //if a block is still loading, stall until finsihed

            //miss penalty/update cache contents:
            c->cacheBlock[index]->tag = pcTag;
            c->instBlockLoadedCycle = cycleCount;
            for (i = 0; i < (c->blockSize); i++) {
                if (!i) { //first word of block
                    cycleCount += 8;
                }
                else { //other words
                    if (i <= whichWord) {
                        cycleCount += 2;
                    }
                }
                c->cacheBlock[index]->data[i] = mainMemory[memAddress];
                memAddress++;
            }
        }
        else { //hit! -> correct tag in block (at least 1 word has been added)
            (c->hitCount)++;
            if (cycleCount <= ((c->instBlockLoadedCycle)+(2*whichWord)+8)) {
                cycleCount = (c->instBlockLoadedCycle)+(2*whichWord)+9;
            } //if current block is still loading, stall until called inst loads
        }
    }
    //return requested data
    return c->cacheBlock[index]->data[whichWord];
}

void writeCacheByte(cache c, int address, int data) {
    (c->accesses)++;
    //decode address into bit fields
    int decodeAddress = address; //copy address
    int whichByte = decodeAddress % 4; //byte referenced in address
    decodeAddress >>= 2; //shift right to get rid of byte offset
    int whichWord = decodeAddress % (c->blockSize);
    decodeAddress >>= (c->blockOffset); //shift right to get rid of block offset
    int index = decodeAddress % (c->numBlocks);
    decodeAddress >>= (c->indexOffset); //shift right to get rid of index offset
    int addressTag = decodeAddress; //tag is all remaining bits

    //check corresponding block's valid bit
    if (!(c->cacheBlock[index]->valid)) {
        validateDBlock(c, address, index, addressTag);
    }
    else { //check tag for hit or miss
        checkBlockWrite(c, address, index, addressTag);
    }

    //update word with provided data
    int byteShift = 4 * whichByte;
    int byteStored = (data & 0xFF) << byteShift; //zero-extended low byte of data, in correct position
    int byteCleared = (c->cacheBlock[index]->data[whichWord]) & (~((0xFF) << byteShift)); //word in data memory with desired byte field cleared (0x00)
    int newWord = byteCleared | byteStored;

    //update word in block and memory
    c->cacheBlock[index]->data[whichWord] = newWord;
    updateMem(c, address, newWord);
    return;
}

void writeCacheHalfword(cache c, int address, int data) {
    (c->accesses)++;
    //decode address into bit fields
    int decodeAddress = (address >> 1); //copy address (shifted to get rid of byte)
    int whichHalfword = decodeAddress % 2;
    decodeAddress >>= 1; //shift right to get rid of byte offset
    int whichWord = decodeAddress % (c->blockSize);
    decodeAddress >>= (c->blockOffset); //shift right to get rid of block offset
    int index = decodeAddress % (c->numBlocks);
    decodeAddress >>= (c->indexOffset); //shift right to get rid of index offset
    int addressTag = decodeAddress; //tag is all remaining bits

    //check corresponding block's valid bit
    if (!(c->cacheBlock[index]->valid)) {
        validateDBlock(c, address, index, addressTag);
    }
    else { //check tag for hit or miss
        checkBlockWrite(c, address, index, addressTag);
    }

    //update word with provided data
    int halfwordShift = 16 * whichHalfword;
    int halfwordStored = (data & 0xFFFF) << halfwordShift; //zero-extended low halfword of data, in correct position
    int halfwordCleared = (c->cacheBlock[index]->data[whichWord]) & (~((0xFFFF) << halfwordShift)); //word in data memory with desired halfword field cleared (0x0000)
    int newWord = halfwordCleared | halfwordStored;

    //update word in block and memory
    c->cacheBlock[index]->data[whichWord] = newWord;
    updateMem(c, address, newWord);
    return;
}

void writeCacheWord(cache c, int address, int data) {
    (c->accesses)++;
    //decode address into bit fields
    int decodeAddress = (address >> 2); //shift right to get rid of byte offset
    int whichWord = decodeAddress % (c->blockSize);
    decodeAddress >>= (c->blockOffset); //shift right to get rid of block offset
    int index = decodeAddress % (c->numBlocks);
    decodeAddress >>= (c->indexOffset); //shift right to get rid of index offset
    int addressTag = decodeAddress; //tag is all remaining bits

    //check corresponding block's valid bit
    if (!(c->cacheBlock[index]->valid)) {
        validateDBlock(c, address, index, addressTag);
    }
    else { //check tag for hit or miss
        checkBlockWrite(c, address, index, addressTag);
    }

    //update word in block and memory
    c->cacheBlock[index]->data[whichWord] = data;
    updateMem(c, address, data);
    return;
}