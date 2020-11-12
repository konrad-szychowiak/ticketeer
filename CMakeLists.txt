cmake_minimum_required(VERSION 3.17)
project(ticketeer)

set(CMAKE_CXX_STANDARD 20)

add_executable(ticketeer src/main.cpp src/lib/tickets/TicketBase.cpp src/lib/tickets/TicketBase.h src/lib/tickets/PlaneTicket.cpp src/lib/tickets/PlaneTicket.h src/lib/tickets/NavalTicket.cpp src/lib/tickets/NavalTicket.h src/lib/tickets/MultiTicket.cpp src/lib/tickets/MultiTicket.h src/lib/tickets/TicketBase.cpp src/lib/tickets/TicketBase.h src/lib/DataBase.h src/utils/globals.h src/cli/cli.cpp src/cli/cli.h src/lib/tickets/SingleTicket.cpp src/lib/tickets/SingleTicket.h src/utils/types.h)