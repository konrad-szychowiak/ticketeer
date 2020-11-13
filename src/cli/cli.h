//
// Created by konrad on 12.11.2020.
//

#ifndef NATIONALCPP_CLI_H
#define NATIONALCPP_CLI_H
#include "../lib/NavalTicket.h"
#include "../lib/PlaneTicket.h"
#include "../lib/TicketBase.h"
#include "../store/Store.h"
#include "../store/utils.h"
#include "globals.h"
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

void print_help();

void list(database::SingleDB single, database::MultiDB multi,
          database::BaseDB reserved);

void add(database::SingleDB single, database::MultiDB multi,
         database::BaseDB reserved);

void remove(database::SingleDB single, database::MultiDB multi,
            database::BaseDB reserved);

void action(database::SingleDB single, database::MultiDB multi,
            database::BaseDB reserved);

void hello();
} // namespace cli

#endif // NATIONALCPP_CLI_H
