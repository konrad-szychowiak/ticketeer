//
// Created by konrad on 05.10.2020.
//

#ifndef NATIONALCPP_MULTITICKET_H
#define NATIONALCPP_MULTITICKET_H

#include "../store/Store.h"
#include "../types/types.h"
#include "SingleTicket.h"
#include "TicketBase.h"
#include <iostream>
#include <map>
#include <string>

class MultiTicket : public TicketBase {
  std::map<IDType, TicketBase *> reservations;

  typedef TicketBase super;

public:
  static const char META = 'm';

  MultiTicket(IDType id, Cost cost) : super(id, cost) {}
  MultiTicket() = default;

  // reservation handling
  void add(TicketBase *ticket_link);
  void removeById(IDType target_id);

  // operators
  MultiTicket *operator+=(TicketBase *other);
  MultiTicket *operator-=(TicketBase *other);

  // serialization
  string toString() override;
  string stringify() override;
  static MultiTicket *parse(string data, Store<SingleTicket> *database);
};

#endif // NATIONALCPP_MULTITICKET_H
