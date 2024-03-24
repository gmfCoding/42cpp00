#ifdef DEBUG_STREAM
#define debugStream std::cout
#else
# define debugStream std::ostream(0)
#endif