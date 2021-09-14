 Linux下用gSOAP开发Web Service服务端和客户端程序

网上本有一篇流传甚广的C版本的，我参考来实现，发现有不少问题，现在根据自己的开发经验将其修改，使用无误；另外，补充同样功能的C++版本，我想这个应该更有用，因为能用C++，当然好过受限于C。

1、gSOAP的安装：

到http://sourceforge.net/projects/gsoap2/去下载最新版本，目前是：2.7.15

简单安装：

configure --prefix=/usr/local/gSOAP

       make

       make install

为了后面的C和C++版本的服务和客户端的开发能够脱离源代码目录，最好还要如下处理：

（1）将源代码目录下gsoap子目录中的import目录拷贝到gSOAP目录下来；

（2）gSOAP目录下建一个env目录，将gsoap/samples/link下的所有文件拷贝过来，并且生成envC.o（C版本要用到），方法是：

/usr/local/gSOAP/bin/soapcpp2 -penv -c env.h

g++ -c -I /usr/local/gSOAP/include envC.c

（3）gSOAP目录下建一个src目录，将将源代码目录下gsoap子目录中的stdsoap*.*拷贝过来。

 

2、功能说明：

       要开发的Web Service功能非常简单，就是一个add函数，将两个参数相加，返回其和。

3、C版本的程序:

（1）头文件：SmsWBS.h

//gsoap ns service name: SmsWBS
//gsoap ns service style: rpc
//gsoap ns service namespace: http://192.168.1.88:9000/SmsWBS.wsdl
//gsoap ns service location: http://192.168.1.88:9000
//gsoap ns service encoding: encoded
//gsoap ns schema namespace: urn:SmsWBS

int ns__add(int num1, int num2, int *sum);
这个头文件需要注意的是，前面的 // 部分是有意义的，可以在上面修改，如果完全去掉，将会导致生成的中间文件不同，由此会引起要修改Makefile文件                                           

（2）Makefile文件：

比较关键，如果头文件中的 // 部分有修改，要检查是否要修改Makefile文件

GSOAP_ROOT=/usr/local/gSOAP
WSNAME0=soap
WSNAME=SmsWBS
CC=g++ -g -DWITH_NONAMESPACES
INCLUDE=-I $(GSOAP_ROOT)/include
SERVER_OBJS=$(WSNAME0)C.o $(WSNAME0)Server.o stdsoap2.o
CLIENT_OBJS=$(GSOAP_ROOT)/env/envC.o $(WSNAME0)ClientLib.o stdsoap2.o
ALL_OBJS=${WSNAME}server.o $(WSNAME0)C.o $(WSNAME0)Server.o ${WSNAME}test.o $(WSNAME0)ClientLib.o
#GSOAP_SRC=/usr/local/gsoap-2.7/gsoap

all:server

${WSNAME}.wsdl:${WSNAME}.h
        $(GSOAP_ROOT)/bin/soapcpp2 -c $(GSOAP_ROOT)/import ${WSNAME}.h

stdsoap2.o:$(GSOAP_ROOT)/src/stdsoap2.c
        $(CC) -c $? $(INCLUDE)

$(ALL_OBJS):%.o:%.c
        $(CC) -c $? $(INCLUDE)

server:Makefile ${WSNAME}.wsdl ${WSNAME}server.o $(SERVER_OBJS)
        $(CC) ${WSNAME}server.o $(SERVER_OBJS) -o ${WSNAME}server

client:Makefile ${WSNAME}.wsdl ${WSNAME}test.c $(ALL_OBJS) stdsoap2.o
        $(CC) ${WSNAME}test.o $(CLIENT_OBJS) -o ${WSNAME}test

clean:
        rm -f *.o *.xml *.a *.wsdl *.nsmap $(WSNAME0)H.h $(WSNAME0)C.c $(WSNAME0)Server.c $(WSNAME0)Client.c $(WSNAME0)Stub.* $(WSNAME)$(WSNAME)Proxy.* $(WSNAME)$(WSNAME)Object.* $(WSNAME0)ServerLib.c $(WSNAME0)ClientLib.c $(WSNAME)server ns.xsd $(WSNAME)test

 

（3）服务端程序SmsWBSserver.c：

#include "soapH.h"
#include "SmsWBS.nsmap"

