/*
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	Copyright (C) 2012-2014 PIVA SOFTWARE (www.pivasoftware.com)
 *		Author: Mohamed Kallel <mohamed.kallel@pivasoftware.com>
 *		Author: Anis Ellouze <anis.ellouze@pivasoftware.com>
 *	Copyright (C) 2011-2012 Luka Perkov <freecwmp@lukaperkov.net>
 *	Copyright (C) 2012 Jonas Gorski <jogo@openwrt.org>
 */

#include <stdbool.h>
#include <libubox/uloop.h>
#include <microxml.h>

#include "xml.h"
#include "backup.h"
#include "config.h"
#include "cwmp.h"
#include "external.h"
#include "easycwmp.h"
#include "messages.h"
#include "easycwmp_time.h"
#include "json.h"
#include "log.h"

#include "tr069_cwmp_api.h"

struct fault_code fault_array[]=
{
	[FAULT_0]	 = {"0", "", ""},
	[FAULT_9000] = {"9000", "Server", "Method not supported"},
	[FAULT_9001] = {"9001", "Server", "Request denied"},
	[FAULT_9002] = {"9002", "Server", "Internal error"},
	[FAULT_9003] = {"9003", "Client", "Invalid arguments"},
	[FAULT_9004] = {"9004", "Server", "Resources exceeded"},
	[FAULT_9005] = {"9005", "Client", "Invalid parameter name"},
	[FAULT_9006] = {"9006", "Client", "Invalid parameter type"},
	[FAULT_9007] = {"9007", "Client", "Invalid parameter value"},
	[FAULT_9008] = {"9008", "Client", "Attempt to set a non-writable parameter"},
	[FAULT_9009] = {"9009", "Server", "Notification request rejected"},
	[FAULT_9010] = {"9010", "Server", "Download failure"},
	[FAULT_9011] = {"9011", "Server", "Upload failure"},
	[FAULT_9012] = {"9012", "Server", "File transfer server authentication failure"},
	[FAULT_9013] = {"9013", "Server", "Unsupported protocol for file transfer"},
	[FAULT_9014] = {"9014", "Server", "Download failure: unable to join multicast group"},
	[FAULT_9015] = {"9015", "Server", "Download failure: unable to contact file server"},
	[FAULT_9016] = {"9016", "Server", "Download failure: unable to access file"},
	[FAULT_9017] = {"9017", "Server", "Download failure: unable to complete download"},
	[FAULT_9018] = {"9018", "Server", "Download failure: file corrupted"},
	[FAULT_9019] = {"9019", "Server", "Download failure: file authentication failure"}
};

const static char *soap_env_url = "http://schemas.xmlsoap.org/soap/envelope/";
const static char *soap_enc_url = "http://schemas.xmlsoap.org/soap/encoding/";
const static char *xsd_url = "http://www.w3.org/2001/XMLSchema";
const static char *xsi_url = "http://www.w3.org/2001/XMLSchema-instance";
const static char *cwmp_urls[] = {
		"urn:dslforum-org:cwmp-1-0", 
		"urn:dslforum-org:cwmp-1-1", 
		"urn:dslforum-org:cwmp-1-2", 
		NULL };

static struct cwmp_namespaces ns;

/* RPC methods */
/**
 *  ??????????????????RPC??????????????????????????????
 *  ??????????????????????????????????????????????????????????????????
 *  1.????????????????????????????????????????????????
 *  2.?????????????????????????????????
 *          OK      - ???????????????????????????????????????
 *          NotOK   - ?????????????????????????????????????????????????????????????????????
 *  
 */
const struct rpc_method rpc_methods[] = {                              //[1]    [2]
	{ "GetRPCMethods",          xml_handle_get_rpc_methods },           //OK    OK
	{ "SetParameterValues",     xml_handle_set_parameter_values },      //OK    OK
	{ "GetParameterValues",     xml_handle_get_parameter_values },      //OK    OK
	{ "GetParameterNames",      xml_handle_get_parameter_names },       //OK    OK
	{ "GetParameterAttributes", xml_handle_get_parameter_attributes },  //OK    OK
	{ "SetParameterAttributes", xml_handle_set_parameter_attributes },  //OK    OK
	{ "AddObject",              xml_handle_AddObject },                 //OK   NotOK
	{ "DeleteObject",           xml_handle_DeleteObject },              //OK   NotOK
	{ "Download",               xml_handle_download },                  //OK   NotOK
	{ "Upload",                 xml_handle_upload },                    //OK   NotOK
	{ "Reboot",                 xml_handle_reboot },                    //OK   TODO
	{ "FactoryReset",           xml_handle_factory_reset },             //OK   TODO
	{ "ScheduleInform",         xml_handle_schedule_inform },           //OK   NotOK
};


mxml_node_t *				/* O - Element node or NULL */
mxmlFindElementOpaque(mxml_node_t *node,	/* I - Current node */
						mxml_node_t *top,	/* I - Top node */
						const char *text,	/* I - Element text, if NULL return NULL */
						int descend)		/* I - Descend into tree - MXML_DESCEND, MXML_NO_DESCEND, or MXML_DESCEND_FIRST */
{
	if (!node || !top || !text)
		return (NULL);

	node = mxmlWalkNext(node, top, descend);

	while (node != NULL)
	{
		if (node->type == MXML_OPAQUE &&
			node->value.opaque &&
			(!text || !strcmp(node->value.opaque, text)))
		{
			return (node);
		}

		if (descend == MXML_DESCEND)
			node = mxmlWalkNext(node, top, MXML_DESCEND);
		else
			node = node->next;
	}
	return (NULL);
}

const char *xml_format_cb(mxml_node_t *node, int pos)
{
	mxml_node_t *b = node;
	static char space_format[20];
	int i=0;

	switch (pos) {
		case  MXML_WS_BEFORE_CLOSE:
			if (node->child && node->child->type != MXML_ELEMENT)
				return ("");
			
			while (b->parent != NULL) {
				space_format[i] = ' ';
				b=b->parent;
				i++;
			}
			space_format[i] = '\0';
			return (space_format);
				
		case  MXML_WS_BEFORE_OPEN:
			while (b->parent != NULL) {
				space_format[i] = ' ';
				b=b->parent;
				i++;
			}
			space_format[i] = '\0';
			return (space_format);
		case  MXML_WS_AFTER_OPEN:
			if (node->child && node->child->type!=MXML_ELEMENT)
				return ("");
			else
				return ("\n");
		case  MXML_WS_AFTER_CLOSE:
			return ("\n");
		default:
			return ("");
	}
}

char *xml_get_value_with_whitespace(mxml_node_t **b, mxml_node_t *body_in)
{
	char * value = strdup((*b)->value.opaque);
	return value;
}

static inline void xml_free_ns(void)
{
	int i = 0;
	FREE(ns.soap_enc);
	FREE(ns.xsd);
	FREE(ns.xsi);
	FREE(ns.cwmp);
	for (i = 0; i < ARRAY_SIZE(ns.soap_env) && ns.soap_env[i]; i++) {
		FREE(ns.soap_env[i]);
	}
}

void xml_exit(void)
{
	xml_free_ns();
}

void xml_log_parameter_fault()
{
	struct list_head *ilist;
	struct external_parameter *external_parameter;

	list_for_each_prev(ilist, &external_list_parameter) {
		external_parameter = list_entry(ilist, struct external_parameter, list);
		if (external_parameter->fault_code && external_parameter->fault_code[0]=='9') {
			cwmp_log(NAME, L_NOTICE, "Fault in the param: %s , Fault code: %s\n", external_parameter->name, external_parameter->fault_code);
		}
		else {
			break;
		}
	}
}

int xml_check_duplicated_parameter(mxml_node_t *tree)
{
	mxml_node_t *b, *n = tree;
	while (n) {
		if (n && n->type == MXML_OPAQUE &&
			n->value.opaque &&
			n->parent->type == MXML_ELEMENT &&
			!strcmp(n->parent->value.element.name, "Name")) {
			b = n;
			while (b = mxmlWalkNext(b, tree, MXML_DESCEND)) {
				if (b && b->type == MXML_OPAQUE &&
					b->value.opaque &&
					b->parent->type == MXML_ELEMENT &&
					!strcmp(b->parent->value.element.name, "Name")) {
					if (strcmp(b->value.opaque, n->value.opaque) == 0) {
						cwmp_log(NAME, L_NOTICE, "Fault in the param: %s , Fault code: 9003 <parameter duplicated>\n", b->value.opaque);
						return 1;
					}
				}
			}
		}
		n = mxmlWalkNext(n, tree, MXML_DESCEND);
	}
	return 0;
}

int xml_mxml_get_attrname_array(mxml_node_t *node,
								const char  *value,
								char *name_arr[],
								int size)
{
	int	i, j = 0;
	mxml_attr_t	*attr;

	if (!node || node->type != MXML_ELEMENT || !value)
		return (-1);

	for (i = node->value.element.num_attrs, attr = node->value.element.attrs;
		i > 0;
		i --, attr ++)
	{
		if (!strcmp(attr->value, value) && *(attr->name + 5) == ':')
		{
			name_arr[j++] = strdup((attr->name + 6));
		}
		if (j >= size) break;
	}

	return (j ? 0 : -1);
}

mxml_node_t *xml_mxml_find_node_by_env_type(mxml_node_t *tree_in, char *bname) {
	mxml_node_t *b;
	char *c;
	int i;

	for (i = 0; i < ARRAY_SIZE(ns.soap_env) && ns.soap_env[i]; i++) {
		if (asprintf(&c, "%s:%s", ns.soap_env[i], bname) == -1)
			return NULL;

		b = mxmlFindElement(tree_in, tree_in, c, NULL, NULL, MXML_DESCEND);
		FREE(c);
		if (b) return b;
	}
	return NULL;
}

static int xml_recreate_namespace(mxml_node_t *tree)
{
	mxml_node_t *b = tree;
	const char *cwmp_urn;
	char *c;
	int i;

	xml_free_ns();

	do {
		if (ns.cwmp == NULL) {
			for (i = 0; cwmp_urls[i] != NULL; i++) {
				cwmp_urn = cwmp_urls[i];
				c = (char *) mxmlElementGetAttrName(b, cwmp_urn);
				if (c && *(c + 5) == ':') {
					ns.cwmp = strdup((c + 6));
					break;
				}
			}
		}

		if (ns.soap_env[0] == NULL) {
			xml_mxml_get_attrname_array(b, soap_env_url, ns.soap_env, ARRAY_SIZE(ns.soap_env));
		}

		if (ns.soap_enc  == NULL) {
			c = (char *) mxmlElementGetAttrName(b, soap_enc_url);
			if (c && (*(c + 5) == ':')) {
				ns.soap_enc = strdup((c + 6));
			}
		}

		if (ns.xsd == NULL) {
			c = (char *) mxmlElementGetAttrName(b, xsd_url);
			if (c && (*(c + 5) == ':')) {
				ns.xsd = strdup((c + 6));
			}
		}

		if (ns.xsi == NULL) {
			c = (char *) mxmlElementGetAttrName(b, xsi_url);
			if (c && (*(c + 5) == ':')) {
				ns.xsi = strdup((c + 6));
			}
		}
	} while (b = mxmlWalkNext(b, tree, MXML_DESCEND));

	if ((ns.soap_env[0] != NULL ) && (ns.cwmp != NULL))
		return 0;

	return -1;
}

