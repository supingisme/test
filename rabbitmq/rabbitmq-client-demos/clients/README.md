## Sample RabbitMQ Message Consumer
This example contains a RabbitMQ client written in C. It uses the librabbitmq
shared object library to interface with the RabbitMQ message broker.

The program listens for messages using a direct exchange ("test-exchange")
using the "test-routing-key" routing key.

My demo relies _heavily_ on the [amqp_listen](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_listen.c) example provided by the
[rabbitmq-c project](https://github.com/alanxz/rabbitmq-c). The (marginally) interesting modifications include: use
of environment variables, client authentication and storing the contents of
message bodies for use in other parts of the program (in the program mentioned
above, the message body would be used to determine which set of videos should
be shown on the display wall). These are admittely all pretty trivial, but I
feel good about the experience: the program itself, reading through the
library's source, working with the C toolchain, etc.

## Dependencies
- librabbitmq-dev

## Build
`make`

## Run
`RABBITMQ_USERNAME=abc RABBITMQ_PASSWORD=xyz ./client.exe localhost 5672 test-exchange test-routing-key "hello world"`