int main(int argc, char **argv)
{
        int m, s;               /* master and slave sockets */
        struct soap SmsWBS_soap;

        soap_init(&SmsWBS_soap);

        soap_set_namespaces(&SmsWBS_soap, namespaces);

        if (argc < 2)
        {
                printf("usage: %s <server_port> \n", argv[0]);
                exit(1);
        }
        else
        {
                m = soap_bind(&SmsWBS_soap, NULL, atoi(argv[1]), 100);
                if (m < 0)
                {
                        soap_print_fault(&SmsWBS_soap, stderr);
                        exit(-1);
                }

                fprintf(stderr, "Socket connection successful: master socket = %d\n", m);

                for (;;)
                {
                        s = soap_accept(&SmsWBS_soap);

                        if (s < 0)
                        {
                                soap_print_fault(&SmsWBS_soap, stderr);
                                exit(-1);
                        }

                        fprintf(stderr, "Socket connection successful: slave socket = %d\n", s);
                        soap_serve(&SmsWBS_soap);
                        soap_end(&SmsWBS_soap);
                }

       }

        return 0;
}

int ns__add(struct soap *add_soap, int num1, int num2, int *sum)
{
        *sum = num1 + num2;
        return 0;
}

 

（4）客户端程序SmsWBStest.c：

#include <stdio.h>
#include <stdlib.h>
#include "soapStub.h"
#include "SmsWBS.nsmap"

int add(const char *server, int num1, int num2, int *sum);

int add(const char *server, int num1, int num2, int *sum)
{
        struct soap SmsWBS_soap;
        int result = 0;

        soap_init(&SmsWBS_soap);
        soap_set_namespaces(&SmsWBS_soap, namespaces);

        soap_call_ns__add(&SmsWBS_soap, server, "", num1, num2, sum);

        if(SmsWBS_soap.error)
        {
                printf("soap error:%d, %s, %s ", SmsWBS_soap.error, *soap_faultcode(&SmsWBS_soap), *soap_faultstring(&SmsWBS_soap));
                result = SmsWBS_soap.error;
         }

        soap_end(&SmsWBS_soap);
        soap_done(&SmsWBS_soap);

        return result;
}

int main(int argc, char **argv)
{
        int result = -1;
        char* server="http://localhost:9000";

        int num1 = 0;
        int num2 = 0;
        int sum = 0;

        if( argc < 3 )
        {
                printf("usage: %s num1 num2 \n", argv[0]);
                exit(0);

        }

        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);

        result = add(server, num1, num2, &sum);
        if (result != 0)
        {
                printf("soap err, errcode = %d \n", result);
        }
        else
        {
                printf("%d + %d = %d \n", num1, num2, sum);
        }

        return 0;
}

（5）编译和运行：

前面都已经准备好了，现在只需要：

make                                     ---得到服务端程序SmsWBSserver

make client                            ---得到客户端程序SmsWBStest

SmsWBSserver 9000             ----运行服务端程序

出来类似下面的显示就表示运行正常

Socket connection successful: master socket = 3

再运行客户端程序：

SmsWBStest 67 78

显示：

67 + 78 = 145

调用Web Service成功

 
续（二）

接（一）

 4、C++版本的程序:

（1）头文件不变，还是SmsWBS.h

（2）Makefile文件：

GSOAP_ROOT=/usr/local/gSOAP
WSNAME0=soap
WSNAME=SmsWBS
CC=g++ -g -DWITH_NONAMESPACES
INCLUDE=-I $(GSOAP_ROOT)/include
SERVER_OBJS=$(WSNAME0)C.o $(WSNAME0)$(WSNAME)Service.o stdsoap2.o
CLIENT_OBJS=$(WSNAME0)$(WSNAME)Proxy.o $(WSNAME0)C.o stdsoap2.o
ALL_OBJS=${WSNAME}server.o $(WSNAME0)C.o $(WSNAME0)$(WSNAME)Service.o $(WSNAME0)$(WSNAME)Proxy.o ${WSNAME}test.o
#GSOAP_SRC=/usr/local/gsoap-2.7/gsoap

all:server

${WSNAME}.wsdl:${WSNAME}.h
        $(GSOAP_ROOT)/bin/soapcpp2 -i $(GSOAP_ROOT)/import ${WSNAME}.h

stdsoap2.o:$(GSOAP_ROOT)/src/stdsoap2.cpp
        $(CC) -c $? $(INCLUDE)

$(ALL_OBJS):%.o:%.cpp
        $(CC) -c $? $(INCLUDE)

server:Makefile ${WSNAME}.wsdl ${WSNAME}server.o $(SERVER_OBJS)
        $(CC) ${WSNAME}server.o $(SERVER_OBJS) -o ${WSNAME}server

client:Makefile ${WSNAME}.wsdl ${WSNAME}test.cpp $(ALL_OBJS) stdsoap2.o
        $(CC) ${WSNAME}test.o $(CLIENT_OBJS) -o ${WSNAME}test

