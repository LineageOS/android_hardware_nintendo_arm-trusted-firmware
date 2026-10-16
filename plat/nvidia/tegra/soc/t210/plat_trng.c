/*
 * Copyright (c) 2026, The LineageOS Project. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdbool.h>
#include <stdint.h>

#include <plat/common/plat_trng.h>
#include <security_engine.h>
#include <smccc_helpers.h>

DEFINE_SVC_UUID2(_plat_trng_uuid,
	0x6beccb80, 0xf1c1, 0x4278, 0xb5, 0x24,
	0xd3, 0xf8, 0xec, 0xcc, 0x0d, 0x21
);
uuid_t plat_trng_uuid;

bool plat_get_entropy(uint64_t *out)
{
	return tegra_se_generate_random(out) == 0;
}

void plat_entropy_setup(void)
{
	plat_trng_uuid = _plat_trng_uuid;
}