static void xml_get_hold_request(mxml_node_t *tree)
{
	mxml_node_t *b;
	char *c;

	cwmp->hold_requests = false;

	if (asprintf(&c, "%s:%s", ns.cwmp, "NoMoreRequests") == -1)
		return;
	b = mxmlFindElement(tree, tree, c, NULL, NULL, MXML_DESCEND);
	free(c);
	if (b) {
		b = mxmlWalkNext(b, tree, MXML_DESCEND_FIRST);

		if(b->value.opaque)
			cwmp->hold_requests = (atoi(b->value.opaque)) ? true : false;
	}

	if (asprintf(&c, "%s:%s", ns.cwmp, "HoldRequests") == -1)
		return;
	b = mxmlFindElement(tree, tree, c, NULL, NULL, MXML_DESCEND);
	free(c);
	if (b) {
		b = mxmlWalkNext(b, tree, MXML_DESCEND_FIRST);

		if(b->value.opaque)
			cwmp->hold_requests = (atoi(b->value.opaque)) ? true : false;
	}
}

int xml_handle_message(char *msg_in, char **msg_out)
{
	mxml_node_t *tree_in = NULL, *tree_out = NULL, *b, *body_out;
	const struct rpc_method *method;
	int i, code = FAULT_9002;
	char *c;

	tree_out = mxmlLoadString(NULL, CWMP_RESPONSE_MESSAGE, MXML_OPAQUE_CALLBACK);
	if (!tree_out) goto error;

	tree_in = mxmlLoadString(NULL, msg_in, MXML_OPAQUE_CALLBACK);
	if (!tree_in) goto error;

	if(xml_recreate_namespace(tree_in)) {
		code = FAULT_9003;
		goto fault_out;
	}
	/* handle cwmp:ID */
	if (asprintf(&c, "%s:%s", ns.cwmp, "ID") == -1)
		goto error;

	b = mxmlFindElement(tree_in, tree_in, c, NULL, NULL, MXML_DESCEND);
	FREE(c);
	/* ACS did not send ID parameter, we are continuing without it */
	if (!b) goto find_method;

	b = mxmlWalkNext(b, tree_in, MXML_DESCEND_FIRST);
	if (!b || !b->value.opaque) goto find_method;
	c = strdup(b->value.opaque);

	b = mxmlFindElement(tree_out, tree_out, "cwmp:ID", NULL, NULL, MXML_DESCEND);
	if (!b) {
		FREE(c);
		goto error;
	}

	b = mxmlNewOpaque(b, c);
	FREE(c);
	if (!b) goto error;

find_method:
	b = xml_mxml_find_node_by_env_type(tree_in, "Body");
	if (!b) {
		code = FAULT_9003;
		goto fault_out;
	}
	while (1) {
		b = mxmlWalkNext(b, tree_in, MXML_DESCEND_FIRST);
		if (!b) {
			code = FAULT_9003;
			goto fault_out;
		}
		if (b->type == MXML_ELEMENT) break;
	}

	c = b->value.element.name;
	if (strchr(c, ':')) {
		char *tmp = strchr(c, ':');
		size_t ns_len = tmp - c;

		if (strlen(ns.cwmp) != ns_len) {
			code = FAULT_9003;
			goto fault_out;
		}

		if (strncmp(ns.cwmp, c, ns_len)) {
			code = FAULT_9003;
			goto fault_out;
		}

		c = tmp + 1;
	} else {
		code = FAULT_9003;
		goto fault_out;
	}
	method = NULL;
	cwmp_log(NAME, L_NOTICE, "received %s method from the ACS\n", c);
	for (i = 0; i < ARRAY_SIZE(rpc_methods); i++) {
		if (!strcmp(c, rpc_methods[i].name)) {
			method = &rpc_methods[i];
			break;
		}
	}
	if (method) {
		if (method->handler(b, tree_in, tree_out)) goto error;
	}
	else {
		code = FAULT_9000;
		goto fault_out;
	}
	*msg_out = mxmlSaveAllocString(tree_out, xml_format_cb);

	mxmlDelete(tree_in);
	mxmlDelete(tree_out);
	return 0;

fault_out:
	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body", NULL, NULL, MXML_DESCEND);
	if (!body_out) goto error;
	xml_create_generic_fault_message(body_out, code);
	*msg_out = mxmlSaveAllocString(tree_out, xml_format_cb);
	mxmlDelete(tree_in);
	mxmlDelete(tree_out);
	return 0;

error:
	mxmlDelete(tree_in);
	mxmlDelete(tree_out);
	return -1;
}

int xml_get_index_fault(char *fault_code)
{
	int i;

	for (i = 0; i < __FAULT_MAX; i++) {
		if (strcmp(fault_array[i].code, fault_code) == 0)
			return i;
	}
	return FAULT_9002;
}

int xml_check_fault_in_list_parameter(void)
{
	struct external_parameter *external_parameter;
	struct list_head *ilist;
	int code;

	ilist = external_list_parameter.prev;
	if (ilist != &external_list_parameter) {
		external_parameter = list_entry(ilist, struct external_parameter, list);
		if (external_parameter->fault_code && external_parameter->fault_code[0] == '9') {
			code = xml_get_index_fault(external_parameter->fault_code);
			return code;
		}
	}
	return 0;
}

/* Inform */

static int xml_prepare_events_inform(mxml_node_t *tree)
{
	mxml_node_t *node, *b1, *b2;
	char *c;
	int n = 0;
	struct list_head *p;
	struct event *event;

	b1 = mxmlFindElement(tree, tree, "Event", NULL, NULL, MXML_DESCEND);
	if (!b1) return -1;

	list_for_each(p, &cwmp->events) {
		event = list_entry (p, struct event, list);
		node = mxmlNewElement (b1, "EventStruct");
		if (!node) goto error;

		b2 = mxmlNewElement (node, "EventCode");
		if (!b2) goto error;

		b2 = mxmlNewOpaque(b2, event_code_array[event->code].code);
		if (!b2) goto error;

		b2 = mxmlNewElement (node, "CommandKey");
		if (!b2) goto error;

		if (event->key) {
			b2 = mxmlNewOpaque(b2, event->key);
			if (!b2) goto error;
		}

		mxmlAdd(b1, MXML_ADD_AFTER, MXML_ADD_TO_PARENT, node);
		n++;
	}

	if (n) {
		if (asprintf(&c, "cwmp:EventStruct[%u]", n) == -1)
			return -1;

		mxmlElementSetAttr(b1, "soap_enc:arrayType", c);
		FREE(c);
	}

	return 0;

error:
	return -1;
}

static int xml_prepare_notifications_inform(mxml_node_t *parameter_list, int *counter)
{
	/* notifications */
	mxml_node_t *b, *n;

	struct list_head *p;
	struct notification *notification;

	list_for_each(p, &cwmp->notifications) {
		notification = list_entry(p, struct notification, list);

		b = mxmlFindElementOpaque(parameter_list, parameter_list, notification->parameter, MXML_DESCEND);
		if (b) continue;
		
		n = mxmlNewElement(parameter_list, "ParameterValueStruct");
		if (!n) goto error;

		b = mxmlNewElement(n, "Name");
		if (!b) goto error;

		b = mxmlNewOpaque(b, notification->parameter);
		if (!b) goto error;

		b = b->parent->parent;
		b = mxmlNewElement(n, "Value");
		if (!b) goto error;

		mxmlElementSetAttr(b, "xsi:type", notification->type);

		b = mxmlNewOpaque(b, notification->value);
		if (!b) goto error;

		(*counter)++;
	}

	return 0;

error:
	return -1;
}

int xml_prepare_inform_message(char **msg_out)
{
	mxml_node_t *tree, *b, *n, *parameter_list;
	struct external_parameter *external_parameter;
	char *c;
	int counter = 0;

	tree = mxmlLoadString(NULL, CWMP_INFORM_MESSAGE, MXML_OPAQUE_CALLBACK);
	if (!tree) goto error;

	if(xml_add_cwmpid(tree)) goto error;

	b = mxmlFindElement(tree, tree, "RetryCount", NULL, NULL, MXML_DESCEND);
	if (!b) goto error;

	b = mxmlNewInteger(b, cwmp->retry_count);
	if (!b) goto error;

	b = mxmlFindElement(tree, tree, "Manufacturer", NULL, NULL, MXML_DESCEND);
	if (!b) goto error;

	b = mxmlNewOpaque(b, cwmp->deviceid.manufacturer);
	if (!b) goto error;

	b = mxmlFindElement(tree, tree, "OUI", NULL, NULL, MXML_DESCEND);
	if (!b) goto error;

	b = mxmlNewOpaque(b, cwmp->deviceid.oui);
	if (!b) goto error;

	b = mxmlFindElement(tree, tree, "ProductClass", NULL, NULL, MXML_DESCEND);
	if (!b) goto error;

	b = mxmlNewOpaque(b, cwmp->deviceid.product_class);
	if (!b) goto error;

	b = mxmlFindElement(tree, tree, "SerialNumber", NULL, NULL, MXML_DESCEND);
	if (!b) goto error;

	b = mxmlNewOpaque(b, cwmp->deviceid.serial_number);
	if (!b) goto error;
   
	if (xml_prepare_events_inform(tree))
		goto error;

	b = mxmlFindElement(tree, tree, "CurrentTime", NULL, NULL, MXML_DESCEND);
	if (!b) goto error;

	b = mxmlNewOpaque(b, mix_get_time());
	if (!b) goto error;

	external_action_simple_execute("inform", "parameter", NULL);
	if (external_action_handle(json_handle_get_parameter_value))
		goto error;

	parameter_list = mxmlFindElement(tree, tree, "ParameterList", NULL, NULL, MXML_DESCEND);
	if (!parameter_list) goto error;

	while (external_list_parameter.next != &external_list_parameter) {

		external_parameter = list_entry(external_list_parameter.next, struct external_parameter, list);

		n = mxmlNewElement(parameter_list, "ParameterValueStruct");
		if (!n) goto error;

		b = mxmlNewElement(n, "Name");
		if (!b) goto error;

		b = mxmlNewOpaque(b, external_parameter->name);
		if (!b) goto error;

		b = mxmlNewElement(n, "Value");
		if (!b) goto error;

		mxmlElementSetAttr(b, "xsi:type", external_parameter->type);
		b = mxmlNewOpaque(b, external_parameter->data ? external_parameter->data : "");
		if (!b) goto error;

		counter++;

		external_parameter_delete(external_parameter);
	}

	if (xml_prepare_notifications_inform(parameter_list, &counter))
		goto error;

	if (asprintf(&c, "cwmp:ParameterValueStruct[%d]", counter) == -1)
		goto error;

	mxmlElementSetAttr(parameter_list, "soap_enc:arrayType", c);
	FREE(c);

	*msg_out = mxmlSaveAllocString(tree, xml_format_cb);

	mxmlDelete(tree);
	return 0;

error:
	external_free_list_parameter();
	mxmlDelete(tree);
	return -1;
}

