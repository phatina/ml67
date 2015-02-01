/*
Copyright 2012,2013 Jon Higgs <jhiggs@eml.cc>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

void shift_esc_is_tilde(bool pressed) {
    if (pressed) {
        if (get_mods() & MOD_LSFT) {
            add_key(KC_GRV);
            send_keyboard_report();
        } else {
            add_key(KC_ESC);
            send_keyboard_report();
        }
    } else {
        // release the keys.
        del_key(KC_GRV);
        del_key(KC_ESC);
        send_keyboard_report();
    }
}
