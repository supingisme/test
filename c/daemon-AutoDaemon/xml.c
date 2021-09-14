#include "xml.h"
#include "log.h"



char *default_config_xml_file[] = {
"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>",
"<config-root>",
"    <executions>",
"        <exe name=\"ls\" args=\"-l\">/usr/bin</exe>",
"        <exe name=\"tree\" args=\"/home\">/usr/bin</exe>",
"    </executions>",
"</config-root>",
NULL,
};




xmlDocPtr xml_doc(xmlChar *szDocName)
{
    xmlDocPtr  doc = xmlReadFile((char*)szDocName, "utf-8", XML_PARSE_RECOVER);
    if (doc == NULL)
    {
    	error("doc is null\n");
        return NULL;
    }
    return doc;
}

/***********************************************************************************************************************
 * Description: get the context of the doc.
 *
 * Input: szdocname: doc name;
 *
 * Output:  return -1,failed;
 *          return 0, success
 ***********************************************************************************************************************/
xmlXPathContextPtr xml_context(xmlDocPtr doc)
{
    xmlXPathContextPtr context = xmlXPathNewContext(doc);
    if (context ==  NULL)
    {
    	error("context is null\n");
        return NULL;
    }
    return context;
}

/***********************************************************************************************************************
 * Description: alter the node value in xml files.
 *
 * Input: context: file context;
 *          xpath: node path;
 *        content: the value of node;
 *
 * Output:  return -1,failed;
 *          return 0, success
 ***********************************************************************************************************************/
int alter_xml_node_value(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *content)
{
    alter_xml_node_value_next(context, xpath, content, 0);
    return 0;
}


/************************************************************************************************************************
 * alter the node value in xml files.
 *
 * Input: context: file context;
 *        xpath: node path;
 *        content: the value of node;
 * Output:  return -1,failed;
 *          return 0, success
 ***********************************************************************************************************************/
int alter_xml_node_value_next(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *content, int index)
{
	xmlXPathObjectPtr result;
	result = xmlXPathEvalExpression(xpath, context);
	if (result == NULL)
	{
		error("result is null\n");
		return -1;
	}
	if (xmlXPathNodeSetIsEmpty(result->nodesetval))
	{
        xmlXPathFreeObject(result);
        error("nodeset is empty, path: %s\n", xpath);
        return -1;
	}
	xmlNodeSetContent(result->nodesetval->nodeTab[index], content);
	return 0;
}

/***********************************************************************************************************************
 * Description: alter the node value in xml files.
 *
 * Input: context: file context;
 *          xpath: node path;
 *        content: the value of node;
 *
 * Output:  return -1,failed;
 *          return 0, success
 ***********************************************************************************************************************/
xmlChar* get_xml_node_value(xmlXPathContextPtr context, const xmlChar *xpath)
{
    return get_xml_node_value_next(context, xpath, 0);
}

/***********************************************************************************************************************
 * Description: alter the node value in xml files.
 *
 * Input: context: file context;
 *          xpath: node path;
 *        content: the value of node;
 *
 * Output:  return -1,failed;
 *          return 0, success
 ***********************************************************************************************************************/
xmlChar* get_xml_node_value_next(xmlXPathContextPtr context, const xmlChar *xpath, int index)
{
    xmlXPathObjectPtr result;
    result = xmlXPathEvalExpression((const xmlChar *)xpath, context);
    if (result == NULL)
    {
    	error("result is null\n");
        return NULL;
    }
    if (xmlXPathNodeSetIsEmpty(result->nodesetval))
    {
        xmlXPathFreeObject(result);
        error("nodeset is empty, path: %s\n", xpath);
        return NULL;
    }
    
    return xmlNodeGetContent(result->nodesetval->nodeTab[index]);;
}

xmlChar* get_xml_node_prop_value(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *propname)
{
    return get_xml_node_prop_value_next(context, xpath, propname, 0);
}

xmlChar* has_xml_node_prop_value(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *propname)
{
    xmlXPathObjectPtr result;
    result = xmlXPathEvalExpression(xpath, context);
    if (result == NULL)
    {
    	error("result is null\n");
        return NULL;
    }
    if (xmlXPathNodeSetIsEmpty(result->nodesetval))
    {
        xmlXPathFreeObject(result);
        error("nodeset is empty, path: %s\n", xpath);
        return NULL;
    }
    xmlAttr *_attr = xmlHasProp(result->nodesetval->nodeTab[0],(const xmlChar*)propname);
    xmlChar *_ret = NULL;
    if(_attr)
        _ret = (xmlChar *)_attr->name;
    
    return _ret;

}





