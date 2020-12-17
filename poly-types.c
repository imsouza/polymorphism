#include <stdio.h>
#include <stdbool.h>
#include "macros.h"

/* 
 * Defines a new structural type that contains two integers as fields. 
 * If a macro is instantiated with a parameter other than T, 
 * we will have a pair of elements of a different type
 */

// Parametric structure
typedef struct {
  int first;
  int second;
} pair_int;


/*
 * in this type, the address of any structure must be 
 * the same as the address of its first member
 */

// Inclusion structures
typedef struct {
  const char *field_parent;
} parent;


typedef struct {
  parent init;
  const char *field_chield;
} child;


bool pair_int_any(pair_int pair,    \
  bool (*predicate)(int)) {         \
  return predicate(pair.first) ||   \
  predicate(pair.second);           \
}


bool is_positive (int x) { 
  return x > 0; 
}


// For each pointer (child *) there will be a pointer to an instance (parent)
void display_inclusion (parent * this) {
  printf("%s\n", this->field_parent);
}


int main () {
  printf(">>> Parametric:\n");
  pair(int) obj;
  obj.first  = 1;
  obj.second = -1;
  printf("%i\n", any(int)(obj, is_positive));


  printf(">>> Inclusion:\n");
  child child_t;
  child_t.init.field_parent = "p";
  child_t.field_chield      = "c";
  display_inclusion((parent *) & child_t);


  printf(">>> Overload:\n");
  double arg1 = 0.11; int arg2 = 3;
  display(arg1);
  display(arg2);

  return 0;
}
