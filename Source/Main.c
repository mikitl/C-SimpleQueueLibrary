#include <stdio.h>
#include <stdlib.h>
#include "QueueLib.h"

int main(int argc, char const *argv[]) {
    QUEUE *Queue = InitQueue();

    for (int i = 1; i < argc; ++i) {
        if (*argv[i] == '-') {
            Queue->Dequeue();
        } else {
            Queue->Enqueue(atoi(argv[i]));
        }
    }
    Queue->Size();

    return 0;
}