xmlChar* get_xml_node_prop_value_next(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *propname, int index)
{
    xmlXPathObjectPtr result;
    result = xmlXPathEvalExpression(xpath, context);
    if (result == NULL)
    {
    	error("result is null\n");
        return NULL;
    }
    if (xmlXPathNodeSetIsEmpty(result->nodesetval))
    {
        xmlXPathFreeObject(result);
        error("nodeset is empty, path: %s\n", xpath);
        return NULL;
    }
    
    return xmlGetProp(result->nodesetval->nodeTab[index],(const xmlChar*)propname);
}



int alter_xml_node_prop_value(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *propname,
                                                const xmlChar *propcontent)
{
    return alter_xml_node_prop_value_next(context, xpath, propname, propcontent, 0);
}

int alter_xml_node_prop_value_next(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *propname,
                                                const xmlChar *propcontent, int index)
{
    xmlXPathObjectPtr result;
    result = xmlXPathEvalExpression(xpath, context);
    if (result == NULL)
    {
    	error("result is null\n");
        return -1;
    }
    if (xmlXPathNodeSetIsEmpty(result->nodesetval))
    {
        xmlXPathFreeObject(result);
        error("nodeset is empty, path: %s\n", xpath);
        return -1;
    }

    xmlSetProp(result->nodesetval->nodeTab[index],(const xmlChar*)propname, propcontent);
    
    return 0;
}


/***********************************************************************************************************************
 * Description: alter the node value in xml files.
 *
 * Input: context: file context;
 *          xpath: node path;
 *        content: the value of node;
 *
 * Output:  return -1,failed;
 *          return 0, success
 ***********************************************************************************************************************/
int alter_xml_node_attr(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *attr)
{
    xmlXPathObjectPtr result;
    result = xmlXPathEvalExpression(xpath,context);
    if (result == NULL)
    {
    	error("result is null\n");
        return -1;
    }
    if (xmlXPathNodeSetIsEmpty(result->nodesetval))
    {
        xmlXPathFreeObject(result);
        error("nodeset:%s is empty\n",xpath);
        return -1;
    }
    if (result->nodesetval->nodeTab[0]->children != NULL )
	{
		result->nodesetval->nodeTab[0]->children->name = attr;
	}
	else
	{
		result->nodesetval->nodeTab[0]->children->next->name = attr;
	}
    //result->nodesetval->nodeTab[0]->name = attr;

    return 0;
}

/***********************************************************************************************************************
 * Description:
 *
 * Input: 
 * 
 * Output:  return -1,failed;
 *          return 0, success
 ***********************************************************************************************************************/
int alter_xml_node_attr_next(xmlXPathContextPtr context, const xmlChar *xpath, const xmlChar *attr)
{
	xmlXPathObjectPtr result;
	result = xmlXPathEvalExpression(xpath,context);
	if (result == NULL)
	{
		error("result is null\n");
		return -1;
	}
	if (xmlXPathNodeSetIsEmpty(result->nodesetval))
	{
  		xmlXPathFreeObject(result);
  		error("nodeset is empty, path: %s\n", xpath);
		return -1;
	}
    if (result->nodesetval->nodeTab[0]->children != NULL )
    {
    	result->nodesetval->nodeTab[0]->children->next->name = attr;
    }
	
	return 0;
}


/***********************************************************************************************************************
 * Description: save the  xml files.
 *
 * Input: szdocname: file name;
 *          doc: the pointer to doc name;
 *          context:the doc context;
 *
 * Output: return -1,failed;
 *          return 0, success
 *          
 ***********************************************************************************************************************/
int save_xml(char *szDocName, xmlDocPtr doc, xmlXPathContextPtr context)
{
    /* no return funcs */
    xmlXPathFreeContext(context);
    xmlSaveFile(szDocName, doc);
    
    return 0;
}

void close_xml(xmlDocPtr doc)
{
    xmlFreeDoc(doc);
}


