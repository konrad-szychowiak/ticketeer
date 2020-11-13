//
// Created by konrad on 12.11.2020.
//

#define DATABASES single, multi, reserved

#define AVAILABLE_STR "AVAILABLE"
#define RESERVED_STR "RESERVED"
#define ID_PROMPT "\n    ? choose one ticket to make reservation. Ticket id:"

#include "cli.h"
#include "globals.h"

void cli::print_help() {
  cout << "\x1b[37m"
       << "help:" << endl
       << "+\treserve new ticket" << endl
       << "-\tcancel reservation" << endl
       << "l\tlist reservations" << endl
       << "x\texit" << endl
       << "\x1b[0m";
}

void cli::hello() {
  auto single_tickets = new Store<SingleTicket>();
  auto multi_tickets = new Store<MultiTicket>();
  auto reserved_tickets = new Store<TicketBase>();

  try {
    single_tickets = database::load_single(AVAILABLE_SIN);
    multi_tickets = database::load_multi(AVAILABLE_MUL, single_tickets);

    reserved_tickets =
        database::load_relations(RESERVED, single_tickets, multi_tickets);

    while (true) {
      print_help();
      action(single_tickets, multi_tickets, reserved_tickets);
    }

    database::save_relations(RESERVED, reserved_tickets);
  } catch (StoreInternalError &e) {
    cerr << "error " << e.what() << endl;
  }

  delete single_tickets;
  delete multi_tickets;
  delete reserved_tickets;
}

void cli::action(database::SingleDB single, database::MultiDB multi,
                 database::BaseDB reserved) {

  switch (prompt<char>("? What to do [+/-/l/x]")) {
  case '+':
    add(DATABASES);
    break;

  case '-':
    remove(DATABASES);
    break;

  case 'l':
    list(DATABASES);
    break;

  case 'x':
    database::save_relations(RESERVED, reserved);
    exit(0);

  default:
    cerr << "Wrong action. Try again. Terminated.";
  }
}

void cli::list(database::SingleDB single, database::MultiDB multi,
               database::BaseDB reserved) {
  listing_header(AVAILABLE_STR);
  single->listAll();
  multi->listAll();

  cout << "-----\n";

  listing_header(RESERVED_STR);
  reserved->listAll();
}

void cli::add(database::SingleDB single, database::MultiDB multi,
              database::BaseDB reserved) {

  listing_header(AVAILABLE_STR);
  single->listAll();
  multi->listAll();

  auto target_id = prompt<IDType>(ID_PROMPT);

  if (single->has(target_id))
    *reserved += single->at(target_id);

  else if (multi->has(target_id))
    *reserved += multi->at(target_id);

  else {
    cerr << "There is no ticket with id " << target_id
         << " available for reservation! Nothing changed.\n";
  }

  info("now you have following reservations:");
  listing_header("RESERVED");
  reserved->listAll();
}

void cli::remove(database::SingleDB single, database::MultiDB multi,
                 database::BaseDB reserved) {

  listing_header(AVAILABLE_STR);
  reserved->listAll();

  auto target_id = prompt<IDType>(ID_PROMPT);

  if (reserved->has(target_id))
    reserved->removeById(target_id);

  else {
    cerr << "There is no ticket with id " << target_id
         << " in reservations! Nothing changed.\n";
  }

  info("now you have following reservations:");
  listing_header(RESERVED_STR);
  reserved->listAll();
}

void cli::listing_header(const string &description) {
  printf("\x1b[1m\x1b[1;33m%5s\x1b[0;1m %s\x1b[0m\n", "id",
         description.c_str());
}

void cli::info(string msg) { cout << "\n\x1b[34m info\x1b[0m " << msg << endl; }