int xml_parse_inform_response_message(char *msg_in)
{
	mxml_node_t *tree, *b;
	char *c;
	int fault = 0;

	tree = mxmlLoadString(NULL, msg_in, MXML_OPAQUE_CALLBACK);
	if (!tree) goto error;
	if(xml_recreate_namespace(tree)) goto error;

	b = xml_mxml_find_node_by_env_type(tree, "Fault");
	if (b) {
		b = mxmlFindElementOpaque(b, b, "8005", MXML_DESCEND);
		if (b) {
			fault = FAULT_ACS_8005;
			goto out;
		}
		goto error;
	}

	xml_get_hold_request(tree);
	b = mxmlFindElement(tree, tree, "MaxEnvelopes", NULL, NULL, MXML_DESCEND);
	if (!b) goto error;

	b = mxmlWalkNext(b, tree, MXML_DESCEND_FIRST);
	if (!b || !b->value.opaque)
		goto error;


out:
	mxmlDelete(tree);
	return fault;

error:
	mxmlDelete(tree);
	return -1;
}

/* ACS GetRPCMethods */
int xml_prepare_get_rpc_methods_message(char **msg_out)
{
	mxml_node_t *tree;

	tree = mxmlLoadString(NULL, CWMP_GET_RPC_METHOD_MESSAGE, MXML_OPAQUE_CALLBACK);
	if (!tree) return -1;

	if(xml_add_cwmpid(tree)) return -1;

	*msg_out = mxmlSaveAllocString(tree, xml_format_cb);

	mxmlDelete(tree);
	return 0;
}

int xml_parse_get_rpc_methods_response_message(char *msg_in)
{
	mxml_node_t *tree, *b;
	char *c;
	int fault = 0;

	tree = mxmlLoadString(NULL, msg_in, MXML_OPAQUE_CALLBACK);
	if (!tree) goto error;
	if(xml_recreate_namespace(tree)) goto error;

	b = xml_mxml_find_node_by_env_type(tree, "Fault");
	if (b) {
		b = mxmlFindElementOpaque(b, b, "8005", MXML_DESCEND);
		if (b) {
			fault = FAULT_ACS_8005;
			goto out;
		}
		goto out;
	}

	xml_get_hold_request(tree);

out:
	mxmlDelete(tree);
	return fault;

error:
	mxmlDelete(tree);
	return -1;
}

/* ACS TransferComplete */

int xml_parse_transfer_complete_response_message(char *msg_in)
{
	mxml_node_t *tree, *b;
	char *c;
	int fault = 0;

	tree = mxmlLoadString(NULL, msg_in, MXML_OPAQUE_CALLBACK);
	if (!tree) goto error;
	if(xml_recreate_namespace(tree)) goto error;

	b = xml_mxml_find_node_by_env_type(tree, "Fault");
	if (b) {
		b = mxmlFindElementOpaque(b, b, "8005", MXML_DESCEND);
		if (b) {
			fault = FAULT_ACS_8005;
			goto out;
		}
		goto out;
	}

	xml_get_hold_request(tree);

out:
	mxmlDelete(tree);
	return fault;

error:
	mxmlDelete(tree);
	return -1;
}


/** 
 *  CPE GetRPCMethods 
 *  ??????RPC?????????
 *  rongtao@sylincom.com
 */
static int xml_handle_get_rpc_methods(mxml_node_t *body_in, mxml_node_t *tree_in, mxml_node_t *tree_out)
{
	cwmp_log(NAME, L_NOTICE, "send GetRPCMethods Request from the ACS\n");
    
	mxml_node_t *b1, *b2, *method_list;
	int i = 0;
    
    /* ??????   GetRPCMethodsResponse ????????????        */
	b1 = mxmlFindElement(tree_out, tree_out, "soap_env:Body", NULL, NULL, MXML_DESCEND);
	if (!b1) return -1;

	b1 = mxmlNewElement(b1, "cwmp:GetRPCMethodsResponse");
	if (!b1) return -1;

	method_list = mxmlNewElement(b1, "MethodList");
	if (!method_list) return -1;

    /* ??????RPC??????-??????????????????-???????????????XML????????? */
	for (i = 0; i < ARRAY_SIZE(rpc_methods); i++) {
		b2 = mxmlNewElement(method_list, "string");
		if (!b2) return -1;

		b2 = mxmlNewOpaque(b2, rpc_methods[i].name);
		if (!b2) return -1;
        
        cwmp_log(NAME, L_NOTICE, "RPCMethods: %d:%s\n", i, rpc_methods[i].name);
	}
	char *attr_value;
	if (asprintf(&attr_value, "xsd:string[%d]", ARRAY_SIZE(rpc_methods)) == -1)
		return -1;

	mxmlElementSetAttr(method_list, "soap_enc:arrayType", attr_value);
	free(attr_value);

    //ACS?????????????????????????????????ACS???????????? rongtao@sylincom.com
    //
    //POST /ACS HTTP/1.1
    //Host: 10.170.6.24:7547
    //User-Agent: easycwmp
    //Content-Type: text/xml; charset="utf-8"
    //SOAPAction:
    //Content-Length: 1099
    //Expect: 100-continue
    //
    //<?xml version="1.0" encoding="UTF-8" standalone="no"?>
    //<soap_env:Envelope
    //    xmlns:soap_env="http://schemas.xmlsoap.org/soap/envelope/"
    //    xmlns:soap_enc="http://schemas.xmlsoap.org/soap/encoding/"
    //    xmlns:xsd="http://www.w3.org/2001/XMLSchema"
    //    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    //    xmlns:cwmp="urn:dslforum-org:cwmp-1-2">
    //    
    //    <soap_env:Header>
    //        <cwmp:ID soap_env:mustUnderstand="1">0001</cwmp:ID>
    //    </soap_env:Header>
    //    <soap_env:Body>
    //        <cwmp:GetRPCMethodsResponse>
    //            <MethodList soap_enc:arrayType="xsd:string[13]">
    //                <string>GetRPCMethods</string>
    //                <string>SetParameterValues</string>
    //                <string>GetParameterValues</string>
    //                <string>GetParameterNames</string>
    //                <string>GetParameterAttributes</string>
    //                <string>SetParameterAttributes</string>
    //                <string>AddObject</string>
    //                <string>DeleteObject</string>
    //                <string>Download</string>
    //                <string>Upload</string>
    //                <string>Reboot</string>
    //                <string>FactoryReset</string>
    //                <string>ScheduleInform</string>
    //            </MethodList>
    //        </cwmp:GetRPCMethodsResponse>
    //    </soap_env:Body>
    //</soap_env:Envelope>

    
	cwmp_log(NAME, L_NOTICE, "send GetRPCMethodsResponse to the ACS\n");
	return 0;
}


/** 
 *  CPE SetParameterValues 
 *  set?????????
 *  Reference:<TR-069_Amendment-6.pdf>
 */
int xml_handle_set_parameter_values(mxml_node_t *body_in, mxml_node_t *tree_in, mxml_node_t *tree_out)
{
	cwmp_log(NAME, L_NOTICE, "Recv SetParameterValues Request from the ACS\n");
        
	mxml_node_t *b = body_in, *body_out;
	struct external_parameter *external_parameter;
	struct list_head *ilist;
	char *parameter_name = NULL, *parameter_value = NULL, *status = NULL, *param_key = NULL;
	int code = FAULT_9002;

	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body", NULL, NULL, MXML_DESCEND);
	if (!body_out) goto error;

	if (xml_check_duplicated_parameter(body_in)) {
		code = FAULT_9003;
		goto fault_out;
	}

    /* ?????????ACS????????????????????????????????????
        easycwmp set value *** 
        easycwmp apply value param_key
     */
	while (b) {
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "Name")) {
			parameter_name = b->value.opaque;
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "Name") &&
			!b->child) {
			parameter_name = "";
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "Value")) {
			free(parameter_value);
			parameter_value = xml_get_value_with_whitespace(&b, body_in);
		}

		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "Value") &&
			!b->child) {
			free(parameter_value);
			parameter_value = strdup("");
		}

		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "ParameterKey")) {
			free(param_key);
			param_key = xml_get_value_with_whitespace(&b, body_in);
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "ParameterKey") &&
			!b->child) {
			free(param_key);
			param_key = strdup("");
		}
        
		if (parameter_name && parameter_value) {
			external_action_parameter_execute("set", "value", parameter_name, parameter_value);
            cwmp_log(NAME, L_NOTICE, "easycwmp set value %s %s \n", parameter_name, parameter_value);
        
			parameter_name = NULL;
			FREE(parameter_value);
		}
		b = mxmlWalkNext(b, body_in, MXML_DESCEND);
	}

    cwmp_log(NAME, L_NOTICE, "easycwmp apply value %s \n", param_key);

    /* apply??????set */
	external_action_simple_execute("apply", "value", param_key);
	free(param_key);
	
	if (external_action_handle(json_handle_set_parameter))
		goto fault_out;

	if (xml_check_fault_in_list_parameter()) {
		code = FAULT_9003;
		goto fault_out;
	}

    /* ??????set???????????? */
    //???????????????
    //<soap_env:Fault>
    //    <faultcode>Client</faultcode>
    //    <faultstring>CWMP fault</faultstring>
    //    <detail>
    //        <cwmp:Fault>
    //            <FaultCode>9003</FaultCode>
    //            <FaultString>Invalid arguments</FaultString>
    //            <SetParameterValuesFault>
    //                <ParameterName>Device.DeviceInfo.SerialNumber</ParameterName>
    //                <FaultCode>9008</FaultCode>
    //                <FaultString>Attempt to set a non-writable parameter</FaultString>
    //            </SetParameterValuesFault>
    //        </cwmp:Fault>
    //    </detail>
    //</soap_env:Fault>
    //???????????????????????????
    //
    //<Status>1</Status>

	external_fetch_set_param_resp_status(&status);
	if(!status)
		goto fault_out;

	b = mxmlNewElement(body_out, "cwmp:SetParameterValuesResponse");
	if (!b) goto error;

	b = mxmlNewElement(b, "Status");
	if (!b) goto error;

	b = mxmlNewOpaque(b, status);
	if (!b) goto error;

	free(status);
	free(parameter_value);
	external_free_list_parameter();

    
    //ACS?????????CPE?????????
    //HTTP/1.1 200 OK
    //Content-Type: text/xml; charset="utf-8"
    //Content-Length: 1185
    //
    //<soap:Envelope
    //    xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/"
    //    xmlns:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"
    //    xmlns:cwmp="urn:dslforum-org:cwmp-1-0"    
    //    xmlns:xsd="http://www.w3.org/2001/XMLSchema"
    //    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
    //    
    //    <soap:Header>
    //        <cwmp:ID soap:mustUnderstand="1">0001</cwmp:ID>       
    //    </soap:Header>  
    //    <soap:Body>
    //        <cwmp:SetParameterValues>  
    //            <ParameterList SOAP-ENC:arrayType="cwmp:ParameterValueStruct[2]">  
    //                <ParameterValueStruct>
    //                    <Name xsi:type="xsd:string">Device.DeviceInfo.SerialNumber</Name>
    //                    <Value xsi:type="xsd:string">NEW_rongtao_SN2020</Value>
    //                </ParameterValueStruct>
    //                <ParameterValueStruct>  
    //                    <Name>Device.ManagementServer.PeriodicInformInterval</Name>  
    //                    <Value xsi:type="xsd:unsignedInt">60</Value>  
    //                </ParameterValueStruct>  
    //            </ParameterList>  
    //            <ParameterKey>124567</ParameterKey>  
    //        </cwmp:SetParameterValues>  
    //    </soap:Body>
    //</soap:Envelope>

    
    //?????????ACS?????????-????????????????????????????????????????????????????????????????????????
    //POST /ACS HTTP/1.1
    //Host: 10.170.6.24:7547
    //User-Agent: easycwmp
    //Content-Type: text/xml; charset="utf-8"
    //SOAPAction:
    //Content-Length: 996
    //    
    //<?xml version="1.0" encoding="UTF-8" standalone="no"?>
    //<soap_env:Envelope
    //    xmlns:soap_env="http://schemas.xmlsoap.org/soap/envelope/"
    //    xmlns:soap_enc="http://schemas.xmlsoap.org/soap/encoding/"
    //    xmlns:xsd="http://www.w3.org/2001/XMLSchema"
    //    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    //    xmlns:cwmp="urn:dslforum-org:cwmp-1-2">
    //    <soap_env:Header>
    //        <cwmp:ID soap_env:mustUnderstand="1">0001</cwmp:ID>
    //    </soap_env:Header>
    //    <soap_env:Body>
    //        <soap_env:Fault>
    //            <faultcode>Client</faultcode>
    //            <faultstring>CWMP fault</faultstring>
    //            <detail>
    //                <cwmp:Fault>
    //                    <FaultCode>9003</FaultCode>
    //                    <FaultString>Invalid arguments</FaultString>
    //                    <SetParameterValuesFault>
    //                        <ParameterName>Device.DeviceInfo.SerialNumber</ParameterName>
    //                        <FaultCode>9008</FaultCode>
    //                        <FaultString>Attempt to set a non-writable parameter</FaultString>
    //                    </SetParameterValuesFault>
    //                </cwmp:Fault>
    //            </detail>
    //        </soap_env:Fault>
    //    </soap_env:Body>
    //</soap_env:Envelope>


	cwmp_log(NAME, L_NOTICE, "send SetParameterValuesResponse to the ACS\n");
	return 0;

