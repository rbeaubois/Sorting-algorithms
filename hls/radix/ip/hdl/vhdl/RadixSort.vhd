-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2018.2
-- Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity RadixSort is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    clk : IN STD_LOGIC;
    e_dout : IN STD_LOGIC_VECTOR (31 downto 0);
    e_empty_n : IN STD_LOGIC;
    e_read : OUT STD_LOGIC;
    s_din : OUT STD_LOGIC_VECTOR (31 downto 0);
    s_full_n : IN STD_LOGIC;
    s_write : OUT STD_LOGIC );
end;


architecture behav of RadixSort is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "RadixSort,hls_ip_2018_2,{HLS_INPUT_TYPE=sc,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7a100tcsg324-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=8.660000,HLS_SYN_LAT=865029,HLS_SYN_TPT=none,HLS_SYN_MEM=260,HLS_SYN_DSP=0,HLS_SYN_FF=582,HLS_SYN_LUT=1516,HLS_VERSION=2018_2}";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal RadixSort_array1_V_q0 : STD_LOGIC_VECTOR (31 downto 0);
    signal RadixSort_array2_V_q0 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_RadixSort_do_sort_fu_54_RadixSort_array1_V_address0 : STD_LOGIC_VECTOR (15 downto 0);
    signal grp_RadixSort_do_sort_fu_54_RadixSort_array1_V_ce0 : STD_LOGIC;
    signal grp_RadixSort_do_sort_fu_54_RadixSort_array1_V_we0 : STD_LOGIC;
    signal grp_RadixSort_do_sort_fu_54_RadixSort_array1_V_d0 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_RadixSort_do_sort_fu_54_RadixSort_array2_V_address0 : STD_LOGIC_VECTOR (15 downto 0);
    signal grp_RadixSort_do_sort_fu_54_RadixSort_array2_V_ce0 : STD_LOGIC;
    signal grp_RadixSort_do_sort_fu_54_RadixSort_array2_V_we0 : STD_LOGIC;
    signal grp_RadixSort_do_sort_fu_54_RadixSort_array2_V_d0 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_RadixSort_do_sort_fu_54_e_read : STD_LOGIC;
    signal grp_RadixSort_do_sort_fu_54_s_din : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_RadixSort_do_sort_fu_54_s_write : STD_LOGIC;

    component RadixSort_do_sort IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        RadixSort_array1_V_address0 : OUT STD_LOGIC_VECTOR (15 downto 0);
        RadixSort_array1_V_ce0 : OUT STD_LOGIC;
        RadixSort_array1_V_we0 : OUT STD_LOGIC;
        RadixSort_array1_V_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
        RadixSort_array1_V_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
        RadixSort_array2_V_address0 : OUT STD_LOGIC_VECTOR (15 downto 0);
        RadixSort_array2_V_ce0 : OUT STD_LOGIC;
        RadixSort_array2_V_we0 : OUT STD_LOGIC;
        RadixSort_array2_V_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
        RadixSort_array2_V_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
        e_dout : IN STD_LOGIC_VECTOR (31 downto 0);
        e_empty_n : IN STD_LOGIC;
        e_read : OUT STD_LOGIC;
        s_din : OUT STD_LOGIC_VECTOR (31 downto 0);
        s_full_n : IN STD_LOGIC;
        s_write : OUT STD_LOGIC );
    end component;


    component RadixSort_RadixSofYi IS
    generic (
        DataWidth : INTEGER;
        AddressRange : INTEGER;
        AddressWidth : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR (15 downto 0);
        ce0 : IN STD_LOGIC;
        we0 : IN STD_LOGIC;
        d0 : IN STD_LOGIC_VECTOR (31 downto 0);
        q0 : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;



begin
    RadixSort_array1_V_U : component RadixSort_RadixSofYi
    generic map (
        DataWidth => 32,
        AddressRange => 64000,
        AddressWidth => 16)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        address0 => grp_RadixSort_do_sort_fu_54_RadixSort_array1_V_address0,
        ce0 => grp_RadixSort_do_sort_fu_54_RadixSort_array1_V_ce0,
        we0 => grp_RadixSort_do_sort_fu_54_RadixSort_array1_V_we0,
        d0 => grp_RadixSort_do_sort_fu_54_RadixSort_array1_V_d0,
        q0 => RadixSort_array1_V_q0);

    RadixSort_array2_V_U : component RadixSort_RadixSofYi
    generic map (
        DataWidth => 32,
        AddressRange => 64000,
        AddressWidth => 16)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        address0 => grp_RadixSort_do_sort_fu_54_RadixSort_array2_V_address0,
        ce0 => grp_RadixSort_do_sort_fu_54_RadixSort_array2_V_ce0,
        we0 => grp_RadixSort_do_sort_fu_54_RadixSort_array2_V_we0,
        d0 => grp_RadixSort_do_sort_fu_54_RadixSort_array2_V_d0,
        q0 => RadixSort_array2_V_q0);

    grp_RadixSort_do_sort_fu_54 : component RadixSort_do_sort
    port map (
        ap_clk => clk,
        ap_rst => ap_rst,
        RadixSort_array1_V_address0 => grp_RadixSort_do_sort_fu_54_RadixSort_array1_V_address0,
        RadixSort_array1_V_ce0 => grp_RadixSort_do_sort_fu_54_RadixSort_array1_V_ce0,
        RadixSort_array1_V_we0 => grp_RadixSort_do_sort_fu_54_RadixSort_array1_V_we0,
        RadixSort_array1_V_d0 => grp_RadixSort_do_sort_fu_54_RadixSort_array1_V_d0,
        RadixSort_array1_V_q0 => RadixSort_array1_V_q0,
        RadixSort_array2_V_address0 => grp_RadixSort_do_sort_fu_54_RadixSort_array2_V_address0,
        RadixSort_array2_V_ce0 => grp_RadixSort_do_sort_fu_54_RadixSort_array2_V_ce0,
        RadixSort_array2_V_we0 => grp_RadixSort_do_sort_fu_54_RadixSort_array2_V_we0,
        RadixSort_array2_V_d0 => grp_RadixSort_do_sort_fu_54_RadixSort_array2_V_d0,
        RadixSort_array2_V_q0 => RadixSort_array2_V_q0,
        e_dout => e_dout,
        e_empty_n => e_empty_n,
        e_read => grp_RadixSort_do_sort_fu_54_e_read,
        s_din => grp_RadixSort_do_sort_fu_54_s_din,
        s_full_n => s_full_n,
        s_write => grp_RadixSort_do_sort_fu_54_s_write);




    e_read <= grp_RadixSort_do_sort_fu_54_e_read;
    s_din <= grp_RadixSort_do_sort_fu_54_s_din;
    s_write <= grp_RadixSort_do_sort_fu_54_s_write;
end behav;
