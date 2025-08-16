# minitalk

**minitalk** is a small project demonstrating inter-process communication in C using UNIX signals (`SIGUSR1` and `SIGUSR2`). The project consists of a server and a client, where the client sends a message to the server bit by bit.

## Description

- **server**: Receives messages from the client and prints them to standard output.
- **client**: Sends a string to the server, transmitting each character bit by bit using signals.

Bonus versions add delivery confirmation from the server to the client.

## Build

To build the project, run:

```sh
make
```

To build the bonus versions:

```sh
make bonus
```

## Usage

### Server

Start the server:

```sh
./server
```

The server will print its PID, which you need for the client.

### Client

Send a message to the server:

```sh
./client <server_pid> <message>
```

### Bonus Versions

- `server_bonus` and `client_bonus` work the same way, but the client prints a confirmation message when the server receives the message.

## Files

- server.c — main server
- client.c — main client
- server_bonus.c — server with delivery confirmation
- client_bonus.c — client with delivery confirmation
- utils.c — helper functions (ft_atoi, ft_putstr_fd, ft_putnbr_fd)
- handler.c — error handling
- minitalk.h — header file
- Makefile — build script

## Example

1. Start the server in one terminal:
    ```
    ./server
    ```
    Output:
    ```
    Server started, server pid is: 12345
    ```

2. In another terminal, send a message:
    ```
    ./client 12345 "Hello, world!"
    ```

## Requirements

- Linux
- C compiler (gcc/cc)
- Standard C libraries

## License

This project is for educational purposes.## Requirements

- Linux
- C compiler (gcc/cc)
- Standard C libraries

## License

This project is for educational purposes.
