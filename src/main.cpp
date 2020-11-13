#include "./cli/cli.h"
#include "./lib/DataBase.h"
#include "./lib/tickets/MultiTicket.h"
#include "./lib/tickets/PlaneTicket.h"

using namespace cli;

int main(int argc, char **argv) {
  auto available = new DataBase<TicketBase>();
  auto reserved = new DataBase<TicketBase>();

  cli::hello(available, reserved);

  return 0;
}
