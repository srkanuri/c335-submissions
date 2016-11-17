#include <stdio.h>
#include <stdlib.h>

typedef struct CELL *LIST;

struct CELL {
    int val;
    LIST next;
};
