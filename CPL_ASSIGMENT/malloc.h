#include<stdio.h>
#include<stddef.h>

char heap[10000];//Considering this as my Heap

struct block
{
    size_t size;//holds the size of the block in consideration
    int free;//its a flag which tells us if the block is allocated or not,if it is free its set to 1, otherwise zero
    struct block *next;//points to the next block in the list
};

struct block*freeList=(struct block*)heap;//Its pointing to main block of memory which is initially free

void initialize();//Initializing the block
void split(struct block *fitting_slot,size_t size);//Splitting the block based on the size of the block required and size available in the heap
void *allocate(size_t noofBytes);
void merge();//Coaelescing/merging free blocks after deallocation
void deallocate(void* ptr);//freeing up the blocks
void printSize();//Prints the size of the block occupied in the heap