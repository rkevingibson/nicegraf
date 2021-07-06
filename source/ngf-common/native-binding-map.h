/**
 * Copyright (c) 2021 nicegraf contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#pragma once

#include "nicegraf.h"
#include "ngf-common/pending-bind-op.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Maps (set, binding) pair to a platform's native binding id. */
typedef struct ngfi_native_binding_map ngfi_native_binding_map;

/* Derives a (set, binding) => (native binding) mapping from a list of
   bind operations. */
ngfi_native_binding_map* ngfi_create_native_binding_map_from_pending_bind_ops(
  const ngfi_pending_bind_op* pending_bind_ops_list);

/* Destroys a native binding map previously created with
   ngfi_create_native_binding_map_... */
void ngfi_destroy_native_binding_map(ngfi_native_binding_map* map);

/* Looks up a native binding from the given map using the provided nicegraf
   set and binding ids. Returns 0xFFFF...FF on failure. */
uint32_t ngfi_native_binding_map_lookup(
  const ngfi_native_binding_map* map, uint32_t set, uint32_t binding);

#ifdef __cplusplus
}
#endif
