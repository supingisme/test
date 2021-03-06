/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2019, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/

/* <DESC>
 * IMAP example showing how to send e-mails IMAP（Internet Mail Access Protocol）以前称作交互邮件访问协议
 * </DESC>
 */

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

/* This is a simple example showing how to send mail using libcurl's IMAP
 * capabilities.
 *
 * Note that this example requires libcurl 7.30.0 or above.
 */

//#define FROM    "<sender@example.org>"
//#define TO      "<addressee@example.net>"
//#define CC      "<info@example.org>"

#define FROM    "<rongtao@sylincom.com>"
#define TO      "<rongtao@sylincom.com>"
#define CC      "<rongtao@sylincom.com>"

static const char *payload_text[] = {
  "Date: Mon, 29 Nov 2010 21:54:29 +1100\r\n",
  "To: " TO "\r\n",
  "From: " FROM "(Example User)\r\n",
  "Cc: " CC "(Another example User)\r\n",
  "Message-ID: "
  "<dcd7cb36-11db-487a-9f3a-e652a9458efd@rfcpedant.example.org>\r\n",
  "Subject: IMAP example message\r\n",
  "\r\n", /* empty line to divide headers from body, see RFC5322 */
  "The body of the message starts here.\r\n",
  "\r\n",
  "It could be a lot of lines, could be MIME encoded, whatever.\r\n",
  "Check RFC5322.\r\n",
  NULL
};

struct upload_status {
  int lines_read;
};

static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
  struct upload_status *upload_ctx = (struct upload_status *)userp;
  const char *data;

  if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) {
    return 0;
  }

  data = payload_text[upload_ctx->lines_read];

  if(data) {
    size_t len = strlen(data);
    memcpy(ptr, data, len);
    upload_ctx->lines_read++;

    return len;
  }

  return 0;
}

int main(void)
{
  CURL *curl;
  CURLcode res = CURLE_OK;

  curl = curl_easy_init();
  if(curl) {
    const char **p;
    long infilesize;
    struct upload_status upload_ctx;

    upload_ctx.lines_read = 0;

    /* Set username and password */
    curl_easy_setopt(curl, CURLOPT_USERNAME, "rongtao");
    curl_easy_setopt(curl, CURLOPT_PASSWORD, "rt123#@!");

    /* This will create a new message 100. Note that you should perform an
     * EXAMINE command to obtain the UID of the next message to create and a
     * SELECT to ensure you are creating the message in the OUTBOX. */
    curl_easy_setopt(curl, CURLOPT_URL, "imap://mail.sylincom.com:993");

    /* In this case, we're using a callback function to specify the data. You
     * could just use the CURLOPT_READDATA option to specify a FILE pointer to
     * read from. */
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
    curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

    infilesize = 0;
    for(p = payload_text; *p; ++p) {
      infilesize += (long)strlen(*p);
    }
    curl_easy_setopt(curl, CURLOPT_INFILESIZE, infilesize);

    /* Perform the append */
    res = curl_easy_perform(curl);

    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* Always cleanup */
    curl_easy_cleanup(curl);
  }

  return (int)res;
}
