#ifndef DEBUG_H
#define DEBUG_H

#define TRACE() printf("[Trace] %s %d\n", __FUNCTION__, __LINE__)
#define ERROR() printf("[Error] %s %d\n", __FUNCTION__, __LINE__)

#endif