//! Parametric definitions
#define pair(T) pair_##T

#define any(T) pair_##T##_any

DEFINE_PAIR(int);

/**
 * Overload definitions
 * Chooses a specific format appropriate for printf 
 * based on the type of the argument passed
 */
#define display_arg(x) (_Generic ((x), \
  int:     "%i",\
  double:  "%f",\
  char:    "%c",\
  default: "%x"))

#define display(x) printf(display_arg(x), x); puts("");

