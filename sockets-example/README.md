### Server-client socket implementation in C

An example of how you can implement server and client sockets in C.

The server code can process multiple clients, it uses fork() to create sub-processes so you can handle plenty of connections.
This is not the best approach, but was fun to try out and bombard with the "spam.sh" script.
