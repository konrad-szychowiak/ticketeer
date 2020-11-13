//
// Created by konrad on 12.11.2020.
//

#ifndef NATIONALCPP_DATABASE_H
#define NATIONALCPP_DATABASE_H

#include "../utils/types.h"
#include "StoreInternalError.h"
#include <iostream>
#include <map>

using namespace std;

template <class T> class Store {
  typedef map<IDType, T *> StoreMap;
  typedef pair<IDType, T *> StoredPair;
  typedef pair<typename StoreMap::iterator, bool> InsertionController;

  StoreMap store;

  bool insert(T *ticket) {
    InsertionController controller;
    controller = this->store.insert(StoredPair(ticket->getId(), ticket));
    return controller.second;
  }

public:
  Store() = default;

  Store *add(T *ticket) {
    InsertionController controller;
    this->insert(ticket);
    return this;
  }

  Store *removeById(IDType id) {
    this->store.erase(id);
    return this;
  }

  T *at(IDType key) { return this->store[key]; }
  T *operator[](IDType key) { return this->store[key]; }
  Store<T> *operator+=(T *ticket) { this->add(ticket); return this; }
  Store<T> *operator-=(T *ticket) { this->removeById(ticket->getId()); return this; }

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

template <class StoredTicket> void Store<StoredTicket>::listAll() {
  for (auto &pair : this->store) {
    auto key = pair.first;
    printf("\x1b[33m%5u\x1b[0m ", key);
    cout << this->store[key]->toString() << endl;
  }
}

#endif // NATIONALCPP_DATABASE_H
