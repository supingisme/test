# Sample RabbitMQ Message Producer
This is a simple RabbitMQ message producer capable of pushing messages to a direct exchange for use by the RabbitMQ client demos found in this repository.

## Dependencies
- librabbitmq-dev

## Build
`make`

## Setup
Create RabbitMQ user with appropriate permissions (e.g. can access virtual host)

## Run
`RABBITMQ_USERNAME=abc RABBITMQ_PASSWORD=xyz ./producer.exe localhost 5672 test-exchange test-routing-key "hello world"`

## Sources
Publisher code is derived from https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_producer.c
