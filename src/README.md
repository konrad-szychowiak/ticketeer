#️ Structure 

> Entrypoint: `src/main.cpp`

## Primitive types aliases (`src/types/types.h`)

+ `IDType` is `int`
+ `Const` is `float`

Can be changed in one place to tweak data usage.

Note that `string::stoi()` and `string::stof()`
are used for parsing those from CSV files.
Pay extra attention when changing aliases to types unrelated to the above. 

## Tickets (`src/lib/`)

+ _abstract_ `TicketBase`: shares `id: IDType` and `cost: Cost`
    + _abstract_ `SingleTicket`: shares `from` and `to`
        + `PlaneTicket`
        + `NavalTicket`
    + `MultiTicket`: can hold multiple (0+) of all the above; **cannot** hold other `MultiTicket`s. 
 
 ## Store (`src/store/`)
 
 > backend
 
 + `class Store<T>`: stores pointers to tickets fo type `T`
 + `StoreInternalError`: for errors, whilst using stored data
 + `utils.(h|cpp)`: collection of functions for handling communication between application's `Store`s and CSV files.
 
 ## CLI (`src/cli/`)
 
 > frontend
 
 Collection of functions for handling user-application communications.
 