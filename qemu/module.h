#ifndef QEMU_MODULE_H
#define QEMU_MODULE_H

typedef enum {
    MODULE_INIT_BLOCK,
    MODULE_INIT_DEVICE,
    MODULE_INIT_MACHINE,
    MODULE_INIT_QAPI,
    MODULE_INIT_MAX
} module_init_type;

void register_module_init(void (*fn)(void), module_init_type type);
void module_call_init(module_init_type type);

#ifndef _MSC_VER

/* GCC / Clang */
#define module_init(function, type)                                         \
    static void __attribute__((constructor))                                \
    do_qemu_init_##function(void)                                           \
    {                                                                       \
        register_module_init(function, type);                               \
    }

#else  /* _MSC_VER */

/* MSVC: use .CRT$XCU constructors */
typedef void(__cdecl* qemu_constructor_t)(void);

#pragma section(".CRT$XCU", read)

#define module_init(function, type)                                         \
    static void __cdecl                                                     \
    do_qemu_init_##function(void)                                           \
    {                                                                       \
        register_module_init(function, type);                               \
    }                                                                       \
    __declspec(allocate(".CRT$XCU"))                                        \
    static qemu_constructor_t                                               \
        do_qemu_init_##function##_ = do_qemu_init_##function

#endif /* _MSC_VER */

#define block_init(function)   module_init(function, MODULE_INIT_BLOCK)
#define device_init(function)  module_init(function, MODULE_INIT_DEVICE)
#define machine_init(function) module_init(function, MODULE_INIT_MACHINE)
#define qapi_init(function)    module_init(function, MODULE_INIT_QAPI)

#endif /* QEMU_MODULE_H */
