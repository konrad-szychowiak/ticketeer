//
// Created by konrad on 05.10.2020.
//

#ifndef NATIONALCPP_NAVALTICKET_H
#define NATIONALCPP_NAVALTICKET_H

#include "SingleTicket.h"

class NavalTicket : public SingleTicket {
private:
  typedef SingleTicket super;

public:
  NavalTicket(std::string from, std::string to, float cost, int id)
      : super(id, cost, std::move(from), std::move(to)) {}

  string toString() {
    return "Cruise from `" + this->getFrom() + "' to `" + this->getTo() + "' " +
           super::toString();
  }
};

#endif // NATIONALCPP_NAVALTICKET_H
