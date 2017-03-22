#include <stdio.h>
#include <stdlib.h>
#include "QueueLib.h"

static NODE *mQueueHead;
static NODE *mQueueTail;
static int  mSize;

QUEUE* InitQueue(void) {
    QUEUE  *Queue = NULL;

    mQueueHead = malloc(sizeof(NODE));
    mQueueHead->Value = 0xDEADBEEF;
    mQueueHead->Next = NULL;
    mQueueHead->Prev = NULL;
    
    mQueueTail = malloc(sizeof(NODE));
    mQueueTail->Value = 0xCAFEBABE;
    mQueueTail->Next = NULL;
    mQueueTail->Prev = NULL;

    mQueueHead->Prev = mQueueTail;
    mQueueTail->Next = mQueueHead;

    mSize = 0;

    Queue = malloc(sizeof(QUEUE));
    Queue->Enqueue = InternalsEnqueue;
    Queue->Dequeue = InternalsDequeue;
    Queue->Size = InternalsSize;

    return Queue;
}


void InternalsEnqueue(int _value) {
    NODE *tmp = NULL;

    tmp = malloc(sizeof(NODE));
    tmp->Value = _value;
    tmp->Next = mQueueTail->Next;
    tmp->Prev = mQueueTail;
    (mQueueTail->Next)->Prev = tmp;
    mQueueTail->Next = tmp;

    mSize = mSize + 1;
    printf("Enqueue: %d\n", _value);

    return;
}


void InternalsDequeue(void) {
    NODE *tmp = NULL;

    if (mQueueHead->Prev == mQueueTail) {
        printf("Dequeue: Queue is empty!\n");
        return;
    }
    tmp = mQueueHead->Prev;
    (tmp->Prev)->Next = mQueueHead;
    mQueueHead->Prev = tmp->Prev;
    mSize = mSize - 1;
    printf("Dequeue: %d\n", tmp->Value);
    free(tmp);
    return;
}


int InternalsSize(void) {
    printf("Size: %d\n", mSize);
    return mSize;
}