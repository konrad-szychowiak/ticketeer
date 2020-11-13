//
// Created by konrad on 13.11.2020.
//

#ifndef TICKETEER_DB_H
#define TICKETEER_DB_H

#include "../lib/DataBase.h"
#include "../lib/MultiTicket.h"
#include "../lib/NavalTicket.h"
#include "../lib/PlaneTicket.h"
#include "../lib/TicketBase.h"

namespace db {
typedef DataBase<SingleTicket> *SingleDB;
typedef DataBase<MultiTicket> *MultiDB;
typedef DataBase<TicketBase> *BaseDB;

SingleTicket *create_simple_ticket(char meta, string info);
SingleTicket *deserialize_simple(string line);

SingleDB load_single(const char *file);
MultiDB load_multi(const char *file, SingleDB database);

void save_relations(const char *file_path, BaseDB database);
BaseDB load_relations(const char *file_path, SingleDB single, MultiDB multi);
} // namespace db

#endif // TICKETEER_DB_H
