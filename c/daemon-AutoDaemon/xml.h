
#ifndef _TOOLS_XML_H
#define _TOOLS_XML_H 1

/* Dependencies ------------------------------------------------------------------------------------------------------*/

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlmemory.h>
#include <libxml/xpath.h>


extern char *default_config_xml_file[];

/* Constants ---------------------------------------------------------------------------------------------------------*/
/* Types -------------------------------------------------------------------------------------------------------------*/
/* Macros ------------------------------------------------------------------------------------------------------------*/
/* Globals -----------------------------------------------------------------------------------------------------------*/
/* Functions ---------------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
 * Description: 
 *      Copyright (C) VBSM Code
 * Input: 
 *
 * Output: 
 ***********************************************************************************************************************/
xmlDocPtr xml_doc(xmlChar *szDocName); 

/***********************************************************************************************************************
 * Description: 
 *      Copyright (C) VBSM Code
 * Input: 
 *
 * Output: 
 ***********************************************************************************************************************/
xmlXPathContextPtr xml_context(xmlDocPtr doc);

/***********************************************************************************************************************
 * Description: 
 *      Copyright (C) VBSM Code
 * Input: 
 *
 * Output: 
 ***********************************************************************************************************************/
int alter_xml_node_value(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *content);

/***********************************************************************************************************************
 * Description: 
 *      Copyright (C) VBSM Code
 * Input: 
 *
 * Output: 
 ***********************************************************************************************************************/
int alter_xml_node_value_next(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *content, int index);

/***********************************************************************************************************************
 * Description: 
 *      Copyright (C) VBSM Code
 * Input: 
 *
 * Output: 
 ***********************************************************************************************************************/
xmlChar* get_xml_node_value(xmlXPathContextPtr context, const xmlChar *xpath);
xmlChar* get_xml_node_prop_value(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *propname);
xmlChar* has_xml_node_prop_value(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *propname);

/***********************************************************************************************************************
 * Description: 
 *      Copyright (C) VBSM Code
 * Input: 
 *
 * Output: 
 ***********************************************************************************************************************/
xmlChar* get_xml_node_value_next(xmlXPathContextPtr context, const xmlChar *xpath, int index);
xmlChar* get_xml_node_prop_value_next(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *propname, int index);

/***********************************************************************************************************************
 * Description: 
 *      Copyright (C) VBSM Code
 * Input: 
 *
 * Output: 
 ***********************************************************************************************************************/
int alter_xml_node_attr(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *attr);

int alter_xml_node_prop_value(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *propname,
                                                const xmlChar *propcontent);

/***********************************************************************************************************************
 * Description: 
 *      Copyright (C) VBSM Code
 * Input: 
 *
 * Output: 
 ***********************************************************************************************************************/
int alter_xml_node_attr_next(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *attr);

int alter_xml_node_prop_value_next(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *propname,
                                                const xmlChar *propcontent, int index);

/***********************************************************************************************************************
 * Description: 
 *      Copyright (C) VBSM Code
 * Input: 
 *
 * Output: 
 ***********************************************************************************************************************/
int save_xml(char *szDocName,xmlDocPtr doc,xmlXPathContextPtr context);
void close_xml(xmlDocPtr doc);



#endif /*<_TOOLS_XML_H>*/