fault_out:
	xml_log_parameter_fault();
	free(parameter_value);
	xml_create_set_parameter_value_fault_message(body_out, code);
	free(status);
	external_free_list_parameter();
	return 0;
error:
	free(parameter_value);
	free(status);
	external_free_list_parameter();
	return-1;
}


/** 
 *  CPE GetParameterValues 
 *  ???????????????
 *  Reference:<TR-069_Amendment-6.pdf>
 *  rongtao@sylincom.com
 */
int xml_handle_get_parameter_values(mxml_node_t *body_in, mxml_node_t *tree_in, mxml_node_t *tree_out)
{
	cwmp_log(NAME, L_NOTICE, "Recv GetParameterValues Request from the ACS\n");
    
	mxml_node_t *n, *parameter_list, *b = body_in, *body_out, *t;
	struct external_parameter *external_parameter;
	char *parameter_name = NULL;
	int counter = 0, fc, code = FAULT_9002;
	struct list_head *ilist;

	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body",
				NULL, NULL, MXML_DESCEND);
	if (!body_out) return -1;

	while (b) {

        //?????????????????????????????? Device.DeviceInfo.SerialNumber
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "string")) {
			parameter_name = b->value.opaque;
		}

		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "string") &&
			!b->child) {
			parameter_name = "";
		}
            
        cwmp_log(NAME, L_NOTICE, "easycwmp get value %s\n", parameter_name);

        /**
         *  ?????????????????????????????????????????????????????????
         */
#ifdef EASYCWMP_OM
		if (parameter_name) {
            /* ???OM?????? */
            GetParameterValues request;
            strcpy(request.ParameterNames, parameter_name);
            tr069_register_GetParameterValues_call(&request);
		}
#else

        //??????easycwmp???????????????easycwmp???????????????easycwmp????????????
		if (parameter_name) {
			external_action_parameter_execute("get", "value", parameter_name, NULL);
			if (external_action_handle(json_handle_get_parameter_value))
				goto fault_out;
			fc = xml_check_fault_in_list_parameter();
			if (fc) {
				code = fc;
				goto fault_out;
			}
		}
        
#endif
		b = mxmlWalkNext(b, body_in, MXML_DESCEND);
		parameter_name = NULL;
	}

    /* CPE???????????????ACS??????????????? */
	n = mxmlNewElement(body_out, "cwmp:GetParameterValuesResponse");
	if (!n) goto out;
	parameter_list = mxmlNewElement(n, "ParameterList");
	if (!parameter_list) goto out;

    /* ???????????????????????????UCI?????????linux???????????????????????? rongtao@sylincom.com */
	while (external_list_parameter.next != &external_list_parameter) {

		external_parameter = list_entry(external_list_parameter.next, struct external_parameter, list);

        //?????????????????????????????????
        //<ParameterValueStruct>
        //    <Name>Device.DeviceInfo.SerialNumber</Name>
        //    <Value xsi:type="xsd:string">rongtaoSNFFFFFF123456</Value>
        //</ParameterValueStruct>
    
		n = mxmlNewElement(parameter_list, "ParameterValueStruct");
		if (!n) goto out;

		t = mxmlNewElement(n, "Name");
		if (!t) goto out;

		t = mxmlNewOpaque(t, external_parameter->name);
		if (!t) goto out;

		t = mxmlNewElement(n, "Value");
		if (!t) goto out;

		mxmlElementSetAttr(t, "xsi:type", external_parameter->type);
		t = mxmlNewOpaque(t, external_parameter->data ? external_parameter->data : "");
		if (!t) goto out;

		counter++;
		external_parameter_delete(external_parameter);
	}
	char *c;
	if (asprintf(&c, "cwmp:ParameterValueStruct[%d]", counter) == -1)
		goto out;

	mxmlElementSetAttr(parameter_list, "soap_enc:arrayType", c);
	FREE(c);

    //////////////////////////////////////////////////////////////////////////////////////
    //ACS???CPE?????????????????????
    //HTTP/1.1 200 OK
    //Content-Type: text/xml; charset="utf-8"
    //Content-Length: 914
    //
    //<soap:Envelope
    //    xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/"
    //    xmlns:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"
    //    xmlns:cwmp="urn:dslforum-org:cwmp-1-0"    
    //    xmlns:xsd="http://www.w3.org/2001/XMLSchema"
    //    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
    //    
    //    <soap:Header>
    //        <cwmp:ID soap:mustUnderstand="1">0001</cwmp:ID>       
    //    </soap:Header>  
    //    <soap:Body>
    //        <cwmp:GetParameterValues>  
    //            <ParameterNames SOAP-ENC:arrayType="xsd:string[10]">  
    //                <string>Device.DeviceInfo.ProductClass</string>  
    //                <string>Device.DeviceInfo.SoftwareVersion</string>  
    //                <string>Device.DeviceInfo.SerialNumber</string>  
    //                <string>Device.DeviceInfo.ManufacturerOUI</string>  
    //            </ParameterNames>  
    //        </cwmp:GetParameterValues> 
    //    </soap:Body>
    //</soap:Envelope>
    //////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    //???ACS?????????????????????
    //POST /ACS HTTP/1.1
    //Host: 10.170.6.24:7547
    //User-Agent: easycwmp
    //Content-Type: text/xml; charset="utf-8"
    //SOAPAction:
    //Content-Length: 1322
    //Expect: 100-continue
    //
    //<?xml version="1.0" encoding="UTF-8" standalone="no"?>
    //<soap_env:Envelope
    //    xmlns:soap_env="http://schemas.xmlsoap.org/soap/envelope/"
    //    xmlns:soap_enc="http://schemas.xmlsoap.org/soap/encoding/"
    //    xmlns:xsd="http://www.w3.org/2001/XMLSchema"
    //    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    //    xmlns:cwmp="urn:dslforum-org:cwmp-1-2">
    //    <soap_env:Header>
    //        <cwmp:ID soap_env:mustUnderstand="1">0001</cwmp:ID>
    //    </soap_env:Header>
    //    <soap_env:Body>
    //        <cwmp:GetParameterValuesResponse>
    //            <ParameterList soap_enc:arrayType="cwmp:ParameterValueStruct[4]">
    //                <ParameterValueStruct>
    //                    <Name>Device.DeviceInfo.ProductClass</Name>
    //                    <Value xsi:type="xsd:string">easycwmp</Value>
    //                </ParameterValueStruct>
    //                <ParameterValueStruct>
    //                    <Name>Device.DeviceInfo.SoftwareVersion</Name>
    //                    <Value xsi:type="xsd:string">rongtao_software_version</Value>
    //                </ParameterValueStruct>
    //                <ParameterValueStruct>
    //                    <Name>Device.DeviceInfo.SerialNumber</Name>
    //                    <Value xsi:type="xsd:string">rongtaoSNFFFFFF123456</Value>
    //                </ParameterValueStruct>
    //                <ParameterValueStruct>
    //                    <Name>Device.DeviceInfo.ManufacturerOUI</Name>
    //                    <Value xsi:type="xsd:string">FFFFFF</Value>
    //                </ParameterValueStruct>
    //            </ParameterList>
    //        </cwmp:GetParameterValuesResponse>
    //    </soap_env:Body>
    //</soap_env:Envelope>
    //////////////////////////////////////////////////////////////////////////////////////


	cwmp_log(NAME, L_NOTICE, "Ready to send GetParameterValuesResponse to the ACS\n");
	return 0;
    
fault_out:
	xml_log_parameter_fault();
	xml_create_generic_fault_message(body_out, code);
	external_free_list_parameter();
	return 0;
out:
	external_free_list_parameter();
	return -1;
}


/** 
 *  CPE GetParameterNames 
 *  ???????????????
 *  Reference:<TR-069_Amendment-6.pdf>
 *  rongtao@sylincom.com
 */
int xml_handle_get_parameter_names(mxml_node_t *body_in, mxml_node_t *tree_in, mxml_node_t *tree_out)
{
	cwmp_log(NAME, L_NOTICE, "Recv GetParameterNames Request from the ACS\n");
    
	mxml_node_t *n, *parameter_list, *b = body_in, *body_out, *t;
	struct external_parameter *external_parameter;
	char *parameter_name = NULL;
	char *next_level = NULL;
	int counter = 0, fc, code = FAULT_9002;

	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body",
					NULL, NULL, MXML_DESCEND);
	if (!body_out) return -1;
	while (b) {
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "ParameterPath")) {
			parameter_name = b->value.opaque;
		}

		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "ParameterPath") &&
			!b->child) {
			parameter_name = "";
		}

		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "NextLevel")) {
			next_level = b->value.opaque;
		}

		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "NextLevel") &&
			!b->child) {
			next_level = "";
		}

		b = mxmlWalkNext(b, body_in, MXML_DESCEND);
	}

    cwmp_log(NAME, L_NOTICE, "easycwmp get name %s %s\n", parameter_name, next_level);

    /**
     *  ??????????????????????????????name?????????????????????
     */
