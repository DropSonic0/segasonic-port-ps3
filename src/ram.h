/**
 *    Name:        ram.h
 *    Description: the game's variables, tables, board registers and structures
 *    Version:     0.1.0
 *    Created:     12-10-2026
 *    Modified:    27-10-2026
 *    Author:      Sebastian Toyos
 *
 *    SegaSonic The Hedgehog (arcade, Sega System 32): the game's V60 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#ifndef SONIC_RAM_H
#define SONIC_RAM_H

#include "game/le.h"

#ifndef _Static_assert
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
/* Built-in in C11 */
#elif defined(__cplusplus) && __cplusplus >= 201103L
#define _Static_assert(cond, msg) static_assert(cond, msg)
#elif defined(_MSC_VER) && _MSC_VER >= 1600
#define _Static_assert(cond, msg) static_assert(cond, msg)
#else
#define SONIC_CONCAT_IMPL(a, b) a##b
#define SONIC_CONCAT(a, b) SONIC_CONCAT_IMPL(a, b)
#define _Static_assert(cond, msg) typedef char SONIC_CONCAT(static_assert_, __LINE__)[(cond) ? 1 : -1]
#endif
#endif

/* the game's variables in work RAM (the original code reaches them from R25, which holds
   GAME_VARIABLES; some code adds offsets it reads from tables) */
#define GAME_VARIABLES 0x208000u
#define object_count_ADDRESS 0x207FE0u
#define object_count RAM16(object_count_ADDRESS)
#define first_object_address_ADDRESS 0x207FE2u
#define first_object_address RAM32(first_object_address_ADDRESS)
#define first_object_link_ADDRESS 0x207FE2u
#define first_object_link RAM16(first_object_link_ADDRESS)
#define last_object_address_ADDRESS 0x207FE6u
#define last_object_address RAM32(last_object_address_ADDRESS)
#define last_object_link_ADDRESS 0x207FE6u
#define last_object_link RAM16(last_object_link_ADDRESS)
#define type_spawn_cursor_ADDRESS 0x208000u
#define type_spawn_cursor ((u32le *)ram(type_spawn_cursor_ADDRESS))
#define type_spawn_stage_ADDRESS 0x208006u
#define type_spawn_stage RAM16(type_spawn_stage_ADDRESS)
#define spawn_count_ADDRESS 0x208008u
#define spawn_count RAM16(spawn_count_ADDRESS)
#define spawn_first_ADDRESS 0x20800Au
#define spawn_first RAM32(spawn_first_ADDRESS)
#define spawn_last_ADDRESS 0x20800Eu
#define spawn_last RAM32(spawn_last_ADDRESS)
#define spawn_last_link_ADDRESS 0x20800Eu
#define spawn_last_link RAM16(spawn_last_link_ADDRESS)
#define deleted_child_ADDRESS 0x208012u
#define deleted_child RAM16(deleted_child_ADDRESS)
#define nearest_player_distance_ADDRESS 0x208016u
#define nearest_player_distance RAM16S(nearest_player_distance_ADDRESS)
#define nearest_player_dx_ADDRESS 0x208018u
#define nearest_player_dx RAM16S(nearest_player_dx_ADDRESS)
#define nearest_player_dy_ADDRESS 0x20801Au
#define nearest_player_dy RAM16S(nearest_player_dy_ADDRESS)
#define direction_to_player_1_ADDRESS 0x20801Cu
#define direction_to_player_1 RAM16(direction_to_player_1_ADDRESS)
#define direction_to_player_2_ADDRESS 0x20801Eu
#define direction_to_player_2 RAM16(direction_to_player_2_ADDRESS)
#define direction_to_player_3_ADDRESS 0x208020u
#define direction_to_player_3 RAM16(direction_to_player_3_ADDRESS)
#define distance_to_player_1_ADDRESS 0x208022u
#define distance_to_player_1 RAM16S(distance_to_player_1_ADDRESS)
#define distance_to_player_2_ADDRESS 0x208024u
#define distance_to_player_2 RAM16S(distance_to_player_2_ADDRESS)
#define distance_to_player_3_ADDRESS 0x208026u
#define distance_to_player_3 RAM16S(distance_to_player_3_ADDRESS)
#define active_player_count_ADDRESS 0x208028u
#define active_player_count RAM8(active_player_count_ADDRESS)
#define nearest_player_ADDRESS 0x208029u
#define nearest_player RAM8(nearest_player_ADDRESS)
#define nearest_player_z_ADDRESS 0x20802Au
#define nearest_player_z RAM16S(nearest_player_z_ADDRESS)
#define nearest_player_floor_z_ADDRESS 0x20802Cu
#define nearest_player_floor_z RAM16S(nearest_player_floor_z_ADDRESS)
#define direction_to_nearest_player_ADDRESS 0x20802Eu
#define direction_to_nearest_player RAM16(direction_to_nearest_player_ADDRESS)
#define released_ring_angle_ADDRESS 0x208030u
#define released_ring_angle RAM16(released_ring_angle_ADDRESS)
#define rings_to_release_ADDRESS 0x208032u
#define rings_to_release RAM16(rings_to_release_ADDRESS)
#define released_ring_flip_ADDRESS 0x208034u
#define released_ring_flip RAM8(released_ring_flip_ADDRESS)
#define released_rings_random_ADDRESS 0x208035u
#define released_rings_random RAM8(released_rings_random_ADDRESS)
#define ranking_done_ADDRESS 0x208036u
#define ranking_done RAM8(ranking_done_ADDRESS)
#define ranking_title_layout_ADDRESS 0x208037u
#define ranking_title_layout RAM8(ranking_title_layout_ADDRESS)
#define escape_alarm_stray_flags_ADDRESS 0x20803Eu
#define escape_alarm_stray_flags RAM32(escape_alarm_stray_flags_ADDRESS)
#define electric_fence_state_ADDRESS 0x208076u
#define electric_fence_state RAM8(electric_fence_state_ADDRESS)
#define unused_type_spawn_byte_ADDRESS 0x208078u
#define unused_type_spawn_byte RAM8(unused_type_spawn_byte_ADDRESS)
#define vines_hold_players_ADDRESS 0x208079u
#define vines_hold_players RAM8(vines_hold_players_ADDRESS)
#define flame_machine_flags_ADDRESS 0x20807Au
#define flame_machine_flags RAM32(flame_machine_flags_ADDRESS)
#define flame_machine_flash_step_ADDRESS 0x20807Eu
#define flame_machine_flash_step RAM8S(flame_machine_flash_step_ADDRESS)
#define tornado_object_ADDRESS 0x20807Fu
#define tornado_object RAM32(tornado_object_ADDRESS)
#define whirlwind_spin_step_ADDRESS 0x20808Bu
#define whirlwind_spin_step RAM16(whirlwind_spin_step_ADDRESS)
#define centipede_command_ADDRESS 0x20808Du
#define centipede_command RAM8(centipede_command_ADDRESS)
#define players_choosing_character_ADDRESS 0x20808Fu
#define players_choosing_character RAM8(players_choosing_character_ADDRESS)
#define characters_taken_ADDRESS 0x208090u
#define characters_taken RAM32(characters_taken_ADDRESS)
#define players_in_join_chooser_ADDRESS 0x208091u
#define players_in_join_chooser RAM32(players_in_join_chooser_ADDRESS)
#define free_character_count_ADDRESS 0x208092u
#define free_character_count RAM8(free_character_count_ADDRESS)
#define character_select_timer_ADDRESS 0x208093u
#define character_select_timer RAM16S(character_select_timer_ADDRESS)
#define ranking_entry_players_ADDRESS 0x208095u
#define ranking_entry_players RAM32(ranking_entry_players_ADDRESS)
#define stage_trigger_bits_ADDRESS 0x208096u
#define stage_trigger_bits RAM32(stage_trigger_bits_ADDRESS)
#define player_1_object_ADDRESS 0x208414u
#define player_1_object RAM16(player_1_object_ADDRESS)
#define player_1_mishap_flag_ADDRESS 0x2084B4u
#define player_1_mishap_flag RAM8(player_1_mishap_flag_ADDRESS)
#define player_1_speed_scale_ADDRESS 0x2084C4u
#define player_1_speed_scale RAM16(player_1_speed_scale_ADDRESS)
#define player_1_sequence_step_ADDRESS 0x2084EAu
#define player_1_sequence_step RAM8(player_1_sequence_step_ADDRESS)
#define player_1_hud_message_shown_ADDRESS 0x208523u
#define player_1_hud_message_shown RAM8(player_1_hud_message_shown_ADDRESS)
#define player_1_stage_rings_ADDRESS 0x20853Cu
#define player_1_stage_rings RAM8(player_1_stage_rings_ADDRESS)
#define player_2_object_ADDRESS 0x208614u
#define player_2_object RAM16(player_2_object_ADDRESS)
#define player_2_mishap_flag_ADDRESS 0x2086B4u
#define player_2_mishap_flag RAM8(player_2_mishap_flag_ADDRESS)
#define player_2_speed_scale_ADDRESS 0x2086C4u
#define player_2_speed_scale RAM16(player_2_speed_scale_ADDRESS)
#define player_2_sequence_step_ADDRESS 0x2086EAu
#define player_2_sequence_step RAM8(player_2_sequence_step_ADDRESS)
#define player_2_hud_message_shown_ADDRESS 0x208723u
#define player_2_hud_message_shown RAM8(player_2_hud_message_shown_ADDRESS)
#define player_2_stage_rings_ADDRESS 0x20873Cu
#define player_2_stage_rings RAM8(player_2_stage_rings_ADDRESS)
#define player_3_object_ADDRESS 0x208814u
#define player_3_object RAM16(player_3_object_ADDRESS)
#define player_3_mishap_flag_ADDRESS 0x2088B4u
#define player_3_mishap_flag RAM8(player_3_mishap_flag_ADDRESS)
#define player_3_speed_scale_ADDRESS 0x2088C4u
#define player_3_speed_scale RAM16(player_3_speed_scale_ADDRESS)
#define player_3_sequence_step_ADDRESS 0x2088EAu
#define player_3_sequence_step RAM8(player_3_sequence_step_ADDRESS)
#define player_3_hud_message_shown_ADDRESS 0x208923u
#define player_3_hud_message_shown RAM8(player_3_hud_message_shown_ADDRESS)
#define player_3_stage_rings_ADDRESS 0x20893Cu
#define player_3_stage_rings RAM8(player_3_stage_rings_ADDRESS)
#define title_scene_built_ADDRESS 0x209000u
#define title_scene_built RAM8(title_scene_built_ADDRESS)
#define title_sonic_step_ADDRESS 0x209001u
#define title_sonic_step RAM8S(title_sonic_step_ADDRESS)
#define screen_sprite_block_address_ADDRESS 0x209002u
#define screen_sprite_block_address RAM32(screen_sprite_block_address_ADDRESS)
#define screen_sprite_block_ADDRESS 0x209002u
#define screen_sprite_block RAM16(screen_sprite_block_ADDRESS)
#define title_step_timer_ADDRESS 0x209004u
#define title_step_timer RAM16S(title_step_timer_ADDRESS)
#define title_timer_ADDRESS 0x209006u
#define title_timer RAM16S(title_timer_ADDRESS)
#define unused_title_word_ADDRESS 0x209008u
#define unused_title_word RAM16(unused_title_word_ADDRESS)
#define title_done_ADDRESS 0x20900Au
#define title_done RAM8(title_done_ADDRESS)
#define unused_title_byte_1_ADDRESS 0x20900Bu
#define unused_title_byte_1 RAM8(unused_title_byte_1_ADDRESS)
#define unused_title_byte_2_ADDRESS 0x209015u
#define unused_title_byte_2 RAM8(unused_title_byte_2_ADDRESS)
#define camera_limits_reached_ADDRESS 0x209023u
#define camera_limits_reached RAM8(camera_limits_reached_ADDRESS)
#define stage_start_section_ADDRESS 0x209024u
#define stage_start_section RAM16(stage_start_section_ADDRESS)
#define scroll_skip_value_index_ADDRESS 0x209026u
#define scroll_skip_value_index RAM8(scroll_skip_value_index_ADDRESS)
#define scroll_skip_next_armed_ADDRESS 0x209027u
#define scroll_skip_next_armed RAM8(scroll_skip_next_armed_ADDRESS)
#define scroll_skip_back_armed_ADDRESS 0x209028u
#define scroll_skip_back_armed RAM8(scroll_skip_back_armed_ADDRESS)
#define scroll_skip_exit_armed_ADDRESS 0x209029u
#define scroll_skip_exit_armed RAM8(scroll_skip_exit_armed_ADDRESS)
#define scroll_skip_call_armed_ADDRESS 0x20902Au
#define scroll_skip_call_armed RAM8(scroll_skip_call_armed_ADDRESS)
#define scroll_skip_open_ADDRESS 0x20902Bu
#define scroll_skip_open RAM8(scroll_skip_open_ADDRESS)
#define scroll_skip_last_point_ADDRESS 0x20902Cu
#define scroll_skip_last_point RAM16S(scroll_skip_last_point_ADDRESS)
#define nearby_floor_blocks_locked_ADDRESS 0x20902Eu
#define nearby_floor_blocks_locked RAM8(nearby_floor_blocks_locked_ADDRESS)
#define camera_velocity_x_ADDRESS 0x20902Fu
#define camera_velocity_x RAM32S(camera_velocity_x_ADDRESS)
#define camera_velocity_y_ADDRESS 0x209033u
#define camera_velocity_y RAM32S(camera_velocity_y_ADDRESS)
#define loaded_tile_sets_ADDRESS 0x20903Bu
#define loaded_tile_sets RAM32(loaded_tile_sets_ADDRESS)
#define loaded_tile_sets_low_ADDRESS 0x20903Bu
#define loaded_tile_sets_low RAM8(loaded_tile_sets_low_ADDRESS)
#define tile_set_slot_ADDRESS 0x20903Fu
#define tile_set_slot RAM16(tile_set_slot_ADDRESS)
#define push_edge_top_ADDRESS 0x209041u
#define push_edge_top RAM16(push_edge_top_ADDRESS)
#define push_edge_bottom_ADDRESS 0x209043u
#define push_edge_bottom RAM16(push_edge_bottom_ADDRESS)
#define push_edge_right_ADDRESS 0x209045u
#define push_edge_right RAM16(push_edge_right_ADDRESS)
#define push_edge_left_ADDRESS 0x209047u
#define push_edge_left RAM16(push_edge_left_ADDRESS)
#define push_edge_case_ADDRESS 0x209049u
#define push_edge_case RAM8(push_edge_case_ADDRESS)
#define players_pushing_edge_ADDRESS 0x20904Au
#define players_pushing_edge RAM8(players_pushing_edge_ADDRESS)
#define players_facing_scroll_ADDRESS 0x20904Bu
#define players_facing_scroll RAM8(players_facing_scroll_ADDRESS)
#define players_in_play_bits_ADDRESS 0x20904Cu
#define players_in_play_bits RAM8(players_in_play_bits_ADDRESS)
#define player_at_trailing_edge_ADDRESS 0x20904Du
#define player_at_trailing_edge RAM8(player_at_trailing_edge_ADDRESS)
#define player_past_leading_edge_ADDRESS 0x20904Eu
#define player_past_leading_edge RAM8(player_past_leading_edge_ADDRESS)
#define tile_sets_in_progress_ADDRESS 0x20904Fu
#define tile_sets_in_progress RAM32(tile_sets_in_progress_ADDRESS)
#define map_stage_09_sound_count_ADDRESS 0x209055u
#define map_stage_09_sound_count RAM8(map_stage_09_sound_count_ADDRESS)
#define input_test_switch_pressed_ADDRESS 0x209056u
#define input_test_switch_pressed RAM8(input_test_switch_pressed_ADDRESS)
#define input_test_switch_released_ADDRESS 0x209059u
#define input_test_switch_released RAM8(input_test_switch_released_ADDRESS)
#define camera_shake_phase_ADDRESS 0x20905Du
#define camera_shake_phase RAM8(camera_shake_phase_ADDRESS)
#define camera_shake_base_y_ADDRESS 0x20905Eu
#define camera_shake_base_y RAM32(camera_shake_base_y_ADDRESS)
#define camera_shake_step_ADDRESS 0x209062u
#define camera_shake_step RAM16(camera_shake_step_ADDRESS)
#define camera_shake_frame_ADDRESS 0x209064u
#define camera_shake_frame RAM8(camera_shake_frame_ADDRESS)
#define camera_shake_frame_pad_ADDRESS 0x209065u
#define camera_shake_frame_pad RAM8(camera_shake_frame_pad_ADDRESS)
#define camera_shake_active_ADDRESS 0x209066u
#define camera_shake_active RAM8(camera_shake_active_ADDRESS)
#define camera_shake_length_ADDRESS 0x209067u
#define camera_shake_length RAM16(camera_shake_length_ADDRESS)
#define camera_shake_wave_ADDRESS 0x209069u
#define camera_shake_wave RAM16(camera_shake_wave_ADDRESS)
#define stage_03_end_started_ADDRESS 0x20906Bu
#define stage_03_end_started RAM8(stage_03_end_started_ADDRESS)
#define stage_03_end_step_ADDRESS 0x20906Cu
#define stage_03_end_step RAM8(stage_03_end_step_ADDRESS)
#define stage_03_end_timer_ADDRESS 0x20906Du
#define stage_03_end_timer RAM8S(stage_03_end_timer_ADDRESS)
#define stage_03_end_frames_ADDRESS 0x20906Eu
#define stage_03_end_frames RAM16(stage_03_end_frames_ADDRESS)
#define unused_view_word_ADDRESS 0x209070u
#define unused_view_word RAM16(unused_view_word_ADDRESS)
#define scroll_ended_ADDRESS 0x209074u
#define scroll_ended RAM8S(scroll_ended_ADDRESS)
#define stage_00_exit_step_ADDRESS 0x209077u
#define stage_00_exit_step RAM8(stage_00_exit_step_ADDRESS)
#define stage_00_exit_delay_ADDRESS 0x209078u
#define stage_00_exit_delay RAM8(stage_00_exit_delay_ADDRESS)
#define stage_00_exit_timer_ADDRESS 0x209079u
#define stage_00_exit_timer RAM16S(stage_00_exit_timer_ADDRESS)
#define stage_00_exit_zoom_ADDRESS 0x20907Bu
#define stage_00_exit_zoom RAM16(stage_00_exit_zoom_ADDRESS)
#define follow_base_speed_list_ADDRESS 0x20907Du
#define follow_base_speed_list RAM32(follow_base_speed_list_ADDRESS)
#define follow_base_speed_ADDRESS 0x209081u
#define follow_base_speed RAM16(follow_base_speed_ADDRESS)
#define sega_logo_step_ADDRESS 0x209083u
#define sega_logo_step RAM8(sega_logo_step_ADDRESS)
#define sega_logo_frame_ADDRESS 0x209084u
#define sega_logo_frame RAM8S(sega_logo_frame_ADDRESS)
#define sega_logo_timer_word_ADDRESS 0x209085u
#define sega_logo_timer_word RAM16(sega_logo_timer_word_ADDRESS)
#define sega_logo_timer_ADDRESS 0x209085u
#define sega_logo_timer RAM8S(sega_logo_timer_ADDRESS)
#define sega_logo_scale_ADDRESS 0x209086u
#define sega_logo_scale RAM16S(sega_logo_scale_ADDRESS)
#define fade_step_ADDRESS 0x209088u
#define fade_step RAM8(fade_step_ADDRESS)
#define fade_kind_ADDRESS 0x209089u
#define fade_kind RAM8S(fade_kind_ADDRESS)
#define fade_delay_ADDRESS 0x20908Au
#define fade_delay RAM16(fade_delay_ADDRESS)
#define stage_05_switch_step_word_ADDRESS 0x20908Cu
#define stage_05_switch_step_word RAM16(stage_05_switch_step_word_ADDRESS)
#define stage_05_switch_step_ADDRESS 0x20908Cu
#define stage_05_switch_step RAM8S(stage_05_switch_step_ADDRESS)
#define fade_delta_ADDRESS 0x20908Du
#define fade_delta RAM16(fade_delta_ADDRESS)
#define stage_06_background_step_ADDRESS 0x20908Fu
#define stage_06_background_step RAM8(stage_06_background_step_ADDRESS)
#define palette_cycle_set_0_frame_ADDRESS 0x20909Cu
#define palette_cycle_set_0_frame RAM8(palette_cycle_set_0_frame_ADDRESS)
#define palette_cycle_set_1_frame_ADDRESS 0x2090ACu
#define palette_cycle_set_1_frame RAM8(palette_cycle_set_1_frame_ADDRESS)
#define palette_cycle_set_ADDRESS 0x2090D0u
#define palette_cycle_set RAM32(palette_cycle_set_ADDRESS)
#define window_wipe_closing_ADDRESS 0x2090D4u
#define window_wipe_closing RAM8(window_wipe_closing_ADDRESS)
#define map_screen_step_ADDRESS 0x2090D5u
#define map_screen_step RAM8(map_screen_step_ADDRESS)
#define window_wipe_left_ADDRESS 0x2090D6u
#define window_wipe_left RAM16(window_wipe_left_ADDRESS)
#define window_wipe_right_ADDRESS 0x2090D8u
#define window_wipe_right RAM16(window_wipe_right_ADDRESS)
#define window_wipe_top_ADDRESS 0x2090DAu
#define window_wipe_top RAM16(window_wipe_top_ADDRESS)
#define window_wipe_bottom_ADDRESS 0x2090DCu
#define window_wipe_bottom RAM16(window_wipe_bottom_ADDRESS)
#define window_wipe_frames_ADDRESS 0x2090DEu
#define window_wipe_frames RAM16(window_wipe_frames_ADDRESS)
#define window_wipe_left_speed_ADDRESS 0x2090E0u
#define window_wipe_left_speed RAM32S(window_wipe_left_speed_ADDRESS)
#define window_wipe_right_speed_ADDRESS 0x2090E4u
#define window_wipe_right_speed RAM32S(window_wipe_right_speed_ADDRESS)
#define window_wipe_top_speed_ADDRESS 0x2090E8u
#define window_wipe_top_speed RAM32S(window_wipe_top_speed_ADDRESS)
#define window_wipe_bottom_speed_ADDRESS 0x2090ECu
#define window_wipe_bottom_speed RAM32S(window_wipe_bottom_speed_ADDRESS)
#define window_wipe_left_edge_ADDRESS 0x2090F0u
#define window_wipe_left_edge RAM32S(window_wipe_left_edge_ADDRESS)
#define window_wipe_left_edge_fraction_ADDRESS 0x2090F0u
#define window_wipe_left_edge_fraction RAM16(window_wipe_left_edge_fraction_ADDRESS)
#define window_wipe_right_edge_ADDRESS 0x2090F4u
#define window_wipe_right_edge RAM32S(window_wipe_right_edge_ADDRESS)
#define window_wipe_right_edge_fraction_ADDRESS 0x2090F4u
#define window_wipe_right_edge_fraction RAM16(window_wipe_right_edge_fraction_ADDRESS)
#define window_wipe_top_edge_ADDRESS 0x2090F8u
#define window_wipe_top_edge RAM32S(window_wipe_top_edge_ADDRESS)
#define window_wipe_top_edge_fraction_ADDRESS 0x2090F8u
#define window_wipe_top_edge_fraction RAM16(window_wipe_top_edge_fraction_ADDRESS)
#define window_wipe_bottom_edge_ADDRESS 0x2090FCu
#define window_wipe_bottom_edge RAM32S(window_wipe_bottom_edge_ADDRESS)
#define window_wipe_bottom_edge_fraction_ADDRESS 0x2090FCu
#define window_wipe_bottom_edge_fraction RAM16(window_wipe_bottom_edge_fraction_ADDRESS)
#define map_stage_icon_ADDRESS 0x209100u
#define map_stage_icon RAM16(map_stage_icon_ADDRESS)
#define bridge_0_load_ADDRESS 0x209400u
#define bridge_0_load RAM8(bridge_0_load_ADDRESS)
#define bridge_0_load_first_ADDRESS 0x209401u
#define bridge_0_load_first RAM8(bridge_0_load_first_ADDRESS)
#define bridge_0_load_last_ADDRESS 0x209402u
#define bridge_0_load_last RAM8(bridge_0_load_last_ADDRESS)
#define bridge_0_sag_ADDRESS 0x209450u
#define bridge_0_sag RAM16(bridge_0_sag_ADDRESS)
#define bridge_1_load_ADDRESS 0x209500u
#define bridge_1_load RAM8(bridge_1_load_ADDRESS)
#define bridge_1_load_first_ADDRESS 0x209501u
#define bridge_1_load_first RAM8(bridge_1_load_first_ADDRESS)
#define bridge_1_load_last_ADDRESS 0x209502u
#define bridge_1_load_last RAM8(bridge_1_load_last_ADDRESS)
#define bridge_1_sag_ADDRESS 0x209550u
#define bridge_1_sag RAM16(bridge_1_sag_ADDRESS)
#define wall_editor_arrow_count_ADDRESS 0x209600u
#define wall_editor_arrow_count RAM16S(wall_editor_arrow_count_ADDRESS)
#define group_slots_ADDRESS 0x209F00u
#define group_slots ((u16le *)ram(group_slots_ADDRESS))
#define nearby_floor_block_count_ADDRESS 0x209F80u
#define nearby_floor_block_count RAM16(nearby_floor_block_count_ADDRESS)
#define nearby_floor_blocks_ADDRESS 0x209F82u
#define nearby_floor_blocks RAM16(nearby_floor_blocks_ADDRESS)
#define banner_sprite_flags_ADDRESS 0x209FC2u
#define banner_sprite_flags RAM16(banner_sprite_flags_ADDRESS)
#define banner_sprite_frame_ADDRESS 0x209FC4u
#define banner_sprite_frame RAM16(banner_sprite_frame_ADDRESS)
#define banner_sprite_palette_ADDRESS 0x209FC6u
#define banner_sprite_palette RAM16(banner_sprite_palette_ADDRESS)
#define banner_sprite_y_ADDRESS 0x209FCCu
#define banner_sprite_y RAM16(banner_sprite_y_ADDRESS)
#define banner_sprite_x_ADDRESS 0x209FCEu
#define banner_sprite_x RAM16(banner_sprite_x_ADDRESS)
#define bitmap_draw_buffer_ADDRESS 0x20B500u
#define bitmap_draw_buffer RAM32(bitmap_draw_buffer_ADDRESS)
#define string_count_ADDRESS 0x20C800u
#define string_count RAM16S(string_count_ADDRESS)
#define string_queue_ADDRESS 0x20C802u
#define string_queue RAM16(string_queue_ADDRESS)
#define palette_cycle_0_ADDRESS 0x20CA00u
#define palette_cycle_0 RAM8(palette_cycle_0_ADDRESS)
#define palette_cycle_0_frames_ADDRESS 0x20CA01u
#define palette_cycle_0_frames RAM8(palette_cycle_0_frames_ADDRESS)
#define palette_cycle_1_ADDRESS 0x20CA05u
#define palette_cycle_1 RAM8(palette_cycle_1_ADDRESS)
#define palette_cycle_1_frames_ADDRESS 0x20CA06u
#define palette_cycle_1_frames RAM8(palette_cycle_1_frames_ADDRESS)
#define circle_wipe_left_ADDRESS 0x20CA13u
#define circle_wipe_left RAM16(circle_wipe_left_ADDRESS)
#define circle_wipe_right_ADDRESS 0x20CA15u
#define circle_wipe_right RAM16(circle_wipe_right_ADDRESS)
#define circle_wipe_line_ADDRESS 0x20CA17u
#define circle_wipe_line RAM16(circle_wipe_line_ADDRESS)
#define unused_circle_wipe_byte_ADDRESS 0x20CA19u
#define unused_circle_wipe_byte RAM8(unused_circle_wipe_byte_ADDRESS)
#define circle_wipe_radius_ADDRESS 0x20CA1Au
#define circle_wipe_radius RAM16S(circle_wipe_radius_ADDRESS)
#define circle_wipe_radius_low_ADDRESS 0x20CA1Au
#define circle_wipe_radius_low RAM8(circle_wipe_radius_low_ADDRESS)
#define test_screen_ADDRESS 0x20CA1Cu
#define test_screen RAM8(test_screen_ADDRESS)
#define test_screen_ready_ADDRESS 0x20CA1Du
#define test_screen_ready RAM8(test_screen_ready_ADDRESS)
#define test_cursor_ADDRESS 0x20CA1Eu
#define test_cursor RAM8(test_cursor_ADDRESS)
#define test_cursor_positions_ADDRESS 0x20CA1Fu
#define test_cursor_positions RAM32(test_cursor_positions_ADDRESS)
#define test_cursor_column_ADDRESS 0x20CA23u
#define test_cursor_column RAM8(test_cursor_column_ADDRESS)
#define test_cursor_row_ADDRESS 0x20CA24u
#define test_cursor_row RAM8(test_cursor_row_ADDRESS)
#define test_cursor_blink_ADDRESS 0x20CA25u
#define test_cursor_blink RAM8S(test_cursor_blink_ADDRESS)
#define test_menu_item_ADDRESS 0x20CA26u
#define test_menu_item RAM8(test_menu_item_ADDRESS)
#define test_continue_mode_ADDRESS 0x20CA27u
#define test_continue_mode RAM8(test_continue_mode_ADDRESS)
#define sound_test_number_ADDRESS 0x20CA28u
#define sound_test_number RAM8(sound_test_number_ADDRESS)
#define crt_test_x_ADDRESS 0x20CA29u
#define crt_test_x RAM16(crt_test_x_ADDRESS)
#define crt_test_y_ADDRESS 0x20CA2Bu
#define crt_test_y RAM16(crt_test_y_ADDRESS)
#define crt_test_color_ADDRESS 0x20CA2Du
#define crt_test_color RAM8(crt_test_color_ADDRESS)
#define debug_sprite_x_ADDRESS 0x20CA36u
#define debug_sprite_x RAM16(debug_sprite_x_ADDRESS)
#define debug_sprite_y_ADDRESS 0x20CA38u
#define debug_sprite_y RAM16(debug_sprite_y_ADDRESS)
#define debug_sprite_spawned_ADDRESS 0x20CA3Au
#define debug_sprite_spawned RAM8(debug_sprite_spawned_ADDRESS)
#define coin_manual_page_ADDRESS 0x20CA3Cu
#define coin_manual_page RAM8(coin_manual_page_ADDRESS)
#define title_ray_mighty_started_ADDRESS 0x20CA40u
#define title_ray_mighty_started RAM8(title_ray_mighty_started_ADDRESS)
#define title_ray_mighty_frame_ADDRESS 0x20CA41u
#define title_ray_mighty_frame RAM8(title_ray_mighty_frame_ADDRESS)
#define title_ray_mighty_delay_ADDRESS 0x20CA42u
#define title_ray_mighty_delay RAM8(title_ray_mighty_delay_ADDRESS)
#define title_ray_mighty_wait_ADDRESS 0x20CA43u
#define title_ray_mighty_wait RAM8(title_ray_mighty_wait_ADDRESS)
#define ending_first_scene_done_ADDRESS 0x20CA44u
#define ending_first_scene_done RAM8(ending_first_scene_done_ADDRESS)
#define ending_scene_step_ADDRESS 0x20CA45u
#define ending_scene_step RAM8(ending_scene_step_ADDRESS)
#define test_settings_changed_ADDRESS 0x20CA46u
#define test_settings_changed RAM8(test_settings_changed_ADDRESS)
#define ring_tally_counted_ADDRESS 0x20CA47u
#define ring_tally_counted RAM8(ring_tally_counted_ADDRESS)
#define ring_tally_percent_ADDRESS 0x20CA49u
#define ring_tally_percent RAM16(ring_tally_percent_ADDRESS)
#define ring_tally_panels_counting_ADDRESS 0x20CA4Bu
#define ring_tally_panels_counting RAM8(ring_tally_panels_counting_ADDRESS)
#define fade_speed_ADDRESS 0x20CA4Du
#define fade_speed RAM8(fade_speed_ADDRESS)
#define stage_results_done_ADDRESS 0x20CA4Eu
#define stage_results_done RAM8(stage_results_done_ADDRESS)
#define backup_clear_timer_ADDRESS 0x20CA4Fu
#define backup_clear_timer RAM8(backup_clear_timer_ADDRESS)
#define memory_test_errors_ADDRESS 0x20CA50u
#define memory_test_errors RAM32(memory_test_errors_ADDRESS)
#define show_eeprom_write_count_ADDRESS 0x20CA51u
#define show_eeprom_write_count RAM8(show_eeprom_write_count_ADDRESS)
#define flood_fill_direction_and_y_ADDRESS 0x20CCDAu
#define flood_fill_direction_and_y RAM16(flood_fill_direction_and_y_ADDRESS)
#define flood_fill_direction_ADDRESS 0x20CCDAu
#define flood_fill_direction RAM8(flood_fill_direction_ADDRESS)
#define flood_fill_y_ADDRESS 0x20CCDBu
#define flood_fill_y RAM8(flood_fill_y_ADDRESS)
#define flood_fill_right_x_ADDRESS 0x20CCDCu
#define flood_fill_right_x RAM16(flood_fill_right_x_ADDRESS)
#define flood_fill_right_address_ADDRESS 0x20CCDEu
#define flood_fill_right_address RAM32(flood_fill_right_address_ADDRESS)
#define flood_fill_left_x_ADDRESS 0x20CCE2u
#define flood_fill_left_x RAM16(flood_fill_left_x_ADDRESS)
#define flood_fill_left_address_ADDRESS 0x20CCE4u
#define flood_fill_left_address RAM32(flood_fill_left_address_ADDRESS)
#define flood_fill_parent_right_x_ADDRESS 0x20CCE8u
#define flood_fill_parent_right_x RAM16(flood_fill_parent_right_x_ADDRESS)
#define flood_fill_parent_right_address_ADDRESS 0x20CCEAu
#define flood_fill_parent_right_address RAM32(flood_fill_parent_right_address_ADDRESS)
#define flood_fill_parent_left_x_ADDRESS 0x20CCEEu
#define flood_fill_parent_left_x RAM16(flood_fill_parent_left_x_ADDRESS)
#define flood_fill_parent_left_address_ADDRESS 0x20CCF0u
#define flood_fill_parent_left_address RAM32(flood_fill_parent_left_address_ADDRESS)
#define flood_fill_push_parent_right_x_ADDRESS 0x20CCF4u
#define flood_fill_push_parent_right_x RAM16(flood_fill_push_parent_right_x_ADDRESS)
#define flood_fill_push_parent_right_address_ADDRESS 0x20CCF6u
#define flood_fill_push_parent_right_address RAM32(flood_fill_push_parent_right_address_ADDRESS)
#define flood_fill_push_parent_left_x_ADDRESS 0x20CCFAu
#define flood_fill_push_parent_left_x RAM16(flood_fill_push_parent_left_x_ADDRESS)
#define flood_fill_push_parent_left_address_ADDRESS 0x20CCFCu
#define flood_fill_push_parent_left_address RAM32(flood_fill_push_parent_left_address_ADDRESS)
#define ranking_ADDRESS 0x20CE00u
#define ranking RAM16(ranking_ADDRESS)
#define centipede_path_ADDRESS 0x20D0EAu
#define centipede_path RAM16(centipede_path_ADDRESS)
#define wall_editor_side_text_ADDRESS 0x20DA43u
#define wall_editor_side_text RAM8(wall_editor_side_text_ADDRESS)
#define tile_block_row_ADDRESS 0x20E400u
#define tile_block_row RAM16(tile_block_row_ADDRESS)
#define tile_block_column_ADDRESS 0x20E402u
#define tile_block_column RAM16(tile_block_column_ADDRESS)
#define view_x_ADDRESS 0x20E404u
#define view_x RAM16S(view_x_ADDRESS)
#define view_y_ADDRESS 0x20E406u
#define view_y RAM16S(view_y_ADDRESS)
#define wanted_tile_sets_ADDRESS 0x20E408u
#define wanted_tile_sets RAM32(wanted_tile_sets_ADDRESS)
#define camera_x_ADDRESS 0x20E40Cu
#define camera_x RAM32S(camera_x_ADDRESS)
#define camera_y_ADDRESS 0x20E410u
#define camera_y RAM32S(camera_y_ADDRESS)
#define section_direction_x_ADDRESS 0x20E414u
#define section_direction_x RAM32S(section_direction_x_ADDRESS)
#define section_direction_y_ADDRESS 0x20E418u
#define section_direction_y RAM32S(section_direction_y_ADDRESS)
#define section_direction_x_list_ADDRESS 0x20E41Cu
#define section_direction_x_list RAM32(section_direction_x_list_ADDRESS)
#define section_direction_y_list_ADDRESS 0x20E420u
#define section_direction_y_list RAM32(section_direction_y_list_ADDRESS)
#define section_limit_x_ADDRESS 0x20E424u
#define section_limit_x RAM16S(section_limit_x_ADDRESS)
#define section_limit_x_list_ADDRESS 0x20E426u
#define section_limit_x_list RAM32(section_limit_x_list_ADDRESS)
#define unused_scroll_offset_ADDRESS 0x20E42Au
#define unused_scroll_offset RAM16S(unused_scroll_offset_ADDRESS)
#define scroll_end_ADDRESS 0x20E42Cu
#define scroll_end RAM16(scroll_end_ADDRESS)
#define unused_scroll_flag_ADDRESS 0x20E42Eu
#define unused_scroll_flag RAM8(unused_scroll_flag_ADDRESS)
#define scroll_speed_ADDRESS 0x20E42Fu
#define scroll_speed RAM16(scroll_speed_ADDRESS)
#define scroll_speed_low_ADDRESS 0x20E42Fu
#define scroll_speed_low RAM8S(scroll_speed_low_ADDRESS)
#define section_speed_list_ADDRESS 0x20E431u
#define section_speed_list RAM32(section_speed_list_ADDRESS)
#define scroll_position_ADDRESS 0x20E435u
#define scroll_position RAM16(scroll_position_ADDRESS)
#define section_limit_y_ADDRESS 0x20E437u
#define section_limit_y RAM16S(section_limit_y_ADDRESS)
#define section_limit_y_list_ADDRESS 0x20E439u
#define section_limit_y_list RAM32(section_limit_y_list_ADDRESS)
#define view_offset_x_ADDRESS 0x20E43Du
#define view_offset_x RAM16(view_offset_x_ADDRESS)
#define view_offset_y_ADDRESS 0x20E43Fu
#define view_offset_y RAM16(view_offset_y_ADDRESS)
#define camera_y_pixels_ADDRESS 0x20E441u
#define camera_y_pixels RAM16(camera_y_pixels_ADDRESS)
#define camera_x_pixels_ADDRESS 0x20E443u
#define camera_x_pixels RAM16(camera_x_pixels_ADDRESS)
#define scroll_mode_timer_ADDRESS 0x20E445u
#define scroll_mode_timer RAM16(scroll_mode_timer_ADDRESS)
#define scroll_mode_script_ADDRESS 0x20E447u
#define scroll_mode_script RAM32(scroll_mode_script_ADDRESS)
#define scroll_mode_ADDRESS 0x20E44Bu
#define scroll_mode RAM16(scroll_mode_ADDRESS)
#define scroll_mode_low_ADDRESS 0x20E44Bu
#define scroll_mode_low RAM8(scroll_mode_low_ADDRESS)
#define scroll_mode_duration_ADDRESS 0x20E44Du
#define scroll_mode_duration RAM16(scroll_mode_duration_ADDRESS)
#define scroll_ramp_speed_ADDRESS 0x20E44Fu
#define scroll_ramp_speed RAM8(scroll_ramp_speed_ADDRESS)
#define scroll_ramp_speed_pad_ADDRESS 0x20E450u
#define scroll_ramp_speed_pad RAM8(scroll_ramp_speed_pad_ADDRESS)
#define nbg3_block_column_ADDRESS 0x20E456u
#define nbg3_block_column RAM16(nbg3_block_column_ADDRESS)
#define nbg3_block_row_ADDRESS 0x20E458u
#define nbg3_block_row RAM16(nbg3_block_row_ADDRESS)
#define camera_origin_x_ADDRESS 0x20E45Au
#define camera_origin_x RAM16(camera_origin_x_ADDRESS)
#define camera_origin_y_ADDRESS 0x20E45Cu
#define camera_origin_y RAM16(camera_origin_y_ADDRESS)
#define section_end_list_ADDRESS 0x20E45Eu
#define section_end_list RAM32(section_end_list_ADDRESS)
#define row_scroll_wave_step_ADDRESS 0x20E486u
#define row_scroll_wave_step RAM16(row_scroll_wave_step_ADDRESS)
#define section_unused_cursor_ADDRESS 0x20E488u
#define section_unused_cursor RAM32(section_unused_cursor_ADDRESS)
#define stage_block_map_width_ADDRESS 0x20E48Cu
#define stage_block_map_width RAM16(stage_block_map_width_ADDRESS)
#define nbg3_block_map_width_ADDRESS 0x20E48Eu
#define nbg3_block_map_width RAM16(nbg3_block_map_width_ADDRESS)
#define scratch_0_ADDRESS 0x20E500u
#define scratch_0 RAM32(scratch_0_ADDRESS)
#define scratch_1_ADDRESS 0x20E504u
#define scratch_1 RAM16(scratch_1_ADDRESS)
#define scratch_2_ADDRESS 0x20E506u
#define scratch_2 RAM16(scratch_2_ADDRESS)
#define scratch_3_ADDRESS 0x20E508u
#define scratch_3 RAM32(scratch_3_ADDRESS)
#define scratch_4_ADDRESS 0x20E50Cu
#define scratch_4 RAM16(scratch_4_ADDRESS)
#define camera_ground_speed_ADDRESS 0x20E510u
#define camera_ground_speed RAM32(camera_ground_speed_ADDRESS)
#define camera_ground_speed_int_ADDRESS 0x20E512u
#define camera_ground_speed_int RAM16(camera_ground_speed_int_ADDRESS)
#define camera_map_direction_ADDRESS 0x20E514u
#define camera_map_direction RAM16(camera_map_direction_ADDRESS)
#define camera_ground_speed_vx_ADDRESS 0x20E516u
#define camera_ground_speed_vx RAM32(camera_ground_speed_vx_ADDRESS)
#define camera_ground_speed_vy_ADDRESS 0x20E51Au
#define camera_ground_speed_vy RAM32(camera_ground_speed_vy_ADDRESS)
#define camera_ground_direction_ADDRESS 0x20E51Eu
#define camera_ground_direction RAM16(camera_ground_direction_ADDRESS)
#define stage_link_from_block_ADDRESS 0x20E520u
#define stage_link_from_block RAM16(stage_link_from_block_ADDRESS)
#define stage_link_from_x_ADDRESS 0x20E522u
#define stage_link_from_x RAM32S(stage_link_from_x_ADDRESS)
#define stage_link_from_y_ADDRESS 0x20E526u
#define stage_link_from_y RAM32S(stage_link_from_y_ADDRESS)
#define stage_link_from_height_ADDRESS 0x20E52Au
#define stage_link_from_height RAM16(stage_link_from_height_ADDRESS)
#define stage_link_to_block_ADDRESS 0x20E52Cu
#define stage_link_to_block RAM16(stage_link_to_block_ADDRESS)
#define stage_link_to_x_ADDRESS 0x20E52Eu
#define stage_link_to_x RAM32S(stage_link_to_x_ADDRESS)
#define stage_link_to_y_ADDRESS 0x20E532u
#define stage_link_to_y RAM32S(stage_link_to_y_ADDRESS)
#define stage_link_to_height_ADDRESS 0x20E536u
#define stage_link_to_height RAM16(stage_link_to_height_ADDRESS)
#define next_stage_slot_request_ADDRESS 0x20E538u
#define next_stage_slot_request RAM8(next_stage_slot_request_ADDRESS)
#define group_depth_step_ADDRESS 0x20E539u
#define group_depth_step RAM8S(group_depth_step_ADDRESS)
#define bridge_1_plank_count_ADDRESS 0x20E542u
#define bridge_1_plank_count RAM16(bridge_1_plank_count_ADDRESS)
#define unused_group_spawn_word_ADDRESS 0x20E544u
#define unused_group_spawn_word RAM16(unused_group_spawn_word_ADDRESS)
#define chaser_speed_ADDRESS 0x20E556u
#define chaser_speed RAM16S(chaser_speed_ADDRESS)
#define group_spawn_cursor_ADDRESS 0x20E55Cu
#define group_spawn_cursor RAM32(group_spawn_cursor_ADDRESS)
#define group_leaders_ADDRESS 0x20E562u
#define group_leaders ((u16le *)ram(group_leaders_ADDRESS))
#define group_leader_1_ADDRESS 0x20E564u
#define group_leader_1 RAM16(group_leader_1_ADDRESS)
#define current_icicle_dropper_ADDRESS 0x20E566u
#define current_icicle_dropper RAM16(current_icicle_dropper_ADDRESS)
#define camera_slope_speed_vx_ADDRESS 0x20E56Au
#define camera_slope_speed_vx RAM32(camera_slope_speed_vx_ADDRESS)
#define camera_slope_speed_vy_ADDRESS 0x20E56Eu
#define camera_slope_speed_vy RAM32(camera_slope_speed_vy_ADDRESS)
#define camera_slope_speed_ADDRESS 0x20E572u
#define camera_slope_speed RAM32(camera_slope_speed_ADDRESS)
#define camera_slope_speed_int_ADDRESS 0x20E574u
#define camera_slope_speed_int RAM16(camera_slope_speed_int_ADDRESS)
#define camera_slope_direction_ADDRESS 0x20E576u
#define camera_slope_direction RAM16(camera_slope_direction_ADDRESS)
#define unused_camera_speed_word_ADDRESS 0x20E57Au
#define unused_camera_speed_word RAM16(unused_camera_speed_word_ADDRESS)
#define player_status_ADDRESS 0x20E590u
#define player_status ((uint8_t *)ram(player_status_ADDRESS))
#define player_2_status_ADDRESS 0x20E591u
#define player_2_status RAM8(player_2_status_ADDRESS)
#define player_3_status_ADDRESS 0x20E592u
#define player_3_status RAM8(player_3_status_ADDRESS)
#define player_status_spare_ADDRESS 0x20E593u
#define player_status_spare RAM8(player_status_spare_ADDRESS)
#define saved_scroll_mode_ADDRESS 0x20E594u
#define saved_scroll_mode RAM16(saved_scroll_mode_ADDRESS)
#define player_dropping_in_ADDRESS 0x20E596u
#define player_dropping_in RAM8(player_dropping_in_ADDRESS)
#define player_dropping_in_before_ADDRESS 0x20E597u
#define player_dropping_in_before RAM8(player_dropping_in_before_ADDRESS)
#define skip_player_summary_ADDRESS 0x20E598u
#define skip_player_summary RAM8(skip_player_summary_ADDRESS)
#define no_player_in_play_ADDRESS 0x20E599u
#define no_player_in_play RAM8(no_player_in_play_ADDRESS)
#define grey_screen_active_ADDRESS 0x20E59Au
#define grey_screen_active RAM8(grey_screen_active_ADDRESS)
#define grey_screen_ended_ADDRESS 0x20E59Bu
#define grey_screen_ended RAM8(grey_screen_ended_ADDRESS)
#define camera_scroll_direction_ADDRESS 0x20E5A0u
#define camera_scroll_direction RAM16(camera_scroll_direction_ADDRESS)
#define all_players_path_request_ADDRESS 0x20E5A2u
#define all_players_path_request RAM8(all_players_path_request_ADDRESS)
#define player_mishap_ADDRESS 0x20E5A3u
#define player_mishap RAM8(player_mishap_ADDRESS)
#define bridge_0_last_plank_ADDRESS 0x20E5A4u
#define bridge_0_last_plank RAM16(bridge_0_last_plank_ADDRESS)
#define bridge_1_last_plank_ADDRESS 0x20E5A6u
#define bridge_1_last_plank RAM16(bridge_1_last_plank_ADDRESS)
#define group_takes_slot_ADDRESS 0x20E5A8u
#define group_takes_slot RAM8(group_takes_slot_ADDRESS)
#define current_game_mode_word_ADDRESS 0x20E5A9u
#define current_game_mode_word RAM16(current_game_mode_word_ADDRESS)
#define current_game_mode_ADDRESS 0x20E5A9u
#define current_game_mode RAM8(current_game_mode_ADDRESS)
#define group_slot_index_ADDRESS 0x20E5AAu
#define group_slot_index RAM16(group_slot_index_ADDRESS)
#define stage_00_geyser_ADDRESS 0x20E5ACu
#define stage_00_geyser RAM16(stage_00_geyser_ADDRESS)
#define game_mode_timer_ADDRESS 0x20E5AEu
#define game_mode_timer RAM16S(game_mode_timer_ADDRESS)
#define continue_second_frames_ADDRESS 0x20E5AEu
#define continue_second_frames RAM8S(continue_second_frames_ADDRESS)
#define continue_count_ADDRESS 0x20E5AFu
#define continue_count RAM8(continue_count_ADDRESS)
#define saved_game_mode_ADDRESS 0x20E5B0u
#define saved_game_mode RAM8(saved_game_mode_ADDRESS)
#define unused_summary_byte_ADDRESS 0x20E5B1u
#define unused_summary_byte RAM8(unused_summary_byte_ADDRESS)
#define event_0f_message_cursor_ADDRESS 0x20E5B2u
#define event_0f_message_cursor RAM32(event_0f_message_cursor_ADDRESS)
#define unused_stage_05_event_long_ADDRESS 0x20E5BAu
#define unused_stage_05_event_long RAM32(unused_stage_05_event_long_ADDRESS)
#define opening_machine_object_ADDRESS 0x20E5BEu
#define opening_machine_object RAM16(opening_machine_object_ADDRESS)
#define stage_06_lightning_cursor_ADDRESS 0x20E5C0u
#define stage_06_lightning_cursor RAM32(stage_06_lightning_cursor_ADDRESS)
#define cleared_stages_ADDRESS 0x20E5C4u
#define cleared_stages RAM16(cleared_stages_ADDRESS)
#define stage_06_shake_ADDRESS 0x20E5C6u
#define stage_06_shake RAM16(stage_06_shake_ADDRESS)
#define stage_06_shake_pixels_ADDRESS 0x20E5C7u
#define stage_06_shake_pixels RAM8(stage_06_shake_pixels_ADDRESS)
#define stage_06_shake_sign_ADDRESS 0x20E5C8u
#define stage_06_shake_sign RAM8S(stage_06_shake_sign_ADDRESS)
#define cage_bar_hit_ADDRESS 0x20E5C9u
#define cage_bar_hit RAM8(cage_bar_hit_ADDRESS)
#define spiked_press_object_ADDRESS 0x20E5CAu
#define spiked_press_object RAM16(spiked_press_object_ADDRESS)
#define propped_board_object_ADDRESS 0x20E5CCu
#define propped_board_object RAM16(propped_board_object_ADDRESS)
#define demo_input_ADDRESS 0x20E5CEu
#define demo_input RAM32(demo_input_ADDRESS)
#define unused_title_byte_3_ADDRESS 0x20E5D2u
#define unused_title_byte_3 RAM8(unused_title_byte_3_ADDRESS)
#define current_screen_ADDRESS 0x20E5D3u
#define current_screen RAM8(current_screen_ADDRESS)
#define chaser_object_ADDRESS 0x20E5D4u
#define chaser_object RAM16(chaser_object_ADDRESS)
#define rising_fire_object_ADDRESS 0x20E5D6u
#define rising_fire_object RAM16(rising_fire_object_ADDRESS)
#define fire_vent_cursor_ADDRESS 0x20E5D8u
#define fire_vent_cursor RAM32(fire_vent_cursor_ADDRESS)
#define lava_columns_ADDRESS 0x20E5DCu
#define lava_columns ((u16le *)ram(lava_columns_ADDRESS))
#define players_finished_ADDRESS 0x20E5E0u
#define players_finished ((uint8_t *)ram(players_finished_ADDRESS))
#define goal_unlocked_ADDRESS 0x20E5E3u
#define goal_unlocked RAM8(goal_unlocked_ADDRESS)
#define goal_scroll_position_ADDRESS 0x20E5E4u
#define goal_scroll_position RAM16(goal_scroll_position_ADDRESS)
#define goal_direction_ADDRESS 0x20E5E6u
#define goal_direction RAM16(goal_direction_ADDRESS)
#define goal_line_ADDRESS 0x20E5E8u
#define goal_line RAM16S(goal_line_ADDRESS)
#define unused_stage_byte_ADDRESS 0x20E5EAu
#define unused_stage_byte RAM8(unused_stage_byte_ADDRESS)
#define roller_ram_count_ADDRESS 0x20E5EBu
#define roller_ram_count RAM8(roller_ram_count_ADDRESS)
#define machine_wrecked_ADDRESS 0x20E5ECu
#define machine_wrecked RAM8(machine_wrecked_ADDRESS)
#define map_screen_active_ADDRESS 0x20E5EDu
#define map_screen_active RAM8(map_screen_active_ADDRESS)
#define stage_03_floor_block_falls_ADDRESS 0x20E5EEu
#define stage_03_floor_block_falls ((uint8_t *)ram(stage_03_floor_block_falls_ADDRESS))
#define stage_03_floor_block_falls_1_ADDRESS 0x20E5EFu
#define stage_03_floor_block_falls_1 RAM8(stage_03_floor_block_falls_1_ADDRESS)
#define zone_list_ADDRESS 0x20E5F0u
#define zone_list RAM16(zone_list_ADDRESS)
#define per_player_view_mode_ADDRESS 0x20E5F2u
#define per_player_view_mode RAM8(per_player_view_mode_ADDRESS)
#define roller_ram_hit_ADDRESS 0x20E5F3u
#define roller_ram_hit RAM8(roller_ram_hit_ADDRESS)
#define sign_stop_flag_ADDRESS 0x20E5F4u
#define sign_stop_flag RAM8(sign_stop_flag_ADDRESS)
#define players_pulled_word_ADDRESS 0x20E5F5u
#define players_pulled_word RAM16(players_pulled_word_ADDRESS)
#define players_pulled_ADDRESS 0x20E5F5u
#define players_pulled RAM8(players_pulled_ADDRESS)
#define moving_floor_object_ADDRESS 0x20E5F6u
#define moving_floor_object RAM16(moving_floor_object_ADDRESS)
#define camera_slope_factor_ADDRESS 0x20E5F8u
#define camera_slope_factor RAM16(camera_slope_factor_ADDRESS)
#define scroll_drift_block_ADDRESS 0x20E5FAu
#define scroll_drift_block RAM32(scroll_drift_block_ADDRESS)
#define scroll_drift_vx_ADDRESS 0x20E5FEu
#define scroll_drift_vx RAM32(scroll_drift_vx_ADDRESS)
#define scroll_drift_vy_ADDRESS 0x20E602u
#define scroll_drift_vy RAM32(scroll_drift_vy_ADDRESS)
#define scroll_drift_speed_ADDRESS 0x20E606u
#define scroll_drift_speed RAM32(scroll_drift_speed_ADDRESS)
#define scroll_drift_direction_ADDRESS 0x20E60Au
#define scroll_drift_direction RAM16(scroll_drift_direction_ADDRESS)
#define handle_rod_drop_players_ADDRESS 0x20E60Cu
#define handle_rod_drop_players RAM8(handle_rod_drop_players_ADDRESS)
#define stage_exit_started_ADDRESS 0x20E60Du
#define stage_exit_started RAM8(stage_exit_started_ADDRESS)
#define biting_head_ADDRESS 0x20E60Eu
#define biting_head RAM16(biting_head_ADDRESS)
#define unused_player_flags_ADDRESS 0x20E612u
#define unused_player_flags ((uint8_t *)ram(unused_player_flags_ADDRESS))
#define scroll_resume_request_ADDRESS 0x20E616u
#define scroll_resume_request RAM8(scroll_resume_request_ADDRESS)
#define demo_prompt_shown_ADDRESS 0x20E617u
#define demo_prompt_shown RAM8(demo_prompt_shown_ADDRESS)
#define joining_closed_ADDRESS 0x20E618u
#define joining_closed RAM8(joining_closed_ADDRESS)
#define event_0d_active_ADDRESS 0x20E619u
#define event_0d_active RAM8(event_0d_active_ADDRESS)
#define players_frozen_ADDRESS 0x20E61Au
#define players_frozen RAM8(players_frozen_ADDRESS)
#define banner_break_ADDRESS 0x20E61Bu
#define banner_break RAM8(banner_break_ADDRESS)
#define stage_name_shown_ADDRESS 0x20E61Cu
#define stage_name_shown RAM8(stage_name_shown_ADDRESS)
#define cleared_shown_ADDRESS 0x20E61Du
#define cleared_shown RAM8(cleared_shown_ADDRESS)
#define stage_clear_timer_ADDRESS 0x20E61Eu
#define stage_clear_timer RAM16(stage_clear_timer_ADDRESS)
#define bridge_swing_angle_ADDRESS 0x20E620u
#define bridge_swing_angle RAM32S(bridge_swing_angle_ADDRESS)
#define bridge_swing_speed_ADDRESS 0x20E624u
#define bridge_swing_speed RAM32S(bridge_swing_speed_ADDRESS)
#define bridge_swing_speed_int_ADDRESS 0x20E626u
#define bridge_swing_speed_int RAM16S(bridge_swing_speed_int_ADDRESS)
#define bridge_head_angle_ADDRESS 0x20E628u
#define bridge_head_angle RAM16(bridge_head_angle_ADDRESS)
#define rope_bridge_collapsing_ADDRESS 0x20E62Cu
#define rope_bridge_collapsing RAM8(rope_bridge_collapsing_ADDRESS)
#define barred_gate_closing_ADDRESS 0x20E62Du
#define barred_gate_closing RAM8(barred_gate_closing_ADDRESS)
#define scene_object_ADDRESS 0x20E62Eu
#define scene_object RAM16(scene_object_ADDRESS)
#define rising_saws_ADDRESS 0x20E632u
#define rising_saws ((u16le *)ram(rising_saws_ADDRESS))
#define rising_saw_1_ADDRESS 0x20E634u
#define rising_saw_1 RAM16(rising_saw_1_ADDRESS)
#define rising_saw_2_ADDRESS 0x20E636u
#define rising_saw_2 RAM16(rising_saw_2_ADDRESS)
#define lead_burning_boulder_ADDRESS 0x20E638u
#define lead_burning_boulder RAM16(lead_burning_boulder_ADDRESS)
#define seesaw_launched_ADDRESS 0x20E63Au
#define seesaw_launched RAM8(seesaw_launched_ADDRESS)
#define burning_boulder_released_ADDRESS 0x20E63Bu
#define burning_boulder_released RAM8(burning_boulder_released_ADDRESS)
#define event_1a_scroll_mode_ADDRESS 0x20E63Cu
#define event_1a_scroll_mode RAM16(event_1a_scroll_mode_ADDRESS)
#define event_1a_scroll_speed_ADDRESS 0x20E63Eu
#define event_1a_scroll_speed RAM16(event_1a_scroll_speed_ADDRESS)
#define player_carriers_ADDRESS 0x20E640u
#define player_carriers ((u16le *)ram(player_carriers_ADDRESS))
#define intro_character_ADDRESS 0x20E646u
#define intro_character RAM8S(intro_character_ADDRESS)
#define event_1c_riding_ADDRESS 0x20E647u
#define event_1c_riding RAM8(event_1c_riding_ADDRESS)
#define metal_platform_lifted_ADDRESS 0x20E648u
#define metal_platform_lifted RAM8(metal_platform_lifted_ADDRESS)
#define event_1c_ride_phase_ADDRESS 0x20E649u
#define event_1c_ride_phase RAM8(event_1c_ride_phase_ADDRESS)
#define goal_line_min_ADDRESS 0x20E64Au
#define goal_line_min RAM16S(goal_line_min_ADDRESS)
#define goal_line_max_ADDRESS 0x20E64Cu
#define goal_line_max RAM16S(goal_line_max_ADDRESS)
#define biting_head_done_ADDRESS 0x20E64Eu
#define biting_head_done RAM8(biting_head_done_ADDRESS)
#define ending_finished_ADDRESS 0x20E64Fu
#define ending_finished RAM8(ending_finished_ADDRESS)
#define event_12_fast_scroll_ADDRESS 0x20E650u
#define event_12_fast_scroll RAM8(event_12_fast_scroll_ADDRESS)
#define icicle_dropper_ready_ADDRESS 0x20E651u
#define icicle_dropper_ready RAM8(icicle_dropper_ready_ADDRESS)
#define group_leader_0_held_ADDRESS 0x20E652u
#define group_leader_0_held RAM8(group_leader_0_held_ADDRESS)
#define sand_block_leader_active_ADDRESS 0x20E653u
#define sand_block_leader_active RAM8(sand_block_leader_active_ADDRESS)
#define group_leaders_1_3_held_ADDRESS 0x20E654u
#define group_leaders_1_3_held RAM8(group_leaders_1_3_held_ADDRESS)
#define chaser_stopped_ADDRESS 0x20E655u
#define chaser_stopped RAM8(chaser_stopped_ADDRESS)
#define sliding_door_opened_ADDRESS 0x20E656u
#define sliding_door_opened RAM8(sliding_door_opened_ADDRESS)
#define escape_countdown_frames_ADDRESS 0x20E657u
#define escape_countdown_frames RAM8S(escape_countdown_frames_ADDRESS)
#define escape_seconds_ADDRESS 0x20E658u
#define escape_seconds RAM8(escape_seconds_ADDRESS)
#define escape_started_ADDRESS 0x20E659u
#define escape_started RAM8(escape_started_ADDRESS)
#define escape_tens_digit_ADDRESS 0x20E65Au
#define escape_tens_digit RAM16(escape_tens_digit_ADDRESS)
#define escape_units_digit_ADDRESS 0x20E65Cu
#define escape_units_digit RAM16(escape_units_digit_ADDRESS)
#define you_failed_fade_red_ADDRESS 0x20E65Eu
#define you_failed_fade_red RAM16(you_failed_fade_red_ADDRESS)
#define you_failed_fade_green_ADDRESS 0x20E660u
#define you_failed_fade_green RAM16(you_failed_fade_green_ADDRESS)
#define you_failed_fade_blue_ADDRESS 0x20E662u
#define you_failed_fade_blue RAM16(you_failed_fade_blue_ADDRESS)
#define you_failed_done_ADDRESS 0x20E664u
#define you_failed_done RAM8(you_failed_done_ADDRESS)
#define unused_escape_byte_ADDRESS 0x20E665u
#define unused_escape_byte RAM8(unused_escape_byte_ADDRESS)
#define escape_alarm_timer_ADDRESS 0x20E666u
#define escape_alarm_timer RAM16(escape_alarm_timer_ADDRESS)
#define stage_b_sound_done_ADDRESS 0x20E668u
#define stage_b_sound_done RAM8(stage_b_sound_done_ADDRESS)
#define health_setting_ADDRESS 0x20E669u
#define health_setting RAM8(health_setting_ADDRESS)
#define starting_health_ADDRESS 0x20E66Au
#define starting_health RAM8(starting_health_ADDRESS)
#define players_in_play_ADDRESS 0x20E66Bu
#define players_in_play RAM8S(players_in_play_ADDRESS)
#define geyser_front_start_ADDRESS 0x20E66Cu
#define geyser_front_start RAM8(geyser_front_start_ADDRESS)
#define escape_countdown_running_ADDRESS 0x20E66Du
#define escape_countdown_running RAM8(escape_countdown_running_ADDRESS)
#define caged_character_ADDRESS 0x20E66Eu
#define caged_character RAM8(caged_character_ADDRESS)
#define machine_fire_done_ADDRESS 0x20E66Fu
#define machine_fire_done RAM8(machine_fire_done_ADDRESS)
#define roller_back_zone_index_ADDRESS 0x20E670u
#define roller_back_zone_index RAM16(roller_back_zone_index_ADDRESS)
#define burning_boulder_release_timer_ADDRESS 0x20E672u
#define burning_boulder_release_timer RAM16S(burning_boulder_release_timer_ADDRESS)
#define free_object_stack_ADDRESS 0x20E900u
#define free_object_stack RAM16S(free_object_stack_ADDRESS)
#define free_object_stack_2_ADDRESS 0x20EA10u
#define free_object_stack_2 ((s16le *)ram(free_object_stack_2_ADDRESS))
#define sound_queue_read_ADDRESS 0x20ED80u
#define sound_queue_read RAM8(sound_queue_read_ADDRESS)
#define sound_queue_write_ADDRESS 0x20ED81u
#define sound_queue_write RAM8(sound_queue_write_ADDRESS)
#define sound_queue_ADDRESS 0x20ED82u
#define sound_queue ((uint8_t *)ram(sound_queue_ADDRESS))
#define vblank_copy_count_ADDRESS 0x20EE00u
#define vblank_copy_count RAM16(vblank_copy_count_ADDRESS)
#define vblank_copies_ADDRESS 0x20EE02u
#define vblank_copies RAM32(vblank_copies_ADDRESS)
#define frames_to_wait_ADDRESS 0x20F000u
#define frames_to_wait RAM8S(frames_to_wait_ADDRESS)
#define frames_per_wait_ADDRESS 0x20F001u
#define frames_per_wait RAM8(frames_per_wait_ADDRESS)
#define debug_pause_ADDRESS 0x20F002u
#define debug_pause RAM8(debug_pause_ADDRESS)
#define unused_frame_byte_ADDRESS 0x20F003u
#define unused_frame_byte RAM8(unused_frame_byte_ADDRESS)
#define test_mode_ADDRESS 0x20F004u
#define test_mode RAM8(test_mode_ADDRESS)
#define vblank_copies_pending_ADDRESS 0x20F005u
#define vblank_copies_pending RAM8(vblank_copies_pending_ADDRESS)
#define system_mode_and_step_ADDRESS 0x20F006u
#define system_mode_and_step RAM16(system_mode_and_step_ADDRESS)
#define system_mode_step_ADDRESS 0x20F006u
#define system_mode_step RAM8(system_mode_step_ADDRESS)
#define system_mode_ADDRESS 0x20F007u
#define system_mode RAM8(system_mode_ADDRESS)
#define sprite_list_ready_ADDRESS 0x20F008u
#define sprite_list_ready RAM8(sprite_list_ready_ADDRESS)
#define screen_mode_ADDRESS 0x20F009u
#define screen_mode RAM8(screen_mode_ADDRESS)
#define game_in_progress_ADDRESS 0x20F00Au
#define game_in_progress RAM8(game_in_progress_ADDRESS)
#define unused_system_byte_ADDRESS 0x20F00Bu
#define unused_system_byte RAM8(unused_system_byte_ADDRESS)
#define service_inputs_ADDRESS 0x20F010u
#define service_inputs RAM16(service_inputs_ADDRESS)
#define service_inputs_previous_ADDRESS 0x20F012u
#define service_inputs_previous RAM16(service_inputs_previous_ADDRESS)
#define service_inputs_pressed_ADDRESS 0x20F014u
#define service_inputs_pressed RAM16(service_inputs_pressed_ADDRESS)
#define service_inputs_released_ADDRESS 0x20F016u
#define service_inputs_released RAM16(service_inputs_released_ADDRESS)
#define input_ports_ADDRESS 0x20F018u
#define input_ports RAM32(input_ports_ADDRESS)
#define input_ports_active_ADDRESS 0x20F01Cu
#define input_ports_active RAM32(input_ports_active_ADDRESS)
#define inputs_pressed_ADDRESS 0x20F020u
#define inputs_pressed RAM32(inputs_pressed_ADDRESS)
#define inputs_released_ADDRESS 0x20F024u
#define inputs_released RAM32(inputs_released_ADDRESS)
#define timer_0_ticks_ADDRESS 0x20F030u
#define timer_0_ticks RAM32(timer_0_ticks_ADDRESS)
#define timer_1_ticks_ADDRESS 0x20F034u
#define timer_1_ticks RAM32(timer_1_ticks_ADDRESS)
#define frame_counter_long_ADDRESS 0x20F038u
#define frame_counter_long RAM32(frame_counter_long_ADDRESS)
#define frame_counter_ADDRESS 0x20F038u
#define frame_counter RAM8(frame_counter_ADDRESS)
#define display_off_frames_ADDRESS 0x20F039u
#define display_off_frames RAM8(display_off_frames_ADDRESS)
#define credit_text_position_ADDRESS 0x20F03Eu
#define credit_text_position RAM32(credit_text_position_ADDRESS)
#define vblank_counter_ADDRESS 0x20F042u
#define vblank_counter RAM16(vblank_counter_ADDRESS)
#define attract_timer_ADDRESS 0x20F044u
#define attract_timer RAM16S(attract_timer_ADDRESS)
#define power_time_save_divider_ADDRESS 0x20F046u
#define power_time_save_divider RAM8(power_time_save_divider_ADDRESS)
#define power_on_time_ADDRESS 0x20F048u
#define power_on_time RAM32(power_on_time_ADDRESS)
#define power_on_frames_ADDRESS 0x20F048u
#define power_on_frames RAM16(power_on_frames_ADDRESS)
#define power_on_frames_high_ADDRESS 0x20F04Au
#define power_on_frames_high RAM32(power_on_frames_high_ADDRESS)
#define power_on_frames_top_ADDRESS 0x20F04Cu
#define power_on_frames_top RAM16(power_on_frames_top_ADDRESS)
#define game_frames_ADDRESS 0x20F050u
#define game_frames RAM32(game_frames_ADDRESS)
#define attract_step_ADDRESS 0x20F060u
#define attract_step RAM8(attract_step_ADDRESS)
#define game_mode_word_ADDRESS 0x20F061u
#define game_mode_word RAM16(game_mode_word_ADDRESS)
#define game_mode_ADDRESS 0x20F061u
#define game_mode RAM8(game_mode_ADDRESS)
#define trackball_1_x_ADDRESS 0x20F062u
#define trackball_1_x RAM16S(trackball_1_x_ADDRESS)
#define trackball_1_y_ADDRESS 0x20F064u
#define trackball_1_y RAM16S(trackball_1_y_ADDRESS)
#define trackball_2_x_ADDRESS 0x20F066u
#define trackball_2_x RAM16S(trackball_2_x_ADDRESS)
#define trackball_2_y_ADDRESS 0x20F068u
#define trackball_2_y RAM16S(trackball_2_y_ADDRESS)
#define trackball_3_x_ADDRESS 0x20F06Au
#define trackball_3_x RAM16S(trackball_3_x_ADDRESS)
#define trackball_3_y_ADDRESS 0x20F06Cu
#define trackball_3_y RAM16S(trackball_3_y_ADDRESS)
#define stage_ADDRESS 0x20F06Eu
#define stage RAM16(stage_ADDRESS)
#define floor_blocks_ADDRESS 0x20F070u
#define floor_blocks RAM32(floor_blocks_ADDRESS)
#define floor_block_bounds_ADDRESS 0x20F07Au
#define floor_block_bounds RAM32(floor_block_bounds_ADDRESS)
#define hitter_list_ADDRESS 0x20F07Eu
#define hitter_list RAM16(hitter_list_ADDRESS)
#define touchable_list_ADDRESS 0x20F080u
#define touchable_list RAM16(touchable_list_ADDRESS)
#define ring_spawn_cursor_ADDRESS 0x20F084u
#define ring_spawn_cursor RAM32(ring_spawn_cursor_ADDRESS)
#define current_restart_point_ADDRESS 0x20F088u
#define current_restart_point RAM32(current_restart_point_ADDRESS)
#define group_spawn_cursor_2_ADDRESS 0x20F08Cu
#define group_spawn_cursor_2 RAM32(group_spawn_cursor_2_ADDRESS)
#define rider_list_ADDRESS 0x20F090u
#define rider_list RAM16(rider_list_ADDRESS)
#define platform_list_ADDRESS 0x20F092u
#define platform_list RAM16(platform_list_ADDRESS)
#define group_member_count_ADDRESS 0x20F094u
#define group_member_count RAM16S(group_member_count_ADDRESS)
#define group_step_x_ADDRESS 0x20F096u
#define group_step_x RAM16(group_step_x_ADDRESS)
#define group_step_y_ADDRESS 0x20F098u
#define group_step_y RAM16(group_step_y_ADDRESS)
#define group_member_x_ADDRESS 0x20F09Au
#define group_member_x RAM16(group_member_x_ADDRESS)
#define group_member_y_ADDRESS 0x20F09Cu
#define group_member_y RAM16(group_member_y_ADDRESS)
#define group_record_ADDRESS 0x20F09Eu
#define group_record RAM32(group_record_ADDRESS)
#define unused_group_spawn_word_2_ADDRESS 0x20F0A4u
#define unused_group_spawn_word_2 RAM16(unused_group_spawn_word_2_ADDRESS)
#define unused_group_spawn_word_3_ADDRESS 0x20F0A6u
#define unused_group_spawn_word_3 RAM16(unused_group_spawn_word_3_ADDRESS)
#define group_member_number_ADDRESS 0x20F0A8u
#define group_member_number RAM8(group_member_number_ADDRESS)
#define unused_game_byte_ADDRESS 0x20F0A9u
#define unused_game_byte RAM8(unused_game_byte_ADDRESS)
#define wall_list_ADDRESS 0x20F0AEu
#define wall_list RAM16(wall_list_ADDRESS)
#define bridge_0_plank_count_ADDRESS 0x20F0B0u
#define bridge_0_plank_count RAM16(bridge_0_plank_count_ADDRESS)
#define wall_spawn_cursor_ADDRESS 0x20F0B2u
#define wall_spawn_cursor RAM32(wall_spawn_cursor_ADDRESS)
#define trackball_step_sums_ADDRESS 0x20F0B6u
#define trackball_step_sums ((u16le *)ram(trackball_step_sums_ADDRESS))
#define stage_init_flags_ADDRESS 0x20F0BCu
#define stage_init_flags RAM32(stage_init_flags_ADDRESS)
#define handler_spawn_cursor_ADDRESS 0x20F0DAu
#define handler_spawn_cursor RAM32(handler_spawn_cursor_ADDRESS)
#define stage_event_cursor_ADDRESS 0x20F0DEu
#define stage_event_cursor RAM32(stage_event_cursor_ADDRESS)
#define scene_step_ADDRESS 0x20F0E2u
#define scene_step RAM8(scene_step_ADDRESS)
#define scene_timer_ADDRESS 0x20F0E4u
#define scene_timer RAM16S(scene_timer_ADDRESS)
#define stage_00_platform_ADDRESS 0x20F0E6u
#define stage_00_platform RAM16(stage_00_platform_ADDRESS)
#define stage_start_kind_ADDRESS 0x20F0E8u
#define stage_start_kind RAM8(stage_start_kind_ADDRESS)
#define unused_player_start_byte_ADDRESS 0x20F0E9u
#define unused_player_start_byte RAM8(unused_player_start_byte_ADDRESS)
#define temp_0_ADDRESS 0x20F0EAu
#define temp_0 RAM16(temp_0_ADDRESS)
#define temp_1_ADDRESS 0x20F0ECu
#define temp_1 RAM32(temp_1_ADDRESS)
#define temp_2_ADDRESS 0x20F0F0u
#define temp_2 RAM8(temp_2_ADDRESS)
#define temp_3_ADDRESS 0x20F0F2u
#define temp_3 RAM16(temp_3_ADDRESS)
#define temp_4_ADDRESS 0x20F0F4u
#define temp_4 RAM16(temp_4_ADDRESS)
#define temp_5_ADDRESS 0x20F0F6u
#define temp_5 RAM16(temp_5_ADDRESS)
#define random_position_ADDRESS 0x20F0FCu
#define random_position RAM32(random_position_ADDRESS)
#define vblank_hook_ADDRESS 0x20F100u
#define vblank_hook RAM32(vblank_hook_ADDRESS)
#define sprite_jump_init_ADDRESS 0x20F104u
#define sprite_jump_init RAM16(sprite_jump_init_ADDRESS)
#define sprite_buffer_flip_ADDRESS 0x20F106u
#define sprite_buffer_flip RAM16(sprite_buffer_flip_ADDRESS)
#define sprite_back_buffer_ADDRESS 0x20F108u
#define sprite_back_buffer RAM32(sprite_back_buffer_ADDRESS)
#define sprite_back_buffer_offset_ADDRESS 0x20F108u
#define sprite_back_buffer_offset RAM16(sprite_back_buffer_offset_ADDRESS)
#define sprite_list_start_ADDRESS 0x20F10Cu
#define sprite_list_start RAM32(sprite_list_start_ADDRESS)
#define sprite_list_start_offset_ADDRESS 0x20F10Cu
#define sprite_list_start_offset RAM16(sprite_list_start_offset_ADDRESS)
#define sprite_list_end_command_ADDRESS 0x20F110u
#define sprite_list_end_command RAM16(sprite_list_end_command_ADDRESS)
#define sprite_frames_ADDRESS 0x20F112u
#define sprite_frames RAM32(sprite_frames_ADDRESS)
#define mixer_text_blend_ADDRESS 0x20F1C0u
#define mixer_text_blend RAM16(mixer_text_blend_ADDRESS)
#define mixer_nbg0_blend_ADDRESS 0x20F1C2u
#define mixer_nbg0_blend RAM16(mixer_nbg0_blend_ADDRESS)
#define mixer_nbg1_blend_ADDRESS 0x20F1C4u
#define mixer_nbg1_blend RAM16(mixer_nbg1_blend_ADDRESS)
#define mixer_nbg2_blend_ADDRESS 0x20F1C6u
#define mixer_nbg2_blend RAM16(mixer_nbg2_blend_ADDRESS)
#define mixer_nbg3_blend_ADDRESS 0x20F1C8u
#define mixer_nbg3_blend RAM16(mixer_nbg3_blend_ADDRESS)
#define mixer_bitmap_blend_ADDRESS 0x20F1CAu
#define mixer_bitmap_blend RAM16(mixer_bitmap_blend_ADDRESS)
#define mixer_offset_select_ADDRESS 0x20F1CEu
#define mixer_offset_select RAM16(mixer_offset_select_ADDRESS)
#define color_offset_red_ADDRESS 0x20F1D0u
#define color_offset_red RAM16(color_offset_red_ADDRESS)
#define color_offset_green_ADDRESS 0x20F1D2u
#define color_offset_green RAM16(color_offset_green_ADDRESS)
#define color_offset_blue_ADDRESS 0x20F1D4u
#define color_offset_blue RAM16(color_offset_blue_ADDRESS)
#define color_offset_2_red_ADDRESS 0x20F1D6u
#define color_offset_2_red RAM16(color_offset_2_red_ADDRESS)
#define color_offset_2_green_ADDRESS 0x20F1D8u
#define color_offset_2_green RAM16(color_offset_2_green_ADDRESS)
#define color_offset_2_blue_ADDRESS 0x20F1DAu
#define color_offset_2_blue RAM16(color_offset_2_blue_ADDRESS)
#define mixer_sprite_control_ADDRESS 0x20F1DCu
#define mixer_sprite_control RAM32(mixer_sprite_control_ADDRESS)
#define mixer_blend_ADDRESS 0x20F1DEu
#define mixer_blend RAM16(mixer_blend_ADDRESS)
#define bitmap_8bpp_ADDRESS 0x20F200u
#define bitmap_8bpp RAM8(bitmap_8bpp_ADDRESS)
#define bitmap_8bpp_pad_ADDRESS 0x20F201u
#define bitmap_8bpp_pad RAM8(bitmap_8bpp_pad_ADDRESS)
#define bitmap_address_ADDRESS 0x20F202u
#define bitmap_address RAM32(bitmap_address_ADDRESS)
#define bitmap_window_left_ADDRESS 0x20F206u
#define bitmap_window_left RAM16S(bitmap_window_left_ADDRESS)
#define bitmap_window_top_ADDRESS 0x20F208u
#define bitmap_window_top RAM16S(bitmap_window_top_ADDRESS)
#define bitmap_window_right_ADDRESS 0x20F20Au
#define bitmap_window_right RAM16S(bitmap_window_right_ADDRESS)
#define bitmap_window_bottom_ADDRESS 0x20F20Cu
#define bitmap_window_bottom RAM16S(bitmap_window_bottom_ADDRESS)
#define vblank_start_hook_ADDRESS 0x20F27Cu
#define vblank_start_hook RAM32(vblank_start_hook_ADDRESS)
#define nbg0_scroll_x_ADDRESS 0x20F280u
#define nbg0_scroll_x RAM32(nbg0_scroll_x_ADDRESS)
#define nbg0_scroll_x_int_ADDRESS 0x20F282u
#define nbg0_scroll_x_int RAM16(nbg0_scroll_x_int_ADDRESS)
#define nbg0_scroll_y_ADDRESS 0x20F284u
#define nbg0_scroll_y RAM32(nbg0_scroll_y_ADDRESS)
#define nbg0_scroll_y_int_ADDRESS 0x20F286u
#define nbg0_scroll_y_int RAM16(nbg0_scroll_y_int_ADDRESS)
#define nbg1_scroll_x_ADDRESS 0x20F288u
#define nbg1_scroll_x RAM32(nbg1_scroll_x_ADDRESS)
#define nbg1_scroll_x_int_ADDRESS 0x20F28Au
#define nbg1_scroll_x_int RAM16(nbg1_scroll_x_int_ADDRESS)
#define nbg1_scroll_y_ADDRESS 0x20F28Cu
#define nbg1_scroll_y RAM32(nbg1_scroll_y_ADDRESS)
#define nbg1_scroll_y_int_ADDRESS 0x20F28Eu
#define nbg1_scroll_y_int RAM16(nbg1_scroll_y_int_ADDRESS)
#define nbg2_scroll_x_fraction_ADDRESS 0x20F290u
#define nbg2_scroll_x_fraction RAM16(nbg2_scroll_x_fraction_ADDRESS)
#define nbg2_scroll_x_ADDRESS 0x20F292u
#define nbg2_scroll_x RAM16(nbg2_scroll_x_ADDRESS)
#define nbg2_scroll_y_fraction_ADDRESS 0x20F294u
#define nbg2_scroll_y_fraction RAM16(nbg2_scroll_y_fraction_ADDRESS)
#define nbg2_scroll_y_ADDRESS 0x20F296u
#define nbg2_scroll_y RAM16(nbg2_scroll_y_ADDRESS)
#define nbg3_scroll_x_long_ADDRESS 0x20F29Au
#define nbg3_scroll_x_long RAM32(nbg3_scroll_x_long_ADDRESS)
#define nbg3_scroll_x_ADDRESS 0x20F29Au
#define nbg3_scroll_x RAM16(nbg3_scroll_x_ADDRESS)
#define nbg3_scroll_y_ADDRESS 0x20F29Eu
#define nbg3_scroll_y RAM16(nbg3_scroll_y_ADDRESS)
#define nbg0_center_x_ADDRESS 0x20F2A0u
#define nbg0_center_x RAM16(nbg0_center_x_ADDRESS)
#define nbg0_center_y_ADDRESS 0x20F2A2u
#define nbg0_center_y RAM16(nbg0_center_y_ADDRESS)
#define nbg1_center_x_ADDRESS 0x20F2A4u
#define nbg1_center_x RAM16(nbg1_center_x_ADDRESS)
#define nbg1_center_y_ADDRESS 0x20F2A6u
#define nbg1_center_y RAM16(nbg1_center_y_ADDRESS)
#define nbg0_pages_ADDRESS 0x20F2B0u
#define nbg0_pages RAM32(nbg0_pages_ADDRESS)
#define nbg1_pages_ADDRESS 0x20F2B4u
#define nbg1_pages RAM32(nbg1_pages_ADDRESS)
#define nbg2_pages_ADDRESS 0x20F2B8u
#define nbg2_pages RAM32(nbg2_pages_ADDRESS)
#define nbg3_pages_ADDRESS 0x20F2BCu
#define nbg3_pages RAM32(nbg3_pages_ADDRESS)
#define video_layer_opaque_shadow_ADDRESS 0x20F2C0u
#define video_layer_opaque_shadow RAM8(video_layer_opaque_shadow_ADDRESS)
#define video_registers_latched_ADDRESS 0x20F2C2u
#define video_registers_latched RAM16(video_registers_latched_ADDRESS)
#define vram_script_dictionary_ADDRESS 0x20F300u
#define vram_script_dictionary ((u16le *)ram(vram_script_dictionary_ADDRESS))
#define video_layer_opaque_latched_ADDRESS 0x20F302u
#define video_layer_opaque_latched RAM8(video_layer_opaque_latched_ADDRESS)
#define credit_pool_ADDRESS 0x20F400u
#define credit_pool RAM8(credit_pool_ADDRESS)
#define free_play_ADDRESS 0x20F401u
#define free_play RAM8(free_play_ADDRESS)
#define credit_coin_cost_ADDRESS 0x20F402u
#define credit_coin_cost RAM8(credit_coin_cost_ADDRESS)
#define credit_pool_coins_ADDRESS 0x20F403u
#define credit_pool_coins RAM8(credit_pool_coins_ADDRESS)
#define shared_coin_counter_word_ADDRESS 0x20F404u
#define shared_coin_counter_word RAM16(shared_coin_counter_word_ADDRESS)
#define shared_coin_counter_ADDRESS 0x20F404u
#define shared_coin_counter RAM8(shared_coin_counter_ADDRESS)
#define unused_coin_byte_ADDRESS 0x20F405u
#define unused_coin_byte RAM8(unused_coin_byte_ADDRESS)
#define coin_counter_1_on_ADDRESS 0x20F406u
#define coin_counter_1_on RAM8(coin_counter_1_on_ADDRESS)
#define coin_counter_1_off_ADDRESS 0x20F407u
#define coin_counter_1_off RAM8(coin_counter_1_off_ADDRESS)
#define coin_counter_1_pending_ADDRESS 0x20F408u
#define coin_counter_1_pending RAM8(coin_counter_1_pending_ADDRESS)
#define chute_1_multiplier_ADDRESS 0x20F409u
#define chute_1_multiplier RAM8(chute_1_multiplier_ADDRESS)
#define coin_counter_2_on_ADDRESS 0x20F40Au
#define coin_counter_2_on RAM8(coin_counter_2_on_ADDRESS)
#define coin_counter_2_off_ADDRESS 0x20F40Bu
#define coin_counter_2_off RAM8(coin_counter_2_off_ADDRESS)
#define coin_counter_2_pending_ADDRESS 0x20F40Cu
#define coin_counter_2_pending RAM8(coin_counter_2_pending_ADDRESS)
#define chute_2_multiplier_ADDRESS 0x20F40Du
#define chute_2_multiplier RAM8(chute_2_multiplier_ADDRESS)
#define bonus_adder_ADDRESS 0x20F40Eu
#define bonus_adder RAM8(bonus_adder_ADDRESS)
#define credits_per_start_ADDRESS 0x20F410u
#define credits_per_start RAM16(credits_per_start_ADDRESS)
#define p1_coins_ADDRESS 0x20F412u
#define p1_coins RAM8(p1_coins_ADDRESS)
#define p1_credits_ADDRESS 0x20F413u
#define p1_credits RAM8(p1_credits_ADDRESS)
#define p1_bonus_coins_ADDRESS 0x20F414u
#define p1_bonus_coins RAM8(p1_bonus_coins_ADDRESS)
#define p1_credits_changed_ADDRESS 0x20F415u
#define p1_credits_changed RAM8(p1_credits_changed_ADDRESS)
#define p2_coins_ADDRESS 0x20F416u
#define p2_coins RAM8(p2_coins_ADDRESS)
#define p2_credits_ADDRESS 0x20F417u
#define p2_credits RAM8(p2_credits_ADDRESS)
#define p2_bonus_coins_ADDRESS 0x20F418u
#define p2_bonus_coins RAM8(p2_bonus_coins_ADDRESS)
#define p2_credits_changed_ADDRESS 0x20F419u
#define p2_credits_changed RAM8(p2_credits_changed_ADDRESS)
#define p3_coins_ADDRESS 0x20F41Au
#define p3_coins RAM8(p3_coins_ADDRESS)
#define p3_credits_ADDRESS 0x20F41Bu
#define p3_credits RAM8(p3_credits_ADDRESS)
#define p3_bonus_coins_ADDRESS 0x20F41Cu
#define p3_bonus_coins RAM8(p3_bonus_coins_ADDRESS)
#define p3_credits_changed_ADDRESS 0x20F41Du
#define p3_credits_changed RAM8(p3_credits_changed_ADDRESS)
#define cabinet_config_ADDRESS 0x20F41Eu
#define cabinet_config RAM8(cabinet_config_ADDRESS)
#define service_coin_sounds_ADDRESS 0x20F41Fu
#define service_coin_sounds RAM8(service_coin_sounds_ADDRESS)
#define coin_sounds_ADDRESS 0x20F420u
#define coin_sounds RAM8(coin_sounds_ADDRESS)
#define stage_order_copy_ADDRESS 0x20F500u
#define stage_order_copy RAM16(stage_order_copy_ADDRESS)
#define eeprom_magic_ADDRESS 0x20F600u
#define eeprom_magic RAM32(eeprom_magic_ADDRESS)
#define eeprom_rom_stamp_ADDRESS 0x20F604u
#define eeprom_rom_stamp RAM16(eeprom_rom_stamp_ADDRESS)
#define eeprom_checksum_ADDRESS 0x20F608u
#define eeprom_checksum RAM16(eeprom_checksum_ADDRESS)
#define eeprom_write_count_ADDRESS 0x20F60Au
#define eeprom_write_count RAM32(eeprom_write_count_ADDRESS)
#define setting_advertise_sound_ADDRESS 0x20F60Eu
#define setting_advertise_sound RAM8(setting_advertise_sound_ADDRESS)
#define setting_coins_per_credit_ADDRESS 0x20F60Fu
#define setting_coins_per_credit RAM8(setting_coins_per_credit_ADDRESS)
#define setting_chute_1_multiplier_ADDRESS 0x20F610u
#define setting_chute_1_multiplier RAM8(setting_chute_1_multiplier_ADDRESS)
#define setting_chute_2_multiplier_ADDRESS 0x20F611u
#define setting_chute_2_multiplier RAM8(setting_chute_2_multiplier_ADDRESS)
#define setting_bonus_adder_ADDRESS 0x20F612u
#define setting_bonus_adder RAM8(setting_bonus_adder_ADDRESS)
#define setting_cabinet_config_ADDRESS 0x20F613u
#define setting_cabinet_config RAM8(setting_cabinet_config_ADDRESS)
#define setting_credits_to_start_ADDRESS 0x20F614u
#define setting_credits_to_start RAM8(setting_credits_to_start_ADDRESS)
#define setting_monitor_flip_ADDRESS 0x20F618u
#define setting_monitor_flip RAM8(setting_monitor_flip_ADDRESS)
#define setting_coin_chute_type_ADDRESS 0x20F61Au
#define setting_coin_chute_type RAM8(setting_coin_chute_type_ADDRESS)
#define setting_coin_number_ADDRESS 0x20F61Bu
#define setting_coin_number RAM8S(setting_coin_number_ADDRESS)
#define setting_difficulty_ADDRESS 0x20F620u
#define setting_difficulty RAM8(setting_difficulty_ADDRESS)
#define setting_initial_vitality_ADDRESS 0x20F622u
#define setting_initial_vitality RAM8(setting_initial_vitality_ADDRESS)
#define setting_no_start_buttons_ADDRESS 0x20F623u
#define setting_no_start_buttons RAM8(setting_no_start_buttons_ADDRESS)
#define setting_moving_seat_ADDRESS 0x20F624u
#define setting_moving_seat RAM8(setting_moving_seat_ADDRESS)
#define setting_cabinet_type_ADDRESS 0x20F625u
#define setting_cabinet_type RAM8(setting_cabinet_type_ADDRESS)
#define setting_coin_number_individual_ADDRESS 0x20F626u
#define setting_coin_number_individual RAM8S(setting_coin_number_individual_ADDRESS)
#define setting_small_large_ADDRESS 0x20F627u
#define setting_small_large RAM8(setting_small_large_ADDRESS)
#define eeprom_backup_ADDRESS 0x20F640u
#define eeprom_backup RAM8(eeprom_backup_ADDRESS)
#define eeprom_backup_checksum_ADDRESS 0x20F648u
#define eeprom_backup_checksum RAM16(eeprom_backup_checksum_ADDRESS)
#define sprite_buckets_end_ADDRESS 0x20FA00u
#define sprite_buckets_end RAM16(sprite_buckets_end_ADDRESS)
#define sprite_buckets_ADDRESS 0x20FA02u
#define sprite_buckets RAM16(sprite_buckets_ADDRESS)

/* work RAM as one family of functions uses it (their scratch variables) */
#define push_motion_x_ADDRESS 0x20E500u
#define push_motion_x RAM32S(push_motion_x_ADDRESS)
#define push_motion_y_ADDRESS 0x20E504u
#define push_motion_y RAM32S(push_motion_y_ADDRESS)
#define back_edge_frames_ADDRESS 0x20CA50u
#define back_edge_frames RAM8(back_edge_frames_ADDRESS)
#define biting_head_depth_ADDRESS 0x20F0EAu
#define biting_head_depth RAM16(biting_head_depth_ADDRESS)
#define bridge_flames_left_ADDRESS 0x20F0EAu
#define bridge_flames_left RAM16S(bridge_flames_left_ADDRESS)
#define bridge_flame_offset_y_ADDRESS 0x20F0ECu
#define bridge_flame_offset_y RAM32(bridge_flame_offset_y_ADDRESS)
#define grate_step_number_ADDRESS 0x20F0EAu
#define grate_step_number RAM8S(grate_step_number_ADDRESS)
#define grate_rows_to_build_ADDRESS 0x20F0EBu
#define grate_rows_to_build RAM8S(grate_rows_to_build_ADDRESS)
#define saw_shaft_part_ADDRESS 0x20F0EAu
#define saw_shaft_part RAM16S(saw_shaft_part_ADDRESS)
#define boulder_flames_left_ADDRESS 0x20F0EAu
#define boulder_flames_left RAM8S(boulder_flames_left_ADDRESS)
#define boulder_flame_number_ADDRESS 0x20F0EBu
#define boulder_flame_number RAM8(boulder_flame_number_ADDRESS)
#define cage_bars_left_ADDRESS 0x20F0EAu
#define cage_bars_left RAM16S(cage_bars_left_ADDRESS)
#define cage_bar_x_ADDRESS 0x20F0ECu
#define cage_bar_x RAM16(cage_bar_x_ADDRESS)
#define cage_bar_y_ADDRESS 0x20F0EEu
#define cage_bar_y RAM16(cage_bar_y_ADDRESS)
#define catapult_pair_template_ADDRESS 0x20F0EAu
#define catapult_pair_template RAM32(catapult_pair_template_ADDRESS)
#define contact_saved_x_ADDRESS 0x20E500u
#define contact_saved_x RAM32(contact_saved_x_ADDRESS)
#define contact_saved_y_ADDRESS 0x20E504u
#define contact_saved_y RAM32(contact_saved_y_ADDRESS)
#define contact_box_side_ADDRESS 0x20F0EAu
#define contact_box_side RAM16(contact_box_side_ADDRESS)
#define step_floor_z_ADDRESS 0x20F0EAu
#define step_floor_z RAM32S(step_floor_z_ADDRESS)
#define step_floor_z_int_ADDRESS 0x20F0ECu
#define step_floor_z_int RAM16(step_floor_z_int_ADDRESS)
#define step_blocking_floor_block_ADDRESS 0x20F0EEu
#define step_blocking_floor_block RAM32(step_blocking_floor_block_ADDRESS)
#define slope_velocity_y_ADDRESS 0x20F0EAu
#define slope_velocity_y RAM32(slope_velocity_y_ADDRESS)
#define unused_drift_divisor_ADDRESS 0x20F0EAu
#define unused_drift_divisor RAM32(unused_drift_divisor_ADDRESS)
#define unused_drift_byte_ADDRESS 0x20F0EEu
#define unused_drift_byte RAM8(unused_drift_byte_ADDRESS)
#define icicle_row_offset_ADDRESS 0x20F0EAu
#define icicle_row_offset RAM16(icicle_row_offset_ADDRESS)
#define demo_input_ADDRESS 0x20E5CEu
#define demo_input RAM32(demo_input_ADDRESS)
#define geysers_left_ADDRESS 0x20F0EAu
#define geysers_left RAM16S(geysers_left_ADDRESS)
#define geyser_y_ADDRESS 0x20F0ECu
#define geyser_y RAM32(geyser_y_ADDRESS)
#define geyser_y_int_ADDRESS 0x20F0EEu
#define geyser_y_int RAM16(geyser_y_int_ADDRESS)
#define geyser_delay_cursor_ADDRESS 0x20F0F0u
#define geyser_delay_cursor RAM32(geyser_delay_cursor_ADDRESS)
#define ice_row_start_x_ADDRESS 0x20F0EAu
#define ice_row_start_x RAM32(ice_row_start_x_ADDRESS)
#define ice_cube_floor_block_ADDRESS 0x20F0EEu
#define ice_cube_floor_block RAM32(ice_cube_floor_block_ADDRESS)
#define buried_part_depth_ADDRESS 0x20F0EAu
#define buried_part_depth RAM16(buried_part_depth_ADDRESS)
#define back_edge_frames_ADDRESS 0x20CA50u
#define back_edge_frames RAM8(back_edge_frames_ADDRESS)
#define fireball_lane_ADDRESS 0x20F0EAu
#define fireball_lane RAM8S(fireball_lane_ADDRESS)
#define fireball_lane_timer_cursor_ADDRESS 0x20F0ECu
#define fireball_lane_timer_cursor RAM32(fireball_lane_timer_cursor_ADDRESS)
#define trackball_1_quadrants_ADDRESS 0x20906Bu
#define trackball_1_quadrants RAM8(trackball_1_quadrants_ADDRESS)
#define trackball_2_quadrants_ADDRESS 0x20906Cu
#define trackball_2_quadrants RAM8(trackball_2_quadrants_ADDRESS)
#define trackball_3_quadrants_ADDRESS 0x20906Du
#define trackball_3_quadrants RAM8(trackball_3_quadrants_ADDRESS)
#define demo_patched_inputs_ADDRESS 0x20F0EAu
#define demo_patched_inputs RAM32(demo_patched_inputs_ADDRESS)
#define saved_sprite_offset_y_ADDRESS 0x20F0EAu
#define saved_sprite_offset_y RAM8(saved_sprite_offset_y_ADDRESS)
#define side_step_projected_y_ADDRESS 0x20F0EEu
#define side_step_projected_y RAM32(side_step_projected_y_ADDRESS)
#define pull_up_done_ADDRESS 0x20F0EAu
#define pull_up_done RAM8(pull_up_done_ADDRESS)
#define side_step_screen_x_ADDRESS 0x20F0EAu
#define side_step_screen_x RAM32(side_step_screen_x_ADDRESS)
#define step_projected_y_ADDRESS 0x20F0EEu
#define step_projected_y RAM32S(step_projected_y_ADDRESS)
#define saved_sprite_offset_y_ADDRESS 0x20F0EAu
#define saved_sprite_offset_y RAM8(saved_sprite_offset_y_ADDRESS)
#define saved_sprite_offset_y_ADDRESS 0x20F0EAu
#define saved_sprite_offset_y RAM8(saved_sprite_offset_y_ADDRESS)
#define saved_sprite_offset_y_ADDRESS 0x20F0EAu
#define saved_sprite_offset_y RAM8(saved_sprite_offset_y_ADDRESS)
#define board_props_left_ADDRESS 0x20F0EAu
#define board_props_left RAM16S(board_props_left_ADDRESS)
#define railing_segments_left_ADDRESS 0x20F0EAu
#define railing_segments_left RAM16S(railing_segments_left_ADDRESS)
#define railing_segment_y_ADDRESS 0x20F0ECu
#define railing_segment_y RAM32(railing_segment_y_ADDRESS)
#define railing_segment_y_int_ADDRESS 0x20F0EEu
#define railing_segment_y_int RAM16(railing_segment_y_int_ADDRESS)
#define board_rings_left_ADDRESS 0x20F0ECu
#define board_rings_left RAM16S(board_rings_left_ADDRESS)
#define object_handler_list_ADDRESS 0x20F0EAu
#define object_handler_list RAM32(object_handler_list_ADDRESS)
#define player_block_cursor_ADDRESS 0x20F0EEu
#define player_block_cursor RAM32(player_block_cursor_ADDRESS)
#define saw_blades_left_ADDRESS 0x20F0EAu
#define saw_blades_left RAM8S(saw_blades_left_ADDRESS)
#define saw_blade_offset_x_ADDRESS 0x20F0ECu
#define saw_blade_offset_x RAM8(saw_blade_offset_x_ADDRESS)
#define scatter_fixed_ADDRESS 0x20F0EAu
#define scatter_fixed RAM16(scatter_fixed_ADDRESS)
#define scatter_fixed_jump_ADDRESS 0x20F0EBu
#define scatter_fixed_jump RAM8(scatter_fixed_jump_ADDRESS)
#define scenery_sprite_kind_ADDRESS 0x20F0EAu
#define scenery_sprite_kind RAM16(scenery_sprite_kind_ADDRESS)
#define sparkle_offset_x_ADDRESS 0x20F0EAu
#define sparkle_offset_x RAM16(sparkle_offset_x_ADDRESS)
#define chaser_zone_index_ADDRESS 0x20F0EAu
#define chaser_zone_index RAM32(chaser_zone_index_ADDRESS)
#define door_rollers_left_ADDRESS 0x20F0EAu
#define door_rollers_left RAM16S(door_rollers_left_ADDRESS)
#define trench_flame_y_ADDRESS 0x20F0EAu
#define trench_flame_y RAM16(trench_flame_y_ADDRESS)
#define trench_flames_left_ADDRESS 0x20F0ECu
#define trench_flames_left RAM16S(trench_flames_left_ADDRESS)
#define grate_debris_record_ADDRESS 0x20F0EAu
#define grate_debris_record RAM32(grate_debris_record_ADDRESS)
#define grate_debris_left_ADDRESS 0x20F0EEu
#define grate_debris_left RAM16S(grate_debris_left_ADDRESS)
#define lava_flame_random_ADDRESS 0x20F0EAu
#define lava_flame_random RAM32(lava_flame_random_ADDRESS)
#define group_floor_block_ADDRESS 0x20F0ECu
#define group_floor_block RAM32(group_floor_block_ADDRESS)
#define group_bridge_number_ADDRESS 0x20F0F0u
#define group_bridge_number RAM8(group_bridge_number_ADDRESS)
#define group_direction_ADDRESS 0x20F0F2u
#define group_direction RAM16(group_direction_ADDRESS)
#define group_leader_ADDRESS 0x20F0F4u
#define group_leader RAM16(group_leader_ADDRESS)
#define group_silent_ADDRESS 0x20F0F6u
#define group_silent RAM8(group_silent_ADDRESS)
#define group_floor_block_ADDRESS 0x20F0ECu
#define group_floor_block RAM32(group_floor_block_ADDRESS)
#define group_bridge_number_ADDRESS 0x20F0F0u
#define group_bridge_number RAM8(group_bridge_number_ADDRESS)
#define group_direction_ADDRESS 0x20F0F2u
#define group_direction RAM16(group_direction_ADDRESS)
#define group_leader_ADDRESS 0x20F0F4u
#define group_leader RAM16(group_leader_ADDRESS)
#define group_previous_member_ADDRESS 0x20F0F6u
#define group_previous_member RAM16(group_previous_member_ADDRESS)
#define ride_start_x_ADDRESS 0x20F0EAu
#define ride_start_x RAM32(ride_start_x_ADDRESS)
#define ring_row_rings_left_ADDRESS 0x20E500u
#define ring_row_rings_left RAM16S(ring_row_rings_left_ADDRESS)
#define ring_row_template_ADDRESS 0x20E502u
#define ring_row_template RAM16(ring_row_template_ADDRESS)
#define ring_row_x_ADDRESS 0x20E504u
#define ring_row_x RAM16(ring_row_x_ADDRESS)
#define ring_row_y_ADDRESS 0x20E506u
#define ring_row_y RAM16(ring_row_y_ADDRESS)
#define ring_row_dx_ADDRESS 0x20E508u
#define ring_row_dx RAM16(ring_row_dx_ADDRESS)
#define ring_row_dy_ADDRESS 0x20E50Au
#define ring_row_dy RAM16(ring_row_dy_ADDRESS)
#define ring_row_next_80_ADDRESS 0x20E50Cu
#define ring_row_next_80 RAM16(ring_row_next_80_ADDRESS)
#define roller_zone_index_ADDRESS 0x20F0EAu
#define roller_zone_index RAM32(roller_zone_index_ADDRESS)
#define slip_pieces_left_ADDRESS 0x20F0EAu
#define slip_pieces_left RAM16S(slip_pieces_left_ADDRESS)
#define slip_piece_speed_ADDRESS 0x20F0ECu
#define slip_piece_speed RAM32(slip_piece_speed_ADDRESS)
#define template_spawn_x_ADDRESS 0x20F0EAu
#define template_spawn_x RAM16(template_spawn_x_ADDRESS)
#define template_spawn_y_ADDRESS 0x20F0ECu
#define template_spawn_y RAM16(template_spawn_y_ADDRESS)
#define template_spawn_z_ADDRESS 0x20F0EEu
#define template_spawn_z RAM16(template_spawn_z_ADDRESS)
#define template_spawn_index_ADDRESS 0x20F0F0u
#define template_spawn_index RAM16(template_spawn_index_ADDRESS)
#define wall_corner_x_ADDRESS 0x20F0EAu
#define wall_corner_x RAM32(wall_corner_x_ADDRESS)
#define wall_corner_y_ADDRESS 0x20F0EEu
#define wall_corner_y RAM32(wall_corner_y_ADDRESS)
#define roller_part_x_ADDRESS 0x20E500u
#define roller_part_x RAM32(roller_part_x_ADDRESS)
#define roller_step_x_ADDRESS 0x20E504u
#define roller_step_x RAM32(roller_step_x_ADDRESS)
#define roller_part_y_ADDRESS 0x20E508u
#define roller_part_y RAM32(roller_part_y_ADDRESS)
#define roller_step_y_ADDRESS 0x20E50Cu
#define roller_step_y RAM32(roller_step_y_ADDRESS)
#define roller_parts_left_ADDRESS 0x20F0EAu
#define roller_parts_left RAM8S(roller_parts_left_ADDRESS)
#define roller_part_record_ADDRESS 0x20F0ECu
#define roller_part_record RAM32(roller_part_record_ADDRESS)
#define roller_part_frame_cursor_ADDRESS 0x20F0F2u
#define roller_part_frame_cursor RAM32(roller_part_frame_cursor_ADDRESS)
#define roller_first_state_ADDRESS 0x20F0F6u
#define roller_first_state RAM16(roller_first_state_ADDRESS)
#define flame_chaser_gap_ADDRESS 0x20F0EAu
#define flame_chaser_gap RAM16S(flame_chaser_gap_ADDRESS)
#define banner_letter_offset_x_ADDRESS 0x20F0EAu
#define banner_letter_offset_x RAM16(banner_letter_offset_x_ADDRESS)
#define banner_letters_left_ADDRESS 0x20F0ECu
#define banner_letters_left RAM16S(banner_letters_left_ADDRESS)
#define player_handler_list_ADDRESS 0x20F0EAu
#define player_handler_list RAM32(player_handler_list_ADDRESS)
#define demo_input_ADDRESS 0x20E5CEu
#define demo_input RAM32(demo_input_ADDRESS)
#define trackball_1_quadrants_ADDRESS 0x20906Bu
#define trackball_1_quadrants RAM8(trackball_1_quadrants_ADDRESS)
#define trackball_2_quadrants_ADDRESS 0x20906Cu
#define trackball_2_quadrants RAM8(trackball_2_quadrants_ADDRESS)
#define trackball_3_quadrants_ADDRESS 0x20906Du
#define trackball_3_quadrants RAM8(trackball_3_quadrants_ADDRESS)
#define tornado_kind_ADDRESS 0x20F0EAu
#define tornado_kind RAM16(tornado_kind_ADDRESS)
#define recent_literals_ADDRESS 0x20B500u
#define recent_literals ((uint8_t *)ram(recent_literals_ADDRESS))
#define escape_seconds_bcd_ADDRESS 0x20F0EAu
#define escape_seconds_bcd RAM16(escape_seconds_bcd_ADDRESS)
#define escape_digit_scale_ADDRESS 0x20F0ECu
#define escape_digit_scale RAM16(escape_digit_scale_ADDRESS)
#define back_edge_frames_ADDRESS 0x20CA50u
#define back_edge_frames RAM8(back_edge_frames_ADDRESS)
#define wall_sprite_offset_x_ADDRESS 0x20F0EAu
#define wall_sprite_offset_x RAM16(wall_sprite_offset_x_ADDRESS)

/* data in the program ROM the code reads */
#define system_mode_handlers_ADDRESS 0x000594u
#define system_mode_handlers ((const u32le *)rom(system_mode_handlers_ADDRESS))
#define attract_sequence_ADDRESS 0x0005B4u
#define attract_sequence ((const uint8_t *)rom(attract_sequence_ADDRESS))
#define mixer_defaults_ADDRESS 0x0005BCu
#define mixer_defaults ROM16(mixer_defaults_ADDRESS)
#define mixer_default_nbg0_ADDRESS 0x0005DEu
#define mixer_default_nbg0 ROM16(mixer_default_nbg0_ADDRESS)
#define mixer_default_nbg3_ADDRESS 0x0005E4u
#define mixer_default_nbg3 ROM16(mixer_default_nbg3_ADDRESS)
#define stage_events_ADDRESS 0x002492u
#define stage_events ((const u16le *)rom(stage_events_ADDRESS))
#define stage_link_points_ADDRESS 0x002520u
#define stage_link_points ((const u16le *)rom(stage_link_points_ADDRESS))
#define stage_order_ADDRESS 0x002639u
#define stage_order ROM16(stage_order_ADDRESS)
#define stage_select_cleared_values_ADDRESS 0x00265Bu
#define stage_select_cleared_values ((const u16le *)rom(stage_select_cleared_values_ADDRESS))
#define stage_start_sounds_ADDRESS 0x002681u
#define stage_start_sounds ((const uint8_t *)rom(stage_start_sounds_ADDRESS))
#define stage_layer_blending_ADDRESS 0x002694u
#define stage_layer_blending ((const u16le *)rom(stage_layer_blending_ADDRESS))
#define stage_name_banners_ADDRESS 0x0026CFu
#define stage_name_banners ((const u16le *)rom(stage_name_banners_ADDRESS))
#define cleared_banner_x_ADDRESS 0x0026F5u
#define cleared_banner_x ROM16(cleared_banner_x_ADDRESS)
#define cleared_banner_y_ADDRESS 0x0026F7u
#define cleared_banner_y ROM16(cleared_banner_y_ADDRESS)
#define floor_4_slow_run_steps_ADDRESS 0x0050AFu
#define floor_4_slow_run_steps ((const uint8_t *)rom(floor_4_slow_run_steps_ADDRESS))
#define hud_name_positions_3p_ADDRESS 0x00CD12u
#define hud_name_positions_3p ((const u16le *)rom(hud_name_positions_3p_ADDRESS))
#define hud_name_positions_2p_ADDRESS 0x00CD18u
#define hud_name_positions_2p ((const u16le *)rom(hud_name_positions_2p_ADDRESS))
#define sink_depth_limits_ADDRESS 0x00E453u
#define sink_depth_limits ((const s16le *)rom(sink_depth_limits_ADDRESS))
#define vine_scroll_stop_player_blocks_ADDRESS 0x00F07Bu
#define vine_scroll_stop_player_blocks ((const u32le *)rom(vine_scroll_stop_player_blocks_ADDRESS))
#define spike_panel_frame_sequence_ADDRESS 0x00F46Bu
#define spike_panel_frame_sequence ((const uint8_t *)rom(spike_panel_frame_sequence_ADDRESS))
#define spike_panel_step_durations_ADDRESS 0x00F474u
#define spike_panel_step_durations ((const u16le *)rom(spike_panel_step_durations_ADDRESS))
#define spike_panel_head_sprites_ADDRESS 0x00F49Eu
#define spike_panel_head_sprites ((const u16le *)rom(spike_panel_head_sprites_ADDRESS))
#define spike_panel_part_1_sprite_flags_ADDRESS 0x00F4FEu
#define spike_panel_part_1_sprite_flags ((const u16le *)rom(spike_panel_part_1_sprite_flags_ADDRESS))
#define spike_panel_part_1_sprites_ADDRESS 0x00F50Au
#define spike_panel_part_1_sprites ((const u16le *)rom(spike_panel_part_1_sprites_ADDRESS))
#define spike_panel_part_2_sprites_ADDRESS 0x00F52Eu
#define spike_panel_part_2_sprites ((const u16le *)rom(spike_panel_part_2_sprites_ADDRESS))
#define electric_pole_rise_frames_ADDRESS 0x00F736u
#define electric_pole_rise_frames ((const uint8_t *)rom(electric_pole_rise_frames_ADDRESS))
#define electric_pole_sprites_ADDRESS 0x00F741u
#define electric_pole_sprites ((const u16le *)rom(electric_pole_sprites_ADDRESS))
#define electric_pole_front_spark_sprites_ADDRESS 0x00F751u
#define electric_pole_front_spark_sprites ((const u16le *)rom(electric_pole_front_spark_sprites_ADDRESS))
#define electric_pole_side_spark_sprites_ADDRESS 0x00F75Fu
#define electric_pole_side_spark_sprites ((const u16le *)rom(electric_pole_side_spark_sprites_ADDRESS))
#define electric_pole_side_spark_offsets_x_ADDRESS 0x00F779u
#define electric_pole_side_spark_offsets_x ((const s16le *)rom(electric_pole_side_spark_offsets_x_ADDRESS))
#define metal_wall_part_tables_ADDRESS 0x00FB08u
#define metal_wall_part_tables ((const u32le *)rom(metal_wall_part_tables_ADDRESS))
#define metal_wall_sprites_ADDRESS 0x00FB20u
#define metal_wall_sprites ((const u16le *)rom(metal_wall_sprites_ADDRESS))
#define metal_wall_dust_sprites_ADDRESS 0x00FBC0u
#define metal_wall_dust_sprites ((const u16le *)rom(metal_wall_dust_sprites_ADDRESS))
#define metal_wall_damage_frames_ADDRESS 0x00FBE0u
#define metal_wall_damage_frames ((const uint8_t *)rom(metal_wall_damage_frames_ADDRESS))
#define flame_machine_capsule_sprites_ADDRESS 0x01002Bu
#define flame_machine_capsule_sprites ((const u16le *)rom(flame_machine_capsule_sprites_ADDRESS))
#define flame_machine_hit_palettes_ADDRESS 0x010045u
#define flame_machine_hit_palettes ((const u16le *)rom(flame_machine_hit_palettes_ADDRESS))
#define flame_machine_rod_sprites_ADDRESS 0x010196u
#define flame_machine_rod_sprites ((const u16le *)rom(flame_machine_rod_sprites_ADDRESS))
#define flame_machine_back_wall_frames_ADDRESS 0x0101B8u
#define flame_machine_back_wall_frames ((const uint8_t *)rom(flame_machine_back_wall_frames_ADDRESS))
#define flame_machine_arm_sprites_ADDRESS 0x010351u
#define flame_machine_arm_sprites ((const u16le *)rom(flame_machine_arm_sprites_ADDRESS))
#define flame_machine_arm_part_sprites_ADDRESS 0x01036Bu
#define flame_machine_arm_part_sprites ((const u16le *)rom(flame_machine_arm_part_sprites_ADDRESS))
#define flame_machine_arm_frames_ADDRESS 0x010385u
#define flame_machine_arm_frames ((const uint8_t *)rom(flame_machine_arm_frames_ADDRESS))
#define flame_machine_cannon_hit_palettes_ADDRESS 0x01042Du
#define flame_machine_cannon_hit_palettes ((const u16le *)rom(flame_machine_cannon_hit_palettes_ADDRESS))
#define flame_machine_flame_frames_ADDRESS 0x01057Du
#define flame_machine_flame_frames ((const uint8_t *)rom(flame_machine_flame_frames_ADDRESS))
#define flame_machine_flame_sprites_ADDRESS 0x0105F4u
#define flame_machine_flame_sprites ((const u16le *)rom(flame_machine_flame_sprites_ADDRESS))
#define flame_machine_flame_shadow_sprites_ADDRESS 0x01060Au
#define flame_machine_flame_shadow_sprites ((const u16le *)rom(flame_machine_flame_shadow_sprites_ADDRESS))
#define flame_machine_flame_directions_ADDRESS 0x010610u
#define flame_machine_flame_directions ((const u16le *)rom(flame_machine_flame_directions_ADDRESS))
#define spiked_disc_sprites_ADDRESS 0x0107AFu
#define spiked_disc_sprites ((const u16le *)rom(spiked_disc_sprites_ADDRESS))
#define treadmill_belt_sprites_ADDRESS 0x010B84u
#define treadmill_belt_sprites ((const u16le *)rom(treadmill_belt_sprites_ADDRESS))
#define treadmill_lift_forces_ADDRESS 0x010B94u
#define treadmill_lift_forces ((const u32le *)rom(treadmill_lift_forces_ADDRESS))
#define treadmill_player_blocks_ADDRESS 0x010BD0u
#define treadmill_player_blocks ((const u32le *)rom(treadmill_player_blocks_ADDRESS))
#define treadmill_roller_sprites_ADDRESS 0x010C43u
#define treadmill_roller_sprites ((const u16le *)rom(treadmill_roller_sprites_ADDRESS))
#define treadmill_roller_part_sprites_ADDRESS 0x010C4Bu
#define treadmill_roller_part_sprites ((const u16le *)rom(treadmill_roller_part_sprites_ADDRESS))
#define flame_jet_nozzle_sprites_ADDRESS 0x010FDAu
#define flame_jet_nozzle_sprites ((const u16le *)rom(flame_jet_nozzle_sprites_ADDRESS))
#define flame_jet_flame_sprites_ADDRESS 0x0111A5u
#define flame_jet_flame_sprites ((const u16le *)rom(flame_jet_flame_sprites_ADDRESS))
#define push_crate_break_sprites_ADDRESS 0x0113F9u
#define push_crate_break_sprites ((const u16le *)rom(push_crate_break_sprites_ADDRESS))
#define push_crate_push_angles_ADDRESS 0x0113FFu
#define push_crate_push_angles ((const u32le *)rom(push_crate_push_angles_ADDRESS))
#define ice_launcher_sprites_ADDRESS 0x011E18u
#define ice_launcher_sprites ((const u16le *)rom(ice_launcher_sprites_ADDRESS))
#define ice_launcher_frame_durations_ADDRESS 0x011E34u
#define ice_launcher_frame_durations ((const u16le *)rom(ice_launcher_frame_durations_ADDRESS))
#define ice_cube_speeds_ADDRESS 0x011E3Eu
#define ice_cube_speeds ((const u16le *)rom(ice_cube_speeds_ADDRESS))
#define ice_launcher_frames_ADDRESS 0x011E48u
#define ice_launcher_frames ((const uint8_t *)rom(ice_launcher_frames_ADDRESS))
#define wall_pad_frames_ADDRESS 0x01205Bu
#define wall_pad_frames ((const uint8_t *)rom(wall_pad_frames_ADDRESS))
#define wall_pad_sprites_ADDRESS 0x012066u
#define wall_pad_sprites ((const u16le *)rom(wall_pad_sprites_ADDRESS))
#define wall_pad_frame_durations_ADDRESS 0x012070u
#define wall_pad_frame_durations ((const u16le *)rom(wall_pad_frame_durations_ADDRESS))
#define whirlwind_sprites_ADDRESS 0x0122F1u
#define whirlwind_sprites ((const u16le *)rom(whirlwind_sprites_ADDRESS))
#define whirlwind_vanish_sprites_ADDRESS 0x0122F9u
#define whirlwind_vanish_sprites ((const u16le *)rom(whirlwind_vanish_sprites_ADDRESS))
#define centipede_head_frames_ADDRESS 0x012726u
#define centipede_head_frames ((const u16le *)rom(centipede_head_frames_ADDRESS))
#define sand_puff_frames_ADDRESS 0x012736u
#define sand_puff_frames ((const u16le *)rom(sand_puff_frames_ADDRESS))
#define centipede_tail_frames_ADDRESS 0x01273Cu
#define centipede_tail_frames ((const u16le *)rom(centipede_tail_frames_ADDRESS))
#define crawler_head_frames_ADDRESS 0x012AD0u
#define crawler_head_frames ((const u16le *)rom(crawler_head_frames_ADDRESS))
#define crawler_tail_frames_ADDRESS 0x012AD4u
#define crawler_tail_frames ((const u16le *)rom(crawler_tail_frames_ADDRESS))
#define crawler_segment_frames_ADDRESS 0x012AE4u
#define crawler_segment_frames ((const u16le *)rom(crawler_segment_frames_ADDRESS))
#define eggman_booth_frames_ADDRESS 0x012C35u
#define eggman_booth_frames ((const u16le *)rom(eggman_booth_frames_ADDRESS))
#define eggman_booth_frame_durations_ADDRESS 0x012C53u
#define eggman_booth_frame_durations ((const uint8_t *)rom(eggman_booth_frame_durations_ADDRESS))
#define eggman_booth_steps_ADDRESS 0x012C62u
#define eggman_booth_steps ((const uint8_t *)rom(eggman_booth_steps_ADDRESS))
#define wall_piece_frames_ADDRESS 0x012CFCu
#define wall_piece_frames ((const u16le *)rom(wall_piece_frames_ADDRESS))
#define shaking_block_frames_ADDRESS 0x012E3Cu
#define shaking_block_frames ((const u16le *)rom(shaking_block_frames_ADDRESS))
#define sand_rock_crumble_frames_ADDRESS 0x012F9Du
#define sand_rock_crumble_frames ((const u16le *)rom(sand_rock_crumble_frames_ADDRESS))
#define snow_mound_burst_frames_ADDRESS 0x0131E9u
#define snow_mound_burst_frames ((const u16le *)rom(snow_mound_burst_frames_ADDRESS))
#define rock_wall_break_frames_ADDRESS 0x0133AFu
#define rock_wall_break_frames ((const u16le *)rom(rock_wall_break_frames_ADDRESS))
#define rock_wall_sparkle_frames_ADDRESS 0x0133CBu
#define rock_wall_sparkle_frames ((const u16le *)rom(rock_wall_sparkle_frames_ADDRESS))
#define rock_wall_glint_steps_ADDRESS 0x0133FFu
#define rock_wall_glint_steps ((const uint8_t *)rom(rock_wall_glint_steps_ADDRESS))
#define rock_wall_glint_frames_ADDRESS 0x013413u
#define rock_wall_glint_frames ((const u16le *)rom(rock_wall_glint_frames_ADDRESS))
#define eggman_teleport_steps_ADDRESS 0x0134E5u
#define eggman_teleport_steps ((const uint8_t *)rom(eggman_teleport_steps_ADDRESS))
#define eggman_teleport_frames_ADDRESS 0x013541u
#define eggman_teleport_frames ((const u16le *)rom(eggman_teleport_frames_ADDRESS))
#define eggman_teleport_durations_ADDRESS 0x013581u
#define eggman_teleport_durations ((const u16le *)rom(eggman_teleport_durations_ADDRESS))
#define sand_arch_spray_frames_ADDRESS 0x0138BDu
#define sand_arch_spray_frames ((const u16le *)rom(sand_arch_spray_frames_ADDRESS))
#define fence_arc_flags_ADDRESS 0x013A8Du
#define fence_arc_flags ((const u16le *)rom(fence_arc_flags_ADDRESS))
#define fence_arc_frames_ADDRESS 0x013AA5u
#define fence_arc_frames ((const u16le *)rom(fence_arc_frames_ADDRESS))
#define mine_bubble_frames_ADDRESS 0x013B3Fu
#define mine_bubble_frames ((const u16le *)rom(mine_bubble_frames_ADDRESS))
#define mine_bubble_frames_2_ADDRESS 0x013B67u
#define mine_bubble_frames_2 ((const u16le *)rom(mine_bubble_frames_2_ADDRESS))
#define mine_sink_steps_ADDRESS 0x013EC7u
#define mine_sink_steps ((const uint8_t *)rom(mine_sink_steps_ADDRESS))
#define mine_frames_ADDRESS 0x013ECFu
#define mine_frames ((const u16le *)rom(mine_frames_ADDRESS))
#define underwater_explosion_frames_ADDRESS 0x013ED9u
#define underwater_explosion_frames ((const u16le *)rom(underwater_explosion_frames_ADDRESS))
#define underwater_explosion_durations_ADDRESS 0x013F05u
#define underwater_explosion_durations ((const uint8_t *)rom(underwater_explosion_durations_ADDRESS))
#define mine_flash_steps_ADDRESS 0x013F1Bu
#define mine_flash_steps ((const uint8_t *)rom(mine_flash_steps_ADDRESS))
#define mine_flash_palettes_ADDRESS 0x013F27u
#define mine_flash_palettes ((const u16le *)rom(mine_flash_palettes_ADDRESS))
#define mine_splash_frames_ADDRESS 0x013FF8u
#define mine_splash_frames ((const u16le *)rom(mine_splash_frames_ADDRESS))
#define mine_splash_spray_frames_ADDRESS 0x01402Cu
#define mine_splash_spray_frames ((const u16le *)rom(mine_splash_spray_frames_ADDRESS))
#define eggman_talk_steps_ADDRESS 0x014255u
#define eggman_talk_steps ((const uint8_t *)rom(eggman_talk_steps_ADDRESS))
#define eggman_press_durations_ADDRESS 0x01425Fu
#define eggman_press_durations ((const u16le *)rom(eggman_press_durations_ADDRESS))
#define eggman_talk_frames_ADDRESS 0x01426Du
#define eggman_talk_frames ((const u16le *)rom(eggman_talk_frames_ADDRESS))
#define eggman_press_frames_ADDRESS 0x014273u
#define eggman_press_frames ((const u16le *)rom(eggman_press_frames_ADDRESS))
#define eggman_run_frames_ADDRESS 0x014281u
#define eggman_run_frames ((const u16le *)rom(eggman_run_frames_ADDRESS))
#define eggman_scene_texts_ADDRESS 0x014291u
#define eggman_scene_texts ((const uint8_t *)rom(eggman_scene_texts_ADDRESS))
#define eggman_scene_text_durations_ADDRESS 0x014294u
#define eggman_scene_text_durations ((const u16le *)rom(eggman_scene_text_durations_ADDRESS))
#define eggman_scene_sounds_ADDRESS 0x01429Au
#define eggman_scene_sounds ((const u16le *)rom(eggman_scene_sounds_ADDRESS))
#define button_box_steps_ADDRESS 0x014345u
#define button_box_steps ((const uint8_t *)rom(button_box_steps_ADDRESS))
#define button_box_durations_ADDRESS 0x014368u
#define button_box_durations ((const u16le *)rom(button_box_durations_ADDRESS))
#define button_box_frames_ADDRESS 0x0143AEu
#define button_box_frames ((const u16le *)rom(button_box_frames_ADDRESS))
#define lid_trap_close_steps_ADDRESS 0x014647u
#define lid_trap_close_steps ((const uint8_t *)rom(lid_trap_close_steps_ADDRESS))
#define lid_trap_lid_frames_ADDRESS 0x01464Bu
#define lid_trap_lid_frames ((const u16le *)rom(lid_trap_lid_frames_ADDRESS))
#define turtle_swim_frames_ADDRESS 0x014917u
#define turtle_swim_frames ((const u16le *)rom(turtle_swim_frames_ADDRESS))
#define turtle_head_steps_ADDRESS 0x014937u
#define turtle_head_steps ((const uint8_t *)rom(turtle_head_steps_ADDRESS))
#define turtle_head_frames_ADDRESS 0x014947u
#define turtle_head_frames ((const u16le *)rom(turtle_head_frames_ADDRESS))
#define turtle_swim_speeds_ADDRESS 0x014951u
#define turtle_swim_speeds ((const u16le *)rom(turtle_swim_speeds_ADDRESS))
#define eel_head_frames_ADDRESS 0x014FB8u
#define eel_head_frames ((const u16le *)rom(eel_head_frames_ADDRESS))
#define eel_head_retract_frames_ADDRESS 0x014FBEu
#define eel_head_retract_frames ((const u16le *)rom(eel_head_retract_frames_ADDRESS))
#define eel_head_extend_frames_ADDRESS 0x014FC6u
#define eel_head_extend_frames ((const u16le *)rom(eel_head_extend_frames_ADDRESS))
#define eel_part_frames_ADDRESS 0x014FCCu
#define eel_part_frames ((const u16le *)rom(eel_part_frames_ADDRESS))
#define eel_part_steps_ADDRESS 0x01500Au
#define eel_part_steps ((const uint8_t *)rom(eel_part_steps_ADDRESS))
#define eel_part_frames_2_ADDRESS 0x015022u
#define eel_part_frames_2 ((const u16le *)rom(eel_part_frames_2_ADDRESS))
#define breakable_panel_break_frames_ADDRESS 0x015180u
#define breakable_panel_break_frames ((const u16le *)rom(breakable_panel_break_frames_ADDRESS))
#define breakable_panel_glow_steps_ADDRESS 0x0151A2u
#define breakable_panel_glow_steps ((const uint8_t *)rom(breakable_panel_glow_steps_ADDRESS))
#define breakable_panel_glow_palettes_ADDRESS 0x0151BFu
#define breakable_panel_glow_palettes ((const u16le *)rom(breakable_panel_glow_palettes_ADDRESS))
#define white_puff_frames_ADDRESS 0x015239u
#define white_puff_frames ((const u16le *)rom(white_puff_frames_ADDRESS))
#define checker_pad_frames_ADDRESS 0x0152A0u
#define checker_pad_frames ((const u16le *)rom(checker_pad_frames_ADDRESS))
#define static_triangle_frames_ADDRESS 0x01533Bu
#define static_triangle_frames ((const u16le *)rom(static_triangle_frames_ADDRESS))
#define eel_den_collapse_frames_ADDRESS 0x015814u
#define eel_den_collapse_frames ((const u16le *)rom(eel_den_collapse_frames_ADDRESS))
#define stage_block_map_widths_ADDRESS 0x017C49u
#define stage_block_map_widths ((const uint8_t *)rom(stage_block_map_widths_ADDRESS))
#define stage_block_maps_ADDRESS 0x017C5Cu
#define stage_block_maps ((const u16le *)rom(stage_block_maps_ADDRESS))
#define stage_section_directions_x_ADDRESS 0x01884Au
#define stage_section_directions_x ((const u16le *)rom(stage_section_directions_x_ADDRESS))
#define stage_section_directions_y_ADDRESS 0x018870u
#define stage_section_directions_y ((const u16le *)rom(stage_section_directions_y_ADDRESS))
#define stage_section_limits_x_ADDRESS 0x018DFAu
#define stage_section_limits_x ((const u16le *)rom(stage_section_limits_x_ADDRESS))
#define stage_section_limits_y_ADDRESS 0x018E20u
#define stage_section_limits_y ((const u16le *)rom(stage_section_limits_y_ADDRESS))
#define stage_section_ends_ADDRESS 0x0193E0u
#define stage_section_ends ((const u16le *)rom(stage_section_ends_ADDRESS))
#define stage_scroll_ends_ADDRESS 0x0196ECu
#define stage_scroll_ends ((const u16le *)rom(stage_scroll_ends_ADDRESS))
#define stage_initial_tile_sets_ADDRESS 0x019712u
#define stage_initial_tile_sets ((const u16le *)rom(stage_initial_tile_sets_ADDRESS))
#define stage_camera_origins_x_ADDRESS 0x01975Au
#define stage_camera_origins_x ((const s16le *)rom(stage_camera_origins_x_ADDRESS))
#define stage_camera_origins_y_ADDRESS 0x019780u
#define stage_camera_origins_y ((const s16le *)rom(stage_camera_origins_y_ADDRESS))
#define stage_view_offsets_x_ADDRESS 0x0197A6u
#define stage_view_offsets_x ((const u16le *)rom(stage_view_offsets_x_ADDRESS))
#define stage_view_offsets_y_ADDRESS 0x0197CCu
#define stage_view_offsets_y ((const u16le *)rom(stage_view_offsets_y_ADDRESS))
#define stage_scroll_modes_ADDRESS 0x0197F2u
#define stage_scroll_modes ((const u16le *)rom(stage_scroll_modes_ADDRESS))
#define stage_fast_scroll_ranges_ADDRESS 0x01A128u
#define stage_fast_scroll_ranges ((const u16le *)rom(stage_fast_scroll_ranges_ADDRESS))
#define stage_section_speeds_ADDRESS 0x01A162u
#define stage_section_speeds ((const u16le *)rom(stage_section_speeds_ADDRESS))
#define stage_section_follow_speeds_ADDRESS 0x01A565u
#define stage_section_follow_speeds ((const u16le *)rom(stage_section_follow_speeds_ADDRESS))
#define stage_section_unused_ADDRESS 0x01A667u
#define stage_section_unused ((const u32le *)rom(stage_section_unused_ADDRESS))
#define stage_tile_sets_ADDRESS 0x01A695u
#define stage_tile_sets ((const u32le *)rom(stage_tile_sets_ADDRESS))
#define scroll_skip_value_lists_ADDRESS 0x01AD04u
#define scroll_skip_value_lists ((const u32le *)rom(scroll_skip_value_lists_ADDRESS))
#define scroll_skip_last_points_ADDRESS 0x01AD10u
#define scroll_skip_last_points ((const u16le *)rom(scroll_skip_last_points_ADDRESS))
#define stage_palette_sets_ADDRESS 0x01B174u
#define stage_palette_sets ((const u32le *)rom(stage_palette_sets_ADDRESS))
#define stage_tile_bank_bits_ADDRESS 0x01B1C0u
#define stage_tile_bank_bits ROM8(stage_tile_bank_bits_ADDRESS)
#define stage_layer_priorities_ADDRESS 0x01B231u
#define stage_layer_priorities ROM8(stage_layer_priorities_ADDRESS)
#define stage_layer_disables_ADDRESS 0x01B27Du
#define stage_layer_disables ((const uint8_t *)rom(stage_layer_disables_ADDRESS))
#define stage_rowscroll_settings_ADDRESS 0x01B290u
#define stage_rowscroll_settings ((const u16le *)rom(stage_rowscroll_settings_ADDRESS))
#define stage_nbg3_widths_ADDRESS 0x01BADAu
#define stage_nbg3_widths ((const uint8_t *)rom(stage_nbg3_widths_ADDRESS))
#define stage_nbg3_block_maps_ADDRESS 0x01BAEDu
#define stage_nbg3_block_maps ((const u32le *)rom(stage_nbg3_block_maps_ADDRESS))
#define ending_road_frames_ADDRESS 0x01C825u
#define ending_road_frames ((const u16le *)rom(ending_road_frames_ADDRESS))
#define stage_template_spawns_ADDRESS 0x01F206u
#define stage_template_spawns ((const u16le *)rom(stage_template_spawns_ADDRESS))
#define stage_object_templates_ADDRESS 0x01F4D2u
#define stage_object_templates ROM16(stage_object_templates_ADDRESS)
#define stage_template_0_sprite_frame_ADDRESS 0x01F4D4u
#define stage_template_0_sprite_frame ROM16(stage_template_0_sprite_frame_ADDRESS)
#define stage_template_0_sprite_palette_ADDRESS 0x01F4D6u
#define stage_template_0_sprite_palette ROM16(stage_template_0_sprite_palette_ADDRESS)
#define stage_template_0_hitbox_size_ADDRESS 0x01F4D8u
#define stage_template_0_hitbox_size ROM16(stage_template_0_hitbox_size_ADDRESS)
#define stage_template_0_animation_speed_ADDRESS 0x01F4DCu
#define stage_template_0_animation_speed ROM8(stage_template_0_animation_speed_ADDRESS)
#define stage_template_0_animation_timer_ADDRESS 0x01F4DDu
#define stage_template_0_animation_timer ROM8(stage_template_0_animation_timer_ADDRESS)
#define stage_template_0_animation_frame_ADDRESS 0x01F4DEu
#define stage_template_0_animation_frame ROM8(stage_template_0_animation_frame_ADDRESS)
#define stage_template_0_kind_ADDRESS 0x01F4DFu
#define stage_template_0_kind ROM8(stage_template_0_kind_ADDRESS)
#define stage_template_0_animation_ADDRESS 0x01F4E0u
#define stage_template_0_animation ROM32(stage_template_0_animation_ADDRESS)
#define stage_template_0_handler_ADDRESS 0x01F4E4u
#define stage_template_0_handler ROM32(stage_template_0_handler_ADDRESS)
#define stage_template_0_offset_x_ADDRESS 0x01F4E8u
#define stage_template_0_offset_x ROM8(stage_template_0_offset_x_ADDRESS)
#define stage_template_0_offset_y_ADDRESS 0x01F4E9u
#define stage_template_0_offset_y ROM8(stage_template_0_offset_y_ADDRESS)
#define stage_template_0_hitbox_height_ADDRESS 0x01F4EAu
#define stage_template_0_hitbox_height ROM16(stage_template_0_hitbox_height_ADDRESS)
#define stage_spawns_by_handler_ADDRESS 0x081224u
#define stage_spawns_by_handler ((const u16le *)rom(stage_spawns_by_handler_ADDRESS))
#define spiked_roller_kinds_ADDRESS 0x082066u
#define spiked_roller_kinds ((const u16le *)rom(spiked_roller_kinds_ADDRESS))
#define spiked_roller_layouts_ADDRESS 0x08219Cu
#define spiked_roller_layouts ROM8(spiked_roller_layouts_ADDRESS)
#define spiked_roller_part_frames_ADDRESS 0x0821DCu
#define spiked_roller_part_frames ROM8(spiked_roller_part_frames_ADDRESS)
#define catapult_launch_delays_ADDRESS 0x08224Au
#define catapult_launch_delays ((const u16le *)rom(catapult_launch_delays_ADDRESS))
#define spiked_roller_frames_ADDRESS 0x0822D2u
#define spiked_roller_frames ((const u16le *)rom(spiked_roller_frames_ADDRESS))
#define spiked_roller_animation_speeds_ADDRESS 0x0822E4u
#define spiked_roller_animation_speeds ((const uint8_t *)rom(spiked_roller_animation_speeds_ADDRESS))
#define spiked_roller_event_coords_ADDRESS 0x082302u
#define spiked_roller_event_coords ((const u16le *)rom(spiked_roller_event_coords_ADDRESS))
#define spiked_roller_events_ADDRESS 0x082306u
#define spiked_roller_events ((const u16le *)rom(spiked_roller_events_ADDRESS))
#define roller_wall_fragment_count_ADDRESS 0x08234Cu
#define roller_wall_fragment_count ROM16(roller_wall_fragment_count_ADDRESS)
#define spiked_roller_rumble_delays_ADDRESS 0x082396u
#define spiked_roller_rumble_delays ((const uint8_t *)rom(spiked_roller_rumble_delays_ADDRESS))
#define fireball_emitter_lists_ADDRESS 0x083185u
#define fireball_emitter_lists ((const u16le *)rom(fireball_emitter_lists_ADDRESS))
#define fireball_types_ADDRESS 0x0832B9u
#define fireball_types ROM16(fireball_types_ADDRESS)
#define door_fragments_ADDRESS 0x08334Fu
#define door_fragments ROM16(door_fragments_ADDRESS)
#define object_steps_ADDRESS 0x08340Du
#define object_steps ((const u16le *)rom(object_steps_ADDRESS))
#define floor_sign_sprites_ADDRESS 0x084FA7u
#define floor_sign_sprites ((const u16le *)rom(floor_sign_sprites_ADDRESS))
#define bubble_heights_ADDRESS 0x08518Du
#define bubble_heights ((const u16le *)rom(bubble_heights_ADDRESS))
#define pacer_end_positions_ADDRESS 0x08519Bu
#define pacer_end_positions ((const u16le *)rom(pacer_end_positions_ADDRESS))
#define spawns_with_next_handler_ADDRESS 0x08530Du
#define spawns_with_next_handler ROM16(spawns_with_next_handler_ADDRESS)
#define fire_vent_blast_palettes_ADDRESS 0x085CF7u
#define fire_vent_blast_palettes ((const u16le *)rom(fire_vent_blast_palettes_ADDRESS))
#define scenery_sprite_kinds_ADDRESS 0x085D1Fu
#define scenery_sprite_kinds ((const u16le *)rom(scenery_sprite_kinds_ADDRESS))
#define eggman_speech_scripts_ADDRESS 0x085DE3u
#define eggman_speech_scripts ((const u16le *)rom(eggman_speech_scripts_ADDRESS))
#define ram_target_debris_count_ADDRESS 0x085ED3u
#define ram_target_debris_count ROM16(ram_target_debris_count_ADDRESS)
#define group_leader_hold_records_ADDRESS 0x085F4Du
#define group_leader_hold_records ((const u16le *)rom(group_leader_hold_records_ADDRESS))
#define burning_boulder_roll_rates_ADDRESS 0x087B79u
#define burning_boulder_roll_rates ((const uint8_t *)rom(burning_boulder_roll_rates_ADDRESS))
#define scene_carrier_records_ADDRESS 0x087BD9u
#define scene_carrier_records ((const u16le *)rom(scene_carrier_records_ADDRESS))
#define fire_trench_flame_heights_ADDRESS 0x087C43u
#define fire_trench_flame_heights ((const u16le *)rom(fire_trench_flame_heights_ADDRESS))
#define ember_emitter_end_positions_ADDRESS 0x087CD1u
#define ember_emitter_end_positions ((const u16le *)rom(ember_emitter_end_positions_ADDRESS))
#define lava_steam_puff_count_ADDRESS 0x087D4Fu
#define lava_steam_puff_count ROM16(lava_steam_puff_count_ADDRESS)
#define icicle_dropper_records_ADDRESS 0x088F35u
#define icicle_dropper_records ((const u16le *)rom(icicle_dropper_records_ADDRESS))
#define ice_floor_floors_ADDRESS 0x0890B9u
#define ice_floor_floors ((const u32le *)rom(ice_floor_floors_ADDRESS))
#define sand_stream_frames_ADDRESS 0x08A612u
#define sand_stream_frames ((const u16le *)rom(sand_stream_frames_ADDRESS))
#define tornado_column_top_frames_ADDRESS 0x08A6B4u
#define tornado_column_top_frames ((const u16le *)rom(tornado_column_top_frames_ADDRESS))
#define tornado_records_ADDRESS 0x08A6C0u
#define tornado_records ((const u16le *)rom(tornado_records_ADDRESS))
#define fire_front_paths_ADDRESS 0x08BDA1u
#define fire_front_paths ((const u16le *)rom(fire_front_paths_ADDRESS))
#define biting_head_paths_ADDRESS 0x08BE25u
#define biting_head_paths ((const u16le *)rom(biting_head_paths_ADDRESS))
#define biting_head_frames_ADDRESS 0x08BE5Fu
#define biting_head_frames ROM16(biting_head_frames_ADDRESS)
#define biting_head_move_frames_ADDRESS 0x08BE61u
#define biting_head_move_frames ROM16(biting_head_move_frames_ADDRESS)
#define biting_head_bite_steps_ADDRESS 0x08BE69u
#define biting_head_bite_steps ROM16(biting_head_bite_steps_ADDRESS)
#define biting_head_bounce_ADDRESS 0x08BEB5u
#define biting_head_bounce ((const int8_t *)rom(biting_head_bounce_ADDRESS))
#define brick_wall_bricks_ADDRESS 0x08BF01u
#define brick_wall_bricks ROM16(brick_wall_bricks_ADDRESS)
#define brick_wall_dust_ADDRESS 0x08BFABu
#define brick_wall_dust ROM16(brick_wall_dust_ADDRESS)
#define rising_saw_paths_ADDRESS 0x08C001u
#define rising_saw_paths ((const u16le *)rom(rising_saw_paths_ADDRESS))
#define grate_step_debris_ADDRESS 0x08C0E9u
#define grate_step_debris ROM16(grate_step_debris_ADDRESS)
#define geyser_row_patterns_ADDRESS 0x08D862u
#define geyser_row_patterns ((const u16le *)rom(geyser_row_patterns_ADDRESS))
#define geyser_fronts_ADDRESS 0x08D89Au
#define geyser_fronts ((const u16le *)rom(geyser_fronts_ADDRESS))
#define river_raft_spawners_ADDRESS 0x08D9AAu
#define river_raft_spawners ((const u16le *)rom(river_raft_spawners_ADDRESS))
#define river_raft_fall_palettes_ADDRESS 0x08DAE6u
#define river_raft_fall_palettes ((const u16le *)rom(river_raft_fall_palettes_ADDRESS))
#define player_block_offsets_ADDRESS 0x08E2D5u
#define player_block_offsets ((const u32le *)rom(player_block_offsets_ADDRESS))
#define distance_to_player_offsets_ADDRESS 0x08E2E1u
#define distance_to_player_offsets ((const u16le *)rom(distance_to_player_offsets_ADDRESS))
#define direction_to_player_offsets_ADDRESS 0x08E2E7u
#define direction_to_player_offsets ((const u16le *)rom(direction_to_player_offsets_ADDRESS))
#define explosion_frames_ADDRESS 0x08E4D2u
#define explosion_frames ((const u16le *)rom(explosion_frames_ADDRESS))
#define debris_frames_ADDRESS 0x08E87Eu
#define debris_frames ((const u16le *)rom(debris_frames_ADDRESS))
#define text_frames_ADDRESS 0x08E9C9u
#define text_frames ((const u16le *)rom(text_frames_ADDRESS))
#define ranking_initial_fields_ADDRESS 0x08EF7Fu
#define ranking_initial_fields ((const u16le *)rom(ranking_initial_fields_ADDRESS))
#define ranking_letter_sprites_ADDRESS 0x08EF85u
#define ranking_letter_sprites ((const u16le *)rom(ranking_letter_sprites_ADDRESS))
#define ranking_entry_x_ADDRESS 0x08EFDDu
#define ranking_entry_x ((const u16le *)rom(ranking_entry_x_ADDRESS))
#define ranking_entry_trackballs_ADDRESS 0x08EFE9u
#define ranking_entry_trackballs ((const u32le *)rom(ranking_entry_trackballs_ADDRESS))
#define ranking_entry_buttons_ADDRESS 0x08EFF5u
#define ranking_entry_buttons ((const uint8_t *)rom(ranking_entry_buttons_ADDRESS))
#define ranking_entry_blocks_ADDRESS 0x08F0CFu
#define ranking_entry_blocks ((const u32le *)rom(ranking_entry_blocks_ADDRESS))
#define default_ranking_ADDRESS 0x08F1B5u
#define default_ranking ROM8(default_ranking_ADDRESS)
#define ranking_portrait_frames_ADDRESS 0x08F876u
#define ranking_portrait_frames ((const u32le *)rom(ranking_portrait_frames_ADDRESS))
#define ranking_portrait_palettes_ADDRESS 0x08F972u
#define ranking_portrait_palettes ((const u16le *)rom(ranking_portrait_palettes_ADDRESS))
#define ranking_name_sprites_ADDRESS 0x08F978u
#define ranking_name_sprites ((const u16le *)rom(ranking_name_sprites_ADDRESS))
#define ranking_stage_sprites_ADDRESS 0x08F984u
#define ranking_stage_sprites ((const u16le *)rom(ranking_stage_sprites_ADDRESS))
#define chooser_idle_steps_ADDRESS 0x09031Du
#define chooser_idle_steps ((const uint8_t *)rom(chooser_idle_steps_ADDRESS))
#define chooser_portrait_frames_ADDRESS 0x090321u
#define chooser_portrait_frames ((const u16le *)rom(chooser_portrait_frames_ADDRESS))
#define chooser_portrait_palettes_ADDRESS 0x090339u
#define chooser_portrait_palettes ((const u16le *)rom(chooser_portrait_palettes_ADDRESS))
#define chooser_x_by_player_ADDRESS 0x09033Fu
#define chooser_x_by_player ((const u16le *)rom(chooser_x_by_player_ADDRESS))
#define chooser_trackball_offsets_ADDRESS 0x09034Bu
#define chooser_trackball_offsets ((const u16le *)rom(chooser_trackball_offsets_ADDRESS))
#define chooser_button_bits_ADDRESS 0x090351u
#define chooser_button_bits ((const uint8_t *)rom(chooser_button_bits_ADDRESS))
#define chooser_player_labels_ADDRESS 0x090357u
#define chooser_player_labels ((const u16le *)rom(chooser_player_labels_ADDRESS))
#define character_name_sprites_ADDRESS 0x09035Du
#define character_name_sprites ((const u16le *)rom(character_name_sprites_ADDRESS))
#define join_chooser_portraits_ADDRESS 0x090363u
#define join_chooser_portraits ((const u16le *)rom(join_chooser_portraits_ADDRESS))
#define join_chooser_palettes_ADDRESS 0x090369u
#define join_chooser_palettes ((const u16le *)rom(join_chooser_palettes_ADDRESS))
#define player_select_title_palettes_ADDRESS 0x09037Bu
#define player_select_title_palettes ((const u16le *)rom(player_select_title_palettes_ADDRESS))
#define join_chooser_blocks_ADDRESS 0x090395u
#define join_chooser_blocks ((const u32le *)rom(join_chooser_blocks_ADDRESS))
#define wall_spawns_ADDRESS 0x0903A2u
#define wall_spawns ((const u16le *)rom(wall_spawns_ADDRESS))
#define wall_kind_second_sprites_ADDRESS 0x090A84u
#define wall_kind_second_sprites ((const s16le *)rom(wall_kind_second_sprites_ADDRESS))
#define object_group_spawns_ADDRESS 0x0920F9u
#define object_group_spawns ((const u16le *)rom(object_group_spawns_ADDRESS))
#define stage_record_spawns_ADDRESS 0x093EC9u
#define stage_record_spawns ((const u16le *)rom(stage_record_spawns_ADDRESS))
#define stage_object_records_2_ADDRESS 0x093F59u
#define stage_object_records_2 ROM16(stage_object_records_2_ADDRESS)
#define rope_plank_frame_ADDRESS 0x093F5Bu
#define rope_plank_frame ROM16(rope_plank_frame_ADDRESS)
#define rope_plank_palette_ADDRESS 0x093F5Du
#define rope_plank_palette ROM16(rope_plank_palette_ADDRESS)
#define rope_plank_animation_ADDRESS 0x093F63u
#define rope_plank_animation ROM32(rope_plank_animation_ADDRESS)
#define rope_plank_animation_2_ADDRESS 0x093F67u
#define rope_plank_animation_2 ROM32(rope_plank_animation_2_ADDRESS)
#define rope_plank_hitbox_size_ADDRESS 0x093F6Bu
#define rope_plank_hitbox_size ROM16(rope_plank_hitbox_size_ADDRESS)
#define rope_bridge_rope_offsets_ADDRESS 0x094001u
#define rope_bridge_rope_offsets ROM16S(rope_bridge_rope_offsets_ADDRESS)
#define rope_bridge_rope_1_dy_ADDRESS 0x094003u
#define rope_bridge_rope_1_dy ROM16S(rope_bridge_rope_1_dy_ADDRESS)
#define rope_bridge_rope_2_dx_ADDRESS 0x094005u
#define rope_bridge_rope_2_dx ROM16S(rope_bridge_rope_2_dx_ADDRESS)
#define rope_bridge_rope_2_dy_ADDRESS 0x094007u
#define rope_bridge_rope_2_dy ROM16S(rope_bridge_rope_2_dy_ADDRESS)
#define wide_rope_bridge_rope_offsets_ADDRESS 0x094009u
#define wide_rope_bridge_rope_offsets ROM16S(wide_rope_bridge_rope_offsets_ADDRESS)
#define stage_00_rock_count_ADDRESS 0x0955A0u
#define stage_00_rock_count ROM16(stage_00_rock_count_ADDRESS)
#define stage_00_geyser_column_sprites_ADDRESS 0x095676u
#define stage_00_geyser_column_sprites ((const u16le *)rom(stage_00_geyser_column_sprites_ADDRESS))
#define falling_rock_count_ADDRESS 0x0956A8u
#define falling_rock_count ROM16(falling_rock_count_ADDRESS)
#define event_1a_first_scroll_mode_ADDRESS 0x095940u
#define event_1a_first_scroll_mode ROM16(event_1a_first_scroll_mode_ADDRESS)
#define event_1a_first_scroll_speed_ADDRESS 0x095942u
#define event_1a_first_scroll_speed ROM16(event_1a_first_scroll_speed_ADDRESS)
#define escape_countdown_digits_ADDRESS 0x095962u
#define escape_countdown_digits ((const u16le *)rom(escape_countdown_digits_ADDRESS))
#define window_wipe_default_left_ADDRESS 0x0967FBu
#define window_wipe_default_left ROM16(window_wipe_default_left_ADDRESS)
#define window_wipe_default_top_ADDRESS 0x096804u
#define window_wipe_default_top ROM16(window_wipe_default_top_ADDRESS)
#define map_number_badge_sprites_ADDRESS 0x096C21u
#define map_number_badge_sprites ((const u16le *)rom(map_number_badge_sprites_ADDRESS))
#define stage_map_markers_ADDRESS 0x096CB5u
#define stage_map_markers ((const uint8_t *)rom(stage_map_markers_ADDRESS))
#define stage_map_trails_ADDRESS 0x096CC8u
#define stage_map_trails ((const u32le *)rom(stage_map_trails_ADDRESS))
#define map_eggman_gesture_frames_ADDRESS 0x096D78u
#define map_eggman_gesture_frames ROM8S(map_eggman_gesture_frames_ADDRESS)
#define stage_map_icons_ADDRESS 0x096D87u
#define stage_map_icons ((const u16le *)rom(stage_map_icons_ADDRESS))
#define next_stage_map_icons_ADDRESS 0x096DA9u
#define next_stage_map_icons ((const u16le *)rom(next_stage_map_icons_ADDRESS))
#define stage_map_sounds_1_ADDRESS 0x096DCBu
#define stage_map_sounds_1 ((const uint8_t *)rom(stage_map_sounds_1_ADDRESS))
#define stage_map_sounds_2_ADDRESS 0x096DDDu
#define stage_map_sounds_2 ((const uint8_t *)rom(stage_map_sounds_2_ADDRESS))
#define stage_map_sounds_3_ADDRESS 0x096DEFu
#define stage_map_sounds_3 ((const uint8_t *)rom(stage_map_sounds_3_ADDRESS))
#define title_sonic_rise_heights_ADDRESS 0x096E0Fu
#define title_sonic_rise_heights ((const uint8_t *)rom(title_sonic_rise_heights_ADDRESS))
#define title_ray_frames_ADDRESS 0x097316u
#define title_ray_frames ((const u16le *)rom(title_ray_frames_ADDRESS))
#define title_mighty_frames_ADDRESS 0x097330u
#define title_mighty_frames ((const u16le *)rom(title_mighty_frames_ADDRESS))
#define stage_ring_bonus_percents_ADDRESS 0x09864Eu
#define stage_ring_bonus_percents ((const uint8_t *)rom(stage_ring_bonus_percents_ADDRESS))
#define stage_ring_counts_ADDRESS 0x09865Fu
#define stage_ring_counts ((const uint8_t *)rom(stage_ring_counts_ADDRESS))
#define ring_tally_blink_palettes_ADDRESS 0x098900u
#define ring_tally_blink_palettes ((const u16le *)rom(ring_tally_blink_palettes_ADDRESS))
#define percent_digit_sprites_ADDRESS 0x098908u
#define percent_digit_sprites ((const u16le *)rom(percent_digit_sprites_ADDRESS))
#define ring_tally_character_sounds_ADDRESS 0x098E7Du
#define ring_tally_character_sounds ((const uint8_t *)rom(ring_tally_character_sounds_ADDRESS))
#define ring_tally_backdrop_palettes_ADDRESS 0x098E80u
#define ring_tally_backdrop_palettes ((const u16le *)rom(ring_tally_backdrop_palettes_ADDRESS))
#define ring_tally_digits_ADDRESS 0x098E8Eu
#define ring_tally_digits ((const u16le *)rom(ring_tally_digits_ADDRESS))
#define ring_tally_portraits_ADDRESS 0x098EA2u
#define ring_tally_portraits ((const u32le *)rom(ring_tally_portraits_ADDRESS))
#define picture_chain_step_jumps_ADDRESS 0x099C6Au
#define picture_chain_step_jumps ((const u32le *)rom(picture_chain_step_jumps_ADDRESS))
#define angle_octants_ADDRESS 0x09A666u
#define angle_octants ((const u16le *)rom(angle_octants_ADDRESS))
#define video_register_defaults_ADDRESS 0x09A676u
#define video_register_defaults ROM16(video_register_defaults_ADDRESS)
#define attract_sound_mask_ADDRESS 0x09A692u
#define attract_sound_mask ((const u32le *)rom(attract_sound_mask_ADDRESS))
#define eeprom_defaults_ADDRESS 0x09C580u
#define eeprom_defaults ROM8(eeprom_defaults_ADDRESS)
#define ram_test_patterns_ADDRESS 0x09ED5Cu
#define ram_test_patterns ((const u32le *)rom(ram_test_patterns_ADDRESS))
#define rom_checksums_ADDRESS 0x09F08Cu
#define rom_checksums ROM16(rom_checksums_ADDRESS)
#define rom_checksum_ic8_ADDRESS 0x09F08Eu
#define rom_checksum_ic8 ROM16(rom_checksum_ic8_ADDRESS)
#define common_start_prompt_texts_ADDRESS 0x09FEDEu
#define common_start_prompt_texts ROM16(common_start_prompt_texts_ADDRESS)
#define start_prompt_texts_ADDRESS 0x09FEE6u
#define start_prompt_texts ROM16(start_prompt_texts_ADDRESS)
#define common_start_prompt_position_ADDRESS 0x09FFCCu
#define common_start_prompt_position ROM16(common_start_prompt_position_ADDRESS)
#define start_prompt_positions_3p_ADDRESS 0x09FFCEu
#define start_prompt_positions_3p ((const u16le *)rom(start_prompt_positions_3p_ADDRESS))
#define start_prompt_position_p2_ADDRESS 0x09FFD0u
#define start_prompt_position_p2 ROM16(start_prompt_position_p2_ADDRESS)
#define start_prompt_position_p3_ADDRESS 0x09FFD2u
#define start_prompt_position_p3 ROM16(start_prompt_position_p3_ADDRESS)
#define start_prompt_positions_2p_ADDRESS 0x09FFD4u
#define start_prompt_positions_2p ((const u16le *)rom(start_prompt_positions_2p_ADDRESS))
#define common_credit_position_ADDRESS 0x09FFD8u
#define common_credit_position ROM16(common_credit_position_ADDRESS)
#define credit_positions_3p_ADDRESS 0x09FFDAu
#define credit_positions_3p ((const u16le *)rom(credit_positions_3p_ADDRESS))
#define credit_position_p2_ADDRESS 0x09FFDCu
#define credit_position_p2 ROM16(credit_position_p2_ADDRESS)
#define credit_position_p3_ADDRESS 0x09FFDEu
#define credit_position_p3 ROM16(credit_position_p3_ADDRESS)
#define credit_positions_2p_ADDRESS 0x09FFE0u
#define credit_positions_2p ((const u16le *)rom(credit_positions_2p_ADDRESS))
#define stage_spawns_by_type_ADDRESS 0x100168u
#define stage_spawns_by_type ((const u32le *)rom(stage_spawns_by_type_ADDRESS))
#define sine_table_ADDRESS 0x101632u
#define sine_table ((const s16le *)rom(sine_table_ADDRESS))
#define cosine_table_ADDRESS 0x101832u
#define cosine_table ((const s16le *)rom(cosine_table_ADDRESS))
#define sine_of_300_ADDRESS 0x101C32u
#define sine_of_300 ROM16S(sine_of_300_ADDRESS)
#define cosine_of_300_ADDRESS 0x101E32u
#define cosine_of_300 ROM16S(cosine_of_300_ADDRESS)
#define angle_ratios_ADDRESS 0x102034u
#define angle_ratios ROM8(angle_ratios_ADDRESS)
#define fraction_slash_top_rows_ADDRESS 0x104BCAu
#define fraction_slash_top_rows ROM32(fraction_slash_top_rows_ADDRESS)
#define fraction_slash_bottom_rows_ADDRESS 0x104BCEu
#define fraction_slash_bottom_rows ROM32(fraction_slash_bottom_rows_ADDRESS)
#define stage_floor_blocks_ADDRESS 0x10B6CCu
#define stage_floor_blocks ((const u16le *)rom(stage_floor_blocks_ADDRESS))
#define floor_slope_factors_ADDRESS 0x10DF46u
#define floor_slope_factors ((const u32le *)rom(floor_slope_factors_ADDRESS))
#define floor_slope_direction_tables_ADDRESS 0x10DF4Au
#define floor_slope_direction_tables ((const u16le *)rom(floor_slope_direction_tables_ADDRESS))
#define floor_attribute_slopes_ADDRESS 0x10E150u
#define floor_attribute_slopes ((const s16le *)rom(floor_attribute_slopes_ADDRESS))
#define floor_attribute_wall_heights_ADDRESS 0x10E152u
#define floor_attribute_wall_heights ((const u16le *)rom(floor_attribute_wall_heights_ADDRESS))
#define stage_floor_block_bounds_ADDRESS 0x10E29Cu
#define stage_floor_block_bounds ((const u16le *)rom(stage_floor_block_bounds_ADDRESS))
#define sonic_bounce_records_ADDRESS 0x1139E8u
#define sonic_bounce_records ((const u16le *)rom(sonic_bounce_records_ADDRESS))
#define ray_bounce_records_ADDRESS 0x113A28u
#define ray_bounce_records ROM16(ray_bounce_records_ADDRESS)
#define mighty_bounce_records_ADDRESS 0x113A68u
#define mighty_bounce_records ROM16(mighty_bounce_records_ADDRESS)
#define sonic_stuck_struggle_animations_ADDRESS 0x113C3Au
#define sonic_stuck_struggle_animations ROM32(sonic_stuck_struggle_animations_ADDRESS)
#define ray_stuck_struggle_animations_ADDRESS 0x113C5Eu
#define ray_stuck_struggle_animations ROM32(ray_stuck_struggle_animations_ADDRESS)
#define mighty_stuck_struggle_animations_ADDRESS 0x113C82u
#define mighty_stuck_struggle_animations ROM32(mighty_stuck_struggle_animations_ADDRESS)
#define ledge_recover_headings_ADDRESS 0x113CD1u
#define ledge_recover_headings ((const u16le *)rom(ledge_recover_headings_ADDRESS))
#define screen_edge_scroll_carry_flags_ADDRESS 0x113CE7u
#define screen_edge_scroll_carry_flags ((const int8_t *)rom(screen_edge_scroll_carry_flags_ADDRESS))
#define player_palette_lists_ADDRESS 0x113D59u
#define player_palette_lists ((const u32le *)rom(player_palette_lists_ADDRESS))
#define floor_block_side_codes_ADDRESS 0x113E95u
#define floor_block_side_codes ((const uint8_t *)rom(floor_block_side_codes_ADDRESS))
#define heading_speed_factors_ADDRESS 0x113EC0u
#define heading_speed_factors ((const u16le *)rom(heading_speed_factors_ADDRESS))
#define max_health_by_setting_ADDRESS 0x113EF2u
#define max_health_by_setting ((const u16le *)rom(max_health_by_setting_ADDRESS))
#define hud_stage_rings_positions_ADDRESS 0x113F44u
#define hud_stage_rings_positions ((const u16le *)rom(hud_stage_rings_positions_ADDRESS))
#define floor_1_facing_bases_ADDRESS 0x113F4Au
#define floor_1_facing_bases ((const uint8_t *)rom(floor_1_facing_bases_ADDRESS))
#define fall_sprite_priorities_ADDRESS 0x113F7Fu
#define fall_sprite_priorities ROM8S(fall_sprite_priorities_ADDRESS)
#define hop_speeds_by_speed_ADDRESS 0x113F9Fu
#define hop_speeds_by_speed ((const s16le *)rom(hop_speeds_by_speed_ADDRESS))
#define hud_prompt_positions_3p_ADDRESS 0x113FB7u
#define hud_prompt_positions_3p ((const u16le *)rom(hud_prompt_positions_3p_ADDRESS))
#define hud_prompt_positions_2p_ADDRESS 0x113FBDu
#define hud_prompt_positions_2p ((const u16le *)rom(hud_prompt_positions_2p_ADDRESS))
#define hud_text_positions_3p_ADDRESS 0x113FEBu
#define hud_text_positions_3p ((const u16le *)rom(hud_text_positions_3p_ADDRESS))
#define hud_text_positions_2p_ADDRESS 0x113FF1u
#define hud_text_positions_2p ((const u16le *)rom(hud_text_positions_2p_ADDRESS))
#define opening_scene_player_positions_ADDRESS 0x11402Eu
#define opening_scene_player_positions ROM16(opening_scene_player_positions_ADDRESS)
#define player_state_stops_move_ADDRESS 0x114074u
#define player_state_stops_move ((const uint8_t *)rom(player_state_stops_move_ADDRESS))
#define stage_player_entries_ADDRESS 0x1140AEu
#define stage_player_entries ((const u16le *)rom(stage_player_entries_ADDRESS))
#define hud_continue_positions_3p_ADDRESS 0x114122u
#define hud_continue_positions_3p ((const u16le *)rom(hud_continue_positions_3p_ADDRESS))
#define hud_continue_positions_2p_ADDRESS 0x114128u
#define hud_continue_positions_2p ((const u16le *)rom(hud_continue_positions_2p_ADDRESS))
#define hud_game_over_positions_3p_ADDRESS 0x114158u
#define hud_game_over_positions_3p ((const u16le *)rom(hud_game_over_positions_3p_ADDRESS))
#define hud_game_over_positions_2p_ADDRESS 0x11415Eu
#define hud_game_over_positions_2p ((const u16le *)rom(hud_game_over_positions_2p_ADDRESS))
#define hud_ring_count_positions_3p_ADDRESS 0x114190u
#define hud_ring_count_positions_3p ((const u16le *)rom(hud_ring_count_positions_3p_ADDRESS))
#define hud_ring_count_positions_2p_ADDRESS 0x114196u
#define hud_ring_count_positions_2p ((const u16le *)rom(hud_ring_count_positions_2p_ADDRESS))
#define stage_goals_ADDRESS 0x11419Au
#define stage_goals ((const u16le *)rom(stage_goals_ADDRESS))
#define stage_goal_exit_paths_ADDRESS 0x1141A0u
#define stage_goal_exit_paths ((const uint8_t *)rom(stage_goal_exit_paths_ADDRESS))
#define tumble_effect_y_offsets_ADDRESS 0x1142AEu
#define tumble_effect_y_offsets ((const u16le *)rom(tumble_effect_y_offsets_ADDRESS))
#define tumble_effect_depth_offsets_ADDRESS 0x1142C4u
#define tumble_effect_depth_offsets ((const s16le *)rom(tumble_effect_depth_offsets_ADDRESS))
#define sonic_trap_struggle_animations_ADDRESS 0x114AA0u
#define sonic_trap_struggle_animations ROM32(sonic_trap_struggle_animations_ADDRESS)
#define ray_trap_struggle_animations_ADDRESS 0x114AB0u
#define ray_trap_struggle_animations ROM32(ray_trap_struggle_animations_ADDRESS)
#define mighty_trap_struggle_animations_ADDRESS 0x114AC0u
#define mighty_trap_struggle_animations ROM32(mighty_trap_struggle_animations_ADDRESS)
#define stage_restart_points_ADDRESS 0x114B84u
#define stage_restart_points ((const u16le *)rom(stage_restart_points_ADDRESS))
#define player_path_offsets_ADDRESS 0x115528u
#define player_path_offsets ((const u16le *)rom(player_path_offsets_ADDRESS))
#define sound_commands_ADDRESS 0x115A32u
#define sound_commands ROM16(sound_commands_ADDRESS)
#define bookkeeping_defaults_ADDRESS 0x115B60u
#define bookkeeping_defaults ROM16(bookkeeping_defaults_ADDRESS)
#define starting_health_by_vitality_ADDRESS 0x115B92u
#define starting_health_by_vitality ((const uint8_t *)rom(starting_health_by_vitality_ADDRESS))
#define test_menu_cursor_positions_ADDRESS 0x115BA3u
#define test_menu_cursor_positions ROM8(test_menu_cursor_positions_ADDRESS)
#define game_assignments_cursor_positions_ADDRESS 0x115BBBu
#define game_assignments_cursor_positions ROM8(game_assignments_cursor_positions_ADDRESS)
#define coin_assignments_cursor_positions_ADDRESS 0x115BCCu
#define coin_assignments_cursor_positions ROM8(coin_assignments_cursor_positions_ADDRESS)
#define coin_manual_cursor_positions_ADDRESS 0x115BD7u
#define coin_manual_cursor_positions ROM8(coin_manual_cursor_positions_ADDRESS)
#define bookkeeping_cursor_positions_ADDRESS 0x115BE2u
#define bookkeeping_cursor_positions ROM8(bookkeeping_cursor_positions_ADDRESS)
#define backup_clear_cursor_positions_ADDRESS 0x115BE3u
#define backup_clear_cursor_positions ROM8(backup_clear_cursor_positions_ADDRESS)
#define test_cursor_arrow_ADDRESS 0x115CEBu
#define test_cursor_arrow ROM8(test_cursor_arrow_ADDRESS)
#define test_cursor_space_ADDRESS 0x115CEDu
#define test_cursor_space ROM8(test_cursor_space_ADDRESS)
#define crt_test_border_lines_ADDRESS 0x115D53u
#define crt_test_border_lines ROM16(crt_test_border_lines_ADDRESS)
#define cabinet_type_texts_ADDRESS 0x115F2Eu
#define cabinet_type_texts ((const u32le *)rom(cabinet_type_texts_ADDRESS))
#define vitality_setting_numbers_ADDRESS 0x115FC0u
#define vitality_setting_numbers ((const u16le *)rom(vitality_setting_numbers_ADDRESS))
#define credits_to_start_texts_ADDRESS 0x1161DDu
#define credits_to_start_texts ((const u32le *)rom(credits_to_start_texts_ADDRESS))
#define coins_per_credit_texts_ADDRESS 0x116422u
#define coins_per_credit_texts ((const u32le *)rom(coins_per_credit_texts_ADDRESS))
#define bonus_adder_texts_ADDRESS 0x1164BFu
#define bonus_adder_texts ((const u32le *)rom(bonus_adder_texts_ADDRESS))
#define coin_setting_texts_ADDRESS 0x116711u
#define coin_setting_texts ((const u32le *)rom(coin_setting_texts_ADDRESS))
#define coin_setting_texts_individual_ADDRESS 0x116779u
#define coin_setting_texts_individual ((const u32le *)rom(coin_setting_texts_individual_ADDRESS))
#define individual_coin_setting_numbers_ADDRESS 0x1167B5u
#define individual_coin_setting_numbers ((const uint8_t *)rom(individual_coin_setting_numbers_ADDRESS))
#define chute_1_credit_cell_positions_ADDRESS 0x116F2Du
#define chute_1_credit_cell_positions ROM8(chute_1_credit_cell_positions_ADDRESS)
#define chute_2_credit_cell_positions_ADDRESS 0x116F3Fu
#define chute_2_credit_cell_positions ROM8(chute_2_credit_cell_positions_ADDRESS)
#define input_test_bits_3p_ADDRESS 0x117080u
#define input_test_bits_3p ROM8(input_test_bits_3p_ADDRESS)
#define input_test_bits_2p_ADDRESS 0x117082u
#define input_test_bits_2p ROM8(input_test_bits_2p_ADDRESS)
#define input_test_bits_no_start_3p_ADDRESS 0x11708Au
#define input_test_bits_no_start_3p ROM8(input_test_bits_no_start_3p_ADDRESS)
#define input_test_bits_no_start_2p_ADDRESS 0x11708Bu
#define input_test_bits_no_start_2p ROM8(input_test_bits_no_start_2p_ADDRESS)
#define input_test_on_texts_3p_ADDRESS 0x117091u
#define input_test_on_texts_3p ROM32(input_test_on_texts_3p_ADDRESS)
#define input_test_on_texts_2p_ADDRESS 0x117099u
#define input_test_on_texts_2p ROM32(input_test_on_texts_2p_ADDRESS)
#define input_test_on_texts_no_start_3p_ADDRESS 0x1170B9u
#define input_test_on_texts_no_start_3p ROM32(input_test_on_texts_no_start_3p_ADDRESS)
#define input_test_on_texts_no_start_2p_ADDRESS 0x1170BDu
#define input_test_on_texts_no_start_2p ROM32(input_test_on_texts_no_start_2p_ADDRESS)
#define input_test_off_texts_3p_ADDRESS 0x1170D5u
#define input_test_off_texts_3p ROM32(input_test_off_texts_3p_ADDRESS)
#define input_test_off_texts_2p_ADDRESS 0x1170DDu
#define input_test_off_texts_2p ROM32(input_test_off_texts_2p_ADDRESS)
#define input_test_off_texts_no_start_3p_ADDRESS 0x1170FDu
#define input_test_off_texts_no_start_3p ROM32(input_test_off_texts_no_start_3p_ADDRESS)
#define input_test_off_texts_no_start_2p_ADDRESS 0x117101u
#define input_test_off_texts_no_start_2p ROM32(input_test_off_texts_no_start_2p_ADDRESS)
#define input_test_cursor_top_limits_ADDRESS 0x1171FDu
#define input_test_cursor_top_limits ROM16S(input_test_cursor_top_limits_ADDRESS)
#define input_test_cursor_bottom_limits_ADDRESS 0x117205u
#define input_test_cursor_bottom_limits ROM16S(input_test_cursor_bottom_limits_ADDRESS)
#define memory_test_good_offsets_ADDRESS 0x11775Au
#define memory_test_good_offsets ROM16(memory_test_good_offsets_ADDRESS)
#define memory_test_bad_offsets_ADDRESS 0x117780u
#define memory_test_bad_offsets ROM16(memory_test_bad_offsets_ADDRESS)
#define small_large_texts_ADDRESS 0x11786Du
#define small_large_texts ((const u32le *)rom(small_large_texts_ADDRESS))

/* the board's registers (read and written through the bus) */
#define memory_test_video_word 0x30CA50u
#define video_control 0x31FF00u
#define video_layer_disable 0x31FF02u
#define video_rowscroll_control 0x31FF04u
#define video_clip_select 0x31FF06u
#define nbg0_page_select 0x31FF40u
#define nbg2_page_select 0x31FF48u
#define nbg0_zoom_x 0x31FF50u
#define nbg0_zoom_y 0x31FF52u
#define nbg1_zoom_x 0x31FF54u
#define nbg1_zoom_y 0x31FF56u
#define video_text_control 0x31FF5Cu
#define video_backdrop_control 0x31FF5Eu
#define video_clip_1_left 0x31FF68u
#define video_clip_1_top 0x31FF6Au
#define video_clip_1_right 0x31FF6Cu
#define video_clip_1_bottom 0x31FF6Eu
#define video_bitmap_clip_left 0x31FF80u
#define video_bitmap_clip_top 0x31FF82u
#define video_bitmap_clip_right 0x31FF84u
#define video_bitmap_clip_bottom 0x31FF86u
#define video_bitmap_scroll_x 0x31FF88u
#define video_bitmap_scroll_y 0x31FF8Au
#define video_layer_opaque_flags 0x31FF8Fu
#define sprite_list_jump 0x400010u
#define sprite_status 0x500002u
#define sprite_flip 0x500004u
#define sprite_wide_screen 0x50000Cu
#define palette_color_4000 0x608000u
#define backdrop_color 0x609400u
#define palette_color_61D0 0x60C3A0u
#define mixer_nbg0 0x610022u
#define mixer_nbg3 0x610028u
#define mixer_bitmap 0x61002Au
#define sound_command 0x700700u
#define sound_command_group 0x700701u
#define bookkeeping_checksum 0x701F00u
#define bookkeeping_coin_credits 0x701F02u
#define bookkeeping_service_credits 0x701F04u
#define bookkeeping_coin_chute_1 0x701F06u
#define bookkeeping_coin_chute_2 0x701F08u
#define bookkeeping_coin_chute_3 0x701F0Au
#define bookkeeping_games 0x701F0Cu
#define bookkeeping_longest_game 0x701F0Eu
#define bookkeeping_power_on_time 0x701F12u
#define bookkeeping_power_on_time_high 0x701F16u
#define bookkeeping_play_time 0x701F18u
#define bookkeeping_play_time_high 0x701F1Cu
#define bookkeeping_player_time 0x701F1Eu
#define bookkeeping_player_time_high 0x701F22u
#define bookkeeping_shortest_game 0x701F24u
#define bookkeeping_rom_stamp 0x701F28u
#define saved_credits 0x701F2Eu
#define bookkeeping_backup 0x701F42u
#define bookkeeping_backup_power_on_time 0x701F52u
#define bookkeeping_backup_power_on_time_high 0x701F56u
#define bookkeeping_backup_rom_stamp 0x701F68u
#define saved_credits_backup 0x701F6Eu
#define saved_ranking 0x701F82u
#define ranking_checksum 0x701FFAu
#define moving_seat_dip 0x701FFEu
#define sound_cpu_hold 0x701FFFu
#define io_port_a 0xC00000u
#define io_port_b 0xC00002u
#define io_port_c 0xC00004u
#define io_port_d 0xC00006u
#define io_port_e 0xC00008u
#define io_port_f 0xC0000Au
#define io_port_g 0xC0000Cu
#define io_port_h 0xC0000Eu
#define io_cnt 0xC0001Cu
#define io_direction 0xC0001Eu
#define cabinet_events 0xC00074u
#define irq_vectors 0xD00000u
#define irq_control_5 0xD00005u
#define irq_mask 0xD00006u
#define irq_acknowledge 0xD00007u
#define timer_0_reload 0xD00008u
#define timer_1_reload 0xD0000Au

/* data in the program ROM symbols.txt labels */
#define boot_e00000_values_ADDRESS 0x00007Eu
#define boot_irq_controller_values_ADDRESS 0x00008Eu
#define attract_mode_names_ADDRESS 0x00060Cu
#define title_copyright_text_ADDRESS 0x000644u
#define run_game_mode_padding_ADDRESS 0x000651u
#define player_objects_ADDRESS 0x002405u
#define player_objects_alt_ADDRESS 0x00241Fu
#define unused_002439_ADDRESS 0x002439u
#define bridge_sag_curve_ADDRESS 0x002471u
#define stage_08_events_ADDRESS 0x0024B8u
#define stage_04_events_ADDRESS 0x0024C6u
#define stage_05_events_ADDRESS 0x0024D0u
#define stage_06_events_ADDRESS 0x0024D6u
#define stage_03_events_ADDRESS 0x0024DCu
#define stage_09_events_ADDRESS 0x0024EEu
#define stage_0a_events_ADDRESS 0x0024FCu
#define stage_0b_events_ADDRESS 0x002502u
#define stage_0c_events_ADDRESS 0x002508u
#define stage_10_events_ADDRESS 0x00250Eu
#define stage_11_events_ADDRESS 0x002518u
#define stage_shared_events_ADDRESS 0x00251Eu
#define stage_01_link_point_ADDRESS 0x002546u
#define unused_game_mode_text_ADDRESS 0x00254Au
#define stage_select_mode_text_ADDRESS 0x00255Au
#define stage_number_text_ADDRESS 0x00256Du
#define unused_fence_set_mode_text_ADDRESS 0x002578u
#define unused_status_texts_ADDRESS 0x002588u
#define continue_text_ADDRESS 0x0025C2u
#define game_over_string_ADDRESS 0x0025D0u
#define unused_to_be_continued_string_ADDRESS 0x0025E2u
#define you_failed_string_ADDRESS 0x0025FAu
#define unused_00260D_ADDRESS 0x00260Du
#define stage_05_layer_blending_ADDRESS 0x0026BAu
#define stage_09_10_layer_blending_ADDRESS 0x0026C7u
#define stage_shared_layer_blending_ADDRESS 0x0026CEu
#define cleared_banner_animation_ADDRESS 0x0026F9u
#define stage_08_name_banner_ADDRESS 0x002707u
#define stage_03_name_banner_ADDRESS 0x002723u
#define stage_04_name_banner_ADDRESS 0x002739u
#define stage_09_name_banner_ADDRESS 0x002755u
#define stage_0a_name_banner_ADDRESS 0x002765u
#define stage_10_name_banner_ADDRESS 0x00277Fu
#define banner_letter_animation_ADDRESS 0x00279Du
#define banner_sparkle_animation_ADDRESS 0x0027BDu
#define unused_player_select_text_ADDRESS 0x0027E1u
#define player_state_out_of_game_padding_ADDRESS 0x005E23u
#define player_stage_exit_stage_4_padding_ADDRESS 0x007499u
#define player_state_scene_thrown_padding_ADDRESS 0x007C09u
#define player_effect_animation_ADDRESS 0x009BF7u
#define floor_8_idle_animation_sonic_ADDRESS 0x009C05u
#define floor_8_escape_animation_sonic_ADDRESS 0x009C13u
#define floor_8_idle_animation_ray_ADDRESS 0x009C1Du
#define floor_8_escape_animation_ray_ADDRESS 0x009C2Bu
#define floor_8_idle_animation_mighty_ADDRESS 0x009C35u
#define floor_8_escape_animation_mighty_ADDRESS 0x009C43u
#define flail_animation_sonic_ADDRESS 0x009C4Du
#define flail_animation_ray_ADDRESS 0x009C6Fu
#define flail_animation_mighty_ADDRESS 0x009C91u
#define object_climb_animation_sonic_ADDRESS 0x009CB3u
#define object_climb_animation_ray_2_ADDRESS 0x009CC1u
#define object_climb_animation_ray_ADDRESS 0x009CCFu
#define object_climb_animation_mighty_ADDRESS 0x009CDDu
#define player_state_held_still_padding_ADDRESS 0x009CEBu
#define move_object_to_next_stage_slot_padding_ADDRESS 0x00A607u
#define unused_hud_name_offsets_ADDRESS 0x00CD1Cu
#define hud_sonic_name_text_ADDRESS 0x00CD22u
#define hud_ray_name_text_ADDRESS 0x00CD29u
#define hud_mighty_name_text_ADDRESS 0x00CD2Fu
#define hud_gauge_ring_palettes_ADDRESS 0x00CD37u
#define hud_gauge_hit_palettes_ADDRESS 0x00CD4Du
#define hud_gauge_low_health_palettes_ADDRESS 0x00CD55u
#define hud_portrait_hurt_palettes_sonic_ADDRESS 0x00CD63u
#define hud_portrait_hurt_palettes_ray_ADDRESS 0x00CD6Bu
#define hud_portrait_hurt_palettes_mighty_ADDRESS 0x00CD73u
#define hud_portrait_low_health_palettes_sonic_ADDRESS 0x00CD7Bu
#define hud_portrait_low_health_palettes_ray_ADDRESS 0x00CD89u
#define hud_portrait_low_health_palettes_mighty_ADDRESS 0x00CD97u
#define hud_no_continue_text_ADDRESS 0x00CDA5u
#define climb_zone_effect_animation_ADDRESS 0x00E459u
#define unused_00E463_ADDRESS 0x00E463u
#define intro_marker_animation_ADDRESS 0x00E46Du
#define check_player_contacts_padding_ADDRESS 0x00E487u
#define unused_00F4AA_ADDRESS 0x00F4AAu
#define metal_wall_half_sprites_ADDRESS 0x00FB30u
#define metal_wall_half_offsets_ADDRESS 0x00FB40u
#define metal_wall_shadow_sprites_ADDRESS 0x00FB60u
#define metal_wall_shadow_offsets_ADDRESS 0x00FB70u
#define metal_wall_crack_sprites_ADDRESS 0x00FB90u
#define metal_wall_crack_offsets_ADDRESS 0x00FBA0u
#define fence_post_init_padding_ADDRESS 0x0138C5u
#define unused_014907_ADDRESS 0x014907u
#define init_stage_view_padding_ADDRESS 0x0158E1u
#define stage_10_block_map_ADDRESS 0x017C82u
#define stage_0f_block_map_ADDRESS 0x017D82u
#define stage_0e_block_map_ADDRESS 0x017DC2u
#define stage_0d_block_map_ADDRESS 0x017E02u
#define stage_0c_block_map_ADDRESS 0x017E42u
#define stage_0b_block_map_ADDRESS 0x017E82u
#define stage_0a_block_map_ADDRESS 0x017F82u
#define stage_09_block_map_ADDRESS 0x018082u
#define stage_08_block_map_ADDRESS 0x018182u
#define stage_03_07_block_map_ADDRESS 0x018382u
#define stage_04_block_map_ADDRESS 0x018582u
#define stage_00_block_map_ADDRESS 0x018682u
#define stage_05_06_block_map_ADDRESS 0x018782u
#define stage_01_02_11_12_block_map_ADDRESS 0x0187C2u
#define stage_10_section_directions_x_ADDRESS 0x018896u
#define stage_0b_section_directions_x_ADDRESS 0x0188CCu
#define stage_0c_0e_section_directions_x_ADDRESS 0x018904u
#define stage_0d_0f_section_directions_x_ADDRESS 0x01891Eu
#define stage_0a_section_directions_x_ADDRESS 0x01892Cu
#define stage_09_section_directions_x_ADDRESS 0x018994u
#define stage_08_section_directions_x_ADDRESS 0x0189FEu
#define stage_05_06_section_directions_x_ADDRESS 0x018A38u
#define stage_03_07_section_directions_x_ADDRESS 0x018A3Au
#define stage_00_section_directions_x_ADDRESS 0x018A72u
#define stage_01_02_11_12_section_directions_x_ADDRESS 0x018A8Eu
#define stage_04_section_directions_x_ADDRESS 0x018B1Cu
#define stage_10_section_directions_y_ADDRESS 0x018B48u
#define stage_0b_section_directions_y_ADDRESS 0x018B7Eu
#define stage_0c_0e_section_directions_y_ADDRESS 0x018BB6u
#define stage_0d_0f_section_directions_y_ADDRESS 0x018BD0u
#define stage_0a_section_directions_y_ADDRESS 0x018BDEu
#define stage_09_section_directions_y_ADDRESS 0x018C46u
#define stage_08_section_directions_y_ADDRESS 0x018CB0u
#define stage_05_06_section_directions_y_ADDRESS 0x018CEAu
#define stage_03_07_section_directions_y_ADDRESS 0x018CECu
#define stage_00_section_directions_y_ADDRESS 0x018D24u
#define stage_01_02_11_12_section_directions_y_ADDRESS 0x018D40u
#define stage_04_section_directions_y_ADDRESS 0x018DCEu
#define stage_10_section_limits_x_ADDRESS 0x018E46u
#define stage_0b_section_limits_x_ADDRESS 0x018E7Eu
#define stage_0c_0e_section_limits_x_ADDRESS 0x018EB8u
#define stage_0d_0f_section_limits_x_ADDRESS 0x018ED6u
#define stage_0a_section_limits_x_ADDRESS 0x018EE6u
#define stage_09_section_limits_x_ADDRESS 0x018F50u
#define stage_08_section_limits_x_ADDRESS 0x018FBCu
#define stage_05_06_section_limits_x_ADDRESS 0x018FF8u
#define stage_03_07_section_limits_x_ADDRESS 0x018FFCu
#define stage_00_section_limits_x_ADDRESS 0x019034u
#define stage_01_02_11_12_section_limits_x_ADDRESS 0x019052u
#define stage_04_section_limits_x_ADDRESS 0x0190E6u
#define stage_10_section_limits_y_ADDRESS 0x019114u
#define stage_0b_section_limits_y_ADDRESS 0x01914Cu
#define stage_0c_0e_section_limits_y_ADDRESS 0x019186u
#define stage_0d_0f_section_limits_y_ADDRESS 0x0191A2u
#define stage_0a_section_limits_y_ADDRESS 0x0191B2u
#define stage_09_section_limits_y_ADDRESS 0x01921Cu
#define stage_08_section_limits_y_ADDRESS 0x019288u
#define stage_05_06_section_limits_y_ADDRESS 0x0192C4u
#define stage_03_07_section_limits_y_ADDRESS 0x0192C8u
#define stage_00_section_limits_y_ADDRESS 0x019300u
#define stage_01_02_11_12_section_limits_y_ADDRESS 0x01931Eu
#define stage_04_section_limits_y_ADDRESS 0x0193B2u
#define stage_10_section_ends_ADDRESS 0x019406u
#define stage_0b_section_ends_ADDRESS 0x019440u
#define stage_0c_0e_section_ends_ADDRESS 0x01947Cu
#define stage_0d_0f_section_ends_ADDRESS 0x01949Au
#define stage_0a_section_ends_ADDRESS 0x0194ACu
#define stage_09_section_ends_ADDRESS 0x019518u
#define stage_08_section_ends_ADDRESS 0x019586u
#define stage_05_06_section_ends_ADDRESS 0x0195C4u
#define stage_03_07_section_ends_ADDRESS 0x0195CAu
#define stage_00_section_ends_ADDRESS 0x019606u
#define stage_01_11_section_ends_ADDRESS 0x019626u
#define stage_02_12_section_ends_ADDRESS 0x019678u
#define stage_04_section_ends_ADDRESS 0x0196BCu
#define stage_00_11_initial_tile_sets_ADDRESS 0x01973Au
#define stage_shared_initial_tile_sets_ADDRESS 0x01974Au
#define stage_10_scroll_modes_ADDRESS 0x019818u
#define stage_0f_scroll_modes_ADDRESS 0x019908u
#define stage_0e_scroll_modes_ADDRESS 0x019944u
#define stage_0d_scroll_modes_ADDRESS 0x019980u
#define stage_0c_scroll_modes_ADDRESS 0x0199BCu
#define stage_0b_scroll_modes_ADDRESS 0x0199F8u
#define stage_0a_scroll_modes_ADDRESS 0x019A70u
#define stage_09_scroll_modes_ADDRESS 0x019BD8u
#define stage_08_scroll_modes_ADDRESS 0x019CF0u
#define stage_05_06_scroll_modes_ADDRESS 0x019E58u
#define stage_shared_scroll_modes_ADDRESS 0x019E80u
#define stage_04_scroll_modes_ADDRESS 0x019F20u
#define stage_00_01_02_03_fast_scroll_ranges_ADDRESS 0x01A150u
#define stage_04_fast_scroll_ranges_ADDRESS 0x01A152u
#define stage_05_06_07_fast_scroll_ranges_ADDRESS 0x01A15Cu
#define stage_08_09_fast_scroll_ranges_ADDRESS 0x01A15Eu
#define stage_0a_to_13_fast_scroll_ranges_ADDRESS 0x01A160u
#define stage_10_section_speeds_ADDRESS 0x01A188u
#define stage_0f_section_speeds_ADDRESS 0x01A200u
#define stage_0e_section_speeds_ADDRESS 0x01A20Fu
#define stage_0d_section_speeds_ADDRESS 0x01A21Eu
#define stage_0c_section_speeds_ADDRESS 0x01A22Du
#define stage_0b_section_speeds_ADDRESS 0x01A23Cu
#define stage_0a_section_speeds_ADDRESS 0x01A25Au
#define stage_09_section_speeds_ADDRESS 0x01A2FAu
#define stage_08_section_speeds_ADDRESS 0x01A34Au
#define stage_05_06_section_speeds_ADDRESS 0x01A3F4u
#define stage_00_section_speeds_ADDRESS 0x01A407u
#define stage_01_02_11_12_section_speeds_ADDRESS 0x01A440u
#define stage_03_07_section_speeds_ADDRESS 0x01A4C5u
#define stage_04_section_speeds_ADDRESS 0x01A515u
#define unused_01A58B_ADDRESS 0x01A58Bu
#define stage_08_section_follow_speeds_ADDRESS 0x01A5BDu
#define stage_shared_section_follow_speeds_ADDRESS 0x01A5DBu
#define stage_04_section_follow_speeds_ADDRESS 0x01A617u
#define unused_01A653_ADDRESS 0x01A653u
#define stage_00_01_02_section_unused_ADDRESS 0x01A673u
#define run_scroll_skip_mode_padding_ADDRESS 0x01A797u
#define scroll_skip_panel_text_ADDRESS 0x01ABBAu
#define scroll_skip_blank_text_ADDRESS 0x01AC54u
#define nbg0_picture_palette_ADDRESS 0x01B154u
#define init_nbg2_layer_padding_ADDRESS 0x01B403u
#define stage_0a_nbg3_page_map_ADDRESS 0x01BB3Du
#define stage_04_nbg3_page_map_ADDRESS 0x01BBD2u
#define stage_0b_to_0f_nbg3_page_map_ADDRESS 0x01BBE2u
#define stage_shared_nbg3_page_map_ADDRESS 0x01BC64u
#define nbg3_quadrant_grid_ADDRESS 0x01BCBCu
#define build_ending_scene_padding_ADDRESS 0x01BCC5u
#define timed_spawns_2_ADDRESS 0x01C49Cu
#define ending_tower_frames_ADDRESS 0x01C4F8u
#define ending_dust_cloud_frames_ADDRESS 0x01C636u
#define ending_music_cues_ADDRESS 0x01C9CAu
#define credits_team_logo_parts_ADDRESS 0x01CC3Du
#define credits_director_parts_ADDRESS 0x01CD01u
#define credits_program_parts_ADDRESS 0x01CDEFu
#define credits_design_parts_ADDRESS 0x01CEFEu
#define credits_sound_parts_ADDRESS 0x01D004u
#define credits_voice_actor_parts_ADDRESS 0x01D113u
#define credits_special_thanks_parts_ADDRESS 0x01D25Du
#define ending_portrait_frames_ADDRESS 0x01D2E4u
#define ending_name_plate_frames_ADDRESS 0x01D2F4u
#define ending_portrait_palettes_ADDRESS 0x01D308u
#define ending_portrait_backdrop_palettes_ADDRESS 0x01D318u
#define timed_spawns_3_ADDRESS 0x01D372u
#define ending_eggman_turn_frames_ADDRESS 0x01D957u
#define ending_sonic_run_frames_ADDRESS 0x01E006u
#define ending_ray_run_frames_ADDRESS 0x01E020u
#define ending_mighty_run_frames_ADDRESS 0x01E03Au
#define ending_sonic_body_frames_ADDRESS 0x01E054u
#define ending_sonic_leg_frames_ADDRESS 0x01E058u
#define ending_ray_body_frames_ADDRESS 0x01E060u
#define ending_ray_leg_frames_ADDRESS 0x01E064u
#define ending_mighty_body_frames_ADDRESS 0x01E06Cu
#define ending_mighty_leg_frames_ADDRESS 0x01E070u
#define ending_debris_1_path_ADDRESS 0x01E078u
#define ending_debris_2_path_ADDRESS 0x01E10Eu
#define ending_debris_3_path_ADDRESS 0x01E194u
#define ending_tower_blast_frames_ADDRESS 0x01E22Au
#define ending_horizon_blast_frames_ADDRESS 0x01E254u
#define ending_big_explosion_frames_ADDRESS 0x01E282u
#define ending_big_explosion_frames_2_ADDRESS 0x01E300u
#define stage_shared_ring_rows_ADDRESS 0x01F22Cu
#define stage_04_ring_rows_ADDRESS 0x01F22Eu
#define stage_08_ring_rows_ADDRESS 0x01F2E4u
#define stage_03_ring_rows_ADDRESS 0x01F32Eu
#define stage_09_ring_rows_ADDRESS 0x01F36Cu
#define stage_01_02_0a_ring_rows_ADDRESS 0x01F3CEu
#define stage_10_ring_rows_ADDRESS 0x01F40Cu
#define stage_05_06_07_ring_rows_ADDRESS 0x01F46Eu
#define stage_0b_ring_rows_ADDRESS 0x01F470u
#define ring_animation_ADDRESS 0x01F56Eu
#define ring_glint_animation_ADDRESS 0x01F5ACu
#define ring_sparkle_animation_ADDRESS 0x01F5CEu
#define unused_01F5F0_ADDRESS 0x01F5F0u
#define low_code_chip_padding_ADDRESS 0x01F5F2u
#define catapult_x_animation_ADDRESS 0x0821E2u
#define catapult_y_animation_ADDRESS 0x0821FCu
#define object_pair_templates_ADDRESS 0x082250u
#define spiked_roller_animation_ADDRESS 0x0822D0u
#define unused_083108_ADDRESS 0x083108u
#define flame_animation_ADDRESS 0x083119u
#define fireball_animation_ADDRESS 0x083123u
#define blank_fireball_animation_ADDRESS 0x083329u
#define boulder_animation_ADDRESS 0x083335u
#define roller_back_zone_limits_ADDRESS 0x08341Fu
#define object_kinds_ADDRESS 0x084FB5u
#define sign_palette_lists_ADDRESS 0x08514Du
#define cage_bar_animation_ADDRESS 0x085171u
#define bubble_animation_ADDRESS 0x085179u
#define opening_ground_animation_ADDRESS 0x0851A3u
#define opening_machine_landed_animation_ADDRESS 0x0851AFu
#define opening_machine_fly_away_animation_ADDRESS 0x0851F9u
#define opening_machine_leap_animation_ADDRESS 0x085243u
#define how_to_play_button_hand_animation_ADDRESS 0x08526Du
#define how_to_play_button_hand_parts_ADDRESS 0x085277u
#define how_to_play_trackball_animation_ADDRESS 0x0852ADu
#define how_to_play_button_presses_ADDRESS 0x0852B7u
#define machine_animation_ADDRESS 0x0852D1u
#define machine_flame_animation_ADDRESS 0x0852DFu
#define machine_fire_script_ADDRESS 0x0852E9u
#define unused_chaser_path_ADDRESS 0x085347u
#define spawn_stage_03_end_pillar_padding_ADDRESS 0x08535Du
#define fire_vent_list_ADDRESS 0x085C33u
#define fire_vent_blast_animation_ADDRESS 0x085CB5u
#define fire_vent_glow_palettes_ADDRESS 0x085CDFu
#define ram_target_part_list_2_ADDRESS 0x085E53u
#define ram_target_part_list_3_ADDRESS 0x085E65u
#define scenery_sprite_palettes_ADDRESS 0x085E7Fu
#define ram_target_damage_script_ADDRESS 0x085E8Du
#define ram_target_animation_ADDRESS 0x085E9Fu
#define ram_target_debris_animations_ADDRESS 0x085F05u
#define collapsing_bridge_plank_animation_ADDRESS 0x087A91u
#define burning_boulder_flame_layout_ADDRESS 0x087AA3u
#define burning_boulder_flame_animations_ADDRESS 0x087ABBu
#define burning_boulder_roll_animation_ADDRESS 0x087B03u
#define falling_ember_speeds_ADDRESS 0x087B11u
#define falling_ember_animation_ADDRESS 0x087B21u
#define falling_ember_slope_burst_animation_ADDRESS 0x087B35u
#define falling_ember_burst_animation_ADDRESS 0x087B4Bu
#define burning_boulder_records_ADDRESS 0x087B61u
#define burning_boulder_speed_script_ADDRESS 0x087B7Fu
#define seesaw_parts_ADDRESS 0x087BABu
#define seesaw_animation_ADDRESS 0x087BC5u
#define fire_wall_parts_ADDRESS 0x087C31u
#define fire_trench_flame_animation_ADDRESS 0x087C89u
#define bridge_fire_script_ADDRESS 0x087CD9u
#define lava_flow_animation_ADDRESS 0x087D05u
#define lava_flow_parts_ADDRESS 0x087D0Fu
#define lava_flow_script_ADDRESS 0x087D21u
#define lava_steam_animation_ADDRESS 0x087D41u
#define lava_steam_puff_offsets_ADDRESS 0x087D51u
#define lava_flame_animation_ADDRESS 0x087D61u
#define lava_flame_animation_2_ADDRESS 0x087D6Fu
#define fire_wall_animation_ADDRESS 0x087D7Du
#define icicle_dropper_scripts_ADDRESS 0x088FC1u
#define icicle_crack_animation_ADDRESS 0x0890C1u
#define sand_face_animation_ADDRESS 0x08A5FCu
#define sand_face_fall_animation_ADDRESS 0x08A606u
#define sand_face_parts_ADDRESS 0x08A61Au
#define sand_stream_parts_ADDRESS 0x08A62Cu
#define sinkhole_animation_ADDRESS 0x08A65Eu
#define rimmed_sinkhole_animation_ADDRESS 0x08A666u
#define sinkhole_growth_records_ADDRESS 0x08A66Eu
#define quicksand_palettes_ADDRESS 0x08A686u
#define tornado_column_animation_ADDRESS 0x08A6A4u
#define tornado_kind_0_end_record_ADDRESS 0x08A72Eu
#define tornado_hazard_lists_ADDRESS 0x08A79Eu
#define quicksand_parts_ADDRESS 0x08A7BAu
#define quicksand_animation_ADDRESS 0x08A7DCu
#define tornado_whirlwind_lists_ADDRESS 0x08A7E4u
#define biting_head_bite_step_records_ADDRESS 0x08BE6Bu
#define biting_head_parts_ADDRESS 0x08BE83u
#define biting_head_clip_entry_ADDRESS 0x08BEC1u
#define brick_animations_ADDRESS 0x08BED5u
#define brick_wall_brick_records_ADDRESS 0x08BF03u
#define brick_wall_dust_records_ADDRESS 0x08BFADu
#define brick_dust_animation_ADDRESS 0x08BFD5u
#define saw_blade_animation_ADDRESS 0x08BFE9u
#define saw_sparks_animation_ADDRESS 0x08BFF3u
#define saw_shaft_animation_ADDRESS 0x08C0CDu
#define grate_step_cut_animation_ADDRESS 0x08C0DDu
#define grate_step_debris_animations_ADDRESS 0x08C11Du
#define geyser_animation_ADDRESS 0x08D81Eu
#define geyser_jet_animation_ADDRESS 0x08D854u
#define geyser_row_delays_ADDRESS 0x08D886u
#define geyser_lists_ADDRESS 0x08D902u
#define waterfall_parts_ADDRESS 0x08D97Eu
#define waterfall_animation_ADDRESS 0x08D998u
#define river_raft_unused_animation_ADDRESS 0x08DABEu
#define river_raft_fall_animation_ADDRESS 0x08DAC6u
#define river_raft_foam_animation_ADDRESS 0x08DAD2u
#define river_raft_unused_animation_2_ADDRESS 0x08DADAu
#define geyser_line_scripts_ADDRESS 0x08DB20u
#define geyser_burst_animation_ADDRESS 0x08DB50u
#define geyser_burst_spray_animation_ADDRESS 0x08DB62u
#define propeller_machine_parts_ADDRESS 0x08DB6Cu
#define propeller_machine_animation_ADDRESS 0x08DBC6u
#define propeller_machine_path_ADDRESS 0x08DBD8u
#define barred_gate_animation_ADDRESS 0x08DC10u
#define railing_parts_ADDRESS 0x08DC24u
#define ranking_rank_texts_ADDRESS 0x08EFF8u
#define countdown_second_texts_ADDRESS 0x08F08Eu
#define out_of_rank_text_ADDRESS 0x08F0DBu
#define ranking_row_numbers_ADDRESS 0x08F858u
#define wall_kinds_ADDRESS 0x090A72u
#define wall_editor_menu_ADDRESS 0x090C7Au
#define wall_editor_far_label_ADDRESS 0x090CBDu
#define wall_editor_near_label_ADDRESS 0x090CD2u
#define crumbling_floor_animations_ADDRESS 0x091FA9u
#define falling_grate_rattle_steps_ADDRESS 0x0920DBu
#define falling_grate_animation_ADDRESS 0x0920EDu
#define stage_object_records_ADDRESS 0x093269u
#define river_water_frames_ADDRESS 0x093463u
#define lava_rock_break_animation_ADDRESS 0x093475u
#define sand_block_parts_ADDRESS 0x093483u
#define lava_rock_parts_ADDRESS 0x0934F9u
#define lava_column_animation_ADDRESS 0x09350Bu
#define lava_column_parts_ADDRESS 0x093515u
#define lava_rock_glow_palettes_ADDRESS 0x093527u
#define group_slot_triggers_ADDRESS 0x093539u
#define ice_platform_piece_parts_ADDRESS 0x093559u
#define ice_platform_piece_parts_2_ADDRESS 0x09356Bu
#define group_leader_data_ADDRESS 0x09357Du
#define rope_bridge_plank_animations_ADDRESS 0x093FB9u
#define wide_rope_bridge_plank_parts_ADDRESS 0x093FDDu
#define stage_00_rock_pieces_ADDRESS 0x0955A2u
#define stage_00_platform_break_animation_ADDRESS 0x095662u
#define stage_00_geyser_animation_ADDRESS 0x09566Au
#define rock_debris_animations_ADDRESS 0x09567Eu
#define stage_00_geyser_speeds_ADDRESS 0x09569Cu
#define falling_rocks_ADDRESS 0x0956AAu
#define message_box_kinds_ADDRESS 0x09571Au
#define event_0f_messages_ADDRESS 0x0957FAu
#define stage_06_lightning_strikes_ADDRESS 0x09582Eu
#define event_1a_scroll_script_ADDRESS 0x09593Eu
#define event_1a_scroll_script_step_1_ADDRESS 0x095944u
#define map_wipe_in_windows_ADDRESS 0x096A4Bu
#define map_wipe_out_windows_ADDRESS 0x096ABDu
#define map_wipe_next_windows_ADDRESS 0x096B2Fu
#define map_stage_positions_ADDRESS 0x096B9Bu
#define map_marker_layouts_ADDRESS 0x096BC7u
#define map_marker_blink_sprites_ADDRESS 0x096C6Fu
#define title_sonic_loop_frames_ADDRESS 0x096E02u
#define timed_spawns_ADDRESS 0x097419u
#define title_smoke_puff_frames_ADDRESS 0x097538u
#define title_sky_cycle_palettes_ADDRESS 0x097F69u
#define start_ring_tally_padding_ADDRESS 0x0983FDu
#define pause_text_ADDRESS 0x09A65Cu
#define sprite_control_init_ADDRESS 0x09A6B2u
#define sprite_list_header_ADDRESS 0x09A6B6u
#define unused_09C569_ADDRESS 0x09C569u
#define default_settings_ADDRESS 0x09C58Eu
#define eeprom_deselect_padding_ADDRESS 0x09C8DFu
#define data_09EDC1_ADDRESS 0x09EDC1u
#define vector_table_ADDRESS 0x09F000u
#define irq_vblank_end_padding_ADDRESS 0x09F55Fu
#define irq_timer0_padding_ADDRESS 0x09F582u
#define int_default_padding_ADDRESS 0x09F5B5u
#define send_sound_command_padding_ADDRESS 0x09F5F9u
#define data_09FEDD_ADDRESS 0x09FEDDu
#define two_credits_one_play_text_ADDRESS 0x09FF84u
#define credits_label_text_ADDRESS 0x09FFAEu
#define free_play_text_ADDRESS 0x09FFC0u
#define high_code_chip_padding_ADDRESS 0x09FFF6u
#define object_types_ADDRESS 0x100000u
#define stage_00_type_spawns_ADDRESS 0x1001B4u
#define stage_01_type_spawns_ADDRESS 0x1001B8u
#define stage_02_type_spawns_ADDRESS 0x1001BCu
#define stage_03_type_spawns_ADDRESS 0x1001C4u
#define stage_04_type_spawns_ADDRESS 0x10043Eu
#define stage_05_type_spawns_ADDRESS 0x1004C0u
#define stage_06_type_spawns_ADDRESS 0x1004C4u
#define stage_07_type_spawns_ADDRESS 0x1004C8u
#define stage_08_type_spawns_ADDRESS 0x1004E8u
#define stage_09_type_spawns_ADDRESS 0x1005E8u
#define stage_0a_type_spawns_ADDRESS 0x100B2Cu
#define stage_0b_type_spawns_ADDRESS 0x101038u
#define stage_0c_type_spawns_ADDRESS 0x101082u
#define stage_0d_type_spawns_ADDRESS 0x10122Au
#define stage_0e_type_spawns_ADDRESS 0x10122Eu
#define stage_0f_type_spawns_ADDRESS 0x1012F6u
#define stage_10_type_spawns_ADDRESS 0x1012FAu
#define stage_11_type_spawns_ADDRESS 0x10162Au
#define stage_12_type_spawns_ADDRESS 0x10162Eu
#define text_font_ADDRESS 0x102136u
#define unused_103876_ADDRESS 0x103876u
#define ending_eggman_flight_path_ADDRESS 0x103B76u
#define fraction_digit_font_ADDRESS 0x104B76u
#define warning_screen_text_ADDRESS 0x104BD2u
#define unused_warning_border_script_ADDRESS 0x104D0Eu
#define default_palette_list_ADDRESS 0x104D60u
#define text_palettes_ADDRESS 0x104D92u
#define tile_bank_0_palette_repeats_ADDRESS 0x104F72u
#define tile_bank_0_palettes_ADDRESS 0x104FCEu
#define sprite_palettes_ADDRESS 0x10558Eu
#define bitmap_palettes_ADDRESS 0x10752Eu
#define backdrop_palette_ADDRESS 0x10768Eu
#define tile_bank_1_palette_list_ADDRESS 0x1076AEu
#define tile_bank_0_palette_list_ADDRESS 0x1076BCu
#define tile_bank_1_palette_repeats_ADDRESS 0x1076CAu
#define tile_bank_1_palettes_ADDRESS 0x107750u
#define stage_04_cycle_palettes_ADDRESS 0x107FB0u
#define stage_09_cycle_palettes_ADDRESS 0x1080B0u
#define stage_06_cycle_palettes_0_ADDRESS 0x108290u
#define stage_06_cycle_palettes_1_ADDRESS 0x108350u
#define stage_0a_cycle_palettes_1_ADDRESS 0x108410u
#define stage_0a_cycle_palettes_0_ADDRESS 0x108550u
#define stage_0c_cycle_palettes_ADDRESS 0x108610u
#define stage_0d_0e_cycle_palettes_ADDRESS 0x108710u
#define stage_0f_cycle_palettes_0_ADDRESS 0x108810u
#define stage_0f_cycle_palettes_1_ADDRESS 0x1088D0u
#define stage_10_cycle_palettes_0_ADDRESS 0x108990u
#define stage_10_cycle_palettes_1_ADDRESS 0x108A90u
#define ending_eggman_cycle_palettes_ADDRESS 0x108B90u
#define stages_00_to_03_sprite_palettes_ADDRESS 0x108D6Cu
#define stage_04_sprite_palettes_ADDRESS 0x10938Cu
#define stages_05_to_08_sprite_palettes_ADDRESS 0x10982Cu
#define stage_09_sprite_palettes_ADDRESS 0x109D0Cu
#define stage_0a_sprite_palettes_ADDRESS 0x10A0CCu
#define stages_10_12_sprite_palettes_ADDRESS 0x10A5CCu
#define stages_0b_to_0f_sprite_palettes_ADDRESS 0x10ACECu
#define stage_11_sprite_palettes_ADDRESS 0x10B14Cu
#define stage_00_floor_blocks_ADDRESS 0x10B6F2u
#define no_floor_block_ADDRESS 0x10B70Au
#define stage_01_02_03_07_floor_blocks_ADDRESS 0x10B720u
#define stage_04_floor_blocks_ADDRESS 0x10BC08u
#define stage_05_06_floor_blocks_ADDRESS 0x10C18Au
#define stage_08_floor_blocks_ADDRESS 0x10C1E4u
#define stage_09_11_12_floor_blocks_ADDRESS 0x10C6B6u
#define stage_0a_floor_blocks_ADDRESS 0x10CB30u
#define stage_0b_floor_blocks_ADDRESS 0x10D3CAu
#define stage_0c_0e_floor_blocks_ADDRESS 0x10D6A2u
#define stage_0d_0f_floor_blocks_ADDRESS 0x10D846u
#define stage_10_floor_blocks_ADDRESS 0x10D93Au
#define slope_speed_direction_pairs_ADDRESS 0x10DFCCu
#define stage_00_floor_block_bounds_ADDRESS 0x10E2C2u
#define stage_01_02_03_07_floor_block_bounds_ADDRESS 0x10E2D4u
#define stage_04_floor_block_bounds_ADDRESS 0x10E666u
#define stage_05_06_floor_block_bounds_ADDRESS 0x10E7C8u
#define stage_08_floor_block_bounds_ADDRESS 0x10E80Au
#define stage_09_floor_block_bounds_ADDRESS 0x10EA1Cu
#define stage_0a_floor_block_bounds_ADDRESS 0x10ECDEu
#define stage_0b_floor_block_bounds_ADDRESS 0x10F020u
#define stage_0c_0e_floor_block_bounds_ADDRESS 0x10F232u
#define stage_0d_0f_floor_block_bounds_ADDRESS 0x10F364u
#define stage_10_floor_block_bounds_ADDRESS 0x10F386u
#define stage_11_12_floor_block_bounds_ADDRESS 0x10F69Au
#define sonic_standing_animations_ADDRESS 0x10F6CCu
#define mighty_standing_animations_ADDRESS 0x10F90Cu
#define ray_standing_animations_ADDRESS 0x10FB4Cu
#define sonic_walking_animations_ADDRESS 0x10FD8Cu
#define mighty_walking_animations_ADDRESS 0x1101CCu
#define ray_walking_animations_ADDRESS 0x11060Cu
#define sonic_running_animations_ADDRESS 0x110A4Cu
#define mighty_running_animations_ADDRESS 0x110D0Cu
#define ray_running_animations_ADDRESS 0x110FCCu
#define sonic_running_fast_animations_ADDRESS 0x11128Cu
#define mighty_running_fast_animations_ADDRESS 0x11154Cu
#define ray_running_fast_animations_ADDRESS 0x11180Cu
#define sonic_alternate_run_animations_ADDRESS 0x111ACCu
#define mighty_alternate_run_animations_ADDRESS 0x111D8Cu
#define ray_alternate_run_animations_ADDRESS 0x11204Cu
#define sonic_attack_jump_animations_ADDRESS 0x11230Eu
#define sonic_plain_jump_animations_ADDRESS 0x1123FEu
#define mighty_attack_jump_animations_ADDRESS 0x1124EEu
#define mighty_plain_jump_animations_ADDRESS 0x1125DEu
#define ray_attack_jump_animations_ADDRESS 0x1126CEu
#define ray_plain_jump_animations_ADDRESS 0x1127BEu
#define sonic_near_edge_teeter_animation_ADDRESS 0x1128BAu
#define sonic_near_edge_fall_animation_ADDRESS 0x1128D8u
#define sonic_far_edge_teeter_animation_ADDRESS 0x1128EEu
#define sonic_far_edge_fall_animation_ADDRESS 0x11290Cu
#define mighty_near_edge_teeter_animation_ADDRESS 0x11291Eu
#define mighty_near_edge_fall_animation_ADDRESS 0x11293Cu
#define mighty_far_edge_teeter_animation_ADDRESS 0x112952u
#define mighty_far_edge_fall_animation_ADDRESS 0x112970u
#define ray_near_edge_teeter_animation_ADDRESS 0x112982u
#define ray_near_edge_fall_animation_ADDRESS 0x1129A0u
#define ray_far_edge_teeter_animation_ADDRESS 0x1129B6u
#define ray_far_edge_fall_animation_ADDRESS 0x1129D4u
#define sonic_far_edge_hang_animations_ADDRESS 0x1129E6u
#define sonic_near_edge_hang_animations_ADDRESS 0x112A20u
#define mighty_far_edge_hang_animations_ADDRESS 0x112A5Au
#define mighty_near_edge_hang_animations_ADDRESS 0x112A96u
#define ray_far_edge_hang_animations_ADDRESS 0x112AD2u
#define ray_near_edge_hang_animations_ADDRESS 0x112B1Eu
#define sonic_climb_animation_ADDRESS 0x112B6Au
#define sonic_climb_over_animation_ADDRESS 0x112B84u
#define sonic_climb_sideways_animation_ADDRESS 0x112BAEu
#define mighty_climb_animation_ADDRESS 0x112BBCu
#define mighty_climb_over_animation_ADDRESS 0x112BD6u
#define mighty_climb_sideways_animation_ADDRESS 0x112C00u
#define ray_climb_animation_ADDRESS 0x112C0Eu
#define ray_climb_over_animation_ADDRESS 0x112C28u
#define ray_climb_sideways_animation_ADDRESS 0x112C52u
#define sonic_skid_animations_ADDRESS 0x112C60u
#define mighty_skid_animations_ADDRESS 0x112E60u
#define ray_skid_animations_ADDRESS 0x113060u
#define sonic_hurt_animations_ADDRESS 0x113260u
#define mighty_hurt_animations_ADDRESS 0x1133B0u
#define ray_hurt_animations_ADDRESS 0x113500u
#define sonic_shocked_animations_ADDRESS 0x113650u
#define mighty_shocked_animations_ADDRESS 0x1136F8u
#define ray_shocked_animations_ADDRESS 0x1137A0u
#define attack_power_3_effect_animations_ADDRESS 0x113848u
#define attack_power_4_effect_animations_ADDRESS 0x113918u
#define sonic_bounce_200_animation_ADDRESS 0x113A00u
#define sonic_bounce_000_animation_ADDRESS 0x113A14u
#define ray_bounce_200_animation_ADDRESS 0x113A40u
#define ray_bounce_000_animation_ADDRESS 0x113A54u
#define mighty_bounce_200_animation_ADDRESS 0x113A80u
#define mighty_bounce_000_animation_ADDRESS 0x113A94u
#define sonic_drift_animation_ADDRESS 0x113AA8u
#define drift_minus_x_start_animation_ADDRESS 0x113AB2u
#define drift_minus_x_animation_ADDRESS 0x113ABAu
#define drift_plus_x_start_animation_ADDRESS 0x113AC4u
#define drift_plus_x_animation_ADDRESS 0x113ACCu
#define ray_drift_animation_ADDRESS 0x113AD6u
#define mighty_drift_animation_ADDRESS 0x113ADEu
#define sonic_geyser_hop_animation_ADDRESS 0x113AF0u
#define ray_geyser_hop_animation_ADDRESS 0x113AFCu
#define mighty_geyser_hop_animation_ADDRESS 0x113B08u
#define sonic_shrink_away_animation_ADDRESS 0x113B14u
#define ray_shrink_away_animation_ADDRESS 0x113B22u
#define mighty_shrink_away_animation_ADDRESS 0x113B30u
#define sonic_state_1b_animation_ADDRESS 0x113B3Eu
#define ray_state_1b_animation_ADDRESS 0x113B50u
#define mighty_state_1b_animation_ADDRESS 0x113B62u
#define sonic_opening_run_animation_ADDRESS 0x113B74u
#define sonic_opening_voice_animation_ADDRESS 0x113B8Eu
#define ray_opening_run_animation_ADDRESS 0x113BA8u
#define ray_opening_voice_animation_ADDRESS 0x113BC2u
#define mighty_opening_run_animation_ADDRESS 0x113BDCu
#define mighty_opening_voice_animation_ADDRESS 0x113BF6u
#define sonic_stuck_animation_ADDRESS 0x113C10u
#define ray_stuck_animation_ADDRESS 0x113C1Eu
#define mighty_stuck_animation_ADDRESS 0x113C2Cu
#define sonic_stuck_struggle_level_animations_ADDRESS 0x113C46u
#define sonic_stuck_escape_animation_ADDRESS 0x113C58u
#define ray_stuck_struggle_level_animations_ADDRESS 0x113C6Au
#define ray_stuck_escape_animation_ADDRESS 0x113C7Cu
#define mighty_stuck_struggle_level_animations_ADDRESS 0x113C8Eu
#define mighty_stuck_escape_animation_ADDRESS 0x113CA0u
#define stuck_effect_animation_ADDRESS 0x113CA6u
#define skid_dust_animation_ADDRESS 0x113D13u
#define sonic_palette_list_ADDRESS 0x113E3Du
#define ray_palette_list_ADDRESS 0x113E45u
#define mighty_palette_list_ADDRESS 0x113E4Du
#define sonic_stage_08_palette_list_ADDRESS 0x113E55u
#define ray_stage_08_palette_list_ADDRESS 0x113E5Du
#define mighty_stage_08_palette_list_ADDRESS 0x113E65u
#define hud_insert_coins_text_ADDRESS 0x113FC1u
#define hud_push_start_text_ADDRESS 0x113FCFu
#define hud_wait_text_ADDRESS 0x113FDDu
#define hud_message_blank_text_ADDRESS 0x113FF5u
#define attack_text_ADDRESS 0x114064u
#define sinking_shadow_animation_ADDRESS 0x11406Cu
#define sonic_floor_8_ride_animation_ADDRESS 0x1140D4u
#define ray_floor_8_ride_animation_ADDRESS 0x1140DCu
#define mighty_floor_8_ride_animation_ADDRESS 0x1140E4u
#define sonic_floor_8_landing_animation_ADDRESS 0x1140ECu
#define ray_floor_8_landing_animation_ADDRESS 0x1140FEu
#define mighty_floor_8_landing_animation_ADDRESS 0x114110u
#define hud_continue_text_ADDRESS 0x11412Cu
#define hud_game_over_text_ADDRESS 0x114162u
#define hud_ring_count_blank_text_ADDRESS 0x114183u
#define stage_goal_records_ADDRESS 0x1141C0u
#define sonic_stun_recover_animation_ADDRESS 0x114244u
#define ray_stun_recover_animation_ADDRESS 0x114262u
#define mighty_stun_recover_animation_ADDRESS 0x114280u
#define ray_stunned_animation_ADDRESS 0x11429Eu
#define blown_away_effect_animation_ADDRESS 0x1142E4u
#define tumble_effect_animation_ADDRESS 0x1142F6u
#define sonic_tumble_animations_ADDRESS 0x11430Eu
#define ray_tumble_animations_ADDRESS 0x1144DEu
#define mighty_tumble_animations_ADDRESS 0x1146AEu
#define sonic_knocked_out_animations_ADDRESS 0x11487Eu
#define ray_knocked_out_animations_ADDRESS 0x1148F6u
#define mighty_knocked_out_animations_ADDRESS 0x11496Eu
#define sonic_seesaw_launch_animation_ADDRESS 0x1149D6u
#define ray_seesaw_launch_animation_ADDRESS 0x1149E2u
#define mighty_seesaw_launch_animation_ADDRESS 0x1149EEu
#define sonic_trapped_animation_ADDRESS 0x1149FAu
#define ray_trapped_animation_ADDRESS 0x114A34u
#define mighty_trapped_animation_ADDRESS 0x114A66u
#define sonic_trap_struggle_level_animations_ADDRESS 0x114AD0u
#define ray_trap_struggle_level_animations_ADDRESS 0x114AE8u
#define mighty_trap_struggle_level_animations_ADDRESS 0x114B00u
#define sonic_pit_sinking_animation_ADDRESS 0x114B18u
#define ray_pit_sinking_animation_ADDRESS 0x114B20u
#define mighty_pit_sinking_animation_ADDRESS 0x114B28u
#define pit_sinking_shadow_animation_ADDRESS 0x114B30u
#define stage_00_restart_points_ADDRESS 0x114BAAu
#define stage_01_restart_points_ADDRESS 0x114C08u
#define stage_02_restart_points_ADDRESS 0x114D1Eu
#define stage_03_07_restart_points_ADDRESS 0x114DDCu
#define stage_04_restart_points_ADDRESS 0x114E92u
#define stage_05_06_restart_points_ADDRESS 0x114FD0u
#define stage_08_restart_points_ADDRESS 0x114FE6u
#define stage_09_restart_points_ADDRESS 0x1150E4u
#define stage_0a_restart_points_ADDRESS 0x115252u
#define stage_0b_restart_points_ADDRESS 0x1152F8u
#define stage_0c_0e_restart_points_ADDRESS 0x11540Eu
#define stage_0d_0f_restart_points_ADDRESS 0x11545Cu
#define stage_10_restart_points_ADDRESS 0x11547Au
#define stage_11_12_restart_points_ADDRESS 0x11551Au
#define player_paths_ADDRESS 0x1155D4u
#define test_menu_text_ADDRESS 0x115BE9u
#define individual_mode_text_ADDRESS 0x115CBAu
#define test_menu_output_test_text_ADDRESS 0x115CCAu
#define continue_mode_text_ADDRESS 0x115CDBu
#define sound_test_text_ADDRESS 0x115CEFu
#define crt_test_color_bars_ADDRESS 0x115D3Fu
#define crt_test_1_text_ADDRESS 0x115D73u
#define crt_test_2_text_ADDRESS 0x115DCEu
#define game_assignments_text_ADDRESS 0x115DFFu
#define monitor_flip_normal_text_ADDRESS 0x115F13u
#define monitor_flip_reverse_text_ADDRESS 0x115F21u
#define cabinet_type_2p_text_ADDRESS 0x115F36u
#define cabinet_type_3p_text_ADDRESS 0x115F3Eu
#define moving_seat_erase_text_ADDRESS 0x115F46u
#define advertise_sound_off_text_ADDRESS 0x115F74u
#define advertise_sound_on_text_ADDRESS 0x115F7Du
#define start_button_use_text_ADDRESS 0x115F86u
#define start_button_no_use_text_ADDRESS 0x115F95u
#define moving_seat_use_text_ADDRESS 0x115FA3u
#define moving_seat_no_use_text_ADDRESS 0x115FB2u
#define output_test_seat_text_ADDRESS 0x115FC8u
#define output_test_no_use_text_ADDRESS 0x11601Bu
#define output_test_text_ADDRESS 0x116029u
#define output_test_1p_on_text_ADDRESS 0x116064u
#define output_test_1p_off_text_ADDRESS 0x11606Du
#define output_test_2p_on_text_ADDRESS 0x116076u
#define output_test_2p_off_text_ADDRESS 0x11607Fu
#define coin_assignments_common_text_ADDRESS 0x116088u
#define coin_assignments_text_ADDRESS 0x116099u
#define coin_chute_2_label_erase_text_ADDRESS 0x116148u
#define coin_chute_labels_text_ADDRESS 0x11615Bu
#define coin_chute_type_individual_text_ADDRESS 0x11617Fu
#define coin_chute_type_common_text_ADDRESS 0x11619Fu
#define credits_to_start_1_text_ADDRESS 0x1161BFu
#define credits_to_start_2_text_ADDRESS 0x1161CEu
#define coin_setting_number_manual_text_ADDRESS 0x1161E5u
#define coin_setting_number_erase_text_ADDRESS 0x1161F1u
#define coin_manual_page_common_text_ADDRESS 0x1161FEu
#define coin_manual_page_text_ADDRESS 0x116277u
#define chute_1_coin_text_ADDRESS 0x116386u
#define chute_1_coins_text_ADDRESS 0x116391u
#define chute_2_coin_text_ADDRESS 0x11639Cu
#define chute_2_coins_text_ADDRESS 0x1163A7u
#define coin_credit_rows_erase_text_ADDRESS 0x1163B2u
#define coins_per_credit_1_text_ADDRESS 0x11644Au
#define coins_per_credit_2_text_ADDRESS 0x116457u
#define coins_per_credit_3_text_ADDRESS 0x116464u
#define coins_per_credit_4_text_ADDRESS 0x116471u
#define coins_per_credit_5_text_ADDRESS 0x11647Eu
#define coins_per_credit_6_text_ADDRESS 0x11648Bu
#define coins_per_credit_7_text_ADDRESS 0x116498u
#define coins_per_credit_8_text_ADDRESS 0x1164A5u
#define coins_per_credit_9_text_ADDRESS 0x1164B2u
#define bonus_adder_none_text_ADDRESS 0x1164E7u
#define bonus_adder_2_text_ADDRESS 0x116507u
#define bonus_adder_3_text_ADDRESS 0x116527u
#define bonus_adder_4_text_ADDRESS 0x116547u
#define bonus_adder_5_text_ADDRESS 0x116567u
#define bonus_adder_6_text_ADDRESS 0x116587u
#define bonus_adder_7_text_ADDRESS 0x1165A7u
#define bonus_adder_8_text_ADDRESS 0x1165C7u
#define bonus_adder_9_text_ADDRESS 0x1165E7u
#define coin_setting_erase_text_ADDRESS 0x116632u
#define coin_setting_text_1_ADDRESS 0x1167C4u
#define coin_setting_text_1_individual_ADDRESS 0x1167D8u
#define coin_setting_text_2_ADDRESS 0x1167EEu
#define coin_setting_text_3_ADDRESS 0x116819u
#define coin_setting_text_4_ADDRESS 0x116844u
#define coin_setting_text_5_ADDRESS 0x11686Fu
#define coin_setting_text_6_ADDRESS 0x11689Au
#define coin_setting_text_6_individual_ADDRESS 0x1168AFu
#define coin_setting_text_7_ADDRESS 0x1168C6u
#define coin_setting_text_8_ADDRESS 0x1168F2u
#define coin_setting_text_8_individual_ADDRESS 0x116907u
#define coin_setting_text_9_ADDRESS 0x11691Eu
#define coin_setting_text_9_individual_ADDRESS 0x116933u
#define coin_setting_text_10_ADDRESS 0x11694Au
#define coin_setting_text_10_individual_ADDRESS 0x11695Fu
#define coin_setting_text_11_ADDRESS 0x116976u
#define coin_setting_text_11_individual_ADDRESS 0x11698Bu
#define coin_setting_text_12_ADDRESS 0x1169A2u
#define coin_setting_text_12_individual_ADDRESS 0x1169B6u
#define coin_setting_text_13_ADDRESS 0x1169CCu
#define coin_setting_text_14_ADDRESS 0x1169F6u
#define coin_setting_text_15_ADDRESS 0x116A21u
#define coin_setting_text_15_individual_ADDRESS 0x116A4Au
#define coin_setting_text_16_ADDRESS 0x116A75u
#define coin_setting_text_17_ADDRESS 0x116AB5u
#define coin_setting_text_17_individual_ADDRESS 0x116AC9u
#define coin_setting_text_18_ADDRESS 0x116ADFu
#define coin_setting_text_18_individual_ADDRESS 0x116AF3u
#define coin_setting_text_19_ADDRESS 0x116B09u
#define coin_setting_text_19_individual_ADDRESS 0x116B5Cu
#define coin_setting_text_20_ADDRESS 0x116BB1u
#define coin_setting_text_21_ADDRESS 0x116C1Bu
#define coin_setting_text_21_individual_ADDRESS 0x116C2Fu
#define coin_setting_text_22_ADDRESS 0x116C5Au
#define coin_setting_text_22_individual_ADDRESS 0x116C98u
#define coin_setting_text_23_ADDRESS 0x116CD8u
#define coin_setting_text_24_ADDRESS 0x116D2Cu
#define coin_setting_text_24_individual_ADDRESS 0x116D94u
#define coin_setting_text_25_ADDRESS 0x116DFEu
#define coin_setting_text_26_ADDRESS 0x116E7Du
#define coin_setting_text_26_individual_ADDRESS 0x116E8Du
#define coin_setting_text_manual_ADDRESS 0x116E9Fu
#define coin_setting_text_manual_individual_ADDRESS 0x116EB1u
#define input_test_start_erase_text_ADDRESS 0x116F51u
#define input_test_text_3p_ADDRESS 0x116F7Du
#define input_test_text_ADDRESS 0x116FA7u
#define input_test_chute_3_text_ADDRESS 0x117072u
#define input_test_chute_2_text_ADDRESS 0x117078u
#define input_test_start_3_on_text_ADDRESS 0x117119u
#define input_test_attack_3_on_text_ADDRESS 0x117122u
#define input_test_start_1_on_text_ADDRESS 0x11712Bu
#define input_test_attack_1_on_text_ADDRESS 0x117134u
#define input_test_start_2_on_text_ADDRESS 0x11713Du
#define input_test_attack_2_on_text_ADDRESS 0x117146u
#define input_test_service_on_text_ADDRESS 0x11714Fu
#define input_test_test_button_on_text_ADDRESS 0x117158u
#define input_test_start_3_off_text_ADDRESS 0x117161u
#define input_test_attack_3_off_text_ADDRESS 0x11716Au
#define input_test_start_1_off_text_ADDRESS 0x117173u
#define input_test_attack_1_off_text_ADDRESS 0x11717Cu
#define input_test_start_2_off_text_ADDRESS 0x117185u
#define input_test_attack_2_off_text_ADDRESS 0x11718Eu
#define input_test_service_off_text_ADDRESS 0x117197u
#define input_test_test_button_off_text_ADDRESS 0x1171A0u
#define input_test_coin_1_on_text_ADDRESS 0x1171A9u
#define input_test_coin_1_off_text_ADDRESS 0x1171B2u
#define input_test_coin_2_on_text_ADDRESS 0x1171BBu
#define input_test_coin_2_off_text_ADDRESS 0x1171C4u
#define input_test_coin_3_on_text_ADDRESS 0x1171CDu
#define input_test_coin_3_off_text_ADDRESS 0x1171D6u
#define input_test_trackball_1_good_text_ADDRESS 0x1171DFu
#define input_test_trackball_2_good_text_ADDRESS 0x1171E9u
#define input_test_trackball_3_good_text_ADDRESS 0x1171F3u
#define backup_clear_text_ADDRESS 0x11720Du
#define backup_clear_done_text_ADDRESS 0x117275u
#define backup_clear_completed_text_ADDRESS 0x11727Bu
#define bookkeeping_text_ADDRESS 0x117292u
#define bookkeeping_chute_3_erase_text_ADDRESS 0x1173E8u
#define memory_test_text_ADDRESS 0x1173FBu
#define memory_test_done_text_ADDRESS 0x1174D0u
#define memory_test_error_text_ADDRESS 0x117526u
#define memory_test_dashes_text_ADDRESS 0x117544u
#define memory_test_result_texts_ADDRESS 0x1175DEu
#define eeprom_caution_text_ADDRESS 0x1177A6u
#define eeprom_write_count_text_ADDRESS 0x11781Eu
#define control_ball_text_ADDRESS 0x117843u
#define control_ball_small_text_ADDRESS 0x117857u
#define control_ball_large_text_ADDRESS 0x117862u
#define attract_demo_1_inputs_ADDRESS 0x117876u
#define attract_demo_2_inputs_ADDRESS 0x118876u
#define unused_fill_119876_ADDRESS 0x119876u
#define sprite_frame_records_ADDRESS 0x130000u
#define unused_fill_13BFD0_ADDRESS 0x13BFD0u
#define stage_04_tile_sets_ADDRESS 0x140000u
#define stage_05_tile_sets_ADDRESS 0x140194u
#define stage_03_tile_sets_ADDRESS 0x1401F4u
#define stage_09_tile_sets_ADDRESS 0x140328u
#define stage_0a_tile_sets_ADDRESS 0x14044Cu
#define stage_0b_tile_sets_ADDRESS 0x140564u
#define stage_10_tile_sets_ADDRESS 0x14070Cu
#define stage_08_tile_sets_ADDRESS 0x1407ECu
#define tile_set_script_lists_ADDRESS 0x140910u
#define tile_set_clear_page_00_script_ADDRESS 0x141A10u
#define tile_set_clear_page_01_script_ADDRESS 0x141A28u
#define tile_set_clear_page_02_script_ADDRESS 0x141A40u
#define tile_set_clear_page_03_script_ADDRESS 0x141A58u
#define unused_tile_set_clear_page_03_script_ADDRESS 0x141A70u
#define tile_set_clear_page_0a_script_ADDRESS 0x141A88u
#define tile_set_clear_page_0b_script_ADDRESS 0x141AA0u
#define tile_set_clear_page_0c_script_ADDRESS 0x141AB8u
#define tile_set_clear_page_0d_script_ADDRESS 0x141AD0u
#define tile_set_clear_page_0f_script_ADDRESS 0x141AE8u
#define tile_set_clear_page_10_script_ADDRESS 0x141B00u
#define tile_set_clear_page_11_script_ADDRESS 0x141B18u
#define tile_set_clear_page_12_script_ADDRESS 0x141B30u
#define tile_set_clear_page_05_script_ADDRESS 0x141B48u
#define unused_tile_set_clear_page_06_script_ADDRESS 0x141B60u
#define tile_set_clear_page_07_script_ADDRESS 0x141B78u
#define unused_tile_set_clear_page_08_script_ADDRESS 0x141B90u
#define stage_04_tile_set_25_script_1_ADDRESS 0x141BA8u
#define stage_04_tile_set_26_script_1_ADDRESS 0x141C90u
#define stage_04_tile_set_2b_script_1_ADDRESS 0x141D76u
#define stage_03_tile_set_17_script_ADDRESS 0x141DBFu
#define stage_03_tile_set_19_script_ADDRESS 0x142072u
#define stage_03_tile_set_1a_script_ADDRESS 0x14216Au
#define stage_03_tile_set_1b_script_ADDRESS 0x1421E3u
#define stage_03_tile_set_1c_script_ADDRESS 0x1424B4u
#define stage_03_tile_set_1d_script_0_ADDRESS 0x1426C9u
#define stage_03_tile_set_1d_script_1_ADDRESS 0x1429A1u
#define stage_03_tile_set_1e_script_0_ADDRESS 0x142AA4u
#define stage_03_tile_set_1e_script_1_ADDRESS 0x142D00u
#define stage_03_tile_set_1f_script_ADDRESS 0x142F4Du
#define stage_03_tile_set_20_script_0_ADDRESS 0x143028u
#define stage_03_tile_set_21_script_0_ADDRESS 0x14308Du
#define stage_03_tile_set_22_script_ADDRESS 0x143291u
#define stage_03_tile_set_29_script_ADDRESS 0x143354u
#define stage_03_tile_set_2a_script_ADDRESS 0x14356Bu
#define stage_03_tile_set_2b_script_0_ADDRESS 0x14369Au
#define stage_03_tile_set_2c_script_ADDRESS 0x143714u
#define stage_03_tile_set_2d_script_0_ADDRESS 0x143983u
#define stage_03_tile_set_2e_script_ADDRESS 0x143A3Au
#define stage_03_tile_set_2f_script_ADDRESS 0x143B2Fu
#define stage_03_tile_set_30_script_ADDRESS 0x143BD3u
#define stage_03_tile_set_31_script_0_ADDRESS 0x143E42u
#define stage_03_tile_set_32_script_ADDRESS 0x143F39u
#define stage_03_tile_set_33_script_ADDRESS 0x144039u
#define stage_03_tile_set_34_script_ADDRESS 0x1441D4u
#define stage_03_tile_set_35_script_ADDRESS 0x14436Bu
#define stage_03_tile_set_36_script_ADDRESS 0x1444EAu
#define stage_03_tile_set_37_script_ADDRESS 0x1446A5u
#define stage_03_tile_set_38_script_ADDRESS 0x14480Fu
#define stage_03_tile_set_39_script_ADDRESS 0x1448BEu
#define stage_03_tile_set_3a_script_ADDRESS 0x144973u
#define stage_03_tile_set_3b_script_ADDRESS 0x144A54u
#define stage_03_tile_set_3c_script_ADDRESS 0x144B65u
#define stage_03_tile_set_3d_script_0_ADDRESS 0x144D6Eu
#define stage_03_tile_set_3d_script_1_ADDRESS 0x144DE3u
#define stage_03_tile_set_3e_script_ADDRESS 0x145030u
#define stage_03_tile_set_3f_script_ADDRESS 0x1451F5u
#define stage_03_tile_set_40_script_ADDRESS 0x1453BAu
#define stage_03_tile_set_41_script_ADDRESS 0x14557Fu
#define stage_03_tile_set_42_script_2_ADDRESS 0x145727u
#define stage_03_end_script_1_ADDRESS 0x145A46u
#define stage_03_tile_set_42_script_1_ADDRESS 0x145A4Eu
#define stage_03_tile_set_43_script_ADDRESS 0x145B2Bu
#define stage_03_tile_set_44_script_ADDRESS 0x145E52u
#define stage_03_end_script_3_ADDRESS 0x146161u
#define stage_03_tile_set_45_script_ADDRESS 0x146169u
#define stage_03_tile_set_46_script_ADDRESS 0x146456u
#define stage_03_tile_set_47_script_ADDRESS 0x1464CFu
#define stage_03_tile_set_48_script_ADDRESS 0x1467A0u
#define stage_03_tile_set_49_script_0_ADDRESS 0x1469B5u
#define stage_03_tile_set_4a_script_0_ADDRESS 0x146A1Au
#define stage_03_tile_set_4b_script_ADDRESS 0x146C1Eu
#define stage_03_tile_set_4c_script_ADDRESS 0x146CE1u
#define stage_03_end_script_2_ADDRESS 0x146DD1u
#define stage_03_tile_set_42_script_0_ADDRESS 0x146DD9u
#define stage_05_tile_set_14_script_ADDRESS 0x147041u
#define stage_05_tile_set_15_script_ADDRESS 0x1472C9u
#define stage_05_tile_set_16_script_ADDRESS 0x14739Du
#define stage_05_tile_set_17_script_ADDRESS 0x147442u
#define stage_04_tile_set_56_script_0_ADDRESS 0x1474F6u
#define stage_04_tile_set_56_script_1_ADDRESS 0x147550u
#define stage_04_tile_set_57_script_ADDRESS 0x1475E5u
#define stage_04_tile_set_58_script_0_ADDRESS 0x147652u
#define stage_04_tile_set_58_script_1_ADDRESS 0x1477C4u
#define stage_04_tile_set_59_script_0_ADDRESS 0x1477FAu
#define stage_04_tile_set_59_script_1_ADDRESS 0x147854u
#define stage_04_tile_set_5a_script_ADDRESS 0x1478E9u
#define stage_04_tile_set_5b_script_0_ADDRESS 0x147956u
#define stage_04_tile_set_5b_script_1_ADDRESS 0x147AC8u
#define stage_04_tile_set_5c_script_0_ADDRESS 0x147AFEu
#define stage_04_tile_set_5d_script_0_ADDRESS 0x147C92u
#define stage_04_tile_set_5d_script_1_ADDRESS 0x147EFCu
#define stage_04_tile_set_5e_script_ADDRESS 0x14806Fu
#define stage_04_tile_set_5f_script_0_ADDRESS 0x1481E4u
#define stage_04_tile_set_5f_script_1_ADDRESS 0x14843Fu
#define stage_04_tile_set_60_script_0_ADDRESS 0x14859Fu
#define stage_04_tile_set_60_script_1_ADDRESS 0x14863Cu
#define stage_04_tile_set_61_script_ADDRESS 0x14872Cu
#define stage_04_tile_set_62_script_0_ADDRESS 0x1488A1u
#define stage_04_tile_set_62_script_1_ADDRESS 0x148AFCu
#define stage_04_tile_set_63_script_0_ADDRESS 0x148C5Cu
#define stage_04_tile_set_63_script_1_ADDRESS 0x148CF9u
#define stage_04_tile_set_64_script_0_ADDRESS 0x148DE9u
#define stage_04_tile_set_64_script_1_ADDRESS 0x149009u
#define stage_04_tile_set_5d_script_2_ADDRESS 0x149047u
#define stage_04_tile_set_14_script_ADDRESS 0x1490FDu
#define stage_04_tile_set_15_script_ADDRESS 0x14938Cu
#define stage_04_tile_set_16_script_ADDRESS 0x1494C2u
#define stage_04_tile_set_17_script_ADDRESS 0x149545u
#define stage_04_tile_set_18_script_ADDRESS 0x1495A2u
#define stage_04_tile_set_19_script_ADDRESS 0x1495FBu
#define stage_04_tile_set_1a_script_ADDRESS 0x14966Au
#define stage_04_tile_set_1b_script_ADDRESS 0x1496C4u
#define stage_04_tile_set_1c_script_ADDRESS 0x149732u
#define stage_04_tile_set_1d_script_ADDRESS 0x14980Du
#define stage_04_tile_set_1e_script_ADDRESS 0x14985Fu
#define stage_04_tile_set_1f_script_ADDRESS 0x14988Du
#define stage_04_tile_set_20_script_ADDRESS 0x14993Fu
#define stage_04_tile_set_21_script_ADDRESS 0x149962u
#define stage_04_tile_set_22_script_ADDRESS 0x149A14u
#define stage_04_tile_set_23_script_ADDRESS 0x149A8Du
#define stage_04_tile_set_24_script_ADDRESS 0x149B9Fu
#define stage_04_tile_set_25_script_0_ADDRESS 0x149DD6u
#define stage_04_tile_set_26_script_0_ADDRESS 0x14A046u
#define stage_04_tile_set_27_script_0_ADDRESS 0x14A2B1u
#define stage_04_tile_set_28_script_0_ADDRESS 0x14A342u
#define stage_04_tile_set_29_script_ADDRESS 0x14A391u
#define stage_04_tile_set_2a_script_ADDRESS 0x14A3EBu
#define stage_04_tile_set_2b_script_0_ADDRESS 0x14A560u
#define stage_04_tile_set_2e_script_ADDRESS 0x14A629u
#define stage_04_tile_set_2f_script_ADDRESS 0x14A69Cu
#define stage_04_tile_set_30_script_ADDRESS 0x14A790u
#define stage_04_tile_set_31_script_ADDRESS 0x14A7EAu
#define stage_04_tile_set_32_script_ADDRESS 0x14A8ECu
#define stage_04_tile_set_33_script_ADDRESS 0x14A95Au
#define stage_04_tile_set_34_script_ADDRESS 0x14A9CCu
#define stage_04_tile_set_35_script_ADDRESS 0x14AA55u
#define stage_04_tile_set_36_script_ADDRESS 0x14AB66u
#define stage_04_tile_set_37_script_ADDRESS 0x14ABC5u
#define stage_04_tile_set_38_script_ADDRESS 0x14AD00u
#define stage_04_tile_set_39_script_ADDRESS 0x14AE78u
#define stage_04_tile_set_3b_script_ADDRESS 0x14B22Fu
#define stage_04_tile_set_3c_script_ADDRESS 0x14B2A2u
#define stage_04_tile_set_3d_script_ADDRESS 0x14B3D2u
#define stage_04_tile_set_3e_script_ADDRESS 0x14B487u
#define stage_04_tile_set_40_script_ADDRESS 0x14B5AEu
#define stage_04_tile_set_41_script_ADDRESS 0x14B5FDu
#define stage_09_tile_set_14_script_0_ADDRESS 0x14B68Eu
#define stage_09_tile_set_14_script_1_ADDRESS 0x14B6E9u
#define stage_09_tile_set_14_script_2_ADDRESS 0x14B8CEu
#define stage_09_tile_set_15_script_0_ADDRESS 0x14B8E1u
#define stage_09_tile_set_15_script_1_ADDRESS 0x14BAC6u
#define stage_09_tile_set_15_script_2_ADDRESS 0x14BD02u
#define stage_09_tile_set_16_script_0_ADDRESS 0x14BE20u
#define stage_09_tile_set_16_script_1_ADDRESS 0x14BE6Au
#define stage_09_tile_set_16_script_2_ADDRESS 0x14BEE7u
#define stage_09_tile_set_17_script_1_ADDRESS 0x14BFDEu
#define stage_09_tile_set_18_script_0_ADDRESS 0x14C025u
#define stage_09_tile_set_18_script_1_ADDRESS 0x14C062u
#define stage_09_tile_set_19_script_0_ADDRESS 0x14C1F3u
#define stage_09_tile_set_19_script_1_ADDRESS 0x14C341u
#define stage_09_tile_set_19_script_2_ADDRESS 0x14C557u
#define stage_09_tile_set_1a_script_0_ADDRESS 0x14C5F5u
#define stage_09_tile_set_1a_script_1_ADDRESS 0x14C653u
#define stage_09_tile_set_1a_script_2_ADDRESS 0x14C6DCu
#define stage_09_tile_set_1b_script_0_ADDRESS 0x14C7CFu
#define stage_09_tile_set_1b_script_1_ADDRESS 0x14C805u
#define stage_09_tile_set_1c_script_0_ADDRESS 0x14C918u
#define stage_09_tile_set_1c_script_1_ADDRESS 0x14CAC0u
#define stage_09_tile_set_1c_script_2_ADDRESS 0x14CCF0u
#define stage_09_tile_set_1d_script_0_ADDRESS 0x14CD8Eu
#define stage_09_tile_set_1d_script_1_ADDRESS 0x14CDF0u
#define stage_09_tile_set_1d_script_2_ADDRESS 0x14CED3u
#define stage_09_tile_set_1e_script_0_ADDRESS 0x14CFA3u
#define stage_09_tile_set_1e_script_1_ADDRESS 0x14CFD9u
#define stage_09_tile_set_1f_script_0_ADDRESS 0x14D0F6u
#define stage_09_tile_set_1f_script_1_ADDRESS 0x14D285u
#define stage_09_tile_set_1f_script_2_ADDRESS 0x14D4D0u
#define stage_09_tile_set_20_script_0_ADDRESS 0x14D56Bu
#define stage_09_tile_set_20_script_1_ADDRESS 0x14D5C9u
#define stage_09_tile_set_20_script_2_ADDRESS 0x14D63Eu
#define stage_09_tile_set_21_script_0_ADDRESS 0x14D6F0u
#define stage_09_tile_set_21_script_1_ADDRESS 0x14D726u
#define stage_09_tile_set_22_script_0_ADDRESS 0x14D843u
#define stage_09_tile_set_22_script_1_ADDRESS 0x14D9D2u
#define stage_09_tile_set_22_script_2_ADDRESS 0x14DC1Du
#define stage_09_tile_set_23_script_0_ADDRESS 0x14DCB8u
#define stage_09_tile_set_23_script_2_ADDRESS 0x14DD16u
#define stage_09_tile_set_23_script_1_ADDRESS 0x14DDC8u
#define stage_09_tile_set_24_script_0_ADDRESS 0x14DE3Du
#define stage_09_tile_set_24_script_1_ADDRESS 0x14DE73u
#define stage_09_tile_set_25_script_0_ADDRESS 0x14DFF5u
#define stage_09_tile_set_25_script_1_ADDRESS 0x14E0A9u
#define stage_09_tile_set_25_script_2_ADDRESS 0x14E334u
#define stage_09_tile_set_26_script_1_ADDRESS 0x14E3EDu
#define stage_09_tile_set_27_script_1_ADDRESS 0x14E4FCu
#define stage_09_tile_set_28_script_1_ADDRESS 0x14E7CBu
#define stage_09_tile_set_29_script_1_ADDRESS 0x14EAE2u
#define stage_09_tile_set_2a_script_1_ADDRESS 0x14EBF1u
#define stage_09_tile_set_2b_script_1_ADDRESS 0x14EEC0u
#define stage_09_tile_set_2c_script_0_ADDRESS 0x14F1D7u
#define stage_09_tile_set_2c_script_1_ADDRESS 0x14F1E7u
#define stage_09_tile_set_2d_script_0_ADDRESS 0x14F43Bu
#define stage_09_tile_set_2d_script_1_ADDRESS 0x14F652u
#define stage_09_tile_set_2d_script_2_ADDRESS 0x14F96Au
#define stage_09_tile_set_2e_script_0_ADDRESS 0x14F9F0u
#define stage_09_tile_set_2e_script_1_ADDRESS 0x14FA0Bu
#define stage_09_tile_set_2e_script_2_ADDRESS 0x14FBDDu
#define stage_09_tile_set_2f_script_1_ADDRESS 0x14FC5Du
#define stage_09_tile_set_30_script_0_ADDRESS 0x14FC7Fu
#define stage_09_tile_set_30_script_1_ADDRESS 0x14FD3Du
#define stage_09_tile_set_31_script_0_ADDRESS 0x14FEF5u
#define stage_09_tile_set_31_script_1_ADDRESS 0x15013Au
#define stage_09_tile_set_31_script_2_ADDRESS 0x1503B5u
#define stage_09_tile_set_32_script_0_ADDRESS 0x150477u
#define stage_09_tile_set_32_script_1_ADDRESS 0x150572u
#define stage_09_tile_set_32_script_2_ADDRESS 0x15065Au
#define stage_09_tile_set_33_script_0_ADDRESS 0x150745u
#define stage_09_tile_set_33_script_1_ADDRESS 0x150882u
#define stage_09_tile_set_34_script_0_ADDRESS 0x150B6Fu
#define stage_09_tile_set_34_script_1_ADDRESS 0x150E06u
#define stage_09_tile_set_34_script_2_ADDRESS 0x151033u
#define stage_09_tile_set_35_script_0_ADDRESS 0x151187u
#define stage_09_tile_set_35_script_1_ADDRESS 0x1511B4u
#define stage_09_tile_set_35_script_2_ADDRESS 0x1511D8u
#define stage_09_tile_set_36_script_0_ADDRESS 0x151266u
#define stage_09_tile_set_36_script_1_ADDRESS 0x151287u
#define stage_09_tile_set_37_script_0_ADDRESS 0x1513AEu
#define stage_09_tile_set_37_script_1_ADDRESS 0x15154Bu
#define stage_09_tile_set_37_script_2_ADDRESS 0x15187Au
#define stage_09_tile_set_38_script_0_ADDRESS 0x1518AEu
#define stage_09_tile_set_38_script_1_ADDRESS 0x151B34u
#define stage_09_tile_set_38_script_2_ADDRESS 0x151D7Du
#define stage_09_tile_set_38_script_3_ADDRESS 0x151E7Au
#define stage_09_tile_set_39_script_0_ADDRESS 0x151EB4u
#define stage_09_tile_set_39_script_1_ADDRESS 0x151FC4u
#define stage_09_tile_set_39_script_2_ADDRESS 0x1520A6u
#define stage_09_tile_set_3a_script_0_ADDRESS 0x152190u
#define stage_09_tile_set_3a_script_1_ADDRESS 0x152372u
#define stage_09_tile_set_3a_script_2_ADDRESS 0x152509u
#define stage_09_tile_set_3b_script_0_ADDRESS 0x15254Du
#define stage_09_tile_set_3b_script_1_ADDRESS 0x15273Au
#define stage_09_tile_set_3b_script_2_ADDRESS 0x1528B2u
#define stage_09_tile_set_3c_script_0_ADDRESS 0x1529B0u
#define stage_09_tile_set_3c_script_1_ADDRESS 0x1529FDu
#define stage_09_tile_set_3c_script_2_ADDRESS 0x152A41u
#define stage_09_tile_set_3d_script_0_ADDRESS 0x152AD3u
#define stage_09_tile_set_3d_script_1_ADDRESS 0x152B68u
#define stage_09_tile_set_3e_script_0_ADDRESS 0x152BD0u
#define stage_09_tile_set_3e_script_1_ADDRESS 0x152E4Eu
#define stage_09_tile_set_3e_script_2_ADDRESS 0x1530A5u
#define stage_09_tile_set_3f_script_0_ADDRESS 0x15317Eu
#define stage_09_tile_set_3f_script_1_ADDRESS 0x1531CEu
#define stage_09_tile_set_3f_script_2_ADDRESS 0x153233u
#define stage_09_tile_set_40_script_0_ADDRESS 0x1532D8u
#define stage_09_tile_set_40_script_1_ADDRESS 0x153341u
#define stage_09_tile_set_40_script_2_ADDRESS 0x15337Au
#define stage_09_tile_set_41_script_0_ADDRESS 0x153386u
#define stage_09_tile_set_41_script_1_ADDRESS 0x1534FEu
#define stage_09_tile_set_41_script_2_ADDRESS 0x15364Fu
#define stage_09_tile_set_42_script_0_ADDRESS 0x15373Au
#define stage_09_tile_set_42_script_1_ADDRESS 0x15378Au
#define stage_09_tile_set_42_script_2_ADDRESS 0x1537EFu
#define stage_09_tile_set_43_script_0_ADDRESS 0x153894u
#define stage_09_tile_set_43_script_1_ADDRESS 0x1538FDu
#define stage_09_tile_set_43_script_2_ADDRESS 0x153936u
#define stage_09_tile_set_44_script_0_ADDRESS 0x153942u
#define stage_09_tile_set_44_script_1_ADDRESS 0x153ABAu
#define stage_09_tile_set_44_script_2_ADDRESS 0x153C0Bu
#define stage_09_tile_set_45_script_0_ADDRESS 0x153CF6u
#define stage_09_tile_set_45_script_1_ADDRESS 0x153D46u
#define stage_09_tile_set_45_script_2_ADDRESS 0x153DABu
#define stage_09_tile_set_46_script_0_ADDRESS 0x153E50u
#define stage_09_tile_set_46_script_1_ADDRESS 0x153F7Fu
#define stage_09_tile_set_46_script_2_ADDRESS 0x1540AEu
#define stage_09_tile_set_47_script_0_ADDRESS 0x1541C3u
#define stage_09_tile_set_47_script_1_ADDRESS 0x154245u
#define stage_09_tile_set_48_script_0_ADDRESS 0x1542F1u
#define stage_09_tile_set_48_script_1_ADDRESS 0x154402u
#define stage_09_tile_set_48_script_2_ADDRESS 0x1544E7u
#define stage_0a_tile_set_14_script_ADDRESS 0x1545E2u
#define stage_0a_tile_set_15_script_ADDRESS 0x1546FDu
#define stage_0a_tile_set_16_script_ADDRESS 0x154786u
#define stage_0a_tile_set_17_script_ADDRESS 0x1548A1u
#define stage_0a_tile_set_18_script_ADDRESS 0x15492Au
#define stage_0a_tile_set_19_script_0_ADDRESS 0x1549E3u
#define stage_0a_tile_set_19_script_1_ADDRESS 0x154B79u
#define stage_0a_tile_set_1a_script_1_ADDRESS 0x154C71u
#define stage_0a_tile_set_1b_script_ADDRESS 0x154DCDu
#define stage_0a_tile_set_1c_script_0_ADDRESS 0x154EB9u
#define stage_0a_tile_set_1c_script_1_ADDRESS 0x155043u
#define stage_0a_tile_set_1d_script_1_ADDRESS 0x15521Fu
#define stage_0a_tile_set_1e_script_1_ADDRESS 0x15535Bu
#define stage_0a_tile_set_1f_script_0_ADDRESS 0x155397u
#define stage_0a_tile_set_1f_script_1_ADDRESS 0x1554E8u
#define stage_0a_tile_set_20_script_0_ADDRESS 0x155621u
#define stage_0a_tile_set_20_script_1_ADDRESS 0x155718u
#define stage_0a_tile_set_21_script_0_ADDRESS 0x1558F4u
#define stage_0a_tile_set_21_script_1_ADDRESS 0x155996u
#define stage_0a_tile_set_22_script_0_ADDRESS 0x155B5Fu
#define stage_0a_tile_set_22_script_1_ADDRESS 0x155C6Eu
#define stage_0a_tile_set_23_script_0_ADDRESS 0x155CBBu
#define stage_0a_tile_set_24_script_0_ADDRESS 0x155CF2u
#define stage_0a_tile_set_24_script_1_ADDRESS 0x155DCFu
#define stage_0a_tile_set_25_script_0_ADDRESS 0x155E26u
#define stage_0a_tile_set_26_script_1_ADDRESS 0x155E5Du
#define stage_0a_tile_set_27_script_1_ADDRESS 0x1560B5u
#define stage_0a_tile_set_28_script_1_ADDRESS 0x156236u
#define stage_0a_tile_set_29_script_1_ADDRESS 0x1563B7u
#define stage_0a_tile_set_2a_script_ADDRESS 0x156538u
#define stage_0a_tile_set_2b_script_ADDRESS 0x156832u
#define stage_0a_tile_set_2d_script_ADDRESS 0x156B2Cu
#define stage_0a_tile_set_2e_script_0_ADDRESS 0x156E26u
#define stage_0a_tile_set_2e_script_1_ADDRESS 0x156E92u
#define stage_0a_tile_set_2f_script_ADDRESS 0x15705Fu
#define stage_0a_tile_set_30_script_0_ADDRESS 0x1570ECu
#define stage_0a_tile_set_30_script_1_ADDRESS 0x157246u
#define stage_0a_tile_set_31_script_ADDRESS 0x1572A0u
#define stage_0a_tile_set_32_script_0_ADDRESS 0x1572FDu
#define stage_0a_tile_set_33_script_0_ADDRESS 0x157357u
#define stage_0a_tile_set_34_script_0_ADDRESS 0x15754Du
#define stage_0a_tile_set_35_script_0_ADDRESS 0x15760Eu
#define stage_0a_tile_set_36_script_0_ADDRESS 0x157668u
#define stage_0a_tile_set_37_script_0_ADDRESS 0x157807u
#define stage_0a_tile_set_38_script_0_ADDRESS 0x1578B4u
#define stage_0a_tile_set_38_script_1_ADDRESS 0x157984u
#define stage_0a_tile_set_39_script_0_ADDRESS 0x1579D8u
#define stage_0a_tile_set_39_script_1_ADDRESS 0x157A63u
#define stage_0a_tile_set_3a_script_0_ADDRESS 0x157B03u
#define stage_0a_tile_set_3a_script_1_ADDRESS 0x157B7Cu
#define stage_0a_tile_set_3b_script_0_ADDRESS 0x157BEEu
#define stage_0a_tile_set_3b_script_1_ADDRESS 0x157E70u
#define stage_0a_tile_set_3c_script_0_ADDRESS 0x157F10u
#define stage_0a_tile_set_3c_script_1_ADDRESS 0x158149u
#define stage_0a_tile_set_3d_script_0_ADDRESS 0x15822Du
#define stage_0a_tile_set_3d_script_1_ADDRESS 0x158363u
#define stage_0a_tile_set_3e_script_0_ADDRESS 0x15845Au
#define stage_0a_tile_set_3e_script_1_ADDRESS 0x15850Fu
#define stage_0a_tile_set_3f_script_ADDRESS 0x158563u
#define stage_0a_tile_set_40_script_0_ADDRESS 0x15866Eu
#define stage_0a_tile_set_41_script_0_ADDRESS 0x1587B7u
#define stage_0a_tile_set_41_script_1_ADDRESS 0x1587D8u
#define stage_0a_tile_set_42_script_0_ADDRESS 0x15880Au
#define stage_0a_tile_set_42_script_1_ADDRESS 0x15899Du
#define stage_0a_tile_set_43_script_0_ADDRESS 0x1589FBu
#define stage_0a_tile_set_1a_script_0_ADDRESS 0x158B8Au
#define stage_0a_tile_set_1d_script_0_ADDRESS 0x158BABu
#define stage_0a_tile_set_44_script_ADDRESS 0x158BCCu
#define stage_0a_tile_set_45_script_ADDRESS 0x158C08u
#define stage_0a_tile_set_19_script_2_ADDRESS 0x158C44u
#define stage_0a_tile_set_1f_script_2_ADDRESS 0x158D1Du
#define stage_0a_tile_set_22_script_2_ADDRESS 0x158DC4u
#define stage_0c_nbg3_script_ADDRESS 0x158E53u
#define stage_0d_nbg3_script_ADDRESS 0x15902Bu
#define stage_0e_nbg3_script_ADDRESS 0x1593D4u
#define stage_0f_nbg3_script_ADDRESS 0x15979Cu
#define stage_0b_tile_set_14_script_ADDRESS 0x15997Au
#define stage_0b_tile_set_15_script_ADDRESS 0x159AB6u
#define stage_0b_tile_set_16_script_ADDRESS 0x159D6Du
#define stage_0b_tile_set_17_script_ADDRESS 0x159EBBu
#define stage_0b_tile_set_18_script_ADDRESS 0x15A18Bu
#define stage_0b_tile_set_19_script_0_ADDRESS 0x15A2D4u
#define stage_0b_tile_set_19_script_1_ADDRESS 0x15A58Fu
#define stage_0b_tile_set_1a_script_0_ADDRESS 0x15A5B7u
#define stage_0b_tile_set_1a_script_1_ADDRESS 0x15A7A3u
#define stage_0b_tile_set_1b_script_0_ADDRESS 0x15A951u
#define stage_0b_tile_set_1b_script_1_ADDRESS 0x15A95Du
#define stage_0b_tile_set_1c_script_0_ADDRESS 0x15A9BAu
#define stage_0b_tile_set_1c_script_1_ADDRESS 0x15AB0Eu
#define stage_0b_tile_set_1d_script_0_ADDRESS 0x15ABCDu
#define stage_0b_tile_set_1d_script_1_ADDRESS 0x15AC10u
#define stage_0b_tile_set_1e_script_0_ADDRESS 0x15AD02u
#define stage_0b_tile_set_1e_script_1_ADDRESS 0x15AF32u
#define stage_0b_tile_set_1f_script_0_ADDRESS 0x15B01Cu
#define stage_0b_tile_set_1f_script_1_ADDRESS 0x15B288u
#define stage_0b_tile_set_20_script_0_ADDRESS 0x15B3D6u
#define stage_0b_tile_set_20_script_1_ADDRESS 0x15B47Bu
#define stage_0b_tile_set_21_script_0_ADDRESS 0x15B62Bu
#define stage_0b_tile_set_21_script_1_ADDRESS 0x15B740u
#define stage_0b_tile_set_22_script_0_ADDRESS 0x15B905u
#define stage_0b_tile_set_22_script_1_ADDRESS 0x15BA59u
#define stage_0b_tile_set_23_script_0_ADDRESS 0x15BB18u
#define stage_0b_tile_set_23_script_1_ADDRESS 0x15BB5Bu
#define stage_0b_tile_set_24_script_0_ADDRESS 0x15BC4Du
#define stage_0b_tile_set_24_script_1_ADDRESS 0x15BE7Du
#define stage_0b_tile_set_25_script_0_ADDRESS 0x15BF67u
#define stage_0b_tile_set_25_script_1_ADDRESS 0x15C1D3u
#define stage_0b_tile_set_26_script_0_ADDRESS 0x15C321u
#define stage_0b_tile_set_26_script_1_ADDRESS 0x15C3C6u
#define stage_0b_tile_set_27_script_0_ADDRESS 0x15C576u
#define stage_0b_tile_set_27_script_1_ADDRESS 0x15C68Bu
#define stage_0b_tile_set_28_script_0_ADDRESS 0x15C850u
#define stage_0b_tile_set_28_script_1_ADDRESS 0x15CB37u
#define stage_0b_tile_set_29_script_0_ADDRESS 0x15CBC3u
#define stage_0b_tile_set_2a_script_0_ADDRESS 0x15CC6Fu
#define stage_0b_tile_set_2b_script_0_ADDRESS 0x15CCACu
#define stage_0b_tile_set_2c_script_0_ADDRESS 0x15CDAEu
#define stage_0b_tile_set_2d_script_0_ADDRESS 0x15CDEBu
#define stage_0b_tile_set_2d_script_1_ADDRESS 0x15D05Au
#define stage_0b_tile_set_2e_script_0_ADDRESS 0x15D08Bu
#define stage_0b_tile_set_2f_script_ADDRESS 0x15D10Du
#define stage_0b_tile_set_30_script_ADDRESS 0x15D31Bu
#define stage_0b_tile_set_31_script_ADDRESS 0x15D4D4u
#define stage_0b_tile_set_32_script_ADDRESS 0x15D5C9u
#define stage_0b_tile_set_33_script_ADDRESS 0x15D9C6u
#define stage_0b_tile_set_34_script_ADDRESS 0x15DC8Fu
#define stage_0b_tile_set_35_script_ADDRESS 0x15DE3Bu
#define stage_0b_tile_set_36_script_ADDRESS 0x15E1A6u
#define stage_0b_tile_set_37_script_ADDRESS 0x15E358u
#define stage_0b_tile_set_38_script_ADDRESS 0x15E4B9u
#define stage_0b_tile_set_39_script_ADDRESS 0x15E8CEu
#define stage_0b_tile_set_3a_script_ADDRESS 0x15EAE4u
#define stage_0b_tile_set_3b_script_ADDRESS 0x15ED1Cu
#define stage_0b_tile_set_3c_script_ADDRESS 0x15EECAu
#define stage_0b_tile_set_3d_script_ADDRESS 0x15F0DEu
#define stage_0b_tile_set_3e_script_ADDRESS 0x15F13Du
#define stage_0b_tile_set_3f_script_ADDRESS 0x15F336u
#define stage_0b_tile_set_40_script_ADDRESS 0x15F461u
#define stage_0b_tile_set_41_script_ADDRESS 0x15F4CAu
#define stage_0b_tile_set_42_script_ADDRESS 0x15F6ACu
#define stage_0b_tile_set_43_script_ADDRESS 0x15F81Bu
#define stage_0b_tile_set_44_script_ADDRESS 0x15F835u
#define stage_0b_tile_set_45_script_ADDRESS 0x15F919u
#define stage_0b_tile_set_46_script_ADDRESS 0x15FB36u
#define stage_0b_tile_set_47_script_ADDRESS 0x15FB97u
#define stage_0b_tile_set_48_script_ADDRESS 0x15FBB5u
#define stage_0b_tile_set_49_script_ADDRESS 0x15FD6Bu
#define stage_0b_tile_set_4a_script_ADDRESS 0x15FF9Au
#define stage_0b_tile_set_4b_script_ADDRESS 0x15FFF7u
#define stage_0b_tile_set_4c_script_ADDRESS 0x160015u
#define stage_0b_tile_set_4d_script_ADDRESS 0x1601CBu
#define stage_0b_tile_set_4e_script_ADDRESS 0x1603FAu
#define stage_0b_tile_set_4f_script_ADDRESS 0x160457u
#define stage_0b_tile_set_50_script_ADDRESS 0x1606ACu
#define stage_0b_tile_set_51_script_ADDRESS 0x1609CBu
#define stage_0b_tile_set_52_script_ADDRESS 0x160CA9u
#define stage_0b_tile_set_53_script_ADDRESS 0x160DC2u
#define stage_0b_tile_set_54_script_ADDRESS 0x160E21u
#define stage_0b_tile_set_55_script_ADDRESS 0x16111Cu
#define stage_0b_tile_set_56_script_ADDRESS 0x1612C7u
#define stage_0b_tile_set_57_script_ADDRESS 0x161330u
#define stage_0b_tile_set_58_script_ADDRESS 0x1615D3u
#define stage_0b_tile_set_59_script_ADDRESS 0x161823u
#define stage_0b_tile_set_5a_script_ADDRESS 0x161849u
#define stage_0b_tile_set_5b_script_ADDRESS 0x161977u
#define stage_0b_tile_set_5c_script_ADDRESS 0x161CEBu
#define stage_0b_tile_set_5d_script_ADDRESS 0x161DA2u
#define stage_0b_tile_set_5e_script_ADDRESS 0x161DC0u
#define stage_0b_tile_set_5f_script_ADDRESS 0x161FD5u
#define stage_0b_tile_set_60_script_ADDRESS 0x16233Eu
#define stage_0b_tile_set_61_script_ADDRESS 0x1623E0u
#define stage_0b_tile_set_62_script_ADDRESS 0x1623FEu
#define stage_0b_tile_set_63_script_ADDRESS 0x162613u
#define stage_0b_tile_set_64_script_ADDRESS 0x16297Cu
#define stage_0b_tile_set_65_script_ADDRESS 0x162A1Eu
#define stage_0b_tile_set_66_script_ADDRESS 0x162C73u
#define stage_0b_tile_set_67_script_ADDRESS 0x162F92u
#define stage_0b_tile_set_68_script_ADDRESS 0x1632B1u
#define stage_0b_tile_set_69_script_0_ADDRESS 0x163436u
#define stage_0b_tile_set_69_script_1_ADDRESS 0x1634D4u
#define stage_10_tile_set_14_script_ADDRESS 0x16360Du
#define stage_10_tile_set_16_script_ADDRESS 0x1636BFu
#define stage_10_tile_set_17_script_ADDRESS 0x1637D1u
#define stage_10_tile_set_18_script_ADDRESS 0x1638C9u
#define stage_10_tile_set_19_script_1_ADDRESS 0x1639EDu
#define stage_10_tile_set_19_script_0_ADDRESS 0x163A8Eu
#define stage_10_tile_set_1a_script_1_ADDRESS 0x163CECu
#define stage_10_tile_set_1a_script_0_ADDRESS 0x163F9Au
#define stage_10_tile_set_1b_script_1_ADDRESS 0x164299u
#define stage_10_tile_set_1b_script_0_ADDRESS 0x164312u
#define stage_10_tile_set_1c_script_1_ADDRESS 0x164491u
#define stage_10_tile_set_1c_script_0_ADDRESS 0x164532u
#define stage_10_tile_set_1d_script_1_ADDRESS 0x16463Au
#define stage_10_tile_set_1d_script_0_ADDRESS 0x1646DBu
#define stage_10_tile_set_1e_script_1_ADDRESS 0x1647E3u
#define stage_10_tile_set_1e_script_0_ADDRESS 0x164A91u
#define stage_10_tile_set_1f_script_1_ADDRESS 0x164D90u
#define stage_10_tile_set_1f_script_0_ADDRESS 0x164E09u
#define stage_10_tile_set_20_script_1_ADDRESS 0x164F88u
#define stage_10_tile_set_20_script_0_ADDRESS 0x165236u
#define stage_10_tile_set_21_script_1_ADDRESS 0x165557u
#define stage_10_tile_set_21_script_0_ADDRESS 0x1655F8u
#define stage_10_tile_set_22_script_1_ADDRESS 0x16573Cu
#define stage_10_tile_set_22_script_0_ADDRESS 0x1658E9u
#define stage_10_tile_set_23_script_1_ADDRESS 0x165AF5u
#define stage_10_tile_set_23_script_0_ADDRESS 0x165B96u
#define stage_10_tile_set_24_script_0_ADDRESS 0x165DBEu
#define stage_10_tile_set_25_script_0_ADDRESS 0x166048u
#define stage_10_tile_set_26_script_0_ADDRESS 0x166310u
#define stage_10_tile_set_26_script_1_ADDRESS 0x16644Du
#define stage_10_tile_set_27_script_0_ADDRESS 0x1667B0u
#define stage_10_tile_set_28_script_0_ADDRESS 0x166A2Cu
#define stage_10_tile_set_29_script_0_ADDRESS 0x166CA8u
#define stage_10_tile_set_29_script_1_ADDRESS 0x166D96u
#define stage_10_tile_set_2a_script_0_ADDRESS 0x166DE6u
#define stage_10_tile_set_2a_script_1_ADDRESS 0x166F24u
#define stage_10_tile_set_2b_script_0_ADDRESS 0x167287u
#define stage_10_tile_set_2b_script_1_ADDRESS 0x167375u
#define stage_10_tile_set_2c_script_0_ADDRESS 0x1673C5u
#define stage_10_tile_set_2c_script_1_ADDRESS 0x167503u
#define stage_10_tile_set_2d_script_0_ADDRESS 0x167784u
#define stage_10_tile_set_2e_script_0_ADDRESS 0x1679DCu
#define stage_10_tile_set_2e_script_1_ADDRESS 0x167BFFu
#define stage_10_tile_set_2f_script_0_ADDRESS 0x167D94u
#define stage_10_tile_set_2f_script_1_ADDRESS 0x167DEFu
#define stage_10_tile_set_30_script_0_ADDRESS 0x16816Fu
#define stage_10_tile_set_31_script_0_ADDRESS 0x16821Cu
#define stage_10_tile_set_32_script_0_ADDRESS 0x168242u
#define stage_10_tile_set_32_script_1_ADDRESS 0x16847Eu
#define stage_10_tile_set_33_script_0_ADDRESS 0x168613u
#define stage_10_tile_set_33_script_1_ADDRESS 0x16866Eu
#define stage_10_tile_set_34_script_0_ADDRESS 0x1689F6u
#define stage_10_tile_set_35_script_0_ADDRESS 0x168B47u
#define stage_10_tile_set_36_script_0_ADDRESS 0x168D3Au
#define stage_10_tile_set_36_script_1_ADDRESS 0x168E84u
#define stage_10_tile_set_37_script_0_ADDRESS 0x168FDCu
#define stage_08_tile_set_14_script_1_ADDRESS 0x169002u
#define stage_08_tile_set_15_script_0_ADDRESS 0x169119u
#define stage_08_tile_set_15_script_1_ADDRESS 0x169172u
#define stage_08_tile_set_16_script_0_ADDRESS 0x1691F4u
#define stage_08_tile_set_17_script_0_ADDRESS 0x169213u
#define stage_08_tile_set_18_script_0_ADDRESS 0x16933Cu
#define stage_08_tile_set_18_script_1_ADDRESS 0x1693AAu
#define stage_08_tile_set_19_script_0_ADDRESS 0x169613u
#define stage_08_tile_set_19_script_1_ADDRESS 0x1697B9u
#define stage_08_tile_set_1a_script_0_ADDRESS 0x1699C6u
#define stage_08_tile_set_1a_script_1_ADDRESS 0x169B31u
#define stage_08_tile_set_1b_script_0_ADDRESS 0x169BA7u
#define stage_08_tile_set_1c_script_0_ADDRESS 0x169BC6u
#define stage_08_tile_set_1d_script_0_ADDRESS 0x169BE0u
#define stage_08_tile_set_1e_script_0_ADDRESS 0x169D4Au
#define stage_08_tile_set_1e_script_1_ADDRESS 0x169DC8u
#define stage_08_tile_set_1f_script_0_ADDRESS 0x16A0AFu
#define stage_08_tile_set_1f_script_1_ADDRESS 0x16A255u
#define stage_08_tile_set_20_script_0_ADDRESS 0x16A462u
#define stage_08_tile_set_20_script_1_ADDRESS 0x16A5CDu
#define stage_08_tile_set_21_script_0_ADDRESS 0x16A643u
#define stage_08_tile_set_22_script_0_ADDRESS 0x16A65Du
#define stage_08_tile_set_23_script_0_ADDRESS 0x16A7C7u
#define stage_08_tile_set_23_script_1_ADDRESS 0x16A845u
#define stage_08_tile_set_24_script_0_ADDRESS 0x16AB2Cu
#define stage_08_tile_set_24_script_1_ADDRESS 0x16ABAAu
#define stage_08_tile_set_25_script_0_ADDRESS 0x16AE85u
#define stage_08_tile_set_25_script_1_ADDRESS 0x16AFDCu
#define stage_08_tile_set_26_script_0_ADDRESS 0x16B1F5u
#define stage_08_tile_set_26_script_1_ADDRESS 0x16B334u
#define stage_08_tile_set_27_script_0_ADDRESS 0x16B4B3u
#define stage_08_tile_set_27_script_1_ADDRESS 0x16B568u
#define stage_08_tile_set_28_script_0_ADDRESS 0x16B6FBu
#define stage_08_tile_set_28_script_1_ADDRESS 0x16B7B0u
#define stage_08_tile_set_29_script_0_ADDRESS 0x16B943u
#define stage_08_tile_set_2a_script_0_ADDRESS 0x16BA6Du
#define stage_08_tile_set_2a_script_1_ADDRESS 0x16BAABu
#define stage_08_tile_set_2b_script_0_ADDRESS 0x16BEAAu
#define stage_08_tile_set_2b_script_1_ADDRESS 0x16BEFEu
#define stage_08_tile_set_2d_script_0_ADDRESS 0x16C31Du
#define stage_08_tile_set_2e_script_0_ADDRESS 0x16C719u
#define stage_08_tile_set_2f_script_0_ADDRESS 0x16CB15u
#define stage_08_tile_set_30_script_0_ADDRESS 0x16CE31u
#define stage_08_tile_set_31_script_0_ADDRESS 0x16CFCFu
#define stage_08_tile_set_32_script_0_ADDRESS 0x16D059u
#define stage_08_tile_set_32_script_1_ADDRESS 0x16D093u
#define stage_08_tile_set_33_script_0_ADDRESS 0x16D402u
#define stage_08_tile_set_33_script_1_ADDRESS 0x16D614u
#define stage_08_tile_set_34_script_0_ADDRESS 0x16D800u
#define stage_08_tile_set_35_script_0_ADDRESS 0x16D84Eu
#define stage_08_tile_set_36_script_0_ADDRESS 0x16D8D8u
#define stage_08_tile_set_36_script_1_ADDRESS 0x16D915u
#define stage_08_tile_set_37_script_0_ADDRESS 0x16DC84u
#define stage_08_tile_set_37_script_1_ADDRESS 0x16DE96u
#define stage_08_tile_set_38_script_0_ADDRESS 0x16E082u
#define stage_08_tile_set_39_script_0_ADDRESS 0x16E0D0u
#define stage_08_tile_set_3a_script_0_ADDRESS 0x16E217u
#define stage_08_tile_set_3a_script_1_ADDRESS 0x16E46Au
#define stage_08_tile_set_3b_script_0_ADDRESS 0x16E62Fu
#define stage_08_tile_set_3c_script_0_ADDRESS 0x16E88Eu
#define stage_08_tile_set_3c_script_1_ADDRESS 0x16E99Cu
#define stage_08_tile_set_3d_script_0_ADDRESS 0x16ECD9u
#define stage_08_tile_set_3d_script_1_ADDRESS 0x16EE6Eu
#define stage_08_tile_set_3e_script_0_ADDRESS 0x16F115u
#define stage_08_tile_set_3e_script_1_ADDRESS 0x16F2AAu
#define stage_08_tile_set_3f_script_0_ADDRESS 0x16F400u
#define stage_08_tile_set_40_script_0_ADDRESS 0x16F4B8u
#define stage_08_tile_set_40_script_1_ADDRESS 0x16F54Du
#define stage_08_tile_set_41_script_0_ADDRESS 0x16F70Bu
#define stage_08_tile_set_41_script_1_ADDRESS 0x16F951u
#define stage_08_tile_set_42_script_0_ADDRESS 0x16F9A0u
#define stage_08_tile_set_43_script_0_ADDRESS 0x16FA54u
#define stage_08_tile_set_43_script_1_ADDRESS 0x16FAE9u
#define stage_08_tile_set_44_script_0_ADDRESS 0x16FC86u
#define stage_08_tile_set_44_script_1_ADDRESS 0x16FECCu
#define stage_08_tile_set_45_script_0_ADDRESS 0x16FF1Bu
#define stage_08_tile_set_46_script_0_ADDRESS 0x16FFCFu
#define stage_08_tile_set_46_script_1_ADDRESS 0x170064u
#define stage_08_tile_set_47_script_0_ADDRESS 0x170201u
#define stage_08_tile_set_48_script_0_ADDRESS 0x17030Fu
#define stage_08_tile_set_48_script_1_ADDRESS 0x1703A4u
#define blank_tile_set_list_offsets_ADDRESS 0x1705DAu
#define blank_tile_set_lists_ADDRESS 0x170602u
#define clear_tile_page_00_script_ADDRESS 0x17064Au
#define clear_tile_page_01_script_ADDRESS 0x170662u
#define clear_tile_page_02_script_ADDRESS 0x17067Au
#define clear_tile_page_03_script_ADDRESS 0x170692u
#define unused_clear_tile_page_03_script_ADDRESS 0x1706AAu
#define clear_tile_page_0a_script_ADDRESS 0x1706C2u
#define clear_tile_page_0b_script_ADDRESS 0x1706DAu
#define clear_tile_page_0c_script_ADDRESS 0x1706F2u
#define clear_tile_page_0d_script_ADDRESS 0x17070Au
#define clear_tile_page_0f_script_ADDRESS 0x170722u
#define clear_tile_page_10_script_ADDRESS 0x17073Au
#define clear_tile_page_11_script_ADDRESS 0x170752u
#define clear_tile_page_12_script_ADDRESS 0x17076Au
#define clear_tile_page_05_script_ADDRESS 0x170782u
#define clear_tile_page_06_script_ADDRESS 0x17079Au
#define clear_tile_page_07_script_ADDRESS 0x1707B2u
#define clear_tile_page_08_script_ADDRESS 0x1707CAu
#define stage_00_tower_top_page_1_script_ADDRESS 0x1707E2u
#define stage_00_tower_top_page_3_script_ADDRESS 0x170819u
#define stage_00_tower_top_page_0_script_ADDRESS 0x17098Au
#define stage_00_tower_top_page_2_script_ADDRESS 0x170BC1u
#define stage_00_exit_tower_wall_script_ADDRESS 0x170D3Bu
#define stage_00_exit_beam_script_ADDRESS 0x170E58u
#define stage_00_exit_beam_end_script_ADDRESS 0x170EE5u
#define stage_00_exit_zoom_page_0_script_ADDRESS 0x170F35u
#define stage_00_exit_zoom_page_1_script_ADDRESS 0x171242u
#define stage_00_exit_zoom_page_2_script_ADDRESS 0x1712D4u
#define cloudy_horizon_script_ADDRESS 0x1715D3u
#define stage_06_island_tower_script_ADDRESS 0x171663u
#define stage_06_upper_jaw_script_ADDRESS 0x1716C1u
#define stage_06_lower_jaw_script_ADDRESS 0x17176Eu
#define stage_06_forest_script_ADDRESS 0x171882u
#define stage_00_coast_script_ADDRESS 0x1718B6u
#define stage_00_horizon_script_ADDRESS 0x171BABu
#define blue_sky_script_ADDRESS 0x171BEBu
#define aerial_city_script_ADDRESS 0x171C77u
#define default_nbg3_script_ADDRESS 0x172005u
#define unused_tiles_0d00_page_05_script_ADDRESS 0x172055u
#define unused_tiles_0d00_page_06_script_ADDRESS 0x1720E5u
#define stage_04_nbg3_script_ADDRESS 0x172175u
#define stage_04_nbg3_fill_script_ADDRESS 0x1721B9u
#define map_monitor_script_ADDRESS 0x1721D1u
#define map_eggman_head_script_ADDRESS 0x172339u
#define unused_tiles_0700_page_00_script_ADDRESS 0x17235Eu
#define stage_0a_nbg3_script_ADDRESS 0x172386u
#define stage_10_nbg3_script_ADDRESS 0x17242Au
#define ending_eggman_machine_script_ADDRESS 0x1725B2u
#define ending_stripes_script_ADDRESS 0x172653u
#define sonic_head_pattern_script_ADDRESS 0x17280Au
#define ending_logo_script_ADDRESS 0x1729B2u
#define ending_bars_script_ADDRESS 0x172A84u
#define unused_tiles_1700_page_05_script_ADDRESS 0x172AA5u
#define winners_dont_use_drugs_script_ADDRESS 0x172B46u
#define recycle_it_script_ADDRESS 0x172C25u
#define stage_08_nbg3_script_ADDRESS 0x172CEDu
#define title_sky_script_ADDRESS 0x172D11u
#define title_waving_background_script_ADDRESS 0x172D41u

/* numbers the code uses, by name (symbols.txt constant lines) */
#define FRAMES_PER_SECOND 0x3Cu
#define FRAMES_PER_MINUTE 0xDFBu
#define IC8_BYTES 0x1F000u
#define IC17_BYTES 0x20000u
#define STAGE_05_SWITCHED_TILE_SETS 0x32A03u
#define FRAMES_PER_HOUR 0x346A7u
#define IC9_BYTES 0x3FFFFu
#define IC18_BYTES 0x40000u
#define IC8_START 0x80000u
#define INITIALS_TAK 0xA0013u
#define IC18_START 0x100000u
#define IC9_START 0x100001u
#define INITIALS_SEX 0x170412u
#define INITIALS_XXX 0x171717u
#define INITIALS_X_X 0x172B17u
#define INITIALS_XX_ 0x2B1717u
#define FRAMES_PER_DAY 0x4E9FA0u

/* the game's structures in work RAM */
#pragma pack(push, 1)
struct object
{
	union
	{
		u32le credit_part_slot;
		u16le draw_next;
		struct
		{
			uint8_t pad_00[0x2];
			u16le sprite_flags;
		};
	};
	union
	{
		u32le part_list;
		u16le sprite_frame;
		struct
		{
			uint8_t pad_04[0x2];
			u16le sprite_palette;
		};
	};
	u16le sprite_scale;
	u16le sprite_layer;
	s16le screen_y;
	s16le screen_x;
	union
	{
		struct
		{
			union
			{
				u16le hitbox_size_x;
				uint8_t shadow_blink;
			};
			union
			{
				u16le hitbox_size_y;
				int8_t hitbox_centre_x;
				struct
				{
					uint8_t pad_12[0x1];
					int8_t hitbox_centre_y;
				};
			};
			s16le anchor_x;
			s16le anchor_y;
			s16le sprite_height;
			s16le sprite_width;
			union
			{
				u32le handler;
				u16le handler_low;
				struct
				{
					uint8_t pad_1C[0x2];
					u16le handler_high;
				};
			};
			u16le previous;
			u16le next;
			union
			{
				u16le direction;
				uint8_t direction_low;
				struct
				{
					uint8_t pad_24[0x1];
					uint8_t direction_high;
				};
			};
			union
			{
				u16le parent;
				struct
				{
					uint8_t pad_26[0x1];
					int8_t hud_anim_timer;
				};
			};
			union
			{
				u32le hud_anim;
				u16le child;
				struct
				{
					uint8_t pad_28[0x2];
					union
					{
						s16le projected_x;
						uint8_t letter_fraction;
						struct
						{
							uint8_t pad_2A[0x1];
							int8_t letter_code;
						};
					};
				};
			};
			union
			{
				s32le projected_y;
				int8_t hud_anim_repeats;
				u16le projected_y_fraction;
				struct
				{
					uint8_t pad_2C[0x1];
					int8_t piece_frame;
					union
					{
						s16le projected_y_int;
						uint8_t piece_value;
					};
				};
			};
			union
			{
				u32le flags;
				uint8_t flags_low_byte;
				u16le flags_low;
				struct
				{
					uint8_t pad_30[0x1];
					uint8_t step;
					s16le timer;
				};
			};
			union
			{
				s32le speed_x;
				uint8_t speed_x_low_byte;
				u16le speed_x_fraction;
				struct
				{
					uint8_t pad_34[0x2];
					s16le speed_x_int;
				};
			};
			union
			{
				s32le speed_y;
				u16le speed_y_fraction;
				struct
				{
					uint8_t pad_38[0x2];
					s16le speed_y_int;
				};
			};
			union
			{
				s32le speed_z;
				u16le speed_z_fraction;
				struct
				{
					uint8_t pad_3C[0x2];
					s16le speed_z_int;
				};
			};
			union
			{
				s32le z;
				u16le z_fraction;
				struct
				{
					uint8_t pad_40[0x2];
					s16le z_int;
				};
			};
			uint8_t animation_speed;
			int8_t animation_timer;
			uint8_t animation_frame;
			uint8_t kind;
			u32le animation;
			union
			{
				s32le x;
				u16le x_fraction;
				struct
				{
					uint8_t pad_4C[0x2];
					s16le x_int;
				};
			};
			union
			{
				s32le y;
				u16le y_fraction;
				struct
				{
					uint8_t pad_50[0x2];
					s16le y_int;
				};
			};
			union
			{
				s32le floor_z;
				u16le floor_z_fraction;
				struct
				{
					uint8_t pad_54[0x2];
					s16le floor_z_int;
				};
			};
			union
			{
				s32le previous_floor_z;
				u16le previous_floor_z_fraction;
				struct
				{
					uint8_t pad_58[0x2];
					s16le previous_floor_z_int;
				};
			};
			s32le floor_block;
			union
			{
				s32le previous_floor_block;
				struct
				{
					uint8_t pad_60[0x2];
					u16le cycle_count;
				};
			};
			int8_t sprite_offset_x;
			int8_t sprite_offset_y;
			union
			{
				u16le hitbox_height;
				struct
				{
					uint8_t pad_66[0x1];
					uint8_t tally_gets_bonus;
				};
			};
			u16le hit_list_next;
			union
			{
				u16le touched_by;
				uint8_t tally_character;
			};
			s16le touch_distance;
			union
			{
				s32le speed;
				uint8_t member_state;
				u16le speed_fraction;
				struct
				{
					uint8_t pad_6E[0x1];
					uint8_t member_number;
					s16le speed_int;
				};
			};
			u16le platform_list_next;
			u16le platform;
			uint8_t floor_slope;
			uint8_t floor_type;
			u16le wall;
			u16le floor_attribute;
			int8_t hitbox_offset_x;
			int8_t hitbox_offset_y;
			int8_t health;
			uint8_t var_7F;
			uint8_t var_80;
			uint8_t var_81;
			union
			{
				u16le var_82;
				uint8_t var_82_low;
				struct
				{
					uint8_t pad_82[0x1];
					uint8_t var_83;
				};
			};
			union
			{
				u16le var_84;
				uint8_t var_84_low;
				struct
				{
					uint8_t pad_84[0x1];
					uint8_t var_85;
				};
			};
			u16le var_86;
			union
			{
				u16le draw_depth;
				uint8_t var_88_low;
			};
			u16le var_8A;
			u16le var_8C;
			uint8_t var_8E;
			uint8_t var_8F;
			union
			{
				u16le var_90;
				struct
				{
					uint8_t pad_90[0x1];
					uint8_t var_91;
				};
			};
			union
			{
				u16le spawn_arg_1;
				uint8_t spawn_arg_1_low;
				struct
				{
					uint8_t pad_92[0x1];
					uint8_t spawn_arg_1_high;
				};
			};
			union
			{
				u16le spawn_arg_2;
				uint8_t spawn_arg_2_low;
				struct
				{
					uint8_t pad_94[0x1];
					uint8_t spawn_arg_2_high;
				};
			};
			u16le var_96;
			union
			{
				u16le var_98;
				struct
				{
					uint8_t pad_98[0x1];
					uint8_t var_99;
				};
			};
			union
			{
				u16le var_9A;
				uint8_t player;
			};
			u32le next_handler;
		};
		struct
		{
			uint8_t pad_10[0x22];
			s16le timer;
			uint8_t pad_34[0x4];
			u32le legs;
			uint8_t pad_3C[0x10];
			u32le body_frames;
			u32le leg_frames;
			uint8_t pad_54[0xC];
			int8_t frame_index;
			uint8_t pad_61[0x1];
			u16le cycle_count;
		} animate_ending;
		struct
		{
			uint8_t pad_10[0x22];
			uint8_t timer_low;
		} animate_ending_debris;
		struct
		{
			uint8_t pad_10[0x50];
			uint8_t frame_index;
		} animate_horizon_blast;
		struct
		{
			uint8_t pad_10[0x15];
			uint8_t frame;
			uint8_t anim_delay;
			int8_t anim_timer;
			u32le anim;
		} animate_hud;
		struct
		{
			uint8_t pad_10[0x70];
			u32le palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
		} animate_sign;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t sink_step;
		} animate_sinking_mine;
		struct
		{
			uint8_t pad_10[0x50];
			uint8_t frame_index;
		} animate_tower_blast;
		struct
		{
			uint8_t pad_10[0x38];
			uint8_t bite_step;
			int8_t bite_timer;
			uint8_t bob_counter;
			int8_t bounce_index;
			uint8_t pad_4C[0x34];
			u32le path;
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
		} biting_head_view;
		struct
		{
			uint8_t pad_10[0x20];
			u16le step_timer;
		} blink_current_map_marker;
		struct
		{
			uint8_t pad_10[0x70];
			u16le draw_depth;
		} board_prop;
		struct
		{
			uint8_t pad_10[0x70];
			s16le wait_timer;
		} boulder;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			u16le frame_timer;
		} breakable_panel;
		struct
		{
			uint8_t pad_10[0x70];
			s16le wait_timer;
		} brick_dust;
		struct
		{
			uint8_t pad_10[0x6F];
			uint8_t state;
			u32le path;
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
			union
			{
				s32le fixed_projected_x;
				u16le projected_x_fraction;
				struct
				{
					uint8_t pad_94[0x2];
					s16le projected_x_whole;
				};
			};
			uint8_t off_screen;
			uint8_t sound_timer;
		} bridge_fire;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			u16le frame_timer;
		} bubble_column;
		struct
		{
			uint8_t pad_10[0x74];
			u16le draw_depth;
		} bubble_near_parent_update;
		struct
		{
			uint8_t pad_10[0x70];
			u16le base_x;
			u16le base_y;
			u16le draw_depth;
			u16le variant;
		} bubble_pop;
		struct
		{
			uint8_t pad_10[0x70];
			u16le base_x;
			u16le base_y;
			uint8_t pad_84[0x2];
			u16le variant;
		} bubble_start;
		struct
		{
			uint8_t pad_10[0x74];
			u16le draw_depth;
		} bubble_update;
		struct
		{
			uint8_t pad_10[0x70];
			s16le rows_left;
			s32le row_projected_y;
			uint8_t pad_86[0xE];
			union
			{
				s32le row_projected_x;
				struct
				{
					uint8_t pad_94[0x2];
					s16le row_projected_x_whole;
				};
			};
		} build_grate_steps;
		struct
		{
			uint8_t pad_10[0x28];
			u32le bonus_label;
			uint8_t pad_3C[0x4];
			u32le backdrop;
			u32le part_3;
			u32le units_digit;
			u32le tens_digit;
			u32le hundreds_digit;
			uint8_t pad_54[0x8];
			u32le result_frames;
			uint8_t pad_60[0x7];
			uint8_t gets_bonus;
		} build_ring_tally_panel;
		struct
		{
			uint8_t pad_10[0x84];
			union
			{
				s32le fixed_projected_x;
				u16le projected_x_fraction;
				struct
				{
					uint8_t pad_94[0x2];
					s16le projected_x_whole;
				};
			};
		} build_saw_shaft_base;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t invisible;
			uint8_t no_second_sprite;
		} build_wall_parts;
		struct
		{
			uint8_t pad_10[0x4E];
			s16le floor_block_high;
			uint8_t pad_60[0x20];
			union
			{
				u32le path;
				struct
				{
					uint8_t pad_80[0x2];
					u16le path_high;
				};
			};
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
			uint8_t pad_94[0x2];
			uint8_t state;
			uint8_t rumble_timer;
			s16le start_delay;
			u16le draw_depth;
			u16le depth_offset;
			s16le slow_timer;
		} burning_boulder;
		struct
		{
			uint8_t pad_10[0x16];
			u16le boulder;
			uint8_t pad_28[0x58];
			s16le offset_x;
			s16le offset_y;
			s16le pause_timer;
		} burning_boulder_flame;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x58];
			uint8_t step;
			uint8_t pad_81[0x1];
			u16le step_timer;
		} button_box;
		struct
		{
			uint8_t pad_10[0x71];
			uint8_t lifted;
			u16le angle;
			u16le spiral_speed;
		} cactus;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
		} cage_bar;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t glint_timer;
			uint8_t glint_timer_high;
			u16le hover_height;
		} carried_ring;
		struct
		{
			uint8_t pad_10[0x24];
			uint8_t state;
			uint8_t pad_35[0x1];
			u16le launch_position;
			uint8_t launch_kind;
			uint8_t rides_platform;
		} catapult;
		struct
		{
			uint8_t pad_10[0x71];
			int8_t path_write_index;
			u16le wobble_angle;
			uint8_t pad_84[0x2];
			u16le hop_timer;
		} centipede;
		struct
		{
			uint8_t pad_10[0x72];
			s16le path_index;
		} centipede_follow_path;
		struct
		{
			uint8_t pad_10[0x72];
			s16le path_index;
			uint8_t pad_84[0x2];
			u16le hop_timer;
		} centipede_segment;
		struct
		{
			uint8_t pad_10[0x72];
			s16le path_index;
			uint8_t pad_84[0x2];
			u16le hop_timer;
			uint8_t pad_88[0xA];
			u32le segment_ahead;
		} centipede_tail;
		struct
		{
			union
			{
				u32le player_block;
				struct
				{
					uint8_t pad_10[0x2];
					uint8_t name_changed;
					int8_t turn_direction;
				};
			};
			uint8_t pad_14[0x6C];
			uint8_t idle_step;
			uint8_t character;
			s16le step_timer;
			u16le turn_timer;
			uint8_t pad_86[0xC];
			union
			{
				u16le right_count;
				struct
				{
					uint8_t pad_92[0x1];
					uint8_t right_turns;
				};
			};
			union
			{
				u16le left_count;
				struct
				{
					uint8_t pad_94[0x1];
					uint8_t left_turns;
				};
			};
		} character_chooser;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t shown_seconds;
		} character_select_countdown;
		struct
		{
			uint8_t pad_10[0x70];
			u16le end_position;
		} chaser_back_zone;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
		} chaser_back_zone_check_parent;
		struct
		{
			uint8_t pad_10[0x70];
			u32le palette_list;
		} check_player;
		struct
		{
			uint8_t pad_10[0x70];
			union
			{
				u16le frame_index_word;
				int8_t frame_index;
			};
			u16le frame_timer;
		} checker_pad;
		struct
		{
			uint8_t pad_10[0x70];
			u16le copy_object;
			uint8_t pad_82[0x6];
			u16le draw_depth;
		} clipped_copy_sprite;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t plank_index;
			uint8_t pad_70[0x10];
			union
			{
				u32le angle;
				struct
				{
					uint8_t pad_80[0x2];
					s16le angle_whole;
				};
			};
			s32le angle_speed;
			u16le draw_depth;
			uint8_t swing_count;
			uint8_t pad_8B[0x1];
			u16le roll_frames;
			u16le roll_timer;
			uint8_t pad_90[0x5];
			uint8_t bridge;
			s16le depth_offset;
			uint8_t pad_98[0x2];
			u16le previous_plank;
		} collapsing_bridge_plank;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x58];
			int8_t walk_step;
			uint8_t moving;
			s16le frame_timer;
			uint8_t pad_84[0x2];
			u16le step_timer;
			uint8_t pad_88[0xA];
			uint8_t variant;
			uint8_t on_platform;
		} crawler;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t over_pit;
			uint8_t pad_81[0xB];
			u16le triggered;
			uint8_t pad_8E[0x4];
			uint8_t variant;
			uint8_t on_platform;
		} crawler_head;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t pad_6F[0x19];
			u16le draw_depth;
			uint8_t pad_8A[0x7];
			uint8_t silent_row;
			uint8_t pad_92[0x4];
			s16le depth_offset;
			u16le normal_palette;
		} crumbling_floor;
		struct
		{
			uint8_t pad_10[0x70];
			u32le palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
		} cycle_part_palettes;
		struct
		{
			uint8_t pad_10[0x50];
			int8_t palette_index;
			uint8_t pad_61[0x1];
			u16le palette_delay;
		} cycle_ring_tally_backdrop_palette;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			int8_t last_frame;
			u16le frame_timer;
			u16le lifetime;
		} debris;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t state;
			uint8_t pad_81[0x1];
			union
			{
				s16le roll_out_timer;
				struct
				{
					uint8_t pad_82[0x1];
					uint8_t off_screen;
				};
			};
		} door_roller;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t state;
			uint8_t pad_81[0x1];
			s16le roll_out_timer;
		} door_roller_roll_out;
		struct
		{
			uint8_t pad_10[0x70];
			u32le fragment;
			int8_t pieces_left;
		} door_wall;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
		} draw_breakable_panel;
		struct
		{
			uint8_t pad_10[0x2];
			uint8_t name_changed;
			uint8_t pad_13[0x6E];
			uint8_t character;
		} draw_character_chooser_labels;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t step;
			uint8_t pad_81[0x3];
			s16le slide_y;
		} draw_eggman_booth;
		struct
		{
			uint8_t pad_10[0x22];
			s16le timer;
			uint8_t pad_34[0x2C];
			uint8_t frame_index;
		} draw_ending_blast_frame;
		struct
		{
			uint8_t pad_10[0x3A];
			int8_t trail_done;
			uint8_t pad_4B[0xC];
			u16le marker_blink_count;
		} draw_map_stage_markers;
		struct
		{
			uint8_t pad_10[0x22];
			s16le base_x;
			s16le base_y;
			s32le step_x;
			s32le step_y;
			s32le offset_x;
			s32le offset_y;
			uint8_t pad_46[0x4];
			int8_t trail_done;
			u16le segment_frames;
			uint8_t pad_4D[0x4];
			u32le next_trail_point;
			u16le segment_timer;
		} draw_map_trail_dot;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t pad_6F[0x1B];
			u16le group_slot;
			uint8_t pad_8C[0x6];
			int8_t takes_slot;
		} draw_rope_bridge_ropes;
		struct
		{
			uint8_t pad_10[0x70];
			u32le path;
			uint8_t pad_84[0x12];
			union
			{
				u16le dropper_flags;
				uint8_t rides_platform;
			};
		} drop_icicle_row;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t pausing;
			int8_t stretch_step;
			u16le pause_timer;
			uint8_t pad_84[0xE];
			uint8_t facing;
			uint8_t den_number;
			int8_t piece_count;
		} eel_anchor;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			u16le frame_timer;
		} eel_den;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			int8_t stretch_step;
			u16le explode_delay;
			u16le frame_timer;
			uint8_t pad_86[0xE];
			uint8_t facing;
			uint8_t den_number;
		} eel_head;
		struct
		{
			uint8_t pad_10[0x71];
			int8_t stretch_step;
			uint8_t pad_82[0x10];
			uint8_t facing;
			uint8_t pad_93[0x1];
			uint8_t piece_count;
			uint8_t wave_step;
		} eel_init;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			int8_t stretch_step;
			u16le frame_timer;
		} eel_piece;
		struct
		{
			uint8_t pad_10[0x71];
			int8_t stretch_step;
			u16le explode_delay;
			uint8_t pad_84[0x8];
			u32le height_offset;
			uint8_t pad_90[0x5];
			uint8_t den_number;
		} eel_segment;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t step;
			uint8_t pad_81[0x1];
			s16le step_timer;
			s16le slide_y;
		} eggman_booth;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t step;
			uint8_t phase;
			u16le step_timer;
			u16le talk_timer;
		} eggman_scene;
		struct
		{
			uint8_t pad_10[0x70];
			s16le frame_count;
			u32le script;
		} eggman_speech;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t step;
			uint8_t frame_index;
			u16le step_timer;
			u16le flicker_phase;
			u16le beam_phase;
		} eggman_teleport;
		struct
		{
			uint8_t pad_10[0x70];
			union
			{
				s16le frame_index_word;
				int8_t frame_index;
				struct
				{
					uint8_t pad_80[0x1];
					int8_t last_frame;
				};
			};
			u16le frame_toggle;
			u16le draw_offset_y;
		} electric_pole;
		struct
		{
			uint8_t pad_10[0x71];
			uint8_t travel_direction;
			s16le spawn_timer;
			u16le end_position;
		} ember_emitter;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t step;
			s16le timer;
			uint8_t pad_34[0x10];
			u32le part_3;
			uint8_t pad_48[0x18];
			uint8_t frame_index;
			uint8_t list_index;
			s16le cycle_count;
		} ending;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t step;
			s16le timer;
			u32le exhaust_flame;
			u32le path;
			uint8_t pad_3C[0x4];
			u32le puff_1;
			u32le puff_2;
			u32le puff_3;
			u32le puff_4;
			u32le puff_5;
			u32le puff_6;
			u32le puff_7;
			u32le puff_8;
		} ending_eggman_fly_in;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			s16le step_timer;
			uint8_t pad_34[0x2D];
			uint8_t counting_up;
		} escape_alarm_flash;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			int8_t last_frame;
			u16le frame_toggle;
		} explode_object;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			int8_t last_frame;
			u16le frame_toggle;
		} explosion;
		struct
		{
			uint8_t pad_10[0x4E];
			s16le floor_block_high;
			uint8_t pad_60[0x20];
			uint8_t state;
			uint8_t travel_direction;
		} falling_ember;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t pad_6F[0x11];
			s16le rattle_step;
			uint8_t pad_82[0x6];
			u16le draw_depth;
			uint8_t pad_8A[0xC];
			s16le depth_offset;
		} falling_grate;
		struct
		{
			uint8_t pad_10[0x82];
			uint8_t extra_posts;
			uint8_t pad_93[0x1];
			uint8_t row_direction;
			uint8_t arc_phase;
		} fence_post;
		struct
		{
			uint8_t pad_10[0x70];
			u32le path;
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
		} fire_front;
		struct
		{
			uint8_t pad_10[0x70];
			s16le flame_timer;
		} fire_trench_start;
		struct
		{
			uint8_t pad_10[0x70];
			s16le flame_timer;
		} fire_trench_update;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x58];
			u32le palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
			uint8_t pad_87[0x1];
			uint8_t burst_state;
			uint8_t pad_89[0x1];
			s16le blast_delay;
		} fire_vent;
		struct
		{
			uint8_t pad_10[0x38];
			u32le shot;
		} fireball_emitter;
		struct
		{
			uint8_t pad_10[0x14];
			u32le arc_angle;
			uint8_t pad_28[0x57];
			uint8_t state;
			uint8_t pad_80[0x2];
			s16le flight_timer;
		} fireball_fly;
		struct
		{
			uint8_t pad_10[0x6F];
			uint8_t state;
			uint8_t pad_80[0x16];
			s16le target_x;
			uint8_t pad_98[0x2];
			s16le target_y;
		} fireball_start;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			u16le frame_phase;
			u16le angle;
			s16le growth_rate;
			u16le growth_rate_high;
		} flame_jet;
		struct
		{
			uint8_t pad_10[0x14];
			int8_t side;
			uint8_t arm_index;
			uint8_t pad_26[0x5A];
			uint8_t frame_index;
			uint8_t sway_step;
			u16le frame_toggle;
			union
			{
				s16le rest_timer;
				uint8_t sway_toggle;
				struct
				{
					uint8_t pad_84[0x1];
					int8_t sway_count;
				};
			};
		} flame_machine_arm;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t frame;
			int8_t frame_index;
			u16le frame_phase;
			s16le pause_timer;
		} flame_machine_back_wall;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t frame_index;
			uint8_t pad_81[0x1];
			u16le frame_toggle;
		} flame_machine_flame;
		struct
		{
			uint8_t pad_10[0x76];
			u16le time_left;
		} flame_machine_init;
		struct
		{
			uint8_t pad_10[0x14];
			int8_t previous_health;
			uint8_t pad_25[0x5D];
			u16le flash_frame_count;
			uint8_t pad_84[0x2];
			u16le time_left;
			uint8_t pad_88[0x4];
			u16le destroyed_frames;
		} flame_machine_update;
		struct
		{
			uint8_t pad_10[0x70];
			u32le palette_list;
			uint8_t flash_on;
			uint8_t flash_period;
			uint8_t flash_timer;
		} flash_hurt_palette;
		struct
		{
			uint8_t pad_10[0x71];
			uint8_t flash_step;
			uint8_t pad_82[0x2];
			u16le flash_timer;
		} flash_mine_palette;
		struct
		{
			uint8_t pad_10[0x70];
			u32le palette_list;
		} follow_player_path;
		struct
		{
			uint8_t pad_10[0x2C];
			u16le turn_speed;
			u16le base_y;
			uint8_t pad_40[0x14];
			int8_t hop_timer;
			uint8_t step;
			uint8_t pad_56[0x2];
			s32le drop_height;
		} gauge_ring;
		struct
		{
			uint8_t pad_10[0x72];
			u16le draw_depth;
		} geyser_erupt;
		struct
		{
			uint8_t pad_10[0x58];
			u32le next_listed_geyser;
			uint8_t pad_6C[0x12];
			s16le sound_timer;
			u32le path;
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
			u32le row_pattern;
			union
			{
				s32le fixed_projected_x;
				u16le projected_x_fraction;
				struct
				{
					uint8_t pad_98[0x2];
					s16le projected_x_whole;
				};
			};
			s16le top_height;
		} geyser_front;
		struct
		{
			uint8_t pad_10[0x70];
			u32le path;
			uint8_t pad_84[0x4];
			s16le speed;
			uint8_t pad_8A[0x4];
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
			s16le travel;
		} geyser_line;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x58];
			u16le erupt_delay;
			u16le draw_depth;
		} geyser_wait;
		struct
		{
			uint8_t pad_10[0x84];
			union
			{
				s32le fixed_projected_x;
				u16le projected_x_fraction;
				struct
				{
					uint8_t pad_94[0x2];
					s16le projected_x_whole;
				};
			};
		} grate_step_debris_view;
		struct
		{
			uint8_t pad_10[0x74];
			s16le cut_z;
			uint8_t copied_animation_speed;
			int8_t copied_animation_timer;
		} grate_step_update;
		struct
		{
			uint8_t pad_10[0x70];
			s16le rows_left;
			s32le row_projected_y;
			uint8_t pad_86[0x10];
			s16le row_projected_x;
		} grate_steps;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t leader;
			uint8_t pad_81[0x1];
			s16le coordinate;
			u16le end_position;
			u16le which_flag;
		} group_leader_hold;
		struct
		{
			uint8_t pad_10[0x24];
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t pad_3F[0x9];
			u32le path;
			uint8_t pad_4C[0x34];
			s16le wait_timer;
			u16le hold_start_position;
			uint8_t hold_timer;
		} group_leader_move;
		struct
		{
			uint8_t pad_10[0x7A];
			u16le group_slot;
			uint8_t pad_8C[0x5];
			uint8_t silent_row;
			uint8_t pad_92[0x4];
			s16le depth_offset;
			u16le normal_palette;
			u16le previous_member;
		} group_member;
		struct
		{
			uint8_t pad_10[0x70];
			union
			{
				u32le next_trigger;
				u16le next_trigger_low;
			};
		} group_slot_trigger;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x59];
			uint8_t swing_side;
			u16le angle;
			union
			{
				s16le angle_speed;
				struct
				{
					uint8_t pad_84[0x1];
					int8_t angle_speed_int;
				};
			};
			s16le swing_accel;
			uint8_t pad_88[0xA];
			uint8_t handle_count;
			uint8_t drops_players;
			u16le end_position;
		} handle_rod;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x58];
			union
			{
				u16le index_word;
				uint8_t index;
				struct
				{
					uint8_t pad_80[0x1];
					uint8_t grip;
				};
			};
			u16le start_angle;
			s16le rod_angle_speed;
			u16le rod;
		} handle_rod_handle;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t handle_index;
			uint8_t fallen;
		} handle_rod_post;
		struct
		{
			uint8_t pad_10[0x70];
			u32le next_press;
		} how_to_play_button_hand;
		struct
		{
			uint8_t pad_10[0x71];
			uint8_t step;
			int8_t pause_timer;
		} how_to_play_trackball_hand;
		struct
		{
			uint8_t pad_10[0x72];
			uint8_t state;
		} ice_block;
		struct
		{
			uint8_t pad_10[0x70];
			s16le blocks_left;
		} ice_block_row;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t state;
			uint8_t shake_timer;
			s16le shake_duration;
			s16le shake_offset;
			uint8_t pad_86[0x2];
			u16le draw_depth;
		} ice_floor_block;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t step;
			int8_t last_step;
			u16le step_timer;
			uint8_t pad_84[0xE];
			uint8_t cube_speed_index;
			uint8_t step_duration_index;
		} ice_launcher;
		struct
		{
			uint8_t pad_10[0x7C];
			s16le travel;
			u16le end_position;
		} ice_platform_leader;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t member;
			uint8_t pad_70[0x18];
			u16le draw_depth;
			uint8_t pad_8A[0x8];
			uint8_t icicle_landed;
			uint8_t pad_93[0x3];
			s16le depth_offset;
		} ice_platform_piece;
		struct
		{
			uint8_t pad_10[0x70];
			s16le next_depth;
		} icicle_cracks;
		struct
		{
			uint8_t pad_10[0x70];
			u32le path;
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
			s16le travel;
			union
			{
				u16le record_flags;
				uint8_t rides_platform;
				struct
				{
					uint8_t pad_96[0x1];
					uint8_t last_dropper;
				};
			};
			union
			{
				s32le platform_offset;
				struct
				{
					uint8_t pad_98[0x2];
					s16le platform_offset_int;
				};
			};
			u16le finish_timer;
		} icicle_dropper;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x5E];
			union
			{
				u16le blink_timer_word;
				uint8_t blink_timer;
			};
		} icicle_shadow;
		struct
		{
			uint8_t pad_10[0x70];
			s16le timer;
			uint8_t state;
			uint8_t pad_83[0x1];
			u16le line_coordinate;
			uint8_t pad_86[0x2];
			u16le draw_depth;
			uint8_t pad_8A[0xC];
			union
			{
				u16le dropper_flags;
				uint8_t rides_platform;
				struct
				{
					uint8_t pad_96[0x1];
					uint8_t counts_goal;
				};
			};
		} icicle_update;
		struct
		{
			uint8_t pad_10[0x6F];
			uint8_t state;
			uint8_t pad_80[0x2];
			s16le flight_timer;
			uint8_t pad_84[0x12];
			s16le target_x;
			uint8_t pad_98[0x2];
			s16le target_y;
		} init_fireball_flight;
		struct
		{
			union
			{
				u32le player_block;
				struct
				{
					uint8_t pad_10[0x3];
					int8_t turn_direction;
				};
			};
			uint8_t pad_14[0x6C];
			uint8_t portrait_changed;
			uint8_t character;
			u16le countdown;
		} join_character_chooser;
		struct
		{
			uint8_t pad_10[0x70];
			s16le base_x;
			s16le base_y;
			uint8_t pad_84[0x8];
			u16le side;
			uint8_t pad_8E[0x2];
			int8_t standing;
			uint8_t pad_91[0x5];
			s16le depth_offset;
		} lava_column;
		struct
		{
			uint8_t pad_10[0x70];
			u32le path;
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
			uint8_t pad_94[0x2];
			u16le unused_word;
			uint8_t sound_timer;
		} lava_flow;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x46];
			uint8_t state;
			uint8_t member;
			s16le erupt_delay;
			uint8_t pad_72[0xE];
			u32le palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
			uint8_t pad_87[0x1];
			u16le draw_depth;
			u16le group_slot;
			uint8_t pad_8C[0x2];
			u16le rise_limit;
			uint8_t pad_90[0x2];
			uint8_t takes_slot;
			uint8_t pad_93[0x3];
			s16le depth_offset;
		} lava_rock;
		struct
		{
			uint8_t pad_10[0x71];
			uint8_t sprung;
		} lid_trap;
		struct
		{
			uint8_t pad_10[0x38];
			s16le move_frames;
			uint8_t pad_4A[0x28];
			int8_t sound_timer;
			uint8_t off_screen;
			uint8_t pad_74[0xB];
			uint8_t state;
			u32le path;
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			union
			{
				s32le fixed_projected_x;
				u16le projected_x_fraction;
				struct
				{
					uint8_t pad_92[0x2];
					s16le projected_x_whole;
				};
			};
			uint8_t pad_96[0x2];
			u16le hold_start_position;
		} machine_fire;
		struct
		{
			uint8_t pad_10[0x20];
			u16le timer;
			uint8_t pad_32[0x16];
			u16le hold_frames;
			uint8_t pad_4A[0x7];
			u32le gesture_list;
			uint8_t pad_55[0x4];
			uint8_t unused_step;
			uint8_t pad_5A[0x3];
			uint8_t sound_step;
		} map_eggman;
		struct
		{
			uint8_t pad_10[0x20];
			u16le timer;
			uint8_t pad_32[0x27];
			uint8_t frame_step;
			uint8_t frame_step_pad;
		} map_eggman_hands;
		struct
		{
			uint8_t pad_10[0x20];
			s16le timer;
			s16le base_x;
			s16le base_y;
			s32le step_x;
			s32le step_y;
			s32le offset_x;
			s32le offset_y;
		} map_intro;
		struct
		{
			uint8_t pad_10[0x20];
			s16le timer;
			s16le base_x;
			s16le base_y;
			s32le step_x;
			s32le step_y;
			uint8_t pad_3E[0xA];
			s16le blink_frames;
			int8_t trail_done;
			uint8_t pad_4B[0x2];
			s16le target_x;
			s16le target_y;
			uint8_t pad_51[0x6];
			u16le marker_blink_count;
			uint8_t pad_59[0x2];
			int8_t blink_phase;
		} map_screen;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x58];
			uint8_t state;
			uint8_t pad_81[0x1];
			s16le timer;
			u16le frame;
		} metal_platform;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			int8_t rise_limit;
			s16le frame_count;
			u16le dust_timer;
			uint8_t pad_86[0xC];
			uint8_t last_health;
			uint8_t pad_93[0x1];
			uint8_t flipped;
			uint8_t ring_count;
		} metal_wall;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			u16le timer;
		} mine;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			u16le frame_timer;
		} mine_splash;
		struct
		{
			uint8_t pad_10[0x20];
			s16le timer;
			s16le base_x;
			s16le base_y;
			s32le step_x;
			s32le step_y;
			s32le offset_x;
			s32le offset_y;
			uint8_t pad_46[0x15];
			uint8_t blink_phase;
		} move_map_stage_icon;
		struct
		{
			uint8_t pad_10[0x78];
			union
			{
				s32le projected_x_carry;
				struct
				{
					uint8_t pad_88[0x2];
					s16le projected_x_carry_int;
				};
			};
		} move_object_projected;
		struct
		{
			uint8_t pad_10[0x22];
			s16le base_x;
			s16le base_y;
			s32le step_x;
			s32le step_y;
			s32le offset_x;
			uint8_t pad_42[0x8];
			int8_t trail_done;
			u16le segment_frames;
			s16le target_x;
			s16le target_y;
			u32le next_trail_point;
		} next_map_trail_segment;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t scene_step_seen;
			uint8_t pad_81[0x1];
			union
			{
				s32le zoom;
				struct
				{
					uint8_t pad_82[0x2];
					s16le zoom_int;
				};
			};
			s32le zoom_speed;
			int8_t phase;
			uint8_t pad_8B[0x1];
			u16le draw_depth;
		} opening_machine;
		struct
		{
			uint8_t pad_10[0x72];
			u16le wave_angle;
			uint8_t pad_84[0x8];
			u32le height_offset;
			uint8_t pad_90[0x2];
			u16le wave_amplitude;
		} place_eel_piece;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
			uint8_t pad_4C[0x10];
			s16le floor_block_low;
			s16le floor_block_high;
			uint8_t pad_60[0x1F];
			uint8_t health_pad;
			u32le palette_list;
			uint8_t hurt_flash_on;
			uint8_t hurt_flash_period;
			uint8_t hurt_flash_timer;
			uint8_t pad_87[0x15];
			u32le block;
		} player_view;
		struct
		{
			uint8_t pad_10[0x86];
			s16le depth_offset;
		} player_effect;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
			uint8_t pad_4C[0x34];
			u32le palette_list;
		} player_object_climb;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
		} player_state_bouncing;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
		} player_state_dropping;
		struct
		{
			uint8_t pad_10[0x5A];
			u16le touched_by;
		} player_state_stuck;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
		} player_stuck_jump_out;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
		} player_stuck_on_object_jump_out;
		struct
		{
			uint8_t pad_10[0x5A];
			u16le touched_by;
		} player_stuck_wait_release;
		struct
		{
			uint8_t pad_10[0x70];
			u32le path;
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
			u16le sound_timer;
		} propeller_machine;
		struct
		{
			uint8_t pad_10[0x24];
			union
			{
				s16le shake_strength;
				uint8_t shake_strength_low;
			};
			uint8_t shake_step;
			uint8_t pad_37[0x49];
			s16le shake_dx;
			u16le draw_depth;
		} propped_board;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x58];
			uint8_t break_frame;
			uint8_t stopped;
			u16le frame_count;
			s16le ring_timer;
			uint8_t pad_86[0xC];
			uint8_t push_quadrant;
			uint8_t post_distance;
			s16le ring_count;
		} push_crate;
		struct
		{
			uint8_t pad_10[0x70];
			u32le palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
		} quicksand;
		struct
		{
			uint8_t pad_10[0x70];
			u16le last_spawn_position;
		} railing_spawner;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t appear_state;
			uint8_t pad_81[0x1];
			u16le variant;
			int8_t hit_count;
			uint8_t pad_85[0x1];
			u32le damage_script;
		} ram_target;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t rows_animate;
			uint8_t rows_remove;
			uint8_t rows_remove_pad;
			uint8_t pad_83[0x1];
			s16le hold_timer;
		} ranking_display;
		struct
		{
			u32le player_block;
			uint8_t pad_14[0x10];
			u16le rank;
			uint8_t pad_26[0xE];
			s16le rings;
			uint8_t character;
			uint8_t stages_reached;
			union
			{
				u32le initials;
				uint8_t first_initial;
				struct
				{
					uint8_t pad_38[0x1];
					uint8_t second_initial;
					uint8_t third_initial;
					uint8_t initials_pad;
				};
			};
			u32le trackball;
			uint8_t pad_40[0x40];
			uint8_t button_bit;
			uint8_t pad_81[0x1];
			u16le out_of_rank_timer;
			u16le time_left;
		} ranking_entry;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x58];
			uint8_t animate;
			uint8_t remove;
			uint8_t pad_82[0x10];
			u16le row;
		} ranking_row;
		struct
		{
			uint8_t pad_10[0x72];
			s16le pause_timer;
		} ranking_title;
		struct
		{
			uint8_t pad_10[0x6E];
			s16le pickup_delay;
			s16le lifetime;
			uint8_t pad_82[0x2];
			u16le release_delay;
			uint8_t pad_86[0x4];
			s16le projected_x_carry_int;
			uint8_t pad_8C[0x6];
			s32le bounce_speed;
		} released_ring;
		struct
		{
			uint8_t pad_10[0x70];
			u16le zoom_step;
			uint8_t pad_82[0x2];
			u16le open_position;
			u16le edge_zone;
			u16le draw_depth;
			uint8_t pad_8A[0x2];
			u16le unscaled_hitbox_size_x;
		} rimmed_sinkhole;
		struct
		{
			uint8_t pad_10[0x6E];
			u16le spawn_scroll_position;
			u16le unused_glint_timer;
		} ring_spin;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			u16le roll_delay;
			uint8_t pad_34[0x10];
			u32le tens_digit;
			uint8_t pad_48[0x14];
			u16le results_timer;
			uint8_t pad_5E[0x2];
			uint8_t blink_index;
			uint8_t pad_61[0x1];
			u16le blink_delay;
		} ring_tally_percent_view;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			u16le step_delay;
			uint8_t pad_34[0x4];
			u32le bonus_label;
			uint8_t pad_3C[0x4];
			u32le backdrop;
			u32le part_3;
			u32le units_digit;
			u32le tens_digit;
			u32le hundreds_digit;
			uint8_t pad_54[0xC];
			int8_t rings_counted;
			uint8_t step;
			u16le palette_delay;
			uint8_t pad_64[0x6];
			uint8_t character;
		} ring_tally_player;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			s16le timer;
		} ring_tally_ticker;
		struct
		{
			uint8_t pad_10[0x6F];
			uint8_t state;
			uint8_t pad_80[0x1];
			uint8_t off_screen;
		} rising_flame;
		struct
		{
			uint8_t pad_10[0x70];
			u32le path;
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
			union
			{
				s32le fixed_projected_x;
				u16le projected_x_fraction;
				struct
				{
					uint8_t pad_94[0x2];
					s16le projected_x_whole;
				};
			};
		} rising_saw;
		struct
		{
			uint8_t pad_10[0x74];
			uint8_t unused_state;
		} river_raft_foam;
		struct
		{
			uint8_t pad_10[0x70];
			u32le entry;
			u16le end_position;
			u32le list_start;
			union
			{
				s32le last_raft_y;
				struct
				{
					uint8_t pad_8A[0x2];
					s16le last_raft_y_int;
				};
			};
			u32le last_raft_speed;
		} river_raft_spawner;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
			uint8_t pad_4C[0x38];
			uint8_t state;
			uint8_t pad_85[0x3];
			u16le draw_depth;
		} river_raft_update;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
			uint8_t pad_4C[0x22];
			uint8_t state;
			uint8_t pad_6F[0x19];
			u16le draw_depth;
			uint8_t pad_8A[0xC];
			s16le depth_offset;
		} river_water;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t break_frame;
			uint8_t breaking;
			s16le frame_count;
			u16le twinkle_delay;
		} rock_wall;
		struct
		{
			uint8_t pad_10[0x70];
			s16le limit;
		} roller_back_zone;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t plank_index;
			uint8_t pad_70[0x18];
			u16le draw_depth;
			u16le group_slot;
			uint8_t pad_8C[0x6];
			int8_t takes_slot;
			uint8_t pad_93[0x2];
			uint8_t bridge;
			s16le depth_offset;
		} rope_bridge_plank;
		struct
		{
			uint8_t pad_10[0x6E];
			u16le spawn_scroll_position;
			u16le glint_timer;
			u16le hover_height;
		} row_ring;
		struct
		{
			uint8_t pad_10[0x22];
			s16le timer;
			uint8_t pad_34[0x2D];
			uint8_t list_index;
		} run_timed_spawns;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x58];
			int8_t balls_gone;
			uint8_t row_position;
			s16le bob_phase;
			uint8_t pad_84[0xE];
			uint8_t row_direction;
			int8_t ball_count;
		} sand_arch;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t pad_6F[0x19];
			u16le draw_depth;
			u16le face_object;
			uint8_t pad_8C[0xA];
			s16le depth_offset;
		} sand_block;
		struct
		{
			uint8_t pad_10[0x70];
			u32le path;
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
		} sand_block_leader;
		struct
		{
			uint8_t pad_10[0x86];
			s16le depth_offset;
		} sand_face;
		struct
		{
			uint8_t pad_10[0x72];
			u16le lifetime;
			s16le frame_index;
		} sand_puff;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t crumble_frame;
			uint8_t crumbling;
			s16le frame_count;
			uint8_t pad_84[0xE];
			uint8_t ring_count;
		} sand_rock;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
		} sand_streams;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x58];
			s16le next_shaft_z;
			uint8_t pad_82[0x1];
			uint8_t state;
			s16le sound_timer;
			uint8_t pad_86[0x2];
			u16le draw_depth;
		} saw_blade;
		struct
		{
			uint8_t pad_10[0x72];
			uint8_t state;
		} saw_shaft_base_draw;
		struct
		{
			uint8_t pad_10[0x70];
			s16le next_step_z;
			uint8_t state;
		} saw_shaft_update;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
		} saw_sparks;
		struct
		{
			uint8_t pad_10[0x6E];
			s16le pickup_delay;
			s16le lifetime;
		} scattered_ring;
		struct
		{
			uint8_t pad_10[0x70];
			u16le end_position;
		} scene_anchor;
		struct
		{
			uint8_t pad_10[0x70];
			u16le end_position;
		} scene_carrier;
		struct
		{
			uint8_t pad_10[0x70];
			u16le end_position;
			u16le radius_x4;
		} scene_object_view;
		struct
		{
			uint8_t pad_10[0x70];
			u32le palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
			uint8_t pad_87[0x1];
			u16le unused_stage;
			s16le depth_offset;
		} scenery_sprite;
		struct
		{
			uint8_t pad_10[0x70];
			u32le palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
		} screen_sign;
		struct
		{
			uint8_t pad_10[0x21];
			uint8_t scrolled_out;
			s16le timer;
		} scroll_credits;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
		} seesaw;
		struct
		{
			uint8_t pad_10[0x4E];
			u16le floor_block_high;
		} set_player_entry_by_scene;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t flicker_timer;
		} shadow;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			u16le frame_timer;
		} shaking_block;
		struct
		{
			uint8_t pad_10[0x86];
			s16le depth_offset;
		} sink_swirl;
		struct
		{
			uint8_t pad_10[0x70];
			u16le zoom_step;
			uint8_t pad_82[0x2];
			u16le open_position;
			uint8_t pad_86[0x2];
			u16le draw_depth;
			int8_t unscaled_offset_x;
			int8_t unscaled_offset_y;
			u16le unscaled_hitbox_size_x;
		} sinkhole;
		struct
		{
			uint8_t pad_10[0x86];
			s16le depth_offset;
		} sinking_effect;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
		} skid_dust;
		struct
		{
			uint8_t pad_10[0x72];
			u16le open_delay;
		} sliding_door;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t burst_frame;
			uint8_t bursting;
			s16le frame_count;
			s16le part_3_count;
			u16le part_3_frame;
			uint8_t pad_88[0xA];
			uint8_t ring_count;
			uint8_t random_scatter;
		} snow_mound;
		struct
		{
			uint8_t pad_10[0x74];
			s16le cut_z;
		} spawn_grate_step_debris;
		struct
		{
			uint8_t pad_10[0x70];
			s16le wait_timer;
		} spawn_group_leader;
		struct
		{
			uint8_t pad_10[0x82];
			uint8_t takes_slot;
			uint8_t pad_93[0x3];
			s16le depth_offset;
		} spawn_lava_column;
		struct
		{
			uint8_t pad_10[0x58];
			u32le next_listed_geyser;
		} spawn_listed_geyser;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
		} spawn_slip_piece;
		struct
		{
			uint8_t pad_10[0x72];
			u16le phase_timer;
			s32le spear_z;
		} spear_trap;
		struct
		{
			uint8_t pad_10[0x71];
			int8_t bounce_count;
			u16le pause_timer;
		} spike_gate_beam;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x58];
			int8_t frame_index;
			int8_t step;
			s16le step_timer;
			uint8_t pad_84[0x2];
			u16le trigger_delay;
			uint8_t pad_88[0xB];
			uint8_t start_step;
		} spike_panel;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
			uint8_t pad_28[0x58];
			uint8_t spin_frame;
			uint8_t arm_frame;
			u16le spin_toggle;
		} spiked_disc;
		struct
		{
			uint8_t pad_10[0x70];
			s16le sound_timer;
			s16le frame_count;
			s16le stopped_frames;
			uint8_t pad_86[0x8];
			uint8_t holding_back;
			uint8_t hold_timer;
		} spiked_press;
		struct
		{
			uint8_t pad_10[0x62];
			union
			{
				u32le event_offset_long;
				u16le event_offset;
				struct
				{
					uint8_t pad_72[0x2];
					u16le roller_kind;
				};
			};
			uint8_t pad_76[0xA];
			union
			{
				u16le state_word;
				uint8_t state;
				struct
				{
					uint8_t pad_80[0x1];
					uint8_t holding_back;
				};
			};
			s16le wait_timer;
			s16le saved_base_speed;
			u16le leader;
			s16le screen_threshold;
			u32le path;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			u16le path_direction;
			uint8_t rumble_timer;
			uint8_t rumble_off_screen;
			uint8_t substate;
			uint8_t pause_timer;
			uint8_t pad_9A[0x2];
			u16le hold_start_position;
			uint8_t hold_timer;
		} spiked_roller;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
		} stage_03_floor_block;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
			uint8_t pad_4C[0x34];
			u16le sparkle_offset;
		} stage_clear_banner;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			s16le timer;
			uint8_t pad_34[0x2C];
			uint8_t frame_index;
		} start_ending_blast;
		struct
		{
			uint8_t pad_10[0x3A];
			int8_t trail_done;
			u16le segment_frames;
			uint8_t pad_4D[0x8];
			u16le segment_timer;
		} start_map_trail;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t frame_index_high;
			u16le frame_timer;
		} static_triangle;
		struct
		{
			uint8_t pad_10[0x86];
			s16le depth_offset;
		} stone_block;
		struct
		{
			uint8_t pad_10[0x70];
			u16le draw_depth;
		} stuck_effect;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			s16le timer;
			uint8_t pad_34[0x2D];
			uint8_t list_index;
		} timed_spawner;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			union
			{
				s16le timer;
				uint8_t timer_low;
			};
			uint8_t pad_34[0x10];
			u32le emblem_bottom_left;
			uint8_t pad_48[0x19];
			uint8_t frame_index;
		} title;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			s16le timer;
			uint8_t pad_34[0x10];
			u32le cloud_4;
		} title_clouds;
		struct
		{
			uint8_t pad_10[0x62];
			uint8_t sound_timer;
			uint8_t off_screen;
			uint8_t pad_74[0xC];
			u32le path;
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
			u16le rotation_angle;
			u16le columns;
		} tornado;
		struct
		{
			uint8_t pad_10[0x70];
			u32le player_block;
		} trap;
		struct
		{
			uint8_t pad_10[0x7C];
			uint8_t sound_c_timer;
			uint8_t sound_1e_timer;
			u32le reached_top;
		} treadmill_gate_update;
		struct
		{
			uint8_t pad_10[0x16];
			u16le parent;
		} treadmill_roller;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t belt_phase;
		} treadmill_update;
		struct
		{
			uint8_t pad_10[0x38];
			u32le animation;
		} tumble_effect;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t stroke_step;
			uint8_t pad_81[0x1];
			u16le stroke_timer;
		} turtle;
		struct
		{
			uint8_t pad_10[0x22];
			u16le step_delay;
			uint8_t pad_34[0x4];
			u32le bonus_label;
			uint8_t pad_3C[0x4];
			u32le backdrop;
			u32le part_3;
			u32le units_digit;
			u32le tens_digit;
			u32le hundreds_digit;
			uint8_t pad_54[0x8];
			u32le result_frames;
			int8_t rings_counted;
			uint8_t step;
			uint8_t pad_62[0x4];
			int8_t ring_total;
			uint8_t gets_bonus;
			uint8_t pad_68[0x2];
			uint8_t character;
		} update_ring_tally_panel;
		struct
		{
			uint8_t pad_10[0x4C];
			u16le results_timer;
			uint8_t pad_5E[0x2];
			uint8_t blink_index;
			uint8_t pad_61[0x1];
			u16le blink_delay;
		} update_ring_tally_percent;
		struct
		{
			uint8_t pad_10[0x14];
			u16le vine;
			uint8_t pad_26[0x5A];
			uint8_t holding;
			uint8_t pad_81[0x1];
			s16le anchor_z;
		} vine_bar;
		struct
		{
			uint8_t pad_10[0x4];
			s32le base_x;
			uint8_t pad_18[0x6A];
			s16le depth_offset;
			uint8_t pad_84[0xF];
			uint8_t segment_count;
			uint8_t phase_step;
		} vine_init;
		struct
		{
			uint8_t pad_10[0x4];
			union
			{
				s32le base_x;
				struct
				{
					uint8_t pad_14[0x2];
					s16le base_x_int;
				};
			};
			uint8_t pad_18[0x30];
			union
			{
				u32le segment_angle;
				struct
				{
					uint8_t pad_48[0x2];
					s16le segment_angle_int;
				};
			};
			uint8_t pad_4C[0x34];
			uint8_t holding;
			uint8_t pad_81[0x1];
			s16le depth_offset;
			uint8_t pad_84[0x11];
			uint8_t curl_scale;
		} vine_swing;
		struct
		{
			uint8_t pad_10[0x27];
			uint8_t depth_from_next;
		} wall_editor;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t frame_step;
			uint8_t pad_81[0x1];
			u16le frame_timer;
		} wall_pad;
		struct
		{
			uint8_t pad_10[0x27];
			uint8_t depth_from_next;
			uint8_t edge_flags;
			uint8_t pad_39[0x47];
			uint8_t invisible;
			uint8_t no_second_sprite;
			u16le end_position;
		} wall_update;
		struct
		{
			uint8_t pad_10[0x70];
			u32le path;
			s16le screen_threshold;
			u16le catch_up_factor;
			s16le base_speed;
			s16le saved_threshold;
			s16le saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			s16le wait_timer;
			u16le hold_start_position;
			u16le sound_timer;
		} waterfall;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t self_copied_byte;
			u16le spin_angle;
			s16le timer;
			u16le spin_step;
		} whirlwind;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t frame_index;
			uint8_t pad_81[0x1];
			u16le frame_timer;
		} white_puff;
	};
};

struct player
{
	uint8_t state;
	uint8_t facing;
	uint8_t pad_02[0x1];
	uint8_t substate;
	s16le state_timer;
	uint8_t control_lock;
	int8_t jump_delay;
	uint8_t standing_started;
	uint8_t is_joining;
	s16le trackball_x;
	s16le trackball_y;
	s16le invulnerable_timer;
	uint8_t pad_10[0x2];
	u16le heading;
	u16le object;
	uint8_t pad_16[0x4];
	u16le last_hazard;
	union
	{
		s32le scene_hop_z;
		struct
		{
			uint8_t pad_1C[0x2];
			s16le scene_hop_z_int;
		};
	};
	s16le ledge_pullback;
	s16le ledge_side;
	s32le slip_distance;
	u16le target_heading;
	uint8_t pad_2A[0x2];
	s16le climb_remaining;
	uint8_t climb_from_top;
	uint8_t hit_stop;
	union
	{
		s32le step_accumulator;
		u16le step_accumulator_low;
		struct
		{
			uint8_t pad_30[0x2];
			s16le step_accumulator_int;
		};
	};
	union
	{
		s32le screen_x;
		u16le screen_x_fraction;
		struct
		{
			uint8_t pad_34[0x2];
			s16le screen_x_int;
		};
	};
	int8_t in_game;
	uint8_t unused_hud_byte;
	uint8_t pad_3A[0x2];
	s32le skid_slowdown;
	s32le skid_speed_slowdown;
	uint8_t pad_44[0x2];
	uint8_t free_turn_timer;
	uint8_t pad_47[0x1];
	int8_t skid_dust_timer;
	uint8_t bounce_direction;
	s32le bounce_speed_z;
	s32le bounce_step;
	uint8_t previous_state;
	uint8_t ignore_screen_edges;
	uint8_t drift_turned_back;
	uint8_t drift_done;
	u16le pull_distance_factor;
	u16le unused_hud_word;
	uint8_t pad_5A[0x2];
	u32le path_pointer;
	uint8_t pad_60[0x4];
	union
	{
		s32le ground_speed;
		struct
		{
			uint8_t pad_64[0x2];
			u16le ground_speed_int;
		};
	};
	union
	{
		s16le walk_cycle;
		struct
		{
			uint8_t pad_68[0x1];
			uint8_t walk_cycle_high;
		};
	};
	s32le walk_pending_x;
	s32le walk_pending_y;
	int8_t attack_power;
	uint8_t alternate_run_toggle;
	uint8_t pad_74[0x1];
	uint8_t joined_health_setting;
	s32le previous_x;
	s32le previous_y;
	union
	{
		s32le previous_z;
		uint8_t previous_z_low;
		struct
		{
			uint8_t pad_7E[0x2];
			s16le previous_z_int;
		};
	};
	uint8_t pad_82[0x2];
	u16le screen_edge;
	u16le hud_portrait;
	u16le hud_gauge;
	u16le heading_snapped;
	uint8_t pad_8C[0x8];
	union
	{
		u32le push_xy;
		s16le push_x;
		struct
		{
			uint8_t pad_94[0x2];
			s16le push_y;
		};
	};
	union
	{
		s32le animation_speed;
		struct
		{
			uint8_t pad_98[0x2];
			s16le animation_speed_int;
		};
	};
	u16le holder;
	uint8_t pad_9E[0x1];
	uint8_t grey_screen_request;
	int8_t pushed_out;
	int8_t push_out_delay;
	s32le push_out_x;
	s32le push_out_y;
	u16le fall_draw_depth;
	u16le jump_first_tile;
	uint8_t pad_AE[0x2];
	u16le path_speed;
	uint8_t path;
	uint8_t unused_reset_byte;
	uint8_t mishap_flag;
	uint8_t saved_substate;
	u16le facing_angle;
	uint8_t scene_step_seen;
	uint8_t path_request;
	union
	{
		s32le scene_zoom;
		u16le scene_zoom_fraction;
		struct
		{
			uint8_t pad_BA[0x2];
			u16le scene_zoom_int;
		};
	};
	int8_t hud_blink_timer;
	uint8_t hud_blink_on;
	s16le path_wait;
	uint8_t entry_status;
	int8_t hurt_contact_delay;
	u16le speed_scale;
	u16le last_damaged;
	union
	{
		s32le escape_progress;
		s16le escape_progress_low;
		struct
		{
			uint8_t pad_C8[0x2];
			s16le escape_progress_int;
		};
	};
	u16le draw_depth;
	union
	{
		s32le side_step_accumulator;
		struct
		{
			uint8_t pad_CE[0x2];
			s16le side_step_accumulator_int;
		};
	};
	s32le saved_screen_x;
	s32le saved_screen_y;
	u16le saved_climb_remaining;
	uint8_t goal_step;
	uint8_t effect_spawned;
	u16le own_view_y;
	u16le last_wall;
	int8_t wall_timer;
	uint8_t drift_anim_step;
	union
	{
		u16le continue_countdown;
		int8_t continue_frames;
		struct
		{
			uint8_t pad_E4[0x1];
			int8_t continue_seconds;
		};
	};
	u16le pull_angle;
	u16le pull_start_distance;
	uint8_t sequence_step;
	int8_t ledge_direction;
	u16le struggle_speed;
	s16le sink_depth;
	uint8_t pad_F0[0x4];
	u16le ground_clip_bottom;
	uint8_t pad_F6[0x1E];
	u32le flags;
	u16le swirl_turn_rate;
	u16le unused_reset_word;
	uint8_t unused_jump_byte;
	uint8_t enter_on_respawn;
	u16le object_climb_steps;
	int8_t climb_hand;
	uint8_t pad_121[0x1];
	uint8_t entry_step;
	uint8_t hud_message_shown;
	s16le jump_frames;
	u16le hud_ring_effect;
	uint8_t scene_path;
	uint8_t ending_step;
	u16le edge_object;
	u16le stage_rings_shown;
	uint8_t fast_climb;
	uint8_t sequence_bounced;
	union
	{
		s32le climb_base_z;
		u16le climb_base_z_fraction;
		struct
		{
			uint8_t pad_130[0x2];
			s16le climb_base_z_int;
		};
	};
	uint8_t ending_done;
	uint8_t game_over_done;
	uint8_t unused_start_byte;
	uint8_t stages_reached;
	u16le ridden_object;
	u16le rings;
	u16le stage_rings;
	uint8_t splash_zone;
	uint8_t was_in_splash_zone;
	uint8_t stage_b_path_done;
	int8_t rings_to_health;
	uint8_t pad_142[0x2];
	u16le hud_gauge_flags;
	u16le hud_gauge_tile;
	u16le hud_gauge_palette;
	u16le hud_gauge_address;
	uint8_t pad_14C[0x2];
	u16le hud_gauge_y;
	u16le hud_gauge_x;
	uint8_t pad_152[0x8];
	u16le hud_gauge_height;
	uint8_t pad_15C[0xA];
	uint8_t hud_gauge_health;
	uint8_t hud_gauge_frame;
	uint8_t hud_gauge_anim_delay;
	uint8_t pad_169[0x1];
	u32le hud_gauge_anim;
	uint8_t hud_gauge_anim_repeats;
	uint8_t hud_gauge_reset;
	uint8_t pad_170[0x4];
	u16le hud_portrait_flags;
	u16le hud_portrait_tile;
	u16le hud_portrait_palette;
	uint8_t pad_17A[0x4];
	u16le hud_portrait_y;
	u16le hud_portrait_x;
	uint8_t pad_182[0x8];
	u16le hud_portrait_height;
	uint8_t pad_18C[0xB];
	uint8_t hud_portrait_frame;
	uint8_t hud_portrait_anim_delay;
	uint8_t pad_199[0x1];
	u32le hud_portrait_anim;
	uint8_t hud_portrait_anim_repeats;
	uint8_t pad_19F[0x5];
	u16le hud_ring_effect_flags;
	uint8_t pad_1A6[0x2];
	u16le hud_ring_effect_palette;
	uint8_t pad_1AA[0x4];
	u16le hud_ring_effect_y;
	u16le hud_ring_effect_x;
	uint8_t pad_1B2[0x15];
	uint8_t hud_ring_effect_frame;
	uint8_t hud_ring_effect_anim_delay;
	uint8_t hud_ring_effect_anim_timer;
	u32le hud_ring_effect_anim;
	uint8_t pad_1CE[0x4];
	u32le join_time;
	u16le last_scroll;
	s16le stall_frames;
	uint8_t pad_1DA[0x26];
};

struct object_type_record
{
	u32le part_count;
	u32le handler;
};

struct type_spawn_record
{
	u16le position;
	u16le projected_x;
	s16le projected_y;
	s16le z;
	u16le object_type;
	u16le spawn_arg_1;
	u16le spawn_arg_2;
};

struct handler_spawn_record
{
	u16le position;
	u16le x;
	u16le y;
	u16le handler_arg;
	u32le handler;
};

struct object_start_list
{
	u16le count;
};

struct machine_fireball_spawns
{
	u16le count;
};

struct machine_fireball_spawn
{
	s16le x;
	s16le y;
	s16le target_x;
	s16le target_y;
	s16le z;
	u32le next_handler;
};

struct ring_row
{
	u16le position;
	u16le template_offset;
	s16le ring_count;
	u16le x;
	u16le y;
	int8_t dx;
	int8_t dy;
};

struct group_spawn_record
{
	u16le position;
	uint8_t kind;
	uint8_t leader;
	uint8_t takes_slot;
	uint8_t pad_05[0x1];
	u32le floor_block;
	u16le member_count;
	u16le step_x;
	u16le step_y;
	u16le direction;
	u16le member_x;
	u16le member_y;
	u16le member_template;
};

struct sprite_buffer_swap
{
	u16le back_buffer_offset;
	u16le list_jump;
};

struct sine_and_cosine
{
	u16le sine;
	uint8_t pad_02[0x1FE];
	u16le cosine;
};

struct floor_attribute_record
{
	union
	{
		s16le push_x;
		uint8_t axis;
	};
	s16le push_y;
	union
	{
		s16le x_per_rise;
		uint8_t ride;
	};
	s16le height;
	s16le top_z;
	u16le along_min;
	u16le along_length;
	u16le rise;
};

struct floor_block_type
{
	uint8_t floor_type;
	uint8_t pad_01[0x1];
	u16le floor_attribute;
};

struct floor_outline_list
{
	u16le count;
};

struct floor_outline
{
	s16le left_x;
	s16le left_y;
	s16le right_x;
	s16le right_y;
	s16le top_x;
	s16le top_y;
	s16le bottom_x;
	s16le bottom_y;
};

struct floor_outline_corner
{
	u16le x;
	u16le y;
};

struct stage_event
{
	u16le position;
	uint8_t next_game_mode;
	uint8_t pad_03[0x1];
};

struct stage_link_point
{
	u16le from_block;
	u16le to_block;
};

struct layer_blend_list
{
	uint8_t count;
};

struct layer_blend_record
{
	uint8_t blend_mask;
	uint8_t layer_bit;
	u16le shadow_offset;
	u16le blend_factor;
};

struct restart_point_record
{
	u16le position;
	uint8_t pad_02[0x6];
};

struct stage_palette
{
	u32le source;
	u32le halfword_count;
};

struct stage_name_banner
{
	u16le screen_x;
	u16le screen_y;
};

struct scroll_mode_step
{
	u16le mode;
	u16le duration;
};

struct event_0f_message
{
	s16le show_time;
	u16le screen_x;
	u16le screen_y;
	u16le kind;
	u16le frames;
};

struct message_box_kind
{
	u16le sprite_frame;
	u16le palette;
	u16le width;
	u16le height;
};

struct stage_06_lightning_strike
{
	s16le strike_time;
	u16le screen_x;
	u16le screen_y;
	u32le animation;
};

struct event_1a_scroll_step
{
	u16le position;
	u16le mode;
	u16le speed;
};

struct stage_03_floor_block_kind
{
	u16le shape;
	u16le fall_flag;
};

struct stage_03_floor_block_shape
{
	int8_t sprite_offset_x;
	int8_t sprite_offset_y;
	u16le depth_offset;
};

struct stage_03_floor_block_animation
{
	u16le last_frame;
	u16le first_frame;
	uint8_t pad_04[0x4];
};

struct rock_debris_piece
{
	u16le sprite_flags;
	u16le offset_x;
	u16le offset_y;
	u16le speed_x;
	u16le speed_y;
	u16le animation_offset;
};

struct spiked_roller_kind
{
	uint8_t part_count;
	u16le layout;
	u16le first_state;
	u16le back_zone;
};

struct spiked_roller_chase_step
{
	u16le position;
	s16le screen_threshold;
	s16le catch_up_factor;
	s16le base_speed;
	u16le wait;
};

struct spiked_roller_layout
{
	int8_t step_x;
	int8_t step_y;
	uint8_t pad_02[0xE];
};

struct spiked_roller_part
{
	u16le sprite_flags;
	u16le hitbox_size_x;
	u16le hitbox_size_y;
	u16le path_direction;
	u32le flags;
	int8_t hitbox_offset_x;
	int8_t hitbox_offset_y;
};

struct spiked_roller_event
{
	u16le position;
	u16le test;
	s16le coordinate;
	u16le state;
};

struct door_roller_spawn
{
	s16le x;
	s16le y;
	uint8_t first_frame;
	uint8_t pad_05[0x1];
};

struct door_fragment
{
	uint8_t pad_00[0x8];
	u16le animation;
};

struct fireball_emitter_list
{
	s16le x;
	s16le y;
	s16le floor_z;
};

struct fireball_type
{
	u16le sprite_flags;
	u16le sprite_palette;
	u16le sprite_scale;
	u16le hitbox_height;
	u16le hitbox_size_x;
	int8_t sprite_offset_x;
	int8_t sprite_offset_y;
	int8_t hitbox_centre_x;
	int8_t hitbox_centre_y;
	u16le animation;
};

struct machine_fire_script_step
{
	s16le height;
	s16le screen_threshold;
	s16le catch_up_factor;
	s16le base_speed;
	u16le wait;
};

struct cage_bar_animation
{
	u16le last_frame;
	uint8_t pad_02[0x4];
	u16le broken_frame;
};

struct fire_vent_spawn
{
	u16le position;
	s16le x;
	s16le y;
	s16le z;
	s16le blast_delay;
};

struct icicle_dropper_record
{
	s16le x;
	s16le y;
	s16le z;
	u16le direction;
	u16le flags;
	u16le script;
};

struct icicle_dropper_step
{
	u16le position;
	s16le screen_threshold;
	s16le catch_up_factor;
	s16le base_speed;
	u16le wait;
	s16le end_coordinate;
};

struct sink_swirl_effect
{
	s16le depth_offset;
	u32le streak_animation;
	u32le puff_animation;
};

struct object_start_place
{
	s16le x;
	s16le y;
	s16le floor_z;
	u16le end_position;
};

struct river_raft_entry
{
	s16le distance;
	u16le speed;
	u32le floor_block;
};

struct geyser_front_record
{
	s16le start_z;
	s16le top_height;
	u16le geyser_list;
};

struct chase_step_at_scroll
{
	u16le position;
	s16le screen_threshold;
	s16le catch_up_factor;
	s16le base_speed;
	u16le wait;
};

struct listed_geyser
{
	u16le position;
	u16le x;
	u16le y;
	u16le z;
	u16le erupt_position;
};

struct stone_block_position
{
	s16le x;
	s16le y;
	s16le z;
	s16le depth_offset;
};

struct geyser_line_start
{
	s16le x;
	s16le y;
	s16le z;
	u16le script;
};

struct geyser_line_step
{
	u16le position;
	s16le y_limit;
	s16le speed;
	s16le wait;
};

struct propeller_machine_animation_step
{
	u16le parts_6_9_frame;
	u16le part_4_frame;
};

struct rope_bridge_rope_offset
{
	s16le dx;
	s16le dy;
};

struct spike_panel_screen_offset
{
	s16le dx;
	s16le dy;
};

struct spike_panel_part_offset
{
	s16le dx;
	s16le dy;
	s16le dz;
};

struct flame_machine_offset
{
	s16le dx;
	s16le dy;
};

struct flame_machine_arm_sway
{
	int8_t dx;
	int8_t dy;
};

struct spiked_disc_hold_offset
{
	s16le dx;
	s16le dz;
};

struct hitbox_size_pair
{
	u16le size_x;
	u16le size_y;
};

struct hitbox_offset_pair
{
	int8_t x;
	int8_t y;
};

struct crawler_walk_row
{
	uint8_t steps[0x6];
};

struct hitbox_size_and_offset
{
	u16le size_x;
	u16le size_y;
	int8_t offset_x;
	int8_t offset_y;
};

struct crawler_piece_offset
{
	s16le dx;
	s16le dy;
};

struct fence_offset
{
	u16le dx;
	u16le dy;
};

struct fence_post_box
{
	u16le size_x;
	u16le size_y;
};

struct fence_post_box_offset
{
	int8_t x;
	int8_t y;
};

struct sprite_palette_cycle
{
	u16le last_index;
	u16le palettes[];
};

struct hud_step_list
{
	u16le last_index;
	u16le steps[];
};

struct eggman_speech_step
{
	s16le delay;
	u16le command;
	u16le arguments[];
};

struct how_to_play_button_press
{
	u16le press_time;
	u16le frame;
};

struct coin_setting_value
{
	uint8_t coins_per_credit;
	uint8_t bonus_coins;
	uint8_t chute_1_coin_value;
	uint8_t chute_2_coin_value;
};

struct ending_tower_frame
{
	s16le end_time;
	u16le sprite_frame;
	u16le sprite_palette;
};

struct ending_explosion_frame
{
	u16le sprite_frame;
	u16le sprite_flags;
};

struct ending_music_cue
{
	s16le time;
	u16le sound_id;
};

struct ending_timed_frame
{
	s16le end_time;
	u16le sprite_frame;
};

struct ending_timed_palette
{
	s16le end_time;
	u16le sprite_palette;
};

struct scenery_kind_record
{
	u16le sprite_flags;
	u16le sprite_frame;
	u16le sprite_palette;
	s16le depth_offset;
	u32le handler;
};

struct group_leader_hold_record
{
	uint8_t leader;
	uint8_t direction;
	s16le coordinate;
	u16le end_position;
	u16le which_flag;
};

struct tornado_start_record
{
	u16le x;
	u16le y;
	u16le hazard_list_offset;
	u16le whirlwind_list_offset;
};

struct tornado_path_step
{
	u16le position;
	s16le coordinate;
	s16le screen_threshold;
	s16le catch_up_factor;
	s16le base_speed;
	u16le wait;
	u16le direction;
};

struct default_ranking_record
{
	u16le rings;
	u16le character_and_stages;
	uint8_t first_letter;
	uint8_t second_letter;
	uint8_t third_letter;
	uint8_t letters_pad;
};

struct wall_kind_offsets
{
	int8_t hitbox_offset_x;
	int8_t hitbox_offset_y;
	int8_t sprite_offset_x;
	int8_t sprite_offset_y;
	uint8_t direction;
	uint8_t pad_05[0x1];
};

struct wall_kind_parts
{
	u16le size_x;
	u16le size_y;
	u16le palette;
	uint8_t part_step_x;
	uint8_t part_step_y;
	s16le part_sprite;
	uint8_t second_offset_x;
	uint8_t second_offset_y;
	s16le second_sprite;
};

struct timed_spawn
{
	s16le time;
	u16le handler_offset;
};

struct crt_test_color_bar_row
{
	u16le x;
	u16le y;
	uint8_t first_color;
};

struct sound_command_bytes
{
	uint8_t group;
	uint8_t number;
};

struct chooser_voice_row
{
	uint8_t sounds[0x4];
};

struct map_icon_position
{
	u16le x;
	u16le y;
};

struct crt_test_line
{
	u16le start_x;
	u16le start_y;
	u16le end_x;
	u16le end_y;
};

struct screen_sign_kind
{
	u16le sprite_frame;
	u16le duration;
	u16le palette_list_offset;
};

struct ram_target_damage_step
{
	int8_t hits;
	uint8_t pad_01[0x1];
	u16le animation;
};

struct falling_rock
{
	u16le x;
	u16le y;
	u16le z;
	s16le speed_x;
	s16le speed_y;
	u32le animation;
};

struct line_direction_step
{
	s16le row_step;
	s16le column_step;
};

struct flood_fill_record
{
	u16le direction_and_y;
	u16le right_x;
	u32le right_address;
	u16le left_x;
	u32le left_address;
	u16le parent_right_x;
	u32le parent_right_address;
	u16le parent_left_x;
	u32le parent_left_address;
};

struct floor_block
{
	s32le x_min;
	s32le x_max;
	s32le y_min;
	s32le y_max;
	s16le height;
	uint8_t type_index;
	uint8_t slope;
	uint8_t fall_priorities;
	uint8_t travel_direction;
};

struct bridge_load
{
	uint8_t count;
	uint8_t pad_01[0x4F];
};

struct stage_object_record
{
	u16le sprite_flags;
	u16le sprite_frame;
	u16le sprite_palette;
	u32le handler;
	u32le animation;
	u16le hitbox_size_x;
	u16le hitbox_size_y;
	int8_t sprite_offset_x;
	int8_t sprite_offset_y;
	s16le depth_offset;
};

struct stage_object_record_2
{
	u16le sprite_flags;
	u16le sprite_frame;
	u16le sprite_palette;
	u32le handler;
	u32le animation;
	u32le odd_member_animation;
	u16le hitbox_size_x;
	u16le hitbox_size_y;
	s16le depth_offset;
};

struct stage_object_template
{
	u16le sprite_flags;
	u16le sprite_frame;
	u16le sprite_palette;
	u16le hitbox_size_x;
	u16le hover_height;
	uint8_t animation_speed;
	int8_t animation_timer;
	uint8_t animation_frame;
	uint8_t kind;
	u32le animation;
	u32le handler;
	int8_t sprite_offset_x;
	int8_t sprite_offset_y;
	u16le hitbox_height;
};

struct sprite_part_list
{
	u16le count;
	u16le part_0_frame;
	uint8_t pad_04[0x6];
	u16le part_1_frame;
	uint8_t pad_0C[0x76];
};

struct sprite_part
{
	u16le frame;
	u16le flags;
	int8_t dx;
	int8_t dy;
	u16le palette;
};

struct frame_animation
{
	u16le last_frame;
	u16le frames[];
};

struct animation_step
{
	u16le frame;
	int8_t dx;
	int8_t dy;
};

struct sign_kind
{
	s16le z;
	u16le sprite_frame;
	u16le duration;
	u16le palette_list_offset;
	u32le handler;
};

struct back_zone_record
{
	u16le limit;
	u32le handler;
};

struct metal_wall_part_offset
{
	int8_t dx;
	int8_t dy;
};

struct wall_spawn
{
	u16le position;
	u16le end_position;
	u16le x;
	u16le y;
	u16le z;
	u16le kind;
	uint8_t part_count;
	uint8_t depth_from_next;
};

struct object_pair_template
{
	u32le handler;
	u32le animation;
	int8_t sprite_offset_x;
	int8_t sprite_offset_y;
	uint8_t launch_kind;
	uint8_t pad_0B[0x1];
	u16le base_hitbox_size_x;
	u16le base_hitbox_size_y;
	int8_t base_hitbox_offset_x;
	int8_t base_hitbox_offset_y;
	u32le base_handler;
	u32le base_animation;
};

struct fireball_shot
{
	u16le position;
	s16le x;
	s16le dy;
	s16le speed_y;
	s16le speed_z;
	u16le type;
};

struct tornado_hazard
{
	u16le position;
	s16le coordinate;
};

struct sinkhole_growth
{
	u16le zoom_step;
	u16le open_delay;
};

struct centipede_path_point
{
	s16le projected_x;
	s16le projected_y;
};

struct clip_entry
{
	u16le draw_next;
	u16le command;
	u16le bottom;
	u16le left;
	u16le right;
	u16le unk_0A;
	u16le unk_0C;
	u16le unk_0E;
	u16le unk_10;
};

struct grate_debris_piece
{
	s16le dx;
	s16le dy;
	s16le speed_x;
	s16le speed_z;
	u16le animation;
};

struct opening_scene_position
{
	s16le screen_x;
	s16le projected_y;
	u16le zoom;
};

struct leader_spawn
{
	uint8_t leader;
	s16le x;
	s16le y;
	s16le z;
	u16le direction;
	u16le path;
};

struct ice_leader_spawn
{
	uint8_t leader;
	u16le end_position;
	s16le reference_x;
	s16le x;
	s16le y;
	s16le z;
};

struct credit_block
{
	union
	{
		u32le counts_long;
		uint8_t coins;
		u16le counts;
		struct
		{
			uint8_t pad_00[0x1];
			uint8_t credits;
			uint8_t bonus_coins;
			uint8_t changed;
		};
	};
};

struct trackball_motion
{
	s16le x;
	s16le y;
};

struct flagged_step
{
	u16le flags;
	u16le frame;
};

struct player_palette_list
{
	u16le last_index;
	u16le normal_palette;
	uint8_t pad_04[0x4];
};

struct edge_voice_scroll_range
{
	u16le start;
	u16le length;
};

struct screen_edge_push
{
	u16le limit_direction;
	u16le push_direction;
};

struct slope_speed_pair
{
	u16le speed_factor;
	u16le direction;
};

struct floor_type_player_state
{
	uint8_t state;
};

struct teeter_record
{
	u16le first_frame;
};

struct teeter_animation_offsets
{
	u16le offsets[0x2];
};

struct shocked_palette_row
{
	u16le palettes[0x8];
};

struct edge_hang_animations
{
	uint8_t pad_00[0x36];
	u16le hold_frame;
	u16le let_go_frame;
	u16le slip_piece_frame;
};

struct player_bounce_record
{
	u16le direction;
	u16le sprite_flags;
	u16le animation_offset;
};

struct knocked_out_entry
{
	u16le sprite_flags;
	u16le animation_offset;
};

struct restart_point
{
	u16le until;
	uint8_t kind;
	uint8_t screen_y;
	u16le x;
	u16le y_or_height;
};

struct stage_start_point
{
	u16le spacing_shift;
	u16le x;
	u16le y;
};

struct stage_goal
{
	u16le position;
	u16le direction;
	u16le line;
	uint8_t exit_path;
	uint8_t pad_07[0x5];
};

struct stage_goal_line_range
{
	u16le line_min;
	u16le line_max;
};

struct player_path_step
{
	s16le speed;
	u16le x_or_wait;
	u16le y;
	u16le flags;
};

struct hud_portrait_sprite
{
	u16le frame;
	u16le palette;
};

struct hud_palette_cycle
{
	u16le last_index;
};

struct floor_slope
{
	uint8_t flags;
	uint8_t pad_01[0x1];
	s32le factor;
	u16le direction_table;
};

struct sand_block_part_list
{
	u16le count;
	uint8_t pad_02[0x6];
	u16le first_palette;
};

struct flagged_animation_start
{
	u16le last_step;
	u16le first_flags;
	u16le first_frame;
	u16le second_flags;
};

struct debris_path_step
{
	s16le end_time;
	s16le screen_x;
	s16le screen_y;
	u16le sprite_frame;
};

struct dust_cloud_frame
{
	s16le screen_y;
	u16le sprite_frame;
};

struct credit_part
{
	u16le sprite_frame;
	s16le screen_y;
	u16le sprite_palette;
	u16le slot;
};

struct screen_point
{
	s16le x;
	s16le y;
};

struct map_marker_layout
{
	u16le sprite_layer;
	s16le screen_x;
	s16le screen_y;
	u16le sprite_frame;
	u16le sprite_palette;
	u16le cleared_palette;
};

struct map_marker_blink
{
	u16le sprite_layer;
	s16le screen_x;
	s16le screen_y;
	u16le sprite_frame;
	u16le sprite_palette;
};

struct wipe_window
{
	s16le left;
	s16le top;
	u16le frames;
};

struct ranking_record
{
	union
	{
		u32le rings_long;
		s16le rings;
		struct
		{
			uint8_t pad_00[0x2];
			union
			{
				u16le character_and_stages;
				uint8_t character;
				struct
				{
					uint8_t pad_02[0x1];
					uint8_t stages_reached;
				};
			};
		};
	};
	union
	{
		u32le initials;
		uint8_t first_initial;
		struct
		{
			uint8_t pad_04[0x1];
			uint8_t second_initial;
			uint8_t third_initial;
			uint8_t initials_pad;
		};
	};
};

struct ranking_row_number
{
	uint8_t tens_code;
	uint8_t units_code;
};

struct ring_tally_portrait
{
	u16le sprite_palette;
	u16le sprite_frame;
	u16le no_bonus_frame;
	u16le bonus_frame;
};

struct ring_tally_result_faces
{
	u16le no_bonus_frame;
	u16le bonus_frame;
};

struct geyser_rise_step
{
	u16le frames;
	u16le rise_speed;
};

struct palette_set_cycle
{
	u32le frames;
	u32le dest;
	uint8_t timer;
	uint8_t rows_left;
	uint8_t delay;
	uint8_t rows;
	int8_t frame;
	int8_t frame_count;
	uint8_t pad_0E[0x2];
};

struct palette_cycle
{
	uint8_t delay;
	int8_t frame_count;
	uint8_t pad_02[0x1];
	int8_t frame;
	int8_t timer;
};

struct coin_counter
{
	union
	{
		u16le pulse_timers;
		uint8_t on_frames;
		struct
		{
			uint8_t pad_00[0x1];
			uint8_t off_frames;
		};
	};
	uint8_t pending_coins;
	uint8_t chute_multiplier;
};

struct text_cell_position
{
	uint8_t column;
	uint8_t row;
};

struct polygon_span
{
	u32le address;
	s16le length;
};

struct quad_vertex
{
	s16le x;
	s16le y;
};

struct picture_colour_slot
{
	uint8_t next;
	uint8_t previous;
	uint8_t colour;
};

struct saved_bitmap_rect
{
	u32le row_bits;
	u32le rows;
};

struct demo_header
{
	u16le stage_number;
	u16le start_section;
	uint8_t pad_04[0xC];
};

struct vblank_copy
{
	u32le source;
	u32le dest;
	u16le halfwords;
};

struct sprite_frame_record
{
	u16le width;
	u16le height;
	u16le bank_bits;
	u16le address;
};

struct string_record
{
	u16le x;
	u16le y;
	u16le palette;
	u16le scale;
};

struct queued_string
{
	s16le x;
	s16le y;
	u16le palette;
	u16le scale;
	u32le text;
};

struct placed_text
{
	u16le position;
	uint8_t string[];
};

struct tilemap_skip
{
	int8_t cells;
};

struct tilemap_long_skip
{
	s16le cells;
};

struct vram_script_address
{
	u16le cell;
};

struct vram_script_cell_run
{
	uint8_t count;
	u16le cell;
};

struct vram_script_byte_cells
{
	uint8_t count;
	uint8_t high_byte;
};

struct vram_script_word_cells
{
	uint8_t count;
};

struct vram_script_page_clear
{
	u16le cell;
	uint8_t pages;
};

struct video_register_defaults_tail
{
	u32le text_backdrop_control;
	u32le bitmap_scroll;
	u32le bitmap_control;
};

struct palette_load_list
{
	u16le entry_count;
};

struct palette_list_entry
{
	u32le source;
	u16le palette_offset;
	u16le copy_mode;
};

struct palette_pens_1_15
{
	u32le pens_1_2;
	u32le pens_3_4;
	u32le pens_5_6;
	u32le pens_7_8;
	u32le pens_9_10;
	u32le pens_11_12;
	u32le pens_13_14;
	u16le pen_15;
};

struct palette_repeat_source
{
	u32le palettes;
};

struct chase_step_with_limit
{
	u16le position;
	s16le limit;
	s16le screen_threshold;
	s16le catch_up_factor;
	s16le base_speed;
	u16le wait;
};

struct biting_head_path_entry
{
	u16le position;
	s16le limit;
	s16le screen_threshold;
	s16le catch_up_factor;
	s16le base_speed;
	u16le wait;
	u16le direction;
};

struct bridge_fire_script_entry
{
	s16le height;
	u16le position;
	s16le screen_threshold;
	s16le catch_up_factor;
	s16le base_speed;
	u16le wait;
};

struct fire_front_path_start
{
	s16le x;
	s16le y;
	s16le floor_z;
	u16le direction;
};

struct biting_head_path_start
{
	s16le x;
	s16le y;
};

struct rising_saw_path_start
{
	s16le x;
	s16le y;
	s16le z;
};

struct brick_wall_brick
{
	u16le sprite_flags;
	u16le offset_x;
	u16le offset_y;
	u16le speed_x;
	u16le speed_y;
	u16le look;
};

struct brick_look
{
	u16le palette;
};

struct brick_dust_puff
{
	u16le sprite_flags;
	u16le offset_x;
	u16le offset_y;
	u16le delay;
};

struct biting_head_bite_step
{
	u16le jaw_frame;
	uint8_t hold;
	uint8_t pad_03[0x1];
};

struct grate_step_debris_list
{
	s16le count;
};

struct burning_boulder_record
{
	s16le x;
	s16le start_delay;
	u32le path;
};

struct burning_boulder_flame_offset
{
	s16le dx;
	s16le dy;
	u16le animation;
};

struct falling_ember_speed
{
	s16le speed_z;
	s16le speed_y;
};

struct scene_carrier_record
{
	s16le x;
	s16le y;
	s16le z;
	s32le speed_x;
	s32le speed_y;
	s32le speed_z;
	u16le end_position;
};

struct lava_steam_puff_offset
{
	s16le dx;
	s16le dy;
};

struct group_slot_trigger_record
{
	u16le position;
	s16le slot;
	u16le delay;
};

#pragma pack(pop)

_Static_assert(sizeof(struct object) == 0xA0, "struct object has the size of the game's blocks");
_Static_assert(sizeof(struct player) == 0x200, "struct player has the size of the game's blocks");
_Static_assert(sizeof(struct object_type_record) == 0x8, "struct object_type_record has the size of the program ROM's records");
_Static_assert(sizeof(struct type_spawn_record) == 0xE, "struct type_spawn_record has the size of the program ROM's records");
_Static_assert(sizeof(struct handler_spawn_record) == 0xC, "struct handler_spawn_record has the size of the program ROM's records");
_Static_assert(sizeof(struct object_start_list) == 0x2, "struct object_start_list has the size of the program ROM's records");
_Static_assert(sizeof(struct machine_fireball_spawns) == 0x2, "struct machine_fireball_spawns has the size of the program ROM's records");
_Static_assert(sizeof(struct machine_fireball_spawn) == 0xE, "struct machine_fireball_spawn has the size of the program ROM's records");
_Static_assert(sizeof(struct ring_row) == 0xC, "struct ring_row has the size of the program ROM's records");
_Static_assert(sizeof(struct group_spawn_record) == 0x18, "struct group_spawn_record has the size of the program ROM's records");
_Static_assert(sizeof(struct sprite_buffer_swap) == 0x4, "struct sprite_buffer_swap has the size of the program ROM's records");
_Static_assert(sizeof(struct sine_and_cosine) == 0x202, "struct sine_and_cosine has the size of the program ROM's records");
_Static_assert(sizeof(struct floor_attribute_record) == 0x10, "struct floor_attribute_record has the size of the program ROM's records");
_Static_assert(sizeof(struct floor_block_type) == 0x4, "struct floor_block_type has the size of the program ROM's records");
_Static_assert(sizeof(struct floor_outline_list) == 0x2, "struct floor_outline_list has the size of the program ROM's records");
_Static_assert(sizeof(struct floor_outline) == 0x10, "struct floor_outline has the size of the program ROM's records");
_Static_assert(sizeof(struct floor_outline_corner) == 0x4, "struct floor_outline_corner has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_event) == 0x4, "struct stage_event has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_link_point) == 0x4, "struct stage_link_point has the size of the program ROM's records");
_Static_assert(sizeof(struct layer_blend_list) == 0x1, "struct layer_blend_list has the size of the program ROM's records");
_Static_assert(sizeof(struct layer_blend_record) == 0x6, "struct layer_blend_record has the size of the program ROM's records");
_Static_assert(sizeof(struct restart_point_record) == 0x8, "struct restart_point_record has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_palette) == 0x8, "struct stage_palette has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_name_banner) == 0x4, "struct stage_name_banner has the size of the program ROM's records");
_Static_assert(sizeof(struct scroll_mode_step) == 0x4, "struct scroll_mode_step has the size of the program ROM's records");
_Static_assert(sizeof(struct event_0f_message) == 0xA, "struct event_0f_message has the size of the program ROM's records");
_Static_assert(sizeof(struct message_box_kind) == 0x8, "struct message_box_kind has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_06_lightning_strike) == 0xA, "struct stage_06_lightning_strike has the size of the program ROM's records");
_Static_assert(sizeof(struct event_1a_scroll_step) == 0x6, "struct event_1a_scroll_step has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_03_floor_block_kind) == 0x4, "struct stage_03_floor_block_kind has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_03_floor_block_shape) == 0x4, "struct stage_03_floor_block_shape has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_03_floor_block_animation) == 0x8, "struct stage_03_floor_block_animation has the size of the program ROM's records");
_Static_assert(sizeof(struct rock_debris_piece) == 0xC, "struct rock_debris_piece has the size of the program ROM's records");
_Static_assert(sizeof(struct spiked_roller_kind) == 0x7, "struct spiked_roller_kind has the size of the program ROM's records");
_Static_assert(sizeof(struct spiked_roller_chase_step) == 0xA, "struct spiked_roller_chase_step has the size of the program ROM's records");
_Static_assert(sizeof(struct spiked_roller_layout) == 0x10, "struct spiked_roller_layout has the size of the program ROM's records");
_Static_assert(sizeof(struct spiked_roller_part) == 0xE, "struct spiked_roller_part has the size of the program ROM's records");
_Static_assert(sizeof(struct spiked_roller_event) == 0x8, "struct spiked_roller_event has the size of the program ROM's records");
_Static_assert(sizeof(struct door_roller_spawn) == 0x6, "struct door_roller_spawn has the size of the program ROM's records");
_Static_assert(sizeof(struct door_fragment) == 0xA, "struct door_fragment has the size of the program ROM's records");
_Static_assert(sizeof(struct fireball_emitter_list) == 0x6, "struct fireball_emitter_list has the size of the program ROM's records");
_Static_assert(sizeof(struct fireball_type) == 0x10, "struct fireball_type has the size of the program ROM's records");
_Static_assert(sizeof(struct machine_fire_script_step) == 0xA, "struct machine_fire_script_step has the size of the program ROM's records");
_Static_assert(sizeof(struct cage_bar_animation) == 0x8, "struct cage_bar_animation has the size of the program ROM's records");
_Static_assert(sizeof(struct fire_vent_spawn) == 0xA, "struct fire_vent_spawn has the size of the program ROM's records");
_Static_assert(sizeof(struct icicle_dropper_record) == 0xC, "struct icicle_dropper_record has the size of the program ROM's records");
_Static_assert(sizeof(struct icicle_dropper_step) == 0xC, "struct icicle_dropper_step has the size of the program ROM's records");
_Static_assert(sizeof(struct sink_swirl_effect) == 0xA, "struct sink_swirl_effect has the size of the program ROM's records");
_Static_assert(sizeof(struct object_start_place) == 0x8, "struct object_start_place has the size of the program ROM's records");
_Static_assert(sizeof(struct river_raft_entry) == 0x8, "struct river_raft_entry has the size of the program ROM's records");
_Static_assert(sizeof(struct geyser_front_record) == 0x6, "struct geyser_front_record has the size of the program ROM's records");
_Static_assert(sizeof(struct chase_step_at_scroll) == 0xA, "struct chase_step_at_scroll has the size of the program ROM's records");
_Static_assert(sizeof(struct listed_geyser) == 0xA, "struct listed_geyser has the size of the program ROM's records");
_Static_assert(sizeof(struct stone_block_position) == 0x8, "struct stone_block_position has the size of the program ROM's records");
_Static_assert(sizeof(struct geyser_line_start) == 0x8, "struct geyser_line_start has the size of the program ROM's records");
_Static_assert(sizeof(struct geyser_line_step) == 0x8, "struct geyser_line_step has the size of the program ROM's records");
_Static_assert(sizeof(struct propeller_machine_animation_step) == 0x4, "struct propeller_machine_animation_step has the size of the program ROM's records");
_Static_assert(sizeof(struct rope_bridge_rope_offset) == 0x4, "struct rope_bridge_rope_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct spike_panel_screen_offset) == 0x4, "struct spike_panel_screen_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct spike_panel_part_offset) == 0x6, "struct spike_panel_part_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct flame_machine_offset) == 0x4, "struct flame_machine_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct flame_machine_arm_sway) == 0x2, "struct flame_machine_arm_sway has the size of the program ROM's records");
_Static_assert(sizeof(struct spiked_disc_hold_offset) == 0x4, "struct spiked_disc_hold_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct hitbox_size_pair) == 0x4, "struct hitbox_size_pair has the size of the program ROM's records");
_Static_assert(sizeof(struct hitbox_offset_pair) == 0x2, "struct hitbox_offset_pair has the size of the program ROM's records");
_Static_assert(sizeof(struct crawler_walk_row) == 0x6, "struct crawler_walk_row has the size of the program ROM's records");
_Static_assert(sizeof(struct hitbox_size_and_offset) == 0x6, "struct hitbox_size_and_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct crawler_piece_offset) == 0x4, "struct crawler_piece_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct fence_offset) == 0x4, "struct fence_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct fence_post_box) == 0x4, "struct fence_post_box has the size of the program ROM's records");
_Static_assert(sizeof(struct fence_post_box_offset) == 0x2, "struct fence_post_box_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct sprite_palette_cycle) == 0x2, "struct sprite_palette_cycle has the size of the program ROM's records");
_Static_assert(sizeof(struct hud_step_list) == 0x2, "struct hud_step_list has the size of the program ROM's records");
_Static_assert(sizeof(struct eggman_speech_step) == 0x4, "struct eggman_speech_step has the size of the program ROM's records");
_Static_assert(sizeof(struct how_to_play_button_press) == 0x4, "struct how_to_play_button_press has the size of the program ROM's records");
_Static_assert(sizeof(struct coin_setting_value) == 0x4, "struct coin_setting_value has the size of the program ROM's records");
_Static_assert(sizeof(struct ending_tower_frame) == 0x6, "struct ending_tower_frame has the size of the program ROM's records");
_Static_assert(sizeof(struct ending_explosion_frame) == 0x4, "struct ending_explosion_frame has the size of the program ROM's records");
_Static_assert(sizeof(struct ending_music_cue) == 0x4, "struct ending_music_cue has the size of the program ROM's records");
_Static_assert(sizeof(struct ending_timed_frame) == 0x4, "struct ending_timed_frame has the size of the program ROM's records");
_Static_assert(sizeof(struct ending_timed_palette) == 0x4, "struct ending_timed_palette has the size of the program ROM's records");
_Static_assert(sizeof(struct scenery_kind_record) == 0xC, "struct scenery_kind_record has the size of the program ROM's records");
_Static_assert(sizeof(struct group_leader_hold_record) == 0x8, "struct group_leader_hold_record has the size of the program ROM's records");
_Static_assert(sizeof(struct tornado_start_record) == 0x8, "struct tornado_start_record has the size of the program ROM's records");
_Static_assert(sizeof(struct tornado_path_step) == 0xE, "struct tornado_path_step has the size of the program ROM's records");
_Static_assert(sizeof(struct default_ranking_record) == 0x8, "struct default_ranking_record has the size of the program ROM's records");
_Static_assert(sizeof(struct wall_kind_offsets) == 0x6, "struct wall_kind_offsets has the size of the program ROM's records");
_Static_assert(sizeof(struct wall_kind_parts) == 0xE, "struct wall_kind_parts has the size of the program ROM's records");
_Static_assert(sizeof(struct timed_spawn) == 0x4, "struct timed_spawn has the size of the program ROM's records");
_Static_assert(sizeof(struct crt_test_color_bar_row) == 0x5, "struct crt_test_color_bar_row has the size of the program ROM's records");
_Static_assert(sizeof(struct sound_command_bytes) == 0x2, "struct sound_command_bytes has the size of the program ROM's records");
_Static_assert(sizeof(struct chooser_voice_row) == 0x4, "struct chooser_voice_row has the size of the program ROM's records");
_Static_assert(sizeof(struct map_icon_position) == 0x4, "struct map_icon_position has the size of the program ROM's records");
_Static_assert(sizeof(struct crt_test_line) == 0x8, "struct crt_test_line has the size of the program ROM's records");
_Static_assert(sizeof(struct screen_sign_kind) == 0x6, "struct screen_sign_kind has the size of the program ROM's records");
_Static_assert(sizeof(struct ram_target_damage_step) == 0x4, "struct ram_target_damage_step has the size of the program ROM's records");
_Static_assert(sizeof(struct falling_rock) == 0xE, "struct falling_rock has the size of the program ROM's records");
_Static_assert(sizeof(struct line_direction_step) == 0x4, "struct line_direction_step has the size of the program ROM's records");
_Static_assert(sizeof(struct flood_fill_record) == 0x1A, "struct flood_fill_record has the size of the game's blocks");
_Static_assert(sizeof(struct floor_block) == 0x16, "struct floor_block has the size of the program ROM's records");
_Static_assert(sizeof(struct bridge_load) == 0x50, "struct bridge_load has the size of the game's blocks");
_Static_assert(sizeof(struct stage_object_record) == 0x16, "struct stage_object_record has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_object_record_2) == 0x18, "struct stage_object_record_2 has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_object_template) == 0x1A, "struct stage_object_template has the size of the program ROM's records");
_Static_assert(sizeof(struct sprite_part_list) == 0x82, "struct sprite_part_list has the size of the game's blocks");
_Static_assert(sizeof(struct sprite_part) == 0x8, "struct sprite_part has the size of the game's blocks");
_Static_assert(sizeof(struct frame_animation) == 0x2, "struct frame_animation has the size of the program ROM's records");
_Static_assert(sizeof(struct animation_step) == 0x4, "struct animation_step has the size of the program ROM's records");
_Static_assert(sizeof(struct sign_kind) == 0xC, "struct sign_kind has the size of the program ROM's records");
_Static_assert(sizeof(struct back_zone_record) == 0x6, "struct back_zone_record has the size of the program ROM's records");
_Static_assert(sizeof(struct metal_wall_part_offset) == 0x2, "struct metal_wall_part_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct wall_spawn) == 0xE, "struct wall_spawn has the size of the program ROM's records");
_Static_assert(sizeof(struct object_pair_template) == 0x1A, "struct object_pair_template has the size of the program ROM's records");
_Static_assert(sizeof(struct fireball_shot) == 0xC, "struct fireball_shot has the size of the program ROM's records");
_Static_assert(sizeof(struct tornado_hazard) == 0x4, "struct tornado_hazard has the size of the program ROM's records");
_Static_assert(sizeof(struct sinkhole_growth) == 0x4, "struct sinkhole_growth has the size of the program ROM's records");
_Static_assert(sizeof(struct centipede_path_point) == 0x4, "struct centipede_path_point has the size of the game's blocks");
_Static_assert(sizeof(struct clip_entry) == 0x12, "struct clip_entry has the size of the game's blocks");
_Static_assert(sizeof(struct grate_debris_piece) == 0xA, "struct grate_debris_piece has the size of the program ROM's records");
_Static_assert(sizeof(struct opening_scene_position) == 0x6, "struct opening_scene_position has the size of the program ROM's records");
_Static_assert(sizeof(struct leader_spawn) == 0xB, "struct leader_spawn has the size of the program ROM's records");
_Static_assert(sizeof(struct ice_leader_spawn) == 0xB, "struct ice_leader_spawn has the size of the program ROM's records");
_Static_assert(sizeof(struct credit_block) == 0x4, "struct credit_block has the size of the game's blocks");
_Static_assert(sizeof(struct trackball_motion) == 0x4, "struct trackball_motion has the size of the game's blocks");
_Static_assert(sizeof(struct flagged_step) == 0x4, "struct flagged_step has the size of the program ROM's records");
_Static_assert(sizeof(struct player_palette_list) == 0x8, "struct player_palette_list has the size of the program ROM's records");
_Static_assert(sizeof(struct edge_voice_scroll_range) == 0x4, "struct edge_voice_scroll_range has the size of the program ROM's records");
_Static_assert(sizeof(struct screen_edge_push) == 0x4, "struct screen_edge_push has the size of the program ROM's records");
_Static_assert(sizeof(struct slope_speed_pair) == 0x4, "struct slope_speed_pair has the size of the program ROM's records");
_Static_assert(sizeof(struct floor_type_player_state) == 0x1, "struct floor_type_player_state has the size of the program ROM's records");
_Static_assert(sizeof(struct teeter_record) == 0x2, "struct teeter_record has the size of the program ROM's records");
_Static_assert(sizeof(struct teeter_animation_offsets) == 0x4, "struct teeter_animation_offsets has the size of the program ROM's records");
_Static_assert(sizeof(struct shocked_palette_row) == 0x10, "struct shocked_palette_row has the size of the program ROM's records");
_Static_assert(sizeof(struct edge_hang_animations) == 0x3C, "struct edge_hang_animations has the size of the program ROM's records");
_Static_assert(sizeof(struct player_bounce_record) == 0x6, "struct player_bounce_record has the size of the program ROM's records");
_Static_assert(sizeof(struct knocked_out_entry) == 0x4, "struct knocked_out_entry has the size of the program ROM's records");
_Static_assert(sizeof(struct restart_point) == 0x8, "struct restart_point has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_start_point) == 0x6, "struct stage_start_point has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_goal) == 0xC, "struct stage_goal has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_goal_line_range) == 0x4, "struct stage_goal_line_range has the size of the program ROM's records");
_Static_assert(sizeof(struct player_path_step) == 0x8, "struct player_path_step has the size of the program ROM's records");
_Static_assert(sizeof(struct hud_portrait_sprite) == 0x4, "struct hud_portrait_sprite has the size of the program ROM's records");
_Static_assert(sizeof(struct hud_palette_cycle) == 0x2, "struct hud_palette_cycle has the size of the program ROM's records");
_Static_assert(sizeof(struct floor_slope) == 0x8, "struct floor_slope has the size of the program ROM's records");
_Static_assert(sizeof(struct sand_block_part_list) == 0xA, "struct sand_block_part_list has the size of the program ROM's records");
_Static_assert(sizeof(struct flagged_animation_start) == 0x8, "struct flagged_animation_start has the size of the program ROM's records");
_Static_assert(sizeof(struct debris_path_step) == 0x8, "struct debris_path_step has the size of the program ROM's records");
_Static_assert(sizeof(struct dust_cloud_frame) == 0x4, "struct dust_cloud_frame has the size of the program ROM's records");
_Static_assert(sizeof(struct credit_part) == 0x8, "struct credit_part has the size of the program ROM's records");
_Static_assert(sizeof(struct screen_point) == 0x4, "struct screen_point has the size of the program ROM's records");
_Static_assert(sizeof(struct map_marker_layout) == 0xC, "struct map_marker_layout has the size of the program ROM's records");
_Static_assert(sizeof(struct map_marker_blink) == 0xA, "struct map_marker_blink has the size of the program ROM's records");
_Static_assert(sizeof(struct wipe_window) == 0x6, "struct wipe_window has the size of the program ROM's records");
_Static_assert(sizeof(struct ranking_record) == 0x8, "struct ranking_record has the size of the game's blocks");
_Static_assert(sizeof(struct ranking_row_number) == 0x2, "struct ranking_row_number has the size of the program ROM's records");
_Static_assert(sizeof(struct ring_tally_portrait) == 0x8, "struct ring_tally_portrait has the size of the program ROM's records");
_Static_assert(sizeof(struct ring_tally_result_faces) == 0x4, "struct ring_tally_result_faces has the size of the program ROM's records");
_Static_assert(sizeof(struct geyser_rise_step) == 0x4, "struct geyser_rise_step has the size of the program ROM's records");
_Static_assert(sizeof(struct palette_set_cycle) == 0x10, "struct palette_set_cycle has the size of the game's blocks");
_Static_assert(sizeof(struct palette_cycle) == 0x5, "struct palette_cycle has the size of the game's blocks");
_Static_assert(sizeof(struct coin_counter) == 0x4, "struct coin_counter has the size of the game's blocks");
_Static_assert(sizeof(struct text_cell_position) == 0x2, "struct text_cell_position has the size of the program ROM's records");
_Static_assert(sizeof(struct polygon_span) == 0x6, "struct polygon_span has the size of the game's blocks");
_Static_assert(sizeof(struct quad_vertex) == 0x4, "struct quad_vertex has the size of the game's blocks");
_Static_assert(sizeof(struct picture_colour_slot) == 0x3, "struct picture_colour_slot has the size of the game's blocks");
_Static_assert(sizeof(struct saved_bitmap_rect) == 0x8, "struct saved_bitmap_rect has the size of the game's blocks");
_Static_assert(sizeof(struct demo_header) == 0x10, "struct demo_header has the size of the program ROM's records");
_Static_assert(sizeof(struct vblank_copy) == 0xA, "struct vblank_copy has the size of the game's blocks");
_Static_assert(sizeof(struct sprite_frame_record) == 0x8, "struct sprite_frame_record has the size of the program ROM's records");
_Static_assert(sizeof(struct string_record) == 0x8, "struct string_record has the size of the program ROM's records");
_Static_assert(sizeof(struct queued_string) == 0xC, "struct queued_string has the size of the game's blocks");
_Static_assert(sizeof(struct placed_text) == 0x2, "struct placed_text has the size of the program ROM's records");
_Static_assert(sizeof(struct tilemap_skip) == 0x1, "struct tilemap_skip has the size of the program ROM's records");
_Static_assert(sizeof(struct tilemap_long_skip) == 0x2, "struct tilemap_long_skip has the size of the program ROM's records");
_Static_assert(sizeof(struct vram_script_address) == 0x2, "struct vram_script_address has the size of the program ROM's records");
_Static_assert(sizeof(struct vram_script_cell_run) == 0x3, "struct vram_script_cell_run has the size of the program ROM's records");
_Static_assert(sizeof(struct vram_script_byte_cells) == 0x2, "struct vram_script_byte_cells has the size of the program ROM's records");
_Static_assert(sizeof(struct vram_script_word_cells) == 0x1, "struct vram_script_word_cells has the size of the program ROM's records");
_Static_assert(sizeof(struct vram_script_page_clear) == 0x3, "struct vram_script_page_clear has the size of the program ROM's records");
_Static_assert(sizeof(struct video_register_defaults_tail) == 0xC, "struct video_register_defaults_tail has the size of the program ROM's records");
_Static_assert(sizeof(struct palette_load_list) == 0x2, "struct palette_load_list has the size of the program ROM's records");
_Static_assert(sizeof(struct palette_list_entry) == 0x8, "struct palette_list_entry has the size of the program ROM's records");
_Static_assert(sizeof(struct palette_pens_1_15) == 0x1E, "struct palette_pens_1_15 has the size of the program ROM's records");
_Static_assert(sizeof(struct palette_repeat_source) == 0x4, "struct palette_repeat_source has the size of the program ROM's records");
_Static_assert(sizeof(struct chase_step_with_limit) == 0xC, "struct chase_step_with_limit has the size of the program ROM's records");
_Static_assert(sizeof(struct biting_head_path_entry) == 0xE, "struct biting_head_path_entry has the size of the program ROM's records");
_Static_assert(sizeof(struct bridge_fire_script_entry) == 0xC, "struct bridge_fire_script_entry has the size of the program ROM's records");
_Static_assert(sizeof(struct fire_front_path_start) == 0x8, "struct fire_front_path_start has the size of the program ROM's records");
_Static_assert(sizeof(struct biting_head_path_start) == 0x4, "struct biting_head_path_start has the size of the program ROM's records");
_Static_assert(sizeof(struct rising_saw_path_start) == 0x6, "struct rising_saw_path_start has the size of the program ROM's records");
_Static_assert(sizeof(struct brick_wall_brick) == 0xC, "struct brick_wall_brick has the size of the program ROM's records");
_Static_assert(sizeof(struct brick_look) == 0x2, "struct brick_look has the size of the program ROM's records");
_Static_assert(sizeof(struct brick_dust_puff) == 0x8, "struct brick_dust_puff has the size of the program ROM's records");
_Static_assert(sizeof(struct biting_head_bite_step) == 0x4, "struct biting_head_bite_step has the size of the program ROM's records");
_Static_assert(sizeof(struct grate_step_debris_list) == 0x2, "struct grate_step_debris_list has the size of the program ROM's records");
_Static_assert(sizeof(struct burning_boulder_record) == 0x8, "struct burning_boulder_record has the size of the program ROM's records");
_Static_assert(sizeof(struct burning_boulder_flame_offset) == 0x6, "struct burning_boulder_flame_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct falling_ember_speed) == 0x4, "struct falling_ember_speed has the size of the program ROM's records");
_Static_assert(sizeof(struct scene_carrier_record) == 0x14, "struct scene_carrier_record has the size of the program ROM's records");
_Static_assert(sizeof(struct lava_steam_puff_offset) == 0x4, "struct lava_steam_puff_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct group_slot_trigger_record) == 0x6, "struct group_slot_trigger_record has the size of the program ROM's records");

#define OBJECT(address) ((struct object *)ram(address))
#define PLAYER(address) ((struct player *)ram(address))
#define OBJECT_TYPE_RECORD(address) ((const struct object_type_record *)rom(address))
#define TYPE_SPAWN_RECORD(address) ((const struct type_spawn_record *)rom(address))
#define HANDLER_SPAWN_RECORD(address) ((const struct handler_spawn_record *)rom(address))
#define OBJECT_START_LIST(address) ((const struct object_start_list *)rom(address))
#define OBJECT_START_HANDLERS(address) ((const u32le *)rom(address))
#define MACHINE_FIREBALL_SPAWNS(address) ((const struct machine_fireball_spawns *)rom(address))
#define MACHINE_FIREBALL_SPAWN(address) ((const struct machine_fireball_spawn *)rom(address))
#define ROM_CHIP_CHECKSUMS(address) ((const u16le *)rom(address))
#define RING_ROW(address) ((const struct ring_row *)rom(address))
#define GROUP_SPAWN_RECORD(address) ((const struct group_spawn_record *)rom(address))
#define SPRITE_CONTROL_SETTINGS(address) ((const uint8_t *)rom(address))
#define SPRITE_BUFFER_SWAP(address) ((const struct sprite_buffer_swap *)rom(address))
#define SINE_AND_COSINE(address) ((const struct sine_and_cosine *)rom(address))
#define FLOOR_ATTRIBUTE_RECORD(address) ((const struct floor_attribute_record *)rom(address))
#define FLOOR_BLOCK_TYPE(address) ((const struct floor_block_type *)rom(address))
#define FLOOR_OUTLINE_LIST(address) ((const struct floor_outline_list *)rom(address))
#define FLOOR_OUTLINE(address) ((const struct floor_outline *)rom(address))
#define FLOOR_OUTLINE_CORNER(address) ((const struct floor_outline_corner *)rom(address))
#define STAGE_EVENT(address) ((const struct stage_event *)rom(address))
#define STAGE_LINK_POINT(address) ((const struct stage_link_point *)rom(address))
#define LAYER_BLEND_LIST(address) ((const struct layer_blend_list *)rom(address))
#define LAYER_BLEND_RECORD(address) ((const struct layer_blend_record *)rom(address))
#define RESTART_POINT_RECORD(address) ((const struct restart_point_record *)rom(address))
#define STAGE_PALETTE(address) ((const struct stage_palette *)rom(address))
#define STAGE_NAME_BANNER(address) ((const struct stage_name_banner *)rom(address))
#define SECTION_SCROLL_SPEEDS(address) ((const uint8_t *)rom(address))
#define SECTION_FOLLOW_SPEEDS(address) ((const uint8_t *)rom(address))
#define SECTION_CAMERA_LIMITS(address) ((const s16le *)rom(address))
#define SECTION_DIRECTIONS(address) ((const s16le *)rom(address))
#define SECTION_END_POSITIONS(address) ((const u16le *)rom(address))
#define SCROLL_MODE_STEP(address) ((const struct scroll_mode_step *)rom(address))
#define FAST_SCROLL_STARTS(address) ((const u16le *)rom(address))
#define SCROLL_QUADRANT_SINES(address) ((const s16le *)rom(address))
#define STAGE_START_TILE_SETS(address) ((const u32le *)rom(address))
#define BLOCK_TILE_SETS(address) ((const uint8_t *)rom(address))
#define TILE_SET_VRAM_SCRIPTS(address) ((const u32le *)rom(address))
#define STAGE_SECTION_LIST_OFFSETS(address) ((const u16le *)rom(address))
#define SECTION_VALUES(address) ((const u16le *)rom(address))
#define NBG_LAYER_PRIORITIES(address) ((const uint8_t *)rom(address))
#define NBG3_BLOCK_PAGES(address) ((const uint8_t *)rom(address))
#define NBG3_QUADRANTS(address) ((const uint8_t *)rom(address))
#define BRIDGE_SAG_DEPTHS(address) ((const uint8_t *)rom(address))
#define TILE_BANK_SELECTS(address) ((const uint8_t *)rom(address))
#define EVENT_0F_MESSAGE(address) ((const struct event_0f_message *)rom(address))
#define MESSAGE_BOX_KIND(address) ((const struct message_box_kind *)rom(address))
#define STAGE_06_LIGHTNING_STRIKE(address) ((const struct stage_06_lightning_strike *)rom(address))
#define EVENT_1A_SCROLL_STEP(address) ((const struct event_1a_scroll_step *)rom(address))
#define STAGE_03_FLOOR_BLOCK_KIND(address) ((const struct stage_03_floor_block_kind *)rom(address))
#define STAGE_03_FLOOR_BLOCK_SHAPE(address) ((const struct stage_03_floor_block_shape *)rom(address))
#define STAGE_03_FLOOR_BLOCK_ANIMATION(address) ((const struct stage_03_floor_block_animation *)rom(address))
#define SPIKED_ROLLER_START_FRAMES(address) ((const uint8_t *)rom(address))
#define ROCK_DEBRIS_PIECE(address) ((const struct rock_debris_piece *)rom(address))
#define SPIKED_ROLLER_KIND(address) ((const struct spiked_roller_kind *)rom(address))
#define SPIKED_ROLLER_CHASE_STEP(address) ((const struct spiked_roller_chase_step *)rom(address))
#define SPIKED_ROLLER_LAYOUT(address) ((const struct spiked_roller_layout *)rom(address))
#define SPIKED_ROLLER_PART(address) ((const struct spiked_roller_part *)rom(address))
#define SPIKED_ROLLER_EVENT(address) ((const struct spiked_roller_event *)rom(address))
#define DOOR_ROLLER_SPAWN(address) ((const struct door_roller_spawn *)rom(address))
#define DOOR_FRAGMENT(address) ((const struct door_fragment *)rom(address))
#define FIREBALL_EMITTER_LIST(address) ((const struct fireball_emitter_list *)rom(address))
#define FIREBALL_TYPE(address) ((const struct fireball_type *)rom(address))
#define MACHINE_FIRE_SCRIPT_STEP(address) ((const struct machine_fire_script_step *)rom(address))
#define CAGE_BAR_ANIMATION(address) ((const struct cage_bar_animation *)rom(address))
#define FIRE_VENT_SPAWN(address) ((const struct fire_vent_spawn *)rom(address))
#define ICICLE_DROPPER_RECORD(address) ((const struct icicle_dropper_record *)rom(address))
#define ICICLE_DROPPER_STEP(address) ((const struct icicle_dropper_step *)rom(address))
#define SINK_SWIRL_EFFECT(address) ((const struct sink_swirl_effect *)rom(address))
#define OBJECT_START_PLACE(address) ((const struct object_start_place *)rom(address))
#define RIVER_RAFT_ENTRY(address) ((const struct river_raft_entry *)rom(address))
#define GEYSER_FRONT_RECORD(address) ((const struct geyser_front_record *)rom(address))
#define CHASE_STEP_AT_SCROLL(address) ((const struct chase_step_at_scroll *)rom(address))
#define GEYSER_ROW_DELAY_CHOICE(address) ((const uint8_t *)rom(address))
#define LISTED_GEYSER(address) ((const struct listed_geyser *)rom(address))
#define STONE_BLOCK_POSITION(address) ((const struct stone_block_position *)rom(address))
#define GEYSER_LINE_START(address) ((const struct geyser_line_start *)rom(address))
#define GEYSER_LINE_STEP(address) ((const struct geyser_line_step *)rom(address))
#define PROPELLER_MACHINE_ANIMATION_STEP(address) ((const struct propeller_machine_animation_step *)rom(address))
#define ROPE_BRIDGE_ROPE_OFFSET(address) ((const struct rope_bridge_rope_offset *)rom(address))
#define SPIKE_PANEL_SCREEN_OFFSET(address) ((const struct spike_panel_screen_offset *)rom(address))
#define SPIKE_PANEL_PART_OFFSET(address) ((const struct spike_panel_part_offset *)rom(address))
#define FLAME_MACHINE_OFFSET(address) ((const struct flame_machine_offset *)rom(address))
#define FLAME_MACHINE_ARM_SWAY(address) ((const struct flame_machine_arm_sway *)rom(address))
#define SPIKED_DISC_HOLD_OFFSET(address) ((const struct spiked_disc_hold_offset *)rom(address))
#define HITBOX_SIZE_PAIR(address) ((const struct hitbox_size_pair *)rom(address))
#define HITBOX_OFFSET_PAIR(address) ((const struct hitbox_offset_pair *)rom(address))
#define CRAWLER_WALK_ROW(address) ((const struct crawler_walk_row *)rom(address))
#define HITBOX_SIZE_AND_OFFSET(address) ((const struct hitbox_size_and_offset *)rom(address))
#define CRAWLER_PIECE_OFFSET(address) ((const struct crawler_piece_offset *)rom(address))
#define FENCE_OFFSET(address) ((const struct fence_offset *)rom(address))
#define FENCE_POST_BOX(address) ((const struct fence_post_box *)rom(address))
#define FENCE_POST_BOX_OFFSET(address) ((const struct fence_post_box_offset *)rom(address))
#define RANKING_PORTRAIT_FRAME_LIST(address) ((const u16le *)rom(address))
#define CHARACTER_BIT_NUMBERS(address) ((const uint8_t *)rom(address))
#define SPRITE_PALETTE_CYCLE(address) ((const struct sprite_palette_cycle *)rom(address))
#define SPRITE_CYCLE_PALETTES(address) ((const u16le *)rom(address))
#define DEMO_TRACKBALL_DELTAS(address) ((const int8_t *)rom(address))
#define HUD_STEP_LIST(address) ((const struct hud_step_list *)rom(address))
#define EGGMAN_SPEECH_STEP(address) ((const struct eggman_speech_step *)rom(address))
#define EGGMAN_SPEECH_ARGUMENTS(address) ((const u16le *)rom(address))
#define HOW_TO_PLAY_BUTTON_PRESS(address) ((const struct how_to_play_button_press *)rom(address))
#define MAP_EGGMAN_GESTURES(address) ((const int8_t *)rom(address))
#define COIN_SETTING_VALUE(address) ((const struct coin_setting_value *)rom(address))
#define ENDING_TOWER_FRAME(address) ((const struct ending_tower_frame *)rom(address))
#define ENDING_EXPLOSION_FRAME(address) ((const struct ending_explosion_frame *)rom(address))
#define ENDING_MUSIC_CUE(address) ((const struct ending_music_cue *)rom(address))
#define ENDING_TIMED_FRAME(address) ((const struct ending_timed_frame *)rom(address))
#define ENDING_TIMED_PALETTE(address) ((const struct ending_timed_palette *)rom(address))
#define SCENERY_KIND_RECORD(address) ((const struct scenery_kind_record *)rom(address))
#define GROUP_LEADER_HOLD_RECORD(address) ((const struct group_leader_hold_record *)rom(address))
#define TORNADO_START_RECORD(address) ((const struct tornado_start_record *)rom(address))
#define TORNADO_PATH_STEP(address) ((const struct tornado_path_step *)rom(address))
#define DEFAULT_RANKING_RECORD(address) ((const struct default_ranking_record *)rom(address))
#define WALL_KIND_OFFSETS(address) ((const struct wall_kind_offsets *)rom(address))
#define WALL_KIND_PARTS(address) ((const struct wall_kind_parts *)rom(address))
#define TITLE_SONIC_LOOP_CODES(address) ((const uint8_t *)rom(address))
#define TIMED_SPAWN(address) ((const struct timed_spawn *)rom(address))
#define TITLE_SMOKE_PUFF_SPRITES(address) ((const u16le *)rom(address))
#define INPUT_TEST_BIT_NUMBERS(address) ((const uint8_t *)rom(address))
#define CRT_TEST_COLOR_BAR_ROW(address) ((const struct crt_test_color_bar_row *)rom(address))
#define SOUND_COMMAND_BYTES(address) ((const struct sound_command_bytes *)rom(address))
#define RAM_TEST_PATTERN_BYTES(address) ((const uint8_t *)rom(address))
#define RAM_TEST_PATTERN_WORDS(address) ((const u16le *)rom(address))
#define CHOOSER_VOICE_ROW(address) ((const struct chooser_voice_row *)rom(address))
#define MAP_ICON_POSITION(address) ((const struct map_icon_position *)rom(address))
#define MEMORY_TEST_RESULT_OFFSETS(address) ((const u16le *)rom(address))
#define CRT_TEST_LINE(address) ((const struct crt_test_line *)rom(address))
#define SCREEN_SIGN_KIND(address) ((const struct screen_sign_kind *)rom(address))
#define RAM_TARGET_DAMAGE_STEP(address) ((const struct ram_target_damage_step *)rom(address))
#define FALLING_ROCK(address) ((const struct falling_rock *)rom(address))
#define LINE_DIRECTION_STEP(address) ((const struct line_direction_step *)rom(address))
#define FLOOD_FILL_RECORD(address) ((struct flood_fill_record *)ram(address))
#define FLOOR_BLOCK(address) ((const struct floor_block *)rom(address))
#define BRIDGE_LOAD(address) ((struct bridge_load *)ram(address))
#define STAGE_OBJECT_RECORD(address) ((const struct stage_object_record *)rom(address))
#define STAGE_OBJECT_RECORD_2(address) ((const struct stage_object_record_2 *)rom(address))
#define STAGE_OBJECT_TEMPLATE(address) ((const struct stage_object_template *)rom(address))
#define SPRITE_PART_LIST(address) ((struct sprite_part_list *)ram(address))
#define SPRITE_PART(address) ((struct sprite_part *)ram(address))
#define FRAME_ANIMATION(address) ((const struct frame_animation *)rom(address))
#define SPRITE_FRAME_NUMBERS(address) ((const u16le *)rom(address))
#define PART_LIST_OFFSETS(address) ((const u16le *)rom(address))
#define ANIMATION_STEP(address) ((const struct animation_step *)rom(address))
#define SIGN_KIND(address) ((const struct sign_kind *)rom(address))
#define BACK_ZONE_RECORD(address) ((const struct back_zone_record *)rom(address))
#define METAL_WALL_PART_OFFSET(address) ((const struct metal_wall_part_offset *)rom(address))
#define METAL_WALL_PART_SPRITES(address) ((const u16le *)rom(address))
#define WALL_SPAWN(address) ((const struct wall_spawn *)rom(address))
#define OBJECT_PAIR_TEMPLATE(address) ((const struct object_pair_template *)rom(address))
#define FIREBALL_SHOT(address) ((const struct fireball_shot *)rom(address))
#define TORNADO_HAZARD(address) ((const struct tornado_hazard *)rom(address))
#define SINKHOLE_GROWTH(address) ((const struct sinkhole_growth *)rom(address))
#define CENTIPEDE_PATH_POINT(address) ((struct centipede_path_point *)ram(address))
#define CLIP_ENTRY(address) ((struct clip_entry *)ram(address))
#define GRATE_DEBRIS_PIECE(address) ((const struct grate_debris_piece *)rom(address))
#define OPENING_SCENE_POSITION(address) ((const struct opening_scene_position *)rom(address))
#define LEADER_SPAWN(address) ((const struct leader_spawn *)rom(address))
#define ICE_LEADER_SPAWN(address) ((const struct ice_leader_spawn *)rom(address))
#define CREDIT_BLOCK(address) ((struct credit_block *)ram(address))
#define TRACKBALL_MOTION(address) ((struct trackball_motion *)ram(address))
#define FLAGGED_STEP(address) ((const struct flagged_step *)rom(address))
#define PLAYER_PALETTE_LIST(address) ((const struct player_palette_list *)rom(address))
#define EDGE_VOICE_SCROLL_RANGE(address) ((const struct edge_voice_scroll_range *)rom(address))
#define SCREEN_EDGE_PUSH(address) ((const struct screen_edge_push *)rom(address))
#define SLOPE_SPEED_PAIR(address) ((const struct slope_speed_pair *)rom(address))
#define PLAYER_FACING_ANIMATION_OFFSETS(address) ((const u16le *)rom(address))
#define FLOOR_TYPE_PLAYER_STATE(address) ((const struct floor_type_player_state *)rom(address))
#define TEETER_RECORD(address) ((const struct teeter_record *)rom(address))
#define TEETER_ANIMATION_OFFSETS(address) ((const struct teeter_animation_offsets *)rom(address))
#define SHOCKED_PALETTE_ROW(address) ((const struct shocked_palette_row *)rom(address))
#define EDGE_HANG_ANIMATIONS(address) ((const struct edge_hang_animations *)rom(address))
#define PLAYER_BOUNCE_RECORD(address) ((const struct player_bounce_record *)rom(address))
#define KNOCKED_OUT_ENTRY(address) ((const struct knocked_out_entry *)rom(address))
#define STRUGGLE_ANIMATION_POINTERS(address) ((const u32le *)rom(address))
#define RESTART_POINT(address) ((const struct restart_point *)rom(address))
#define STAGE_START_POINT(address) ((const struct stage_start_point *)rom(address))
#define STAGE_GOAL(address) ((const struct stage_goal *)rom(address))
#define STAGE_GOAL_LINE_RANGE(address) ((const struct stage_goal_line_range *)rom(address))
#define FALL_SPRITE_PRIORITY_SIDES(address) ((const int8_t *)rom(address))
#define PLAYER_PATH_STEP(address) ((const struct player_path_step *)rom(address))
#define HUD_PORTRAIT_SPRITE(address) ((const struct hud_portrait_sprite *)rom(address))
#define HUD_PALETTE_CYCLE(address) ((const struct hud_palette_cycle *)rom(address))
#define HUD_CYCLE_PALETTES(address) ((const u16le *)rom(address))
#define FLOOR_SLOPE(address) ((const struct floor_slope *)rom(address))
#define SAND_BLOCK_PART_LIST(address) ((const struct sand_block_part_list *)rom(address))
#define FLAGGED_ANIMATION_START(address) ((const struct flagged_animation_start *)rom(address))
#define ENDING_SPRITE_FRAMES(address) ((const u16le *)rom(address))
#define DEBRIS_PATH_STEP(address) ((const struct debris_path_step *)rom(address))
#define DUST_CLOUD_FRAME(address) ((const struct dust_cloud_frame *)rom(address))
#define CREDIT_PART(address) ((const struct credit_part *)rom(address))
#define SCREEN_POINT(address) ((const struct screen_point *)rom(address))
#define MAP_MARKER_LAYOUT(address) ((const struct map_marker_layout *)rom(address))
#define MAP_MARKER_BLINK(address) ((const struct map_marker_blink *)rom(address))
#define WIPE_WINDOW(address) ((const struct wipe_window *)rom(address))
#define RANKING_RECORD(address) ((struct ranking_record *)ram(address))
#define RANKING_ROW_NUMBER(address) ((const struct ranking_row_number *)rom(address))
#define RING_TALLY_PORTRAIT(address) ((const struct ring_tally_portrait *)rom(address))
#define RING_TALLY_RESULT_FACES(address) ((const struct ring_tally_result_faces *)rom(address))
#define TITLE_WAVE_SINES(address) ((const u16le *)rom(address))
#define GEYSER_RISE_STEP(address) ((const struct geyser_rise_step *)rom(address))
#define PALETTE_SET_CYCLE(address) ((struct palette_set_cycle *)ram(address))
#define PALETTE_CYCLE(address) ((struct palette_cycle *)ram(address))
#define COIN_COUNTER(address) ((struct coin_counter *)ram(address))
#define START_PROMPT_TEXT_OFFSETS(address) ((const u16le *)rom(address))
#define FRACTION_FONT_ROW_LONGS(address) ((const u32le *)rom(address))
#define TEXT_CELL_POSITION(address) ((const struct text_cell_position *)rom(address))
#define POLYGON_SPAN(address) ((struct polygon_span *)ram(address))
#define QUAD_VERTEX(address) ((struct quad_vertex *)ram(address))
#define PICTURE_COLOUR_SLOT(address) ((struct picture_colour_slot *)ram(address))
#define SAVED_BITMAP_RECT(address) ((struct saved_bitmap_rect *)ram(address))
#define BOOT_REGISTER_VALUES(address) ((const uint8_t *)rom(address))
#define DEMO_HEADER(address) ((const struct demo_header *)rom(address))
#define ROM_CHECK_BYTES(address) ((const uint8_t *)rom(address))
#define INPUT_TEST_TEXTS(address) ((const u32le *)rom(address))
#define INPUT_TEST_CURSOR_LIMITS(address) ((const s16le *)rom(address))
#define TEST_CURSOR_CHARACTERS(address) ((const uint8_t *)rom(address))
#define VBLANK_COPY(address) ((struct vblank_copy *)ram(address))
#define SPRITE_FRAME_RECORD(address) ((const struct sprite_frame_record *)rom(address))
#define STRING_RECORD(address) ((const struct string_record *)rom(address))
#define SPRITE_STRING_CHARS(address) ((const uint8_t *)rom(address))
#define QUEUED_STRING(address) ((struct queued_string *)ram(address))
#define PLACED_TEXT(address) ((const struct placed_text *)rom(address))
#define TEXT_LAYER_STRING(address) ((const uint8_t *)rom(address))
#define FORMATTED_TEXT(address) ((const uint8_t *)rom(address))
#define TILEMAP_SKIP(address) ((const struct tilemap_skip *)rom(address))
#define TILEMAP_LONG_SKIP(address) ((const struct tilemap_long_skip *)rom(address))
#define FONT_ROWS_1BPP(address) ((const uint8_t *)rom(address))
#define FONT_ROWS_2BPP(address) ((const u16le *)rom(address))
#define VRAM_SCRIPT(address) ((const uint8_t *)rom(address))
#define VRAM_SCRIPT_ADDRESS(address) ((const struct vram_script_address *)rom(address))
#define VRAM_SCRIPT_CELL_RUN(address) ((const struct vram_script_cell_run *)rom(address))
#define VRAM_SCRIPT_BYTE_CELLS(address) ((const struct vram_script_byte_cells *)rom(address))
#define VRAM_SCRIPT_LOW_BYTES(address) ((const uint8_t *)rom(address))
#define VRAM_SCRIPT_WORD_CELLS(address) ((const struct vram_script_word_cells *)rom(address))
#define VRAM_SCRIPT_CELLS(address) ((const u16le *)rom(address))
#define VRAM_SCRIPT_PAGE_CLEAR(address) ((const struct vram_script_page_clear *)rom(address))
#define VIDEO_REGISTER_DEFAULTS_TAIL(address) ((const struct video_register_defaults_tail *)rom(address))
#define PALETTE_LOAD_LIST(address) ((const struct palette_load_list *)rom(address))
#define PALETTE_LIST_ENTRY(address) ((const struct palette_list_entry *)rom(address))
#define PALETTE_PENS_1_15(address) ((const struct palette_pens_1_15 *)rom(address))
#define PALETTE_REPEAT_SOURCE(address) ((const struct palette_repeat_source *)rom(address))
#define PALETTE_REPEAT_COUNTS(address) ((const u16le *)rom(address))
#define CHASE_STEP_WITH_LIMIT(address) ((const struct chase_step_with_limit *)rom(address))
#define BITING_HEAD_PATH_ENTRY(address) ((const struct biting_head_path_entry *)rom(address))
#define BRIDGE_FIRE_SCRIPT_ENTRY(address) ((const struct bridge_fire_script_entry *)rom(address))
#define FIRE_FRONT_PATH_START(address) ((const struct fire_front_path_start *)rom(address))
#define BITING_HEAD_PATH_START(address) ((const struct biting_head_path_start *)rom(address))
#define RISING_SAW_PATH_START(address) ((const struct rising_saw_path_start *)rom(address))
#define BRICK_WALL_BRICK(address) ((const struct brick_wall_brick *)rom(address))
#define BRICK_LOOK(address) ((const struct brick_look *)rom(address))
#define BRICK_DUST_PUFF(address) ((const struct brick_dust_puff *)rom(address))
#define BITING_HEAD_BITE_STEP(address) ((const struct biting_head_bite_step *)rom(address))
#define GRATE_STEP_DEBRIS_LIST(address) ((const struct grate_step_debris_list *)rom(address))
#define BURNING_BOULDER_RECORD(address) ((const struct burning_boulder_record *)rom(address))
#define BURNING_BOULDER_FLAME_OFFSET(address) ((const struct burning_boulder_flame_offset *)rom(address))
#define FALLING_EMBER_SPEED(address) ((const struct falling_ember_speed *)rom(address))
#define SCENE_CARRIER_RECORD(address) ((const struct scene_carrier_record *)rom(address))
#define LAVA_STEAM_PUFF_OFFSET(address) ((const struct lava_steam_puff_offset *)rom(address))
#define GROUP_SLOT_TRIGGER_RECORD(address) ((const struct group_slot_trigger_record *)rom(address))

/* the program ROM's tables of records, by name: name[i].field */
#define spike_panel_head_offsets_ADDRESS 0x00F486u
#define spike_panel_head_offsets ((const struct spike_panel_screen_offset *)rom(spike_panel_head_offsets_ADDRESS))
#define spike_panel_part_1_offsets_ADDRESS 0x00F4DAu
#define spike_panel_part_1_offsets ((const struct spike_panel_part_offset *)rom(spike_panel_part_1_offsets_ADDRESS))
#define spike_panel_part_2_offsets_ADDRESS 0x00F516u
#define spike_panel_part_2_offsets ((const struct spike_panel_screen_offset *)rom(spike_panel_part_2_offsets_ADDRESS))
#define flame_machine_back_wall_offsets_ADDRESS 0x0101A0u
#define flame_machine_back_wall_offsets ((const struct flame_machine_offset *)rom(flame_machine_back_wall_offsets_ADDRESS))
#define flame_machine_arm_sway_offsets_ADDRESS 0x01039Eu
#define flame_machine_arm_sway_offsets ((const struct flame_machine_arm_sway *)rom(flame_machine_arm_sway_offsets_ADDRESS))
#define flame_machine_flame_offsets_ADDRESS 0x010575u
#define flame_machine_flame_offsets ((const struct flame_machine_offset *)rom(flame_machine_flame_offsets_ADDRESS))
#define spiked_disc_hold_offsets_ADDRESS 0x0107B7u
#define spiked_disc_hold_offsets ((const struct spiked_disc_hold_offset *)rom(spiked_disc_hold_offsets_ADDRESS))
#define ice_launcher_hitbox_sizes_ADDRESS 0x011E57u
#define ice_launcher_hitbox_sizes ((const struct hitbox_size_pair *)rom(ice_launcher_hitbox_sizes_ADDRESS))
#define ice_launcher_hitbox_offsets_ADDRESS 0x011E8Fu
#define ice_launcher_hitbox_offsets ((const struct hitbox_offset_pair *)rom(ice_launcher_hitbox_offsets_ADDRESS))
#define crawler_walk_steps_ADDRESS 0x012AD8u
#define crawler_walk_steps ((const struct crawler_walk_row *)rom(crawler_walk_steps_ADDRESS))
#define crawler_collision_boxes_ADDRESS 0x012AF4u
#define crawler_collision_boxes ((const struct hitbox_size_and_offset *)rom(crawler_collision_boxes_ADDRESS))
#define crawler_segment_offsets_ADDRESS 0x012B00u
#define crawler_segment_offsets ((const struct crawler_piece_offset *)rom(crawler_segment_offsets_ADDRESS))
#define crawler_tail_offsets_ADDRESS 0x012B14u
#define crawler_tail_offsets ((const struct crawler_piece_offset *)rom(crawler_tail_offsets_ADDRESS))
#define crawler_head_offsets_ADDRESS 0x012B1Cu
#define crawler_head_offsets ((const struct crawler_piece_offset *)rom(crawler_head_offsets_ADDRESS))
#define wall_piece_boxes_ADDRESS 0x012D08u
#define wall_piece_boxes ((const struct hitbox_size_and_offset *)rom(wall_piece_boxes_ADDRESS))
#define shaking_block_boxes_ADDRESS 0x012E48u
#define shaking_block_boxes ((const struct hitbox_size_and_offset *)rom(shaking_block_boxes_ADDRESS))
#define fence_post_offsets_ADDRESS 0x013A65u
#define fence_post_offsets ((const struct fence_offset *)rom(fence_post_offsets_ADDRESS))
#define fence_post_boxes_ADDRESS 0x013A75u
#define fence_post_boxes ((const struct fence_post_box *)rom(fence_post_boxes_ADDRESS))
#define fence_post_box_offsets_ADDRESS 0x013A85u
#define fence_post_box_offsets ((const struct fence_post_box_offset *)rom(fence_post_box_offsets_ADDRESS))
#define fence_arc_offsets_ADDRESS 0x013A95u
#define fence_arc_offsets ((const struct fence_offset *)rom(fence_arc_offsets_ADDRESS))
#define stage_03_floor_block_kinds_ADDRESS 0x082284u
#define stage_03_floor_block_kinds ((const struct stage_03_floor_block_kind *)rom(stage_03_floor_block_kinds_ADDRESS))
#define roller_wall_fragments_ADDRESS 0x08234Eu
#define roller_wall_fragments ((const struct rock_debris_piece *)rom(roller_wall_fragments_ADDRESS))
#define door_roller_layout_ADDRESS 0x0833EFu
#define door_roller_layout ((const struct door_roller_spawn *)rom(door_roller_layout_ADDRESS))
#define screen_sign_kinds_ADDRESS 0x084FA9u
#define screen_sign_kinds ((const struct screen_sign_kind *)rom(screen_sign_kinds_ADDRESS))
#define ram_target_debris_ADDRESS 0x085ED5u
#define ram_target_debris ((const struct rock_debris_piece *)rom(ram_target_debris_ADDRESS))
#define sink_swirl_effects_ADDRESS 0x08A80Eu
#define sink_swirl_effects ((const struct sink_swirl_effect *)rom(sink_swirl_effects_ADDRESS))
#define stone_block_positions_ADDRESS 0x08DAF0u
#define stone_block_positions ((const struct stone_block_position *)rom(stone_block_positions_ADDRESS))
#define geyser_line_starts_ADDRESS 0x08DB10u
#define geyser_line_starts ((const struct geyser_line_start *)rom(geyser_line_starts_ADDRESS))
#define scene_anchor_positions_ADDRESS 0x08DC1Cu
#define scene_anchor_positions ((const struct object_start_place *)rom(scene_anchor_positions_ADDRESS))
#define character_taken_bits_ADDRESS 0x090354u
#define character_taken_bits ((const uint8_t *)rom(character_taken_bits_ADDRESS))
#define chooser_voice_sounds_ADDRESS 0x09036Fu
#define chooser_voice_sounds ((const struct chooser_voice_row *)rom(chooser_voice_sounds_ADDRESS))
#define sprite_buffer_swaps_ADDRESS 0x09A6CCu
#define sprite_buffer_swaps ((const struct sprite_buffer_swap *)rom(sprite_buffer_swaps_ADDRESS))
#define line_direction_steps_ADDRESS 0x09C4D2u
#define line_direction_steps ((const struct line_direction_step *)rom(line_direction_steps_ADDRESS))
#define stage_palettes_ADDRESS 0x108CD0u
#define stage_palettes ((const struct stage_palette *)rom(stage_palettes_ADDRESS))
#define floor_slopes_ADDRESS 0x10DF44u
#define floor_slopes ((const struct floor_slope *)rom(floor_slopes_ADDRESS))
#define floor_types_ADDRESS 0x10E14Cu
#define floor_types ((const struct floor_block_type *)rom(floor_types_ADDRESS))
#define teetering_animations_ADDRESS 0x1128AEu
#define teetering_animations ((const struct teeter_animation_offsets *)rom(teetering_animations_ADDRESS))
#define floor_type_player_states_ADDRESS 0x113CD9u
#define floor_type_player_states ((const struct floor_type_player_state *)rom(floor_type_player_states_ADDRESS))
#define screen_edge_push_directions_ADDRESS 0x113EE0u
#define screen_edge_push_directions ((const struct screen_edge_push *)rom(screen_edge_push_directions_ADDRESS))
#define hud_gauge_positions_3p_ADDRESS 0x113F10u
#define hud_gauge_positions_3p ((const struct screen_point *)rom(hud_gauge_positions_3p_ADDRESS))
#define hud_gauge_positions_2p_ADDRESS 0x113F1Cu
#define hud_gauge_positions_2p ((const struct screen_point *)rom(hud_gauge_positions_2p_ADDRESS))
#define hud_portrait_positions_3p_ADDRESS 0x113F24u
#define hud_portrait_positions_3p ((const struct screen_point *)rom(hud_portrait_positions_3p_ADDRESS))
#define hud_portrait_positions_2p_ADDRESS 0x113F30u
#define hud_portrait_positions_2p ((const struct screen_point *)rom(hud_portrait_positions_2p_ADDRESS))
#define hud_portrait_sprites_ADDRESS 0x113F38u
#define hud_portrait_sprites ((const struct hud_portrait_sprite *)rom(hud_portrait_sprites_ADDRESS))
#define shocked_palettes_ADDRESS 0x113F4Fu
#define shocked_palettes ((const struct shocked_palette_row *)rom(shocked_palettes_ADDRESS))
#define shrink_away_positions_ADDRESS 0x113FABu
#define shrink_away_positions ((const struct screen_point *)rom(shrink_away_positions_ADDRESS))
#define edge_voice_scroll_ranges_ADDRESS 0x114B38u
#define edge_voice_scroll_ranges ((const struct edge_voice_scroll_range *)rom(edge_voice_scroll_ranges_ADDRESS))
#define coin_setting_values_ADDRESS 0x116EC5u
#define coin_setting_values ((const struct coin_setting_value *)rom(coin_setting_values_ADDRESS))

#endif
