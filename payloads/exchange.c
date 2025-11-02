#include "exchange.h"
#include <stdlib.h>

exchange_t* exg_create(buffer_t* raw) {
	exchange_t* self = calloc(1, sizeof(exchange_t));
	self->raw = raw;

	return self;
}

void exg_unpack_hdr(exchange_t* self) {
	buf_rread(self->raw, &self->hdr.initiator_spi, 8);
	buf_rread(self->raw, &self->hdr.responder_spi, 8);
	buf_read(self->raw, &self->hdr.next_payload, 1);
	buf_read(self->raw, &self->hdr.version, 1);
	buf_read(self->raw, &self->hdr.exchange_type, 1);
	buf_read(self->raw, &self->hdr.flags, 1);
	buf_rread(self->raw, &self->hdr.message_id, 4);
	buf_rread(self->raw, &self->hdr.length, 4);
}
