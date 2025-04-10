set_property PACKAGE_PIN G26 [get_ports {cam1_gpio[0]}]
set_property IOSTANDARD LVCMOS15 [get_ports {cam1_gpio[0]}]
set_property PULLUP true [get_ports {cam1_gpio[0]}]

set_property PACKAGE_PIN G27  [get_ports cam1_i2c_scl_io]
set_property PACKAGE_PIN F28 [get_ports cam1_i2c_sda_io]

set_property IOSTANDARD LVCMOS15 [get_ports cam1_i2c_scl_io]
set_property IOSTANDARD LVCMOS15 [get_ports cam1_i2c_sda_io]


set_property PULLUP true [get_ports cam1_i2c_scl_io]
set_property PULLUP true [get_ports cam1_i2c_sda_io]

#bank 702 N4N5
set_property PACKAGE_PIN U23 [get_ports mipi_phy_if_0_clk_p]
set_property PACKAGE_PIN T23 [get_ports mipi_phy_if_0_data_p[0]]
set_property PACKAGE_PIN R23 [get_ports mipi_phy_if_0_data_p[1]]
set_property PACKAGE_PIN L23 [get_ports mipi_phy_if_0_data_p[2]]
set_property PACKAGE_PIN M22 [get_ports mipi_phy_if_0_data_p[3]]

set_property IOSTANDARD MIPI_DPHY [get_ports mipi_phy_if_0_clk_p]
set_property IOSTANDARD MIPI_DPHY [get_ports mipi_phy_if_0_clk_n]
set_property IOSTANDARD MIPI_DPHY [get_ports mipi_phy_if_0_data_p[0]]
set_property IOSTANDARD MIPI_DPHY [get_ports mipi_phy_if_0_data_n[0]]
set_property IOSTANDARD MIPI_DPHY [get_ports mipi_phy_if_0_data_p[1]]
set_property IOSTANDARD MIPI_DPHY [get_ports mipi_phy_if_0_data_n[1]]
set_property IOSTANDARD MIPI_DPHY [get_ports mipi_phy_if_0_data_p[2]]
set_property IOSTANDARD MIPI_DPHY [get_ports mipi_phy_if_0_data_n[2]]
set_property IOSTANDARD MIPI_DPHY [get_ports mipi_phy_if_0_data_p[3]]
set_property IOSTANDARD MIPI_DPHY [get_ports mipi_phy_if_0_data_n[3]]
set_property CLOCK_REGION X3Y0 [get_cells -hier -filter {name =~ *mipi_csi2_rx_subsyst_1/inst/phy/inst/inst/rxbyteclkhs_buf}]
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets -hier -filter {name =~ *mipi_csi2_rx_subsyst_0/inst/phy/inst/inst/*/inst/BANK_WRAPPER_INST0/fifo_wr_clk[0]}]
#set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets -hier -filter {name =~ *mipi_csi2_rx_subsyst_1/inst/phy/inst/inst/*/inst/BANK_WRAPPER_INST0/fifo_wr_clk[0]}]
