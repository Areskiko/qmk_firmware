// Inspired by https://www.jonashietala.se/blog/2022/09/06/the_current_t-34_keyboard_layout/


#include QMK_KEYBOARD_H

#define _BASE 0
#define _NUMBER 1

#define NUMBER MO(_NUMBER)

enum unicode_names {
    AE_LOWER,
    AE_UPPER,
    OE_LOWER,
    OE_UPPER,
    AA_LOWER,
    AA_UPPER,
};

const uint32_t PROGMEM unicode_map[] = {
    [AE_LOWER] = 0x00E6,
    [AE_UPPER] = 0x00C6,
    [OE_LOWER] = 0x00F8,
    [OE_UPPER] = 0x00D8,
    [AA_LOWER] = 0x00E5,
    [AA_UPPER] = 0x00C5,
};
const uint16_t PROGMEM ae_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM aa_combo[] = {KC_A, KC_I, COMBO_END};

combo_t key_combos[] = {
    COMBO(ae_combo, UP(AE_LOWER, AE_UPPER)),
    COMBO(oe_combo, UP(OE_LOWER, OE_UPPER)),
    COMBO(aa_combo, UP(AA_LOWER, AA_UPPER)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_5x6(
        TG(_NUMBER),    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       /**/  KC_BSLS,       KC_Z,         KC_8,       KC_9,       KC_0,       KC_BSPC,
        KC_TAB,         KC_J,       KC_C,       KC_Y,       KC_F,       KC_P,       /**/  KC_X,       KC_W,         KC_O,       KC_U,       KC_L,       KC_MINS,
        KC_ESC,         KC_R,       KC_S,       KC_T,       KC_H,       KC_K,       /**/  KC_M,       KC_N,         KC_A,       KC_I,       KC_Q,       KC_QUOT,
        OSM(MOD_LSFT),  KC_Z,       KC_V,       KC_G,       KC_D,       KC_B,       /**/  KC_SLSH,    KC_MINS,      KC_COMM,    KC_DOT,     KC_SCLN,    OSM(MOD_LCTL),
                                    KC_LBRC,    KC_RBRC,                            /**/              KC_LPRN,    KC_RPRN,
                                                    KC_ENT,     KC_SPC,             /**/      KC_E,       KC_BSPC,
                                                    KC_HOME,    QK_AREP,            /**/      QK_REP,     KC_RGUI,
                                                    KC_LSFT,    KC_GRV,             /**/      KC_LGUI,    KC_LALT
    ),

    [_NUMBER] = LAYOUT_5x6(
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   /**/  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,     KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   /**/  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,     KC_TRNS,
        KC_TRNS,    KC_0,       KC_1,       KC_2,       KC_3,        KC_4,      /**/  KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   /**/  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,                            /**/              KC_TRNS,    KC_TRNS,
                                                KC_TRNS,    KC_TRNS,            /**/      KC_TRNS,      KC_TRNS,
                                                KC_TRNS,    KC_TRNS,            /**/      KC_TRNS,      KC_TRNS,
                                                KC_TRNS,    KC_TRNS,            /**/      KC_TRNS,      KC_TRNS
    ),

    [2] = LAYOUT_5x6(
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   /**/  KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   /**/  KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   /**/  KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   /**/  KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,                            /**/                        KC_TRNS,    KC_TRNS,
                                                KC_TRNS,    KC_TRNS,            /**/      KC_TRNS,      KC_TRNS,
                                                KC_TRNS,    KC_TRNS,            /**/      KC_TRNS,      KC_TRNS,
                                                KC_TRNS,    KC_TRNS,            /**/      KC_TRNS,      KC_TRNS
    )
};
