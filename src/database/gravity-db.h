/* Pi-hole: A black hole for Internet advertisements
*  (c) 2019 Pi-hole, LLC (https://pi-hole.net)
*  Network-wide ad blocking via your own hardware.
*
*  FTL Engine
*  gravity database prototypes
*
*  This file is copyright under the latest version of the EUPL.
*  Please see LICENSE file for your rights under this license. */
#ifndef GRAVITY_H
#define GRAVITY_H

// clients data structure
#include "../datastructure.h"
// enum http_method
#include "../webserver/http-common.h"
// Definition of struct regexData
#include "../regex_r.h"

// Table row record, not all fields are used by all tables
typedef struct {
	bool enabled;
	int type_int;
	const char *name;
	const char *domain;
	const char *address;
	const char *type;
	const char *comment;
	const char *group_ids;
	const char *description;
	const char *argument;
	const char *oldtype;
	const char *ip;
	const char *item;
	long id;
	time_t date_added;
	time_t date_modified;
} tablerow;

void gravityDB_forked(void);
void gravityDB_reopen(void);
bool gravityDB_open(void);
void gravityDB_reload_groups(clientsData* client);
bool gravityDB_prepare_client_statements(clientsData* client);
void gravityDB_close(void);
bool gravityDB_getTable(unsigned char list);
const char* gravityDB_getDomain(int *rowid);
char* get_client_names_from_ids(const char *group_ids) __attribute__ ((malloc));
void gravityDB_finalizeTable(void);
int gravityDB_count(const enum gravity_tables list);
bool in_auditlist(const char *domain);

bool in_gravity(const char *domain, clientsData* client);
bool in_blacklist(const char *domain, clientsData* client);
bool in_whitelist(const char *domain, const DNSCacheData *dns_cache, clientsData* client);

bool gravityDB_get_regex_client_groups(clientsData* client, const unsigned int numregex, const regexData *regex,
                                       const unsigned char type, const char* table);

bool gravityDB_readTable(const enum gravity_list_type listtype, const char *filter, const char **message);
bool gravityDB_readTableGetRow(tablerow *row, const char **message);
void gravityDB_readTableFinalize(void);
bool gravityDB_addToTable(const enum gravity_list_type listtype, tablerow *row,
                          const char **message, const enum http_method method);
bool gravityDB_delFromTable(const enum gravity_list_type listtype, const char* domain_name, const char **message);
bool gravityDB_edit_groups(const enum gravity_list_type listtype, cJSON *groups,
                           const tablerow *row, const char **message);

#endif //GRAVITY_H
