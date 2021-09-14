/* soapH.h
   Generated by gSOAP 2.8.16 from calc.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapH_H
#define soapH_H
#include "soapStub.h"
#ifdef __cplusplus
extern "C" {
#endif
#ifndef WITH_NOIDREF
SOAP_FMAC3 void SOAP_FMAC4 soap_markelement(struct soap*, const void*, int);
SOAP_FMAC3 int SOAP_FMAC4 soap_putindependent(struct soap*);
SOAP_FMAC3 int SOAP_FMAC4 soap_getindependent(struct soap*);
#endif
SOAP_FMAC3 void *SOAP_FMAC4 soap_getelement(struct soap*, int*);
SOAP_FMAC3 int SOAP_FMAC4 soap_putelement(struct soap*, const void*, const char*, int, int);
SOAP_FMAC3 int SOAP_FMAC4 soap_ignore_element(struct soap*);

SOAP_FMAC3 const char ** SOAP_FMAC4 soap_faultcode(struct soap *soap);

#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (3)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_byte(struct soap*, char *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_byte(struct soap*, const char*, int, const char *, const char*);
SOAP_FMAC3 char * SOAP_FMAC4 soap_in_byte(struct soap*, const char*, char *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_byte(struct soap*, const char *, const char*, const char*);

#ifndef soap_write_byte
#define soap_write_byte(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_byte(soap, data),0) || soap_put_byte(soap, data, "byte", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 char * SOAP_FMAC4 soap_get_byte(struct soap*, char *, const char*, const char*);

#ifndef soap_read_byte
#define soap_read_byte(soap, data) ( soap_begin_recv(soap) || !soap_get_byte(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_int(struct soap*, int *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_int(struct soap*, const char*, int, const int *, const char*);
SOAP_FMAC3 int * SOAP_FMAC4 soap_in_int(struct soap*, const char*, int *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_int(struct soap*, const int *, const char*, const char*);

#ifndef soap_write_int
#define soap_write_int(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_int(soap, data),0) || soap_put_int(soap, data, "int", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 int * SOAP_FMAC4 soap_get_int(struct soap*, int *, const char*, const char*);

#ifndef soap_read_int
#define soap_read_int(soap, data) ( soap_begin_recv(soap) || !soap_get_int(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_double
#define SOAP_TYPE_double (7)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_double(struct soap*, double *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_double(struct soap*, const char*, int, const double *, const char*);
SOAP_FMAC3 double * SOAP_FMAC4 soap_in_double(struct soap*, const char*, double *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_double(struct soap*, const double *, const char*, const char*);

#ifndef soap_write_double
#define soap_write_double(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_double(soap, data),0) || soap_put_double(soap, data, "double", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 double * SOAP_FMAC4 soap_get_double(struct soap*, double *, const char*, const char*);

#ifndef soap_read_double
#define soap_read_double(soap, data) ( soap_begin_recv(soap) || !soap_get_double(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (31)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Fault(struct soap*, const char*, int, const struct SOAP_ENV__Fault *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_in_SOAP_ENV__Fault(struct soap*, const char*, struct SOAP_ENV__Fault *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Fault
#define soap_write_SOAP_ENV__Fault(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Fault(soap, data),0) || soap_put_SOAP_ENV__Fault(soap, data, "SOAP-ENV:Fault", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_get_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Fault
#define soap_read_SOAP_ENV__Fault(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Fault(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (30)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Reason(struct soap*, const char*, int, const struct SOAP_ENV__Reason *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_in_SOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Reason
#define soap_write_SOAP_ENV__Reason(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Reason(soap, data),0) || soap_put_SOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_get_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Reason
#define soap_read_SOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (27)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Detail(struct soap*, const char*, int, const struct SOAP_ENV__Detail *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_in_SOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Detail
#define soap_write_SOAP_ENV__Detail(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Detail(soap, data),0) || soap_put_SOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_get_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Detail
#define soap_read_SOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (25)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Code(struct soap*, const char*, int, const struct SOAP_ENV__Code *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_in_SOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Code
#define soap_write_SOAP_ENV__Code(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Code(soap, data),0) || soap_put_SOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_get_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Code
#define soap_read_SOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (24)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Header(struct soap*, const char*, int, const struct SOAP_ENV__Header *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_in_SOAP_ENV__Header(struct soap*, const char*, struct SOAP_ENV__Header *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Header
#define soap_write_SOAP_ENV__Header(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Header(soap, data),0) || soap_put_SOAP_ENV__Header(soap, data, "SOAP-ENV:Header", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_get_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Header
#define soap_read_SOAP_ENV__Header(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Header(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef SOAP_TYPE_ns2__pow
#define SOAP_TYPE_ns2__pow (23)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns2__pow(struct soap*, struct ns2__pow *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns2__pow(struct soap*, const struct ns2__pow *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns2__pow(struct soap*, const char*, int, const struct ns2__pow *, const char*);
SOAP_FMAC3 struct ns2__pow * SOAP_FMAC4 soap_in_ns2__pow(struct soap*, const char*, struct ns2__pow *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns2__pow(struct soap*, const struct ns2__pow *, const char*, const char*);

#ifndef soap_write_ns2__pow
#define soap_write_ns2__pow(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns2__pow(soap, data),0) || soap_put_ns2__pow(soap, data, "ns2:pow", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns2__pow * SOAP_FMAC4 soap_get_ns2__pow(struct soap*, struct ns2__pow *, const char*, const char*);

#ifndef soap_read_ns2__pow
#define soap_read_ns2__pow(soap, data) ( soap_begin_recv(soap) || !soap_get_ns2__pow(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ns2__powResponse
#define SOAP_TYPE_ns2__powResponse (22)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns2__powResponse(struct soap*, struct ns2__powResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns2__powResponse(struct soap*, const struct ns2__powResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns2__powResponse(struct soap*, const char*, int, const struct ns2__powResponse *, const char*);
SOAP_FMAC3 struct ns2__powResponse * SOAP_FMAC4 soap_in_ns2__powResponse(struct soap*, const char*, struct ns2__powResponse *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns2__powResponse(struct soap*, const struct ns2__powResponse *, const char*, const char*);

#ifndef soap_write_ns2__powResponse
#define soap_write_ns2__powResponse(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns2__powResponse(soap, data),0) || soap_put_ns2__powResponse(soap, data, "ns2:powResponse", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns2__powResponse * SOAP_FMAC4 soap_get_ns2__powResponse(struct soap*, struct ns2__powResponse *, const char*, const char*);

#ifndef soap_read_ns2__powResponse
#define soap_read_ns2__powResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ns2__powResponse(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ns2__div
#define SOAP_TYPE_ns2__div (20)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns2__div(struct soap*, struct ns2__div *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns2__div(struct soap*, const struct ns2__div *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns2__div(struct soap*, const char*, int, const struct ns2__div *, const char*);
SOAP_FMAC3 struct ns2__div * SOAP_FMAC4 soap_in_ns2__div(struct soap*, const char*, struct ns2__div *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns2__div(struct soap*, const struct ns2__div *, const char*, const char*);

#ifndef soap_write_ns2__div
#define soap_write_ns2__div(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns2__div(soap, data),0) || soap_put_ns2__div(soap, data, "ns2:div", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns2__div * SOAP_FMAC4 soap_get_ns2__div(struct soap*, struct ns2__div *, const char*, const char*);

#ifndef soap_read_ns2__div
#define soap_read_ns2__div(soap, data) ( soap_begin_recv(soap) || !soap_get_ns2__div(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ns2__divResponse
#define SOAP_TYPE_ns2__divResponse (19)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns2__divResponse(struct soap*, struct ns2__divResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns2__divResponse(struct soap*, const struct ns2__divResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns2__divResponse(struct soap*, const char*, int, const struct ns2__divResponse *, const char*);
SOAP_FMAC3 struct ns2__divResponse * SOAP_FMAC4 soap_in_ns2__divResponse(struct soap*, const char*, struct ns2__divResponse *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns2__divResponse(struct soap*, const struct ns2__divResponse *, const char*, const char*);

#ifndef soap_write_ns2__divResponse
#define soap_write_ns2__divResponse(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns2__divResponse(soap, data),0) || soap_put_ns2__divResponse(soap, data, "ns2:divResponse", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns2__divResponse * SOAP_FMAC4 soap_get_ns2__divResponse(struct soap*, struct ns2__divResponse *, const char*, const char*);

#ifndef soap_read_ns2__divResponse
#define soap_read_ns2__divResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ns2__divResponse(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ns2__mul
#define SOAP_TYPE_ns2__mul (17)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns2__mul(struct soap*, struct ns2__mul *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns2__mul(struct soap*, const struct ns2__mul *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns2__mul(struct soap*, const char*, int, const struct ns2__mul *, const char*);
SOAP_FMAC3 struct ns2__mul * SOAP_FMAC4 soap_in_ns2__mul(struct soap*, const char*, struct ns2__mul *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns2__mul(struct soap*, const struct ns2__mul *, const char*, const char*);

#ifndef soap_write_ns2__mul
#define soap_write_ns2__mul(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns2__mul(soap, data),0) || soap_put_ns2__mul(soap, data, "ns2:mul", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns2__mul * SOAP_FMAC4 soap_get_ns2__mul(struct soap*, struct ns2__mul *, const char*, const char*);

#ifndef soap_read_ns2__mul
#define soap_read_ns2__mul(soap, data) ( soap_begin_recv(soap) || !soap_get_ns2__mul(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ns2__mulResponse
#define SOAP_TYPE_ns2__mulResponse (16)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns2__mulResponse(struct soap*, struct ns2__mulResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns2__mulResponse(struct soap*, const struct ns2__mulResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns2__mulResponse(struct soap*, const char*, int, const struct ns2__mulResponse *, const char*);
SOAP_FMAC3 struct ns2__mulResponse * SOAP_FMAC4 soap_in_ns2__mulResponse(struct soap*, const char*, struct ns2__mulResponse *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns2__mulResponse(struct soap*, const struct ns2__mulResponse *, const char*, const char*);

#ifndef soap_write_ns2__mulResponse
#define soap_write_ns2__mulResponse(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns2__mulResponse(soap, data),0) || soap_put_ns2__mulResponse(soap, data, "ns2:mulResponse", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns2__mulResponse * SOAP_FMAC4 soap_get_ns2__mulResponse(struct soap*, struct ns2__mulResponse *, const char*, const char*);

#ifndef soap_read_ns2__mulResponse
#define soap_read_ns2__mulResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ns2__mulResponse(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ns2__sub
#define SOAP_TYPE_ns2__sub (14)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns2__sub(struct soap*, struct ns2__sub *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns2__sub(struct soap*, const struct ns2__sub *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns2__sub(struct soap*, const char*, int, const struct ns2__sub *, const char*);
SOAP_FMAC3 struct ns2__sub * SOAP_FMAC4 soap_in_ns2__sub(struct soap*, const char*, struct ns2__sub *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns2__sub(struct soap*, const struct ns2__sub *, const char*, const char*);

#ifndef soap_write_ns2__sub
#define soap_write_ns2__sub(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns2__sub(soap, data),0) || soap_put_ns2__sub(soap, data, "ns2:sub", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns2__sub * SOAP_FMAC4 soap_get_ns2__sub(struct soap*, struct ns2__sub *, const char*, const char*);

#ifndef soap_read_ns2__sub
#define soap_read_ns2__sub(soap, data) ( soap_begin_recv(soap) || !soap_get_ns2__sub(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ns2__subResponse
#define SOAP_TYPE_ns2__subResponse (13)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns2__subResponse(struct soap*, struct ns2__subResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns2__subResponse(struct soap*, const struct ns2__subResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns2__subResponse(struct soap*, const char*, int, const struct ns2__subResponse *, const char*);
SOAP_FMAC3 struct ns2__subResponse * SOAP_FMAC4 soap_in_ns2__subResponse(struct soap*, const char*, struct ns2__subResponse *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns2__subResponse(struct soap*, const struct ns2__subResponse *, const char*, const char*);

#ifndef soap_write_ns2__subResponse
#define soap_write_ns2__subResponse(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns2__subResponse(soap, data),0) || soap_put_ns2__subResponse(soap, data, "ns2:subResponse", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns2__subResponse * SOAP_FMAC4 soap_get_ns2__subResponse(struct soap*, struct ns2__subResponse *, const char*, const char*);

#ifndef soap_read_ns2__subResponse
#define soap_read_ns2__subResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ns2__subResponse(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ns2__add
#define SOAP_TYPE_ns2__add (11)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns2__add(struct soap*, struct ns2__add *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns2__add(struct soap*, const struct ns2__add *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns2__add(struct soap*, const char*, int, const struct ns2__add *, const char*);
SOAP_FMAC3 struct ns2__add * SOAP_FMAC4 soap_in_ns2__add(struct soap*, const char*, struct ns2__add *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns2__add(struct soap*, const struct ns2__add *, const char*, const char*);

#ifndef soap_write_ns2__add
#define soap_write_ns2__add(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns2__add(soap, data),0) || soap_put_ns2__add(soap, data, "ns2:add", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns2__add * SOAP_FMAC4 soap_get_ns2__add(struct soap*, struct ns2__add *, const char*, const char*);

#ifndef soap_read_ns2__add
#define soap_read_ns2__add(soap, data) ( soap_begin_recv(soap) || !soap_get_ns2__add(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ns2__addResponse
#define SOAP_TYPE_ns2__addResponse (10)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns2__addResponse(struct soap*, struct ns2__addResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns2__addResponse(struct soap*, const struct ns2__addResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns2__addResponse(struct soap*, const char*, int, const struct ns2__addResponse *, const char*);
SOAP_FMAC3 struct ns2__addResponse * SOAP_FMAC4 soap_in_ns2__addResponse(struct soap*, const char*, struct ns2__addResponse *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns2__addResponse(struct soap*, const struct ns2__addResponse *, const char*, const char*);

#ifndef soap_write_ns2__addResponse
#define soap_write_ns2__addResponse(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns2__addResponse(soap, data),0) || soap_put_ns2__addResponse(soap, data, "ns2:addResponse", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns2__addResponse * SOAP_FMAC4 soap_get_ns2__addResponse(struct soap*, struct ns2__addResponse *, const char*, const char*);

#ifndef soap_read_ns2__addResponse
#define soap_read_ns2__addResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ns2__addResponse(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (33)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Reason(struct soap*, const char *, int, struct SOAP_ENV__Reason *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*, const char*, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Reason
#define soap_write_PointerToSOAP_ENV__Reason(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Reason(soap, data),0) || soap_put_PointerToSOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason **, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Reason
#define soap_read_PointerToSOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (32)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Detail(struct soap*, const char *, int, struct SOAP_ENV__Detail *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*, const char*, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Detail
#define soap_write_PointerToSOAP_ENV__Detail(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Detail(soap, data),0) || soap_put_PointerToSOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail **, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Detail
#define soap_read_PointerToSOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (26)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Code(struct soap*, const char *, int, struct SOAP_ENV__Code *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*, const char*, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Code
#define soap_write_PointerToSOAP_ENV__Code(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Code(soap, data),0) || soap_put_PointerToSOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code **, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Code
#define soap_read_PointerToSOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef SOAP_TYPE_PointerTodouble
#define SOAP_TYPE_PointerTodouble (8)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerTodouble(struct soap*, double *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerTodouble(struct soap*, const char *, int, double *const*, const char *);
SOAP_FMAC3 double ** SOAP_FMAC4 soap_in_PointerTodouble(struct soap*, const char*, double **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerTodouble(struct soap*, double *const*, const char*, const char*);

#ifndef soap_write_PointerTodouble
#define soap_write_PointerTodouble(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerTodouble(soap, data),0) || soap_put_PointerTodouble(soap, data, "double", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 double ** SOAP_FMAC4 soap_get_PointerTodouble(struct soap*, double **, const char*, const char*);

#ifndef soap_read_PointerTodouble
#define soap_read_PointerTodouble(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerTodouble(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
#endif

#define soap_default__QName(soap, a) soap_default_string(soap, a)

SOAP_FMAC3 void SOAP_FMAC4 soap_serialize__QName(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out__QName(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in__QName(struct soap*, const char*, char **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put__QName(struct soap*, char *const*, const char*, const char*);

#ifndef soap_write__QName
#define soap_write__QName(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize__QName(soap, data),0) || soap_put__QName(soap, data, "byte", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get__QName(struct soap*, char **, const char*, const char*);

#ifndef soap_read__QName
#define soap_read__QName(soap, data) ( soap_begin_recv(soap) || !soap_get__QName(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (4)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_string(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_string(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_string(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in_string(struct soap*, const char*, char **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_string(struct soap*, char *const*, const char*, const char*);

#ifndef soap_write_string
#define soap_write_string(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_string(soap, data),0) || soap_put_string(soap, data, "byte", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get_string(struct soap*, char **, const char*, const char*);

#ifndef soap_read_string
#define soap_read_string(soap, data) ( soap_begin_recv(soap) || !soap_get_string(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifdef __cplusplus
}
#endif

#endif

/* End of soapH.h */
