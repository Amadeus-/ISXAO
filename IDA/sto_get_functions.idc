#include <idc.idc>

static main()
{
	Wait(); // We won't work until autoanalysis is complete

	SetStatus(IDA_STATUS_WORK);
		
	Message("Script started.\n");
		
	auto base_address = 0x140000000;
		
	auto ent_active_player_ptr_sig = "48 8B 05 19 07 EB 01";
	auto ent_active_player_ptr_offset = 0;
	ent_active_player_ptr_offset = find_and_label_function("entActivePlayerPtr", ent_active_player_ptr_sig) - base_address;
	
	auto ent_from_entity_ref_sig = "80 3D 09 78 10 02 00 74 ?";
	auto ent_from_entity_ref_offset = 0;
	ent_from_entity_ref_offset = find_and_label_function("entFromEntityRef", ent_from_entity_ref_sig) - base_address;
	
	auto ent_from_entity_ref_any_partition_sig = "80 3D A9 77 10 02 00";
	auto ent_from_entity_ref_any_partition_offset = 0;
	ent_from_entity_ref_any_partition_offset = find_and_label_function("entFromEntityRefAnyPartition", ent_from_entity_ref_any_partition_sig) - base_address;
	
	auto ent_get_mount_sig = "40 53 48 83 EC 20 48 85 C9 74 ? 48 8B 99 28 01 00 00 48 85 DB 74 ? 80 7B 3C 00";
	auto ent_get_mount_offset = 0;
	ent_get_mount_offset = find_and_label_function("entGetMount", ent_get_mount_sig) - base_address;
	
	auto ent_get_partition_idx_sig_0 = "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 40 41 8B D9 49 8B F8 48 8B F2 48 85 C9 0F 85 ? ? ? ? E8 ? ? ? ? 85 C0 74 ? 89 5C 24 38 4C 8D 0D 5B A0 29 01";
	auto ent_get_partition_idx_offset_0 = 0;
	ent_get_partition_idx_offset_0 = find_and_label_function("entGetPartitionIdx_0", ent_get_partition_idx_sig_0) - base_address;
	
	auto ent_get_partition_idx_sig_1 = "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 40 41 8B D9 49 8B F8 48 8B F2 48 85 C9 0F 85 ? ? ? ? E8 ? ? ? ? 85 C0 74 ? 89 5C 24 38 4C 8D 0D 23 A3 F5 00";
	auto ent_get_partition_idx_offset_1 = 0;
	ent_get_partition_idx_offset_1 = find_and_label_function("entGetPartitionIdx_1", ent_get_partition_idx_sig_1) - base_address;
	
	auto ent_get_partition_idx_sig_2 = "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 40 41 8B D9 49 8B F8 48 8B F2 48 85 C9 0F 85 ? ? ? ? E8 ? ? ? ? 85 C0 74 ? 89 5C 24 38 4C 8D 0D D3 D3 C0 00";
	auto ent_get_partition_idx_offset_2 = 0;
	ent_get_partition_idx_offset_2 = find_and_label_function("entGetPartitionIdx_2", ent_get_partition_idx_sig_2) - base_address;
	
	auto ent_get_partition_idx_sig_3 = "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 40 41 8B D9 49 8B F8 48 8B F2 48 85 C9 0F 85 ? ? ? ? E8 ? ? ? ? 85 C0 74 ? 89 5C 24 38 4C 8D 0D 03 AA B5 00";
	auto ent_get_partition_idx_offset_3 = 0;
	ent_get_partition_idx_offset_3 = find_and_label_function("entGetPartitionIdx_3", ent_get_partition_idx_sig_3) - base_address;
	
	auto ent_get_persisted_name_sig = "40 53 48 83 EC 30 48 8B 81 20 01 00 00";
	auto ent_get_persisted_name_offset = 0;
	ent_get_persisted_name_offset = find_and_label_function("entGetPersistedName", ent_get_persisted_name_sig) - base_address;
	
	auto ent_has_ref_recently_existed_sig = "80 3D A9 74 10 02 00";
	auto ent_has_ref_recently_existed_offset = 0;
	ent_has_ref_recently_existed_offset = find_and_label_function("entHasRefRecentlyExisted", ent_has_ref_recently_existed_sig) - base_address;
	
	auto ent_system_free_entity_sig = "48 89 5C 24 08 57 48 83 EC 20 49 8B F8 48 8B D9 E8 ? ? ? ? 48 8B D7";
	auto ent_system_free_entity_offset = 0;
	ent_system_free_entity_offset = find_and_label_function("EntSystem_FreeEntity", ent_system_free_entity_sig) - base_address;
	
	auto entity_set_target_sig = "48 85 C9 0F 84 ? ? ? ? 56 57";
	auto entity_set_target_offset = 0;
	entity_set_target_offset = find_and_label_function("entity_SetTarget", entity_set_target_sig) - base_address;
	
	auto ctm_set_destination_to_pos_sig = "48 89 5C 24 08 57 48 83 EC 50 48 8B F9 E8 ? ? ? ? 4C 8D 44 24 70";
	auto ctm_set_destination_to_pos_offset = 0;
	ctm_set_destination_to_pos_offset = find_and_label_function("ctm_SetDestinationToPos", ctm_set_destination_to_pos_sig) - base_address;
	
	SetStatus(IDA_STATUS_READY);
	
	Message("Script complete.\n");
	
	
	return;
}

static find_and_label_function(function_name, function_sig)
{
	auto pAddress = 0x140000000;
	
	pAddress = FindBinary(pAddress, SEARCH_DOWN, function_sig);
	
	if (pAddress == 0 || pAddress == BADADDR) {
		return 0;
	}
	
	MakeName(pAddress, function_name);
	Message("Function %s found at 0x%08X\n", function_name, pAddress);
	return pAddress;
}