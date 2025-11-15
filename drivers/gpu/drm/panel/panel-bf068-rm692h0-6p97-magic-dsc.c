// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2025 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>

#include <video/mipi_display.h>

#include <drm/display/drm_dsc.h>
#include <drm/display/drm_dsc_helper.h>
#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct bf068_rm692h0_6p97_magic_dsc {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct drm_dsc_config dsc;
	struct gpio_desc *reset_gpio;
};

static inline
struct bf068_rm692h0_6p97_magic_dsc *to_bf068_rm692h0_6p97_magic_dsc(struct drm_panel *panel)
{
	return container_of(panel, struct bf068_rm692h0_6p97_magic_dsc, panel);
}

static void bf068_rm692h0_6p97_magic_dsc_reset(struct bf068_rm692h0_6p97_magic_dsc *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(40);
}

static int bf068_rm692h0_6p97_magic_dsc_on(struct bf068_rm692h0_6p97_magic_dsc *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x98);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x20, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x42);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x68, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x40);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x0a, 0xc9);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x0b, 0x17);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x0c, 0x35);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbe, 0xc9);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbf, 0x11);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc0, 0xc9);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbd, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xa1);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb3, 0x7f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfa, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x57);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc2, 0x48);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x5a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x1a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x0d, 0x64);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x40);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdc, 0xb8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x42);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xda, 0x82);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x81, 0x80);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x34);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x47, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x48, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9f, 0x5c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa0, 0xc4);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1c, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1d, 0x10);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x49, 0x55);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x34);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1e, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1f, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x20, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x22, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x21, 0x70);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x23, 0xf8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x24, 0x77);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x25, 0xf8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_GAMMA_CURVE, 0xf8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x2f, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_PARTIAL_ROWS, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_PARTIAL_COLUMNS,
				     0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x32, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x33, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x34, 0x00);
	mipi_dsi_dcs_set_tear_on_multi(&dsi_ctx, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_ADDRESS_MODE, 0x40);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x37, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x38, 0x7f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x39, 0x00);
	mipi_dsi_dcs_set_pixel_format_multi(&dsi_ctx, 0xb6);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x3b, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_3D_CONTROL, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x3f, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_VSYNC_TIMING, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x41, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x42, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xd4);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_VSYNC_TIMING, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xfd);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x80, 0x06);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x83, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xa0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x06, 0x36);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6e, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7c, 0x15);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xd0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x11, 0x75);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x92, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xa1);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3, 0x87);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc4, 0xff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc5, 0x7f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfa, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xd2);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x4f, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x50, 0x11);
	mipi_dsi_dcs_set_display_brightness_multi(&dsi_ctx, 0x00ab);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x52, 0x30);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_CONTROL_DISPLAY,
				     0x09);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x54, 0xb0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_POWER_SAVE, 0x04);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x56, 0x5c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x58, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x59, 0x14);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x5a, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x5b, 0x2e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x5c, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x5d, 0x9a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_CABC_MIN_BRIGHTNESS,
				     0x19);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x5f, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x60, 0xbe);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x61, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x62, 0x0a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x63, 0x0c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x64, 0x05);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x65, 0x0e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x66, 0x05);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x67, 0xfd);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x68, 0x16);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x69, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6a, 0x10);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6b, 0xdc);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6c, 0x07);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6d, 0x10);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6e, 0x20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x70, 0x06);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x71, 0x0f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x72, 0x0f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x73, 0x33);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x74, 0x0e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x75, 0x1c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x76, 0x2a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x77, 0x38);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x78, 0x46);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x79, 0x54);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7a, 0x62);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7b, 0x69);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7c, 0x70);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7d, 0x77);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7e, 0x79);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7f, 0x7b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x80, 0x7d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x81, 0x7e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x82, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x83, 0xc2);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x84, 0x22);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x85, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x86, 0x2a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x87, 0x40);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x88, 0x32);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x89, 0xbe);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8a, 0x3a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8b, 0xfc);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8c, 0x3a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8d, 0xfa);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8e, 0x3a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8f, 0xf8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x90, 0x3b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x91, 0x38);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x92, 0x3b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x93, 0x78);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x94, 0x3b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x95, 0x76);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x96, 0x4b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x97, 0xb6);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x98, 0x4b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x99, 0xf6);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9a, 0x4c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9b, 0x34);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9c, 0x5c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9d, 0x74);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9e, 0x8c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9f, 0xf4);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_READ_PPS_START, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa3, 0xba);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa4, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa5, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa6, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa7, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_READ_PPS_CONTINUE,
				     0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xaa, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa0, 0xa0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x40);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x24, 0x54);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_READ_PPS_CONTINUE,
				     0x14);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xad, 0xc8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa5, 0x20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xac, 0x04);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xae, 0x70);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xaf, 0x4b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x4b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb2, 0x4b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb3, 0x4f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x26);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1d, 0x26);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa4, 0x1f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x40);
	mipi_dsi_dcs_set_pixel_format_multi(&dsi_ctx, 0xe8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x3b, 0xe8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x42);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x81, 0xe8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x82, 0xe8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc2, 0x08);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_ADDRESS_MODE, 0x00);
	mipi_dsi_dcs_set_tear_on_multi(&dsi_ctx, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_CONTROL_DISPLAY,
				     0x20);
	mipi_dsi_dcs_set_display_brightness_multi(&dsi_ctx, 0x0000);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 100);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 20);

	return dsi_ctx.accum_err;
}

static int bf068_rm692h0_6p97_magic_dsc_off(struct bf068_rm692h0_6p97_magic_dsc *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 147);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 20);

	return dsi_ctx.accum_err;
}

