/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "./asn1c/S1AP-IEs.asn"
 * 	`asn1c -fcompound-names -fno-include-deps -gen-PER -findirect-choice -pdu=S1AP-PDU`
 */

#ifndef	_ExpectedHOInterval_H_
#define	_ExpectedHOInterval_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ExpectedHOInterval {
	ExpectedHOInterval_sec15	= 0,
	ExpectedHOInterval_sec30	= 1,
	ExpectedHOInterval_sec60	= 2,
	ExpectedHOInterval_sec90	= 3,
	ExpectedHOInterval_sec120	= 4,
	ExpectedHOInterval_sec180	= 5,
	ExpectedHOInterval_long_time	= 6
	/*
	 * Enumeration is extensible
	 */
} e_ExpectedHOInterval;

/* ExpectedHOInterval */
typedef long	 ExpectedHOInterval_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ExpectedHOInterval_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ExpectedHOInterval;
extern const asn_INTEGER_specifics_t asn_SPC_ExpectedHOInterval_specs_1;
asn_struct_free_f ExpectedHOInterval_free;
asn_struct_print_f ExpectedHOInterval_print;
asn_constr_check_f ExpectedHOInterval_constraint;
ber_type_decoder_f ExpectedHOInterval_decode_ber;
der_type_encoder_f ExpectedHOInterval_encode_der;
xer_type_decoder_f ExpectedHOInterval_decode_xer;
xer_type_encoder_f ExpectedHOInterval_encode_xer;
oer_type_decoder_f ExpectedHOInterval_decode_oer;
oer_type_encoder_f ExpectedHOInterval_encode_oer;
per_type_decoder_f ExpectedHOInterval_decode_uper;
per_type_encoder_f ExpectedHOInterval_encode_uper;
per_type_decoder_f ExpectedHOInterval_decode_aper;
per_type_encoder_f ExpectedHOInterval_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ExpectedHOInterval_H_ */
#include <asn_internal.h>
