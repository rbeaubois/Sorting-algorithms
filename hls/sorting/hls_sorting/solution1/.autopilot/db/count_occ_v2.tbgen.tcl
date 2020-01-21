set moduleName count_occ_v2
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
set C_modelName {count_occ_v2}
set C_modelType { void 0 }
set C_modelArgList {
	{ array_src int 32 regular {array 65536 { 1 3 } 1 1 }  }
	{ c1 int 32 regular {array 256 { 2 2 } 1 1 }  }
	{ c2 int 32 regular {array 256 { 2 2 } 1 1 }  }
	{ c3 int 32 regular {array 256 { 2 2 } 1 1 }  }
	{ c4 int 32 regular {array 256 { 2 2 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "array_src", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "c1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE"} , 
 	{ "Name" : "c2", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE"} , 
 	{ "Name" : "c3", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE"} , 
 	{ "Name" : "c4", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE"} ]}
# RTL Port declarations: 
set portNum 49
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
	{ c1_address0 sc_out sc_lv 8 signal 1 } 
	{ c1_ce0 sc_out sc_logic 1 signal 1 } 
	{ c1_we0 sc_out sc_logic 1 signal 1 } 
	{ c1_d0 sc_out sc_lv 32 signal 1 } 
	{ c1_q0 sc_in sc_lv 32 signal 1 } 
	{ c1_address1 sc_out sc_lv 8 signal 1 } 
	{ c1_ce1 sc_out sc_logic 1 signal 1 } 
	{ c1_we1 sc_out sc_logic 1 signal 1 } 
	{ c1_d1 sc_out sc_lv 32 signal 1 } 
	{ c1_q1 sc_in sc_lv 32 signal 1 } 
	{ c2_address0 sc_out sc_lv 8 signal 2 } 
	{ c2_ce0 sc_out sc_logic 1 signal 2 } 
	{ c2_we0 sc_out sc_logic 1 signal 2 } 
	{ c2_d0 sc_out sc_lv 32 signal 2 } 
	{ c2_q0 sc_in sc_lv 32 signal 2 } 
	{ c2_address1 sc_out sc_lv 8 signal 2 } 
	{ c2_ce1 sc_out sc_logic 1 signal 2 } 
	{ c2_we1 sc_out sc_logic 1 signal 2 } 
	{ c2_d1 sc_out sc_lv 32 signal 2 } 
	{ c2_q1 sc_in sc_lv 32 signal 2 } 
	{ c3_address0 sc_out sc_lv 8 signal 3 } 
	{ c3_ce0 sc_out sc_logic 1 signal 3 } 
	{ c3_we0 sc_out sc_logic 1 signal 3 } 
	{ c3_d0 sc_out sc_lv 32 signal 3 } 
	{ c3_q0 sc_in sc_lv 32 signal 3 } 
	{ c3_address1 sc_out sc_lv 8 signal 3 } 
	{ c3_ce1 sc_out sc_logic 1 signal 3 } 
	{ c3_we1 sc_out sc_logic 1 signal 3 } 
	{ c3_d1 sc_out sc_lv 32 signal 3 } 
	{ c3_q1 sc_in sc_lv 32 signal 3 } 
	{ c4_address0 sc_out sc_lv 8 signal 4 } 
	{ c4_ce0 sc_out sc_logic 1 signal 4 } 
	{ c4_we0 sc_out sc_logic 1 signal 4 } 
	{ c4_d0 sc_out sc_lv 32 signal 4 } 
	{ c4_q0 sc_in sc_lv 32 signal 4 } 
	{ c4_address1 sc_out sc_lv 8 signal 4 } 
	{ c4_ce1 sc_out sc_logic 1 signal 4 } 
	{ c4_we1 sc_out sc_logic 1 signal 4 } 
	{ c4_d1 sc_out sc_lv 32 signal 4 } 
	{ c4_q1 sc_in sc_lv 32 signal 4 } 
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
 	{ "name": "c1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "c1", "role": "address0" }} , 
 	{ "name": "c1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c1", "role": "ce0" }} , 
 	{ "name": "c1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c1", "role": "we0" }} , 
 	{ "name": "c1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c1", "role": "d0" }} , 
 	{ "name": "c1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c1", "role": "q0" }} , 
 	{ "name": "c1_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "c1", "role": "address1" }} , 
 	{ "name": "c1_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c1", "role": "ce1" }} , 
 	{ "name": "c1_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c1", "role": "we1" }} , 
 	{ "name": "c1_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c1", "role": "d1" }} , 
 	{ "name": "c1_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c1", "role": "q1" }} , 
 	{ "name": "c2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "c2", "role": "address0" }} , 
 	{ "name": "c2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c2", "role": "ce0" }} , 
 	{ "name": "c2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c2", "role": "we0" }} , 
 	{ "name": "c2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c2", "role": "d0" }} , 
 	{ "name": "c2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c2", "role": "q0" }} , 
 	{ "name": "c2_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "c2", "role": "address1" }} , 
 	{ "name": "c2_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c2", "role": "ce1" }} , 
 	{ "name": "c2_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c2", "role": "we1" }} , 
 	{ "name": "c2_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c2", "role": "d1" }} , 
 	{ "name": "c2_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c2", "role": "q1" }} , 
 	{ "name": "c3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "c3", "role": "address0" }} , 
 	{ "name": "c3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c3", "role": "ce0" }} , 
 	{ "name": "c3_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c3", "role": "we0" }} , 
 	{ "name": "c3_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c3", "role": "d0" }} , 
 	{ "name": "c3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c3", "role": "q0" }} , 
 	{ "name": "c3_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "c3", "role": "address1" }} , 
 	{ "name": "c3_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c3", "role": "ce1" }} , 
 	{ "name": "c3_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c3", "role": "we1" }} , 
 	{ "name": "c3_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c3", "role": "d1" }} , 
 	{ "name": "c3_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c3", "role": "q1" }} , 
 	{ "name": "c4_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "c4", "role": "address0" }} , 
 	{ "name": "c4_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c4", "role": "ce0" }} , 
 	{ "name": "c4_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c4", "role": "we0" }} , 
 	{ "name": "c4_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c4", "role": "d0" }} , 
 	{ "name": "c4_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c4", "role": "q0" }} , 
 	{ "name": "c4_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "c4", "role": "address1" }} , 
 	{ "name": "c4_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c4", "role": "ce1" }} , 
 	{ "name": "c4_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "c4", "role": "we1" }} , 
 	{ "name": "c4_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c4", "role": "d1" }} , 
 	{ "name": "c4_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "c4", "role": "q1" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "count_occ_v2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "213438", "EstimateLatencyMax" : "213438",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "array_src", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "c1", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "c2", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "c3", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "c4", "Type" : "Memory", "Direction" : "IO"}]}]}


