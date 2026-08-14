# 2026-08-14T18:15:50.307006800
import vitis

client = vitis.create_client()
client.set_workspace(path="sender_hls")

cfg = client.get_config_file(path="/e:/workspace/IntelliJ/hdmi_sender/sender_hls/sender_hls/hls_config.cfg")

cfg = client.get_config_file(path="/e:/workspace/IntelliJ/hdmi_sender/sender_hls/sender_hls/hls_config.cfg")

cfg = client.get_config_file(path="/e:/workspace/IntelliJ/hdmi_sender/sender_hls/sender_hls/hls_config.cfg")

cfg = client.get_config_file(path="/e:/workspace/IntelliJ/hdmi_sender/sender_hls/sender_hls/hls_config.cfg")

cfg = client.get_config_file(path="/e:/workspace/IntelliJ/hdmi_sender/sender_hls/sender_hls/hls_config.cfg")

cfg.set_values(key="syn.file_cflags", values=[])

cfg.set_value(section="hls", key="syn.csimflags", value="")

cfg.set_value(section="hls", key="syn.cflags", value="")

cfg.set_values(key="syn.file", values=["../C_source/sender.hpp", "../C_source/sender.cpp"])

cfg.set_values(key="syn.file_csimflags", values=[])

comp = client.get_component(name="sender_hls")
comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

vitis.dispose()

comp = client.get_component(name="sender_hls")
comp.run(operation="C_SIMULATION")

comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

