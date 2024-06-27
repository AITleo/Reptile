#include <linux/kprobes.h>
#include "include/lookup.h"

void* (*kallsyms_lookup_name)(const char *name);

int find_kallsyms_lookup_name(void){
    // find the kallsyms_lookup_name function
	struct kprobe kp;
	char* symbol_name = "kallsyms_lookup_name";
	kp.symbol_name = symbol_name;
    register_kprobe(&kp);
    kallsyms_lookup_name = (void* (*)(const char*)) kp.addr;
    unregister_kprobe(&kp);
}

