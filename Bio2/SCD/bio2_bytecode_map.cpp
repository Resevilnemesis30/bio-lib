/*
*
*	Megan Grass
*	January 01, 2024
*
*
*	TODO:
*
*		reflexpr couldn't come soon enough.
*
*/


#pragma once

#include "bio2_bytecode_map.h"

std::unordered_map<std::size_t, std::string> iNop = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iEvt_end = {
	{ 0, "Opcode" },
	{ 1, "Nop" }
};
std::unordered_map<std::size_t, std::string> iEvt_next = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iEvt_chain = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Gosub" },
	{ 3, "Evt_no" }
};
std::unordered_map<std::size_t, std::string> iEvt_exec = {
	{ 0, "Opcode" },
	{ 1, "Task_level" },
	{ 2, "Gosub" },
	{ 3, "Evt_no" }
};
std::unordered_map<std::size_t, std::string> iEvt_kill = {
	{ 0, "Opcode" },
	{ 1, "Evt_no" }
};
std::unordered_map<std::size_t, std::string> iIfel_ck = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Ofs" }
};
std::unordered_map<std::size_t, std::string> iElse_ck = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Ofs" }
};
std::unordered_map<std::size_t, std::string> iEndif = {
	{ 0, "Opcode" },
	{ 1, "Nop" }
};
std::unordered_map<std::size_t, std::string> iSleep = {
	{ 0, "Opcode" },
	{ 1, "Sleeping" },
	{ 2, "Lcnt" }
};
std::unordered_map<std::size_t, std::string> iSleeping = {
	{ 0, "Opcode" },
	{ 1, "Lcnt" }
};
std::unordered_map<std::size_t, std::string> iWsleep = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iWsleeping = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iFor = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Ofs" },
	{ 3, "Lcnt" }
};
std::unordered_map<std::size_t, std::string> iNext = {
	{ 0, "Opcode" },
	{ 1, "Nop" }
};
std::unordered_map<std::size_t, std::string> iWhile = {
	{ 0, "Opcode" },
	{ 1, "ConditionLen" },
	{ 2, "Ofs" }
};
std::unordered_map<std::size_t, std::string> iEwhile = {
	{ 0, "Opcode" },
	{ 1, "Nop" }
};
std::unordered_map<std::size_t, std::string> iDo = {
	{ 0, "Opcode" },
	{ 1, "Num" },
	{ 2, "Ofs" }
};
std::unordered_map<std::size_t, std::string> iEdwhile = {
	{ 0, "Opcode" },
	{ 1, "ConditionLen" }
};
std::unordered_map<std::size_t, std::string> iSwitch = {
	{ 0, "Opcode" },
	{ 1, "Work_no" },
	{ 2, "Ofs" }
};
std::unordered_map<std::size_t, std::string> iCase = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Ofs" },
	{ 3, "Expression" }
};
std::unordered_map<std::size_t, std::string> iDefault = {
	{ 0, "Opcode" },
	{ 1, "Nop" }
};
std::unordered_map<std::size_t, std::string> iEswitch = {
	{ 0, "Opcode" },
	{ 1, "Nop" }
};
std::unordered_map<std::size_t, std::string> iGoto = {
	{ 0, "Opcode" },
	{ 1, "Ifel_ctr" },
	{ 2, "Loop_ctr" },
	{ 3, "Nop" },
	{ 4, "Ofs" }
};
std::unordered_map<std::size_t, std::string> iGosub = {
	{ 0, "Opcode" },
	{ 1, "Evt_no" }
};
std::unordered_map<std::size_t, std::string> iReturn = {
	{ 0, "Opcode" },
	{ 1, "Nop" }
};
std::unordered_map<std::size_t, std::string> iBreak = {
	{ 0, "Opcode" },
	{ 1, "Nop" }
};
std::unordered_map<std::size_t, std::string> iFor2 = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Ofs" },
	{ 3, "Nop" },
	{ 4, "Lcnt" }
};
std::unordered_map<std::size_t, std::string> iBreak_point = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iWork_copy = {
	{ 0, "Opcode" },
	{ 1, "Work_no" },
	{ 2, "Work_dest" },
	{ 3, "DataType" }
};
std::unordered_map<std::size_t, std::string> iCk = {
	{ 0, "Opcode" },
	{ 1, "Flag" },
	{ 2, "Bit" },
	{ 3, "OnOff" }
};
std::unordered_map<std::size_t, std::string> iSet = {
	{ 0, "Opcode" },
	{ 1, "Flag" },
	{ 2, "Bit" },
	{ 3, "Operator" }
};
std::unordered_map<std::size_t, std::string> iCmp = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Flag" },
	{ 3, "Operator" },
	{ 4, "Num" }
};
std::unordered_map<std::size_t, std::string> iSave = {
	{ 0, "Opcode" },
	{ 1, "Flag" },
	{ 2, "Num" }
};
std::unordered_map<std::size_t, std::string> iCopy = {
	{ 0, "Opcode" },
	{ 1, "Flag0" },
	{ 2, "Flag1" }
};
std::unordered_map<std::size_t, std::string> iCalc = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Operator" },
	{ 3, "Flag" },
	{ 4, "Num" }
};
std::unordered_map<std::size_t, std::string> iCalc2 = {
	{ 0, "Opcode" },
	{ 1, "Operator" },
	{ 2, "Flag0" },
	{ 3, "Flag1" }
};
std::unordered_map<std::size_t, std::string> iSce_rnd = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iCut_chg = {
	{ 0, "Opcode" },
	{ 1, "Cut_no" },
};
std::unordered_map<std::size_t, std::string> iCut_old = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iMessage_on = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Mess_no" },
	{ 3, "Attr" },
	{ 4, "Stop_data" }
};
std::unordered_map<std::size_t, std::string> iAot_set = {
	{ 0, "Opcode" },
	{ 1, "Aot" },
	{ 2, "Id" },
	{ 3, "Type" },
	{ 4, "nFloor" },
	{ 5, "Super" },
	{ 6, "X" },
	{ 7, "Z" },
	{ 8, "W" },
	{ 9, "D" },
	{ 10, "Data0" },
	{ 11, "Data1" },
	{ 12, "Data2" }
};
std::unordered_map<std::size_t, std::string> iObj_model_set = {
	{ 0, "Opcode" },
	{ 1, "Om_no" },
	{ 2, "Id" },
	{ 3, "Cc_ctr" },
	{ 4, "Cc_wait" },
	{ 5, "Cc_num" },
	{ 6, "nFloor" },
	{ 7, "Super" },
	{ 8, "Type" },
	{ 9, "Be_flg" },
	{ 10, "Attribute" },
	{ 11, "Pos_x" },
	{ 12, "Pos_y" },
	{ 13, "Pos_z" },
	{ 14, "Cdir_x" },
	{ 15, "Cdir_y" },
	{ 16, "Cdir_z" },
	{ 17, "Ofs_x" },
	{ 18, "Ofs_y" },
	{ 19, "Ofs_z" },
	{ 20, "At_w" },
	{ 21, "At_h" },
	{ 22, "At_d" }
};
std::unordered_map<std::size_t, std::string> iWork_set = {
	{ 0, "Opcode" },
	{ 1, "Work_type" },
	{ 2, "Work_no" }
};
std::unordered_map<std::size_t, std::string> iSpeed_set = {
	{ 0, "Opcode" },
	{ 1, "Spd_type" },
	{ 2, "Num" }
};
std::unordered_map<std::size_t, std::string> iAdd_speed = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iAdd_aspeed = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iPos_set = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Pos_x" },
	{ 3, "Pos_y" },
	{ 4, "Pos_z" }
};
std::unordered_map<std::size_t, std::string> iDir_set = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Cdir_x" },
	{ 3, "Cdir_y" },
	{ 4, "Cdir_z"}
};
std::unordered_map<std::size_t, std::string> iMember_set = {
	{ 0, "Opcode" },
	{ 1, "Member" },
	{ 2, "Num" }
};
std::unordered_map<std::size_t, std::string> iMember_set2 = {
	{ 0, "Opcode" },
	{ 1, "Member" },
	{ 2, "Flag" }
};
std::unordered_map<std::size_t, std::string> iSe_on = {
	{ 0, "Opcode" },
	{ 1, "VAB" },
	{ 2, "EDT" },
	{ 3, "Work_type" },
	{ 4, "Pos_x" },
	{ 5, "Pos_y" },
	{ 6, "Pos_z" }
};
std::unordered_map<std::size_t, std::string> iSca_id_set = {
	{ 0, "Opcode" },
	{ 1, "Col_no" },
	{ 2, "Id" }
};
std::unordered_map<std::size_t, std::string> iFlr_set = {
	{ 0, "Opcode" },
	{ 1, "Flr_no" },
	{ 2, "OnOff" }
};
std::unordered_map<std::size_t, std::string> iDir_ck = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Vec_x" },
	{ 3, "Vec_z" },
	{ 4, "Add_dir" }
};
std::unordered_map<std::size_t, std::string> iSce_espr_on = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Esp_id" },
	{ 3, "Esp_dt" },
	{ 4, "Work_kind" },
	{ 5, "Work_no" },
	{ 6, "Espmv" },
	{ 7, "Svec_x" },
	{ 8, "Svec_y" },
	{ 9, "Svec_z" },
	{ 10, "Dir_y" }
};
std::unordered_map<std::size_t, std::string> iDoor_aot_set = {
	{ 0, "Opcode" },
	{ 1, "Aot" },
	{ 2, "Id" },
	{ 3, "Type" },
	{ 4, "nFloor" },
	{ 5, "Super" },
	{ 6, "X" },
	{ 7, "Z" },
	{ 8, "W" },
	{ 9, "D" },
	{ 10, "Next_pos_x" },
	{ 11, "Next_pos_y" },
	{ 12, "Next_pos_z" },
	{ 13, "Next_cdir_y" },
	{ 14, "Next_stage" },
	{ 15, "Next_room" },
	{ 16, "Next_cut" },
	{ 17, "Next_nfloor" },
	{ 18, "Dtex_type" },
	{ 19, "Door_type" },
	{ 20, "Knock_type" },
	{ 21, "Key_id" },
	{ 22, "Key_type" },
	{ 23, "Free" }
};
std::unordered_map<std::size_t, std::string> iCut_auto = {
	{ 0, "Opcode" },
	{ 1, "OnOff" }
};
std::unordered_map<std::size_t, std::string> iMember_copy = {
	{ 0, "Opcode" },
	{ 1, "Flag" },
	{ 2, "Member" }
};
std::unordered_map<std::size_t, std::string> iMember_cmp = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Member" },
	{ 3, "Operator" },
	{ 4, "Num" }
};
std::unordered_map<std::size_t, std::string> iPlc_motion = {
	{ 0, "Opcode" },
	{ 1, "Routine_0" },
	{ 2, "Move_no" },
	{ 3, "Sce_flg" }
};
std::unordered_map<std::size_t, std::string> iPlc_dest = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Routine_0" },
	{ 3, "Set_flg_no" },
	{ 4, "Dest_x" },
	{ 5, "Dest_z" }
};
std::unordered_map<std::size_t, std::string> iPlc_neck = {
	{ 0, "Opcode" },
	{ 1, "Neck_flg" },
	{ 2, "Neck_point_x" },
	{ 3, "Neck_point_y" },
	{ 4, "Neck_point_z" },
	{ 5, "Free" }
};
std::unordered_map<std::size_t, std::string> iPlc_ret = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iPlc_flg = {
	{ 0, "Opcode" },
	{ 1, "Operator" },
	{ 2, "Num" }
};
std::unordered_map<std::size_t, std::string> iSce_em_set = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Em_no" },
	{ 3, "Id" },
	{ 4, "Type" },
	{ 5, "nFloor" },
	{ 6, "Sound_flg" },
	{ 7, "Model_type" },
	{ 8, "Em_set_flg" },
	{ 9, "Pos_x" },
	{ 10, "Pos_y" },
	{ 11, "Pos_z" },
	{ 12, "Cdir_y" },
	{ 13, "Motion" },
	{ 14, "Ctr_flg" }
};
std::unordered_map<std::size_t, std::string> iCol_chg_set = {
	{ 0, "Opcode" },
	{ 1, "Cc_ctr" },
	{ 2, "Cc_cnt" },
	{ 3, "Cc_wait" },
	{ 4, "Cc_num" }
};
std::unordered_map<std::size_t, std::string> iAot_reset = {
	{ 0, "Opcode" },
	{ 1, "Aot" },
	{ 2, "Id" },
	{ 3, "Type" },
	{ 4, "Data0" },
	{ 5, "Data1" },
	{ 6, "Data2" }
};
std::unordered_map<std::size_t, std::string> iAot_on = {
	{ 0, "Opcode" },
	{ 1, "Aot" }
};
std::unordered_map<std::size_t, std::string> iSuper_set = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Work_type" },
	{ 3, "Work_no" },
	{ 4, "Pos_x" },
	{ 5, "Pos_y" },
	{ 6, "Pos_z" },
	{ 7, "Cdir_x" },
	{ 8, "Cdir_y" },
	{ 9, "Cdir_z" }
};
std::unordered_map<std::size_t, std::string> iSuper_reset = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Cdir_x" },
	{ 3, "Cdir_y" },
	{ 4, "Cdir_z" }
};
std::unordered_map<std::size_t, std::string> iPlc_gun = {
	{ 0, "Opcode" },
	{ 1, "Routine_0" }
};
std::unordered_map<std::size_t, std::string> iCut_replace = {
	{ 0, "Opcode" },
	{ 1, "Fcut" },
	{ 2, "Tcut" }
};
std::unordered_map<std::size_t, std::string> iSce_espr_kill = {
	{ 0, "Opcode" },
	{ 1, "Esp_id" },
	{ 2, "Esp_type" },
	{ 3, "Work_kind" },
	{ 4, "Work_no" }
};
std::unordered_map<std::size_t, std::string> iDoor_model_set = {
	{ 0, "Opcode" },
	{ 1, "Work_no" },
	{ 2, "Id" },
	{ 3, "Type" },
	{ 4, "Be_flg" },
	{ 5, "Model_no" },
	{ 6, "Attribute2" },
	{ 7, "Attribute" },
	{ 8, "Pos_x" },
	{ 9, "Pos_y" },
	{ 10, "Pos_z" },
	{ 11, "Cdir_x" },
	{ 12, "Cdir_y" },
	{ 13, "Cdir_z" }
};
std::unordered_map<std::size_t, std::string> iItem_aot_set = {
	{ 0, "Opcode" },
	{ 1, "Aot" },
	{ 2, "Id" },
	{ 3, "Type" },
	{ 4, "nFloor" },
	{ 5, "Super" },
	{ 6, "X" },
	{ 7, "Z" },
	{ 8, "W" },
	{ 9, "D" },
	{ 10, "iItem" },
	{ 11, "nItem" },
	{ 12, "Item_flg" },
	{ 13, "Om_no" },
	{ 14, "Action" }
};
std::unordered_map<std::size_t, std::string> iSce_key_ck = {
	{ 0, "Opcode" },
	{ 1, "Flag" },
	{ 2, "Key" }
};
std::unordered_map<std::size_t, std::string> iSce_trg_ck = {
	{ 0, "Opcode" },
	{ 1, "Flag" },
	{ 2, "Key_trg" }
};
std::unordered_map<std::size_t, std::string> iSce_bgm_control = {
	{ 0, "Opcode" },
	{ 1, "Work_no" },
	{ 2, "Op" },
	{ 3, "Data0" },
	{ 4, "Data1" },
	{ 5, "Data2" }
};
std::unordered_map<std::size_t, std::string> iSce_espr_control = {
	{ 0, "Opcode" },
	{ 1, "Esp_id" },
	{ 2, "Esp_type" },
	{ 3, "Esp_rtn" },
	{ 4, "Work_kind" },
	{ 5, "Work_no" }
};
std::unordered_map<std::size_t, std::string> iSce_fade_set = {
	{ 0, "Opcode" },
	{ 1, "Work_no" },
	{ 2, "Hrate" },
	{ 3, "Mask_rgb" },
	{ 3, "Add" }
};
std::unordered_map<std::size_t, std::string> iSce_espr3d_on = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Esp_id" },
	{ 3, "Esp_dt" },
	{ 4, "Work_kind" },
	{ 5, "Work_no" },
	{ 6, "Espmv" },
	{ 7, "Svec_x" },
	{ 8, "Svec_y" },
	{ 9, "Svec_z" },
	{ 10, "Dsv_x" },
	{ 11, "Dsv_y" },
	{ 12, "Dsv_z" },
	{ 13, "Dir_y" }
};
std::unordered_map<std::size_t, std::string> iMember_calc = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Operator" },
	{ 3, "Member" },
	{ 4, "Num" }
};
std::unordered_map<std::size_t, std::string> iMember_calc2 = {
	{ 0, "Opcode" },
	{ 1, "Operator" },
	{ 2, "Member" },
	{ 3, "Work_no" }
};
std::unordered_map<std::size_t, std::string> iSce_bgmtbl_set = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Stage" },
	{ 3, "Room" },
	{ 4, "Main" },
	{ 5, "Sub" },
	{ 6, "PANVT" }
};
std::unordered_map<std::size_t, std::string> iPlc_rot = {
	{ 0, "Opcode" },
	{ 1, "Free_no" },
	{ 2, "Sce_free" }
};
std::unordered_map<std::size_t, std::string> iXa_on = {
	{ 0, "Opcode" },
	{ 1, "Mode" },
	{ 2, "Num" }
};
std::unordered_map<std::size_t, std::string> iWeapon_chg = {
	{ 0, "Opcode" },
	{ 1, "Plw_no" }
};
std::unordered_map<std::size_t, std::string> iPlc_cnt = {
	{ 0, "Opcode" },
	{ 1, "Move_cnt" }
};
std::unordered_map<std::size_t, std::string> iSce_shake_on = {
	{ 0, "Opcode" },
	{ 1, "Slide_ofs" },
	{ 2, "Copy_ofs" }
};
std::unordered_map<std::size_t, std::string> iMizu_div_set = {
	{ 0, "Opcode" },
	{ 1, "Div_max" }
};
std::unordered_map<std::size_t, std::string> iKeep_Item_ck = {
	{ 0, "Opcode" },
	{ 1, "Item_no" }
};
std::unordered_map<std::size_t, std::string> iXa_vol = {
	{ 0, "Opcode" },
	{ 1, "Cd_vol" }
};
std::unordered_map<std::size_t, std::string> iKage_set = {
	{ 0, "Opcode" },
	{ 1, "Work_type" },
	{ 2, "Work_no" },
	{ 3, "R" },
	{ 4, "G" },
	{ 5, "B" },
	{ 6, "Half_x" },
	{ 7, "Half_z" },
	{ 8, "Off_x" },
	{ 9, "Off_z" }
};
std::unordered_map<std::size_t, std::string> iCut_be_set = {
	{ 0, "Opcode" },
	{ 1, "Fcut" },
	{ 2, "Vcut_num" },
	{ 3, "Be_flg" }
};
std::unordered_map<std::size_t, std::string> iSce_Item_lost = {
	{ 0, "Opcode" },
	{ 1, "Item_no" }
};
std::unordered_map<std::size_t, std::string> iPlc_gun_eff = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iSce_espr_on2 = {
	{ 0, "Opcode" },
	{ 1, "Dir_y_id0" },
	{ 2, "Esp_id" },
	{ 3, "Esp_dt" },
	{ 4, "Work_kind" },
	{ 5, "Work_no" },
	{ 6, "Espmv" },
	{ 7, "Svec_x" },
	{ 8, "Svec_y" },
	{ 9, "Svec_z" },
	{ 10, "Dir_y_id1" }
};
std::unordered_map<std::size_t, std::string> iSce_espr_kill2 = {
	{ 0, "Opcode" },
	{ 1, "Esp_id" }
};
std::unordered_map<std::size_t, std::string> iPlc_stop = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iAot_set_4p = {
	{ 0, "Opcode" },
	{ 1, "Aot" },
	{ 2, "Id" },
	{ 3, "Type" },
	{ 4, "nFloor" },
	{ 5, "Super" },
	{ 6, "X0" },
	{ 7, "Z0" },
	{ 8, "X1" },
	{ 9, "Z1" },
	{ 10, "X2" },
	{ 11, "Z2" },
	{ 12, "X3" },
	{ 13, "Z3" },
	{ 14, "Data0" },
	{ 15, "Data1" },
	{ 16, "Data2" }
};
std::unordered_map<std::size_t, std::string> iDoor_aot_set_4p = {
	{ 0, "Opcode" },
	{ 1, "Aot" },
	{ 2, "Id" },
	{ 3, "Type" },
	{ 4, "nFloor" },
	{ 5, "Super" },
	{ 6, "X0" },
	{ 7, "Z0" },
	{ 8, "X1" },
	{ 9, "Z1" },
	{ 10, "X2" },
	{ 11, "Z2" },
	{ 12, "X3" },
	{ 13, "Z3" },
	{ 14, "Next_pos_x" },
	{ 15, "Next_pos_y" },
	{ 16, "Next_pos_z" },
	{ 17, "Next_cdir_y" },
	{ 18, "Next_stage" },
	{ 19, "Next_room" },
	{ 20, "Next_cut" },
	{ 21, "Next_nfloor" },
	{ 22, "Dtex_type" },
	{ 23, "Door_type" },
	{ 24, "Knock_type" },
	{ 25, "Key_id" },
	{ 26, "Key_type" },
	{ 27, "Free" }
};
std::unordered_map<std::size_t, std::string> iItem_aot_set_4p = {
	{ 0, "Opcode" },
	{ 1, "Aot" },
	{ 2, "Id" },
	{ 3, "Type" },
	{ 4, "nFloor" },
	{ 5, "Super" },
	{ 6, "X0" },
	{ 7, "Z0" },
	{ 8, "X1" },
	{ 9, "Z1" },
	{ 10, "X2" },
	{ 11, "Z2" },
	{ 12, "X3" },
	{ 13, "Z3" },
	{ 14, "iItem" },
	{ 15, "nItem" },
	{ 16, "Item_flg" },
	{ 17, "Om_no" },
	{ 18, "Action" }
};
std::unordered_map<std::size_t, std::string> iLight_pos_set = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Pos_no" },
	{ 3, "XYZ" },
	{ 4, "Position" }
};
std::unordered_map<std::size_t, std::string> iLight_kido_set = {
	{ 0, "Opcode" },
	{ 1, "Brit_no" },
	{ 2, "Brightness" }
};
std::unordered_map<std::size_t, std::string> iRbj_reset = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iSce_scr_move = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Scrl_y" }
};
std::unordered_map<std::size_t, std::string> iParts_set = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Ptr" },
	{ 3, "Work_type" },
	{ 4, "Num" }
};
std::unordered_map<std::size_t, std::string> iMovie_on = {
	{ 0, "Opcode" },
	{ 1, "Str_num" }
};
std::unordered_map<std::size_t, std::string> iSplc_ret = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iSplc_sce = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iSuper_on = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Work_type" },
	{ 3, "Work_no" },
	{ 4, "Mat_x" },
	{ 5, "Mat_y" },
	{ 6, "Mat_z" },
	{ 7, "Rot_x" },
	{ 8, "Rot_y" },
	{ 9, "Rot_z" }
};
std::unordered_map<std::size_t, std::string> iMirror_set = {
	{ 0, "Opcode" },
	{ 1, "Flag" },
	{ 2, "Position" },
	{ 3, "Min" },
	{ 4, "Max" }
};
std::unordered_map<std::size_t, std::string> iSce_fade_adjust = {
	{ 0, "Opcode" },
	{ 1, "No" },
	{ 2, "Brightness" }
};
std::unordered_map<std::size_t, std::string> iSce_espr3d_on2 = {
	{ 0, "Opcode" },
	{ 1, "Dir_y_id0" },
	{ 2, "Bit" },
	{ 3, "Work_kind" },
	{ 4, "Work_no" },
	{ 5, "Espmv" },
	{ 6, "Svec_x" },
	{ 7, "Svec_y" },
	{ 8, "Svec_z" },
	{ 9, "Dsv_x" },
	{ 10, "Dsv_y" },
	{ 11, "Dsv_z" },
	{ 12, "Dir_y_id1" }
};
std::unordered_map<std::size_t, std::string> iSce_Item_get = {
	{ 0, "Opcode" },
	{ 1, "Item_no" },
	{ 2, "Num" }
};
std::unordered_map<std::size_t, std::string> iSce_line_start = {
	{ 0, "Opcode" },
	{ 1, "Ot_no" },
	{ 2, "Prio" }
};
std::unordered_map<std::size_t, std::string> iSce_line_main = {
	{ 0, "Opcode" },
	{ 1, "Line_no" },
	{ 2, "Slide_ofs" },
	{ 3, "Copy_ofs" }
};
std::unordered_map<std::size_t, std::string> iSce_line_end = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iSce_parts_bomb = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Ptr" },
	{ 3, "Poly_R" },
	{ 4, "Poly_G" },
	{ 5, "Poly_B" },
	{ 6, "Free0" },
	{ 7, "Free2" },
	{ 8, "Free6" },
	{ 9, "Free1" },
	{ 10, "Free3" }
};
std::unordered_map<std::size_t, std::string> iSce_parts_down = {
	{ 0, "Opcode" },
	{ 1, "Ptr" },
	{ 2, "Old_x" },
	{ 3, "Old_y" },
	{ 4, "Old_z" },
	{ 5, "Timer1" },
	{ 6, "Old_x2" },
	{ 7, "Old_y2" },
	{ 8, "Old_z2" }
};
std::unordered_map<std::size_t, std::string> iLight_color_set = {
	{ 0, "Opcode" },
	{ 1, "Col_no" },
	{ 2, "R" },
	{ 3, "G" },
	{ 4, "B" },
	{ 5, "Nop" }
};
std::unordered_map<std::size_t, std::string> iLight_pos_set2 = {
	{ 0, "Opcode" },
	{ 1, "Lit_no" },
	{ 2, "Pos_no" },
	{ 3, "XYZ" },
	{ 4, "Position" }
};
std::unordered_map<std::size_t, std::string> iLight_kido_set2 = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Lit_no" },
	{ 3, "Brit_no" },
	{ 4, "Brightness" }
};
std::unordered_map<std::size_t, std::string> iLight_color_set2 = {
	{ 0, "Opcode" },
	{ 1, "Lit_no" },
	{ 2, "Col_no" },
	{ 3, "R" },
	{ 4, "G" },
	{ 5, "B" }
};
std::unordered_map<std::size_t, std::string> iSe_vol = {
	{ 0, "Opcode" },
	{ 1, "Volume_Se" }
};
std::unordered_map<std::size_t, std::string> iSce_Item_cmp = {
	{ 0, "Opcode" },
	{ 1, "Operator" },
	{ 2, "Num" }
};
std::unordered_map<std::size_t, std::string> iSce_espr_kill_all = {
	{ 0, "Opcode" },
	{ 1, "Work_kind" },
	{ 2, "Work_no" }
};
std::unordered_map<std::size_t, std::string> iPlc_heal = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iSt_map_hint = {
	{ 0, "Opcode" },
	{ 1, "Tag" }
};
std::unordered_map<std::size_t, std::string> iSce_em_pos_ck = {
	{ 0, "Opcode" },
	{ 1, "Em_no0" },
	{ 2, "Em_no1" },
	{ 3, "Flg" },
	{ 4, "Att" }
};
std::unordered_map<std::size_t, std::string> iPoison_ck = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iPoison_clr = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iSce_Item_lost2 = {
	{ 0, "Opcode" },
	{ 1, "Item_no" },
	{ 2, "Num" }
};
std::unordered_map<std::size_t, std::string> iPlc_life_max = {
	{ 0, "Opcode" }
};
std::unordered_map<std::size_t, std::string> iVib_set0 = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "data0" },
	{ 3, "data1" }
};
std::unordered_map<std::size_t, std::string> iVib_set1 = {
	{ 0, "Opcode" },
	{ 1, "Id" },
	{ 2, "data0" },
	{ 3, "data1" }
};
std::unordered_map<std::size_t, std::string> iVib_fade_set = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "data0" },
	{ 3, "data1" },
	{ 4, "data2" },
	{ 5, "data3" }
};
std::unordered_map<std::size_t, std::string> iItem_aot_set2 = {
	{ 0, "Opcode" },
	{ 1, "Aot" },
	{ 2, "Id" },
	{ 3, "Type" },
	{ 4, "nFloor" },
	{ 5, "Super" },
	{ 6, "X" },
	{ 7, "Z" },
	{ 8, "W" },
	{ 9, "D" },
	{ 10, "iItem" },
	{ 11, "nItem" },
	{ 12, "Flag" },
	{ 13, "Om_no" },
	{ 14, "Action" },
	{ 15, "Rnd_flg" },
	{ 16, "Nop" }
};
std::unordered_map<std::size_t, std::string> iSce_em_set2 = {
	{ 0, "Opcode" },
	{ 1, "Nop" },
	{ 2, "Em_no" },
	{ 3, "Id" },
	{ 4, "Type" },
	{ 5, "nFloor" },
	{ 6, "Sound_flg" },
	{ 7, "Model_type" },
	{ 8, "Em_set_flg" },
	{ 9, "Pos_x" },
	{ 10, "Pos_y" },
	{ 11, "Pos_z" },
	{ 12, "Cdir_y" },
	{ 13, "Motion" },
	{ 14, "Ctr_flg" },
	{ 15, "Rnd_flg" },
	{ 16, "Nop" }
};

