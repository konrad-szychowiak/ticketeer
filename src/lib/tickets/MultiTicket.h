//
// Created by konrad on 05.10.2020.
//

#ifndef NATIONALCPP_MULTITICKET_H
#define NATIONALCPP_MULTITICKET_H

#include "../../utils/types.h"
#include "TicketBase.h"
#include <iostream>
#include <map>
#include <string>

class MultiTicket : public TicketBase {
  std::map<IDType, TicketBase *> reservations;
  IDType id;

  typedef TicketBase super;

public:
  MultiTicket(IDType id, Cost cost) : super(id, cost) {}
  MultiTicket() = default;

  void addReservation(TicketBase *ticket_link) {
    this->reservations.insert(
        std::pair<IDType, TicketBase *>(ticket_link->getId(), ticket_link));
    this->setCost(this->getCost() + ticket_link->getCost());
  }

  string toString() override;

  MultiTicket *operator+(TicketBase *other) {
    this->addReservation(other);
    return this;
  }

  MultiTicket *operator+=(TicketBase *other) {
    this->addReservation(other);
    return this;
  }
};

#endif // NATIONALCPP_MULTITICKET_H
