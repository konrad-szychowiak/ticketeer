//
// Created by konrad on 12.11.2020.
//

#include "cli.h"
void cli::print_help() {
  cout << "\x1b[37mhelp:" << endl
       << "+\treserve new ticket" << endl
       << "-\tcancel reservation" << endl
       << "l\tlist reservations" << endl
       << "\x1b[0m";
}

void cli::hello() {

  const char *AVAILABLE_SIN = "../database/single.csv";
  const char *AVAILABLE_MUL = "../database/multi.csv";
  const char *RESERVED = "../database/reserved.csv";

  auto single_tickets = new DataBase<SingleTicket>();
  auto multi_tickets = new DataBase<MultiTicket>();
  auto reserved_tickets = new DataBase<TicketBase>();

  single_tickets = db::load_single(AVAILABLE_SIN);
  multi_tickets = db::load_multi(AVAILABLE_MUL, single_tickets);

  reserved_tickets =
      db::load_relations(RESERVED, single_tickets, multi_tickets);

  print_help();
  action(single_tickets, multi_tickets, reserved_tickets);

  db::save_relations(RESERVED, reserved_tickets);
}
void cli::action(db::SingleDB single, db::MultiDB multi, db::BaseDB reserved) {
  auto act = prompt<char>("? What to do [+/-/l]");
  switch (act) {
  case '+':
    add_reservation(single, multi, reserved);
    break;
  case '-':
    remove_reservation(single, multi, reserved);
    break;
  case 'l':
    list_all(single, multi, reserved);
    break;
  default:
    exit(1);
  }
}
void cli::list_all(db::SingleDB single, db::MultiDB multi,
                   db::BaseDB reserved) {
  printf("\x1b[1m\x1b[1;33m%5s\x1b[0;1m %s\x1b[0m\n", "id", "AVAILABLE");
  single->listAll();
  multi->listAll();

  cout << "-----\n";

  printf("\x1b[1m\x1b[1;33m%5s\x1b[0;1m %s\x1b[0m\n", "id", "RESERVED");
  reserved->listAll();
}
bool cli::argcmp(int argc, char **argv, int pos, const char *pattern) {
  if (argc >= pos && strcmp(argv[pos], pattern) == 0)
    return true;
  return false;
}
void cli::add_reservation(db::SingleDB single, db::MultiDB multi,
                          db::BaseDB reserved) {
  cout << "\n\x1b[34m info\x1b[0m from:\n";
  printf("\x1b[1m\x1b[1;33m%5s\x1b[0;1m %s\x1b[0m\n", "id", "AVAILABLE");
  single->listAll();
  multi->listAll();

  auto target_id = prompt<IDType>(
      "\n    ? choose one ticket to make reservation. Ticket id:");

  if (single->has(target_id))
    reserved->add(single->at(target_id));
  else if (multi->has(target_id))
    reserved->add(multi->at(target_id));
  else {
    cerr << "There is no ticket with id " << target_id
         << " available for reservation!\n";
    exit(0);
  }

  cout << "\n\x1b[34m info\x1b[0m now you have following reservations:\n";
  printf("\x1b[1m\x1b[1;33m%5s\x1b[0;1m %s\x1b[0m\n", "id", "RESERVED");
  reserved->listAll();
}

void cli::remove_reservation(db::SingleDB single, db::MultiDB multi,
                             db::BaseDB reserved) {
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
}