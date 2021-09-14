## RabbitMQ Client Demos

### What?
A series of proof-of-concept programs which demonstrate how to read messages
from a RabbitMQ message queue using a variety of languages and RabbitMQ client
libraries.

### Why?
A few years ago, I worked on [a (very exciting) project](http://fakelove.tv/work/star-wars-premiere) whose front-end was
an [openFrameworks](http://openframeworks.cc/) application. Due to time/resource constraints, the
developers were unable to get the ofx application to pull messages directly
from the back-end's message queue. We ended up hacking together a Rube Goldberg
solution -- a Ruby program which read messages from RabbitMQ and passed them
to the ofx application via OSC -- which wound up being _good enough_. (For
anyone who may be interested in reading more about the problems we faced and
the solutions we came up with, a case study is available on [my website](http://peterdohertys.website/case-studies/star-wars-red-carpet-sound-off.html).)

That all being said, I've always wanted to revisit this project and try
rewriting the front-end/client program in a variety of other, simpler and,
potentially, more efficient languages.

So far, I've rewritten the client in C and Rust. These programs can be found in
the clients directory and instructions for building and running those programs
can be found in the nested READMEs.

This repository includes a program to publish messages to a message queue for
use in testing the client applications. Its source and instructions for
building and running it can be found in the producer directory.

### Conclusions
I'm ready to call this experiment a success. I was able to sucessfully
resurrect the project's back-end and get the client programs authenticating
against and pulling messages off the original queue.

I've learned a lot about the various ecosystems of the client languages and how
they might be used in similar projects in the future.
