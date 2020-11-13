//
// Created by konrad on 12.11.2020.
//

#include "cli.h"
void cli::print_help() {
  cout << "HELP:" << endl
       << "+\treserve new ticket" << endl
       << "-\tcancel reservation" << endl
       << "\x1b[32;1ml\x1b[0m\tlist reservations" << endl
       << "a\tadd new available reservation to the database" << endl
       << "C\tcancel" << endl;
}

TicketBase *cli::create_ticket(const char meta, string info) {
  switch (meta) {
  case PlaneTicket::meta:
    return PlaneTicket::deserialise(info);
  default:
    return nullptr;
  }
}

void cli::serialise_line(string line) {
  const char line_meta = line.substr(0, 1)[0];
  cout << create_ticket(line_meta, line.substr(2))->toString();
}
