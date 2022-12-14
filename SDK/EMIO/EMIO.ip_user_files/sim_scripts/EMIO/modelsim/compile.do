vlib modelsim_lib/work
vlib modelsim_lib/msim

vlib modelsim_lib/msim/xilinx_vip
vlib modelsim_lib/msim/axi_infrastructure_v1_1_0
vlib modelsim_lib/msim/axi_vip_v1_1_4
vlib modelsim_lib/msim/processing_system7_vip_v1_0_6
vlib modelsim_lib/msim/xil_defaultlib

vmap xilinx_vip modelsim_lib/msim/xilinx_vip
vmap axi_infrastructure_v1_1_0 modelsim_lib/msim/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_4 modelsim_lib/msim/axi_vip_v1_1_4
vmap processing_system7_vip_v1_0_6 modelsim_lib/msim/processing_system7_vip_v1_0_6
vmap xil_defaultlib modelsim_lib/msim/xil_defaultlib

vlog -work xilinx_vip -64 -incr -sv -L axi_vip_v1_1_4 -L processing_system7_vip_v1_0_6 -L xilinx_vip "+incdir+F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/include" \
"F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_if.sv" \
"F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/clk_vip_if.sv" \
"F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work axi_infrastructure_v1_1_0 -64 -incr "+incdir+../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/ec67/hdl" "+incdir+../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/70cf/hdl" "+incdir+../../../../EMIO.srcs/sources_1/bd/EMIO/ip/EMIO_processing_system7_0_0" "+incdir+F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_4 -64 -incr -sv -L axi_vip_v1_1_4 -L processing_system7_vip_v1_0_6 -L xilinx_vip "+incdir+../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/ec67/hdl" "+incdir+../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/70cf/hdl" "+incdir+../../../../EMIO.srcs/sources_1/bd/EMIO/ip/EMIO_processing_system7_0_0" "+incdir+F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/98af/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work processing_system7_vip_v1_0_6 -64 -incr -sv -L axi_vip_v1_1_4 -L processing_system7_vip_v1_0_6 -L xilinx_vip "+incdir+../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/ec67/hdl" "+incdir+../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/70cf/hdl" "+incdir+../../../../EMIO.srcs/sources_1/bd/EMIO/ip/EMIO_processing_system7_0_0" "+incdir+F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/70cf/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/ec67/hdl" "+incdir+../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/70cf/hdl" "+incdir+../../../../EMIO.srcs/sources_1/bd/EMIO/ip/EMIO_processing_system7_0_0" "+incdir+F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../EMIO.srcs/sources_1/bd/EMIO/ip/EMIO_processing_system7_0_0/sim/EMIO_processing_system7_0_0.v" \
"../../../../EMIO.srcs/sources_1/bd/EMIO/sim/EMIO.v" \

vlog -work xil_defaultlib \
"glbl.v"

