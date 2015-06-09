#include <ftw.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Test for callback functions in little and big-endian modes.
   Since standard libraries are expected to be little-endian, they
   will call callbacks with parameters in little-endian format.

   Although this test will work for a gcc-compiled binary on a BE
   system, that's just because gcc doesn't understand the pragmas
   or attributes, so it's just compiling everything big-endian.
 */

/* ignore warnings about bad pragmas and attributes */
#pragma warning disable 181
#pragma warning disable 161
#pragma GCC diagnostic ignored "-Wattributes"

int attributed_comparison(const void * __attribute__((littleendian)) a, const void * __attribute__((littleendian)) b)
{
  unsigned int *ia = (unsigned int*) a;
  unsigned int *ib = (unsigned int*) b;
  if(*ia < *ib) return -1;
  if(*ib < *ia) return 1;
  return 0;
}

#pragma byte_order littleendian

int pragmad_comparison(const void *a, const void *b)
{
  // Note that this sorts in the reverse order of attributed_comparison, so we can tell it did something.
  unsigned int *ia = (unsigned int*) a;
  unsigned int *ib = (unsigned int*) b;
  if(*ia < *ib) return 1;
  if(*ib < *ia) return -1;
  return 0;
}

int ftw_callback(const char *fpath, const struct stat *sb, int typeflag)
{
  int mode = sb->st_mode;
  // This is an unpleasant check, but it avoids having to duplicate fpath for basename
  if(strstr(fpath, __FILE__) == fpath + strlen(fpath) - strlen(__FILE__)) {
    printf("ftw_callback: path = %s mode=%o\n", __FILE__, mode);
  }
  return 0;
}

#pragma byte_order bigendian


int main()
{
  unsigned int values[] = { 2, 4, 6, 8, 1, 3, 5, 7};
  int i;
  qsort(values, 8L, sizeof(unsigned int), attributed_comparison);

  for(i=0;i<8;i++) {
    printf("Value %d: %u\n", i, values[i]);
  }

  qsort(values, 8L, sizeof(unsigned int), pragmad_comparison);

  for(i=0;i<8;i++) {
    printf("Value %d: %u\n", i, values[i]);
  }

  // Slightly more complicated test now:
  ftw(".", ftw_callback, 1);
}
