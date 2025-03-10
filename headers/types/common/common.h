// Shared types used throughout the game

#ifndef HEADERS_TYPES_COMMON_H_
#define HEADERS_TYPES_COMMON_H_

#include "enums.h"

// This is essentially the standard (32-bit) Unix I/O vector struct.
// It's used for file I/O and represents a buffer of data with a pointer and a length.
struct iovec {
    void* iov_base;
    uint32_t iov_len;
};
ASSERT_SIZE(struct iovec, 8);

// In the move data, the target and range are encoded together in the first byte of a single
// two-byte field. The target is the lower half, and the range is the upper half.
struct move_target_and_range {
    enum move_target : 4;
    enum move_range : 4;
    enum healing_move_type : 4;
    uint16_t unused : 4; // At least I'm pretty sure this is unused...
};
ASSERT_SIZE(struct move_target_and_range, 2);

// Data for a single move
struct move_data {
    uint16_t base_power;                          // 0x0
    enum type_id type : 8;                        // 0x2
    enum move_category category : 8;              // 0x3
    struct move_target_and_range target_range;    // 0x4
    struct move_target_and_range ai_target_range; // 0x6: Target/range as seen by the AI
    uint8_t pp;                                   // 0x8
    uint8_t ai_weight; // 0x9: Possibly. Weight for AI's random move selection
    // 0xA: Both accuracy values are used to calculate the move's actual accuracy.
    // See the PMD Info Spreadsheet.
    uint8_t accuracy1;
    uint8_t accuracy2;            // 0xB
    uint8_t field_0xc;            // unknown
    uint8_t strikes;              // 0xD: Number of times the move hits (i.e. for multi-hit moves)
    uint8_t max_ginseng_boost;    // 0xE: Maximum possible Ginseng boost for this move
    uint8_t crit_chance;          // 0xF: The base critical hit chance
    bool reflected_by_magic_coat; // 0x10
    bool can_be_snatched;         // 0x11
    bool fails_while_muzzled;     // 0x12
    // 0x13: Seems to be used by the AI with Status Checker for using moves against frozen monsters
    bool ai_can_use_against_frozen;
    bool usable_while_taunted; // 0x14
    // 0x15: Index in the string files of the range string to be displayed in the move info screen
    uint8_t range_string_idx;
    enum move_id id : 16; // 0x16
    // 0x18: Index in the string files of the message string to be displayed in the dungeon message
    // log when a move is used. E.g., the default (0) is "[User] used [move]!"
    uint16_t message_string_idx;
};
ASSERT_SIZE(struct move_data, 26);

// The move data table, as contained within /BALANCE/waza_p.bin, and when loaded into memory.
struct move_data_table {
    struct move_data entries[559];
};
ASSERT_SIZE(struct move_data_table, 14534);

// TODO: Add more data file structures, as convenient or needed, especially if the load address
// or pointers to the load address are known.

#endif
