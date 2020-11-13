//
// Created by konrad on 12.11.2020.
//

#ifndef NATIONALCPP_CLI_H
#define NATIONALCPP_CLI_H
#include "../lib/DataBase.h"
#include "../lib/tickets/NavalTicket.h"
#include "../lib/tickets/PlaneTicket.h"
#include "../lib/tickets/TicketBase.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace cli {

const string AVAILABLE = "database/available.csv";
const string RESERVED = "database/reserved.csv";

template <typename T> T prompt(string message) {
  T foo;
  cout << message << " ";
  cin >> foo;
  return foo;
}

inline bool argcmp(int argc, char **argv, int pos, const char *pattern) {
  if (argc >= pos && strcmp(argv[pos], pattern) == 0)
    return true;
  return false;
}

TicketBase *create_ticket(const char meta, string info);

void serialise_line(string line);

template <typename DB> void read_db(string file, DB *db) {
  fstream dataFile;
  string line = "n;1;23;a;b";
  serialise_line(line);
//  dataFile.open(file, ios::out);
//  while (!dataFile.eof()) {
//    cin >> line;
//    cout << "[line]\t" << line << endl;
//  }
}

void print_help();

template <typename DB> void list_all(DB *available, DB *reserved) {
  cout << "AVAILABLE:\n";
  available->listAll();
  cout << endl << "RESERVED:\n";
  available->listAll();
}

template <typename DB> void action(DB *available, DB *reserved) {
  auto act = prompt<char>("What to do? [+/-/l/a/C]");
  switch (act) {
  case '+':
    break;
  case '-':
    break;
  case 'l':
    list_all(available, reserved);
    break;
  case 'a':
    break;
  case 'C':
    return;
  default:
    throw "Wrong action";
  }
}

template <typename DB> void hello(DB *available, DB *reserved) {
  read_db(AVAILABLE, available);
  //  read_db(RESERVED, reserved);
  print_help();
  action(available, reserved);
}

} // namespace cli

#endif // NATIONALCPP_CLI_H