#ifdef EASYCWMP_OM
    
    /* ???OM?????? */
    GetParameterNames request;
    strcpy(request.ParameterPath, parameter_name);
    request.NextLevel = next_level;
    tr069_register_GetParameterNames_call(&request);
    
#else
    /* ??????????????? */
	if (parameter_name && next_level) {
		external_action_parameter_execute("get", "name", parameter_name, next_level);
        cwmp_log(NAME, L_NOTICE, "easycwmp get name %s %s\n", parameter_name, next_level);
		if (external_action_handle(json_handle_get_parameter_name))
			goto fault_out;
		fc = xml_check_fault_in_list_parameter();
		if (fc) {
			code = fc;
			goto fault_out;
		}
	}
    
#endif

	n = mxmlNewElement(body_out, "cwmp:GetParameterNamesResponse");
	if (!n) goto out;

	parameter_list = mxmlNewElement(n, "ParameterList");
	if (!parameter_list) goto out;

	while (external_list_parameter.next != &external_list_parameter) {
		external_parameter = list_entry(external_list_parameter.next, struct external_parameter, list);

		n = mxmlNewElement(parameter_list, "ParameterInfoStruct");
		if (!n) goto out;

		t = mxmlNewElement(n, "Name");
		if (!t) goto out;

		t = mxmlNewOpaque(t, external_parameter->name);
		if (!t) goto out;

		t = mxmlNewElement(n, "Writable");
		if (!t) goto out;

		t = mxmlNewOpaque(t, external_parameter->data);
		if (!t) goto out;

		counter++;

		external_parameter_delete(external_parameter);
	}

	char *c;
	if (asprintf(&c, "cwmp:ParameterInfoStruct[%d]", counter) == -1)
		goto out;

	mxmlElementSetAttr(parameter_list, "soap_enc:arrayType", c);
	FREE(c);

    //??????ACS????????????????????????
    //    <soap:Body>
    //        <cwmp:GetParameterNames>  
    //            <ParameterPath>Device.DeviceInfo.</ParameterPath>
    //            <NextLevel xsi:type='SOAP-ENC:boolean'>1</NextLevel>
    //        </cwmp:GetParameterNames> 
    //    </soap:Body>
    //
    //CPE???????????????
    //<soap_env:Body>
    //    <cwmp:GetParameterNamesResponse>
    //        <ParameterList soap_enc:arrayType="cwmp:ParameterInfoStruct[11]">
    //            <ParameterInfoStruct>
    //                <Name>Device.DeviceInfo.SpecVersion</Name>
    //                <Writable>0</Writable>
    //            </ParameterInfoStruct>
    //            <ParameterInfoStruct>
    //                <Name>Device.DeviceInfo.ProvisioningCode</Name>
    //                <Writable>1</Writable>
    //            </ParameterInfoStruct>
    //            <ParameterInfoStruct>
    //                <Name>Device.DeviceInfo.Manufacturer</Name>
    //                <Writable>0</Writable>
    //            </ParameterInfoStruct>
    //            <ParameterInfoStruct>
    //                <Name>Device.DeviceInfo.ManufacturerOUI</Name>
    //                <Writable>0</Writable>
    //            </ParameterInfoStruct>
    //            <ParameterInfoStruct>
    //                <Name>Device.DeviceInfo.ProductClass</Name>
    //                <Writable>0</Writable>
    //            </ParameterInfoStruct>
    //            <ParameterInfoStruct>
    //                <Name>Device.DeviceInfo.SerialNumber</Name>
    //                <Writable>0</Writable>
    //            </ParameterInfoStruct>
    //            <ParameterInfoStruct>
    //                <Name>Device.DeviceInfo.HardwareVersion</Name>
    //                <Writable>0</Writable>
    //            </ParameterInfoStruct>
    //            <ParameterInfoStruct>
    //                <Name>Device.DeviceInfo.SoftwareVersion</Name>
    //                <Writable>0</Writable>
    //            </ParameterInfoStruct>
    //            <ParameterInfoStruct>
    //                <Name>Device.DeviceInfo.UpTime</Name>
    //                <Writable>0</Writable>
    //            </ParameterInfoStruct>
    //            <ParameterInfoStruct>
    //                <Name>Device.DeviceInfo.DeviceLog</Name>
    //                <Writable>0</Writable>
    //            </ParameterInfoStruct>
    //            <ParameterInfoStruct>
    //                <Name>Device.DeviceInfo.MemoryStatus.</Name>
    //                <Writable>0</Writable>
    //            </ParameterInfoStruct>
    //        </ParameterList>
    //    </cwmp:GetParameterNamesResponse>
    //</soap_env:Body>

    ////??????ACS??????????????????????????????
    //<soap:Body>
    //    <cwmp:GetParameterNames>  
    //        <ParameterPath>Device.DeviceInfo.SerialNumber</ParameterPath>
    //        <NextLevel xsi:type='SOAP-ENC:boolean'>0</NextLevel>
    //    </cwmp:GetParameterNames> 
    //</soap:Body>
    //
    ////??????CPE?????????????????????
    //<soap_env:Body>
    //    <cwmp:GetParameterNamesResponse>
    //        <ParameterList soap_enc:arrayType="cwmp:ParameterInfoStruct[1]">
    //            <ParameterInfoStruct>
    //                <Name>Device.DeviceInfo.SerialNumber</Name>
    //                <Writable>0</Writable>
    //            </ParameterInfoStruct>
    //        </ParameterList>
    //    </cwmp:GetParameterNamesResponse>
    //</soap_env:Body>


	cwmp_log(NAME, L_NOTICE, "send GetParameterNamesResponse to the ACS\n");
	return 0;

    
fault_out:
	xml_log_parameter_fault();
	xml_create_generic_fault_message(body_out, code);
	external_free_list_parameter();
	return 0;

out:
	external_free_list_parameter();
	return -1;
}


/** 
 *  CPE GetParameterAttributes 
 *  ??????????????????
 *  Reference:<TR-069_Amendment-6.pdf>
 *  rongtao@sylincom.com
 */
static int xml_handle_get_parameter_attributes(mxml_node_t *body_in, mxml_node_t *tree_in, mxml_node_t *tree_out)
{
	cwmp_log(NAME, L_NOTICE, "Recv GetParameterAttributes Request from the ACS\n");
    
	mxml_node_t *n, *parameter_list, *b = body_in, *body_out, *t;
	struct external_parameter *external_parameter;
	char *parameter_name = NULL;
	int counter = 0, fc, code = FAULT_9002;
	struct list_head *ilist;

	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body",
				NULL, NULL, MXML_DESCEND);
	if (!body_out) return -1;

	while (b) {
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "string")) {
			parameter_name = b->value.opaque;
		}

		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "string") &&
			!b->child) {
			parameter_name = "";
		}
		if (parameter_name) {
			external_action_parameter_execute("get", "notification", parameter_name, NULL);
			if (external_action_handle(json_handle_get_parameter_attribute))
				goto fault_out;
			fc = xml_check_fault_in_list_parameter();
			if (fc) {
				code = fc;
				goto fault_out;
			}
		}
		b = mxmlWalkNext(b, body_in, MXML_DESCEND);
		parameter_name = NULL;
	}

	n = mxmlNewElement(body_out, "cwmp:GetParameterAttributesResponse");
	if (!n) goto out;

	parameter_list = mxmlNewElement(n, "ParameterList");
	if (!parameter_list) goto out;

	while (external_list_parameter.next != &external_list_parameter) {

		external_parameter = list_entry(external_list_parameter.next, struct external_parameter, list);

		n = mxmlNewElement(parameter_list, "ParameterAttributeStruct");
			if (!n) goto out;

		t = mxmlNewElement(n, "Name");
		if (!t) goto out;

		t = mxmlNewOpaque(t, external_parameter->name);
		if (!t) goto out;

		t = mxmlNewElement(n, "Notification");
		if (!t) goto out;
		t = mxmlNewOpaque(t, external_parameter->data ? external_parameter->data : "");
		if (!t) goto out;

		t = mxmlNewElement(n, "AccessList");
		if (!t) goto out;

		counter++;

		external_parameter_delete(external_parameter);
	}
	char *c;
	if (asprintf(&c, "cwmp:ParameterAttributeStruct[%d]", counter) == -1)
		goto out;

	mxmlElementSetAttr(parameter_list, "soap_enc:arrayType", c);
	FREE(c);

    ////ACS???CPE?????????????????????
    //<cwmp:GetParameterAttributes>  
    //    <ParameterNames soap-enc:arrayType="soap:string[]">
    //        <string>Device.DeviceInfo.ProductClass</string> 
    //        <string>Device.DeviceInfo.SoftwareVersion</string>  
    //        <string>Device.DeviceInfo.SerialNumber</string>  
    //        <string>Device.DeviceInfo.ManufacturerOUI</string>             
    //    </ParameterNames>  
    //</cwmp:GetParameterAttributes> 
    //
    ////CPE???ACS???????????????
    //<cwmp:GetParameterAttributesResponse>
    //    <ParameterList soap_enc:arrayType="cwmp:ParameterAttributeStruct[4]">
    //        <ParameterAttributeStruct>
    //            <Name>Device.DeviceInfo.ProductClass</Name>
    //            <Notification>0</Notification>
    //            <AccessList />
    //        </ParameterAttributeStruct>
    //        <ParameterAttributeStruct>
    //            <Name>Device.DeviceInfo.SoftwareVersion</Name>
    //            <Notification>2</Notification>
    //            <AccessList />
    //        </ParameterAttributeStruct>
    //        <ParameterAttributeStruct>
    //            <Name>Device.DeviceInfo.SerialNumber</Name>
    //            <Notification>2</Notification>
    //            <AccessList />
    //        </ParameterAttributeStruct>
    //        <ParameterAttributeStruct>
    //            <Name>Device.DeviceInfo.ManufacturerOUI</Name>
    //            <Notification>0</Notification>
    //            <AccessList />
    //        </ParameterAttributeStruct>
    //    </ParameterList>
    //</cwmp:GetParameterAttributesResponse>


	cwmp_log(NAME, L_NOTICE, "send GetParameterAttributesResponse to the ACS\n");
	return 0;
fault_out:
	xml_log_parameter_fault();
	xml_create_generic_fault_message(body_out, code);
	external_free_list_parameter();
	return 0;
out:
	external_free_list_parameter();
	return -1;
}


/** 
 *  CPE SetParameterAttributes 
 *  ??????????????????
 *  Reference:<TR-069_Amendment-6.pdf>
 *  rongtao@sylincom.com
 */
