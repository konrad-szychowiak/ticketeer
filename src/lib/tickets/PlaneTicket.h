//
// Created by konrad on 05.10.2020.
//

#ifndef NATIONALCPP_PLANETICKET_H
#define NATIONALCPP_PLANETICKET_H

#include "SingleTicket.h"
#include <string>
#include <utility>

using namespace std;

class PlaneTicket : public SingleTicket {
private:
  typedef SingleTicket super;

public:
  PlaneTicket(std::string from, std::string to, float cost, int id)
      : super(id, cost, std::move(from), std::move(to)) {}

  string toString() override {
    return "Flight from `" + this->getFrom() + "' to `" + this->getTo() + "' " +
           super::toString();
  }
};

#endif // NATIONALCPP_PLANETICKET_H
