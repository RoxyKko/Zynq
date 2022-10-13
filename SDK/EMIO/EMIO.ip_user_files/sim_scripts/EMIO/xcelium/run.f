-makelib xcelium_lib/xilinx_vip -sv \
  "F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
  "F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
  "F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
  "F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
  "F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
  "F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
  "F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_if.sv" \
  "F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/clk_vip_if.sv" \
  "F:/FPGA/Vivado_ide/Vivado/2018.3/data/xilinx_vip/hdl/rst_vip_if.sv" \
-endlib
-makelib xcelium_lib/axi_infrastructure_v1_1_0 \
  "../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_vip_v1_1_4 -sv \
  "../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/98af/hdl/axi_vip_v1_1_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/processing_system7_vip_v1_0_6 -sv \
  "../../../../EMIO.srcs/sources_1/bd/EMIO/ipshared/70cf/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../../EMIO.srcs/sources_1/bd/EMIO/ip/EMIO_processing_system7_0_0/sim/EMIO_processing_system7_0_0.v" \
  "../../../../EMIO.srcs/sources_1/bd/EMIO/sim/EMIO.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  glbl.v
-endlib

