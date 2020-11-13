//
// Created by konrad on 13.11.2020.
//

#ifndef TICKETEER_DB_H
#define TICKETEER_DB_H

#include "../lib/MultiTicket.h"
#include "../lib/NavalTicket.h"
#include "../lib/PlaneTicket.h"
#include "../lib/TicketBase.h"
#include "../store/Store.h"

namespace db {
typedef Store<SingleTicket> *SingleDB;
typedef Store<MultiTicket> *MultiDB;
typedef Store<TicketBase> *BaseDB;

SingleTicket *create_simple_ticket(char meta, string info);
SingleTicket *deserialize_simple(string line);

SingleDB load_single(const char *file);
MultiDB load_multi(const char *file, SingleDB database);

void save_relations(const char *file_path, BaseDB database);
BaseDB load_relations(const char *file_path, SingleDB single, MultiDB multi);
} // namespace db

#endif // TICKETEER_DB_H