static int xml_handle_set_parameter_attributes(mxml_node_t *body_in, mxml_node_t *tree_in, mxml_node_t *tree_out)
{
	cwmp_log(NAME, L_NOTICE, "Recv SetParameterAttributes Request from the ACS\n");

	mxml_node_t *b = body_in, *body_out;
	char *c, *parameter_name = NULL, *parameter_notification = NULL, *success = NULL;
	uint8_t attr_notification_update = 0;
	struct external_parameter *external_parameter;
	struct list_head *ilist;
	int fc, code = FAULT_9002 ;

	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body", NULL, NULL, MXML_DESCEND);
	if (!body_out) goto error;

    //???ACS????????????????????????????????????????????????????????? AccessListChange+AccessList???????????? rongtao@sylincom.com
    //<cwmp:SetParameterAttributes>  
    //    <ParameterList xsi:type='SOAP-ENC:Array' SOAP-ENC:arrayType="cwmp:SetParameterAttributesStruct[2]">
    //        <SetParameterAttributesStruct>  
    //            <Name>Device.DeviceInfo.SerialNumber</Name>  
    //            <NotificationChange xsi:type='xsd:boolean'>1</NotificationChange> 
    //            <Notification xsi:type='xsd:int'>2</Notification>  
    //            <AccessListChange xsi:type='xsd:boolean'>1</AccessListChange> 
    //            <AccessList xsi:type='xsd:string'>access</AccessList>  
    //        </SetParameterAttributesStruct>  
    //        <SetParameterAttributesStruct>  
    //            <Name>Device.DeviceInfo.SoftwareVersion</Name>  
    //            <NotificationChange xsi:type='xsd:boolean'>1</NotificationChange> 
    //            <Notification xsi:type='xsd:int'>2</Notification>  
    //            <AccessListChange xsi:type='xsd:boolean'>1</AccessListChange> 
    //            <AccessList xsi:type='xsd:string'>access</AccessList>  
    //        </SetParameterAttributesStruct> 
    //    </ParameterList>  
    //</cwmp:SetParameterAttributes> 
	while (b != NULL) {
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "SetParameterAttributesStruct")) {
			attr_notification_update = 0;
			parameter_name = NULL;
			parameter_notification = NULL;
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "Name")) {
			parameter_name = b->value.opaque;
		}

		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "Name") &&
			!b->child) {
			parameter_name = "";
		}

		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "NotificationChange")) {
			if (strcasecmp(b->value.opaque, "true") == 0) {
				attr_notification_update = 1;
			} else if (strcasecmp(b->value.opaque, "false") == 0) {
				attr_notification_update = 0;
			} else {
				attr_notification_update = (uint8_t) atoi(b->value.opaque);
			}
		}

		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "Notification")) {
			parameter_notification = b->value.opaque;
		}

		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "Notification") &&
			!b->child) {
			parameter_notification = "";
		}

        /**
         *  ????????????????????? AccessListChange ??? AccessList ??? ???????????????????????????
         */

		if (attr_notification_update && parameter_name && parameter_notification) {
			external_action_parameter_execute("set", "notification", parameter_name, parameter_notification);
            cwmp_log(NAME, L_NOTICE, "easycwmp set notification %s %s\n", parameter_name, parameter_notification);
			attr_notification_update = 0;
			parameter_name = NULL;
			parameter_notification = NULL;
		}
		b = mxmlWalkNext(b, body_in, MXML_DESCEND);
	}
    
    cwmp_log(NAME, L_NOTICE, "easycwmp apply notification %s %s\n", parameter_name, parameter_notification);

    //CPE?????????ACS?????????Body?????????SetParameterAttributesResponse??????????????????
    //<soap_env:Body>
    //    <cwmp:SetParameterAttributesResponse />
    //</soap_env:Body>
	external_action_simple_execute("apply", "notification", NULL);

	if (external_action_handle(json_handle_set_parameter))
		goto fault_out;

	fc = xml_check_fault_in_list_parameter();
	if (fc) {
		code = fc;
		goto fault_out;
	}

	external_fetch_set_param_resp_status(&success);
	if(!success)
		goto fault_out;

	b = mxmlNewElement(body_out, "cwmp:SetParameterAttributesResponse");
	if (!b) goto error;

	free(success);
	external_free_list_parameter();

	cwmp_log(NAME, L_NOTICE, "send SetParameterAttributesResponse to the ACS\n");
	return 0;

fault_out:
	xml_log_parameter_fault();
	xml_create_generic_fault_message(body_out, code);
	free(success);
	external_free_list_parameter();
	return 0;
error:
	free(success);
	external_free_list_parameter();
	return -1;
}


/** 
 *  CPE Download 
 *  ??????
 *  ACS????????????????????????CPE????????????????????????????????????
 *  ????????????????????????????????????????????????????????????????????????????????????By ??????
 *
 *  ????????????????????????????????? /tmp/easycwmp_download/
 *  
 *  ???????????????????????????
 *      "1 Firmware Upgrade Image"
 *      "2 Web Content"
 *      ???3 Vendor Configuration File???
 *      ???4 Tone File??? (see [28] Appendix B)
 *      ???5 Ringer File??? (see [28] Appendix B)
 *      ???6 Stored Firmware Image??? (see Appendix V)
 *
 *  rongtao@sylincom.com
 */
static int xml_handle_download(mxml_node_t *body_in, mxml_node_t *tree_in, mxml_node_t *tree_out)
{
	cwmp_log(NAME, L_NOTICE, "Recv Download Request from the ACS\n");
    
	mxml_node_t *n, *t, *b = body_in, *body_out;
	char *download_url = NULL, *file_size = NULL,
		*command_key = NULL, *file_type = NULL, *username = NULL,
		*password = NULL, r;
	int delay = -1, code = FAULT_9002;

	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body", NULL, NULL, MXML_DESCEND);
	if (!body_out) return -1;

	while (b != NULL) {
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "CommandKey")) {
			FREE(command_key);
			command_key = xml_get_value_with_whitespace(&b, body_in);
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "CommandKey") &&
			!b->child) {
			FREE(command_key);
			command_key = strdup("");
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "FileType")) {
			FREE(file_type);
			file_type = xml_get_value_with_whitespace(&b, body_in);
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "URL")) {
			download_url = b->value.opaque;
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "Username")) {
			FREE(username);
			username = xml_get_value_with_whitespace(&b, body_in);
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "Username") &&
			!b->child) {
			FREE(username);
			username = strdup("");
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "Password")) {
			FREE(password);
			password = xml_get_value_with_whitespace(&b, body_in);
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "Password") &&
			!b->child) {
			FREE(password);
			password = strdup("");
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "FileSize")) {
			file_size = b->value.opaque;
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "FileSize") &&
			!b->child) {
			file_size = "0";
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "DelaySeconds")) {
			delay = atoi(b->value.opaque);
		}
		b = mxmlWalkNext(b, body_in, MXML_DESCEND);
	}
	if (!download_url || !file_size || !command_key || !file_type || !username || !password || delay < 0) {
		code = FAULT_9003;
		goto fault_out;
	}
	if (sscanf(download_url,"%*[a-zA-Z_0-9]://%c",&r) < 1 ||
		sscanf(download_url,"%*[^:]://%*[^:]:%*[^@]@%c",&r) == 1) {
		code = FAULT_9003;
		goto fault_out;
	}
	if (cwmp->download_count >= MAX_DOWNLOAD) {
		code = FAULT_9004;
		goto fault_out;
	}
    //?????????ACS??????CPE?????????????????????
    //<cwmp:Download>
    //    <CommandKey>1271227474281</CommandKey>  
    //    <FileType>Mainpage File</FileType>  
    //    <URL>http://10.170.6.66/study/index.html</URL>  
    //    <Username />  
    //    <Password />  
    //    <FileSize>146242</FileSize>  
    //    <TargetFileName>index.html</TargetFileName>  
    //    <DelaySeconds>5</DelaySeconds>  
    //    <SuccessURL />  
    //    <FailureURL />  
    //</cwmp:Download> 
    //?????????????????????
    //[easycwmp][NOTICE][xml.c:xml_handle_download:1859]: Download: ActualCMD:  command_key = 1271227474281
    //[easycwmp][NOTICE][xml.c:xml_handle_download:1860]: Download: ActualCMD:  delay = 5
    //[easycwmp][NOTICE][xml.c:xml_handle_download:1861]: Download: ActualCMD:  file_size = 146242
    //[easycwmp][NOTICE][xml.c:xml_handle_download:1862]: Download: ActualCMD:  download_url = http://10.170.6.66/study/i
    //[easycwmp][NOTICE][xml.c:xml_handle_download:1863]: Download: ActualCMD:  file_type = Mainpage File
    //[easycwmp][NOTICE][xml.c:xml_handle_download:1864]: Download: ActualCMD:  username = 
    //[easycwmp][NOTICE][xml.c:xml_handle_download:1865]: Download: ActualCMD:  password = 
    
    cwmp_log(NAME, L_NOTICE, "Download: URL %s, file_size %s\n", download_url, file_size);
    
#define DOWNLOAD_PRINTS(string) cwmp_log(NAME, L_NOTICE, "Download: ActualCMD:  %s = %s\n", #string, string)
#define DOWNLOAD_PRINTI(integer) cwmp_log(NAME, L_NOTICE, "Download: ActualCMD:  %s = %d\n", #integer, integer)
    DOWNLOAD_PRINTS(command_key);
    DOWNLOAD_PRINTI(delay);
    DOWNLOAD_PRINTS(file_size);
    DOWNLOAD_PRINTS(download_url);
    DOWNLOAD_PRINTS(file_type);
    DOWNLOAD_PRINTS(username);
    DOWNLOAD_PRINTS(password);

    /* ???????????? */
    
#if 0 //EasyCWMP????????????
	n = backup_add_download(command_key, delay, file_size, download_url, file_type, username, password);
	cwmp_add_download(command_key, delay, file_size, download_url, file_type, username, password, n);
#else
    /* ?????????????????????????????????????????? rongtao@sylincom.com */
    external_action_download_execute_easy(download_url, file_size);
#endif
    
	FREE(file_type);
	FREE(command_key);
	FREE(username);
	FREE(password);

	t = mxmlNewElement(body_out, "cwmp:DownloadResponse");
	if (!t) return -1;

	b = mxmlNewElement(t, "Status");
	if (!b) return -1;

	b = mxmlNewElement(t, "StartTime");
	if (!b) return -1;

	b = mxmlNewOpaque(b, UNKNOWN_TIME);
	if (!b) return -1;

	b = mxmlFindElement(t, tree_out, "Status", NULL, NULL, MXML_DESCEND);
	if (!b) return -1;

	b = mxmlNewOpaque(b, "1");

	b = mxmlNewElement(t, "CompleteTime");
	if (!b) return -1;

	b = mxmlNewOpaque(b, UNKNOWN_TIME);
	if (!b) return -1;

	cwmp_log(NAME, L_NOTICE, "send DownloadResponse to the ACS\n");
	return 0;

fault_out:
	xml_create_generic_fault_message(body_out, code);
	FREE(file_type);
	FREE(command_key);
	FREE(username);
	FREE(password);
	return 0;
}



/** 
 *  CPE upload 
 *  ??????
 *  ACS????????????????????????CPE?????????????????????????????????????????????
 *
 *  ????????????????????????
 *      ???1 Vendor Configuration File??? [DEPRECATED]
 *      ???2 Vendor Log File??? [DEPRECATED]
 *      ???3 Vendor Configuration File <i>???
 *      ???4 Vendor Log File <i>???
 *
 *  rongtao@sylincom.com
 */
