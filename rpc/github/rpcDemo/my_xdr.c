/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "my.h"

bool_t
xdr_my_io_data_s (XDR *xdrs, my_io_data_s *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->mtype))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->len))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->data, 1024,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_my_io_data_t (XDR *xdrs, my_io_data_t *objp)
{
	register int32_t *buf;

	 if (!xdr_my_io_data_s (xdrs, objp))
		 return FALSE;
	return TRUE;
}
