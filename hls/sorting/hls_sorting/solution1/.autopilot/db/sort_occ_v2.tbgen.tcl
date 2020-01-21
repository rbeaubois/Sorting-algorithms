set moduleName sort_occ_v2
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {sort_occ_v2}
set C_modelType { void 0 }
set C_modelArgList {
	{ array_src int 32 regular {array 65536 { 1 3 } 1 1 }  }
	{ array_dst int 32 regular {array 65536 { 0 3 } 0 1 }  }
	{ shift int 6 regular  }
	{ count int 32 regular {array 256 { 2 3 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "array_src", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "array_dst", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "shift", "interface" : "wire", "bitwidth" : 6, "direction" : "READONLY"} , 
 	{ "Name" : "count", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE"} ]}
# RTL Port declarations: 
set portNum 19
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ array_src_address0 sc_out sc_lv 16 signal 0 } 
	{ array_src_ce0 sc_out sc_logic 1 signal 0 } 
	{ array_src_q0 sc_in sc_lv 32 signal 0 } 
	{ array_dst_address0 sc_out sc_lv 16 signal 1 } 
	{ array_dst_ce0 sc_out sc_logic 1 signal 1 } 
	{ array_dst_we0 sc_out sc_logic 1 signal 1 } 
	{ array_dst_d0 sc_out sc_lv 32 signal 1 } 
	{ shift sc_in sc_lv 6 signal 2 } 
	{ count_address0 sc_out sc_lv 8 signal 3 } 
	{ count_ce0 sc_out sc_logic 1 signal 3 } 
	{ count_we0 sc_out sc_logic 1 signal 3 } 
	{ count_d0 sc_out sc_lv 32 signal 3 } 
	{ count_q0 sc_in sc_lv 32 signal 3 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "array_src_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "array_src", "role": "address0" }} , 
 	{ "name": "array_src_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "array_src", "role": "ce0" }} , 
 	{ "name": "array_src_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "array_src", "role": "q0" }} , 
 	{ "name": "array_dst_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "array_dst", "role": "address0" }} , 
 	{ "name": "array_dst_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "array_dst", "role": "ce0" }} , 
 	{ "name": "array_dst_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "array_dst", "role": "we0" }} , 
 	{ "name": "array_dst_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "array_dst", "role": "d0" }} , 
 	{ "name": "shift", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "shift", "role": "default" }} , 
 	{ "name": "count_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "count", "role": "address0" }} , 
 	{ "name": "count_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "count", "role": "ce0" }} , 
 	{ "name": "count_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "count", "role": "we0" }} , 
 	{ "name": "count_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "count", "role": "d0" }} , 
 	{ "name": "count_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "count", "role": "q0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "sort_occ_v2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "327681", "EstimateLatencyMax" : "327681",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "array_src", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "array_dst", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "shift", "Type" : "None", "Direction" : "I"},
			{"Name" : "count", "Type" : "Memory", "Direction" : "IO"}]}]}


set ArgLastReadFirstWriteLatency {
	sort_occ_v2 {
		array_src {Type I LastRead 1 FirstWrite -1}
		array_dst {Type O LastRead -1 FirstWrite 5}
		shift {Type I LastRead 0 FirstWrite -1}
		count {Type IO LastRead 3 FirstWrite 5}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "327681", "Max" : "327681"}
	, {"Name" : "Interval", "Min" : "327681", "Max" : "327681"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	array_src { ap_memory {  { array_src_address0 mem_address 1 16 }  { array_src_ce0 mem_ce 1 1 }  { array_src_q0 mem_dout 0 32 } } }
	array_dst { ap_memory {  { array_dst_address0 mem_address 1 16 }  { array_dst_ce0 mem_ce 1 1 }  { array_dst_we0 mem_we 1 1 }  { array_dst_d0 mem_din 1 32 } } }
	shift { ap_none {  { shift in_data 0 6 } } }
	count { ap_memory {  { count_address0 mem_address 1 8 }  { count_ce0 mem_ce 1 1 }  { count_we0 mem_we 1 1 }  { count_d0 mem_din 1 32 }  { count_q0 mem_dout 0 32 } } }
}
