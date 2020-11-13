//
// Created by konrad on 05.10.2020.
//

#ifndef NATIONALCPP_MULTITICKET_H
#define NATIONALCPP_MULTITICKET_H

#include "../store/Store.h"
#include "../utils/types.h"
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
  void addReservation(TicketBase *ticket_link);
  void removeById(IDType target_id);

  // FIXME operators
  MultiTicket *operator+=(TicketBase *other);
  MultiTicket *operator-=(TicketBase *other);

  // serialisation
  string toString() override;
  string serialize() override;

  static MultiTicket *deserialize(string data, Store<SingleTicket> *database);
};

#endif // NATIONALCPP_MULTITICKET_H
