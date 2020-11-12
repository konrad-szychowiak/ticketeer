//
// Created by konrad on 12.11.2020.
//

#ifndef NATIONALCPP_CLI_H
#define NATIONALCPP_CLI_H
#include <cstdio>
#include <cstring>

#include "../lib/DataBase.h"

using namespace std;

namespace cli {

inline bool argcmp(int argc, char **argv, int pos, const char *pattern) {
  if (argc >= pos && strcmp(argv[pos], pattern) == 0)
    return true;
  return false;
}

template <class T> void list(DataBase<T> *db) {
  cout << "\x1b[1m===RESERVATIONS===\x1b[0m\n";
  db->listAll();
};

} // namespace cli

#endif // NATIONALCPP_CLI_H