static int bf068_rm692h0_6p97_magic_dsc_prepare(struct drm_panel *panel)
{
	struct bf068_rm692h0_6p97_magic_dsc *ctx = to_bf068_rm692h0_6p97_magic_dsc(panel);
	struct device *dev = &ctx->dsi->dev;
	struct drm_dsc_picture_parameter_set pps;
	int ret;

	bf068_rm692h0_6p97_magic_dsc_reset(ctx);

	ret = bf068_rm692h0_6p97_magic_dsc_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		return ret;
	}

	drm_dsc_pps_payload_pack(&pps, &ctx->dsc);

	ret = mipi_dsi_picture_parameter_set(ctx->dsi, &pps);
	if (ret < 0) {
		dev_err(panel->dev, "failed to transmit PPS: %d\n", ret);
		return ret;
	}

	ret = mipi_dsi_compression_mode(ctx->dsi, true);
	if (ret < 0) {
		dev_err(dev, "failed to enable compression mode: %d\n", ret);
		return ret;
	}

	msleep(28); /* TODO: Is this panel-dependent? */

	return 0;
}

static int bf068_rm692h0_6p97_magic_dsc_unprepare(struct drm_panel *panel)
{
	struct bf068_rm692h0_6p97_magic_dsc *ctx = to_bf068_rm692h0_6p97_magic_dsc(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = bf068_rm692h0_6p97_magic_dsc_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);

	return 0;
}

static const struct drm_display_mode bf068_rm692h0_6p97_magic_dsc_mode = {
	.clock = (1116 + 248 + 8 + 336) * (2480 + 56 + 8 + 8) * 60 / 1000,
	.hdisplay = 1116,
	.hsync_start = 1116 + 248,
	.hsync_end = 1116 + 248 + 8,
	.htotal = 1116 + 248 + 8 + 336,
	.vdisplay = 2480,
	.vsync_start = 2480 + 56,
	.vsync_end = 2480 + 56 + 8,
	.vtotal = 2480 + 56 + 8 + 8,
	.width_mm = 71,
	.height_mm = 157,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int bf068_rm692h0_6p97_magic_dsc_get_modes(struct drm_panel *panel,
						  struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &bf068_rm692h0_6p97_magic_dsc_mode);
}

static const struct drm_panel_funcs bf068_rm692h0_6p97_magic_dsc_panel_funcs = {
	.prepare = bf068_rm692h0_6p97_magic_dsc_prepare,
	.unprepare = bf068_rm692h0_6p97_magic_dsc_unprepare,
	.get_modes = bf068_rm692h0_6p97_magic_dsc_get_modes,
};

static int bf068_rm692h0_6p97_magic_dsc_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness_large(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int bf068_rm692h0_6p97_magic_dsc_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness_large(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness;
}

static const struct backlight_ops bf068_rm692h0_6p97_magic_dsc_bl_ops = {
	.update_status = bf068_rm692h0_6p97_magic_dsc_bl_update_status,
	.get_brightness = bf068_rm692h0_6p97_magic_dsc_bl_get_brightness,
};

static struct backlight_device *
bf068_rm692h0_6p97_magic_dsc_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 3515,
		.max_brightness = 3515,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &bf068_rm692h0_6p97_magic_dsc_bl_ops, &props);
}

static int bf068_rm692h0_6p97_magic_dsc_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct bf068_rm692h0_6p97_magic_dsc *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct bf068_rm692h0_6p97_magic_dsc, panel,
				   &bf068_rm692h0_6p97_magic_dsc_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO_BURST |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS | MIPI_DSI_MODE_LPM;

	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = bf068_rm692h0_6p97_magic_dsc_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	/* This panel only supports DSC; unconditionally enable it */
	dsi->dsc = &ctx->dsc;

	ctx->dsc.dsc_version_major = 1;
	ctx->dsc.dsc_version_minor = 1;

	/* TODO: Pass slice_per_pkt = 2 */
	ctx->dsc.slice_height = 20;
	ctx->dsc.slice_width = 558;
	/*
	 * TODO: hdisplay should be read from the selected mode once
	 * it is passed back to drm_panel (in prepare?)
	 */
	WARN_ON(1116 % ctx->dsc.slice_width);
	ctx->dsc.slice_count = 1116 / ctx->dsc.slice_width;
	ctx->dsc.bits_per_component = 10;
	ctx->dsc.bits_per_pixel = 10 << 4; /* 4 fractional bits */
	ctx->dsc.block_pred_enable = true;

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void bf068_rm692h0_6p97_magic_dsc_remove(struct mipi_dsi_device *dsi)
{
	struct bf068_rm692h0_6p97_magic_dsc *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id bf068_rm692h0_6p97_magic_dsc_of_match[] = {
	{ .compatible = "mdss,bf068-rm692h0-6p97-magic-dsc" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, bf068_rm692h0_6p97_magic_dsc_of_match);

static struct mipi_dsi_driver bf068_rm692h0_6p97_magic_dsc_driver = {
	.probe = bf068_rm692h0_6p97_magic_dsc_probe,
	.remove = bf068_rm692h0_6p97_magic_dsc_remove,
	.driver = {
		.name = "panel-bf068-rm692h0-6p97-magic-dsc",
		.of_match_table = bf068_rm692h0_6p97_magic_dsc_of_match,
	},
};
module_mipi_dsi_driver(bf068_rm692h0_6p97_magic_dsc_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for BF068_RM692H0_Full_Screen_MAGIC_DSC_FHD_6P7Inch");
MODULE_LICENSE("GPL");
