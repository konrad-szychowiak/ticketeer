//
// Created by konrad on 12.11.2020.
//

#ifndef NATIONALCPP_SINGLETICKET_H
#define NATIONALCPP_SINGLETICKET_H

#include <iostream>
#include <string>
#include <utility>

#include "../types/types.h"
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
  SingleTicket(IDType id, Cost cost, string from, string to);

  string getFrom() const;
  void setFrom(std::string value);

  string getTo() const;
  void setTo(std::string value);

  string toString() override;
  string stringify() override;
};

#endif // NATIONALCPP_SINGLETICKET_H
