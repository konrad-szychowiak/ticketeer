//
// Created by konrad on 05.10.2020.
//

#include "PlaneTicket.h"

PlaneTicket::PlaneTicket(IDType id, Cost cost, std::string from, std::string to)
    : super(id, cost, std::move(from), std::move(to)) {}

string PlaneTicket::toString() {
  return "Flight from `" + this->getFrom() + "' to `" + this->getTo() + "' " +
         super::toString();
}
