/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 * Copyright (c) 2017 Victor Perez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "endstop_ISR.h"
#include "../../module/endstops.h"
#include "../../../../../../src/common/ArduinoInterrupt.hpp"

// One ISR for all EXT-Interrupts
void endstop_ISR() { endstops.update(); }

static void setup_endstop_interrupts() {
  #if HAS_X_MAX
    attachInterrupt(X_MAX_PIN, endstop_ISR, CHANGE);
  #endif
  #if HAS_X_MIN
    attachInterrupt(X_MIN_PIN, endstop_ISR, CHANGE);
  #endif
  #if HAS_Y_MAX
    attachInterrupt(Y_MAX_PIN, endstop_ISR, CHANGE);
  #endif
  #if HAS_Y_MIN
    attachInterrupt(Y_MIN_PIN, endstop_ISR, CHANGE);
  #endif
  #if HAS_Z_MAX
    attachInterrupt(Z_MAX_PIN, endstop_ISR, CHANGE);
  #endif
  #if HAS_Z_MIN
    attachInterrupt(Z_MIN_PIN, endstop_ISR, CHANGE);
  #endif
  #if HAS_Z2_MAX
    attachInterrupt(Z2_MAX_PIN, endstop_ISR, CHANGE);
  #endif
  #if HAS_Z2_MIN
    attachInterrupt(Z2_MIN_PIN, endstop_ISR, CHANGE);
  #endif
  #if HAS_Z3_MAX
    attachInterrupt(Z3_MAX_PIN, endstop_ISR, CHANGE);
  #endif
  #if HAS_Z3_MIN
    attachInterrupt(Z3_MIN_PIN, endstop_ISR, CHANGE);
  #endif
  #if HAS_Z_MIN_PROBE_PIN
    attachInterrupt(Z_MIN_PROBE_PIN, endstop_ISR, CHANGE);
  #endif
}
