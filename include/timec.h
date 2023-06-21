#ifndef TIMEC
#define TIMEC

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <string.h>

typedef struct timespecs timespecs_t;

struct timespecs {
  struct timeval system_time;
  struct timeval user_time;
  struct timeval day_time;
  struct rusage resource_time_begin;
  struct rusage resource_time_end;
  struct timeval day_time_begin;
  struct timeval day_time_end;
};

float get_milliseconds(struct timeval time);
struct timeval time_diff(struct timeval begin, struct timeval end);
timespecs_t *create_time_specs();
void start_time_count(timespecs_t *specs);
void stop_time_count(timespecs_t *specs);
void erase_time_specs(timespecs_t *specs);
void reset_time_count(timespecs_t *specs);
void time_specs_print(timespecs_t *specs);
void write_time_per_size(FILE *user, FILE *system, FILE *total,timespecs_t *specs,int m, int n);

#endif