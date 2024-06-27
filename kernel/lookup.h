#ifndef LOOKUP_H
#define LOOKUP_H


int find_kallsyms_lookup_name(void);

extern void* (*kallsyms_lookup_name)(const char *name);

#endif // LOOKUP_H