set ArgLastReadFirstWriteLatency {
	count_occ_v2 {
		array_src {Type I LastRead 10 FirstWrite -1}
		c1 {Type IO LastRead 11 FirstWrite 4}
		c2 {Type IO LastRead 11 FirstWrite 4}
		c3 {Type IO LastRead 11 FirstWrite 4}
		c4 {Type IO LastRead 11 FirstWrite 4}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "213438", "Max" : "213438"}
	, {"Name" : "Interval", "Min" : "213438", "Max" : "213438"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	array_src { ap_memory {  { array_src_address0 mem_address 1 16 }  { array_src_ce0 mem_ce 1 1 }  { array_src_q0 mem_dout 0 32 } } }
	c1 { ap_memory {  { c1_address0 mem_address 1 8 }  { c1_ce0 mem_ce 1 1 }  { c1_we0 mem_we 1 1 }  { c1_d0 mem_din 1 32 }  { c1_q0 mem_dout 0 32 }  { c1_address1 mem_address 1 8 }  { c1_ce1 mem_ce 1 1 }  { c1_we1 mem_we 1 1 }  { c1_d1 mem_din 1 32 }  { c1_q1 mem_dout 0 32 } } }
	c2 { ap_memory {  { c2_address0 mem_address 1 8 }  { c2_ce0 mem_ce 1 1 }  { c2_we0 mem_we 1 1 }  { c2_d0 mem_din 1 32 }  { c2_q0 mem_dout 0 32 }  { c2_address1 mem_address 1 8 }  { c2_ce1 mem_ce 1 1 }  { c2_we1 mem_we 1 1 }  { c2_d1 mem_din 1 32 }  { c2_q1 mem_dout 0 32 } } }
	c3 { ap_memory {  { c3_address0 mem_address 1 8 }  { c3_ce0 mem_ce 1 1 }  { c3_we0 mem_we 1 1 }  { c3_d0 mem_din 1 32 }  { c3_q0 mem_dout 0 32 }  { c3_address1 mem_address 1 8 }  { c3_ce1 mem_ce 1 1 }  { c3_we1 mem_we 1 1 }  { c3_d1 mem_din 1 32 }  { c3_q1 mem_dout 0 32 } } }
	c4 { ap_memory {  { c4_address0 mem_address 1 8 }  { c4_ce0 mem_ce 1 1 }  { c4_we0 mem_we 1 1 }  { c4_d0 mem_din 1 32 }  { c4_q0 mem_dout 0 32 }  { c4_address1 mem_address 1 8 }  { c4_ce1 mem_ce 1 1 }  { c4_we1 mem_we 1 1 }  { c4_d1 mem_din 1 32 }  { c4_q1 mem_dout 0 32 } } }
}