static int xml_handle_upload(mxml_node_t *body_in, mxml_node_t *tree_in, mxml_node_t *tree_out)
{
	cwmp_log(NAME, L_NOTICE, "Recv Upload Request from the ACS\n");
    
	mxml_node_t *n, *t, *b = body_in, *body_out;
	char *upload_url = NULL,
		*command_key = NULL, *file_type = NULL, *username = NULL,
		*password = NULL, r;
	int delay = -1, code = FAULT_9002;

	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body", NULL, NULL, MXML_DESCEND);
	if (!body_out) {
		printf("!body_out) \n" );
		return -1;
	}

	while (b != NULL) {
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "CommandKey")) {
			FREE(command_key);
			command_key = xml_get_value_with_whitespace(&b, body_in);
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "CommandKey") &&
			!b->child) {
			FREE(command_key);
			command_key = strdup("");
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "FileType")) {
			FREE(file_type);
			file_type = xml_get_value_with_whitespace(&b, body_in);
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "URL")) {
			upload_url = b->value.opaque;
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "Username")) {
			FREE(username);
			username = xml_get_value_with_whitespace(&b, body_in);
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "Username") &&
			!b->child) {
			FREE(username);
			username = strdup("");
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "Password")) {
			FREE(password);
			password = xml_get_value_with_whitespace(&b, body_in);
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "Password") &&
			!b->child) {
			FREE(password);
			password = strdup("");
		}
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "DelaySeconds")) {
			delay = atoi(b->value.opaque);
		}
		b = mxmlWalkNext(b, body_in, MXML_DESCEND);
	}
	if (!upload_url || !command_key || !file_type || !username || !password || delay < 0) {
		code = FAULT_9003;
		goto fault_out;
	}
	if (sscanf(upload_url,"%*[a-zA-Z_0-9]://%c",&r) < 1 ||
		sscanf(upload_url,"%*[^:]://%*[^:]:%*[^@]@%c",&r) == 1) {
		code = FAULT_9003;
		goto fault_out;
	}
	if (cwmp->upload_count >= MAX_UPLOAD) {
		code = FAULT_9004;
		goto fault_out;
	}

    
#define UPLOAD_PRINTS(string) cwmp_log(NAME, L_NOTICE, "Upload: ActualCMD:  %s = %s\n", #string, string)
#define UPLOAD_PRINTI(integer) cwmp_log(NAME, L_NOTICE, "Upload: ActualCMD:  %s = %d\n", #integer, integer)

    
    cwmp_log(NAME, L_NOTICE, "Upload: URL %s\n", upload_url);
    UPLOAD_PRINTS(command_key);
    UPLOAD_PRINTI(delay);
    UPLOAD_PRINTS(upload_url);
    UPLOAD_PRINTS(file_type);
    UPLOAD_PRINTS(username);
    UPLOAD_PRINTS(password);

#if 0 //???????????????????????????
	n = backup_add_upload(command_key, delay, upload_url, file_type, username, password);
	cwmp_add_upload(command_key, delay, upload_url, file_type, username, password, n);
#else
    /* ?????????????????????????????? */
    external_action_upload_execute(upload_url, file_type, NULL, NULL);
#endif

    
	FREE(file_type);
	FREE(command_key);
	FREE(username);
	FREE(password);

	t = mxmlNewElement(body_out, "cwmp:UploadResponse");
	if (!t) return -1;

	b = mxmlNewElement(t, "Status");
	if (!b) return -1;

	b = mxmlNewElement(t, "StartTime");
	if (!b) return -1;

	b = mxmlNewOpaque(b, UNKNOWN_TIME);
	if (!b) return -1;

	b = mxmlFindElement(t, tree_out, "Status", NULL, NULL, MXML_DESCEND);
	if (!b) return -1;

	b = mxmlNewOpaque(b, "1");

	b = mxmlNewElement(t, "CompleteTime");
	if (!b) return -1;

	b = mxmlNewOpaque(b, UNKNOWN_TIME);
	if (!b) return -1;

	return 0;

fault_out:
	xml_create_generic_fault_message(body_out, code);
	FREE(file_type);
	FREE(command_key);
	FREE(username);
	FREE(password);
	return 0;
}


/*  */

/** 
 *  CPE FactoryReset 
 *   
 *   ????????????CPE?????????????????????????????????????????????????????????????????? 
 *   ?????????????????????????????????CPE???????????????????????????????????? 
 *   ???58??????????????????????????????????????????59?????????????????????????????????
 *   
 *  Reference:<TR-069_Amendment-6.pdf>
 *  rongtao@sylincom.com
 */
static int xml_handle_factory_reset(mxml_node_t *node, mxml_node_t *tree_in, mxml_node_t *tree_out)
{
	mxml_node_t *body_out, *b;

	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body", NULL, NULL, MXML_DESCEND);
	if (!body_out) return -1;

	b = mxmlNewElement(body_out, "cwmp:FactoryResetResponse");
	if (!b) return -1;

	cwmp_add_handler_end_session(ENDS_FACTORY_RESET);

	cwmp_log(NAME, L_NOTICE, "send FactoryResetResponse to the ACS\n");
	return 0;
}

 /*  */
/** 
 *  CPE Reboot 
 *   
 *   
 *  Reference:<TR-069_Amendment-6.pdf>
 *  rongtao@sylincom.com
 */
static int xml_handle_reboot(mxml_node_t *node, mxml_node_t *tree_in, mxml_node_t *tree_out)
{
	mxml_node_t *b = node, *body_out;
	char *command_key = NULL;
	int code = FAULT_9002;

	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body", NULL, NULL, MXML_DESCEND);
	if (!body_out) return -1;

	while (b) {
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "CommandKey")) {
			FREE(command_key);
			command_key = xml_get_value_with_whitespace(&b, node);
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "CommandKey") &&
			!b->child) {
			FREE(command_key);
			command_key = strdup("");
		}
		b = mxmlWalkNext(b, node, MXML_DESCEND);
	}
    
	if (!command_key) {
		code = FAULT_9003;
		goto fault_out;
	}

	b = mxmlNewElement(body_out, "cwmp:RebootResponse");
	if (!b) {
		FREE(command_key);
		return -1;
	}

	backup_add_event(EVENT_M_REBOOT, command_key, 0);
	cwmp_add_handler_end_session(ENDS_REBOOT);

	FREE(command_key);

	cwmp_log(NAME, L_NOTICE, "send RebootResponse to the ACS\n");
	return 0;

fault_out:
	xml_create_generic_fault_message(body_out, code);
	FREE(command_key);
	return 0;
}


/*  */

/** 
 *  CPE ScheduleInform 
 *   
 *      ACS??????????????????????????????CPE????????????????????????????????????Inform?????????????????????????????????Inform????????????????????????
 *   
 *      ???49??????????????????????????????????????????50?????????????????????????????????
 *   
 *      ??????CPE????????????????????????ScheduleInform??????????????????????????????ScheduleInform?????????
 *      ???CPE????????????????????????ScheduleInform???????????????????????????????????????????????????????????????????????????DelaySeconds???????????????????????????
 *      ????????????????????????CPE?????????????????????????????????ScheduleInform???????????????CPE?????????????????????????????? 
 *      CPE???????????????????????????ScheduleInform??????????????? 
 *      CPE??????????????????ScheduleInform??????????????????????????????????????????????????????ScheduleInform???????????????CommandKey???
 *      ????????????????????????ScheduleInform???DelaySeconds????????????
 *   
 *  ??????????????????
 *  <cwmp:ScheduleInform>
 *      <DelaySeconds xsi:type='xsd:unsignedint'>2</DelaySeconds>  
 *      <CommandKey xsi:type='xsd:string'>Reboot</CommandKey>  
 *  </cwmp:ScheduleInform> 
 *   
 *  Reference:<TR-069_Amendment-6.pdf>
 *  rongtao@sylincom.com
 */
static int xml_handle_schedule_inform(mxml_node_t *body_in, mxml_node_t *tree_in, mxml_node_t *tree_out)
{
	mxml_node_t *b = body_in, *body_out;
	char *command_key = NULL;
	char *delay_seconds = NULL;
	int  delay = 0, code = FAULT_9002;

	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body", NULL, NULL, MXML_DESCEND);
	if (!body_out) return -1;

	while (b) {
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "CommandKey")) {
			FREE(command_key);
			command_key = xml_get_value_with_whitespace(&b, body_in);
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "CommandKey") &&
			!b->child) {
			FREE(command_key);
			command_key = strdup("");
		}

		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "DelaySeconds")) {
			delay_seconds = b->value.opaque;
		}
		b = mxmlWalkNext(b, body_in, MXML_DESCEND);
	}
	if (delay_seconds) delay = atoi(delay_seconds);

	if (command_key && (delay > 0)) {
		cwmp_add_scheduled_inform(command_key, delay);
		b = mxmlNewElement(body_out, "cwmp:ScheduleInformResponse");
		if (!b) goto error;
	}
	else {
		code = FAULT_9003;
		goto fault_out;
	}
	FREE(command_key);
	cwmp_log(NAME, L_NOTICE, "send ScheduleInformResponse to the ACS\n");
	return 0;

fault_out:
	FREE(command_key);
	xml_create_generic_fault_message(body_out, code);
	return 0;

error:
	FREE(command_key);
	return -1;
}


/** 
 *  CPE AddObject 
 *      ACS???????????????????????????????????????????????????????????? ????????????????????????????????????????????????????????????????????????????????? 
 *
 *  ?????????
 *
 *  Top.Group.Object???
 *
 *  ?????????????????????????????????????????????????????? ??????????????????CPE?????????????????????????????? 
 *  ?????????????????????????????????????????????????????????????????????????????????????????????DeleteObject?????????????????????????????? 
 *  ????????????????????????????????????????????????????????????????????????????????????????????? 
 *  ???????????????AddObject???????????????????????????2?????????????????????Parameter????????????????????????
 *
 *  Top.Group.Object.2.Parameter
 *
 *  ??????CPE???????????????????????????????????????3.6.1?????????????????????????????????????????????
 *      ??????????????????????????????????????????A.2.2.2??????????????????????????????
 *      ?????????????????????????????????????????????????????????????????????CPE?????????????????????????????????????????????????????????
 *      ????????????????????????????????????????????????CPE??????????????? cpe-??????????????????????????????????????????????????????????????????
 *      ???????????????????????????????????????ACS?????????????????????????????????????????????????????????
 *
 *  ??????????????????????????????????????????????????? a?????????????????????
 *
 *  Top.Group.Object.[a].
 *
 *  ???????????????????????????????????? a?????????????????????????????????????????????????????????????????????
 *  ???????????????????????????????????????????????????????????????????????????????????????
 *
 *  Top.Group.Object.[a].parameter
 *
 *  ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
 *
 *      ?????????????????????????????????????????????????????????????????????????????????????????????????????????
 *      ???AccessList??????????????????????????????
 *
 *  ??????????????????????????????29????????????????????????????????????30????????????
 *
 *  ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
 *  ????????????????????????CPE????????????????????????????????????????????????????????????????????????????????????????????????
 *  CPE????????????????????????????????????????????????????????????????????????????????????????????????CPE???????????????????????????????????????
 *
 *  * ??????CPE??????????????????????????????????????????????????????????????????
 *
 *  ????????????????????????????????????CPE?????????AddObject???????????????????????????????????????????????????
 *  ???CPE?????????????????????Status???????????????0??????????????????????????????????????????
 *
 *  ??????CPE???????????????????????????????????????????????????CPE??????????????????????????????????????????
 *  ???????????????????????????Status???????????????1????????????????????????????????????????????????????????????????????????????????????????????????????????????
 *  ??????????????????????????????????????????????????????????????????CPE??????AddObject????????????????????????????????????
 *  ??????????????????????????????ParameterKey?????????????????????????????????????????????????????????????????????
 *  ?????????????????????????????????????????????
 *  CPE?????????????????????SetParameterValues???GetParameterValues???SetParameterAttributes???GetParameterAttributes
 *  ???????????????Object??????Parameters???????????????
 *  ????????????AddObject???????????????????????????????????????-object???DeleteObject????????????????????????????????????????????????
 *
 *  ??????AddObject????????????Status??????1?????????????????????????????????????????????????????????????????????????????????
 *  ????????????????????????????????????????????????????????????CPE?????????????????????????????????????????????
 *  ???CPE?????????????????????????????????????????????????????????????????????????????????CPE????????????????????????
 *  ??????ACS??????????????????CPE??????????????????Reboot??????????????????????????????????????????????????????
 *  ?????????????????????CPE?????????????????????????????????????????????????????????CPE????????????????????????????????????????????????
 *  ???CPE?????????????????????????????????????????????????????????????????????????????????
 *  ACS??????????????????????????????????????????????????????????????????????????????ACS???????????????
 *  ?????????????????????????????????????????????SetParameterValues???AddObject???DeleteObject???????????????????????????
 *  ????????????????????????Status???1????????????????????????????????????????????????????????????????????????????????????
 *  ??????AddObject?????????CPE????????????????????????????????????CPE?????????????????????????????????????????????????????????????????????
 *   
 *  Reference:<TR-069_Amendment-6.pdf>
 *  rongtao@sylincom.com
 */