clean:
        rm -f *.o *.xml *.a *.wsdl *.nsmap $(WSNAME0)H.h $(WSNAME0)C.cpp $(WSNAME0)Server.cpp  $(WSNAME0)Stub.* $(WSNAME0)$(WSNAME)S
ervice.* $(WSNAME0)$(WSNAME)Proxy.* $(WSNAME0)$(WSNAME)Object.* $(WSNAME0)ServerLib.cpp $(WSNAME0)ClientLib.cpp $(WSNAME)server ns.x
sd $(WSNAME)test

（3）服务端程序SmsWBSserver.cpp：

#include "soapSmsWBSService.h"
#include "SmsWBS.nsmap"

int main(int argc, char **argv)
{ 
 SmsWBSService sms;

 if (argc < 2)
  sms.serve();       /* serve as CGI application */
 else
 { 
  int port = atoi(argv[1]);

  if (!port)
  { 
   fprintf(stderr, "Usage: SmsWBSserver++ <port>\n");
   exit(0);
  }

  /* run iterative server on port until fatal error */
  if (sms.run(port))
  { 
   sms.soap_stream_fault(std::cerr);
   exit(-1);
  }
 }

 return 0;
}

int SmsWBSService::add(int num1, int num2, int *sum)
{
 *sum = num1 + num2;
 return SOAP_OK;
}

（4）客户端程序SmsWBStest.cpp：

#include <stdio.h>
#include <stdlib.h>
#include "soapSmsWBSProxy.h"
#include "SmsWBS.nsmap"

int main(int argc, char **argv)
{
        int result = -1;
        char* server="http://localhost:9000";

        int num1 = 0;
        int num2 = 0;
        int sum = 0;

        if( argc < 3 )
        {
                printf("usage: %s num1 num2 \n", argv[0]);
                exit(0);
        }

        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);

        SmsWBSProxy  sms;
        result = sms.add(num1, num2, &sum);
        if (result != 0)
        {
                printf("soap err, errcode = %d \n", result);
        }
        else
        {
                printf("%d + %d = %d \n", num1, num2, sum);
        }

        return 0;
}

（5）编译运行，与C版本类似，只是服务端运行时没有提示信息

续（三）

接（二）

5、方便其它平台调用Web Service服务所需要做的工作:

以上的C和C++版本的Web Service服务端运行后，在本机或者其它机（windows系统也一样）浏览器中输入http://192.168.1.88:9000/SmsWBS?wsdl，会返回XML文件内容，但是并无Web Service的功能函数描述，原因是尚未实现允许客户端通过http的get操作来获取 SmsWBS.wsdl文件。因此，需要补充实现这一部分，以C++版本为例，完善后的SmsWBSserver.cpp程序是：

#include "soapSmsWBSService.h"
#include "SmsWBS.nsmap"

int http_get(struct soap * soap);

int main(int argc, char **argv)
{ 
 SmsWBSService sms;

 if (argc < 2)
  sms.serve();       /* serve as CGI application */
 else
 { 
  int port = atoi(argv[1]);

  if (!port)
  { 
   fprintf(stderr, "Usage: SmsWBSserver++ <port>\n");
   exit(0);
  }

  /* run iterative server on port until fatal error */
  sms.fget = http_get;

  if (sms.run(port))
  { 
   sms.soap_stream_fault(std::cerr);
   exit(-1);
  }
 }

 return 0;
}

int SmsWBSService::add(int num1, int num2, int *sum)
{
 *sum = num1 + num2;
 return SOAP_OK;
}

//能够远程读取wsdl文件
int http_get(struct soap * soap)
{ 
 FILE *fd = NULL;

 char *s = strchr(soap->path, '?');
 if (!s || strcmp(s, "?wsdl"))
  return SOAP_GET_METHOD;

 fd = fopen("SmsWBS.wsdl", "rb");

 if (!fd)
  return 404;

 soap->http_content = "text/xml";

 soap_response(soap, SOAP_FILE);

 for (;;)
 { 
 size_t r = fread(soap->tmpbuf, 1, sizeof(soap->tmpbuf), fd);
 if (!r)
   break;
 if (soap_send_raw(soap, soap->tmpbuf, r))
   break; 
 }

 fclose(fd);
 soap_end_send(soap);

 return SOAP_OK;
}


重新将服务端编译，运行后http://192.168.1.88:9000/SmsWBS?wsdl能够获取到完整的SmsWBS.wsdl。

至此，可以在windows下的VC++.Net项目中通过“添加WEB 引用”来方便地生成客户端类文件，从而调用Web Service服务端的功能。