std::unordered_map<std::int8_t, std::unordered_map<std::size_t, std::string>> iBytecode = {
	{ 0x00, iNop },
	{ 0x01, iEvt_end },
	{ 0x02, iEvt_next },
	{ 0x03, iEvt_chain },
	{ 0x04, iEvt_exec },
	{ 0x05, iEvt_kill },
	{ 0x06, iIfel_ck },
	{ 0x07, iElse_ck },
	{ 0x08, iEndif },
	{ 0x09, iSleep },
	{ 0x0A, iSleeping },
	{ 0x0B, iWsleep },
	{ 0x0C, iWsleeping },
	{ 0x0D, iFor },
	{ 0x0E, iNext },
	{ 0x0F, iWhile },
	{ 0x10, iEwhile },
	{ 0x11, iDo },
	{ 0x12, iEdwhile },
	{ 0x13, iSwitch },
	{ 0x14, iCase },
	{ 0x15, iDefault },
	{ 0x16, iEswitch },
	{ 0x17, iGoto },
	{ 0x18, iGosub },
	{ 0x19, iReturn },
	{ 0x1A, iBreak },
	{ 0x1B, iFor2 },
	{ 0x1C, iBreak_point },
	{ 0x1D, iWork_copy },
	{ 0x1E, iNop },
	{ 0x1F, iNop },
	{ 0x20, iNop },
	{ 0x21, iCk },
	{ 0x22, iSet },
	{ 0x23, iCmp },
	{ 0x24, iSave },
	{ 0x25, iCopy },
	{ 0x26, iCalc },
	{ 0x27, iCalc2 },
	{ 0x28, iSce_rnd },
	{ 0x29, iCut_chg },
	{ 0x2A, iCut_old },
	{ 0x2B, iMessage_on },
	{ 0x2C, iAot_set },
	{ 0x2D, iObj_model_set },
	{ 0x2E, iWork_set },
	{ 0x2F, iSpeed_set },
	{ 0x30, iAdd_speed },
	{ 0x31, iAdd_aspeed },
	{ 0x32, iPos_set },
	{ 0x33, iDir_set },
	{ 0x34, iMember_set },
	{ 0x35, iMember_set2 },
	{ 0x36, iSe_on },
	{ 0x37, iSca_id_set },
	{ 0x38, iFlr_set },
	{ 0x39, iDir_ck },
	{ 0x3A, iSce_espr_on },
	{ 0x3B, iDoor_aot_set },
	{ 0x3C, iCut_auto },
	{ 0x3D, iMember_copy },
	{ 0x3E, iMember_cmp },
	{ 0x3F, iPlc_motion },
	{ 0x40, iPlc_dest },
	{ 0x41, iPlc_neck },
	{ 0x42, iPlc_ret },
	{ 0x43, iPlc_flg },
	{ 0x44, iSce_em_set },
	{ 0x45, iCol_chg_set },
	{ 0x46, iAot_reset },
	{ 0x47, iAot_on },
	{ 0x48, iSuper_set },
	{ 0x49, iSuper_reset },
	{ 0x4A, iPlc_gun },
	{ 0x4B, iCut_replace },
	{ 0x4C, iSce_espr_kill },
	{ 0x4D, iDoor_model_set },
	{ 0x4E, iItem_aot_set },
	{ 0x4F, iSce_key_ck },
	{ 0x50, iSce_trg_ck },
	{ 0x51, iSce_bgm_control },
	{ 0x52, iSce_espr_control },
	{ 0x53, iSce_fade_set },
	{ 0x54, iSce_espr3d_on },
	{ 0x55, iMember_calc },
	{ 0x56, iMember_calc2 },
	{ 0x57, iSce_bgmtbl_set },
	{ 0x58, iPlc_rot },
	{ 0x59, iXa_on },
	{ 0x5A, iWeapon_chg },
	{ 0x5B, iPlc_cnt },
	{ 0x5C, iSce_shake_on },
	{ 0x5D, iMizu_div_set },
	{ 0x5E, iKeep_Item_ck },
	{ 0x5F, iXa_vol },
	{ 0x60, iKage_set },
	{ 0x61, iCut_be_set },
	{ 0x62, iSce_Item_lost },
	{ 0x63, iPlc_gun_eff },
	{ 0x64, iSce_espr_on2 },
	{ 0x65, iSce_espr_kill2 },
	{ 0x66, iPlc_stop },
	{ 0x67, iAot_set_4p },
	{ 0x68, iDoor_aot_set_4p },
	{ 0x69, iItem_aot_set_4p },
	{ 0x6A, iLight_pos_set },
	{ 0x6B, iLight_kido_set },
	{ 0x6C, iRbj_reset },
	{ 0x6D, iSce_scr_move },
	{ 0x6E, iParts_set },
	{ 0x6F, iMovie_on },
	{ 0x70, iSplc_ret },
	{ 0x71, iSplc_sce },
	{ 0x72, iSuper_on },
	{ 0x73, iMirror_set },
	{ 0x74, iSce_fade_adjust },
	{ 0x75, iSce_espr3d_on2 },
	{ 0x76, iSce_Item_get },
	{ 0x77, iSce_line_start },
	{ 0x78, iSce_line_main },
	{ 0x79, iSce_line_end },
	{ 0x7A, iSce_parts_bomb },
	{ 0x7B, iSce_parts_down },
	{ 0x7C, iLight_color_set },
	{ 0x7D, iLight_pos_set2 },
	{ 0x7E, iLight_kido_set2 },
	{ 0x7F, iLight_color_set2 },
	{ 0x80, iSe_vol },
	{ 0x81, iSce_Item_cmp },
	{ 0x82, iSce_espr_kill_all },
	{ 0x83, iPlc_heal },
	{ 0x84, iSt_map_hint },
	{ 0x85, iSce_em_pos_ck },
	{ 0x86, iPoison_ck },
	{ 0x87, iPoison_clr },
	{ 0x88, iSce_Item_lost2 },
	{ 0x89, iPlc_life_max },
	{ 0x8A, iVib_set0 },
	{ 0x8B, iVib_set1 },
	{ 0x8C, iVib_fade_set },
	{ 0x8D, iItem_aot_set2 },
	{ 0x8E, iSce_em_set2 },
	{ 0x8F, iNop }
};