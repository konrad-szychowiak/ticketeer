//
// Created by konrad on 12.11.2020.
//

#ifndef NATIONALCPP_CLI_H
#define NATIONALCPP_CLI_H
#include "../lib/DataBase.h"
#include "../lib/NavalTicket.h"
#include "../lib/PlaneTicket.h"
#include "../lib/TicketBase.h"
#include "../utils/db.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace cli {
template <typename T> T prompt(string message) {
  T foo;
  cout << message << " ";
  cin >> foo;
  return foo;
}

inline bool argcmp(int argc, char **argv, int pos, const char *pattern);

void print_help();
void list_all(db::SingleDB single, db::MultiDB multi, db::BaseDB reserved);
void add_reservation(db::SingleDB single, db::MultiDB multi,
                     db::BaseDB reserved);
void remove_reservation(db::SingleDB single, db::MultiDB multi,
                        db::BaseDB reserved);
void action(db::SingleDB single, db::MultiDB multi, db::BaseDB reserved);
void hello();
} // namespace cli

#endif // NATIONALCPP_CLI_H
