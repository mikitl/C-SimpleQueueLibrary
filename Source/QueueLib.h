#ifndef _QUEUE_LIB_H_
#define _QUEUE_LIB_H_

typedef struct _NODE {
    int           Value;
    struct _NODE  *Next;
    struct _NODE  *Prev;
} NODE;

typedef struct _QUEUE {
    void (*Enqueue)(int);
    void (*Dequeue)(void);
    int (*Size)(void);
} QUEUE;

QUEUE* InitQueue(void);
void InternalsEnqueue(int _value);
void InternalsDequeue(void);
int InternalsSize(void);

#endif