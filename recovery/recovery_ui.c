/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <linux/input.h>

#include "recovery_ui.h"
#include "common.h"

char* MENU_HEADERS[] = { "Volume up/down to move highlight;",
                         "power button to select.",
                         "",
                         NULL };

char* MENU_ITEMS[] = { "reboot system now",
                       "wipe data/factory reset",
                       "wipe cache partition",
                       NULL };

int device_recovery_start() {
    return 0;
}

int device_toggle_display(volatile char* key_pressed, int key_code) {
    // hold power and press volume-up
    return key_pressed[0x1a] && key_code == 0x2a;
}

int device_reboot_now(volatile char* key_pressed, int key_code) {
    // Reboot if the power key is pressed five times in a row, with
    // no other keys in between.
    static int presses = 0;
    if (key_code == 0x1a) {   // power button
        ++presses;
        return presses == 5;
    } else {
        presses = 0;
        return 0;
    }
}

int device_handle_key(int key_code, int visible) {
    if (visible) {
        switch (key_code) {
            case KEY_DOWN:
            case KEY_VOLUMEDOWN:
            case 0x3a:   // crespo volume-down
                return HIGHLIGHT_DOWN;

            case KEY_UP:
            case KEY_VOLUMEUP:
            case 0x2a:   // crespo volume-up
                return HIGHLIGHT_UP;

            case KEY_ENTER:
            case 0x1a:   // crespo power
                return SELECT_ITEM;
        }
    }

    return NO_ACTION;
}

int device_perform_action(int which) {
    switch (which) {
        case 0: return ITEM_REBOOT;
        case 1: return ITEM_WIPE_DATA;
        case 2: return ITEM_WIPE_CACHE;
    }
    return NO_ACTION;
}

int device_wipe_data() {
    return 0;
}
