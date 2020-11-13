//
// Created by konrad on 05.10.2020.
//

#ifndef NATIONALCPP_TICKETBASE_H
#define NATIONALCPP_TICKETBASE_H

#include "../types/types.h"
#include <string>
#include <utility>

using namespace std;

class TicketBase {
private:
  IDType id;
  Cost cost;

public:
  TicketBase(IDType id, Cost cost);
  TicketBase() = default;

  // id
  [[nodiscard]] IDType getId() const;

  // cost
  [[nodiscard]] float getCost() const;
  void setCost(float value);

  // serialization
  virtual string toString();
  virtual string stringify();

  static string getField(string &fields);
};

#endif // NATIONALCPP_TICKETBASE_H
