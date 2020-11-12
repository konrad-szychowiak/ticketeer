//
// Created by konrad on 12.11.2020.
//

#ifndef NATIONALCPP_DATABASE_H
#define NATIONALCPP_DATABASE_H

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

    if (!this->insert(ticket)) {
      throw "Already in store";
    }

    return this;
  }

  DataBase *removeById(IDType id) {
    this->store.erase(id);
    return this;
  }

  void listAll();
};

template <class StoredTicket> void DataBase<StoredTicket>::listAll() {
  for (auto &pair : this->store) {
    auto key = pair.first;
    printf("[\x1b[1m%5u] ", key);
    cout << this->store[key]->toString() << endl;
  }
}

#endif // NATIONALCPP_DATABASE_H
