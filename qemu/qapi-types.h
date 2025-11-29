/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * schema-defined QAPI types
 *
 * Copyright IBM, Corp. 2011
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 *
 */

#ifndef QAPI_TYPES_H
#define QAPI_TYPES_H

#include "qapi/qapi-types-core.h"

typedef struct NameInfo NameInfo;

typedef struct NameInfoList
{
    NameInfo *value;
    struct NameInfoList *next;
} NameInfoList;

typedef struct VersionInfo VersionInfo;

typedef struct VersionInfoList
{
    VersionInfo *value;
    struct VersionInfoList *next;
} VersionInfoList;

typedef struct KvmInfo KvmInfo;

typedef struct KvmInfoList
{
    KvmInfo *value;
    struct KvmInfoList *next;
} KvmInfoList;

extern const char *RunState_lookup[];
typedef enum RunState
{
    RUN_STATE_DEBUG = 0,
    RUN_STATE_INMIGRATE = 1,
    RUN_STATE_INTERNAL_ERROR = 2,
    RUN_STATE_IO_ERROR = 3,
    RUN_STATE_PAUSED = 4,
    RUN_STATE_POSTMIGRATE = 5,
    RUN_STATE_PRELAUNCH = 6,
    RUN_STATE_FINISH_MIGRATE = 7,
    RUN_STATE_RESTORE_VM = 8,
    RUN_STATE_RUNNING = 9,
    RUN_STATE_SAVE_VM = 10,
    RUN_STATE_SHUTDOWN = 11,
    RUN_STATE_WATCHDOG = 12,
    RUN_STATE_MAX = 13,
} RunState;

typedef struct StatusInfo StatusInfo;

typedef struct StatusInfoList
{
    StatusInfo *value;
    struct StatusInfoList *next;
} StatusInfoList;

typedef struct UuidInfo UuidInfo;

typedef struct UuidInfoList
{
    UuidInfo *value;
    struct UuidInfoList *next;
} UuidInfoList;

typedef struct ChardevInfo ChardevInfo;

typedef struct ChardevInfoList
{
    ChardevInfo *value;
    struct ChardevInfoList *next;
} ChardevInfoList;

typedef struct CommandInfo CommandInfo;

typedef struct CommandInfoList
{
    CommandInfo *value;
    struct CommandInfoList *next;
} CommandInfoList;

struct NameInfo
{
    bool has_name;
    char * name;
};

void qapi_free_NameInfoList(NameInfoList * obj);
void qapi_free_NameInfo(NameInfo * obj);

struct VersionInfo
{
    struct 
    {
        int64_t major;
        int64_t minor;
        int64_t micro;
    } qemu;
    char * package;
};

void qapi_free_VersionInfoList(VersionInfoList * obj);
void qapi_free_VersionInfo(VersionInfo * obj);

struct KvmInfo
{
    bool enabled;
    bool present;
};

void qapi_free_KvmInfoList(KvmInfoList * obj);
void qapi_free_KvmInfo(KvmInfo * obj);

struct StatusInfo
{
    bool running;
    bool singlestep;
    RunState status;
};

void qapi_free_StatusInfoList(StatusInfoList * obj);
void qapi_free_StatusInfo(StatusInfo * obj);

struct UuidInfo
{
    char * UUID;
};

void qapi_free_UuidInfoList(UuidInfoList * obj);
void qapi_free_UuidInfo(UuidInfo * obj);

struct ChardevInfo
{
    char * label;
    char * filename;
};

void qapi_free_ChardevInfoList(ChardevInfoList * obj);
void qapi_free_ChardevInfo(ChardevInfo * obj);

struct CommandInfo
{
    char * name;
};

void qapi_free_CommandInfoList(CommandInfoList * obj);
void qapi_free_CommandInfo(CommandInfo * obj);

#endif
