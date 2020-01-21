// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Tue Jan 21 10:00:04 2020
// Host        : hayoru running 64-bit Manjaro Linux
// Command     : write_verilog -force -mode synth_stub
//               /home/rbeaubois/Documents/ENSEIRB/Sorting-algorithms/vivado/radix/design_1/ip/design_1_HLS_radix_0_0/design_1_HLS_radix_0_0_stub.v
// Design      : design_1_HLS_radix_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "HLS_radix,Vivado 2018.2" *)
module design_1_HLS_radix_0_0(ap_clk, ap_rst_n, S_AXIS_TVALID, S_AXIS_TREADY, 
  S_AXIS_TDATA, S_AXIS_TDEST, S_AXIS_TKEEP, S_AXIS_TSTRB, S_AXIS_TUSER, S_AXIS_TLAST, 
  S_AXIS_TID, M_AXIS_TVALID, M_AXIS_TREADY, M_AXIS_TDATA, M_AXIS_TDEST, M_AXIS_TKEEP, 
  M_AXIS_TSTRB, M_AXIS_TUSER, M_AXIS_TLAST, M_AXIS_TID)
/* synthesis syn_black_box black_box_pad_pin="ap_clk,ap_rst_n,S_AXIS_TVALID,S_AXIS_TREADY,S_AXIS_TDATA[31:0],S_AXIS_TDEST[0:0],S_AXIS_TKEEP[3:0],S_AXIS_TSTRB[3:0],S_AXIS_TUSER[0:0],S_AXIS_TLAST[0:0],S_AXIS_TID[0:0],M_AXIS_TVALID,M_AXIS_TREADY,M_AXIS_TDATA[31:0],M_AXIS_TDEST[0:0],M_AXIS_TKEEP[3:0],M_AXIS_TSTRB[3:0],M_AXIS_TUSER[0:0],M_AXIS_TLAST[0:0],M_AXIS_TID[0:0]" */;
  input ap_clk;
  input ap_rst_n;
  input S_AXIS_TVALID;
  output S_AXIS_TREADY;
  input [31:0]S_AXIS_TDATA;
  input [0:0]S_AXIS_TDEST;
  input [3:0]S_AXIS_TKEEP;
  input [3:0]S_AXIS_TSTRB;
  input [0:0]S_AXIS_TUSER;
  input [0:0]S_AXIS_TLAST;
  input [0:0]S_AXIS_TID;
  output M_AXIS_TVALID;
  input M_AXIS_TREADY;
  output [31:0]M_AXIS_TDATA;
  output [0:0]M_AXIS_TDEST;
  output [3:0]M_AXIS_TKEEP;
  output [3:0]M_AXIS_TSTRB;
  output [0:0]M_AXIS_TUSER;
  output [0:0]M_AXIS_TLAST;
  output [0:0]M_AXIS_TID;
endmodule
