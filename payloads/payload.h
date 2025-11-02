#ifndef __PAYLOAD_H__
#define __PAYLOAD_H__

typedef enum {
	IKE_PAYLOAD_NONE        = 0,
	IKE_PAYLOAD_SA          = 33,
	IKE_PAYLOAD_KE          = 34,
	IKE_PAYLOAD_IDi         = 35,
	IKE_PAYLOAD_IDr         = 36,
	IKE_PAYLOAD_CERT        = 37,
	IKE_PAYLOAD_CERTREQ     = 38,
	IKE_PAYLOAD_AUTH        = 39,
	IKE_PAYLOAD_NONCE       = 40,
	IKE_PAYLOAD_NOTIFY      = 41,
	IKE_PAYLOAD_DELETE      = 42,
	IKE_PAYLOAD_VENDOR      = 43,
	IKE_PAYLOAD_TSi         = 44,
	IKE_PAYLOAD_TSr         = 45,
	IKE_PAYLOAD_SK          = 46,
	IKE_PAYLOAD_CP          = 47,
	IKE_PAYLOAD_EAP         = 48,
}PLD_TYPE;

typedef struct payload_t {
	PLD_TYPE	type;
	void*			body;

	struct payload_t* next;
}payload_t;

payload_t*	pld_create(PLD_TYPE type);
void				pld_free(payload_t* self);

#endif //__PAYLOAD_H__