static int xml_handle_AddObject(mxml_node_t *body_in, mxml_node_t *tree_in, mxml_node_t *tree_out)
{
	cwmp_log(NAME, L_NOTICE, "Recv AddObject Request from the ACS\n");
    
	mxml_node_t *b = body_in, *t, *body_out;
	char *object_name = NULL, *param_key = NULL;
	char *status = NULL, *fault = NULL, *instance = NULL;
	int code = FAULT_9002;

	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body", NULL, NULL, MXML_DESCEND);
	if (!body_out) return -1;

	while (b) {
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "ObjectName")) {
			object_name = b->value.opaque;
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "ObjectName") &&
			!b->child) {
			object_name = "";
		}

		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "ParameterKey")) {
			free(param_key);
			param_key = xml_get_value_with_whitespace(&b, body_in);
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "ParameterKey") &&
			!b->child) {
			free(param_key);
			param_key = strdup("");
		}
		b = mxmlWalkNext(b, body_in, MXML_DESCEND);
	}

	if (!param_key) {
		code = FAULT_9003;
		goto fault_out;
	}

	if (object_name) {
		external_action_parameter_execute("add", "object", object_name, NULL);
		if (external_action_handle(json_handle_add_object)) goto fault_out;
	} else {
		code = FAULT_9003;
		goto fault_out;
	}

    cwmp_log(NAME, L_NOTICE, "easycwmp add object %s \n", object_name);
    
	external_fetch_add_obj_resp(&status, &instance, &fault);

	if (fault && fault[0] == '9') {
		code = xml_get_index_fault(fault);
		goto fault_out;
	}
	if (!status || !instance) {
		code = FAULT_9002;
		goto fault_out;
	}

    cwmp_log(NAME, L_NOTICE, "easycwmp apply object , param_key %s \n", param_key);

	external_action_simple_execute("apply", "object", param_key);
	FREE(param_key);

	t = mxmlNewElement(body_out, "cwmp:AddObjectResponse");
	if (!t) goto error;

	b = mxmlNewElement(t, "InstanceNumber");
	if (!b) goto error;
	b = mxmlNewOpaque(b, instance);
	if (!b) goto error;

	b = mxmlNewElement(t, "Status");
	if (!b) goto error;
	b = mxmlNewOpaque(b, status);
	if (!b) goto error;

	free(instance);
	free(status);
	free(fault);

    //????????????Object
    //<cwmp:AddObject>
    //    <ObjectName xsi:type='xsd:string'>Top.Group.Object.rongtao</ObjectName>  
    //    <ParameterKey xsi:type='xsd:string'>1234321</ParameterKey>  
    //</cwmp:AddObject> 

    //????????????object??????
    //<soap_env:Body>
    //    <soap_env:Fault>
    //        <faultcode>Client</faultcode>
    //        <faultstring>CWMP fault</faultstring>
    //        <detail>
    //            <cwmp:Fault>
    //                <FaultCode>9005</FaultCode>
    //                <FaultString>Invalid parameter name</FaultString>
    //            </cwmp:Fault>
    //        </detail>
    //    </soap_env:Fault>
    //</soap_env:Body>


	cwmp_log(NAME, L_NOTICE, "send AddObjectResponse to the ACS\n");
	return 0;

fault_out:
	cwmp_log(NAME, L_NOTICE, "Fault in the param: %s, Fault code: %s\n", object_name ? object_name : "", fault_array[code].code);
	xml_create_generic_fault_message(body_out, code);
	FREE(param_key);
	free(instance);
	free(status);
	free(fault);
	return 0;

error:
	FREE(param_key);
	free(instance);
	free(status);
	free(fault);
	return -1;
}

/* DeleteObject */

static int xml_handle_DeleteObject(mxml_node_t *body_in,
					mxml_node_t *tree_in,
					mxml_node_t *tree_out)
{
	cwmp_log(NAME, L_NOTICE, "Recv DeleteObject Request from the ACS\n");
    
	mxml_node_t *b = body_in, *t, *body_out;
	char *object_name = NULL, *param_key = NULL;
	char *status = NULL, *fault = NULL;
	int code = FAULT_9002;

	body_out = mxmlFindElement(tree_out, tree_out, "soap_env:Body", NULL, NULL, MXML_DESCEND);
	if (!body_out) return -1;

	while (b) {
		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "ObjectName")) {
			object_name = b->value.opaque;
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "ObjectName") &&
			!b->child) {
			object_name = "";
		}

		if (b && b->type == MXML_OPAQUE &&
			b->value.opaque &&
			b->parent->type == MXML_ELEMENT &&
			!strcmp(b->parent->value.element.name, "ParameterKey")) {
			free(param_key);
			param_key = xml_get_value_with_whitespace(&b, body_in);
		}
		if (b && b->type == MXML_ELEMENT &&
			!strcmp(b->value.element.name, "ParameterKey") &&
			!b->child) {
			free(param_key);
			param_key = strdup("");
		}
		b = mxmlWalkNext(b, body_in, MXML_DESCEND);
	}

	if (!param_key) {
		code = FAULT_9003;
		goto fault_out;
	}

	if (object_name) {
		external_action_parameter_execute("delete", "object", object_name, NULL);
		if (external_action_handle(json_handle_method_status)) goto fault_out;
	} else {
		code = FAULT_9003;
		goto fault_out;
	}

    cwmp_log(NAME, L_NOTICE, "easycwmp delete object %s \n", object_name);

	external_fetch_method_resp_status(&status, &fault);

	if (fault && fault[0] == '9') {
		code = xml_get_index_fault(fault);
		goto fault_out;
	}
	if (!status ) {
		code = FAULT_9002;
		goto fault_out;
	}
    
    cwmp_log(NAME, L_NOTICE, "easycwmp apply object , param_key %s \n", param_key);

	external_action_simple_execute("apply", "object", param_key);
	FREE(param_key);

	t = mxmlNewElement(body_out, "cwmp:DeleteObjectResponse");
	if (!t) goto error;

	b = mxmlNewElement(t, "Status");
	if (!b) goto error;
	b = mxmlNewOpaque(b, status);
	if (!b) goto error;
	free(status);
	free(fault);

	cwmp_log(NAME, L_NOTICE, "send DeleteObjectResponse to the ACS\n");
	return 0;

fault_out:
	cwmp_log(NAME, L_NOTICE, "Fault in the param: %s, Fault code: %s\n", object_name ? object_name : "", fault_array[code].code);
	xml_create_generic_fault_message(body_out, code);
	FREE(param_key);
	free(status);
	free(fault);
	return 0;

error:
	FREE(param_key);
	free(status);
	free(fault);
	return -1;
}

/* Fault */

mxml_node_t *xml_create_generic_fault_message(mxml_node_t *body, int code)
{
	mxml_node_t *b, *t, *u;

	b = mxmlNewElement(body, "soap_env:Fault");
	if (!b) return NULL;

	t = mxmlNewElement(b, "faultcode");
	if (!t) return NULL;

	u = mxmlNewOpaque(t, fault_array[code].type);
	if (!u) return NULL;

	t = mxmlNewElement(b, "faultstring");
	if (!t) return NULL;

	u = mxmlNewOpaque(t, "CWMP fault");
	if (!u) return NULL;

	b = mxmlNewElement(b, "detail");
	if (!b) return NULL;

	b = mxmlNewElement(b, "cwmp:Fault");
	if (!b) return NULL;

	t = mxmlNewElement(b, "FaultCode");
	if (!t) return NULL;

	u = mxmlNewOpaque(t, fault_array[code].code);
	if (!u) return NULL;

	t = mxmlNewElement(b, "FaultString");
	if (!t) return NULL;

	u = mxmlNewOpaque(t, fault_array[code].string);
	if (!u) return NULL;

	cwmp_log(NAME, L_NOTICE, "send Fault: %s: '%s'\n", fault_array[code].code, fault_array[code].string);
	return b;
}

int xml_create_set_parameter_value_fault_message(mxml_node_t *body, int code)
{
	struct external_parameter *external_parameter;
	mxml_node_t *b, *n, *t;
	int index;

	n = xml_create_generic_fault_message(body, code);
	if (!n)
		return -1;

	while (external_list_parameter.next != &external_list_parameter) {

		external_parameter = list_entry(external_list_parameter.next, struct external_parameter, list);

		if (external_parameter->fault_code && external_parameter->fault_code[0]=='9') {

			index = xml_get_index_fault(external_parameter->fault_code);

			b = mxmlNewElement(n, "SetParameterValuesFault");
			if (!b) return -1;

			t = mxmlNewElement(b, "ParameterName");
			if (!t) return -1;
			t = mxmlNewOpaque(t, external_parameter->name);
			if (!t) return -1;

			t = mxmlNewElement(b, "FaultCode");
			if (!t) return -1;
			t = mxmlNewOpaque(t, external_parameter->fault_code);
			if (!t) return -1;

			t = mxmlNewElement(b, "FaultString");
			if (!t) return -1;
			t = mxmlNewOpaque(t, fault_array[index].string);
			if (!t) return -1;
		}
		external_parameter_delete(external_parameter);
	}
	return 0;
}

int xml_add_cwmpid(mxml_node_t *tree)
{
	mxml_node_t *b;
	static unsigned int id = 0;
	char buf[16];
	b = mxmlFindElement(tree, tree, "cwmp:ID", NULL, NULL, MXML_DESCEND);
	if (!b) return -1;
	snprintf(buf, sizeof(buf), "%u", ++id);
	b = mxmlNewOpaque(b, buf);
	if (!b) return -1;
	return 0;
}
