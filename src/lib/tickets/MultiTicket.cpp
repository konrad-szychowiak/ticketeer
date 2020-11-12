//
// Created by konrad on 05.10.2020.
//

#include "MultiTicket.h"

string MultiTicket::toString() {
  string text = "Multiple directions " + super::toString();
  for (auto const &pair : this->reservations) {
    auto key = pair.first;
    printf("[\x1b[1m%5u] ", key);
    cout << this->reservations[key]->toString() << "\n";
  }

  return text;
}
