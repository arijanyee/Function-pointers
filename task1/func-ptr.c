
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include "process.h"
#include "util.h"

#define DEBUG 0

/**
 * Signature for a function pointer that can compare
 * two processes.
 */
typedef int (*Comparer)(const void *a, const void *b);

/**
 * Compares two processes.
 * Priority: descending order.
 * Arrival time: ascending order for equal priorities.
 */
int my_comparer(const void *this, const void *that)
{
    const Process *a = (const Process *)this;
    const Process *b = (const Process *)that;

    if (a->priority != b->priority) {
        return b->priority - a->priority;
    }

    return a->arrival_time - b->arrival_time;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: ./qsort <input-file-path>\n");
        fflush(stdout);
        return 1;
    }

    /* Parse the input */
    FILE *input_file = fopen(argv[1], "r");

    if (!input_file) {
        fprintf(stderr, "Error: Invalid filepath\n");
        fflush(stdout);
        return 1;
    }

    Process *processes = parse_file(input_file);

    if (processes == NULL) {
        fclose(input_file);
        return 1;
    }

    /* Sort the input */
    Comparer process_comparer = &my_comparer;

#if DEBUG
    for (int i = 0; i < P_SIZE; i++) {
        printf("%d (%d, %d) ",
               processes[i].pid,
               processes[i].priority,
               processes[i].arrival_time);
    }
    printf("\n");
#endif

    qsort(processes, P_SIZE, sizeof(Process), process_comparer);

    /* Print the sorted data */
    for (int i = 0; i < P_SIZE; i++) {
        printf("%d (%d, %d)\n",
               processes[i].pid,
               processes[i].priority,
               processes[i].arrival_time);
    }

    fflush(stdout);
    fflush(stderr);

    /* Clean up */
    free(processes);
    fclose(input_file);

    return 0;
}
