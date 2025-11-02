#ifndef __EXCHANGE_H__
#define __EXCHANGE_H__

#include "payload.h"
#include "buffer.h"

typedef struct {
	uint64_t	initiator_spi;
	uint64_t	responder_spi;
	uint8_t		next_payload;
	uint8_t		version;
	uint8_t		exchange_type;
	uint8_t		flags;
	uint32_t	message_id;
	uint32_t	length;
}ike_header_t;

typedef struct {
	ike_header_t	hdr;
	payload_t*		plds;

	buffer_t* raw; // packed
}exchange_t;

exchange_t* exg_create(buffer_t* raw);
void				exg_free(exchange_t* self);

void exg_push(exchange_t* self, payload_t* pld);
void exg_pack(exchange_t* self);
void exg_unpack_hdr(exchange_t* self);
void exg_unpack_plds(exchange_t* self);

#endif //__EXCHANGE_H__
