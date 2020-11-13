//
// Created by konrad on 12.11.2020.
//

#define DATABASES single, multi, reserved

#include "cli.h"
void cli::print_help() {
  cout << "\x1b[37m"
       << "help:" << endl
       << "+\treserve new ticket" << endl
       << "-\tcancel reservation" << endl
       << "l\tlist reservations" << endl
       << "\x1b[0m";
}

void cli::hello() {

  const char *AVAILABLE_SIN = "../database/single.csv";
  const char *AVAILABLE_MUL = "../database/multi.csv";
  const char *RESERVED = "../database/reserved.csv";

  auto single_tickets = new Store<SingleTicket>();
  auto multi_tickets = new Store<MultiTicket>();
  auto reserved_tickets = new Store<TicketBase>();

  single_tickets = database::load_single(AVAILABLE_SIN);
  multi_tickets = database::load_multi(AVAILABLE_MUL, single_tickets);

  reserved_tickets =
      database::load_relations(RESERVED, single_tickets, multi_tickets);

  print_help();
  action(single_tickets, multi_tickets, reserved_tickets);

  database::save_relations(RESERVED, reserved_tickets);

  delete single_tickets;
  delete multi_tickets;
  delete reserved_tickets;
}

void cli::action(database::SingleDB single, database::MultiDB multi,
                 database::BaseDB reserved) {

  switch (prompt<char>("? What to do [+/-/l]")) {
  case '+':
    add(DATABASES);

  case '-':
    remove(DATABASES);

  case 'l':
    list(DATABASES);

  default:
    cerr << "Wrong action. Try again. Terminated.";
    exit(0);
  }
}

void cli::list(database::SingleDB single, database::MultiDB multi,
               database::BaseDB reserved) {
  printf("\x1b[1m\x1b[1;33m%5s\x1b[0;1m %s\x1b[0m\n", "id", "AVAILABLE");
  single->listAll();
  multi->listAll();

  cout << "-----\n";

  printf("\x1b[1m\x1b[1;33m%5s\x1b[0;1m %s\x1b[0m\n", "id", "RESERVED");
  reserved->listAll();

  exit(0);
}

void cli::add(database::SingleDB single, database::MultiDB multi,
              database::BaseDB reserved) {

  cout << "\n\x1b[34m info\x1b[0m from:\n";
  printf("\x1b[1m\x1b[1;33m%5s\x1b[0;1m %s\x1b[0m\n", "id", "AVAILABLE");

  single->listAll();
  multi->listAll();

  auto target_id = prompt<IDType>(
      "\n    ? choose one ticket to make reservation. Ticket id:");

  if (single->has(target_id))
    *reserved += single->at(target_id);

  else if (multi->has(target_id))
    *reserved += multi->at(target_id);

  else {
    cerr << "There is no ticket with id " << target_id
         << " available for reservation!\n";
    exit(0);
  }

  cout << "\n\x1b[34m info\x1b[0m now you have following reservations:\n";
  printf("\x1b[1m\x1b[1;33m%5s\x1b[0;1m %s\x1b[0m\n", "id", "RESERVED");
  reserved->listAll();
}

void cli::remove(database::SingleDB single, database::MultiDB multi,
                 database::BaseDB reserved) {
  cout << "\n\x1b[34m info\x1b[0m from:\n";
  printf("\x1b[1m\x1b[1;33m%5s\x1b[0;1m %s\x1b[0m\n", "id", "RESERVED");
  reserved->listAll();

  auto target_id = prompt<IDType>(
      "\n    ? choose one reservation to cancel. Reservation id:");

  if (reserved->has(target_id))
    reserved->removeById(target_id);

  else {
    cerr << "There is no ticket with id " << target_id << " in reservations!\n";
    exit(0);
  }

  cout << "\n\x1b[34m info\x1b[0m now you have following reservations:\n";
  printf("\x1b[1m\x1b[1;33m%5s\x1b[0;1m %s\x1b[0m\n", "id", "RESERVED");
  reserved->listAll();

  exit(0);
}