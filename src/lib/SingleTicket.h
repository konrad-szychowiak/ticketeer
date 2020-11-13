//
// Created by konrad on 12.11.2020.
//

#ifndef NATIONALCPP_SINGLETICKET_H
#define NATIONALCPP_SINGLETICKET_H

#include <iostream>
#include <string>
#include <utility>

#include "../utils/types.h"
#include "./TicketBase.h"

using namespace std;

struct Travel {
  IDType id;
  Cost cost;
  string from, to;
};

class SingleTicket : public TicketBase {
  string from;
  string to;

  typedef TicketBase super;

public:
  SingleTicket(IDType id, Cost cost, string from, string to) : super(id, cost) {
    this->from = std::move(from);
    this->to = std::move(to);
  }

  string getFrom() const { return this->from; }
  void setFrom(std::string value) { this->from = std::move(value); }

  string getTo() const { return this->to; }
  void setTo(std::string value) { this->to = std::move(value); }

  string toString() override {
    return ", from `" + this->getFrom() + "' to `" + this->getTo() + "'" +
           super::toString();
  }

  string serialize() override {
    return ";" + to_string(this->getId()) + ";" + to_string(this->getCost()) +
           ";" + this->from + ";" + this->to + ";\n";
  }
};

#endif // NATIONALCPP_SINGLETICKET_H
