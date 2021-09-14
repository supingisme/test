/*
* ***** BEGIN LICENSE BLOCK *****
* Version: MIT
*
* Portions created by Peter Doherty are Copyright (c) 2018 Peter Doherty. All
* Rights Reserved.
*
* Portions created by Alan Antonuk are Copyright (c) 2012-2013
* Alan Antonuk. All Rights Reserved.
*
* Portions created by VMware are Copyright (c) 2007-2012 VMware, Inc.
* All Rights Reserved.
*
* Portions created by Tony Garnock-Jones are Copyright (c) 2009-2010
* VMware, Inc. and Tony Garnock-Jones. All Rights Reserved.
*
* Permission is hereby granted, free of charge, to any person
* obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use, copy,
* modify, merge, publish, distribute, sublicense, and/or sell copies
* of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
* BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* ***** END LICENSE BLOCK *****
*/

#include <amqp.h>
#include <amqp_tcp_socket.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main(int argc, char const *const *argv) {
int port,
status;
char const *bindingkey,
*exchange,
*hostname,
*password,
*username;
  amqp_socket_t *socket = NULL;
  amqp_connection_state_t conn;
  amqp_bytes_t queuename;

  if (argc < 5) {
    fprintf(stderr, "Usage: amqp_listen host port exchange bindingkey\n");
    return 1;
  }

  hostname = argv[1];
  port = atoi(argv[2]);
  exchange = argv[3];
  bindingkey = argv[4];

  username = getenv("RABBITMQ_USERNAME");
  if (!username) {
    die("$RABBITMQ_USERNAME is required.");
  }

  password = getenv("RABBITMQ_PASSWORD");
  if (!password) {
    die("$RABBITMQ_PASSWORD is required.");
  }

  conn = amqp_new_connection();

  socket = amqp_tcp_socket_new(conn);
  if (!socket) {
    die("creating TCP socket");
  }

  status = amqp_socket_open(socket, hostname, port);
  if (status) {
    die("opening TCP socket");
  }

  die_on_amqp_error(amqp_login(conn,
                               "/",
                               0,
                               131072,
                               0,
                               AMQP_SASL_METHOD_PLAIN,
                               username,
                               password), "Logging in");
  amqp_channel_open(conn, 1);
  die_on_amqp_error(amqp_get_rpc_reply(conn), "Opening channel");

  // presumably required because queuename is being redefined?
  {
    amqp_queue_declare_ok_t *r = amqp_queue_declare(conn,
                                                    1,
                                                    amqp_empty_bytes,
                                                    0,
                                                    0,
                                                    0,
                                                    1,
                                                    amqp_empty_table);
    die_on_amqp_error(amqp_get_rpc_reply(conn), "Declaring queue");
    queuename = amqp_bytes_malloc_dup(r->queue);

    if (queuename.bytes == NULL) {
      fprintf(stderr, "Out of memory while copying queue name");
      return 1;
    }
  }

  amqp_queue_bind(conn,
                  1,
                  queuename,
                  amqp_cstring_bytes(exchange),
                  amqp_cstring_bytes(bindingkey),
                  amqp_empty_table);
  die_on_amqp_error(amqp_get_rpc_reply(conn), "Binding queue");

  amqp_basic_consume(conn,
                     1,
                     queuename,
                     amqp_empty_bytes,
                     0,
                     0,
                     0,
                     amqp_empty_table);
  die_on_amqp_error(amqp_get_rpc_reply(conn), "Consuming");

  for (;;) {
    amqp_rpc_reply_t res;
    amqp_envelope_t envelope;
    char *message_body;
    int message_body_length;

    amqp_maybe_release_buffers(conn);

    res = amqp_consume_message(conn, &envelope, NULL, 0);

    if (AMQP_RESPONSE_NORMAL != res.reply_type) {
      break;
    }

    message_body = envelope.message.body.bytes;
    message_body_length = envelope.message.body.len;
    message_body[message_body_length] = '\0';

    printf("Message body: %s\n", message_body);

    amqp_destroy_envelope(&envelope);
  }

  die_on_amqp_error(amqp_channel_close(conn, 1, AMQP_REPLY_SUCCESS),
                    "Closing channel");
  die_on_amqp_error(amqp_connection_close(conn, AMQP_REPLY_SUCCESS),
                    "Closing connection");
  die_on_error(amqp_destroy_connection(conn), "Ending connection");
}
