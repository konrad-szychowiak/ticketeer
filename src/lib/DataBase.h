//
// Created by konrad on 12.11.2020.
//

#ifndef NATIONALCPP_DATABASE_H
#define NATIONALCPP_DATABASE_H

#include "../utils/DBInternalError.h"
#include "../utils/types.h"
#include <iostream>
#include <map>

using namespace std;

template <class StoredTicket> class DataBase {
  typedef map<IDType, StoredTicket *> Store;
  typedef pair<IDType, StoredTicket *> StoredPair;
  typedef pair<typename Store::iterator, bool> InsertionController;

  Store store;

  bool insert(StoredTicket *ticket) {
    InsertionController controller;
    controller = this->store.insert(StoredPair(ticket->getId(), ticket));
    return controller.second;
  }

public:
  DataBase() = default;

  DataBase *add(StoredTicket *ticket) {
    InsertionController controller;

    this->insert(ticket);

    return this;
  }

  DataBase *removeById(IDType id) {
    this->store.erase(id);
    return this;
  }

  StoredTicket *at(IDType key) { return this->store[key]; }
  StoredTicket *operator[](IDType key) { return this->store[key]; }

  void listAll();

  bool has(IDType key) {
    if (this->store.count(key))
      return true;
    return false;
  }

  string serialize_keys() {
    string text = "";
    for (auto &pair : this->store) {
      auto key = pair.first;
      text += to_string(key) + ";";
    }
    return text;
  }

  string serialize() {
    string text = "";
    for (auto &pair : this->store) {
      auto key = pair.first;
      text += this->store[key]->serialize();
    }
    return text;
  }
};

template <class StoredTicket> void DataBase<StoredTicket>::listAll() {
  for (auto &pair : this->store) {
    auto key = pair.first;
    printf("\x1b[33m%5u\x1b[0m ", key);
    cout << this->store[key]->toString() << endl;
  }
}

#endif // NATIONALCPP_DATABASE_H
