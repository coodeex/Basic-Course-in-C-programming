#ifndef AALTO_MACROS_H
#define AALTO_MACROS_H

// Implement something here...
#define EQ3(a,b,c) ((a==b) ? ((b==c) ? 1 : 0) : 0)

#define MIN3(a,b,c) ((a<b && a<c) ? a : (b<a && b<c) ? b : c)

#endif
