/*
 * Module signature checker (DISABLED)
 *
 * Copyright (C) 2012 Red Hat, Inc. All Rights Reserved.
 * Written by David Howells (dhowells@redhat.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public Licence
 * as published by the Free Software Foundation; either version
 * 2 of the Licence, or (at your option) any later version.
 *
 * MODIFIED: Signature verification completely removed.
 */

#include <linux/kernel.h>
#include <linux/errno.h>
#include <keys/system_keyring.h>
#include <crypto/public_key.h>
#include "module-internal.h"

/*
 * Module signature information block.
 *
 * The constituents of the signature section are, in order:
 *
 *	- Signer's name
 *	- Key identifier
 *	- Signature data
 *	- Information block
 */
struct module_signature {
	u8	algo;		/* Public-key crypto algorithm [0] */
	u8	hash;		/* Digest algorithm [0] */
	u8	id_type;	/* Key identifier type [PKEY_ID_PKCS7] */
	u8	signer_len;	/* Length of signer's name [0] */
	u8	key_id_len;	/* Length of key identifier [0] */
	u8	__pad[3];
	__be32	sig_len;	/* Length of signature data */
};

/*
 * Verify the signature on a module.
 *
 * This function is intentionally disabled to allow loading of any module
 * regardless of signature status. No verification is performed.
 */
int mod_verify_sig(const void *mod, unsigned long *_modlen)
{
	/* Signature verification disabled - always succeed */
	pr_warn("Module signature verification is DISABLED - any module will be accepted\n");
	return 0;
}
