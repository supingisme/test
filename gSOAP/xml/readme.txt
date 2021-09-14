XML Data Bindings
Or in other words, how to map schemas (XSD les) to C/C++ bindings for automatically reading
and writing XML data.
The XML C/C++ data binding in gSOAP provides and automated mechanism to encode any C
and C++ data type in XML (and decode XML back to C/C++ data). An XML schema (XSD
le) can be transformed into a set of C or C++ denitions that can be readily incorporated into
your application to manipulate XML with much more ease than DOM or SAX. Essentially, each
XML component denition in an XML schema has a C/C++ data type representation that has
equivalent type properties. The advantage of this approach is immediately apparent when we look
at an XSD complexType that maps to a class:


	<complexType name="Address"> 										class ns Address
		<sequence> 														{
			<element name="name" type="string"/> 							std::string name;
			<element name="home" type="tns:Location" minOccurs="0"/> 		ns_Location *home;
			<element name="phone" type="unsignedLong"/> 					ULONG64 phone;
			<element name="dob" type="dateTime"/> 							time_t dob;
		</sequence>
		<attribute name="ID" type="int" use="required"/> 					@int ID;
	</complexType> 														}


In this way, an automatic mapping between XML elements of the XML schema and members of a
class is created. No DOM traversals and SAX events are needed. In addition, the XML C/C++
data binding makes XML manipulation type safe. That is, the type safety of C/C++ ensures that
only valid XML documents can be parsed and generated.
The wsdl2h tool performs the mapping of WSDL and XML schemas to C and/or C++ automatically.
The output of wsdl2h is an annotated header le that includes comments and documentation on
the use of the C/C++ declarations in a SOAP/XML client/server or in a generic application for
reading and writing XML using the auto-generated serializers.