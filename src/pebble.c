/*

RockBed v1.0.0
A suite and methdology for creating Pebble app unit tests.
http://smallstoneapps.github.io/rockbed/

----------------------

The MIT License (MIT)

Copyright © 2014 - 2015 Matthew Tole

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

--------------------

src/pebble.c

*/

#include <pebble.h>
#include "pebble_extra.h"

void app_log(uint8_t log_level, const char *src_filename, int src_line_number, const char *fmt, ...) {

}

uint32_t app_message_inbox_size_maximum(void) {
  return APP_MESSAGE_INBOX_SIZE_MINIMUM;
}

uint32_t app_message_outbox_size_maximum(void) {
  return APP_MESSAGE_OUTBOX_SIZE_MINIMUM;
}

AppMessageResult app_message_open(const uint32_t size_inbound, const uint32_t size_outbound) {
  return APP_MSG_OK;
}

AppMessageInboxReceived app_message_register_inbox_received(AppMessageInboxReceived received_callback) {
  return received_callback;
}

AppMessageInboxDropped app_message_register_inbox_dropped(AppMessageInboxDropped dropped_callback) {
  return dropped_callback;
}

AppMessageOutboxSent app_message_register_outbox_sent(AppMessageOutboxSent sent_callback) {
  return sent_callback;
}

AppMessageOutboxFailed app_message_register_outbox_failed(AppMessageOutboxFailed failed_callback) {
  return failed_callback;
}

AppMessageResult app_message_outbox_begin(DictionaryIterator **iterator) {
  return APP_MSG_OK;
}

AppMessageResult app_message_outbox_send(void) {
  return APP_MSG_OK;
}

Tuple *dict_find(const DictionaryIterator *iter, const uint32_t key) {
  return NULL;
}

DictionaryResult dict_write_cstring(DictionaryIterator *iter, const uint32_t key, const char * const cstring) {
  return DICT_OK;
}

void app_timer_cancel(AppTimer *timer_handle) {

}

AppTimer* app_timer_register(uint32_t timeout_ms, AppTimerCallback callback, void* callback_data) {
  return NULL;
}

GFont fonts_get_system_font(const char *font_key) {
  return NULL;
}

GBitmap* gbitmap_create_with_resource(uint32_t resource_id) {
  return NULL;
}

void gbitmap_destroy(GBitmap* bitmap) {

}

void graphics_context_set_text_color(GContext* ctx, GColor color) {

}

void graphics_draw_bitmap_in_rect(GContext* ctx, const GBitmap *bitmap, GRect rect) {

}

void graphics_draw_text(GContext* ctx, const char* text, GFont const font, const GRect box, const GTextOverflowMode overflow_mode, const GTextAlignment alignment, const GTextLayoutCacheRef layout) {

}

void vibes_enqueue_custom_pattern(VibePattern pattern) {

}

void vibes_long_pulse(void) {

}

void vibes_short_pulse(void) {

}
