#include <timec.h>

float get_milliseconds(struct timeval time) 
{
  float milliseconds = time.tv_sec * 1000 + time.tv_usec * 0.001;
  return milliseconds;
}

/* Returns a strucutre that contains the difference between two 
   other time structures */
struct timeval time_diff(struct timeval begin, struct timeval end)
{
  struct timeval diff;
  diff.tv_sec = end.tv_sec - begin.tv_sec;
  diff.tv_usec = end.tv_usec - begin.tv_usec;
  
  return diff;
}

timespecs_t *create_time_specs()
{
  timespecs_t *time_specs = malloc(sizeof(timespecs_t));
  memset(time_specs, 0, sizeof(timespecs_t));
  return time_specs;
}

/* Marks an time count start point in a strucutre */
void start_time_count(timespecs_t *specs) 
{
  gettimeofday(&specs->day_time_begin, NULL);
  getrusage(RUSAGE_SELF, &specs->resource_time_begin);
}

/* Ends a time couting loop based on the mark previously
   saved in a structure and on the current time value.
   Further, the function sum the time difference to the 
   time values already present int that structure */
void stop_time_count(timespecs_t *specs) 
{
  gettimeofday(&specs->day_time_end, NULL);
  getrusage(RUSAGE_SELF, &specs->resource_time_end);

  struct timeval day_timeDiff = time_diff(specs->day_time_begin, specs->day_time_end);
  struct timeval user_timeDiff = time_diff(specs->resource_time_begin.ru_utime,
      specs->resource_time_end.ru_utime);
  struct timeval system_timeDiff = time_diff(specs->resource_time_begin.ru_stime,
      specs->resource_time_end.ru_stime);

  specs->day_time.tv_sec += day_timeDiff.tv_sec;
  specs->day_time.tv_usec += day_timeDiff.tv_usec;
  specs->user_time.tv_sec += user_timeDiff.tv_sec;
  specs->user_time.tv_usec += user_timeDiff.tv_usec;
  specs->system_time.tv_sec += system_timeDiff.tv_sec;
  specs->system_time.tv_usec += system_timeDiff.tv_usec;
}

/* Reset the time values of a structure */
void reset_time_count(timespecs_t *specs) 
{
  specs->system_time = (struct timeval){0, 0};
  specs->user_time = (struct timeval){0, 0};
  specs->day_time = (struct timeval){0, 0};
}

void erase_time_specs(timespecs_t *specs)
{
  free(specs);
}

void time_specs_print(timespecs_t *specs)
{
  printf("User time\t: %f ms\n", get_milliseconds(specs->user_time));
  printf("System time\t: %f ms\n", get_milliseconds(specs->system_time));
  printf("Total time\t: %f ms\n", get_milliseconds(specs->day_time));
}

void write_time_per_size(FILE *user, FILE *system, FILE *total,timespecs_t *specs,int m, int n)
{
  fprintf(user,"%d\t%d\t%f\n",m,n,get_milliseconds(specs->user_time));
  fprintf(system,"%d\t%d\t%f\n",m,n,get_milliseconds(specs->system_time));
  fprintf(total,"%d\t%d\t%f\n",m,n,get_milliseconds(specs->day_time));
}